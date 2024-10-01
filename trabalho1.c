// Incluir no sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    carregar_usuarios();

    // Função para método de entrada no sistema (CADASTRO, LOGIN, OU SAIR)
    int opcao;
    while (1) {
        printf("\n| 1 | Cadastrar usuário\n");
        printf("| 2 | Login\n");
        printf("| 3 | Sair\n");
        opcao = input1("Escolha uma opção: ");

        switch (opcao) {
            case 1:
                cadastrar_usuario();
                break;
            case 2: {
                Usuario *usuario = login_usuario();
                if (usuario != NULL) {
                    menu(usuario);
                }
                break;
            }
            case 3:
                printf("Saindo do sistema...\n");
                return 0;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}

// Cotação bitcoins (globais)
double cot_bitcoin = 322.865;
double cot_eth = 15.524;
double cot_rip = 2.67;
// Define o máx de usuários que podem ser criados e o máx de transações
#define MAX_USUARIOS 10
#define MAX_TRANSACOES 100

// Estrutura para armazenar dados do usuário
typedef struct {
    char cpf[12];
    int senha;
    char nome[50];
    double saldo;
    double valor_btc;
    double valor_eth;
    double valor_rip;
    char extrato[MAX_TRANSACOES][100]; // Histórico de até 100 transações
    int transacao_atual;
} Usuario;


// Array de usuários e contador
Usuario usuarios[MAX_USUARIOS];
int num_usuarios = 0;

// Função para obter a entrada do usuário
int input1(const char *prompt) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}

// Função para obter a entrada do usuário (double)
double input2(const char *prompt) {
    double input;
    printf("%s", prompt);
    scanf("%lf", &input);
    return input;
}

// Função para obter a entrada do usuário (string)
void input3(const char *prompt, char *input) {
    printf("%s", prompt);
    scanf("%s", input);
}

// Função para carregar dados de usuários de um arquivo binário
void carregar_usuarios() {
    FILE *file = fopen("usuarios.bin", "rb");
    if (file != NULL) {
        fread(usuarios, sizeof(Usuario), MAX_USUARIOS, file);
        fclose(file);
    }
}

// Função para salvar dados de usuários em um arquivo binário
void salvar_usuarios() {
    FILE *file = fopen("usuarios.bin", "wb");
    if (file != NULL) {
        fwrite(usuarios, sizeof(Usuario), MAX_USUARIOS, file);
        fclose(file);
    }
}
// Função para verificar se um CPF já está cadastrado
int cpf_existente(const char *cpf) {
    for (int i = 0; i < num_usuarios; i++) {
        if (strcmp(usuarios[i].cpf, cpf) == 0) {
            return 1; // CPF já existente 
        }
    }
    return 0; // CPF não cadastrado ainda
}

// Função para cadastrar um novo usuário
void cadastrar_usuario() {
    if (num_usuarios >= MAX_USUARIOS) {
        printf("Número máximo de usuários atingido.\n");
        return;
    }

    Usuario novo_usuario;
    input3("Digite o CPF: ", novo_usuario.cpf);

    // Verificar se o CPF já está cadastrado
    if (cpf_existente(novo_usuario.cpf)) {
        printf("CPF já cadastrado. Tente novamente com um CPF diferente.\n");
        return;
    }

    novo_usuario.senha = input1("Digite a senha: ");
    input3("Digite o nome: ", novo_usuario.nome);
    novo_usuario.saldo = 0;
    novo_usuario.valor_btc = 0;
    novo_usuario.valor_eth = 0;
    novo_usuario.valor_rip = 0;
    novo_usuario.transacao_atual = 0;

    usuarios[num_usuarios++] = novo_usuario;
    salvar_usuarios();
    printf("Usuário cadastrado com sucesso!\n");
}

// Função para buscar um usuário por CPF
Usuario *buscar_usuario(const char *cpf) {
    for (int i = 0; i < num_usuarios; i++) {
        if (strcmp(usuarios[i].cpf, cpf) == 0) {
            return &usuarios[i];
        }
    }
    return NULL;
}

// Função para fazer o login do usuário
Usuario *login_usuario() {
    char cpf[12];
    int senha;

    input3("Digite aqui seu CPF: ", cpf);
    Usuario *usuario = buscar_usuario(cpf);
    if (usuario == NULL) {
        printf("Usuário não encontrado.\n");
        return NULL;
    }

    senha = input1("Digite aqui sua senha: ");
    if (senha != usuario->senha) {
        printf("Senha incorreta.\n");
        return NULL;
    }

    printf("\nLogin realizado com sucesso, bem-vindo %s!\n", usuario->nome);
    return usuario;
}
void consultar_saldo(Usuario *usuario) {
    printf("\nNome: %s\n", usuario->nome);
    printf("CPF: %s\n", usuario->cpf);
    printf("Reais: %.2f\n", usuario->saldo);
    printf("Bitcoin: %.2f\n", usuario->valor_btc);
    printf("Ethereum: %.2f\n", usuario->valor_eth);
    printf("Ripple: %.2f\n", usuario->valor_rip);
}
// Função para salvar o extrato no arquivo.txt
void arquivo(Usuario *usuario) {
    FILE *file = fopen("extrato.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de extrato.\n");
        return;
    }
    fprintf(file, "Extrato de %s (%s):\n", usuario->nome, usuario->cpf);
    for (int i = 0; i < usuario->transacao_atual; i++) {
        fprintf(file, "%s", usuario->extrato[i]);
    }
    fclose(file);
}

// Função para consultar o extrato da conta
void consultar_extrato(Usuario *usuario) {
    printf("\nNome: %s\n", usuario->nome);
    printf("CPF: %s\n", usuario->cpf);
    if (usuario->transacao_atual > 0) {
        for (int i = 0; i < usuario->transacao_atual; i++) {
            printf("%s", usuario->extrato[i]);
        }
    } else {
        printf("Não houve transações.\n");
    }
    arquivo(usuario);

// Função para depositar na conta
void depositar(Usuario *usuario) {
    double quantia = input2("Digite a quantidade para depositar: ");
    if (quantia > 0) {
        usuario->saldo += quantia;
        char transacao[100];
        snprintf(transacao, 100, "+ %.2f REAL\n", quantia);
        strcpy(usuario->extrato[usuario->transacao_atual++], transacao);
        printf("Depósito realizado com sucesso!\nSeu novo saldo é: %.2f\n", usuario->saldo);
    } else {
        printf("Quantidade inválida!\n");
    }
}
// Função para verificar a senha antes de permitir o saque do usuário
int verificar_senha(Usuario *usuario) {
    int senha = input1("Digite sua senha para sacar: ");
    return (senha == usuario->senha);
}

// Função para sacar da conta
void sacar(Usuario *usuario) {
    if (!verificar_senha(usuario)) {
        printf("Senha incorreta. Saque não permitido.\n");
        return;
    }

    double quantia = input2("Digite a quantidade do saque: ");
    if (quantia <= usuario->saldo) {
        usuario->saldo -= quantia;
        char transacao[100];
        snprintf(transacao, 100, "- %.2f REAL\n", quantia);
        strcpy(usuario->extrato[usuario->transacao_atual++], transacao);
        printf("Saque realizado com sucesso!\nSeu novo saldo é: %.2f\n", usuario->saldo);
    } else {
        printf("Saldo insuficiente.\n");
    }
}
// Função para comprar criptomoedas
void comprar_criptomoedas(Usuario *usuario) {
    printf("Escolha a criptomoeda que deseja comprar:\n");
    printf("1 - Bitcoin (R$%.3f)\n", cot_bitcoin);
    printf("2 - Ethereum (R$%.3f)\n", cot_eth);
    printf("3 - Ripple (R$%.2f)\n", cot_rip);

    int escolha = input1("Digite o número correspondente à criptomoeda desejada: ");
    double quantidade, custo;

    switch (escolha) {
        case 1:
            quantidade = input2("Digite a quantidade de Bitcoin que deseja comprar: ");
            double tx_bitcoin = cot_bitcoin * 1.02; // Taxa de 2%
            custo = quantidade * tx_bitcoin; // Custo total incluindo taxa

            printf("O custo total será R$%.3f. Tem certeza que deseja continuar? (1 para Sim, 0 para Não)\n", custo);
            int confirmacao_btc = input1("Confirme sua escolha: ");
            if (confirmacao_btc == 1) {
                if (custo <= usuario->saldo) {
                    usuario->saldo -= custo;
                    usuario->valor_btc += quantidade;
                    char transacao[100];
                    snprintf(transacao, 100, "+ %.2f BITCOIN (Custo: %.3f)\n", quantidade, custo);
                    strcpy(usuario->extrato[usuario->transacao_atual++], transacao);
                    printf("%.2f Bitcoin comprado com sucesso!\n", quantidade);
                } else {
                    printf("Saldo insuficiente.\n");
                }
            } else {
                printf("Compra cancelada.\n");
            }
            break;

        case 2:
            quantidade = input2("Digite a quantidade de Ethereum que deseja comprar: ");
            double tx_eth = cot_eth * 1.01; // Taxa de 1%
            custo = quantidade * tx_eth;

            printf("O custo total será R$%.3f. Tem certeza que deseja continuar? (1 para Sim, 0 para Não)\n", custo);
            int confirmacao_eth = input1("Confirme sua escolha: ");
            if (confirmacao_eth == 1) {
                if (custo <= usuario->saldo) {
                    usuario->saldo -= custo;
                    usuario->valor_eth += quantidade;
                    char transacao[100];
                    snprintf(transacao, 100, "+ %.2f ETHEREUM (Custo: %.3f)\n", quantidade, custo);
                    strcpy(usuario->extrato[usuario->transacao_atual++], transacao);
                    printf("%.2f Ethereum comprado com sucesso!\n", quantidade);
                } else {
                    printf("Saldo insuficiente.\n");
                }
            } else {
                printf("Compra cancelada.\n");
            }
            break;

        case 3:
            quantidade = input2("Digite a quantidade de Ripple que deseja comprar: ");
            double tx_ripple = cot_rip * 1.01; // Taxa de 1%
            custo = quantidade * tx_ripple;

            printf("O custo total será R$%.3f. Tem certeza que deseja continuar? (1 para Sim, 0 para Não)\n", custo);
            int confirmacao_rip = input1("Confirme sua escolha: ");
            if (confirmacao_rip == 1) {
                if (custo <= usuario->saldo) {
                    usuario->saldo -= custo;
                    usuario->valor_rip += quantidade;
                    char transacao[100];
                    snprintf(transacao, 100, "+ %.2f RIPPLE (Custo: %.3f)\n", quantidade, custo);
                    strcpy(usuario->extrato[usuario->transacao_atual++], transacao);
                    printf("%.2f Ripple comprado com sucesso!\n", quantidade);
                } else {
                    printf("Saldo insuficiente.\n");
                }
            } else {
                printf("Compra cancelada.\n");
            }
            break;

        default:
            printf("Opção inválida.\n");
            break;
    }
}

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
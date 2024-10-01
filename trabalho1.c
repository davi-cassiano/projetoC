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
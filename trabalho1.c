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
}
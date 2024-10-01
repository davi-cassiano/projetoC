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

// Função principal com o menu de opções
void menu(Usuario *usuario) {
    while (1) {
        printf("\n| 1 | Consultar saldo\n");
        printf("| 2 | Consultar extrato\n");
        printf("| 3 | Depositar\n");
        printf("| 4 | Sacar\n");
        printf("| 5 | Comprar criptomoedas\n");
        printf("| 6 | Vender criptomoedas\n");
        printf("| 7 | Atualizar cotação\n");
        printf("| 8 | Sair\n");

        int opcao = input1("\nDigite aqui a opção desejada: ");
        switch (opcao) {
            case 1:
                consultar_saldo(usuario);
                break;
            case 2:
                consultar_extrato(usuario);
                break;
            case 3:
                depositar(usuario);
                salvar_usuarios();
                break;
            case 4:
                sacar(usuario);
                salvar_usuarios();
                break;
            case 5:
                comprar_criptomoedas(usuario);
                salvar_usuarios();
                break;
            case 6:
                vender_criptomoedas(usuario);
                salvar_usuarios();
                break;
            case 7:
                atualizar_cotacao();
                break;
            case 8:
                printf("Obrigado por utilizar nossos serviços!\n");
                salvar_usuarios();
                return;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }
}

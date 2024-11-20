// login admin
// cpf: 12345678910
// senha: 1234

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INVESTIDORES 10
#define MAX_CRYPTOS 10
#define MAX_TRANSACOES 100

int main() {
    carregar_dados();
    char cpf[12];
    int senha;

    printf("=== LOGIN ADMINISTRADOR ===\n");
    input3("CPF: ", cpf);
    senha = input1("Senha: ");

    if (strcmp(cpf, "12345678910") == 0 && senha == 1234) {
        printf("Login bem-sucedido.\n");
        menu_administrador();
    } else {
        printf("Login falhou.\n");
    }

    return 0;
}

// Menu principal
void menu_administrador() {
    while (1) {
        printf("\n=== MENU ADMINISTRADOR ===\n");
        printf("1. Cadastrar investidor\n");
        printf("2. Excluir investidor\n");
        printf("3. Consultar saldo de investidor\n");
        printf("4. Consultar extrato de investidor\n");
        printf("5. Cadastrar criptomoeda\n");
        printf("6. Excluir criptomoeda\n");
        printf("7. Atualizar cotações\n");
        printf("8. Sair\n");
        int opcao = input1("Escolha uma opção: ");

        switch (opcao) {
            case 1:
                cadastrar_investidor();
                break;
            case 2:
                excluir_investidor();
                break;
            case 3:
                consultar_saldo();
                break;
            case 4:
                consultar_extrato();
                break;
            case 5:
                cadastrar_criptomoeda();
                break;
            case 6:
                excluir_criptomoeda();
                break;
            case 7:
                atualizar_cotacoes();
                break;
            case 8:
                printf("Saindo...\n");
                salvar_dados();
                return;
            default:
                printf("Opção inválida.\n");
        }
    }
}
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

void consultar_extrato() {
    char cpf[12];
    input3("CPF do investidor: ", cpf);
    Investidor *investidor = buscar_investidor(cpf);

    if (investidor) {
        printf("Extrato de %s:\n", investidor->nome);
        for (int i = 0; i < investidor->transacao_atual; i++) {
            printf("%s", investidor->extrato[i]);
        }
    } else {
        printf("Investidor não encontrado.\n");
    }
}
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

void atualizar_cotacoes() {
    srand(time(NULL));
    for (int i = 0; i < num_criptomoedas; i++) {
        double variacao = ((rand() % 101 - 50) / 100.0) * 0.05;
        criptomoedas[i].cotacao += criptomoedas[i].cotacao * variacao;
        if (criptomoedas[i].cotacao < 0) {
            criptomoedas[i].cotacao = 0;
        }
    }

    printf("Cotações atualizadas com sucesso.\n");
}
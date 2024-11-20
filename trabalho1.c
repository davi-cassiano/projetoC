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

typedef struct {
    char nome[50];
    char cpf[12];
    int senha;
    double saldo;
    double criptos[MAX_CRYPTOS];
    char extrato[MAX_TRANSACOES][100];
    int transacao_atual;
} Investidor;

typedef struct {
    char nome[50];
    double cotacao;
    double taxa_compra;
    double taxa_venda;
} Criptomoeda;

// Dados globais
Investidor investidores[MAX_INVESTIDORES];
int num_investidores = 0;
Criptomoeda criptomoedas[MAX_CRYPTOS];
int num_criptomoedas = 0;

// Funções auxiliares para entrada
int input1(const char *prompt) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}

double input2(const char *prompt) {
    double input;
    printf("%s", prompt);
    scanf("%lf", &input);
    return input;
}

void input3(const char *prompt, char *input) {
    printf("%s", prompt);
    scanf("%s", input);
}

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

// Funções de arquivo
void carregar_dados() {
    FILE *file = fopen("dados.bin", "rb");
    if (file) {
        fread(&investidores, sizeof(Investidor), MAX_INVESTIDORES, file);
        fread(&criptomoedas, sizeof(Criptomoeda), MAX_CRYPTOS, file);
        fclose(file);
    }
}

void salvar_dados() {
    FILE *file = fopen("dados.bin", "wb");
    if (file) {
        fwrite(&investidores, sizeof(Investidor), MAX_INVESTIDORES, file);
        fwrite(&criptomoedas, sizeof(Criptomoeda), MAX_CRYPTOS, file);
        fclose(file);
    }
}

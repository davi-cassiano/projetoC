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

void cadastrar_criptomoeda() {
    if (num_criptomoedas >= MAX_CRYPTOS) {
        printf("Número máximo de criptomoedas atingido.\n");
        return;
    }

    Criptomoeda nova;
    input3("Nome da criptomoeda: ", nova.nome);
    nova.cotacao = input2("Cotação inicial: ");
    nova.taxa_compra = input2("Taxa de compra (em %%): ");
    nova.taxa_venda = input2("Taxa de venda (em %%): ");
    criptomoedas[num_criptomoedas++] = nova;

    salvar_dados();
    printf("Criptomoeda cadastrada com sucesso.\n");
}

void excluir_criptomoeda() {
    char nome[50];
    input3("Nome da criptomoeda a excluir: ", nome);

    for (int i = 0; i < num_criptomoedas; i++) {
        if (strcmp(criptomoedas[i].nome, nome) == 0) {
            printf("Criptomoeda encontrada: %s (Cotação: %.2f)\n", criptomoedas[i].nome, criptomoedas[i].cotacao);
            int confirmacao = input1("Confirma exclusão? (1 para Sim, 0 para Não): ");
            if (confirmacao == 1) {
                for (int j = i; j < num_criptomoedas - 1; j++) {
                    criptomoedas[j] = criptomoedas[j + 1];
                }
                num_criptomoedas--;
                salvar_dados();
                printf("Criptomoeda excluída com sucesso.\n");
                return;
            } else {
                printf("Exclusão cancelada.\n");
                return;
            }
        }
    }
    printf("Criptomoeda não encontrada.\n");
}
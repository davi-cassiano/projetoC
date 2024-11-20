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
int input1(const char prompt) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}

double input2(const charprompt) {
    double input;
    printf("%s", prompt);
    scanf("%lf", &input);
    return input;
}

void input3(const char prompt, charinput) {
    printf("%s", prompt);
    scanf("%s", input);
}

// Funções de arquivo
void carregar_dados() {
    FILE file = fopen("dados.bin", "rb");
    if (file) {
        fread(&investidores, sizeof(Investidor), MAX_INVESTIDORES, file);
        fread(&criptomoedas, sizeof(Criptomoeda), MAX_CRYPTOS, file);
        fclose(file);
    }
}

void salvar_dados() {
    FILEfile = fopen("dados.bin", "wb");
    if (file) {
        fwrite(&investidores, sizeof(Investidor), MAX_INVESTIDORES, file);
        fwrite(&criptomoedas, sizeof(Criptomoeda), MAX_CRYPTOS, file);
        fclose(file);
    }
}

// Buscar investidor
Investidor buscar_investidor(const charcpf) {
    for (int i = 0; i < num_investidores; i++) {
        if (strcmp(investidores[i].cpf, cpf) == 0) {
            return &investidores[i];
        }
    }
    return NULL;
}

// Funções administrativas
void cadastrar_investidor() {
    if (num_investidores >= MAX_INVESTIDORES) {
        printf("Número máximo de investidores atingido.\n");
        return;
    }

    Investidor novo;
    input3("Nome do investidor: ", novo.nome);
    input3("CPF do investidor: ", novo.cpf);

    if (buscar_investidor(novo.cpf)) {
        printf("Investidor com este CPF já existe.\n");
        return;
    }

    novo.senha = input1("Senha do investidor: ");
    novo.saldo = 0;
    novo.transacao_atual = 0;
    memset(novo.criptos, 0, sizeof(novo.criptos));
    investidores[num_investidores++] = novo;

    salvar_dados();
    printf("Investidor cadastrado com sucesso.\n");
}

void excluir_investidor() {
    char cpf[12];
    input3("CPF do investidor a excluir: ", cpf);
    Investidor *investidor = buscar_investidor(cpf);

    if (investidor) {
        printf("Investidor encontrado: %s\n", investidor->nome);
        int confirmacao = input1("Confirma exclusão? (1 para Sim, 0 para Não): ");
        if (confirmacao == 1) {
            for (int i = (investidor - investidores); i < num_investidores - 1; i++) {
                investidores[i] = investidores[i + 1];
            }
            num_investidores--;
            salvar_dados();
            printf("Investidor excluído com sucesso.\n");
        } else {
            printf("Exclusão cancelada.\n");
        }
    } else {
        printf("Investidor não encontrado.\n");
    }
}

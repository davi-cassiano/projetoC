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

// Função para gerar cotações aleatórias para as criptomoedas em um valor entre -5% e +5%
void gerar_cotacoes_aleatorias() {
    double variacao_bitcoin = ((rand() % 100 - 50) / 100.0) * 0.05;
    double variacao_eth = ((rand() % 100 - 50) / 100.0) * 0.05; 
    double variacao_rip = ((rand() % 100 - 50) / 100.0) * 0.05; 

    cot_bitcoin += cot_bitcoin * variacao_bitcoin;
    cot_eth += cot_eth * variacao_eth;
    cot_rip += cot_rip * variacao_rip;

    // Garantir que as cotações não sejam negativas
    if (cot_bitcoin < 0) cot_bitcoin = 0;
    if (cot_eth < 0) cot_eth = 0;
    if (cot_rip < 0) cot_rip = 0;

    printf("Cotações atualizadas:\n");
    printf("Bitcoin: R$%.3f\n", cot_bitcoin);
    printf("Ethereum: R$%.3f\n", cot_eth);
    printf("Ripple: R$%.2f\n", cot_rip);
}

// Função para atualizar as cotações
void atualizar_cotacao() {
    gerar_cotacoes_aleatorias();
}
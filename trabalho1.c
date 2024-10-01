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

// Função para comprar criptomoedas
void comprar_criptomoedas(Usuario *usuario) {
    printf("Escolha a criptomoeda que deseja comprar:\n");
    printf("1 - Bitcoin (R$%.3f)\n", cot_bitcoin);
    printf("2 - Ethereum (R$%.3f)\n", cot_eth);
    printf("3 - Ripple (R$%.2f)\n", cot_rip);

    int escolha = input1("Digite o número correspondente à criptomoeda desejada: ");
    double quantidade, custo;

    switch (escolha) {
        case 1:
            quantidade = input2("Digite a quantidade de Bitcoin que deseja comprar: ");
            double tx_bitcoin = cot_bitcoin * 1.02; // Taxa de 2%
            custo = quantidade * tx_bitcoin; // Custo total incluindo taxa

            printf("O custo total será R$%.3f. Tem certeza que deseja continuar? (1 para Sim, 0 para Não)\n", custo);
            int confirmacao_btc = input1("Confirme sua escolha: ");
            if (confirmacao_btc == 1) {
                if (custo <= usuario->saldo) {
                    usuario->saldo -= custo;
                    usuario->valor_btc += quantidade;
                    char transacao[100];
                    snprintf(transacao, 100, "+ %.2f BITCOIN (Custo: %.3f)\n", quantidade, custo);
                    strcpy(usuario->extrato[usuario->transacao_atual++], transacao);
                    printf("%.2f Bitcoin comprado com sucesso!\n", quantidade);
                } else {
                    printf("Saldo insuficiente.\n");
                }
            } else {
                printf("Compra cancelada.\n");
            }
            break;

        case 2:
            quantidade = input2("Digite a quantidade de Ethereum que deseja comprar: ");
            double tx_eth = cot_eth * 1.01; // Taxa de 1%
            custo = quantidade * tx_eth;

            printf("O custo total será R$%.3f. Tem certeza que deseja continuar? (1 para Sim, 0 para Não)\n", custo);
            int confirmacao_eth = input1("Confirme sua escolha: ");
            if (confirmacao_eth == 1) {
                if (custo <= usuario->saldo) {
                    usuario->saldo -= custo;
                    usuario->valor_eth += quantidade;
                    char transacao[100];
                    snprintf(transacao, 100, "+ %.2f ETHEREUM (Custo: %.3f)\n", quantidade, custo);
                    strcpy(usuario->extrato[usuario->transacao_atual++], transacao);
                    printf("%.2f Ethereum comprado com sucesso!\n", quantidade);
                } else {
                    printf("Saldo insuficiente.\n");
                }
            } else {
                printf("Compra cancelada.\n");
            }
            break;

        case 3:
            quantidade = input2("Digite a quantidade de Ripple que deseja comprar: ");
            double tx_ripple = cot_rip * 1.01; // Taxa de 1%
            custo = quantidade * tx_ripple;

            printf("O custo total será R$%.3f. Tem certeza que deseja continuar? (1 para Sim, 0 para Não)\n", custo);
            int confirmacao_rip = input1("Confirme sua escolha: ");
            if (confirmacao_rip == 1) {
                if (custo <= usuario->saldo) {
                    usuario->saldo -= custo;
                    usuario->valor_rip += quantidade;
                    char transacao[100];
                    snprintf(transacao, 100, "+ %.2f RIPPLE (Custo: %.3f)\n", quantidade, custo);
                    strcpy(usuario->extrato[usuario->transacao_atual++], transacao);
                    printf("%.2f Ripple comprado com sucesso!\n", quantidade);
                } else {
                    printf("Saldo insuficiente.\n");
                }
            } else {
                printf("Compra cancelada.\n");
            }
            break;

        default:
            printf("Opção inválida.\n");
            break;
    }
}
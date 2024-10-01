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

// Função para vender criptomoedas
void vender_criptomoedas(Usuario *usuario) {
    printf("Escolha a criptomoeda que deseja vender:\n");
    printf("1 - Bitcoin\n");
    printf("2 - Ethereum\n");
    printf("3 - Ripple\n");

    int escolha = input1("Digite o número correspondente à criptomoeda desejada: ");
    double quantidade, receita;

    switch (escolha) {
        case 1:
            quantidade = input2("Digite a quantidade de Bitcoin que deseja vender: ");
            if (quantidade <= 0) {
                printf("Quantidade inválida. Insira um valor positivo.\n");
                break;
            }
            if (quantidade <= usuario->valor_btc) {
                printf("Tem certeza que deseja vender %.2f Bitcoin? (1 para Sim, 0 para Não)\n", quantidade);
                int confirmacao = input1("Confirme sua escolha: ");
                if (confirmacao == 1) {
                    receita = quantidade * cot_bitcoin;
                    usuario->saldo += receita;
                    usuario->valor_btc -= quantidade;
                    char transacao[100];
                    snprintf(transacao, 100, "- %.2f BITCOIN (Receita: %.3f)\n", quantidade, receita);
                    strcpy(usuario->extrato[usuario->transacao_atual++], transacao);
                    printf("%.2f Bitcoin vendido com sucesso!\n", quantidade);
                } else {
                    printf("Venda cancelada.\n");
                }
            } else {
                printf("Quantidade insuficiente. Você possui apenas %.2f Bitcoin.\n", usuario->valor_btc);
            }
            break;

        case 2:
            quantidade = input2("Digite a quantidade de Ethereum que deseja vender: ");
            if (quantidade <= 0) {
                printf("Quantidade inválida. Insira um valor positivo.\n");
                break;
            }
            if (quantidade <= usuario->valor_eth) {
                printf("Tem certeza que deseja vender %.2f Ethereum? (1 para Sim, 0 para Não)\n", quantidade);
                int confirmacao = input1("Confirme sua escolha: ");
                if (confirmacao == 1) {
                    receita = quantidade * cot_eth;
                    usuario->saldo += receita;
                    usuario->valor_eth -= quantidade;
                    char transacao[100];
                    snprintf(transacao, 100, "- %.2f ETHEREUM (Receita: %.3f)\n", quantidade, receita);
                    strcpy(usuario->extrato[usuario->transacao_atual++], transacao);
                    printf("%.2f Ethereum vendido com sucesso!\n", quantidade);
                } else {
                    printf("Venda cancelada.\n");
                }
            } else {
                printf("Quantidade insuficiente. Você possui apenas %.2f Ethereum.\n", usuario->valor_eth);
            }
            break;

        case 3:
            quantidade = input2("Digite a quantidade de Ripple que deseja vender: ");
            if (quantidade <= 0) {
                printf("Quantidade inválida. Insira um valor positivo.\n");
                break;
            }
            if (quantidade <= usuario->valor_rip) {
                printf("Tem certeza que deseja vender %.2f Ripple? (1 para Sim, 0 para Não)\n", quantidade);
                int confirmacao = input1("Confirme sua escolha: ");
                if (confirmacao == 1) {
                    receita = quantidade * cot_rip;
                    usuario->saldo += receita;
                    usuario->valor_rip -= quantidade;
                    char transacao[100];
                    snprintf(transacao, 100, "- %.2f RIPPLE (Receita: %.3f)\n", quantidade, receita);
                    strcpy(usuario->extrato[usuario->transacao_atual++], transacao);
                    printf("%.2f Ripple vendido com sucesso!\n", quantidade);
                } else {
                    printf("Venda cancelada.\n");
                }
            } else {
                printf("Quantidade insuficiente. Você possui apenas %.2f Ripple.\n", usuario->valor_rip);
            }
            break;

        default:
            printf("Opção inválida.\n");
            break;
    }
}

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

// Função para verificar a senha antes de permitir o saque do usuário
int verificar_senha(Usuario *usuario) {
    int senha = input1("Digite sua senha para sacar: ");
    return (senha == usuario->senha);
}

// Função para sacar da conta
void sacar(Usuario *usuario) {
    if (!verificar_senha(usuario)) {
        printf("Senha incorreta. Saque não permitido.\n");
        return;
    }

    double quantia = input2("Digite a quantidade do saque: ");
    if (quantia <= usuario->saldo) {
        usuario->saldo -= quantia;
        char transacao[100];
        snprintf(transacao, 100, "- %.2f REAL\n", quantia);
        strcpy(usuario->extrato[usuario->transacao_atual++], transacao);
        printf("Saque realizado com sucesso!\nSeu novo saldo é: %.2f\n", usuario->saldo);
    } else {
        printf("Saldo insuficiente.\n");
    }
}
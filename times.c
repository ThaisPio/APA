#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Time {
    char nome_Time[30];
    int pontos;
};

void trocarTimes(struct Time *a, struct Time *b) {
    struct Time temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarPorPontos(struct Time times[], int inicio, int fim) {
    if (inicio < fim) {
        int indice = fim;
        int i = inicio - 1;
        int j;

        for (j = inicio; j <= fim - 1; j++) {
            if (times[j].pontos > times[indice].pontos) {
                i++;
                trocarTimes(&times[i], &times[j]);
            }
        }

        trocarTimes(&times[i + 1], &times[indice]);
        ordenarPorPontos(times, inicio, i);
        ordenarPorPontos(times, i + 2, fim);
    }
}

int main() {
    int opcao, pontosBusca, i; 
    struct Time tabela[] = {
        {"Argentina Grupo A", 9},
        {"Canada Grupo A", 4},
        {"Chile Grupo A", 2},
        {"Peru Grupo A", 1},
        {"Venezuela Grupo B", 9},
        {"Equador Grupo B", 4},
        {"Mexico Grupo B", 4},
        {"Jamaica Grupo B", 0},
        {"Uruguai Grupo C", 9},
        {"Panama Grupo C", 6},
        {"Estados Unidos Grupo C", 3},
        {"Colombia Grupo D", 7},
        {"Brasil Grupo D", 5},
        {"Costa Rica Grupo D", 4},
        {"Paraguai Grupo D", 0}
        
    };

    do {
        printf("1. Retornar o Nome com base na quantidade de pontos\n");
        
        printf("2. Reordenar a tabela para exibir os times com base na quantidade de pontos\n");
        
		printf("3. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe a quantidade de pontos: ");
                scanf("%d", &pontosBusca);

            for (i = 0; i < sizeof(tabela) / sizeof(tabela[0]); i++) {
                    if (tabela[i].pontos == pontosBusca) {
                        printf("Time: %s\n", tabela[i].nome_Time);
                   }
                }
                break;

            case 2:
                ordenarPorPontos(tabela, 0, sizeof(tabela) / sizeof(tabela[0]) - 1);
                int metade = sizeof(tabela) / sizeof(tabela[0]);

                for (i = 0; i < metade; i++) {
                    printf("Posicao: %d, Time: %s, Pontos: %d\n", i + 1, tabela[i].nome_Time, tabela[i].pontos);
                }
                break;

            case 3:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}


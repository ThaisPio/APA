#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

// Estrutura para armazenar informa��es sobre a an�lise do c�digo
typedef struct {
    int loops;
    int passos; // Contagem de passos
    int chamadas_recursivas;
    bool eh_algoritmo_ordenacao;
    bool eh_probabilistico;
    bool eh_programacao_dinamica;
    bool eh_backtracking;
    bool eh_recursivo;
    bool eh_guloso;
    bool eh_divide_conquista;
    char melhor_caso[20];
    char pior_caso[20];
} AnaliseCodigo;

// Fun��o para inicializar os valores da an�lise
void inicializar_analise(AnaliseCodigo *analise) {
    analise->loops = 0;
    analise->passos = 0;
    analise->chamadas_recursivas = 0;
    analise->eh_algoritmo_ordenacao = false;
    analise->eh_probabilistico = false;
    analise->eh_programacao_dinamica = false;
    analise->eh_backtracking = false;
    analise->eh_recursivo = false;
    analise->eh_guloso = false;
    analise->eh_divide_conquista = false;
    strcpy(analise->melhor_caso, "N/A");
    strcpy(analise->pior_caso, "N/A");
}

// Fun��o para identificar o tipo de algoritmo e t�cnica usada
void analisar_codigo(FILE *arquivo, AnaliseCodigo *analise) {
    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo)) {
        // Contagem de loops (for ou while)
        if (strstr(linha, "for") || strstr(linha, "while")) {
            analise->loops++;
            analise->passos++; // Incrementa o n�mero de passos por loop
        }
        
        // Contagem de passos em atribui��es e c�lculos
        if (strstr(linha, "=") && !strstr(linha, "==")) {
            analise->passos++; // A cada atribui��o, contamos um passo
        }

        // Contagem de passos para recurs�o
        if (strstr(linha, "fibonacci(") || strstr(linha, "collatz(") || strstr(linha, "imprimirSubconjunto(")) {
            analise->chamadas_recursivas++;
            analise->eh_recursivo = true;
            analise->passos++; // Incrementa o n�mero de passos para cada chamada recursiva
        }

        // Identifica��o de dividir para conquistar (ex: Merge Sort)
        if (strstr(linha, "mergeSort(") || strstr(linha, "merge(")) {
            analise->eh_divide_conquista = true;
            strcpy(analise->melhor_caso, "O(n log n)");
            strcpy(analise->pior_caso, "O(n log n)");
        }

        // Identifica��o de backtracking (gera��o de solu��es alternativas)
        if (strstr(linha, "imprimirSubconjunto(") || strstr(linha, "solveNQUtil(")) {
            analise->eh_backtracking = true;
            strcpy(analise->melhor_caso, "O(2^n)");
            strcpy(analise->pior_caso, "O(2^n)");
        }

        // Identifica��o de programa��o din�mica (uso de tabelas/matrizes)
        if (strstr(linha, "int f[") || strstr(linha, "double f[") || strstr(linha, "fibonacci") || strstr(linha, "moedas")) {
            analise->eh_programacao_dinamica = true;
            strcpy(analise->melhor_caso, "O(n)");
            strcpy(analise->pior_caso, "O(n^2)");
        }

        // Identifica��o de algoritmos probabil�sticos (uso de probabilidade/aleatoriedade)
        if (strstr(linha, "rand(") || strstr(linha, "probabilidade") || strstr(linha, "p[")) {
            analise->eh_probabilistico = true;
            strcpy(analise->melhor_caso, "O(n)");
            strcpy(analise->pior_caso, "Depende do randomizador");
        }

        // Identifica��o de programa��o gulosa (decis�es locais �timas)
        if (strstr(linha, "knapsack(") || strstr(linha, "ratio")) {
            analise->eh_guloso = true;
            strcpy(analise->melhor_caso, "O(n log n)");
            strcpy(analise->pior_caso, "O(n log n)");
        }

        // Identifica��o de algoritmos de ordena��o interna 
        if (strstr(linha, "insertionSort(") || (strstr(linha, "for") && strstr(linha, "j = i"))) {
            analise->eh_algoritmo_ordenacao = true;
            strcpy(analise->melhor_caso, "O(n)");
            strcpy(analise->pior_caso, "O(n^2)");
        }
    }
}

// Fun��o para exibir os resultados da an�lise e fornecer melhor/pior caso
void exibir_resultados(AnaliseCodigo *analise) {
    printf("\n--- Resultados da An�lise ---\n");
    printf("N�mero de Loops: %d\n", analise->loops);
    printf("N�mero de Passos: %d\n", analise->passos);
    printf("N�mero de Chamadas Recursivas: %d\n", analise->chamadas_recursivas);

    // Classifica��o do tipo de algoritmo
    if (analise->eh_algoritmo_ordenacao) {
        printf("Tipo de Algoritmo: Ordena��o Interna\n");
    }
    if (analise->eh_recursivo) {
        printf("Tipo de Algoritmo: Recurs�o\n");
    }
    if (analise->eh_divide_conquista) {
        printf("T�cnica Utilizada: Dividir para Conquistar\n");
    }
    if (analise->eh_backtracking) {
        printf("T�cnica Utilizada: Backtracking\n");
    }
    if (analise->eh_programacao_dinamica) {
        printf("T�cnica Utilizada: Programa��o Din�mica\n");
    }
    if (analise->eh_probabilistico) {
        printf("T�cnica Utilizada: Algoritmo Probabil�stico\n");
    }
    if (analise->eh_guloso) {
        printf("T�cnica Utilizada: Programa��o Gulosa\n");
    }

    // Exibir melhor e pior caso
    printf("Complexidade Melhor Caso: %s\n", analise->melhor_caso);
    printf("Complexidade Pior Caso: %s\n", analise->pior_caso);

    if (!analise->eh_algoritmo_ordenacao && !analise->eh_recursivo &&
        !analise->eh_backtracking && !analise->eh_programacao_dinamica &&
        !analise->eh_probabilistico && !analise->eh_guloso && !analise->eh_divide_conquista) {
        printf("T�cnica Utilizada: N�o identificada automaticamente\n");
    }
}

// Fun��o principal para abrir o arquivo e realizar a an�lise
int main() {
    setlocale(LC_ALL, ""); 

    // Nome do arquivo que ser� aberto automaticamente
    char nome_do_arquivo[] = "moedas.c";
    
    FILE *arquivo;
    AnaliseCodigo analise;

    // Inicializar a an�lise
    inicializar_analise(&analise);

    // Abrir o arquivo automaticamente
    arquivo = fopen(nome_do_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", nome_do_arquivo);
        return 1;
    }

    // Exibir o conte�do do arquivo
    printf("\n--- Conte�do do Arquivo %s ---\n", nome_do_arquivo);
    char ch;
    while ((ch = fgetc(arquivo)) != EOF) {
        putchar(ch);
    }
    
    // Voltar o ponteiro para o in�cio do arquivo para realizar a an�lise
    rewind(arquivo);

    // Analisar o c�digo lido
    analisar_codigo(arquivo, &analise);

    // Fechar o arquivo
    fclose(arquivo);

    // Exibir os resultados da an�lise
    exibir_resultados(&analise);

    return 0;
}


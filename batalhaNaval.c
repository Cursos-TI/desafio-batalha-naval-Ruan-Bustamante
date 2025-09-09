#include <stdio.h>

// Definições Fixas
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    
    // Definições do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posicionamento do navio1 - Horizontal
    int linha_navio1 = 2;
    int coluna_navio1 = 3;
    char orientacao_navio1 = 'H'; // Para Horizontal

    // Validação navio dentro do tabuleiro
    if (orientacao_navio1 == 'H' && (coluna_navio1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO)) {
        printf("Erro! Navio1 fora dos limites do tabuleiro!\n");
        return 1; // Sai do programa se houver erro
    }

    // Posiciona navio1 no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_navio1][coluna_navio1 + i] = NAVIO;
    }

    // Posicionamento do navio2 - Vertical
    int linha_navio2 = 5;
    int coluna_navio2 = 6;
    char orientacao_navio2 = 'V'; // Para Vertical

    // Validação navio dentro do tabuleiro
    if (orientacao_navio2 == 'V' && (linha_navio2 + TAMANHO_NAVIO > TAMANHO_TABULEIRO)) {
        printf("Erro! Navio2 fora dos limites do tabuleiro!\n");
        return 1; // Sai do programa se houver erro
    }

    // Posiciona navio2 no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_navio2 + i][coluna_navio2] = NAVIO;
    }

    // Exibe o tabuleiro
    printf("\n--- Tabuleiro Batalha Naval ---\n");

    // Imprime o cabecalho das colunas
    printf("  "); // Espaço para alinhar com as linhas
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("%d ", col); // Imprime o numero da coluna
    }
    printf("\n");

    // Loops aninhados para percorrer e imprimir a matriz
    for (int i = 0; i < TAMANHO_TABULEIRO; i++){
        printf("%d ", i); // Imprime o numero da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++){
            printf("%d ", tabuleiro[i][j]); // Imprime 0=água e 3=navio com espaço para alinhamento
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }

    


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}

#include <stdio.h>

// Definições Fixas
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para determinar se a posição do Navio é válida
int posicao_valida (int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int l, int c);


int main() {
    
    // Definições do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas dos navios

    // Navio 1: Horizontal
    int linha_navio1 = 1;
    int coluna_navio1 = 1;

    // Navio 2: Vertical
    int linha_navio2 = 3;
    int coluna_navio2 = 7;

    // Navio 3: Diagonal Crescente
    int linha_navio3 = 5;
    int coluna_navio3 = 5;

    // Navio 4: Diagonal Decrescente
    int linha_navio4 = 3;
    int coluna_navio4 = 5;

    // Posicionando os navios
    int valido = 1; // Flag para verificar a validade da posição antes de posicionar

    // Navio 1: Horizontal
   valido = 1;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        // Se alguma posição for invalida, a validação falha
        if (!posicao_valida(tabuleiro, linha_navio1, coluna_navio1 + i)) {
            valido = 0; // Marca como falha
            break;
        }
    }
    if (valido) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_navio1][coluna_navio1 + i] = NAVIO;
        }
    }  else {
            printf("Erro ao posicionar Navio 1: Horizontal.\n");
    }

    // Navio 2: Vertical
    valido = 1;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!posicao_valida(tabuleiro, linha_navio2 + i, coluna_navio2)) {
            valido = 0; // Marca como falha
            break;
        }
    }
    if (valido) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_navio2 + i][coluna_navio2] = NAVIO;
        }
        } else {
            printf("Erro ao posicionar Navio 2: Vertical.\n");
    }

    // Navio 3: Diagonal Crescente
    valido = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (!posicao_valida(tabuleiro, linha_navio3 + i, coluna_navio3 + i)) {
                valido = 0; // Marca como falha
                break;
            }
        }
        if (valido) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio3 + i][coluna_navio3 + i] = NAVIO;
            }
            } else {
                printf("Erro ao posicionar Navio 3: Diagonal Crescente.\n");
        }

    // Navio 4: Diagonal Decrescente
    valido = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (!posicao_valida(tabuleiro, linha_navio4 + i, coluna_navio4 - i)) {
                valido = 0; // Marca como falha
                break;
            }
        }
        if (valido) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio4 + i][coluna_navio4 - i] = NAVIO;
            }
            } else {
                printf("Erro ao posicionar Navio 4: Diagonal Decrescente.\n");
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

    return 0;
}

// Funcao para verificar se a posicao e valida
// Retorna 1 se a posicao e valida, 0 caso contrario
int posicao_valida(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int l, int c) {
    // Verifica se esta dentro dos limites do tabuleiro (0 a 9)
    if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO) {
        return 0; // Fora dos limites do tabuleiro
    } 
    // Verifica se a posicao ja esta ocupada por um navio
    if (tabuleiro[l][c] != AGUA) {
        return 0; // Ja ocupado
    }
    return 1; // Posicao valida
}
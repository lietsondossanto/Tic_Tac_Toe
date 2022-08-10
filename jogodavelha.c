#include <stdio.h>
#include <stdlib.h>

void zeraTabuleiro(char tabuleiro[3][3])
{
    int i;
    int j;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibeTabuleiro(char tabuleiro[3][3])
{
    int i;
    int j;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%c |", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void jogada(char tabuleiro[3][3], char player)
{
    int x, y;

    while(1) {
        printf("Digite a posicao de jogada para %c: ", player);
        scanf("%d %d", &x, &y);

        if ((x > 2 || y > 2) || (x < 0 || y < 0)) {
            printf("Posicao valida!\n\n");
        }else if (tabuleiro[x][y] == ' ') {
            tabuleiro[x][y] = player;
            break;
        } else {
            printf("Essa posicao nao pode ser utilizada!\n\n");
        }
    }
}

int validarTabuleiro(char tabuleiro[3][3], char player)
{
    int i;
    int j;

    // Validar as Linhas
    for(i = 0; i < 3; i++) {
        if( tabuleiro[i][0] != ' '
            &&tabuleiro[i][0] == tabuleiro[i][1]
            && tabuleiro[i][1] == tabuleiro[i][2]) {
            return 1;
        }
    }

    // Validar as Columas
    for(j = 0; j < 3; j++) {
        if( tabuleiro[0][j] != ' '
            &&tabuleiro[0][j] == tabuleiro[1][j]
            && tabuleiro[1][j] == tabuleiro[2][j]) {
            return 1;
        }
    }

    // Validar as Diagonais
    if( tabuleiro[0][0] != ' '
        &&tabuleiro[0][0] == tabuleiro[1][1]
        && tabuleiro[1][1] == tabuleiro[2][2]) {
        return 1;
    }

    if( tabuleiro[0][2] != ' '
        &&tabuleiro[0][2] == tabuleiro[1][1]
        && tabuleiro[1][1] == tabuleiro[2][0]) {
        return 1;
    }

    return 0;
}

int verificaEmpate(char tabuleiro[3][3])
{
    int i;
    int j;

    for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if(tabuleiro[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    char tabuleiro[3][3];
    char c1 = 'X';
    char c2 = 'O';
    char player = c1;

    zeraTabuleiro(tabuleiro);
    exibeTabuleiro(tabuleiro);

    while (1) {
        jogada(tabuleiro, player);
        exibeTabuleiro(tabuleiro);

        if(validarTabuleiro(tabuleiro, player) == 1) {
            printf("O player %c GANHOU!!!\n", player);
            break;
        }

        if (verificaEmpate(tabuleiro) == 1) {
            printf("Houve um EMPATE!!!\n", player);
            break;
        }

        if (player == c1) {
            player = c2;
        } else {
            player = c1;
        }
    }

    printf("FIM DO JOGO\n\n\n");
    return 0;
}

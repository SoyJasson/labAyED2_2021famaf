#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define BOARD_SIZE 3
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int cell = 0;
    printf("\t .................................................\n");
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        printf("\t .................................................\n");
    }
}

char get_winner(char board[BOARD_SIZE][BOARD_SIZE])
{
    board = board;
    char winner = '-';

    for (int i = 0; i < BOARD_SIZE; ++i) {
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            winner = board[i][0];
        };
        if(board[1][i] != '-' && board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            winner = board[0][i];
        };
    };
    if(board[1][1] != '-' && ((board[0][0] == board[1][1] && board[2][2] == board[1][1]) || (board[0][2] == board[1][1] && board[2][0] == board[1][1]))){
            winner = board[1][1];
        };

    return winner;
}

bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE])
{
    board = board;

    bool hayEspacio = false;
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            hayEspacio |= board[row][column] == '-';
        };
    };

    return hayEspacio;
}

int main(void)
{
    printf("TicTacToe [Completo B)]\n");

    char board[BOARD_SIZE][BOARD_SIZE] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posicion (numero del 0 al 8): ",
               turn);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un numero desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_SIZE;
            int colum = cell % BOARD_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda invalida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Gano %c\n", winner);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char playerTurn;
char freespace[2] = {'_',' '};
char board[9] = {'_','_','_','_','_','_',' ',' ',' '};
char reset;
char move;
int move1;
int winner = 0;

void currentBoard(void)
{
    printf("\n   a   b   c \n1 _%c_|_%c_|_%c_\n2 _%c_|_%c_|_%c_\n3  %c | %c | %c\n",
           board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
}

void checkForWin(void)
{
    if((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') ||
        (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') ||
        (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') ||
        (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') ||
        (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') ||
        (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') ||
        (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') ||
        (board[2] == 'X' && board[4] == 'X' && board[6] == 'X'))
        {
            printf("Winner is X!\n");
            currentBoard();
            printf("Would you like to play again? Y/N: ");
            scanf(" %c", &reset);
            reset = toupper(reset);
            if(reset == 'Y')
            {
                board[0] = '_';
                board[1] = '_';
                board[2] = '_';
                board[3] = '_';
                board[4] = '_';
                board[5] = '_';
                board[6] = ' ';
                board[7] = ' ';
                board[8] = ' ';
            }
            else if(reset == 'N')
            {
                winner = 1;
            }
            else
            {
                printf("You didn't type Y on N, please try again.");
                checkForWin();
            }
        }
    else if((board[0] == 'O' && board[1] == 'O' && board[2] == 'O') ||
        (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') ||
        (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') ||
        (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') ||
        (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') ||
        (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') ||
        (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') ||
        (board[2] == 'O' && board[4] == 'O' && board[6] == 'O'))
        {
            printf("Winner is O!\n");
            currentBoard();
            printf("Would you like to play again? Y/N: ");
            scanf(" %c", &reset);
            reset = toupper(reset);
            if(reset == 'Y')
            {
                board[0] = '_';
                board[1] = '_';
                board[2] = '_';
                board[3] = '_';
                board[4] = '_';
                board[5] = '_';
                board[6] = ' ';
                board[7] = ' ';
                board[8] = ' ';
            }
            else if(reset == 'N')
            {
                winner = 1;
            }
            else
            {
                printf("You didn't type Y on N, please try again.");
                checkForWin();
            }
        }
    else if(board[0] != '_' && board[1] != '_' && board[2] != '_' &&
        board[3] != '_' && board[4] != '_' && board[5] != '_' &&
        board[6] != ' ' && board[7] != ' ' && board[8] != ' ')
        {
            currentBoard();
            printf("This game is a draw.\n");
            char reset;
            printf("Would you like to play again? Y/N: ");
            scanf(" %c", &reset);
            reset = toupper(reset);
            if(reset == 'Y')
            {
                board[0] = '_';
                board[1] = '_';
                board[2] = '_';
                board[3] = '_';
                board[4] = '_';
                board[5] = '_';
                board[6] = ' ';
                board[7] = ' ';
                board[8] = ' ';
            }
            else if(reset == 'N')
            {
                winner = 1;
            }
            else
            {
                printf("You didn't type Y on N, please try again.");
                checkForWin();
            }
        }
}

void playerSwitch(void)
{
    if(playerTurn == 'X')
        {
            playerTurn = 'O';
        }
        else
        {
            playerTurn = 'X';
        }
}


int main()
{
    printf("Welcome to a console based Tic Tac Toe written in C By Chris Alessandro\n");
    printf("Who will go first X or O?: ");
    scanf(" %c" , &playerTurn);

    while(winner == 0)
    {
        currentBoard();
        printf("Player %c enter the space you want e.g a1: ", playerTurn);
        scanf(" %c%d", &move, &move1);
        move = tolower(move);
        if((move == 'a') && (move1 == 1) && (board[0] == freespace[0]))
        {
            board[0] = playerTurn;
            playerSwitch();
            checkForWin();
        }
        else if((move == 'b') && (move1 == 1) && (board[1] == freespace[0]))
        {
            board[1] = playerTurn;
            playerSwitch();
            checkForWin();
        }
        else if((move == 'c') && (move1 == 1) && (board[2] == freespace[0]))
        {
            board[2] = playerTurn;
            playerSwitch();
            checkForWin();
        }
        else if((move == 'a') && (move1 == 2) && (board[3] == freespace[0]))
        {
            board[3] = playerTurn;
            playerSwitch();
            checkForWin();
        }
        else if((move == 'b') && (move1 == 2) && (board[4] == freespace[0]))
        {
            board[4] = playerTurn;
            playerSwitch();
            checkForWin();
        }
        else if((move == 'c') && (move1 == 2) && (board[5] == freespace[0]))
        {
            board[5] = playerTurn;
            playerSwitch();
            checkForWin();
        }
        else if((move == 'a') && (move1 == 3) && (board[6] == freespace[1]))
        {
            board[6] = playerTurn;
            playerSwitch();
            checkForWin();
        }
        else if((move == 'b') && (move1 == 3) && (board[7] == freespace[1]))
        {
            board[7] = playerTurn;
            playerSwitch();
            checkForWin();
        }
        else if((move == 'c') && (move1 == 3) && (board[8] == freespace[1]))
        {
            board[8] = playerTurn;
            playerSwitch();
            checkForWin();
        }
        else
        {
            printf("Error, this space is taken or you entered an incorrect space.\n");
        }
    }
    return 0;
}


 <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard()
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkWinner()
{
    int i;

    // Check rows and columns
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;

        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return 1;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;

    return 0;
}

int main()
{
    int choice, row, col, moves = 0;
    char player = 'X';

    while (moves < 9)
    {
        displayBoard();

        printf("Player %c, enter a position (1-9): ", player);

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        if (choice < 1 || choice > 9)
        {
            printf("Choose a number between 1 and 9.\n");
            continue;
        }

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            printf("That position is already occupied!\n");
            continue;
        }

        board[row][col] = player;
        moves++;

        if (checkWinner())
        {
            displayBoard();
            printf("Player %c wins!\n", player);
            return 0;
        }

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    displayBoard();
    printf("It's a draw!\n");

    return 0;
}

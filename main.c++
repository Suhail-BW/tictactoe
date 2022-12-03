#include <iostream>
using namespace std;
#define MAX_MOVES 9
// function to print our tic tac toe board
void print_board(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j] << "\t\t";
        }
        cout << "\n";
        for (int k = 0; k < 3; k++)
        {
            cout << "---\t\t";
        }
        cout << "\n";
    }
}
// function to check diagonally win
bool check_diag(char board[3][3])
{
    bool flag = false;
    if ((board[0][0] == 'X' && board[2][2] == 'X' && board[1][1] == 'X') || (board[0][2] == 'X' && board[2][0] == 'X' && board[1][1] == 'X'))
    {
        flag = true;
        cout << "######## X won the game diagonally ##########" << endl;
    }
    else if ((board[0][0] == 'O' && board[2][2] == 'O' && board[1][1] == 'O') || (board[0][2] == 'O' && board[2][0] == 'O' && board[1][1] == 'O'))
    {
        flag = true;
        cout << "########### O won the game diagonally ##########" << endl;
    }
    return flag;
}
// fucntion to check horizontally win
bool check_horizon(char board[3][3])
{
    bool flag = false;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
        {
            cout << "######### X won horizontally ###########" << endl;
            flag = true;
            break;
        }
        else if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
        {
            cout << "############ O won horizontally ############" << endl;
            flag = true;
            break;
        }
    }
    return flag;
}
// function to check vertically win
bool check_vertic(char board[3][3])
{
    bool flag = false;
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
        {
            cout << "########### X won vertically ###########" << endl;
            flag = true;
            break;
        }
        else if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
        {
            cout << "######### O won vertically #########" << endl;
            flag = true;
            break;
        }
    }
    return flag;
}
// function to write X symbol into our board
void write_X(char (&board)[3][3], int &a, int &b)
{
    cout << "Enter the x coordinate for X: ";
    cin >> a;
    cout << "Enter the y cordinate for X: ";
    cin >> b;
    while (board[a][b] == 'X' || board[a][b] == 'O')
    {
        cout << "Postion already taken re-enter: ";
        cin >> a >> b;
        continue;
    }
    cout << "\n";
    board[a][b] = 'X';
}
// function to write O symbol into out board
void write_O(char (&board)[3][3], int &a, int &b)
{
    cout << "Enter the x cordinate for O: ";
    cin >> a;
    cout << "Enter the y cordinate for O: ";
    cin >> b;
    while (board[a][b] == 'X' || board[a][b] == 'O')
    {
        cout << "Postion already taken re-enter: ";
        cin >> a >> b;
        continue;
    }
    cout << "\n";
    board[a][b] = 'O';
}
int main()
{
    int a, b;
    char board[3][3] = {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};
    bool game_is_on = true;
    int number_of_moves = 0;
    while (game_is_on)
    {
        write_X(board, a, b);
        game_is_on = !(check_horizon(board) || check_vertic(board) || check_diag(board));
        print_board(board);
        if (!game_is_on)
        {
            break;
        }
        ++number_of_moves;
        if (number_of_moves >= MAX_MOVES)
        {
            cout << "#########--Match drawn and the value of i is--##########" << endl;
            print_board(board);
            break;
        }
        write_O(board, a, b);
        game_is_on = !(check_horizon(board) || check_vertic(board) || check_diag(board));
        print_board(board);
        if (!game_is_on)
        {
            break;
        }
        ++number_of_moves;
    }

    return 0;
}
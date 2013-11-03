#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

char board[9];

void drawBoard();
char winCheck();
bool tieCheck();

int main()
{
    char P1, P2, input;
    int location;
    bool turn, quit = false;
    while (!quit)
    {
        for (int i = 0; i < 9; i++)
            board[i] = ' ';
        cout << "Player 1 choose your character: ";
        do
        {
            cin >> P1;
        }
        while (P1 == ' ');
        cout << "Player 2 choose your character: ";
        do
        {
            cin >> P2;
        }
        while (P2 == P1 || P2 == ' ');

        srand(time(NULL));
        turn = rand() % 2;
        while(winCheck() == ' ' && !tieCheck())
        {
            drawBoard();
            cout << "Player " << (turn ? "1" : "2") << " where do you want to go? (1-9)\n";
            do
            {
                cin >> location;
            }
            while (location < 1 || location > 10 || board[location - 1] != ' ');
            board[location - 1] = (turn ? P1 : P2);
            turn = !turn;
        }
        if (winCheck() == P1)
            cout << "Congratulation Player 1!\n";
        else if (winCheck() == P2)
            cout << "Congratulation Player 2!\n";
        else
            cout <<"Tie Game\n";

        cout << "Play again? (Y/N)\n";
        cin >> input;
        if (toupper(input) == 'N')
            quit = true;
    }
    system("PAUSE");
    return 0;
}

void drawBoard()
{
    system("CLS");
    cout << endl;
    cout << "\t" << board[0] << (char)179 << board[1] << (char)179 << board[2]
         << "    1" << (char)179 << "2" << (char)179 << "3\n";
    cout << "\t" << (char)196 << (char)197 << (char)196 << (char)197 << (char)196
         << "    " << (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << endl;
    cout << "\t" << board[3] << (char)179 << board[4] << (char)179 << board[5]
         << "    4" << (char)179 << "5" << (char)179 << "6\n";
    cout << "\t" << (char)196 << (char)197 << (char)196 << (char)197 << (char)196
         << "    " << (char)196 << (char)197 << (char)196 << (char)197 << (char)196 << endl;
    cout << "\t" << board[6] << (char)179 << board[7] << (char)179 << board[8]
         << "    7" << (char)179 << "8" << (char)179 << "9\n\n";
}

char winCheck()
{
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')//top
        return board[0];
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')//diagnal right down
        return board[0];
    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')//left
        return board[0];
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')//middle h
        return board[3];
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')//bottom
        return board[6];
    if (board[6] == board[4] && board[4] == board[2] && board[6] != ' ')//diagnal right up
        return board[6];
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')//middle v
        return board[1];
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')//right
        return board[2];
    return ' ';
}

bool tieCheck()
{
	for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
            return false;
    }
    return true;
}





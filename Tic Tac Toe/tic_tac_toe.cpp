#include<iostream>
#include<vector>
using namespace std;



/* Rules of this game : -
 -> This game is developed on a 3x3 grid
 -> This game is designed for two players.
 -> Every player may choose a letter b/w X and O
 -> Both will get a changes to turn by turn

 Note -> using data structure to provide the basic operations of the game.
*/

void drawBoard(const vector<vector<char>> &board){
    cout << "-------------\n";
    for(int i = 0 ; i < 3 ; i++){
        cout << "| ";
        for(int j = 0 ; j < 3 ; j++){
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool checkTheWinner(const vector<vector<char>>&board,char player){
    // check for rows,cols,and diagonals

    for(int i = 0 ; i < 3 ; i++){
        // for checking the whole row
        if(player == board[0][i] && player == board[1][i] && player == board[2][i])return true;
        // for checking the whole column
        if(player == board[i][0] && player == board[i][1] && player == board[i][2])return true;
    }

    // for diagonally we have only two options [top left to bottom right] or [top right to bottom left]
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)return true;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)return true;
    return false; 
}


int main()
{
   vector<vector<char>> board(3,vector<char>(3,' '));
   char player = 'X';

   int row,col;
   int turn;


   // Game loop will run 9 times
   for(turn = 0 ; turn < 9 ; turn++){
       drawBoard(board);

       // run till i get valid input..
       while(true){
        cout << "Player " << player << ", enter row(0-2) and column (0-2): ";
        
        cin >> row >> col;
        // check if row and col are valid or not  -> if valid then exit
        if(row >=0 && row<=2 && col>=0 && col<=2 && board[row][col] == ' ')break;
        else cout << "Invalid move. Try again.\n";
       }

       board[row][col] = player;

       // check if the current player is winner after making the move or not.
       if(checkTheWinner(board,player)){
        drawBoard(board);
        cout << "Player " << player << " wins!\n";
        break;
       }

       // now switch to another player
       player = (player == 'X') ? 'O' : 'X';
   }

   // game ends
   drawBoard(board);
  
   // check for a draw
   if(turn == 9 && !checkTheWinner(board,'X') && !checkTheWinner(board,'O'))cout << "It's a draw!\n";

   return 0;
}
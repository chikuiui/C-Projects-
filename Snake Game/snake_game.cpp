#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;


/* Snake game

   Rules :-

   -> Don't hit a wall and don't bite your own tail.
   -> Crashing into a wall or your tail will end the game immediately.
   -> 10 points will be added to the player's score for eating the fruit(#)
   -> The player total score is calculated based on the number of fruits the snake consumed.
   -> The length of the snake will increase after eating the fruits.
   -> User w,a,s,d to move the snake (IMP)


   Libraries :-

      iostream -> standard imput / output library of C++
      windows.h -> windows API library
      conio.h -> non-standard library that contains console commands.
*/


// for boundary
const int WIDTH = 80;
const int HEIGHT = 20;

// snake head coordinates (x-axis,y-axis)
int x,y;

// food coordinates.
int fruitX,fruitY;

// variable to store player score.
int playerScore;

// Array to store the coordinates of snake tail (x-axis,y-axis)
int snakeTailX[100],snakeTailY[100];

// variable to store the length of the snake's tail
int snakeTailLength;

// for storing snake's movind snakesDirection
enum snakeDirection {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

// snake direction variable using enum
snakeDirection sDir;

// boolean to check whether the game is over or not.
bool isGameOver;


// Initialize the game 
void gameInit(){
    isGameOver = false;

    sDir = STOP;
    // snake initial location
    x = WIDTH/2;
    y = HEIGHT/2;

    // fruit random location
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    // player initial score
    playerScore = 0;
}


// Create a function for creating the game board and rendering the game whenever needed in the console.
void gameRender(const string &playerName){
    system("cls"); // clear the console.

    // creating the top walls with '-'
    for(int i = 0 ; i < WIDTH+2 ; i++)cout << '-';
    cout << endl;


    for(int i = 0 ; i < HEIGHT ; i++){
        for(int j = 0 ; j <= WIDTH ; j++){
            
            // creating side walls with '|'
            if(j == 0 || j == WIDTH)cout << "|";
            
            // creating the snake's head with 'O'
            if(i == y && j == x)cout << "O";
            
            // creating the snake's food with '#'
            else if(i == fruitY && j == fruitX) cout << "#";

            // creating snake's tail
            else {
                bool prTail = false;
                for(int k = 0 ; k < snakeTailLength ; k++){
                    // for tail
                    if(snakeTailX[k] == j && snakeTailY[k] == i){
                        cout << "o";
                        prTail = true;
                    }
                }
                if(!prTail)cout << " ";
            }

        }
        cout << endl;
    }


    // creating the bottom walls
    for(int i = 0 ; i < WIDTH+2 ; i++)cout << "-";
    cout << endl;

    // display player's score
    cout << playerName << "'s score -> " << playerScore << endl;
}


// create a function to update the game state after each move 
void updateGame(){

    // updating the whole tail to new tail
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];

    int prev2X,prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;

    for(int i = 1 ; i < snakeTailLength ; i++){
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];

        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    // when i press on button sDir changes .
    switch (sDir){
      case LEFT:
        x--;
        break;
      case RIGHT:
        x++;
        break;
      case UP:
        y--;
        break;
      case DOWN:
        y++;
        break;
    }


    // check for snake collision with wall
    if(x >= WIDTH || x < 0 || y >= HEIGHT || y < 0)isGameOver = true;

    // check for collision with the tail
    for(int i = 0 ; i < snakeTailLength ; i++)if(snakeTailX[i] == x && snakeTailY[i] == y)isGameOver = true;
    
    // check for snake's get the food
    if(x == fruitX && y == fruitY){
        playerScore += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        snakeTailLength++;
    }
}


// set the game difficulty
int setDifficulty(){
    int dfc,choice;
    cout << "\nSET DIFFICULTY\n1: Easy\n2: Medium\n3: hard "
            "\nNOTE: if not chosen or pressed any other "
            "key, the difficulty will be automatically set "
            "to medium\nChoose difficulty level: "; 

    cin >> choice;

    switch (choice)
    {
      case 1:
        dfc = 50;
        break;
      case 2:
        dfc = 100;
        break;
      case 3:
        dfc = 150;
        break;
      default:
        dfc = 100;
        break;
    }
    return dfc;
}


// Handling the user input
void userInput(){
    // check if the key is pressed or not
    if(_kbhit()){  // function checks the console for a recent keystroke.
        // Getting the pressed key
        switch (_getch()) // o get the keystroke
        {
          case 'a':
            sDir = LEFT;  
            break;
          case 's':
            sDir = DOWN;  
            break;
          case 'd':
            sDir = RIGHT;  
            break;
          case 'w':
            sDir = UP;  
            break;
          case 'x':
            isGameOver = true;
            break;      
        }
    }
}


// 


int main()
{

   string playerName;
   cout << "Enter your name: ";
   cin >> playerName;

   int dfc = setDifficulty();

   gameInit();

   while(!isGameOver){
     gameRender(playerName);
     userInput();
     updateGame();
     // creating a delay according to the chosen difficulty
     Sleep(dfc);
   }

   
   return 0;
}
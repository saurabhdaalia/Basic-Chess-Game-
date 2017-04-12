#include<iostream>
#include<string>



// pieces are described as integer values
// we will make them constants, so that if at any time we want to change their values we can do so here


const int pawn = 100;
const int bishop = 30;
const int knight = 300;
const int rook = 500;
const int queen = 900;
const int king = 2000;


//now we need a board to put the pieces on and move around on
//the board data type should match the pieces data type

int board[8][8];

// board [rank] [file];
// where rank = 0 - 7 (1 to 8 on a real chess board) and file = 0 - 7 (a - h)

 int startup[8][8] = { rook, knight, bishop, queen, king, bishop, knight, rook, pawn, pawn,pawn,pawn,pawn,pawn,pawn, pawn, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -rook, -knight, -bishop, -queen, -king, -bishop, -knight, -rook};

// the startup constant contains the standard starting position of all chess games
//each side has 8 pieces and 8 pawns / all pawns are on the colours respective ranks
// for black pieces we use -piecetype. (negative)

void setup (void) {
int i, j;
	for (i = 0; i < 8; i++){
		  for (j = 0; j < 8; j++){

			board[i][j] = startup[i][j];
			//setup starting position
	  }
		}

}
//the two for loops run through all the iteratins of the 8x8 array and copy the starting position to the real board.

// next we need a function that will display the board some way either graphics or text
// in this case we will print to the screen a text version of the boards contents

//it is standard in FEN notations and other text of a chess board to express each piece by it's first letter
// except the knight which uses 'N'

// the black pieces are lower case while the white pieces are upper case
// otherwise it is impossible to distinguish black pieces from white pieces

void printb (void){
using namespace std; // this must be here in order to begin using strings.
int m, n;
string piece;
for (m = 0; m<8; m++){
cout << endl<<endl;
 for (n = 0; n< 8; n++){
 switch (board[m][n]){
 case 0:
 piece = "+";
 break;
 case pawn:
 piece = "P";
 break;
 case knight:
 piece = "N";
 break;
 case bishop:
 piece = "B";
 break;
 case rook:
 piece = "R";
 break;
 case queen:
 piece = "Q";
 break;
 case king:
 piece = "K";
 break;
 case -pawn:
 piece = "p";
 break;
 case -knight:
 piece = "n";
 break;
 case -bishop:
 piece = "b";
 break;
 case -rook:
 piece = "r";
 break;
 case -queen:
 piece = "q";
 break;
 case -king:
 piece = "k";
 break;
 }
  cout << "  " << piece << "  ";
 }
}

 cout << endl << endl;
}

int check(int x, int y)
{
    using namespace std;
     char check_pos[8]={'a','b','c','d','e','f','g','h'};

    if(board[x][y]==-100) //for black team player pawn
        {
//****************************************************************************************************************************//
            if(board[x-1][y-1]==100) //for left upper side threat from opposite PAWN.
                 {
                    cout<<"pawn has a threat from pawn located at!"<<" "<<check_pos[y-1]<<x<<endl;
                 }

            if(board[x-1][y+1]==100) //for right upper side threat from opposite PAWN.
                 {
                    cout<<"pawn has a threat from pawn located at!"<<" "<<check_pos[y+1]<<x<<endl;
                 }
//****************************************************************************************************************************///
            if(board[x-1][y-1]==2000)// for left upper side threat from KING.
                 {
                cout<<"Pawn has a threat from King located at! "<<check_pos[y-1]<<x<<endl;
                 }
            if(board[x-1][y+1]==2000)// for right upper side threat from KING.
                 {
                cout<<"Pawn has a threat from King located at! "<<check_pos[y+1]<<x<<endl;
                 }
                 if(board[x+1][y-1]==2000) //for left down side threat from opposite KING.
                 {
                    cout<<"pawn has a threat from pawn located at!"<<" "<<check_pos[y-1]<<x<<endl;
                 }
                 if(board[x+1][y+1]==2000)// for right down side threat from KING.
                 {
                cout<<"Pawn has a threat from King located at! "<<check_pos[y+1]<<x<<endl;
                 }
                 if(board[x-1][y]==2000)// for upper vertical threat from KING.
                 {
                cout<<"Pawn has a threat from King located at! "<<check_pos[y+1]<<x<<endl;
                 }
                 if(board[x+1][y]==2000)// for  down vertical threat from KING.
                 {
                cout<<"Pawn has a threat from King located at! "<<check_pos[y+1]<<x<<endl;
                 }
                 if(board[x][y-1]==2000)// for left side horizontal threat from KING.
                 {
                cout<<"Pawn has a threat from King located at! "<<check_pos[y+1]<<x<<endl;
                 }
                 if(board[x][y+1]==2000)// for right side  horizontal threat from KING.
                 {
                cout<<"Pawn has a threat from King located at! "<<check_pos[y+1]<<x<<endl;
                 }


//****************************************************************************************************************************///
            while(x>=0 && y>=0) //left upper side diagonal loop
            {
                if(board[x][y]==300) //for left upper side diagonal threat from opposite KNIGHT
                {
                    cout<<"Pawn has a threat from knight located at! "<<check_pos[y]<<x+1<<endl;
                }
                if(board[x][y]==900) //for left upper side diagonal threat from opposite QUEEN.
                {
                    cout<<"Pawn has a threat from Queen locacted at ! "<<check_pos[y]<<x+1<<endl;
                }
                x--;
                y--;
            }

              while(x>=0 && y>=0) //left down side diagonal loop
            {
                if(board[x][y]==300) //for left down side diagonal threat from opposite KNIGHT.
                {
                    cout<<"Pawn has a threat from knight located at! "<<check_pos[y]<<x+1<<endl;
                }
                if(board[x][y]==900) //for left down side threat from opposite QUEEN.
                {
                    cout<<"Pawn has a threat from Queen locacted at ! "<<check_pos[y]<<x+1<<endl;
                }
                x++;
                y--;
            }

            while(x>=0 && y>=0) //right upper side diagonal loop
            {
                if(board[x][y]==300) //for right upper side threat from opposite KNIGHT.
                {
                    cout<<"Pawn has a threat from knight located at! "<<check_pos[y]<<x+1<<endl;
                }
                if(board[x][y]==900) //for right upper side threat from opposite QUEEN.
                {
                    cout<<"Pawn has a threat from Queen locacted at ! "<<check_pos[y]<<x+1<<endl;
                }
                x--;
                y++;
            }

               while(x>=0 && y>=0) //right down side diagonal loop
            {
                if(board[x][y]==300) //for right down side threat from opposite KNIGHT.
                {
                    cout<<"Pawn has a threat from knight located at! "<<check_pos[y]<<x+1<<endl;
                }
                if(board[x][y]==900) //for right down side threat from opposite QUEEN.
                {
                    cout<<"Pawn has a threat from Queen locacted at ! "<<check_pos[y]<<x+1<<endl;
                }
                x++;
                y++;
            }

//****************************************************************************************************************************///

           //////////rook/////////error///////////////////
//****************************************************************************************************************************///
   /////////////////LEFT SIDE CHECK FOR BISHOP/////////////////////
               if(board[x-2][y-1]==30 &&(x>=0 && y>=0)) //position 1//
               {
                   cout<<"Pawn has a threat from bishop located at1! "<<check_pos[y-1]<<x-1;
               }
               if(board[x-1][y-2]==30 &&(x>=0 && y>=0)) //position 2//
               {
                   cout<<"Pawn has a threat from bishop located at! 2 "<<check_pos[y-2]<<x;
               }
               if(board[x+1][y-2]==30 &&(x<=7 && y>=0)) //position 3//
               {
                   cout<<"Pawn has a threat from bishop located at! 3"<<check_pos[y-2]<<x+2;
               }
               if(board[x+2][y-1]==30 &&(x<=7 && y>=0)) //position 4//
               {
                   cout<<"Pawn has a threat from bishop located at! 4"<<check_pos[y-1]<<x+3;
               }
     ///////////////RIGHT SIDE CHECK/////////////
             if(board[x-2][y+1]==30 &&(x>=0 && y<=7)) //position opposite of 1//
               {
                   cout<<"Pawn has a threat from bishop located at!-1 "<<check_pos[y+1]<<x-1;
               }
             if(board[x-1][y+1]==30 &&(x>=0 && y<=7)) //position opposite of 2//
               {
                   cout<<"Pawn has a threat from bishop located at! -2 "<<check_pos[y+1]<<x;
               }
             if(board[x+1][y+2]==30 &&((x+1)<=7 && (y+2)<=7)) //position opposite of 3//
               {
                   cout<<"Pawn has a threat from bishop located at! -3 "<<check_pos[y+2]<<x+2;
               }
             if(board[x+2][y+1]==30 &&(x<=7 && y<=7)) //position opposite of 4//
               {
                   cout<<"Pawn has a threat from bishop located at!-4 "<<check_pos[y+1]<<x+3;
               }

//****************************************************************************************************************************///

}
    else if(board[x][y]==100)//white player pawn
    {
//****************************************************************************************************************************//
            if(board[x-1][y-1]==-100) //for left upper side threat from opposite PAWN.
                 {
                    cout<<"pawn has a threat from pawn located at!"<<" "<<check_pos[y-1]<<x<<endl;
                 }

            if(board[x-1][y+1]==-100) //for right upper side threat from opposite PAWN.
                 {
                    cout<<"pawn has a threat from pawn located at!"<<" "<<check_pos[y+1]<<x<<endl;
                 }
//****************************************************************************************************************************///
            if(board[x-1][y-1]==-2000)// for left upper side threat from KING.
                 {
                cout<<"Pawn has a threat from King located at! "<<check_pos[y-1]<<x<<endl;
                 }
            if(board[x-1][y+1]==-2000)// for right upper side threat from KING.
                 {
                cout<<"Pawn has a threat from King located at! "<<check_pos[y+1]<<x<<endl;
                 }
                 if(board[x+1][y-1]==-2000) //for left down side threat from opposite KING.
                 {
                    cout<<"pawn has a threat from pawn located at!"<<" "<<check_pos[y-1]<<x<<endl;
                 }
                 if(board[x+1][y+1]==-2000)// for right down side threat from KING.
                 {
                cout<<"Pawn has a threat from King located at! "<<check_pos[y+1]<<x<<endl;
                 }
                 if(board[x-1][y]==-2000)// for upper vertical threat from KING.
                 {
                cout<<"Pawn has a threat from King located at! "<<check_pos[y+1]<<x<<endl;
                 }
                 if(board[x+1][y]==-2000)// for  down vertical threat from KING.
                 {
                cout<<"Pawn has a threat from King located at! "<<check_pos[y+1]<<x<<endl;
                 }
                 if(board[x][y-1]==-2000)// for left side horizontal threat from KING.
                 {
                cout<<"Pawn has a threat from King located at! "<<check_pos[y+1]<<x<<endl;
                 }
                 if(board[x][y+1]==-2000)// for right side  horizontal threat from KING.
                 {
                cout<<"Pawn has a threat from King located at! "<<check_pos[y+1]<<x<<endl;
                 }


//****************************************************************************************************************************///
            while(x>=0 && y>=0) //left upper side diagonal loop
            {
                if(board[x][y]==-300) //for left upper side diagonal threat from opposite KNIGHT
                {
                    cout<<"Pawn has a threat from bishop located at! "<<check_pos[y]<<x+1<<endl;
                }
                if(board[x][y]==-900) //for left upper side diagonal threat from opposite QUEEN.
                {
                    cout<<"Pawn has a threat from Queen locacted at ! "<<check_pos[y]<<x+1<<endl;
                }
                x--;
                y--;
            }

              while(x>=0 && y>=0) //left down side diagonal loop
            {
                if(board[x][y]==-300) //for left down side diagonal threat from opposite KNIGHT.
                {
                    cout<<"Pawn has a threat from bishop located at! "<<check_pos[y]<<x+1<<endl;
                }
                if(board[x][y]==-900) //for left down side threat from opposite QUEEN.
                {
                    cout<<"Pawn has a threat from Queen locacted at ! "<<check_pos[y]<<x+1<<endl;
                }
                x++;
                y--;
            }

            while(x>=0 && y>=0) //right upper side diagonal loop
            {
                if(board[x][y]==-300) //for right upper side threat from opposite KNIGHT.
                {
                    cout<<"Pawn has a threat from bishop located at! "<<check_pos[y]<<x+1<<endl;
                }
                if(board[x][y]==-900) //for right upper side threat from opposite QUEEN.
                {
                    cout<<"Pawn has a threat from Queen locacted at ! "<<check_pos[y]<<x+1<<endl;
                }
                x--;
                y++;
            }

               while(x>=0 && y>=0) //right down side diagonal loop
            {
                if(board[x][y]==-300) //for right down side threat from opposite KNIGHT.
                {
                    cout<<"Pawn has a threat from bishop located at! "<<check_pos[y]<<x+1<<endl;
                }
                if(board[x][y]==-900) //for right down side threat from opposite QUEEN.
                {
                    cout<<"Pawn has a threat from Queen locacted at ! "<<check_pos[y]<<x+1<<endl;
                }
                x++;
                y++;
            }

//****************************************************************************************************************************///

///////////////////////rook///error//////////////////////////////////
//****************************************************************************************************************************///
   /////////////////LEFT SIDE CHECK FOR BISHOP/////////////////////
               if(board[x-2][y-1]==-30 &&(x>=0 && y>=0)) //position 1//
               {
                   cout<<"Pawn has a threat from bishop located at! "<<check_pos[y-1]<<x-1;
               }
               if(board[x-1][y-2]==-30 &&(x>=0 && y>=0)) //position 2//
               {
                   cout<<"Pawn has a threat from bishop located at! "<<check_pos[y-2]<<x;
               }
               if(board[x+1][y-2]==-30 &&(x<=7 && y>=0)) //position 3//
               {
                   cout<<"Pawn has a threat from bishop located at! "<<check_pos[y-2]<<x+2;
               }
               if(board[x+2][y-1]==-30 &&(x<=7 && y>=0)) //position 4//
               {
                   cout<<"Pawn has a threat from bishop located at! "<<check_pos[y-1]<<x+3;
               }
     ///////////////RIGHT SIDE CHECK/////////////
             if(board[x-2][y+1]==-30 &&(x>=0 && y<=7)) //position opposite of 1//
               {
                   cout<<"Pawn has a threat from bishop located at! "<<check_pos[y+1]<<x-1;
               }
             if(board[x-1][y+1]==-30 &&(x>=0 && y<=7)) //position opposite of 2//
               {
                   cout<<"Pawn has a threat from bishop located at! "<<check_pos[y+1]<<x;
               }
             if(board[x+1][y+2]==-30 &&(x<=7 && y<=7)) //position opposite of 3//
               {
                   cout<<"Pawn has a threat from bishop located at! "<<check_pos[y+2]<<x+2;
               }
             if(board[x+2][y+1]==-30 &&(x<=7 && y<=7)) //position opposite of 4//
               {
                   cout<<"Pawn has a threat from bishop located at! "<<check_pos[y+1]<<x+3;
               }

//****************************************************************************************************************************///
    }
    else
    {
        cout<<"Enter valid Pawn Location!!"<<endl;
    }
    return 0;


}

/* int correct_move(int a1,int b1, int c1, int d1)
 {
using namespace std;

     if(board[b1][a1]==-100) //for pawn
     {
         if(((d1==b1-1) && ((c1==a1-1)||(c1==a1)||(c1==a1+1))) || (board[d1][c1]==0))
         {
             board[d1][c1]=board[b1][a1];
             board[b1][c1]=0;
             printb();
         }
         else
            {
            cout<<"Not valid move!!"<<endl;
         }
     }
     else if(board[b1][a1]==-)
     {

     }
     else if(board[b1][a1]==)
     {

     }
     else if(board[b1][a1]==)
     {

     }
     else if(board[b1][a1]==)
     {

     }
     else if(board[b1][a1]==)
     {

     }
 }*/

//the main function//


int main (void) {

using namespace std;

//we need to tell the user about the program  ..  and how to use it

cout<<"********Simple CHESS!! (with threat to pawn check feature!!)*************"<<endl;
cout << "please enter your moves in 4 letter " << endl << "i.e e2e4 in lower case only" << endl;
cout << "commands: exit = quit, start = START THE GAME!!" << endl << "new = new game" << endl;
cout<<"To check if pawn is in danger= check (followed by position of the pawn i.e e6)"<<endl<<endl;

string action; // this will be the string that contains info from the user
setup(); //we must set up the initial position

while (1){ // infinite loop

	getline (cin, action );  //ask the user to input what he wants the game to do
		 if (action.substr(0, 4) == "exit" || action.substr(0, 4) == "quit")   { //test //for quit or exit statements
		  break;
		 }
		 if (action.substr(0, 5) == "start")   { // display the board
		  printb();
		 }
		 if (action.substr(0, 3) == "new")   { // ask for a new game
		  setup();
		 }
		 if (action.substr(0, 1) >= "a" && action.substr(0, 1) <= "h" && action.substr(1, 1) >= "1" && action.substr(1, 1) <= "8" && action.substr(2, 1) >= "a" && action.substr(2, 1) <= "h" && action.substr(3, 1) >= "1" && action.substr(3, 1) <= "8")   { // this statement makes sure both squares are on the chess board when executing //a move
		  // execute move
		  // then display new board position



		  int a, b, c, d;


		  a = action[0] - 'a';
		  b = action[1] - '1';
		  c = action[2] - 'a';
		  d = action[3] - '1';


//		  correct_move(a,b,c,d);
//executes the move if its on the board!
		  board[d][c] = board[b][a];
		  board[b][a] = 0;

		  printb(); //prints out to the screen the updated position after moving the pieces
		 }
		 // the threat to pawn checker
		 if(action.substr(0, 5)=="check"){
            string pos; //co-ordinates of the pawn
            getline(cin, pos);
            if(pos.substr(0, 1)>="a" && pos.substr(0, 1)<="h" && pos.substr(1, 1)>="1"&&pos.substr(1, 1)<="8")
            {
                int a1,b1;
              a1=pos[0]-'a';
              b1=pos[1]-'1';
              check(b1,a1); //calling check function and giving coordinates

            }
		 }
		}

}

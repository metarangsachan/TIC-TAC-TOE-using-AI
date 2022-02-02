#include<iostream>
using namespace std;
int cplayer;
char cmarker;
char p1Marker;
char computer;

struct move
	{
    int r, c, score;
	};
class Tictactoe{

	public: 
	char brd[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	
	//prints the board;//includes the changes done by entering X and O;
	int board()
	{
	   	    cout << '\n';
        	for (int i = 0; i < 3; i++) {
            	if (i) {
            	    cout << "-----------\n";
            	}
            	for (int j = 0; j < 3; j++)
				 {
                	if (j) 
					{
                   	 cout << "|";
                	}
                	cout << ' ';
                	if (brd[i][j] == ' ') 
					{
               	    	cout << 3 * i + j + 1;
               	    } 
					else 
					{
               	 	cout << brd[i][j];
               	 	}
               	 cout << ' ';
         	   }
         	   cout << '\n';
       	 }
   		 cout << '\n';
   	}
    
    //retruns current player in any case of winning positing
    bool winner()
{
    for(int i = 0; i < 3; i++)
    {
        if((brd[i][0] == brd[i][1] && brd[i][1] == brd[i][2]) &&(brd[i][0] !=' ' && brd[i][1]!=' ' && brd[i][2]!= ' ' ))
        {
            return true;
    
        }
        if((brd[0][i] == brd[1][i] && brd[1][i] == brd[2][i])&&(brd[1][i] !=' ' && brd[0][i]!=' ' && brd[2][i]!= ' ' ))
        {
            return true;
            
        }
    }
    if((brd[0][0] == brd[1][1] && brd[1][1] == brd[2][2])&&(brd[1][1] !=' ' && brd[0][0]!=' ' && brd[2][2]!= ' ' ))
    {
        return true;
    }
    if((brd[0][2] == brd[1][1] && brd[1][1] == brd[2][0])&&(brd[0][2] !=' ' && brd[1][1]!=' ' && brd[2][0]!= ' ' ))
    {
        return true;
        
    }
    return false;
}
		//returns true if all the boxes are filled and no one wins
      bool tie() 
	{
        if (winner())
            return false;
        for (int i = 0; i < 3; i++) 
		{
            for (int j = 0; j < 3; j++) 
			{
                if (brd[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
    
    //function for pplayer to move : 
	void player_move() 
	{
        while (true) 
		{
        	cout << "Its player's turn enter an empty cell   : ";
            int cell;
            cin >> cell;
            int r = (cell - 1)/3; 
			int c = (cell - 1) % 3;
            if (cell >= 1 && cell <= 9 && brd[r][c] == ' ') {
                brd[r][c] = p1Marker;
                break;
            }
            else
			{
            	cout<<"enter a valid cell please. "<<endl;
			}
        }
    }
    
    //function for comupter to make the best move
    void computer_move()
    {
 		cout<<"Computer is making its move...  "<<endl;
		move best_move = minimax();
        brd[best_move.r][best_move.c] = computer;
    }
	//using minimax algorithm to find the best move.
	move minimax(bool maximizing_player = true)
	{
        move best_move;
        if (winner())
		{
            if (maximizing_player) 
			{
                best_move.score = -1;
            } 
			else 
			{
                best_move.score = 1;
            }
            return best_move;
        } 
		else if (tie()) 
		{
            best_move.score = 0;
            return best_move;
        }
        int temp;
        best_move.score = maximizing_player ? -2 : 2;
        for (int i = 0; i < 3; i++) 
		{
            for (int j = 0; j < 3; j++) 
			{
                if (brd[i][j]==' ') 
				{	
                    brd[i][j] = maximizing_player ? computer : p1Marker;
                    move board_state = minimax(!maximizing_player);
                    if (maximizing_player) 
					{
                        if (board_state.score > best_move.score) 
						{
                            best_move.score = board_state.score;
                            best_move.r = i;
                            best_move.c = j;
                        }
                    } 
					else 
					{
                        if (board_state.score < best_move.score) {
                            best_move.score = board_state.score;
                            best_move.r = i;
                            best_move.c = j;
                        }
                    }
                    brd[i][j] =' ';
                }
            }
        }
        return best_move;
    } 

	//function to change truns between computer(player 2) and player(player 1) . 
/*	int turns()
	{
	if(cmarker == p1Marker)
    {
        cmarker = computer;
    } else {
        cmarker = p1Marker;
    }
    if(cplayer == 1)
    {
        cplayer = 2;
    } else 
	{
        cplayer = 1;
    }
   } */

 void game()
	{
        while (true)
		{
            cout<<"Player 1, Choose your marker (enter X or O, X goes first)  :  ";
			cin>>p1Marker;
			if(p1Marker=='X'||p1Marker=='x'){
			cout<<"Player 1 shall be using marker X and computer shall be using marker O. "<<endl;
			computer='O';
			break;
			}
			if(p1Marker=='O'||p1Marker=='o'){
			cout<<"Player 1 shall be using marker O and computer shall be using marker X . "<<endl;
			computer='X';
			break;
			}	
            else
			{
            	cout<<"please enter a valid choice. "<<endl;
			}
        }

        if (p1Marker == 'O' || p1Marker == 'o') 
		{
            computer_move();
        }
        board();
        while (true) {
            player_move();
            board();
            if (winner()) {
                cout << "Player wins!\n";
                return;
            } 
			else if (tie()) {
                cout << "Tie!\n";
                return;
            }
            computer_move();
            board();
            if (winner()) {
                cout << "Computer wins!\n";
                return;
            } else if (tie()) {
                cout << "Tie!\n";
                return;
            }
        }
    }

};
int main(){
	Tictactoe T;
	T.game();
}

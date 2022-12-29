//Welcome to Tic-Tac-Toe Game :)
#include <iostream>
#include <conio.h>
using namespace std;

void printInputMatrix();
void printBoard();
int addMark();
int check();

char board[3][3] = {' ',' ',' ',
					' ',' ',' ',
					' ',' ',' '};
int turn = 1; //1-Player 1 | 0-Player 2
char mark = 'O'; //O-Player 1 | X-Player 2
int input;

int main()
{
	int won = 0;
	int validInput = 0;
	
	for(int i=0; i<9; i++)
	{
		system("cls");//For clearing the screen
		
		printBoard();
		
		if(turn)
		{
			cout<<"Player 1 Turn (Your Symbol: O)"<<endl;
		}
		else
		{
			cout<<"Player 2 Turn (Your Symbol: X)"<<endl;
		} 
		
		printInputMatrix();//calling printInputMatrix
		
		cout<<"Enter Input from Input Matrix: ";
		cin>>input;//Taking input from user
		
		while(input<0 || input>9)
		{
			cout<<"Invalid Input. Please Re-Enter input: ";
			cin>>input;
		}
		
		if(turn)
		{
			mark = 'O';
		}
		else
		{
			mark = 'X';
		} 
		
		validInput = addMark();
		
		if( !validInput ) //if it is false then there will be second turns player
		{
			i--;
			continue;
		}
		
		won = check();
		
		if( won)
		{
			system("cls");
			printBoard();
			if(turn) cout<<endl<<"*** Player 1 - You Won ***";
			else cout<<endl<<"*** Player 2 - You Won ***";
			getch(); //pauses the Output Console until a key is pressed.
			break;
		}
		if(i==8)
		{
			system("cls");
			printBoard();
			cout<<endl<<"*** MATCH DRAW ***";
		}
		
		turn = !turn;//changing turns
	}
	
	return 0;
}
void printInputMatrix()
{
	cout<<endl<<endl<<"INPUT MATRIX"<<endl;
	cout<<" 1 | 2 | 3 "<<endl;
	cout<<"------------"<<endl;
	cout<<" 4 | 5 | 6 "<<endl;
	cout<<"------------"<<endl;
	cout<<" 7 | 8 | 9 "<<endl;
}
void printBoard()
{
	cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" "<<endl;
	cout<<"------------"<<endl;
	cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" "<<endl;
	cout<<"------------"<<endl;
	cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" "<<endl;
}
int addMark()
{
	for(int i=0,k=1; i<3; i++)
	{
		for(int j=0; j<3; j++,k++)
		{
			if( k==input )
			{
				
				if(board[i][j] == ' ')
				{
					board[i][j] = mark;
					return 1;
				}
				else
				{
					cout<<"Invalid Input";
					getch();
					
				}
				return 0;
			}
				
		}
	}
}
int check()
{
	//checking rows
	if(board[0][0]==mark && board[0][1]==mark && board[0][2]==mark)
		return 1;
	if(board[1][0]==mark && board[1][1]==mark && board[1][2]==mark)
		return 1;
	if(board[2][0]==mark && board[2][1]==mark && board[2][2]==mark)
		return 1;
		
	//checking Columns
	if(board[0][0]==mark && board[1][0]==mark && board[2][0]==mark)
		return 1;
	if(board[0][1]==mark && board[1][1]==mark && board[2][1]==mark)
		return 1;
	if(board[0][2]==mark && board[1][2]==mark && board[2][2]==mark)
		return 1;
		
	//checking diagonals
	if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark)
		return 1;
	if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark)
		return 1;
	
	return 0;
}

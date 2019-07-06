
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <conio.h>
#include "help.h"

using namespace std;


void specialGem3right(int board[8][8],int specialrow,int specialcolumn,int& score) // This function will work for special gem that we get by 4 consective gems.
{
	
	
		for (int row = 0; row < 8; row++)
		{
			for (int column = 0; column < 8; column++)
			{
				
				for (int z=0; z<10; z++)   //To make sure there are no consective gems together
				{
					for (int SpecialGems=100; SpecialGems <105; SpecialGems++) // If the gem is of any four special shapes.
					{
					
					if ( board[row][column+1] ==  board[row][column+2]  &&  board[row][column] == SpecialGems&& board[row][column+1] == SpecialGems-100)
					{
								//To Introduce Special Gem effect.
			
						for (int foraboveandbelow=-1;foraboveandbelow<2;foraboveandbelow++)
						{
							for (int j=row; j>=1; j--)				//To eliminate Special gem row and rows above and below it.
							{
							
							
							swap(board[row-j][column], board[row+foraboveandbelow][column]);
							swap(board[row-j][column+1], board[row+foraboveandbelow][column+1]);
					 		swap(board[row-j][column+2], board[row+foraboveandbelow][column+2]);
								
							
							}
						}

						
						swap( board[row+1][column],board[row][column]);
						
						system ("cls");
				
						for (int toregenrate=0; toregenrate<3; toregenrate++)		//To regenerate first 3 rows eliminated by special gem.
						{
							for (int col = column; col <= column+2; col++)
							{
							board[toregenrate][col] = rand() % 5;
							
							}
						}
						for (int toregenrate=0; toregenrate<3; toregenrate++)  //To- avoid consective numbers.
						{
							for (int col = column; col <= column+2; col++)
							{


								if (board[toregenrate][col] == board[toregenrate][col+1] && board[toregenrate][col] ==  board[toregenrate][col+2])
									if (board[toregenrate][col]==0)
										board[toregenrate][col]=board[toregenrate][col]+1;
									else 
									board[toregenrate][col]=board[toregenrate][col]-1;
			
							}
						}

							system("cls");
							score=score+10;
						}		
					}
				}
					
				
				
			}
		
		}
}


void specialGem3sides(int board[8][8],int specialrow,int specialcolumn,int& score)// This function will work for special gem that we get by 4 consective gems. If the gem is sandwiched in a row

{
	
	
		for (int row = 0; row < 8; row++)
		{
			for (int column = 0; column < 8; column++)
			{
				
				for (int z=0; z<10; z++)   //To make sure there are no consective gems together
				{
					for (int SpecialGems=100; SpecialGems <105; SpecialGems++) // To work for any special gem.
					{
					
					if ( board[row][column-1] ==  board[row][column+1]  &&  board[row][column] == SpecialGems&& board[row][column+1] == SpecialGems-100)
					{
								//To Introduce Special Gem effect.
			
						swap(board[row-2][column-1], board[row-3][column-1]);
						for (int foraboveandbelow=-1;foraboveandbelow<2;foraboveandbelow++)                                                                              
						{
							for (int j=row; j>=1; j--)				//To eliminate Special gem row and rows above and below it.
							{
							
							
							swap(board[row-j][column-1], board[row+foraboveandbelow][column-1]);
							swap(board[row-j][column], board[row+foraboveandbelow][column]);
					 		swap(board[row-j][column+1], board[row+foraboveandbelow][column+1]);
								
							
							}
						}

						
						swap( board[row+1][column],board[row][column]);
						
						system ("cls");
				
						for (int toregenrate=0; toregenrate<3; toregenrate++)		//To regenerate first 3 rows eliminated by special gem.
						{
							for (int col = column-1; col <= column+1; col++)
							{
							board[toregenrate][col] = rand() % 5;
							
							}
						}
						for (int toregenrate=0; toregenrate<3; toregenrate++)  //To- avoid consective numbers.
						{
							for (int col = column-1; col <= column+1; col++)
							{


								if (board[toregenrate][col] == board[toregenrate][col+1] && board[toregenrate][col] ==  board[toregenrate][col+2])
									if (board[toregenrate][col]==0)
										board[toregenrate][col]=board[toregenrate][col]+1;
									else 
									board[toregenrate][col]=board[toregenrate][col]-1;
			
							}
						}

							system("cls");
							score=score+10;
						}		
					}
				}
					
				
				
			}
		
		}
}




void specialGem3left(int board[8][8],int specialrow,int specialcolumn, int& score) // This function will work for special gem that we get by 4 consective gems. 
{
	int SpecialGems=100;
		for (int row = 0; row < 8; row++)
		{
			for (int column = 0; column < 8; column++)
			{
				
				
					for (int SpecialGems=100; SpecialGems<105; SpecialGems++) // To work for any special gem.
					{
					
					if ( board[row][column-1] ==  board[row][column-2]  &&  board[row][column] == SpecialGems && board[row][column-1] == SpecialGems-100)
					{
								//To Introduce Special Gem effect.
			
						for (int foraboveandbelow=-1;foraboveandbelow<2;foraboveandbelow++)
						{
							for (int j=row; j>=1; j--)				//To eliminate Special gem row and rows above and below it.
							{
							
							
							swap(board[row-j][column], board[row+foraboveandbelow][column]);
							swap(board[row-j][column-1], board[row+foraboveandbelow][column-1]);
					 		swap(board[row-j][column-2], board[row+foraboveandbelow][column-2]);
								
							
							}
						}

						
						swap( board[row+1][column],board[row][column]);
						swap( board[row+1][column-1],board[row][column-1]);
						swap( board[row+1][column-2],board[row][column-2]);
						
						system ("cls");
				
						for (int toregenrate=0; toregenrate<3; toregenrate++)		//To regenerate first 3 rows eliminated by special gem.
						{
							for (int col = column; col >= column-2; col--)
							{
							board[toregenrate][col] = rand() % 5;
							
							}
						}
						for (int toregenrate=0; toregenrate<3; toregenrate++)  //To avoid consective numbers.
						{
							for (int col = column; col <= column-2; col--)
							{


								if (board[toregenrate][col] == board[toregenrate][col-1] && board[toregenrate][col] ==  board[toregenrate][col-2])
									if (board[toregenrate][col]==0)
										board[toregenrate][col]=board[toregenrate][col]+1;
									else 
									board[toregenrate][col]=board[toregenrate][col]-1;
			
							}
						}


							system("cls");
							score=score+10;
				}
			}
		}
	}
}

void specialGem3down(int board[8][8],int specialrow,int specialcolumn, int& score)// This function will work for special gem that we get by 4 consective gems. 

{
	int SpecialGems=100;
	for (int row = 0; row < 8; row++)
		{
			for (int column = 0; column < 8; column++)
			{
				

				for (int z=0; z<10; z++)   //To make sure there are no consective gems together
				{
						for (int SpecialGems=100; SpecialGems<105; SpecialGems++)
					{
					
						
					
					if (board[row+1][column] == board[row+2][column] && board[row][column] == SpecialGems && board[row+1][column] == SpecialGems-100) //To introduce special gem effect.
					{
						for (int forleftandright=-1;forleftandright<2;forleftandright++)
						{
							for (int j=row, l=0; j>=-1; j--,l++)
							{
								swap(board[row+3-l][column+forleftandright], board[row-l][column+forleftandright]);
						
								system ("cls");
							}
						}
						for (int j=row+3; j>=0; j--)
						{	
							swap(board[row+3-j][column], board[row+3][column]);
							
							swap(board[row+3-j][column+1], board[row+3][column+1]);
							
							swap(board[row+3-j][column+2], board[row+3][column+2]);
							
							system ("cls");
						
						
						}
						
						
					for (int forleftandright=-1;forleftandright<2;forleftandright++) //To regenrate.
						{
							for (int j = 0; j < 4; j++)
							{
								board[j][column+forleftandright] = rand() % 5;
							
							}
						}
								system ("cls");
								score=score+10;
					
					
					if (board[0][column] == board[0][column+1] && board[0][column] == board[0][column+2])// To avoid consective gems.
								if (board[0][column]==0)
			 						board[0][column+1]=board[0][column]+1;
								else 
								board[0][column+1]=board[0][column]-1;


						}	
				
					}
				}
		}
	}
}




void specialGem3sandwiched(int board[8][8],int specialrow,int specialcolumn, int& score) //If special gem is sandwiched from above and below.
{int SpecialGems=100;

		for (int row = 0; row < 8; row++)
		{
			for (int column = 0; column < 8; column++)
			{
				
				for (int z=0; z<10; z++)   //To make sure there are no consective gems together
				{
					for (int SpecialGems=100; SpecialGems<105; SpecialGems++)// To work for any special gem.
					{
							if (board[row-1][column] == board[row+1][column] && board[row][column] == SpecialGems && board[row-1][column] == SpecialGems-100)
						{
						for (int forleftandright=-1;forleftandright<2;forleftandright++) // To introduce special Effect.
						{
							for (int j=row-1; j!=row-2; j--)
							{ 
								swap(board[j+1][column+forleftandright], board[j-2][column+forleftandright]);
						
								system ("cls");
							}
						}
						for (int forleftandright=-1;forleftandright<2;forleftandright++)
						{
							for (int j=row-6; j>=0; j--)
							{	
								swap(board[j][column+forleftandright], board[j+2][column+forleftandright]);
							
								system ("cls");
							}
						}
						
						for (int forleftandright=-1;forleftandright<2;forleftandright++)//To reproduce.
						{
							for (int j = 0; j < 3; j++)
							{
								board[j][column+forleftandright] = rand() % 5;
							
							}
						}


						if (board[0][column] == board[0][column+1] && board[0][column] == board[0][column+2])// To avoid consective.
								if (board[0][column]==0)
			 						board[0][column+1]=board[0][column]+1;
								else 
								board[0][column+1]=board[0][column]-1;


						system ("cls");
						score=score+10;
					}
}
				}
			}
		}
	}




void specialGem3up(int board[8][8],int specialrow,int specialcolumn, int& score)
{int SpecialGems=100;

		for (int row = 0; row < 8; row++)
		{
			for (int column = 0; column < 8; column++)
			{
				
				for (int z=0; z<10; z++)   //To make sure there are no consective gems together
				{
					for (int SpecialGems=100; SpecialGems<105; SpecialGems++)
					{
							if (board[row-1][column] == board[row-2][column] && board[row][column] == SpecialGems && board[row-1][column] == SpecialGems-100)
						{
						for (int forleftandright=-1;forleftandright<2;forleftandright++)
						{
							for (int j=row; j!=row-3; j--)
							{ 
								swap(board[j][column+forleftandright], board[j-3][column+forleftandright]);
						
								system ("cls");
							}
						}
						for (int forleftandright=-1;forleftandright<2;forleftandright++)
						{
							for (int j=row-6; j>=0; j--)
							{	
								swap(board[j][column+forleftandright], board[j+3][column+forleftandright]);
							
								system ("cls");
							}
						}
						
						for (int forleftandright=-1;forleftandright<2;forleftandright++)
						{
							for (int j = 0; j < 3; j++)
							{
								board[j][column+forleftandright] = rand() % 5;
							
							}
						}


						if (board[0][column] == board[0][column+1] && board[0][column] == board[0][column+2])
								if (board[0][column]==0)
			 						board[0][column+1]=board[0][column]+1;
								else 
								board[0][column+1]=board[0][column]-1;


						system ("cls");
						score=score+10;
					}
}
				}
			}
		}
	}
//
//void BonusSpecialRight(int board[8][8],int specialrow,int specialcolumn,int score)
//{
//	
//	
//		for (int row = 0; row < 8; row++)
//		{
//			for (int column = 0; column < 8; column++)
//			{
//				
//				for (int z=0; z<10; z++)   //To make sure there are no consective gems together
//				{
//					for (int SpecialGems=100; SpecialGems <105; SpecialGems++)
//					{
//					
//					if ( board[row][column+1] ==  board[row][column+2]  &&  board[row][column] == SpecialGems&& board[row][column+1] == SpecialGems-100)
//					{
//
//
//

void BonusGemEffect(int board[8][8],int torow, int tocol,int fromrow,int fromcol,int& score)
{
	if (board[torow][tocol]==200 )
		{
			int tobewipedout=board[fromrow][fromcol];
			for (int row = 0; row < 8; row++)
			{
				for (int column = 0; column < 8; column++)
				{
					if (board[row][column]==tobewipedout)
					{
						for (int j=row; j>=0; j--)
						{	
							swap(board[row-j][column], board[row][column]);
							system("cls");
						}
						board[0][column] = rand() % 5;
					}	
				}
			}
		
				score=score+50;
		}
}

void BonusGemEffect2(int board[8][8],int torow, int tocol,int fromrow,int fromcol,int& score)
{
	if (board[fromrow][fromcol]==200 )
	{
		int tobewipedout=board[torow][tocol];
		for (int row = 0; row < 8; row++)
		{
			for (int column = 0; column < 8; column++)
			{
				if (board[row][column]==tobewipedout)
				{
					for (int j=row; j>=0; j--)
					{	
						swap(board[row-j][column], board[row][column]);
						system("cls");
					}
					board[0][column] = rand() % 5;					
				}
			}
		}
				score=score+50;
	}
}

void FiveGemstogetherinarow(int board[8][8],int& veryspecialrow, int&veryspecialcolumn,int torow, int tocol, int& score)
{

	for (int row = 0; row < 8; row++)
	{
				for (int column = 0; column < 8; column++)
				{


		
				if (board[row][column] == board[row][column+1] && board[row][column] ==  board[row][column+2] && board[row][column] ==  board[row][column+3] && board[row][column] ==  board[row][column+4])
						{
							veryspecialrow=torow;
							veryspecialcolumn=tocol;
							int temp=board[row][column];

							for (int j=row; j>=0; j--)
							{	
							
							swap(board[row-j][column], board[row][column]);
							swap(board[row-j][column+1], board[row][column+1]);
					 		swap(board[row-j][column+2], board[row][column+2]);
							swap(board[row-j][column+3], board[row][column+3]);	
							swap(board[row-j][column+4], board[row][column+4]);
							system ("cls");
							}

							if (temp<200)
								board[veryspecialrow][veryspecialcolumn]=200;


							for (int col = column; col != column+4; col++)
							{
							board[0][col] = rand() % 5;
							}
							
							
							if (board[0][column] == board[0][column+1] && board[0][column] == board[0][column+2])
								if (board[0][column]==0)
			 						board[0][column+2]=board[0][column]+1;
								else 
								board[0][column+2]=board[0][column]-1;
		
	
							score=score+20;
					}
				}
			
		}
}

void FourGemstogetherinarow(int board[8][8],int& specialrow, int& specialcolumn,int torow, int tocol, int& score)
{
	
		for (int row = 0; row < 8; row++)
		{
			for (int column = 0; column < 8; column++)
			{
				if (board[row][column] == board[row][column+1] && board[row][column] ==  board[row][column+2] && board[row][column] ==  board[row][column+3])
				{
							
							specialrow=torow;
							specialcolumn=tocol;
							int temp=board[row][column];

							for (int j=row; j>=0; j--)
							{	
							
							swap(board[row-j][column], board[row][column]);
							swap(board[row-j][column+1], board[row][column+1]);
					 		swap(board[row-j][column+2], board[row][column+2]);
							swap(board[row-j][column+3], board[row][column+3]);	
							system ("cls");
							}

							if (temp<100)
								board[specialrow][specialcolumn]=temp+100;

							
							
							for (int col = column; col != column+3; col++)
							{
							board[0][col] = rand() % 5;
							}
							
							
							if (board[0][column] == board[0][column+1] && board[0][column] == board[0][column+2])
								if (board[0][column]==0)
			 						board[0][column+1]=board[0][column]+1;
								else 
								board[0][column+1]=board[0][column]-1;
		
	
							score=score+20;
				}
			}
		}
	
}

void ThreeGemstogetherinarow(int board[8][8], int& score)
{
	
			for (int row = 0; row < 8; row++)
			{
				for (int column = 0; column < 8; column++)
				{


		
				


					if (board[row][column] == board[row][column+1] && board[row][column] ==  board[row][column+2])
					{	
				
						
						for (int j=row; j>=0; j--)
						{	
							swap(board[row-j][column], board[row][column]);
							swap(board[row-j][column+1], board[row][column+1]);
							swap(board[row-j][column+2], board[row][column+2]);
						
							system ("cls");
						
						
						}
						for (int col = column; col != column+2; col++)
						{
							board[0][col] = rand() % 5;
						}
						
						if (board[0][column] == board[0][column+1] && board[0][column] == board[0][column+2])
								if (board[0][column]==0)
			 						board[0][column+1]=board[0][column]+1;
								else 
								board[0][column+1]=board[0][column]-1;

						score=score+10;
		
					}
				}
			
	}
}

void FiveGemstogetherinacolumn(int board[8][8],int& veryspecialrow, int&veryspecialcolumn,int torow, int tocol, int& score)
{
	
		
			for (int row = 0; row < 8; row++)
			{
				for (int column = 0; column < 8; column++)
				{


		
				


					if (board[row][column] == board[row+1][column] && board[row][column] ==  board[row+2][column] && board[row][column] ==  board[row+3][column] && board[row][column] ==  board[row+4][column] )
					{
						veryspecialrow=torow;
						veryspecialcolumn=tocol;
						int temp=board[row][column];

						
						for (int j=row, l=0; j>=0; j--,l++)
						{
							swap(board[row+5-l][column], board[row-l][column]);
						
							system ("cls");
	
						}
						for (int j = 0; j < 5; j++)
						{
							board[j][column] = rand() % 5;
						}
						
						
						board[veryspecialrow][veryspecialcolumn]=200;
							
						score=score+50;
					}

				}
			
		}
}

void FourGemstogetherinacolumn(int board[8][8],int& specialrow, int& specialcolumn,int torow, int tocol, int& score)
{
	
		for (int row = 0; row < 8; row++)
		{
			for (int column = 0; column < 8; column++)
			{

	if (board[row][column] == board[row+1][column] && board[row][column] ==  board[row+2][column] && board[row][column] ==  board[row+3][column])
	{
		specialrow=torow;
		specialcolumn=tocol;
		int temp=board[row][column];

						
		for (int j=row, l=0; j>=0; j--,l++)
		{
			swap(board[row+4-l][column], board[row-l][column]);
						
			system ("cls");
	
		}
		for (int j = 0; j < 4; j++)
		{
			board[j][column] = rand() % 5;
		}
						
		if (temp<100)
			board[specialrow][specialcolumn]=temp+100;
					
		score=score+20;
	
			}
		}
	}
}

void ThreeGemstogetherinacolumn(int board[8][8], int& score)
{

		
			for (int row = 0; row < 8; row++)
			{
				for (int column = 0; column < 8; column++)
				{
				if (board[row][column] == board[row+1][column] && board[row][column] ==  board[row+2][column])
					{
						for (int j=row, l=0; j>=0; j--,l++)
						{
							swap(board[row+3-l][column], board[row-l][column]);
						

							system ("cls");
	
						}
					
						for (int j = 0; j < 3; j++)
						{
							board[j][column] = rand() % 5;
						}

						
						if (board[0][column] == board[1][column] && board[0][column] == board[2][column])
							if (board[0][column]==0)
			 					{
									board[1][column]=board[0][column]+1;								
								}
							else 
							{
								board[1][column]=board[0][column]-1;
							}
						score=score+10;
				
				}
			}
		}
}

void printBoard(int board[8][8],int time,int score, int a2, int startingPosition, int currentlySelectedRow, int CurrentlySelectedColumn)
{
	// 0 is for T is for triangle, S for square, C for circle, D for diamond and R for rombus
	/*int a1, a2, b1, b2;

			a1 = (startingPosition + 800) ;
			a2 = (startingPosition + 300) ;
			b1 = (startingPosition + 480) ;
			b2 = (startingPosition ) ;


	myRect(a1, a2, b1, b2, 255, 255, 255, 0, 0, 0);
*/
	int scoreDigit=score;
	int scorePrint[3]={};
	
	myRect(50, 50, 500, 250, 0, 0, 0, 0, 0, 0);
	
		Box();

	int scoreFlag=0;
		

		for (int b=0; b<=2;b++)
		{

		if (scoreDigit>100)
		{
			scoreFlag++;
			
			scorePrint [b]= 0;
			scoreDigit=scoreDigit/10;
			
		}
		else if (scoreDigit>=10)
		{
			scoreFlag++;
			scorePrint [b]= scoreDigit%10;
			
			scoreDigit=scoreDigit/10;
		}
		else if (scoreDigit>=1)
			{
			scorePrint [b]= scoreDigit;
			scoreFlag++;


			scoreDigit=scoreDigit/10;
		}
		else if (scoreDigit==0)
		{
			scorePrint [b]=0;
			
		}
	}
		int a=0;
		while( a<=240 && scoreFlag>=0)
		{
			
			if (scorePrint[scoreFlag]==1)
				Digit1(a);
			else if (scorePrint[scoreFlag]==2)
				Digit2(a);
			else if (scorePrint[scoreFlag]==3)
				Digit3(a);
			else if (scorePrint[scoreFlag]==4)
				Digit4(a);
			else if (scorePrint[scoreFlag]==5)
				Digit5(a);
			else if (scorePrint[scoreFlag]==6)
				Digit6(a);
			else if (scorePrint[scoreFlag]==7)
				Digit7(a);

			else if (scorePrint[scoreFlag]==8)
				Digit8(a);
			else if (scorePrint[scoreFlag]==9)
				Digit9(a);
			else if (scorePrint[scoreFlag]==0)
				Digit0(a);
		
			scoreFlag--;
			a=a+70;
		}

		

			

for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			int x1, x2, y1, y2;

			x1 = (startingPosition +430) + (column * 40);
			y1 = (startingPosition + 0) + (row * 40);
			x2 = (startingPosition + 460) + (column * 40);
			y2 = (startingPosition + 30) + (row * 40);

			int borderColor = 0;

			myRect(x1, y1, x2+10, y2+10, 0, 0, 0, 0, 0, 0);


			if (row == currentlySelectedRow && column == CurrentlySelectedColumn)
			{
				borderColor = 255;
			}


			if (board[row][column] == 0)
			{
				/*myEllipse(x1, y1, x2, y2, 0, borderColor, borderColor, 0, 0, 2-55);*/
				myRect(x1, y1, x2, y2, 0, borderColor, borderColor, 0, 0, 255);
				cout << "    ";
			}
			else if (board[row][column] == 1)
			{
				Polygon(x1, y1, x2, y2, 0, borderColor, borderColor, 0, 255, 0);
				cout << "    ";
			}
			else if (board[row][column] == 2)
			{
				myRect(x1, y1, x2, y2, 0, borderColor, borderColor, 255, 0, 0);
				cout << "    ";
			}
			else if (board[row][column] == 3)
			{
				Poly3(x1, y1, x2, y2, 0, borderColor, borderColor, 255, 0, 255);
				cout << "    ";
			}
			
			else if (board[row][column]==4)
			{
				Poly2(x1, y1, x2, y2, 0, borderColor, borderColor, 255, 255, 255);
				cout << "    ";
			}

			else if (board[row][column] == 100)			//For special gems
			{
				myEllipse(x1-5, y1-5, x2+5, y2+5, 0, borderColor, borderColor, 255, 102, 178);
				cout << "    ";
			}

			else if (board[row][column] == 101)			//For special gems
			{
				Polygon(x1-5, y1-5, x2+5, y2+5,  0, borderColor, borderColor, 255, 102, 178);
				cout << "    ";
			}
			else if (board[row][column] == 102)			//For special gems
			{
				myRect(x1-5, y1-5, x2+5, y2+5, 0, borderColor, borderColor, 255, 102, 178);
				cout << "    ";
			}
			else if (board[row][column] == 103)			//For special gems
			{
				Poly3(x1-5, y1-5, x2+5, y2+5,  0, borderColor, borderColor, 255, 102, 178);
				cout << "    ";
			}
			else if (board[row][column] == 104)			//For special gems
			{
				Poly2(x1+3, y1+3, x2, y2, 255, 102, 178, 255, 102, 178);
				cout << "    ";
			}
			
			
			if (board[row][column] == 200)
			{
				if (time%2==0)
					myEllipse(x1, y1, x2, y2, 255, 255, 255, 0, 0, 0);
				else
					myEllipse(x1, y1, x2, y2, 255, 0, 255, 0, 0, 0);
				cout << "    ";
			}
			
		}
		cout << endl;
		cout << endl;
		cout << endl;
		

		
	}
}


void randomlyPopulateBoard(int board[8][8])
{
	srand((unsigned)time(0));
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			board[row][column] = rand() % 5;
		}
	}
	for (int row = 0; row < 8; row++)		//To not get 3 consective numbers.
	{
		for (int column = 0; column < 8; column++)
		{


			if (board[row][column] == board[row-1][column] && board[row][column] ==  board[row-2][column])
				if (board[row][column]==0)
					board[row][column]=board[row][column]+1;
				else 
					board[row][column]=board[row][column]-1;
			
			if (board[row][column] == board[row][column-1] && board[row][column] == board[row][column-2])
				if (board[row][column]==0)
			 		board[row][column]=board[row][column]+1;
				else 
					board[row][column]=board[row][column]-1;
		}
	}
}
int main()
{
	int board[8][8] = {0};
	randomlyPopulateBoard(board);
	int currentlySelectedRow=0;
	int CurrentlySelectedColumn=0;
	int startingPosition=100;
	int specialrow=99,specialcolumn=99;
	int score=0;
	int veryspecialcolumn=9999,veryspecialrow=9999;
	
	
	int a1=20,a2=400;
	myRect(a1, 350, a2, 370, 255, 0, 0, 255, 0, 0);
	myRect(a1, 350, a2, 370, 255, 0, 0, 255, 0, 0);
	

	double duration=0;
	clock_t time;
	time= clock()/200;
	cout<< time;

	
	
	printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
	char controll='n';
		
	for (int v=0; v<100; v++)
	{
		
		if (time>=380)
			break;

	while (controll!='m')
	{
		
		if (time>=380)
			break;

		while (controll!='m')
		{


		time= clock()/200;
		myRect(a2-time, 350, a2, 370, 255, 0, 0, 0, 0, 0);
		myRect(150, 550, 650, 750, 0, 0, 255 , 0, 0, 0);
		
			if (time>=380)
				break;


			if (_kbhit())
			{

				system("cls");    
        
				controll = _getch();
				
				if (controll == 'S')
				{
				remove("save.txt");
				ofstream fout("save.txt");
				for (int i=0; i<8; i++)
				{
					for (int j=0; j<8; j++)
					{
						fout<<board[i][j]<<" ";
					}
				}
				fout<<score<<time;
				fout.close();
			}	
				

				
				if (controll == 'L')
				{
					ifstream fin("save.txt");
				for (int i=0; i<8; i++)
				{
					for (int j=0; j<8; j++)
					{
						fin>>board[i][j];
					}
				}
				fin>>score>>time;

				}
				
				if (controll == 'w')
				{
				currentlySelectedRow--;
				printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
			
				}
				if (currentlySelectedRow==-1)
				 currentlySelectedRow = 7;

				if (controll == 'd')
				{
				CurrentlySelectedColumn++;
				printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
				}
				if (CurrentlySelectedColumn==8)
				 CurrentlySelectedColumn = 0;

				if (controll == 'a')
				{
				CurrentlySelectedColumn--;
				printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
				}
				if (CurrentlySelectedColumn==-1)
				CurrentlySelectedColumn = 7;
		
				if (controll == 's')
				{
				currentlySelectedRow++;
				printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
				}
				if (currentlySelectedRow==8)
				currentlySelectedRow = 0;	

				


				if (controll == 13)
				{
				break;
				}
				
				
			system("cls");
				
						
			printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
			}
			
			
	}
	
	
	int fromrow= currentlySelectedRow;
	int fromcol = CurrentlySelectedColumn;
	
	system("cls");
	
	printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
	
		while (currentlySelectedRow < 8 && CurrentlySelectedColumn < 8 && CurrentlySelectedColumn>-1 && currentlySelectedRow>-1)
		{
			time= clock()/200;

			
			if (time>=380)
				break;


		myRect(a2-time, 350, a2, 370, 255, 0, 0, 0, 0, 0);
		myRect(150, 550, 650, 750, 0, 0, 255 , 0, 0, 0);

			if (_kbhit())
			{
				system("cls");

			cout<< "score"<<score;
			
		
			
			controll = _getch();
			
			
				//if (controll == 'S')
				//{
				//	cout<<"   "; 
				//	fout<<board[0][5];
				//	
				//}	
				//

				//
				//if (controll == 'L')
				//{

				//			fin>>board[0][5];
				//				cout<<board[0][5];
				//	
				//	
				//}
				//  fout.close();
				//
			
			
			if (controll == 'w')
			{
				currentlySelectedRow--;
				printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);

			}
			
			if (currentlySelectedRow==-1)
				 currentlySelectedRow = 7;

			if (controll == 'd')
			{
				CurrentlySelectedColumn++;
				printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);


			}
			if (CurrentlySelectedColumn==8)
				 CurrentlySelectedColumn = 0;

			if (controll == 'a')
			{
				CurrentlySelectedColumn--;
				printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
			}
			if (CurrentlySelectedColumn==-1)
				 CurrentlySelectedColumn = 7;

			if (controll == 's')
			{
				currentlySelectedRow++;
				printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
			}
			if (currentlySelectedRow==8)
				currentlySelectedRow = 0;	

			if (controll == 13)
			{
				break;
			}
			
				
				system("cls");
						
			printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
			system("cls");
			}
		
			
		}
		
		int torow = currentlySelectedRow;
		int tocol = CurrentlySelectedColumn;
		int temp;
	
			swap(board[torow][tocol], board[fromrow][fromcol]);
		

		system("cls");
	
		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);

		
		BonusGemEffect(board,torow,tocol,fromrow,fromcol,score);

		system("cls");

		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
		
		BonusGemEffect(board,torow,tocol,fromrow,fromcol,score);
		
		system("cls");

		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
		
		FiveGemstogetherinarow(board,veryspecialrow, veryspecialcolumn,torow, tocol, score);

		system("cls");

		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
		
		FourGemstogetherinarow(board,specialrow, specialcolumn,torow, tocol, score);

		system("cls");

		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
		
		ThreeGemstogetherinarow(board, score);

		system("cls");

		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);

		FiveGemstogetherinacolumn(board,veryspecialrow, veryspecialcolumn,torow, tocol, score);

		system("cls");

		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
		
		FourGemstogetherinacolumn(board,specialrow, specialcolumn,torow, tocol, score);

		system("cls");

		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
		
		ThreeGemstogetherinacolumn(board, score);
	
		system("cls");
				
		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);
				
		specialGem3right(board, specialrow,specialcolumn, score)	;	
		
		system("cls");

		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);

		system("cls");

		specialGem3left(board, specialrow,specialcolumn, score)	;	
		
		system("cls");

		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);

		system("cls");

		specialGem3down(board, specialrow,specialcolumn, score)	;	
		
		system("cls");

		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);

		system("cls");

		
		specialGem3sandwiched(board, specialrow,specialcolumn, score)	;	
		
		system("cls");

		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);

		system("cls");


		specialGem3up(board, specialrow,specialcolumn, score)	;	
		
		system("cls");

		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);

		system("cls");
		
		specialGem3sides( board,specialrow, specialcolumn, score);
		
		system("cls");

		printBoard(board, time, score, a2, startingPosition, currentlySelectedRow, CurrentlySelectedColumn);

		system("cls");
		
		
	}
	}
	system("pause");
	return 0;
}
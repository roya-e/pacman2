#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#define R 5
#define H 10
#define M 100 
char playfiled[R][H]; 
int numberOfFood;
struct pacman{
	int x;
	int y;	
}mypacman={0,0};
void gotoxy( int x, int y)
{
	COORD coord; 
	coord.X= x; 
	coord.Y= y; 
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleCursorPosition( handle, coord); 
} 
int start()
{
	int i=0,j=0;
	char r;
	FILE *ptf;
	char address[M];
	printf ("Enter the name and path of a text file: "); 
	scanf("%s" ,address);
	ptf=fopen(address ,"r");
	if(ptf==NULL)
	{
		printf("\nERROR : Cant open the file");
		return 0;
	}
	r=fgetc(ptf);
	while(r!=EOF)
	{
		if(r=='*')
			numberOfFood++;	
		if(r=='0'){
			mypacman.x=i;   
			mypacman.y=j;  
		}
		if(r=='{' || r=='}' || r==',' || r=='\'' || r==' ')
		{
			continue;
		}	
		else if(r!='\n') 
			playfiled[i][j]=r;
		else if(r=='\n')
		{
			j++;
		}
		else
		{
			i++;
		}
		r=fgetc(ptf);
	}  
	fclose(ptf);
}
int input()
{
	char c1,c2;
	//if(khbit())
//	{
		c1=getch();
		if(c1=='1');
			return 0;
		if(c1==-32)
		{
			c2=getchar();
			if((int)c2==72)//up
			{
				if(playfiled[mypacman.x-1][mypacman.y]=='*')
				{
					numberOfFood--;
				}
				if(playfiled[mypacman.x-1][mypacman.y]=='#')
				{
					gotoxy(0 ,6);
					printf("You can’t move there! There is an obstacle");
				}	
				else if(mypacman.x==0)
				{
					gotoxy(0 ,6);
					printf("You can’t move there! There is a wall");
				}
				else
				{
					gotoxy(mypacman.y+1 ,mypacman.x);
					printf("\b%c" ,1);
					sleep(1);
					gotoxy(mypacman.y+1 ,mypacman.x-1);
					printf("\b%c" ,0);
					mypacman.x--;
					sleep(1);
				}
			}
			if((int)c2==80)//down
			{
				if(playfiled[mypacman.x+1][mypacman.y]=='*'){
					numberOfFood--;
				}
				if(playfiled[mypacman.x+1][mypacman.y]=='#')
				{
					gotoxy(0 ,6);
					printf("You can’t move there! There is an obstacle");
				}	
				else if(mypacman.x==4)
				{
					gotoxy(0 ,6);
					printf("You can’t move there! There is a wall");
				}
				else
				{
					gotoxy(mypacman.y+1 ,mypacman.x);
					printf("\b%c" ,1);
					sleep(1);
					gotoxy(mypacman.y+1 ,mypacman.x+1);
					mypacman.x++;
					printf("\b%c" ,0);
					sleep(1);
				}
			}
			if((int)c2==75)//left
			{
				if(playfiled[mypacman.x][mypacman.y-1]=='*')
				{
					numberOfFood--;
				}
				if(playfiled[mypacman.x][mypacman.y-1]=='#')
				{
					gotoxy(0 ,6);
					printf("You can’t move there! There is an obstacle");
				}	
				else if(mypacman.y==0)
				{
					gotoxy(0 ,6);
					printf("You can’t move there! There is a wall");
				}
				else
				{
					gotoxy(mypacman.y+1 ,mypacman.x);
					printf("\b%c" ,1);
					sleep(1);
					gotoxy(mypacman.y ,mypacman.x);
					mypacman.y--;
					printf("\b%c" ,0);
					sleep(1);
				}
			}
			if((int)c2==77)//right
			{
				if(playfiled[mypacman.x][mypacman.y+1]=='*')
				{
					numberOfFood--;
				}
				if(playfiled[mypacman.x][mypacman.y+1]=='#')
				{
					gotoxy(0 ,6);
					printf("You can’t move there! There is an obstacle");
				}	
				else if(mypacman.y==9)
				{
					gotoxy(0 ,6);
					printf("You can’t move there! There is a wall");
				}
				else
				{
					gotoxy(mypacman.y+1 ,mypacman.x);
					printf("\b%c" ,1);
					sleep(1);
					mypacman.y++;
					gotoxy(mypacman.y+1 ,mypacman.x);
					printf("\b%c" ,0);
					sleep(1);
				}
			}
		}
//	}
}
int main(){
	if(start()==0)
	{
		return 0;
	}
	int result=input();
	while(result!=0 && numberOfFood!=0);
	if(numberOfFood==0)
	{
		gotoxy(0,6);
		printf("Pacman ate all the Food:)");
	}
	system("cls");
	gotoxy(10,10);
	printf("The Game Has End");
}
//////////////////////////////////////////////////////////////1.dibag kardan









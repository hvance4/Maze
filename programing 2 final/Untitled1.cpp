//program by herbie vance on 11/4/16

#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
//prototypes
void loadMaze(string *maze, int *hero,int *dragon);
void printMaze(string *maze,char& input);
bool moveHero(string *maze,int* hero, bool princess, bool& win,char& input);
bool moveDragon(string *maze,int* hero, bool princess,int *dragon,bool& lose);
int main()
{
	string maze[11];
	int hero[2]={0,0};
	int dragon[2]={0,0};
	char input;
	bool win=false,princess=false, lose=false;
	loadMaze(maze,hero, dragon);
	
	while(!win && !lose)
	{
	printMaze(maze,input);
	moveHero(maze,hero,princess,win, input);
	moveDragon(maze,hero,princess,dragon,lose);
	}
}
void loadMaze(string *maze,int* hero, int* dragon)
{
	fstream mazeFile;
	int row=0, found=0, drag=0;
	mazeFile.open("maze.txt");
	
	if(mazeFile.fail())
	cout << "error";
	
	while(mazeFile.good())
	{
		getline(mazeFile,maze[row]);
		found= maze[row].find("h");
		drag = maze[row].find("D");
		row++;
		if(found >= 0)
		{
			hero[0]=row-1;
			hero[1]=found;
		}
		if(drag >= 0)
		{
			dragon[0]=row-1;
			dragon[1]= drag;
		}
		
	}
	mazeFile.close();
}
void printMaze(string *maze,char& input)
{
	for(int i=0;i<11;i++)
	{
		cout << maze[i] << endl;
	}
	cout << "whats your next move hero? w(up), a(left) s(down) d(right) ";
	cin >> input;
}
bool moveHero(string *maze,int* hero, bool princess, bool& win, char& input)
{
	
	int temp[2];
	char temp1;
	temp[0]=hero[0];
	temp[1]=hero[1];
	bool valid= false;
		
		switch(input)
		{
			case 'w': temp[0]--;
			break;
			case 'a': temp[1]--;
			break;
			case 'd': temp[1]++;
			break; 
			case 's': temp[0]++;
			break;
			case 'f': ;
			default :  ;	
		}
		if(maze[temp[0]][temp[1]] == ' '|| maze[temp[0]][temp[1]]== 'F'|| maze[temp[0]][temp[1]]== 'P')
		{
			if(maze[temp[0]][temp[1]]=='P')
			{
				princess = true;
				maze[hero[0]][hero[1]]= ' '; //deletes old H
				maze[temp[0]][temp[1]]= 'H';// hero gets buff
			}
			if(maze[temp[0]][temp[1]] == 'F') //&& princess == true
			{
				maze[hero[0]][hero[1]]= ' '; //deletes old H
				maze[temp[0]][temp[1]]= 'F';// hero gets buff
			
				win= true;
				return 0; ;
			}
			
			
			if(maze[temp[0]][temp[1]]== ' ')
			{
			temp1=maze[hero[0]][hero[1]];
			maze[hero[0]][hero[1]]=maze[temp[0]][temp[1]];
			maze[temp[0]][temp[1]]=temp1;
			}
			valid= true;
			hero[0]=temp[0];
			hero[1]=temp[1];
		}
}
bool moveDragon(string *maze,int* hero, bool princess,int *dragon,bool& lose)
{

	int input=0;
	int temp[2];
	char temp1;
	temp[0]=dragon[0];
	temp[1]=dragon[1];
	
	srand(time(NULL));
	 input = rand() % 4+1;
	 	switch(input)
		{
			case 1: temp[0]--;
			break;
			case 2: temp[1]--;
			break;
			case 3: temp[1]++;
			break; 
			case 4: temp[0]++;
			break;
			default :  ;	
		}
	
	if(maze[hero[0]].at(hero[1]) == maze[temp[0]].at(temp[1]+1) || maze[hero[0]].at(hero[1]) == maze[temp[0]].at(temp[1]-1) || maze[hero[0]].at(hero[1]) == maze[temp[0]+1].at(temp[1]) || maze[hero[0]].at(hero[1]) == maze[temp[0]-1].at(temp[1]) )
			{
				lose= true;
				return 0;
			}
	if(maze[temp[0]][temp[1]] == ' '|| maze[temp[0]][temp[1]]== 'h'|| maze[temp[0]][temp[1]]== 'H')
		{
			
			if(maze[temp[0]][temp[1]]== ' ')
			{
			temp1=maze[dragon[0]][dragon[1]];
			maze[dragon[0]][dragon[1]]=maze[temp[0]][temp[1]];
			maze[temp[0]][temp[1]]=temp1;
			}
		
			dragon[0]=temp[0];
			dragon[1]=temp[1];
		}
	
	
	
}
	
	
		


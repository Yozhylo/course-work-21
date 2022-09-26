#include "maze.h"
#include <cstdlib>
#include <ctime>

int mazeWidth, mazeHeight;
bool** maze = initMaze(mazeWidth, mazeHeight);
void fillMaze(bool** maze, int w, int h) {
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++) (i % 2 && j % 2)? maze[i][j] = false : maze[i][j] = true;
}
bool** initMaze(int w, int h){
	//Инициализация матрицы-лабиринта
	bool** tMaze = new bool* [w];
	for (int i = 0; i < w; i++) tMaze[i] = new bool [h];

	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++) tMaze[i][j] = false;

	return tMaze;
}
void genMaze(bool** maze, int w, int h, int type){
	srand(time(NULL));
	fillMaze(maze, w, h);
	switch (type)
	{
	case tree: treeAlgo(maze, w, h); break;
	//case backtrack: backtrackAlgo(maze, w, h); break;
	}
	
}
void treeAlgo(bool** maze, int w, int h){
	int rVal = 0;

	for (int i = 1; i < w; i+=2)
		for (int j = 1; j < h; j+=2)
		{
			rVal = rand() % 2; //Переменная случая
			if (rVal == 0 && i != 1) maze[i - 1][j] = false; //Если ячейка не находится слева и случай равен 0, то соединяем с Западом
			else if(j != h - 2)maze[i][j + 1] = false; //Иначе с Севером
			if (rVal == 1 && j != h - 2)maze[i][j + 1] = false; //Если ячейка не находится сверху и случай равен 1, то соединяем с Севером
			else if (i != 1)maze[i - 1][j] = false; //Иначе с Западом
		}
}
/*void backtrackAlgo(bool** maze,int w, int h){
	int rVal = 0;
	struct Cell {
		int x = 1,
			y = 1;
	}lastCell;

	bool** visitedCellsList = initMaze(w, h);
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++) visitedCellsList[i][j] = false;
	
	for (int i = 1; i < w; i += 2)
		for (int j = 1; j < h; j += 2)
		{
			rVal = rand() % 4;
					if (rVal == 0 && j < h - 2 && visitedCellsList[i][j] == false && visitedCellsList[i][j + 1] == false) //Движение на Север
					{
						maze[i][j + 1] = false;
						visitedCellsList[i][j] = true;
						visitedCellsList[i][j + 2] = true;
						if(j) j += 2;
					}
					else if (rVal == 1 && i < w - 2 && visitedCellsList[i][j] == false && visitedCellsList[i + 1][j] == false) //Движение на Восток
					{
						maze[++i][j] = false;
						visitedCellsList[i][j] = true;
						visitedCellsList[i + 2][j] = true;
						i += 2;
					} 
					else if (rVal == 2 && j != 1 && visitedCellsList[i][j] == false && visitedCellsList[i][j - 1] == false) //Движение на Юг
					{
						maze[i][j - 1] = false;
						visitedCellsList[i][j] = true;
						visitedCellsList[i][j - 2] = true;
						j -= 2;
					}
					else if (rVal == 3 && i != 1 && visitedCellsList[i][j] == false && visitedCellsList[i - 1][j] == false) //Движение на Запад
					{
						maze[--i][j] = false;
						visitedCellsList[i][j] = true;
						visitedCellsList[i - 2][j] = true; 
						i -= 2;
					}
					
		}

}*/

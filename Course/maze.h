#pragma once
//Переменные
extern int mazeWidth, mazeHeight; //Переменные ширины и высоты лабиринта
extern bool** maze; //Матрица хранящая данные о лабиринте (0 = пол, 1 = стена)
enum mazeTypes {
				tree,
				backtrack,
};

//Функции
bool** initMaze(int mazeWidth, int mazeHeight); //Функция инициализации лабиринта
void fillMaze(bool** maze, int w, int h);  //Процедура заполнения лабиринта
void genMaze(bool** maze, int w, int h, int type); // Процедура генерации лабиринта

//Функции-алгоритмы
void treeAlgo(bool** maze, int w, int h); //Алгоритм бинарного дерева (смещение Северо-Запад)
	 //backtrackAlgo(bool** maze, int w, int h);
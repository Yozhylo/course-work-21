#pragma once
//Переменные

static GLfloat wRed = 0.0f, wGreen = 0.0f, wBlue = 0.0f, //Значения цветов для стены
			   fRed = 1.0f, fGreen = 1.0f, fBlue = 1.0f; //Значения цветов для пола
enum colors {
	color_white,
	color_black,
	color_grey,
	color_red,
	color_green,
	color_blue,
};
enum menuChoice {
				menu_gen_maze,
				menu_screenshot_maze,
};
//Структура граф. настроек
static struct gPrefs{
	int windowWidth = 500,
		windowHeight = 500;
}CurPrefs;

//Функции
void drawMaze(bool** maze, int mazeWidth, int mazeHeight); //Процедура отрисовки всего лабиринта
void drawTile(bool isWall); //Процедура отрисовки ячейки лабиринта
void renderScene(); //Процедура отрисовки всей сцены
void reshapeWindow(int w, int h); //Процедура реакции на изменение размеров окна
void createContextMenu(); //Процедура создания контекстного меню
int mazeToFile(int w, int h); //Функция записи лабиринта в файл

//process-функции
void processGenMenu(int choice); //Процедура обработки событий меню генерации
void processWallColorMenu(int choice); //Процедура обработки событий меню смены цвета стены
void processFloorColorMenu(int choice); //Процедура обработки событий меню смены цвета пола
void processResizeMazeMenu(int choice); //Процедру обратотки событий меню смены размера
void processMainMenu(int choice); //Процедура обработки событий главного меню
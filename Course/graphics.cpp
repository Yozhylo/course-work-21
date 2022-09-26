#pragma warning(disable : 4996)

#include "GL\freeglut.h"
#include "graphics.h"
#include "maze.h"
#include <fstream>

void drawTile(bool isWall){
	glBegin(GL_TRIANGLE_FAN); //Начало отрисовки клетки при помощи примитива треугольник
		//Определяем стена или пол, соответствено назначаем цвет для примитива
		if (isWall == false) glColor3f(fRed,fGreen,fBlue);
		else glColor3f(wRed, wGreen, wBlue);
		
		//Определяем координаты, в нашем случае, граней примитива
		glVertex2f(0, 0);
		glVertex2f(1, 0); glVertex2f(1, 1);
		glVertex2f(0, 1);
	glEnd();
}
void drawMaze(bool** maze, int mazeWidth, int mazeHeight){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glScalef((GLfloat)(2.0/mazeWidth), (GLfloat)(2.0/mazeHeight), 1);
	glTranslatef((GLfloat)(-0.5*mazeWidth), (GLfloat)(-0.5*mazeHeight), 0);
	for (int i = 0; i < mazeWidth; i++)
		for (int j = 0; j < mazeHeight; j++)
		{
			glPushMatrix();
				glTranslatef((GLfloat)i, (GLfloat)j, 0);
				drawTile(maze[i][j]);
			glPopMatrix();
		}
}
void renderScene(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Очистка буфферов цвета и глубины
	drawMaze(maze, mazeWidth, mazeHeight);
	glutSwapBuffers();
}
void reshapeWindow(int width, int height) {
	//Исчисляем соотношение сторон окна и предотвращаем деление на ноль
	if (height == 0) height = 1;
	GLfloat ratio = (GLfloat)width / (GLfloat)height;

	
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width >= height) gluOrtho2D(-1.0 * ratio, 1.0 * ratio, -1.0, 1.0);
	else gluOrtho2D(-1.0, 1.0, -1.0 / ratio, 1.0 / ratio);
}
void createContextMenu(){
	int genMenu = glutCreateMenu(processGenMenu);
	glutAddMenuEntry("Binary Tree Algorithm", menu_gen_maze);
	
	int wallColorMenu = glutCreateMenu(processWallColorMenu);
	glutAddMenuEntry("White",color_white);
	glutAddMenuEntry("Black", color_black);
	glutAddMenuEntry("Grey", color_grey);
	glutAddMenuEntry("Red", color_red);
	glutAddMenuEntry("Green", color_green);
	glutAddMenuEntry("Blue", color_blue);

	int floorColorMenu = glutCreateMenu(processFloorColorMenu);
	glutAddMenuEntry("White", color_white);
	glutAddMenuEntry("Black", color_black);
	glutAddMenuEntry("Grey", color_grey);
	glutAddMenuEntry("Red", color_red);
	glutAddMenuEntry("Green", color_green);
	glutAddMenuEntry("Blue", color_blue);

	
	int resizeMazeMenu = glutCreateMenu(processResizeMazeMenu);
	glutAddMenuEntry("15X15", 15);
	glutAddMenuEntry("25X25", 25);
	glutAddMenuEntry("50X50", 50);
	glutAddMenuEntry("75X75", 75);
	glutAddMenuEntry("100X100", 100);

	int mainMenu = glutCreateMenu(processMainMenu);
	glutAddSubMenu("Change size of the maze", resizeMazeMenu);
	glutAddSubMenu("Generate a maze", genMenu);
	glutAddSubMenu("Change the color of walls", wallColorMenu);
	glutAddSubMenu("Change the color of floors", floorColorMenu);
	glutAddMenuEntry("Export maze to targa image", menu_screenshot_maze);
	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//process
void processGenMenu(int choice) {
	if(choice == menu_gen_maze) genMaze(maze, mazeWidth, mazeHeight, 0);
}
void processWallColorMenu(int choice) {
	switch (choice)
	{
	case color_white: {
		wRed = 1.0f; wGreen = 1.0f; wBlue = 1.0f;
	break;}
	case color_black: {
		wRed = 0.0f; wGreen = 0.0f; wBlue = 0.0f;
		break; }
	case color_grey: {
		wRed = 0.5f; wGreen = 0.5f; wBlue = 0.5f;
		break; }
	case color_red: {
		wRed = 1.0f; wGreen = 0.2f; wBlue = 0.2f;
		break; }
	case color_green: {
		wRed = 0.2f; wGreen = 1.0f; wBlue = 0.2f;
		break; }
	case color_blue: {
		wRed = 0.2f; wGreen = 0.2f; wBlue = 1.0f;
		break; }
	}
}
void processFloorColorMenu(int choice) {
	switch (choice)
	{
	case color_white: {
		fRed = 1.0f, fGreen = 1.0f, fBlue = 1.0f;
		break; }
	case color_black: {
		fRed = 0.0f, fGreen = 0.0f, fBlue = 0.0f;
		break; }
	case color_grey: {
		fRed = 0.5f, fGreen = 0.5f, fBlue = 0.5f;
		break; }
	case color_red: {
		fRed = 1.0f, fGreen = 0.2f, fBlue = 0.2f;
		break; }
	case color_green: {
		fRed = 0.2f, fGreen = 1.0f, fBlue = 0.2f;
		break; }
	case color_blue: {
		fRed = 0.2f, fGreen = 0.2f, fBlue = 1.0f;
		break; }
	}
}
void processResizeMazeMenu(int choice) {
	switch (choice)
	{
	case 15: {
		mazeWidth = 15, mazeHeight = 15; maze = initMaze(mazeWidth, mazeHeight);
		break; }
	case 25: {
		mazeWidth = 25, mazeHeight = 25; maze = initMaze(mazeWidth, mazeHeight);
		break; }
	case 50: {
		mazeWidth = 51, mazeHeight = 51; maze = initMaze(mazeWidth, mazeHeight);
		break; }
	case 75: {
		mazeWidth = 75, mazeHeight = 75; maze = initMaze(mazeWidth, mazeHeight);
		break; }
	case 100: {
		mazeWidth = 101, mazeHeight = 101; maze = initMaze(mazeWidth, mazeHeight);
		break; }
	}
}
void processMainMenu(int choice){
	if (choice == menu_screenshot_maze) mazeToFile(CurPrefs.windowWidth,CurPrefs.windowHeight);
}
int mazeToFile(int w, int h)
{
	char *output = new char[w * h * 3];

	glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, output);

	FILE *pFile = 0;        //Указатель на файл

	unsigned char tgaHeader[12] = { 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; //Создаем заголовок к .tga
	unsigned char header[6];
	unsigned char bits = 24; //Битность
	int colorMode = 3; //Цветовой режим
	unsigned char tempColors = 0;

	pFile = fopen("maze.tga", "wb");


	if (!pFile) return 0; //Проверка на открытие


	header[0] = CurPrefs.windowWidth % 256;
	header[1] = CurPrefs.windowWidth / 256;
	header[2] = CurPrefs.windowHeight % 256;
	header[3] = CurPrefs.windowHeight / 256;
	header[4] = bits;
	header[5] = 0;

	//Записываем хедеры в начало файла:
	fwrite(tgaHeader, sizeof(tgaHeader), 1, pFile);
	fwrite(header, sizeof(header), 1, pFile);


	for (int i = 0; i < w * h * colorMode; i += colorMode) //Меняем данные местами (RGB -> BRG)
	{
		tempColors = output[i];
		output[i] = output[i + 2];
		output[i + 2] = tempColors;
	}

	// Записываем данные изображения:
	fwrite(output, CurPrefs.windowWidth * CurPrefs.windowHeight * colorMode, 1, pFile);

	// Закрываем файл
	fclose(pFile);

	// Удаляем ненужные теперь данные
	delete[] output;
	return 1;
} //Функция передачи лабиринта в файл


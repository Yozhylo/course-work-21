#include <GL/freeglut.h>
#include "graphics.h"
#include "maze.h"

void main(int argc, char **argv)
{
	//Инициализация окна
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(CurPrefs.windowWidth, CurPrefs.windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Maze");

	//Отрисовка окна и его содержимого
	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshapeWindow);

	glutIdleFunc(renderScene);
	createContextMenu();
	
	glutMainLoop();

	delete[] maze;
}
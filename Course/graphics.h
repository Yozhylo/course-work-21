#pragma once
//����������

static GLfloat wRed = 0.0f, wGreen = 0.0f, wBlue = 0.0f, //�������� ������ ��� �����
			   fRed = 1.0f, fGreen = 1.0f, fBlue = 1.0f; //�������� ������ ��� ����
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
//��������� ����. ��������
static struct gPrefs{
	int windowWidth = 500,
		windowHeight = 500;
}CurPrefs;

//�������
void drawMaze(bool** maze, int mazeWidth, int mazeHeight); //��������� ��������� ����� ���������
void drawTile(bool isWall); //��������� ��������� ������ ���������
void renderScene(); //��������� ��������� ���� �����
void reshapeWindow(int w, int h); //��������� ������� �� ��������� �������� ����
void createContextMenu(); //��������� �������� ������������ ����
int mazeToFile(int w, int h); //������� ������ ��������� � ����

//process-�������
void processGenMenu(int choice); //��������� ��������� ������� ���� ���������
void processWallColorMenu(int choice); //��������� ��������� ������� ���� ����� ����� �����
void processFloorColorMenu(int choice); //��������� ��������� ������� ���� ����� ����� ����
void processResizeMazeMenu(int choice); //�������� ��������� ������� ���� ����� �������
void processMainMenu(int choice); //��������� ��������� ������� �������� ����
#pragma once
//����������
extern int mazeWidth, mazeHeight; //���������� ������ � ������ ���������
extern bool** maze; //������� �������� ������ � ��������� (0 = ���, 1 = �����)
enum mazeTypes {
				tree,
				backtrack,
};

//�������
bool** initMaze(int mazeWidth, int mazeHeight); //������� ������������� ���������
void fillMaze(bool** maze, int w, int h);  //��������� ���������� ���������
void genMaze(bool** maze, int w, int h, int type); // ��������� ��������� ���������

//�������-���������
void treeAlgo(bool** maze, int w, int h); //�������� ��������� ������ (�������� ������-�����)
	 //backtrackAlgo(bool** maze, int w, int h);
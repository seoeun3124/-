#pragma once
#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include <mmsystem.h> 
#include "Utility.h"
#include "stage.h"
char name[200];  //�÷��̾� �̸�
int round;       //����
int score;       //����
int level;       //���̵� : 1=����  2=����  3=�����
void MainGame();
void MainRender();
void thirdback();
void displayStart();
void resizeConsole(int width, int height);
void gameStart();
void saveCheck();
void secondback();
int cnt;
HDC BackgroundDC;        //����̹�������
HBITMAP BackgroundMap;   //����̹�������
HDC StartScreenDC[10];       //�����̹�������
HBITMAP StartScreenMap[10];  //�����̹�������
#endif
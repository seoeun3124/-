#pragma once
#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include <mmsystem.h> 
#include "Utility.h"
#include "stage.h"
char name[200];  //플레이어 이름
int round;       //라운드
int score;       //점수
int level;       //난이도 : 1=쉬움  2=보통  3=어려움
void MainGame();
void MainRender();
void thirdback();
void displayStart();
void resizeConsole(int width, int height);
void gameStart();
void saveCheck();
void secondback();
int cnt;
HDC BackgroundDC;        //배경이미지저장
HBITMAP BackgroundMap;   //배경이미지저장
HDC StartScreenDC[10];       //시작이미지저장
HBITMAP StartScreenMap[10];  //시작이미지저장
#endif
#pragma once
#include "Main.h"
#include "stage.h"
#ifndef UTILITY_H
#define UTILITY_H
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <mmsystem.h> 
#include <time.h>
#include <Process.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "msimg32.lib")
#define gamemusic "..//Debug//resources//music//start.wav"
#define startmusic "..//Debug//resources//music/music0.wav"
#define AttackButtonSize 90
#define ButtonSize 147

void UtilityInit();
void gotoxy(int x, int y);
void HideCursor(char show);
void LI(HDC* DC, HBITMAP* Map, char* path);
void PO(int sx, int sy, int ox, int oy, int w, int h, HDC originDC);
void PI(int sx, int sy, int w, int h, HDC originDC);
void PT(int sx, int sy, int w, int h, HDC originDC);

HWND ConsoleWindow;            
HINSTANCE ConsoleInstance;      
HDC ConsoleDC;                  

DWORD WINAPI ThreadFunc(LPVOID);

HANDLE hThrd; //스레드를 접근하기 위한 손잡이 개념
DWORD threadId;

HDC     StartScreenDC[10], BackgroundDC;     //시작이미지,배경이미지
HBITMAP StartScreenMap[10], BackgroundMap;   //시작이미지,배경이미지
HDC CafeDC;
HBITMAP CafeMap;
HDC ParkDC;
HBITMAP ParkMap;
HDC ParkcutDC;
HBITMAP ParkcutMap;
HDC     ButtonDC[10];        //방향키
HBITMAP ButtonMap[10];       //방향키

HDC     AttackButtonDC[5];  //공격버튼
HBITMAP AttackButtonMap[5];  //공격버튼
char Music[10][300];
int MaxLife;
int CurrentLife;
int zomcnt1;
int key;
int cnt;
typedef struct {
	int Width;   //가로길이
	int Height;  //세로길이
	HDC WaitDC[5][5];        //대기이미지    0=뒤  1=앞  2=왼  3=오
	HBITMAP WaitMap[5][5];   //대기이미지
	HDC WalkDC[5][5];        //걷는이미지
	HBITMAP WalkMap[5][5];   //걷는이미지
	HDC LifeDC[5];
	HBITMAP LifeMap[5];
	int SpriteCount;    //캐릭터 이미지 카운트
	int xPosition;  //캐릭터 X좌표
	int yPosition;  //캐릭터 Y좌표
	int dw;
	int hp;
	int dir;   //캐릭터가 보고 있는 방향
}Character;
Character player;
typedef struct {
	int Width;
	int Height;
	HDC WalkDC[5][5];
	HBITMAP WalkMap[5][5];
	int hp;
	int xPosition;
	int yPosition;
	int dir;
}Zombie;
typedef struct {
	HDC WaitDC[2][30];
	HBITMAP WaitMap[2][30];
	int Width; // 408
	int Height; //396
	int xPosition;
	int yPosition;
	int cnt;

}Boss;
Boss boss;
Zombie zombie;
typedef struct {
	int atxPosition;
	int atyPosition;
	HDC WeaponDC[30];
	HBITMAP WeaponMap[30];
	int dir;
}Pencil;
Pencil pencil;

#endif
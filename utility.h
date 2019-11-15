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

HANDLE hThrd; //�����带 �����ϱ� ���� ������ ����
DWORD threadId;

HDC     StartScreenDC[10], BackgroundDC;     //�����̹���,����̹���
HBITMAP StartScreenMap[10], BackgroundMap;   //�����̹���,����̹���
HDC CafeDC;
HBITMAP CafeMap;
HDC ParkDC;
HBITMAP ParkMap;
HDC ParkcutDC;
HBITMAP ParkcutMap;
HDC     ButtonDC[10];        //����Ű
HBITMAP ButtonMap[10];       //����Ű

HDC     AttackButtonDC[5];  //���ݹ�ư
HBITMAP AttackButtonMap[5];  //���ݹ�ư
char Music[10][300];
int MaxLife;
int CurrentLife;
int zomcnt1;
int key;
int cnt;
typedef struct {
	int Width;   //���α���
	int Height;  //���α���
	HDC WaitDC[5][5];        //����̹���    0=��  1=��  2=��  3=��
	HBITMAP WaitMap[5][5];   //����̹���
	HDC WalkDC[5][5];        //�ȴ��̹���
	HBITMAP WalkMap[5][5];   //�ȴ��̹���
	HDC LifeDC[5];
	HBITMAP LifeMap[5];
	int SpriteCount;    //ĳ���� �̹��� ī��Ʈ
	int xPosition;  //ĳ���� X��ǥ
	int yPosition;  //ĳ���� Y��ǥ
	int dw;
	int hp;
	int dir;   //ĳ���Ͱ� ���� �ִ� ����
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
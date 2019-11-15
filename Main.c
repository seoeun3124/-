#include "Main.h"
#define ZOMBIE_SPEED 1
unsigned _stdcall Thread_Attack(void *arg) {
	while (1) {
		if (GetAsyncKeyState(0x31) < 0 && player.dir == 3) {
			for (int i = pencil.atxPosition; i <= pencil.atxPosition + 70; i += 7) {
				PT(i, pencil.atyPosition, 43, 7, pencil.WeaponDC[3]);
				Sleep(50);
			}
		}
		if (GetAsyncKeyState(0x31) < 0 && player.dir == 2) {
			for (int i = pencil.atxPosition; i >= player.xPosition - 70; i -= 7) {
				PT(i, pencil.atyPosition, 43, 7, pencil.WeaponDC[2]);
				Sleep(50);
			}
		}
		if (GetAsyncKeyState(0x31) < 0 && player.dir == 1) {
			for (int i = pencil.atyPosition; i <= pencil.atyPosition + 70; i += 7) {
				PT(pencil.atxPosition, i, 7, 43, pencil.WeaponDC[1]);
				Sleep(50);
			}
		}
		if (GetAsyncKeyState(0x31) < 0 && player.dir == 0) {
			for (int i = pencil.atyPosition; i >= pencil.atyPosition - 70; i -= 7) {
				PT(pencil.atxPosition, i, 7, 43, pencil.WeaponDC[4]);
				Sleep(50);
			}
		}
		pencil.atxPosition = player.xPosition;
		pencil.atyPosition = player.yPosition;
	}
}
unsigned _stdcall Thread_Zombie(void *arg) {
	while (1) {
		PI(0, 0, 1222, 851, BackgroundDC);
		if (zombie.xPosition > player.xPosition) {
			if (cannotgoleft() < 0) {
				PT(zombie.xPosition, zombie.yPosition, zombie.Width, zombie.Height, zombie.WalkDC[3][zomcnt1++]);
			}
			else {
				PT(zombie.xPosition - ZOMBIE_SPEED, zombie.yPosition, zombie.Width, zombie.Height, zombie.WalkDC[3][zomcnt1++]);
				zombie.xPosition -= ZOMBIE_SPEED;
			}
			PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
			PT(200, 650, ButtonSize, ButtonSize,	ButtonDC[4]);
			LifeCheck();
			zomcnt1 %= 4;
			zombie.dir = 3;
		}
		else if (zombie.xPosition < player.xPosition) {
			if (cannotgoright() < 0) {
				PT(zombie.xPosition, zombie.yPosition, zombie.Width, zombie.Height, zombie.WalkDC[2][zomcnt1++]);
			}
			else {
				PT(zombie.xPosition + ZOMBIE_SPEED, zombie.yPosition, zombie.Width, zombie.Height, zombie.WalkDC[2][zomcnt1++]);
				zombie.xPosition += ZOMBIE_SPEED;
			}
			PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
			PT(200, 650, ButtonSize, ButtonSize, ButtonDC[4]);
			LifeCheck();
			zomcnt1 %= 4;
			zombie.dir = 2;
		}
		if (zombie.yPosition > player.yPosition) {
			if (cannotgoright() < 0) {
				PT(zombie.xPosition, zombie.yPosition, zombie.Width, zombie.Height, zombie.WalkDC[0][zomcnt1++]);
			}
			else {
				PT(zombie.xPosition, zombie.yPosition - ZOMBIE_SPEED, zombie.Width, zombie.Height, zombie.WalkDC[0][zomcnt1++]);
				zombie.yPosition -= ZOMBIE_SPEED;
			}
			PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
			PT(200, 650, ButtonSize, ButtonSize, ButtonDC[4]);
			LifeCheck();
			zomcnt1 %= 4;
			zombie.dir = 0;
		}
		else if (zombie.yPosition < player.yPosition) {
			if (cannotgoright() < 0) {
				PT(zombie.xPosition, zombie.yPosition, zombie.Width, zombie.Height, zombie.WalkDC[1][zomcnt1++]);
			}
			else {
				PT(zombie.xPosition, zombie.yPosition + ZOMBIE_SPEED, zombie.Width, zombie.Height, zombie.WalkDC[1][zomcnt1++]);
				zombie.yPosition += ZOMBIE_SPEED;
			}
			PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
			PT(200, 650, ButtonSize, ButtonSize, ButtonDC[4]);
			LifeCheck();
			zomcnt1 %= 4;
			zombie.dir = 1;
		}
		else
		{
			PT(zombie.xPosition, zombie.yPosition, zombie.Width, zombie.Height, zombie.WalkDC[zombie.dir][zomcnt1++]);
			PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
			PT(200, 650, ButtonSize, ButtonSize, ButtonDC[4]);
			LifeCheck();
		}
	
	}
}
int main() {
	HideCursor(0); //커서숨기기
	UtilityInit();   //이미지 불러오기
	displayStart(); //시작 화면 출력
	saveCheck();  //세이브 파일 불러오기 및 체크
	PT(zombie.xPosition, zombie.yPosition, zombie.Width, zombie.Height, zombie.WalkDC[4][1]);
	_beginthreadex(NULL, 0, Thread_Attack, 0, 0, NULL);
	//_beginthreadex(NULL, 0, Thread_Zombie, 0, 0, NULL);
	player.xPosition = 200;
	player.yPosition = 100;
	PlaySound(0, 0, 0);
	PlaySound(TEXT(Music[1]), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (1) {
		switch (key)
		{
			case 1:
				MainRender();
				Sleep(50);
				break;
			case 2:
				secondback();
				Sleep(50);
				break;
			case 3:
				thirdback();
				Sleep(50);
				break;
		}
	}
}
void secondback() {
	PT(0, 0, 1324, 865, CafeDC);
	if (GetAsyncKeyState(VK_DOWN) < 0) {   //아래 방향키 눌렀을때
		player.dir = 1; //yPosition-50
		if (cannotgodownincafe() < 0) {
			PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WalkDC[1][cnt++]);
		}
		else if (cannotgodownincafe() == 2) {
			PlaySound(0, 0, 0);
			PlaySound(TEXT(Music[1]), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			key = 1;
			system("cls");
			resizeConsole(120, 40);
			player.xPosition = 880;
			player.yPosition = 20;
		}
		else {
			PT(player.xPosition, player.yPosition + 10, player.Width, player.Height, player.WalkDC[1][cnt++]);
			player.yPosition += 10;
		}
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player.dir]);
		LifeCheck(1000,1128);
		cnt = cnt % 4;
	}
	else if (GetAsyncKeyState(VK_UP) < 0) {  //위 방향키 눌렀을때
		player.dir = 0;
		if (cannotgoupincafe() < 0) {
			PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WalkDC[0][cnt++]);
		}
		else if (cannotgoupincafe() == 3) {
			PlaySound(0, 0, 0);
			PlaySound(TEXT(Music[2]), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WalkDC[0][cnt++]);
			system("cls");
			key = 3;
			resizeConsole(100, 43);
			player.xPosition = 850;
			player.yPosition = 560;
			
		}
		else {
			PT(player.xPosition, player.yPosition - 10, player.Width, player.Height, player.WalkDC[0][cnt++]);
			player.yPosition -= 10;
		}
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player.dir]);
		LifeCheck(1000,1128);
		cnt = cnt % 4;
	}
	else if (GetAsyncKeyState(VK_LEFT) < 0) {   //왼쪽 방향키 눌렀을때
		if (cannotgoleftincafe() == -1) {
			PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WalkDC[2][cnt++]);
		}
		else
		{
			PT(player.xPosition - 10, player.yPosition, player.Width, player.Height, player.WalkDC[2][cnt++]);
			player.xPosition -= 10;
		}
		player.dir = 2;
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player.dir]);
		LifeCheck(1000,1128);
		cnt = cnt % 4;
	}
		else if (GetAsyncKeyState(VK_RIGHT) < 0) {
		if (cannotgorightincafe() == -1) {
				PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WalkDC[3][cnt++]);
			}
		else {
			PT(player.xPosition + 10, player.yPosition, player.Width, player.Height, player.WalkDC[3][cnt++]);
			player.xPosition += 10;
		}
		player.dir = 3;
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player.dir]);
		LifeCheck(1000,1128);
		cnt = cnt % 4;
	}
	else {
		PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WaitDC[player.dir][cnt++]);
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[4]);
		LifeCheck(1000,1128);
		cnt = cnt % 4;
		player.dw = 0;
	}
}
void thirdback() {
	PT(0, 0, 1000, 869, ParkDC);  //배경출력
	
	//0 : 뒤 1 : 앞 2 : 왼 3 : 오
	// render selection bar
	if (GetAsyncKeyState(VK_DOWN) < 0) {   //아래 방향키 눌렀을때
		player.dir = 1; //yPosition-50
		if (cannotgodowninpark() < 0) {
			PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WalkDC[1][cnt++]);
		}
		else {
			PT(player.xPosition, player.yPosition + 10, player.Width, player.Height, player.WalkDC[1][cnt++]);
			player.yPosition += 10;
		}
		PT(0, 0, 1000, 869, ParkcutDC);
		PT(70, 690, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player.dir]);
		LifeCheck(800,928);
		cnt = cnt % 4;
	}
	else if (GetAsyncKeyState(VK_UP) < 0) {  //위 방향키 눌렀을때
		player.dir = 0;
		if (cannotgoupinpark() < 0) {
			PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WalkDC[0][cnt++]);
		}
		else if (cannotgoupinpark() == 4) {
			PlaySound(0, 0, 0);
			PlaySound(TEXT(Music[2]), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			key = 2;
			system("cls");
			resizeConsole(130, 45);
			player.xPosition = 125;
			player.yPosition = 50;
		}
		else {
			PT(player.xPosition, player.yPosition - 10, player.Width, player.Height, player.WalkDC[0][cnt++]);
			player.yPosition -= 10;
		}
		PT(0, 0, 1000, 869, ParkcutDC);
		PT(70, 690, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player.dir]);
		LifeCheck(800,928);
		cnt = cnt % 4;
	}
	else if (GetAsyncKeyState(VK_LEFT) < 0) {   //왼쪽 방향키 눌렀을때
		if (cannotgoleftinpark() < 0) {
			PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WalkDC[2][cnt++]);
		}
		else
		{
			PT(player.xPosition - 10, player.yPosition, player.Width, player.Height, player.WalkDC[2][cnt++]);
			player.xPosition -= 10;
		}
		PT(0, 0, 1000, 869, ParkcutDC);
		player.dir = 2;
		PT(70, 690, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player.dir]);
		LifeCheck(800,928);
		cnt = cnt % 4;
	}
	else if (GetAsyncKeyState(VK_RIGHT) < 0) {
		if (cannotgorightinpark() < 0) {
			PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WalkDC[3][cnt++]);
		}
		else {
			PT(player.xPosition + 10, player.yPosition, player.Width, player.Height, player.WalkDC[3][cnt++]);
			player.xPosition += 10;
		}
		PT(0, 0, 1000, 869, ParkcutDC);
		player.dir = 3;
		PT(70, 690, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player.dir]);
		LifeCheck(800,928);
		cnt = cnt % 4;
	}
	else {
		PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WaitDC[player.dir][cnt++]);
		PT(70, 690, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[4]);
		PT(0, 0, 1000, 869, ParkcutDC);
		LifeCheck(800,928);
		cnt = cnt % 4;
		player.dw = 0;
	}
}
void resizeConsole(int width, int height) {  //콘솔 크기 설정
	char ch[100];
	sprintf(ch, "mode con cols=%d lines=%d", width, height);
	system(ch);
}
void saveCheck() {  //세이브 파일 불러오기 및 체크
	char continuegame;
	SetConsoleTitle("saveCheck"); //콘솔 이름 설정

	gotoxy(0, 0);
	printf("이름을 입력하세요\n");
	HideCursor(1);
	scanf("%s", name);
	HideCursor(0);
	FILE *fp = fopen(name, "r");
	if (fp != NULL) {
		printf("이전 세이브 파일이 존재합니다. 계속하시겠습니까?(y/n)\n");
		scanf(" %c", &continuegame);
		if (continuegame == 'y' || continuegame == 'Y') {
			//세이브 파일 읽어 그 라운드에서 계속
			printf("계속하기\n");
			fscanf(fp, "%d %d", &round, &score);
			fclose(fp);
			Sleep(1500);
		}
		else if (continuegame == 'n' || continuegame == 'N') {
			//세이브 파일 버리고 새로 쓰기
			printf("새로하기\n");
			round = 0;
			score = 0;
			fclose(fp);
			Sleep(1500);
		}
		else printf("입력 : >>%c<<\n잘못 입력하셨습니다.\n", continuegame);
	}
	else {
		printf("새 게임");
		round = 0;
		score = 0;
		Sleep(1500);
	}
	system("cls");

	PlaySound(0, 0, 0);

}
void displayStart() {    //시작 화면 출력
	SetConsoleTitle("DisplayStart"); //콘솔 이름 설정
	PlaySound(TEXT(Music[0]), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	resizeConsole(120, 35);
	while (!_kbhit()) {
		for (int i = 1; i <= 2; i++) {
			PT(0, 0, 1200, 670, StartScreenDC[i]);
			Sleep(500);
		}
	}
	_getch();
	system("cls"); 
	resizeConsole(120, 40);
}
void gameStart() {
	if (round == 0) {
		round0();
	}
	else if (round == 1) {
		round1();
	}
	else if (round == 2) {
		round2();
	}
	else if (round == 3) {
		round3();
	}
	else if (round == 4) {
		gameclear();
	}
}
void MainRender() {   // render background
	player.Width = 19;
	player.Height = 47;
	PT(0, 0, 1222, 851, BackgroundDC);  //배경출력
	//0 : 뒤 1 : 앞 2 : 왼 3 : 오
	// render selection bar
	if (GetAsyncKeyState(VK_DOWN) < 0) {   //아래 방향키 눌렀을때
		player.dir = 1; //yPosition-50
		if (cannotgodown() < 0) {
			PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WalkDC[1][cnt++]);
		}
		else {
			PT(player.xPosition, player.yPosition + 10, player.Width, player.Height, player.WalkDC[1][cnt++]);
			player.yPosition += 10;
		}
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player.dir]);
		LifeCheck(1000,1128);
		cnt = cnt % 4;
	}
	else if (GetAsyncKeyState(VK_UP) < 0) {  //위 방향키 눌렀을때
		player.dir = 0;
		if (cannotgoup() < 0) {
			PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WalkDC[0][cnt++]);
		}
		else if (cannotgoup() == 1) {
			PlaySound(0, 0, 0);
			PlaySound(TEXT(Music[1]), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			key = 2;
			system("cls");
			resizeConsole(130, 45);
			player.xPosition = 250;
			player.yPosition = 600;
		}
		else {
			PT(player.xPosition, player.yPosition - 10, player.Width, player.Height, player.WalkDC[0][cnt++]);
			player.yPosition -= 10;
		}
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player.dir]);
		LifeCheck(1000,1128);
		cnt = cnt % 4;
	}
	else if (GetAsyncKeyState(VK_LEFT) < 0) {   //왼쪽 방향키 눌렀을때
		if (cannotgoleft() < 0) {
			PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WalkDC[2][cnt++]);
		}
		else
		{
			PT(player.xPosition - 10, player.yPosition, player.Width, player.Height, player.WalkDC[2][cnt++]);
			player.xPosition -= 10;
		}
		player.dir = 2;
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player.dir]);
		LifeCheck(1000,1128);
		cnt = cnt % 4;
	}
	else if (GetAsyncKeyState(VK_RIGHT) < 0) {
		if (cannotgoright() < 0) {
			PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WalkDC[3][cnt++]);
		}
		else {
			PT(player.xPosition + 10, player.yPosition, player.Width, player.Height, player.WalkDC[3][cnt++]);
			player.xPosition += 10;
		}
		player.dir = 3;
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player.dir]);
		LifeCheck(1000,1128);
		cnt = cnt % 4;
	}
	else {
		PT(player.xPosition, player.yPosition, player.Width, player.Height, player.WaitDC[player.dir][cnt++]);
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[4]);
		LifeCheck(1000,1128);
		cnt = cnt % 4;
		player.dw = 0;
	}
	
}
void MainGame() {  //?
	//MainInit();
	UtilityInit();
	MainRender(0);
}
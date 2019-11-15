#include "utility.h"
#define WIN32_LEAN_AND_MEAN
static HWND hWnd;
static HINSTANCE hInst;
#define MINUS_Y 40
#define MINUS_X 15
void LifeCheck(int x,int y) {
	CurrentLife = 4;
	for (int i = 1; i < CurrentLife; i++) {
		for (int xp = x; xp <= y; xp += 32) {
			PT(xp, 10, 30, 30, player.LifeDC[i]);
		}
	}
}
int cannotgoup() {
	if (((player.xPosition <= 135 - MINUS_X && player.xPosition >= 35 - MINUS_X) || (player.xPosition >= 260 - MINUS_X && player.xPosition <= 425 - MINUS_X) ||
		(player.xPosition >= 545 - MINUS_X && player.xPosition <= 675 - MINUS_X) || (player.xPosition >= 730 - MINUS_X && player.xPosition <= 840 - MINUS_X) ||
		(player.xPosition >= 930 - MINUS_X && player.xPosition <= 1027 - MINUS_X))
		&& (player.yPosition == 320 - MINUS_Y)) {
		return -1;
	}
	else if (((player.xPosition >= 130 - MINUS_X && player.xPosition <= 260 - MINUS_X) || (player.xPosition >= 415 - MINUS_X && player.xPosition <= 545 - MINUS_X))
		&& (player.yPosition == 350 - MINUS_Y)) {
		return -1;
	}
	else if (((player.xPosition >= 670 - MINUS_X && player.xPosition <= 740 - MINUS_X)) && player.yPosition == 410 - MINUS_Y) {
		return -1;
	}
	else if (((player.xPosition >= 35 - MINUS_X && player.xPosition <= 1090 - MINUS_X)) && player.yPosition == 730 - MINUS_Y) {
		return -1;
	}
	else if (player.yPosition == 20 && (player.xPosition<=845-MINUS_X || player.xPosition>=925-MINUS_X)) {
		return -1;
	}
	if (player.yPosition <= 0) {
		return 1;
	}
	if (((zombie.xPosition <= 135 - MINUS_X && zombie.xPosition >= 35 - MINUS_X) || (zombie.xPosition >= 260 - MINUS_X && zombie.xPosition <= 425 - MINUS_X) ||
		(zombie.xPosition >= 545 - MINUS_X && zombie.xPosition <= 675 - MINUS_X) || (zombie.xPosition >= 730 - MINUS_X && zombie.xPosition <= 840 - MINUS_X) ||
		(zombie.xPosition >= 930 - MINUS_X && zombie.xPosition <= 1027 - MINUS_X))
		&& (zombie.yPosition == 320 - MINUS_Y)) {
		return -1;
	}
	else if (((zombie.xPosition >= 130 - MINUS_X && zombie.xPosition <= 260 - MINUS_X) || (zombie.xPosition >= 415 - MINUS_X && zombie.xPosition <= 545 - MINUS_X))
		&& (zombie.yPosition == 350 - MINUS_Y)) {
		return -1;
	}
	else if (((zombie.xPosition >= 670 - MINUS_X && zombie.xPosition <= 740 - MINUS_X)) && zombie.yPosition == 410 - MINUS_Y) {
		return -1;
	}
	else if (((zombie.xPosition >= 35 - MINUS_X && zombie.xPosition <= 1090 - MINUS_X)) && zombie.yPosition == 730 - MINUS_Y) {
		return -1;
	}

	else return 0;
}
int cannotgodown() {
	if (((player.xPosition >= 53 - MINUS_X && player.xPosition <= 640 - MINUS_X) || (player.xPosition >= 740 - MINUS_X && player.xPosition <= 800 - MINUS_X)
		|| (player.xPosition >= 835 - MINUS_X &&
			player.xPosition <= 930 - MINUS_X) || (player.xPosition >= 965 - MINUS_X && player.xPosition <= 1025 - MINUS_X))
		&& (player.yPosition == 600 - MINUS_Y))
	{
		return -1;
	}
	else if (((player.xPosition >= 35 - MINUS_X && player.xPosition <= 135 - MINUS_X) || (player.xPosition >= 255 - MINUS_X && player.xPosition <= 420 - MINUS_X)
		|| (player.xPosition >= 545 - MINUS_X && player.xPosition <= 680 - MINUS_X)) && (player.yPosition == 600 - MINUS_Y)) {
		return -1;
	}
	else if (((player.xPosition >= 130 - MINUS_X && player.xPosition <= 260 - MINUS_X) || (player.xPosition >= 420 - MINUS_X && player.xPosition <= 545 - MINUS_X)) &&
		(player.yPosition == 570 - MINUS_Y)) {
		return -1;
	}
	else if (((player.xPosition >= 35 - MINUS_X && player.xPosition <= 835 - MINUS_X) || (player.xPosition >= 930 - MINUS_X && player.xPosition <= 1090 - MINUS_X)) &&
		(player.yPosition == 180 - MINUS_Y)) {
		return -1;
	}
	else if (((player.xPosition >= 675 - MINUS_X && player.xPosition <= 740 - MINUS_X) 
		|| (player.xPosition >= 1027 - MINUS_X && player.xPosition <= 1090 - MINUS_X)) && (player.yPosition == 500 - MINUS_Y)) {
		return -1;
	}
	else if (((player.xPosition >= 640 - MINUS_X && player.xPosition <= 675 - MINUS_X) || (player.xPosition >= 800 - MINUS_X && player.xPosition <= 835 - MINUS_X) ||
		(player.xPosition >= 930 - MINUS_X && player.xPosition <= 965 - MINUS_X)) && (player.yPosition == 570 - MINUS_Y)) {
		return -1;
	}
	/*
	if (((zombie.xPosition >= 53 - MINUS_X && zombie.xPosition <= 640 - MINUS_X) || (zombie.xPosition >= 740 - MINUS_X && zombie.xPosition <= 800 - MINUS_X)
		|| (zombie.xPosition >= 835 - MINUS_X &&
			zombie.xPosition <= 930 - MINUS_X) || (zombie.xPosition >= 965 - MINUS_X && zombie.xPosition <= 1025 - MINUS_X))
		&& (zombie.yPosition == 600 - MINUS_Y))
	{
		return -1;
	}
	else if (((zombie.xPosition >= 35 - MINUS_X && zombie.xPosition <= 135 - MINUS_X) || (zombie.xPosition >= 255 - MINUS_X && zombie.xPosition <= 420 - MINUS_X)
		|| (zombie.xPosition >= 545 - MINUS_X && zombie.xPosition <= 680 - MINUS_X)) && (zombie.yPosition == 600 - MINUS_Y)) {
		return -1;
	}
	else if (((zombie.xPosition >= 130 - MINUS_X && zombie.xPosition <= 260 - MINUS_X) || (zombie.xPosition >= 420 - MINUS_X && zombie.xPosition <= 545 - MINUS_X)) &&
		(zombie.yPosition == 570 - MINUS_Y)) {
		return -1;
	}
	else if (((zombie.xPosition >= 35 - MINUS_X && zombie.xPosition <= 835 - MINUS_X) || (zombie.xPosition >= 930 - MINUS_X && zombie.xPosition <= 1090 - MINUS_X)) &&
		(zombie.yPosition == 180 - MINUS_Y)) {
		return -1;
	}
	else if (((zombie.xPosition >= 675 - MINUS_X && zombie.xPosition <= 740 - MINUS_X)
		|| (zombie.xPosition >= 1027 - MINUS_X && zombie.xPosition <= 1090 - MINUS_X)) && (zombie.yPosition == 500 - MINUS_Y)) {
		return -1;
	}
	else if (((zombie.xPosition >= 640 - MINUS_X && zombie.xPosition <= 675 - MINUS_X) || (zombie.xPosition >= 800 - MINUS_X && zombie.xPosition <= 835 - MINUS_X) ||
		(zombie.xPosition >= 930 - MINUS_X && zombie.xPosition <= 965 - MINUS_X)) && (zombie.yPosition == 570 - MINUS_Y)) {
		return -1;
	}*/
	if (player.yPosition == 760 ) {
		return -1;
	}
	else return 0;
}
int cannotgoleft() {
	if (((player.yPosition >= 190 - MINUS_Y && player.yPosition <= 310 - MINUS_Y)) && player.xPosition == 845 - MINUS_X) {
		return -1;
	}
	else if (((player.yPosition >= 310 - MINUS_Y && player.yPosition <= 410 - MINUS_Y) ||
		(player.yPosition>=510 - MINUS_Y && player.yPosition<=600 - MINUS_Y)) && player.xPosition == 745 - MINUS_X) {
		return -1;
	}
	else if (((player.xPosition == 265 - MINUS_X || player.xPosition == 555- MINUS_X) && (player.yPosition >= 260 - MINUS_Y && player.yPosition <= 345 - MINUS_Y))) {
		return -1;
	}
	else if (((player.xPosition == 265 - MINUS_X) || (player.xPosition == 555 - MINUS_X)
		|| (player.xPosition == 845 - MINUS_X) || (player.xPosition == 975 - MINUS_X)) && (player.yPosition >= 570 - MINUS_Y && player.yPosition <= 600 - MINUS_Y)) {
		return -1;
	}
	else if ((player.xPosition == 1105 - MINUS_X) && (player.yPosition >= 190 - MINUS_Y && player.yPosition <= 730 - MINUS_Y)) {
		return -1;
	}
	/*if (((zombie.yPosition >= 190 - MINUS_Y && zombie.yPosition <= 310 - MINUS_Y)) && zombie.xPosition == 845 - MINUS_X) {
		return -1;
	}
	else if (((zombie.yPosition >= 310 - MINUS_Y && zombie.yPosition <= 410 - MINUS_Y) ||
		(player.yPosition >= 510 - MINUS_Y && zombie.yPosition <= 600 - MINUS_Y)) && zombie.xPosition == 745 - MINUS_X) {
		return -1;
	}
	else if (((zombie.xPosition == 265 - MINUS_X || zombie.xPosition == 555 - MINUS_X) && (zombie.yPosition >= 260 - MINUS_Y && zombie.yPosition <= 345 - MINUS_Y))) {
		return -1;
	}
	else if (((zombie.xPosition == 265 - MINUS_X) || (zombie.xPosition == 555 - MINUS_X)
		|| (zombie.xPosition == 845 - MINUS_X) || (zombie.xPosition == 975 - MINUS_X)) && (zombie.yPosition >= 570 - MINUS_Y && zombie.yPosition <= 600 - MINUS_Y)) {
		return -1;
	}
	else if ((zombie.xPosition == 1105 - MINUS_X) && (zombie.yPosition >= 190 - MINUS_Y && zombie.yPosition <= 730 - MINUS_Y)) {
		return -1;
	}
	*/
	else if (player.xPosition == 15-MINUS_X) {
		return -1;
	}
	else return 0;
}
int cannotgoright() {
	if (((player.xPosition == 135 - MINUS_X || player.xPosition == 425 - MINUS_X) && (player.yPosition >= 260 - MINUS_Y && player.yPosition <= 345 - MINUS_Y))) {
		return -1;
	}
	else if ((player.xPosition == 35 - MINUS_X) && (player.yPosition >= 185 - MINUS_Y && player.yPosition <= 315 - MINUS_Y)) {
		return -1;
	}
	else if ((player.xPosition == 35 - MINUS_X) && (player.yPosition >= 605 - MINUS_Y && player.yPosition <= 730 - MINUS_Y)) {
		return -1;
	}
	else if (((player.xPosition == 125 - MINUS_X) || (player.xPosition == 415 - MINUS_X) || (player.xPosition == 645 - MINUS_X)
		|| (player.xPosition == 805 - MINUS_X) || (player.xPosition == 935 - MINUS_X)) && (player.yPosition >= 570 - MINUS_Y && player.yPosition <= 600 - MINUS_Y)) {
		return -1;
	}
	else if ((player.xPosition == 675 - MINUS_X || player.xPosition == 1025 - MINUS_X) && player.yPosition >= 510 - MINUS_Y && player.yPosition <= 610 - MINUS_Y) {
		return -1;
	}
	else if ((player.xPosition == 925 - MINUS_X) && (player.yPosition >= 190 - MINUS_Y && player.yPosition <= 315 - MINUS_Y)) {
return -1;
	}
	else if ((player.xPosition == 1025 - MINUS_X) && (player.yPosition >= 310 - MINUS_Y && player.yPosition <= 600 - MINUS_Y)) {
	return -1;
	}
	else if ((player.xPosition == 675 - MINUS_X) && (player.yPosition >= 310 - MINUS_Y && player.yPosition <= 410 - MINUS_Y)) {
	return -1;
	}
	/*
	if (((zombie.xPosition == 135 - MINUS_X || zombie.xPosition == 425 - MINUS_X) && (zombie.yPosition >= 260 - MINUS_Y && zombie.yPosition <= 345 - MINUS_Y))) {
		return -1;
	}
	else if ((zombie.xPosition == 35 - MINUS_X) && (zombie.yPosition >= 185 - MINUS_Y && zombie.yPosition <= 315 - MINUS_Y)) {
		return -1;
	}
	else if ((zombie.xPosition == 35 - MINUS_X) && (zombie.yPosition >= 605 - MINUS_Y && zombie.yPosition <= 730 - MINUS_Y)) {
		return -1;
	}
	else if (((zombie.xPosition == 125 - MINUS_X) || (zombie.xPosition == 415 - MINUS_X) || (zombie.xPosition == 645 - MINUS_X)
		|| (zombie.xPosition == 805 - MINUS_X) || (zombie.xPosition == 935 - MINUS_X)) && (zombie.yPosition >= 570 - MINUS_Y && zombie.yPosition <= 600 - MINUS_Y)) {
		return -1;
	}
	else if ((zombie.xPosition == 675 - MINUS_X || zombie.xPosition == 1025 - MINUS_X) && zombie.yPosition >= 510 - MINUS_Y && zombie.yPosition <= 610 - MINUS_Y) {
		return -1;
	}
	else if ((zombie.xPosition == 925 - MINUS_X) && (zombie.yPosition >= 190 - MINUS_Y && zombie.yPosition <= 315 - MINUS_Y)) {
		return -1;
	}
	else if ((zombie.xPosition == 1025 - MINUS_X) && (zombie.yPosition >= 310 - MINUS_Y && zombie.yPosition <= 600 - MINUS_Y)) {
		return -1;
	}
	else if ((zombie.xPosition == 675 - MINUS_X) && (zombie.yPosition >= 310 - MINUS_Y && zombie.yPosition <= 410 - MINUS_Y)) {
		return -1;
	} */
	else if (player.xPosition == 1170) {
		return -1;
	}
	else {
		return 0;
	}
}
int cannotgoupincafe() {
	if (player.xPosition >= 0 - MINUS_X && player.xPosition <= 195 - MINUS_X && player.yPosition == 400 - MINUS_Y) {
		return -1;
	}
	else if (player.xPosition >= 195 - MINUS_X && player.xPosition <= 355 - MINUS_X && player.yPosition == 140 - MINUS_Y) {
		return -1;
	}
	else if (player.yPosition == 80 - MINUS_Y && player.xPosition >= 95 - MINUS_X && player.xPosition <= 195 - MINUS_X) {
		return 3;
	}
	else if (player.yPosition == 400 - MINUS_Y && player.xPosition >= 345 - MINUS_X && player.xPosition <= 965 - MINUS_X) {
		return -1;
	}
	else if (player.xPosition >= 415 - MINUS_X && player.xPosition <= 875 - MINUS_X && player.yPosition == 150 - MINUS_Y) {
		return -1;
	}
	else if (player.yPosition == 300 - MINUS_Y && player.xPosition >= 1055 - MINUS_X && player.xPosition <= 1155 - MINUS_X) {
		return -1;
	}
	else if (player.xPosition >= 350 - MINUS_X && player.xPosition <= 960 - MINUS_X && player.yPosition == 660 - MINUS_Y) {
		return -1;
	}
	else if (player.xPosition >= 0 - MINUS_X && player.xPosition <= 195 - MINUS_X && player.yPosition == 660 - MINUS_Y) {
		return -1;
	}
	return 0;
}
int cannotgoleftincafe() {
	if (player.xPosition == 105 - MINUS_X && player.yPosition >= 130 - MINUS_Y && player.yPosition <= 240 - MINUS_Y) {
		return -1;
	}
	else if (player.xPosition == 215 - MINUS_X && player.yPosition >= 200 - MINUS_Y && player.yPosition <= 400 - MINUS_Y) {
		return -1;
	}
	else if ((player.xPosition == 105 - MINUS_X) && (player.yPosition >= 70 - MINUS_Y && player.yPosition <= 140 - MINUS_Y)) {
		return -1;
	}
	else if (player.xPosition == 365 - MINUS_X && player.yPosition >= 0 - MINUS_Y && player.yPosition <= 130 - MINUS_Y) {
		return -1;
	}
	else if (player.xPosition == 975 - MINUS_X && player.yPosition >= 230 - MINUS_Y && player.yPosition <= 400 - MINUS_Y) {
		return -1;
	}
	else if (player.xPosition == 575 - MINUS_X && player.yPosition >= 200 - MINUS_Y && player.yPosition <= 230 - MINUS_Y) {
		return -1;
	}
	else if (player.xPosition == 835 - MINUS_X && player.yPosition >= 200 - MINUS_Y && player.yPosition <= 230 - MINUS_Y) {
		return -1;
	}
	else if (player.yPosition >= 70 - MINUS_Y & player.yPosition <= 140 - MINUS_Y && player.xPosition == 885 - MINUS_X) {
		return -1;
	}
	else if (player.yPosition >= 100 - MINUS_Y && player.yPosition <= 300 - MINUS_Y && player.xPosition == 1165 - MINUS_X) {
		return -1;
	}
	else if (player.yPosition >= 490 - MINUS_Y && player.yPosition <= 660 - MINUS_Y && ((player.xPosition == 97 - MINUS_X)
		|| (player.xPosition == 205 - MINUS_X))) {
		return -1;
	}
	else if (player.xPosition == 195 - MINUS_X && player.yPosition >= 750 - MINUS_Y && player.yPosition <= 860 - MINUS_Y){
	return -1;
}
	else if (player.xPosition == 955 - MINUS_X && player.yPosition >= 730 - MINUS_Y && player.yPosition <= 860 - MINUS_Y) {
		return -1;
	}
	else return 0;
}
int cannotgorightincafe() {
	if (player.xPosition == 155 - MINUS_X && player.yPosition >= 200 - MINUS_Y && player.yPosition <= 230 - MINUS_Y) {
		return -1;
	}
	else if ((player.xPosition == 195 - MINUS_X) && (player.yPosition >= 70 - MINUS_Y && player.yPosition <= 140 - MINUS_Y)) {
		return -1;
	}
	else if (player.xPosition == 345 -MINUS_X && player.yPosition >= 230 - MINUS_Y && player.yPosition <= 400 - MINUS_Y) {
		return -1;
	}
	else if (player.xPosition == 485 - MINUS_X && player.yPosition >= 200 - MINUS_Y && player.yPosition <= 230- MINUS_Y) {
		return -1;
	}
	else if (player.xPosition == 745 - MINUS_X && player.yPosition >= 200 - MINUS_Y && player.yPosition <= 230- MINUS_Y) {
		return -1;
	}
	else if (player.yPosition >= 70 - MINUS_Y & player.yPosition <= 140 - MINUS_Y && player.xPosition == 415 - MINUS_X) {
		return -1;
	}
	else if (player.yPosition >= 100 - MINUS_Y && player.yPosition <= 300 - MINUS_Y && player.xPosition == 1055 - MINUS_X) {
		return -1;
	}
	else if (player.yPosition >= 490 - MINUS_Y && player.yPosition <= 660 - MINUS_Y && player.xPosition == 355 - MINUS_X) {
		return -1;
	}
	else if (player.xPosition == 345 - MINUS_X && player.yPosition >= 730 - MINUS_Y && player.yPosition <= 860 - MINUS_Y) {
		return -1;
	}
	return 0;
}
int cannotgodownincafe() {
	if (player.yPosition == 230 - MINUS_Y && player.xPosition >= 95 - MINUS_X && player.xPosition <= 155 - MINUS_X) {
		return -1;
	}
	else if (player.xPosition >= 155 - MINUS_X && player.xPosition <= 185 - MINUS_X && player.yPosition == 190 - MINUS_Y) {
		return -1;
	}
	else if (player.yPosition == 230 - MINUS_Y && ((player.xPosition >= 345 && player.xPosition <= 485 - MINUS_X) ||
		(player.xPosition >= 565 - MINUS_X && player.xPosition <= 745 - MINUS_X) || (player.xPosition>=825-MINUS_X && player.xPosition<= 955-MINUS_X))) {
		return -1;
	}
	else if (player.yPosition == 200 - MINUS_Y && ((player.xPosition >= 485 - MINUS_X && player.xPosition <= 565 - MINUS_X)
		|| (player.xPosition >= 745 - MINUS_X && player.xPosition <= 825 - MINUS_X))) {
		return -1;
	}
	else if (player.yPosition == 100 - MINUS_Y && player.xPosition >= 1055 - MINUS_X && player.xPosition <= 1155 - MINUS_X) {
		return -1;
	}
	else if (player.xPosition >= 350 - MINUS_X && player.xPosition <= 960 - MINUS_X && player.yPosition == 490 - MINUS_Y) {
		return -1;
	}
	else if ((player.xPosition >= 0 - MINUS_X && player.xPosition <= 195 - MINUS_X) && ((player.yPosition == 490 - MINUS_Y) || (player.yPosition==740-MINUS_Y))) {
		return -1;
	}
	else if (player.yPosition == 730 - MINUS_Y && player.xPosition >= 345 - MINUS_X && player.xPosition <= 955 - MINUS_X) {
		return -1;
	}
	else if (player.yPosition == 810 - MINUS_Y && player.xPosition >= 965 - MINUS_X && player.xPosition <= 1313 - MINUS_X) {
		return -1;
	}
	else if (player.yPosition == 830 - MINUS_Y && player.xPosition <= 345 - MINUS_X && player.xPosition >= 195 - MINUS_X) {
		return 2;
	}
	else return 0;
}
int cannotgoupinpark() {
	if ((player.xPosition >= 190 - MINUS_X && player.xPosition <= 230 - MINUS_X ||
		(player.xPosition >= 460 - MINUS_X && player.xPosition <= 490 - MINUS_X) ||
		(player.xPosition >= 710 - MINUS_X && player.xPosition <= 750 - MINUS_X) ||
		(player.xPosition >= 980 - MINUS_X) ||
		(player.xPosition >= 310 - MINUS_X && player.xPosition <= 380 - MINUS_X) ||
		(player.xPosition >= 570 - MINUS_X && player.xPosition <= 640 - MINUS_X)) &&
		(player.yPosition <= 460 - MINUS_Y && player.yPosition >= 410)) {
		return -1;
	}
	else if (((player.xPosition >= 300 - MINUS_X && player.xPosition <= 380 - MINUS_X) ||
		(player.xPosition >= 560 - MINUS_X && player.xPosition <= 640 - MINUS_X)) &&
		(((player.yPosition == 460 - MINUS_Y) || (player.yPosition == 610 - MINUS_Y)))) {
		return -1;
	}
	return 0;
}
int cannotgodowninpark() {
	if (((player.xPosition >= 190 - MINUS_X && player.xPosition <= 230 - MINUS_X) ||
		(player.xPosition >= 460 - MINUS_X && player.xPosition <= 490 - MINUS_X) ||
		(player.xPosition >= 710 - MINUS_X && player.xPosition <= 750 - MINUS_X) ||
		(player.xPosition >= 980 - MINUS_X))&&((player.yPosition==410-MINUS_Y)||(player.yPosition==560-MINUS_Y))) {
		return -1;
	}
	else if (player.xPosition <= 800 - MINUS_X && player.xPosition <= 900 - MINUS_X && player.yPosition == 560 - MINUS_Y) {
		return 3;
	}
	else if(((player.xPosition>=300-MINUS_X && player.xPosition<=380- MINUS_X)|| 
		(player.xPosition >= 560 - MINUS_X && player.xPosition <= 640 - MINUS_X)) &&
		(((player.yPosition == 430 - MINUS_Y) || (player.yPosition == 580 - MINUS_Y)))) {
		return -1;
	}
	else if (player.xPosition >= 0 - MINUS_X && player.xPosition <= 500 - MINUS_X && player.yPosition == 620 - MINUS_Y) {
		return -1;
	}
	else if (player.xPosition >= 500 - MINUS_X && player.xPosition <= 670 - MINUS_X && player.yPosition == 800 - MINUS_Y) {
		return -1;
	}
	return 0;
}
int cannotgoleftinpark() {
	if (((player.yPosition <= 460 - MINUS_Y && player.yPosition >= 410 - MINUS_Y)
		||(player.yPosition<=610-MINUS_Y &&player.yPosition>=570-MINUS_Y)) &&
		((player.xPosition == 240 - MINUS_X) || (player.xPosition == 500 - MINUS_X) ||
		(player.xPosition == 760 - MINUS_X))) {
		return -1;
	}
	else if (((player.xPosition == 480 - MINUS_X) || (player.xPosition == 640 - MINUS_X))
		&& (player.yPosition >= 430 - MINUS_Y && player.yPosition <= 460 - MINUS_Y)) {
		return -1;
	}
	else if (((player.xPosition == 380 - MINUS_X) || (player.xPosition == 640 - MINUS_X))
		&& ((player.yPosition >= 430 - MINUS_Y && player.yPosition <= 460 - MINUS_Y)
			||(player.yPosition>=580-MINUS_Y && player.yPosition<=610-MINUS_Y))) {
		return -1;
	}
	else if (player.xPosition == 510 - MINUS_X && player.yPosition >= 620 - MINUS_Y && player.yPosition <= 800 - MINUS_Y) {
		return -1;
	}
	else if (player.yPosition >= 800 - MINUS_Y && player.xPosition == 680 - MINUS_X) {
		return -1;
	}
	else return 0;
}
int cannotgorightinpark() {
	if ((player.yPosition <= 460 - MINUS_Y && player.yPosition >= 410 - MINUS_Y) &&
		((player.xPosition == 190 - MINUS_X) || (player.xPosition == 450 - MINUS_X) ||
		(player.xPosition == 720 - MINUS_X) || (player.xPosition == 970 - MINUS_X))) {
		return -1;
	}
	else if (((player.xPosition == 300 - MINUS_X) || (player.xPosition == 560 - MINUS_X))
		&& ((player.yPosition >= 430 - MINUS_Y && player.yPosition <= 460 - MINUS_Y)
		|| (player.yPosition >= 580 - MINUS_Y && player.yPosition <= 610 - MINUS_Y))) {
		return -1;
	}
	else if (player.xPosition == 80-MINUS_X && player.yPosition >= 0 - MINUS_Y && player.yPosition <= 120 - MINUS_Y) {
		return -1;
	}
	return 0;
}
void UtilityInit() {               //이미지 불러오는 함수
	SetConsoleTitle("UtilityInit");  //콘솔 이름 설정
	ConsoleInstance = GetModuleHandle(NULL);  // ┐
	ConsoleWindow = GetConsoleWindow();       // │이미지 관련 설정
	ConsoleDC = GetDC(ConsoleWindow);         // ┘
	LI(&BackgroundDC, &BackgroundMap, "..//Debug//resources//background//background.bmp");     //배경 이미지를 불러옴
	int i, j;
	LI(&CafeDC, &CafeMap, "..//Debug//resources//background//cafe.bmp");
	LI(&ParkDC, &ParkMap, "..//Debug//resources//background//park.bmp");
	LI(&ParkcutDC, &ParkcutMap, "..//Debug//resources//background//parkcut.bmp");
	char path[300];
	player.Height = 47;
	player.Width = 19;
	zombie.Height = 86;
	zombie.Width = 52;
	zombie.xPosition = 500;
	zombie.yPosition = 500;
	boss.xPosition = 500;
	boss.yPosition = 500;
	boss.Width = 408;
	boss.Height = 396;
	zomcnt1 = 0;
	boss.cnt = 0;
	key = 1;
	cnt = 0;
	pencil.atxPosition = player.xPosition;
	pencil.atyPosition = player.yPosition;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//zombie//%d//%d.bmp", i, j);
			LI(&zombie.WalkDC[i][j], &zombie.WalkMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {                 //캐릭터 걷는이미지 불러옴
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//player//walk//%d//%d.bmp",i,j);
			LI(&player.WalkDC[i][j],&player.WalkMap[i][j],path);
		}
	}
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= 28; j++) {
			sprintf(path, "..//Debug//resources//boss/%d//%d.bmp", i, j);
			LI(&boss.WaitDC[i][j], &boss.WaitMap[i][j], path);
		} 
	}
	for (int i = 1; i <= 2; i++) {
		sprintf(path, "..//Debug//resources//background//start%d.bmp", i);
		LI(&StartScreenDC[i], &StartScreenMap[i],path);
	}
	for (int i = 0; i < 4; i++) {                 //캐릭터 대기이미지 불러옴
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//player//wait//%d//%d.bmp", i, j);
			LI(&player.WaitDC[i][j], &player.WaitMap[i][j], path);
		}
	}
	for (i = 0; i < 5; i++) {                 //방향키 이미지 불러옴
		sprintf(path, "..//Debug//resources//button//button%d.bmp", i);
		LI(&ButtonDC[i], &ButtonMap[i], path);
	}
	for (i = 0; i < 2; i++) {                 //공격버튼 이미지 불러옴
		sprintf(path, "..//Debug//resources//button//attack%d.bmp", i);
		LI(&AttackButtonDC[i], &AttackButtonMap[i], path);
	}
	for (i = 0; i < 10; i++) {               //음악 경로 저장
		sprintf(Music[i], "..//Debug//resources//music//music%d.wav", i);
	}
	for (int i = 1; i <= 4; i++) {
		sprintf(path, "..//Debug//resources//weapon//%d.bmp",i);
		LI(&pencil.WeaponDC[i], &pencil.WeaponMap[i], path);
	}
	for (int i = 0; i < 4; i++) {
		sprintf(path, "..//Debug//resources//heart//%d.bmp", i);
		LI(&player.LifeDC[i], &player.LifeMap[i], path);
	}
}
void HideCursor(char show) {  //커서숨기기 :  show의 값이 0이면 숨김, 1이면 보임
	CONSOLE_CURSOR_INFO cc;
	cc.bVisible = show;
	cc.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cc);
}
void gotoxy(int x, int y) {        //좌표로 커서 이동 함수
	COORD co = { x,y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), co);
}
int kp(int key) {   //키보드 입력 상태 확인하는 함수  ????
	return (GetAsyncKeyState(key) & 0x8000);
}
void LI(HDC* DC, HBITMAP* Map, char* path) {  //LoadImage, 이미지를 불러오는 함수
	(*DC) = CreateCompatibleDC(ConsoleDC);
	(*Map) = (HBITMAP)LoadImage(NULL, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	SelectObject(*DC, *Map);
}
void PT(int sx, int sy, int w, int h, HDC originDC) {  //투명화 이미지 출력 
	TransparentBlt(ConsoleDC, sx, sy, w, h, originDC, 0, 0, w, h, RGB(255, 0, 255));  //RGB인자 값 : 제거할 배경 색
}
void PO(int sx, int sy, int ox, int oy, int w, int h, HDC originDC) { //?
	BitBlt(ConsoleDC, sx, sy, w, h, originDC, ox, oy, SRCCOPY);
}
void PI(int sx, int sy, int w, int h, HDC originDC) {         //?
	BitBlt(ConsoleDC, sx, sy, w, h, originDC, 0, 0, SRCCOPY);
}
void ST(int sx, int sy, int w, int h, HDC originDC) { // w,h -> 콘솔에 출력할 이미지 크기 , 400,100,300,150 ->위치, 크기
	StretchBlt(ConsoleDC, 0, 0, 1222, 851, BackgroundDC, 400, 100, 300, 150, SRCCOPY);
}   
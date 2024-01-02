#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include <conio.h>
#include <windows.h>

#pragma comment(lib,"Winmm.lib")
void loadResource();

void m(int map1[13][13], int map[13][13], int map2[13][13]);

void Book();

void drawmap();

char* intTOstring(int x);


void PK(struct gameRole* role, struct monster* m, int map[13][13], int i, int j);

void up(int floor);

void down(int floor);

char* intTOstring(int x);

void head();

void chuan(int k);

void keyDown();


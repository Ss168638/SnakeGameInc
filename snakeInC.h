#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

//UP, DOWN, LEFT and RIGHT Key Integer value
#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77

//Grid Size
#define ROW 12
#define COL 37
#define ROW_WIDTH 2
#define COL_WIDTH 2
#define ODD_NUMBER_MASK_BIT 1   //MASK BIT TO IDENTIFY ODD NUMBER
#define SNAKE_HEAD 'O'
#define SNAKE_FOOD '@'
#define TOP_BOTTOM_BORDER '-'
#define LEFT_RIGHT_BORDER '|'
#define COL_SEPERATOR '|'   //COLOUMN SEPERATOR
#define ROW_SEPERATOR '-'   //ROW SEPERATOR

//Snake Data
int POSX = 5;
int POSY = 5;
int x_speed = 2;
int y_speed = 0;
int snakeTail = 1;
int TPOSX[50];
int TPOSY[50];

//Food Postion Data
int FOODX = 0;
int FOODY = 0;

bool game_running = true;

//FUNCTIONS DECLARATION
void _init_();
void display_Snake();
void isEaten();
void get_Direction();
void check_Collision();
void display_Score();
void get_New_Food_Position();
bool isExistingTailPOS(int y, int x);
void delay();
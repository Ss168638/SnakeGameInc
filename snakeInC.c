#include "snakeInC.h"

void _init_()
{
    POSX = (rand()%COL);
    POSY = (rand()%ROW);
    if(((POSX & ODD_NUMBER_MASK_BIT) == ODD_NUMBER_MASK_BIT) && ((POSY & ODD_NUMBER_MASK_BIT) == ODD_NUMBER_MASK_BIT))
    {    
        if(POSX == 0 || POSX == COL || POSY == 0 || POSY == ROW) { _init_(); }
    }
    else { _init_(); }

    get_New_Food_Position();
}

void get_New_Food_Position()
{
    FOODX = (rand()%COL);
    FOODY = (rand()%ROW);
    if(((FOODX & ODD_NUMBER_MASK_BIT) == ODD_NUMBER_MASK_BIT) && ((FOODY & ODD_NUMBER_MASK_BIT) == ODD_NUMBER_MASK_BIT))
    {    
        if(FOODX == 0 || FOODX == COL || FOODY == 0 || FOODY == ROW)
        { get_New_Food_Position(); }
    }
    else { get_New_Food_Position(); }
}

void isEaten()
{
    if(POSX == FOODX && POSY == FOODY)
    {
        snakeTail++;
        get_New_Food_Position();
    }
}

bool isExistingTailPOS(int y, int x)
{
    int tail = snakeTail;
    while(tail > 0)
    {
        if((TPOSY[tail] == y) && (TPOSX[tail] == x)) return true;
        tail--;
    }
    return false;
}

void display_Score()
{
    printf("Score : %d \n", snakeTail);
}

void display_Snake()
{
    system("cls");
    display_Score();
    for(size_t r = 0; r <= ROW; ++r)
    {
        for(size_t c = 0; c <= COL; ++c)
        {
            if( r == 0 || r == ROW || c == 0 || c == COL)
            {
                if(r == 0 || r == ROW) fputc(TOP_BOTTOM_BORDER, stdout);
                else fputc(LEFT_RIGHT_BORDER, stdout);
            }
            else if((isExistingTailPOS(r, c) == true))
            {
                fputc(SNAKE_HEAD, stdout);
            }
            else if(r == FOODY && c == FOODX)
            {
                fputc(SNAKE_FOOD, stdout);
            }
            else 
            {
                if(r % ROW_WIDTH == 0) fputc(ROW_SEPERATOR, stdout);
                else if(c % COL_WIDTH == 0) fputc(COL_SEPERATOR, stdout);
                else fputc(' ', stdout);
            }
        }
        fputc('\n', stdout);
    }
}

void get_Direction()
{
    int keyPressed = 0;
    if(_kbhit())
    {
        keyPressed = _getch();
        switch(keyPressed)
        {
            case KB_UP:
            x_speed = 0;
            y_speed = -2;
            break;
            
            case KB_DOWN:
            x_speed = 0;
            y_speed = 2;
            break;
            
            case KB_LEFT:
            x_speed = -2;
            y_speed = 0;
            break;
            
            case KB_RIGHT:
            x_speed = 2;
            y_speed = 0;
            break;
        }
    }
    else
    {
        POSX = POSX + x_speed;
        POSY = POSY + y_speed;
    }
    check_Collision();
}

void check_Collision()
{
    if(POSX == 0 || POSX == COL) game_running = false;
    if(POSY == 0 || POSY == ROW) game_running = false;
    if(isExistingTailPOS(POSX, POSY)) game_running = false;
}

void delay()
{
    for(unsigned long long int t = 0; t < 0xFFFFFF7; ++t) { /* do nothing */ }
}

int main()
{
    srand(time(0)); //SEED VALUE FOR RANDOM FUNCTION
    _init_();   //INITIALIZE FOOD AND SNAKE LOCATION
    while(game_running)
    {
        TPOSY[1] = POSY;
        TPOSX[1] = POSX;
        display_Snake();
        isEaten();
        if(snakeTail > 1)
        {
            for(int i=snakeTail; i > 1; i--)
            {
                TPOSX[i] = TPOSX[i-1];
                TPOSY[i] = TPOSY[i-1];
            }
        }
        get_Direction();
        delay();
    }
    return 0;
}
#include <dos.h>
#include <conio.h>
#include <windows.h>
#include <graphics.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include<MMsystem.h>

using namespace std;

void submission();
void option();
void gametype();
void instructions();
void stagemenu();
void campaign();
void game();
void stage1();
void stage2();
void stage3();
void check();
void dead();
void gameover();
void level();
void high();

int snake_x[500],snake_y[500],snake_size = 5,score,highscore,spd = 100,l;

int flag=0,stage=0,bite=0,die=0,once=0;

bool checkdied = false,BONUS = false;
main()
{
    int gdirect = DETECT,gmode;  /* request autodetection */
    initgraph(&gdirect,&gmode,""); /* initialize graphics and local variables */

    int cursor_y = 130;
    char ch;
    while(1)
    {
        if (once==0) submission();///front page
        setcolor(WHITE);
        settextstyle(5,0,6);
        outtextxy(180,30," Snake ");
        setcolor(BLUE);

        settextstyle(3,0,4); /*this part prints menu again but inside while loop,because other functions will return here*/
        outtextxy(200,130,"New Game");
        outtextxy(200,160,"Options");
        outtextxy(200,190,"Highscore");
        outtextxy(200,220,"Exit");

        setcolor(WHITE);
        outtextxy(160,cursor_y,">");

        setcolor(RED);
        settextstyle(3,0,2);
        outtextxy(60,280,"<Visit The Option Menu First To Configure Your Game>");

        if(kbhit)
        {
            ch = getch();
            setcolor(BLACK);
            outtextxy(160,cursor_y,">");
            if(ch == 13)
            {
                if(cursor_y==130)
                {
                    dead();
                    if(flag==1)
                    {
                        campaign();
                        flag=0;
                    }

                    else
                    {
                        if (stage== 0)
                            game();
                        else if(stage == 1)
                            stage1();
                        else if (stage == 2)
                            stage2();
                        else
                            stage3();
                    }
                }
                else if(cursor_y==160)
                    option();

                else if(cursor_y==190)
                    high();

                else if(cursor_y==220)
                    exit(0);
            }
        }
        if(ch==80)
        {
            cursor_y+=30;
            if(cursor_y > 220)
            {
                cursor_y=130;
            }
        }
        if(ch==72)
        {
            cursor_y-=30;
            if(cursor_y < 130)
            {
                cursor_y=220;
            }
        }
    }
    return 0;
}
void submission()
{
    setcolor(3);
    settextstyle(4,0,4);
    outtextxy(90,2," Project-1: Snake");
    settextstyle(10,0,3);
    setcolor(10);
    outtextxy(20,80," Submitted by:");
    outtextxy(40,140,"Souhardya Saha Dip");
    outtextxy(40,160,"Registration No: 2017831024");

    outtextxy(40,200,"Pulock Das Kamol");
    outtextxy(40,220,"Registration No: 2017831046");

    outtextxy(20,280," Submitted to: ");
    outtextxy(40,320,"Asif Mohammed Samir Sir ");
    outtextxy(40,340,"Assistant Professor");
    outtextxy(40,360,"IICT,SUST");
//    //("gameover.wav",NULL,SND_FILENAME | SND_SYNC);
    getch();
    once=1;
    ////("menu.wav",NULL,SND_FILENAME | SND_SYNC);
    cleardevice();
    if(kbhit()) return;
}
void option()
{
    clearviewport();
    int cursor_y = 190;
    char ch;
    while(1)
    {
        settextstyle(3,0,3);

        setcolor(WHITE);
        outtextxy(160,cursor_y,">");

        setcolor(GREEN);
        outtextxy(200,190,"Instructions");
        outtextxy(200,220,"Game type");
        outtextxy(200,250,"Snake speed");

        setcolor(RED);
        settextstyle(3,0,3);
        outtextxy(130,350,"<<<Press ESC to return>>>");


        setcolor(WHITE);
        outtextxy(160,cursor_y,">");

        if(kbhit)
        {
            ch=getch();
            setcolor(BLACK);
            outtextxy(160,cursor_y,">");

            if(ch==80)
            {
                cursor_y+=30;
                if(cursor_y > 250)
                    cursor_y=190;
            }
            if(ch==72)
            {
                cursor_y-=30;
                if(cursor_y < 190)
                    cursor_y = 250;
            }
            if(ch==13)
            {
                if(cursor_y == 190)
                    instructions();
                else if (cursor_y == 220)
                    gametype();
                else if (cursor_y == 250)
                {
                    clearviewport();
                    level();
                }
            }
            if (ch == 27)
            {
                clearviewport();
                return;
            }
        }
    }
    return;
}
void gametype()
{
    clearviewport();
    int cursor_y = 190;
    char ch;
    while(1)
    {
        settextstyle(3,0,3);

        setcolor(WHITE);
        outtextxy(160,cursor_y,">");

        setcolor(RED);
        outtextxy(200,190,"Classic");
        outtextxy(200,220,"Campaign");
        outtextxy(200,250,"Select Stage");

        setcolor(RED);
        settextstyle(3,0,3);
        outtextxy(130,350,"<<<Press ESC to return>>>");

        setcolor(WHITE);
        outtextxy(160,cursor_y,">");

        if(kbhit)
        {
            ch=getch();
            setcolor(BLACK);
            outtextxy(160,cursor_y,">");

            if(ch==80)
            {
                cursor_y+=30;
                if(cursor_y > 250)
                    cursor_y=190;
            }
            if(ch==72)
            {
                cursor_y-=30;
                if(cursor_y < 190)
                    cursor_y = 250;
            }
            if(ch==13)
            {
                if(cursor_y == 190)
                {
                    stage = 0;
                    return;
                }
                else if (cursor_y == 220)
                {
                    flag=1;
                    return;
                }
                else if (cursor_y == 250)
                {
                    stagemenu();
                    return;
                }
            }
            if (ch == 27)
            {
                clearviewport();
                return;
            }
        }
    }
    return;
}
void stagemenu()
{
    clearviewport();
    int cursor_y = 190;
    char ch;
    while(1)
    {
        settextstyle(3,0,3);

        setcolor(WHITE);
        outtextxy(160,cursor_y,">");

        setcolor(RED);
        outtextxy(200,190,"Amateur");
        outtextxy(200,220,"Regular");
        outtextxy(200,250,"Professional");

        setcolor(WHITE);
        outtextxy(160,cursor_y,">");

        if(kbhit)
        {
            ch=getch();
            setcolor(BLACK);
            outtextxy(160,cursor_y,">");

            if(ch==80)
            {
                cursor_y+=30;
                if(cursor_y > 250)
                    cursor_y=190;
            }
            if(ch==72)
            {
                cursor_y-=30;
                if(cursor_y < 190)
                    cursor_y = 250;
            }
            if(ch==13)
            {
                if(cursor_y == 190)
                    stage = 1;
                else if (cursor_y == 220)
                    stage = 2;
                else if (cursor_y == 250)
                    stage = 3;

                return;
            }
            if (ch == 27)
            {
                clearviewport();
                return;
            }
        }
    }
    return;
}
void instructions()
{
    clearviewport();
    setcolor(WHITE);
    settextstyle(3,0,2);
    outtextxy(100,160,"USE THE ARROW KEYS TO MOVE THE SNAKE");
    outtextxy(100,190,"PRESS 'ALT' TO PAUSE");
    getch();
    clearviewport();
    return;
}
void game()
{
    clearviewport();

    freopen("GameData.dat","r",stdin);
    cin >> highscore;

    cleardevice();
    char ch;
    string key = "right";

    int maxx = getmaxx();
    int maxy = getmaxy()-50;    ///why this -50

    int x = 13,y = 13;

    int food_x = rand()%maxx,  food_y = rand()%maxy;
    int temp;
    temp = food_x%13;
    food_x-=temp;               ///why this minus
    temp = food_y%13;
    food_y-=temp;

    int i = 0;
    int bonus = 500;
    while(true)
    {
        clearviewport();
        if(score >0 && score%5==4)
            BONUS = true;
        else
        {
            bonus = 500;
            BONUS = false;
        }
        if(!BONUS || bonus == 0)
        {
            setcolor(BLACK);
            outtextxy(150,maxy+11,"THE BIG BITE AWAITS");
            setcolor(BLUE);    ///FOOD BORDER
            setfillstyle(SOLID_FILL,BLUE);
            circle(food_x,food_y,5);            ///x position, y position, size
            floodfill(food_x,food_y,BLUE);
        }
        else
        {
            setcolor(CYAN);
            setfillstyle(SOLID_FILL,CYAN);
            circle(food_x,food_y,10);
            floodfill(food_x,food_y,CYAN);

            char spp[1000];
            setcolor(BLACK);
            sprintf(spp,"THE BIG BITE AWAITS--%d",bonus);
            outtextxy(150,maxy+11,"THE BIG BITE AWAITS");
            setcolor(RED);
            outtextxy(150,maxy+11,spp);
            // clears
        }
        maxx = getmaxx();
        maxy = getmaxy()-50;

        setcolor(YELLOW);
        line(0,maxy+10,maxx,maxy+10);///down
        line(0,2,maxx,1); ///up
        line(2,2,2,maxy+10); ///left
        line(maxx-2,1,maxx-2,maxy+10); ///right

        if(kbhit())
        {
            ch = getch();
            if(ch == 0)
                ch = getch();
            if(ch == 72 && key != "down" )
                key = "up";
            if(ch == 80 && key != "up")
                key = "down";
            if(ch == 75 && key != "right")
                key = "left";
            if(ch == 77 && key != "left")
                key = "right";
            if(ch == 27) ///ESC=27
            {
                cleardevice();
                return;
            }
        }
        if(i < 5)
        {
            snake_x[i] = x-240;
            snake_y[i] = y-285;
            i++;
        }
        else
        {
            for(int _size = snake_size-2; _size >= 0; _size--)
            {
                snake_x[_size+1] = snake_x[_size];
                snake_y[_size+1] = snake_y[_size];
            }
            snake_x[0] = x;
            snake_y[0] = y;

            setcolor(RED);
            circle(snake_x[0],snake_y[0],8);
            setfillstyle(SOLID_FILL,RED);
            floodfill(snake_x[0],snake_y[0],RED);

            setcolor(WHITE);
            for(int _size = 1; _size < snake_size; _size++)
            {
                circle(snake_x[_size],snake_y[_size],5);
                setfillstyle(SOLID_FILL,WHITE);
                floodfill(snake_x[_size],snake_y[_size],WHITE);
            }

            char ara[100];
            sprintf(ara,"SCORE: %d",score);
            setcolor(WHITE);
            outtextxy(00,maxy+11,ara);
            sprintf(ara,"HIGHEST: %d",highscore);
            setcolor(WHITE);
            outtextxy(450,maxy+11,ara);

            delay(spd);

        }
        if(x == food_x && y== food_y)
        {
            bite++;
            if(bite==6 && flag==1)
                return;
            snake_size++;
            score++;
            /* Snake eats food*/
            if(score%5==0 && score>0)
                score+=bonus;

            food_x = rand()%maxx,food_y = rand()%maxy;
            temp = food_x%13;
            food_x-=temp;
            temp = food_y%13;
            food_y-=temp;

            if(food_x < 5 || food_x > maxx - 5 || food_y < 5 || food_y > maxy - 5)
            {
                while(food_x < 5 || food_x > maxx - 5 || food_y < 5 || food_y > maxy - 5)
                {
                    food_x = rand()%maxx,food_y = rand()%maxy;
                    temp = food_x%13;
                    food_x-=temp;
                    temp = food_y%13;
                    food_y-=temp;
                }
            }
        }
        if(key == "right")
            x = x+13;
        if(x > maxx)
            x =0;
        if(key == "left")
            x = x-13;
        if(x < 0)
            x = maxx-(maxx%13);
        if(key == "up")
            y = y-13;
        if(y > maxy)
            y = 0;
        if(key == "down")
            y = y+13;
        if(y < 0)
            y = maxy-(maxy%13);
        check();
        if(checkdied)
        {
            gameover();
            dead();
            return;
        }

        if(BONUS)
        {
            if(bonus>0)
                bonus-=10;
        }
        setcolor(BLACK);
        circle(snake_x[0],snake_y[0],8);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(snake_x[0],snake_y[0],BLACK);

        for(int _size = 1; _size < snake_size; _size++)
        {
            circle(snake_x[_size],snake_y[_size],5);
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(snake_x[_size],snake_y[_size],BLACK);
        }

    }
}
void stage1()
{
    clearviewport();

    freopen("GameData.dat","r",stdin);
    cin >> highscore;

    cleardevice();
    char ch;
    string key = "right";

    int maxx = getmaxx();
    int maxy = getmaxy()-50;    ///why this -50

    int x = 13,y = 13;

    int food_x = rand()%maxx,  food_y = rand()%maxy;
    int temp;
    temp = food_x%13;
    food_x-=temp;               ///why this minus
    temp = food_y%13;
    food_y-=temp;

    if(food_x <= 13 || food_x >= maxx - 13 || food_y <= 13 || food_y >= maxy - 13)
    {
        while(food_x <= 13 || food_x >= maxx - 13 || food_y <= 13 || food_y >= maxy - 13)
        {
            food_x = rand()%maxx,food_y = rand()%maxy;
            temp = food_x%13;
            food_x-=temp;
            temp = food_y%13;
            food_y-=temp;
        }
    }

    int i = 0;
    int bonus = 500;
    while(true)
    {
        clearviewport();
        if(score >0 && score%5==4)
            BONUS = true;
        else
        {
            bonus = 500;
            BONUS = false;
        }
        if(!BONUS || bonus == 0)
        {
            settextstyle(3,0,2);
            setcolor(BLACK);
            outtextxy(150,maxy+11,"THE BIG BITE AWAITS");
            setcolor(BLUE);    ///FOOD BORDER
            setfillstyle(SOLID_FILL,BLUE);
            circle(food_x,food_y,5);            ///x position, y position, size
            floodfill(food_x,food_y,BLUE);

        }
        else
        {
            setcolor(CYAN);
            setfillstyle(SOLID_FILL,CYAN);
            circle(food_x,food_y,10);
            floodfill(food_x,food_y,CYAN);

            char spp[1000];
            setcolor(BLACK);
            sprintf(spp,"THE BIG BITE AWAITS--%d",bonus);
            outtextxy(150,maxy+11,"THE BIG BITE AWAITS");
            setcolor(YELLOW);
            outtextxy(150,maxy+11,spp);
            // clears
        }

        setfillstyle(HATCH_FILL,RED);
        bar(0,0,10,425);///LEFT
        bar(10,0,631,10);///UP
        bar(621,10,631,425);///RIGHT
        bar(10,415,621,425);///DOWN
        setfillstyle(SOLID_FILL,YELLOW);

        maxx = getmaxx();
        maxy = getmaxy()-50;

        if(kbhit())
        {
            ch = getch();
            if(ch == 0)
                ch = getch();
            if(ch == 72 && key != "down" )
                key = "up";
            if(ch == 80 && key != "up")
                key = "down";
            if(ch == 75 && key != "right")
                key = "left";
            if(ch == 77 && key != "left")
                key = "right";
            if(ch == 27) ///ESC=27
            {
                cleardevice();
                return;
            }
        }

        if(i < 5)
        {
            snake_x[i] = x-240;
            snake_y[i] = y-285;
            i++;
        }
        else
        {
            for(int _size = snake_size-2; _size >= 0; _size--)
            {
                snake_x[_size+1] = snake_x[_size];
                snake_y[_size+1] = snake_y[_size];
            }
            snake_x[0] = x;
            snake_y[0] = y;

            setcolor(RED);
            circle(snake_x[0],snake_y[0],8);
            setfillstyle(SOLID_FILL,RED);
            floodfill(snake_x[0],snake_y[0],RED);

            setcolor(WHITE);
            for(int _size = 1; _size < snake_size; _size++)
            {
                circle(snake_x[_size],snake_y[_size],5);
                setfillstyle(SOLID_FILL,WHITE);
                floodfill(snake_x[_size],snake_y[_size],WHITE);
            }
            char ara[100];
            sprintf(ara,"SCORE: %d",score);
            setcolor(WHITE);
            outtextxy(00,maxy+11,ara);
            sprintf(ara,"HIGHEST: %d",highscore);
            setcolor(WHITE);
            outtextxy(450,maxy+11,ara);

            delay(spd);
        }

        if(x == food_x && y== food_y)
        {
            bite++;
            if(bite==6 && flag==1)
                return;
            snake_size++;
            score++;
            /* Snake eats food*/
            if(score%5==0 && score>0)
                score+=bonus;

            food_x = rand()%maxx,food_y = rand()%maxy;
            temp = food_x%13;
            food_x-=temp;
            temp = food_y%13;
            food_y-=temp;

            if(food_x <= 13 || food_x >= maxx - 13 || food_y <= 13 || food_y >= maxy - 13)
            {
                while(food_x <= 13 || food_x >= maxx - 13 || food_y <= 13 || food_y >= maxy - 13)
                {
                    food_x = rand()%maxx,food_y = rand()%maxy;
                    temp = food_x%13;
                    food_x-=temp;
                    temp = food_y%13;
                    food_y-=temp;
                }
            }
        }



        if(key == "right")
            x = x+13;
        if(x > maxx-13)
            checkdied=true;
        if(key == "left")
            x = x-13;
        if(x < 13)
            checkdied=true;
        if(key == "up")
            y = y-13;
        if(y > maxy-13)
            checkdied=true;
        if(key == "down")
            y = y+13;
        if(y < 13 )
            checkdied=true;
        check();
        if(checkdied)
        {
            gameover();
            dead();
            return;
        }
        if(BONUS)
        {
            if(bonus>0)
                bonus-=10;
        }
        setcolor(BLACK);
        circle(snake_x[0],snake_y[0],8);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(snake_x[0],snake_y[0],BLACK);

        for(int _size = 1; _size < snake_size; _size++)
        {
            circle(snake_x[_size],snake_y[_size],5);
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(snake_x[_size],snake_y[_size],BLACK);
        }
    }
}
void stage2()
{
    clearviewport();

    freopen("GameData.dat","r",stdin);
    cin >> highscore;

    cleardevice();
    char ch;
    string key = "right";

    int maxx = getmaxx();
    int maxy = getmaxy()-50;

    int x = 13,y = 13;

    int food_x = rand()%maxx,  food_y = rand()%maxy;
    int temp;
    temp = food_x%13;
    food_x-=temp;
    temp = food_y%13;
    food_y-=temp;

    if(food_x <= 13 || food_x >= maxx - 13 || food_y <= 13 || food_y >= maxy - 13)
    {
        while(food_x <= 13 || food_x >= maxx - 13 || food_y <= 13 || food_y >= maxy - 13)
        {
            food_x = rand()%maxx,food_y = rand()%maxy;
            temp = food_x%13;
            food_x-=temp;
            temp = food_y%13;
            food_y-=temp;
        }
    }

    int i = 0;
    int bonus = 500;

    while(true)
    {

        cleardevice();

        if(score >0 && score%5==4)
            BONUS = true;
        else
        {
            bonus = 500;
            BONUS = false;
        }
        if(!BONUS || bonus == 0)
        {
            settextstyle(3,0,2);
            setcolor(BLACK);
            outtextxy(150,maxy+11,"THE BIG BITE AWAITS");
            setcolor(BLUE);    ///FOOD BORDER
            setfillstyle(SOLID_FILL,BLUE);
            circle(food_x,food_y,5);            ///x position, y position, size
            floodfill(food_x,food_y,BLUE);

        }
        else
        {
            setcolor(CYAN);
            setfillstyle(SOLID_FILL,CYAN);
            circle(food_x,food_y,10);
            floodfill(food_x,food_y,CYAN);

            char spp[1000];
            setcolor(BLACK);
            sprintf(spp,"THE BIG BITE AWAITS--%d",bonus);
            outtextxy(150,maxy+11,"THE BIG BITE AWAITS");
            setcolor(YELLOW);
            outtextxy(150,maxy+11,spp);
            // clears
        }


        setfillstyle(HATCH_FILL,RED);
        bar(0,0,10,425);///LEFT
        bar(10,0,631,10);///UP
        bar(621,10,631,425);///RIGHT
        bar(10,415,621,425);///DOWN
        setfillstyle(SOLID_FILL,YELLOW);

        bar(195,299,429,312);///down
        bar(429,299,416,78);///right
        bar(195,299,208,78);///left
        bar(208,78,234,91);///up-left
        bar(416,78,390,91);///up-right

        maxx = getmaxx();
        maxy = getmaxy()-50;

        if(kbhit())
        {
            ch = getch();
            if(ch == 0)
                ch = getch();
            if(ch == 72 && key != "down" )
                key = "up";
            if(ch == 80 && key != "up")
                key = "down";
            if(ch == 75 && key != "right")
                key = "left";
            if(ch == 77 && key != "left")
                key = "right";
            if(ch == 27) ///ESC=27
            {
                cleardevice();
                return;
            }
        }
        if(i < 5)
        {
            snake_x[i] = x-240;
            snake_y[i] = y-285;
            i++;
        }
        else
        {
            for(int _size = snake_size-2; _size >= 0; _size--)
            {
                snake_x[_size+1] = snake_x[_size];
                snake_y[_size+1] = snake_y[_size];
            }
            snake_x[0] = x;
            snake_y[0] = y;

            setcolor(RED);
            circle(snake_x[0],snake_y[0],8);
            setfillstyle(SOLID_FILL,RED);
            floodfill(snake_x[0],snake_y[0],RED);
            setcolor(WHITE);

            for(int _size = 1; _size < snake_size; _size++)
            {
                circle(snake_x[_size],snake_y[_size],5);
                setfillstyle(SOLID_FILL,WHITE);
                floodfill(snake_x[_size],snake_y[_size],WHITE);
            }
            char ara[100];
            sprintf(ara,"SCORE: %d",score);
            setcolor(WHITE);
            outtextxy(00,maxy+11,ara);
            sprintf(ara,"HIGHEST: %d",highscore);
            setcolor(WHITE);
            outtextxy(450,maxy+11,ara);
            delay(spd);
        }

        if(x == food_x && y== food_y)
        {
            bite++;
            if(bite==6 && flag==1)
                return;
            snake_size++;
            score++;
            /* Snake eats food*/
            if(score%5==0 && score>0)
                score+=bonus;

food:
            food_x = rand()%maxx,food_y = rand()%maxy;
            temp = food_x%13;
            food_x-=temp;
            temp = food_y%13;
            food_y-=temp;

            if(food_x <= 13 || food_x >= maxx - 13 || food_y <= 13 || food_y >= maxy - 13)
            {
                while(food_x <= 13 || food_x >= maxx - 13 || food_y <= 13 || food_y >= maxy - 13)
                {
                    food_x = rand()%maxx,food_y = rand()%maxy;
                    temp = food_x%13;
                    food_x-=temp;
                    temp = food_y%13;
                    food_y-=temp;
                }
            }
        }

        if(food_x>=195 && food_x<=208 && food_y>=78 && food_y<=312)
            goto food;
        if(food_x>=416 && food_x<=429 && food_y>=78 && food_y<=312)
            goto food;
        if(food_x>=416 && food_x<=429 && food_y>=78 && food_y<=312)
            goto food;
        if(food_x>=208 && food_x<=416 && food_y>=299 && food_y<=312)
            goto food;
        if(food_x>=208 && food_x<=416 && food_y>=299 && food_y<=312)
            goto food;
        if(food_x>=208 && food_x<=234 && food_y>=78 && food_y<=91)
            goto food;
        if(food_x>=390 && food_x<=416 && food_y>=78 && food_y<=91)
            goto food;

        if(key == "right")
            x = x+13;
        if(x > maxx-13)
            checkdied=true;
        if(key == "left")
            x = x-13;
        if(x < 13)
            checkdied=true;
        if(key == "up")
            y = y-13;
        if(y > maxy-13)
            checkdied=true;
        if(key == "down")
            y = y+13;
        if(y < 13 )
            checkdied=true;

        ///middle part
        if(snake_y[0]==299 && snake_x[0]<=416 && snake_x[0]>=208)
            checkdied=true;
        if(snake_y[0]==91 && snake_x[0]<=234 && snake_x[0]>=208 )
            checkdied=true;
        if(snake_y[0]==91 && snake_x[0]<=416 && snake_x[0]>=390 )
            checkdied=true;
        if(snake_y[0]==78 && snake_x[0]<=234 && snake_x[0]>=195 )
            checkdied=true;
        if(snake_y[0]==78 && snake_x[0]<=429 && snake_x[0]>=390 )
            checkdied=true;
        if(snake_y[0]==312 && snake_x[0]<=429 && snake_x[0]>=195)
            checkdied=true;
        if(snake_x[0]==429 && snake_y[0]<=312 && snake_y[0]>=78 )
            checkdied=true;
        if(snake_x[0]==195 && snake_y[0]<=312 && snake_y[0]>=78 )
            checkdied=true;
        if(snake_x[0]==208 && snake_y[0]<=299 && snake_y[0]>=78 )
            checkdied=true;
        if(snake_x[0]==416 && snake_y[0]<=299 && snake_y[0]>=78 )
            checkdied=true;

        check();
        if(checkdied)
        {
            gameover();
            dead();
            return;
        }
        if(BONUS)
        {
            if(bonus>0)
                bonus-=10;
        }
        setcolor(BLACK);
        circle(snake_x[0],snake_y[0],8);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(snake_x[0],snake_y[0],BLACK);

        for(int _size = 1; _size < snake_size; _size++)
        {
            circle(snake_x[_size],snake_y[_size],5);
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(snake_x[_size],snake_y[_size],BLACK);
        }
    }
}
void stage3()
{
    clearviewport();

    freopen("GameData.dat","r",stdin);
    cin >> highscore;

    cleardevice();
    char ch;
    string key = "right";

    int maxx = getmaxx();
    int maxy = getmaxy()-50;    ///why this -50

    int x = 13,y = 13;

    int food_x = rand()%maxx,  food_y = rand()%maxy;
    int temp;
    temp = food_x%13;
    food_x-=temp;               ///why this minus
    temp = food_y%13;
    food_y-=temp;

    if(food_x < 13 || food_x > maxx - 13 || food_y < 13 || food_y > maxy - 13)
    {
        while(food_x < 13 || food_x > maxx - 13 || food_y < 13 || food_y > maxy - 13)
        {
            food_x = rand()%maxx,food_y = rand()%maxy;
            temp = food_x%13;
            food_x-=temp;
            temp = food_y%13;
            food_y-=temp;
        }
    }

    int i = 0;
    int bonus = 500;
    while(true)
    {
        clearviewport();
        if(score >0 && score%5==4)
            BONUS = true;
        else
        {
            bonus = 500;
            BONUS = false;
        }
        if(!BONUS || bonus == 0)
        {
            settextstyle(3,0,2);
            setcolor(BLACK);
            outtextxy(150,maxy+11,"THE BIG BITE AWAITS");
            setcolor(BLUE);    ///FOOD BORDER
            setfillstyle(SOLID_FILL,BLUE);
            circle(food_x,food_y,5);            ///x position, y position, size
            floodfill(food_x,food_y,BLUE);

        }
        else
        {
            setcolor(CYAN);
            setfillstyle(SOLID_FILL,CYAN);
            circle(food_x,food_y,10);
            floodfill(food_x,food_y,CYAN);

            char spp[1000];
            setcolor(BLACK);
            sprintf(spp,"THE BIG BITE AWAITS--%d",bonus);
            outtextxy(150,maxy+11,"THE BIG BITE AWAITS");
            setcolor(YELLOW);
            outtextxy(150,maxy+11,spp);
            // clears
        }

        setfillstyle(HATCH_FILL,RED);
        bar(0,0,10,425);///LEFT
        bar(10,0,631,10);///UP
        bar(621,10,631,425);///RIGHT
        bar(10,415,621,425);///DOWN
        setfillstyle(SOLID_FILL,YELLOW);

        setfillstyle(HATCH_FILL,RED);
        bar(0,0,10,425);///LEFT
        bar(10,0,631,10);///UP
        bar(621,10,631,425);///RIGHT
        bar(10,415,621,425);///DOWN
        ///left-up
        setfillstyle(SOLID_FILL,GREEN);
        bar(39,91,117,104);
        bar(117,91,104,39);
        ///right-up
        bar(585,39,507,52);
        bar(585,52,572,104);
        ///right-down
        bar(507,377,520,299);
        bar(520,299,585,312);
        ///left-down
        bar(39,299,52,377);
        bar(52,377,117,364);
        setfillstyle(SOLID_FILL,YELLOW);
        ///line-left
        bar(221,78,234,338);
        ///line-right
        bar(403,78,416,338);

        maxx = getmaxx();
        maxy = getmaxy()-50;

        if(kbhit())
        {
            ch = getch();
            if(ch == 0)
                ch = getch();
            if(ch == 72 && key != "down" )
                key = "up";
            if(ch == 80 && key != "up")
                key = "down";
            if(ch == 75 && key != "right")
                key = "left";
            if(ch == 77 && key != "left")
                key = "right";
            if(ch == 27) ///ESC=27
            {
                cleardevice();
                return;
            }
        }

        if(i < 5)
        {
            snake_x[i] = x-240;
            snake_y[i] = y-285;
            i++;
        }
        else
        {
            for(int _size = snake_size-2; _size >= 0; _size--)
            {
                snake_x[_size+1] = snake_x[_size];
                snake_y[_size+1] = snake_y[_size];
            }
            snake_x[0] = x;
            snake_y[0] = y;

            setcolor(RED);
            circle(snake_x[0],snake_y[0],8);
            setfillstyle(SOLID_FILL,RED);
            floodfill(snake_x[0],snake_y[0],RED);

            setcolor(WHITE);
            for(int _size = 1; _size < snake_size; _size++)
            {
                circle(snake_x[_size],snake_y[_size],5);
                setfillstyle(SOLID_FILL,WHITE);
                floodfill(snake_x[_size],snake_y[_size],WHITE);
            }
            char ara[100];
            sprintf(ara,"SCORE: %d",score);
            setcolor(WHITE);
            outtextxy(00,maxy+11,ara);
            sprintf(ara,"HIGHEST: %d",highscore);
            setcolor(WHITE);
            outtextxy(450,maxy+11,ara);

            delay(spd);
        }

        if(x == food_x && y== food_y)
        {
            bite++;
            if(bite==6 && flag==1)
                return;
            snake_size++;
            score++;
            /* Snake eats food*/
            if(score%5==0 && score>0)
                score+=bonus;


food:
            food_x = rand()%maxx,food_y = rand()%maxy;
            temp = food_x%13;
            food_x-=temp;
            temp = food_y%13;
            food_y-=temp;

            if(food_x < 13 || food_x > maxx - 13 || food_y < 13 || food_y > maxy - 13)
            {
                while(food_x < 13 || food_x > maxx - 13 || food_y < 13 || food_y > maxy - 13)
                {
                    food_x = rand()%maxx,food_y = rand()%maxy;
                    temp = food_x%13;
                    food_x-=temp;
                    temp = food_y%13;
                    food_y-=temp;
                }
            }
        }
        ///for food randomization out of border
        ///left-up
        if(food_x>=39 && food_x<=117 && food_y>=91 && food_y<=104)
            goto food;
        if(food_x>=104 && food_x<=117 && food_y>=39 && food_y<=91 )
            goto food;

///right-up
        if(food_x>=507 && food_x<=585 && food_y>=39 && food_y<=52)
            goto food;
        if(food_x>=572 && food_x<=585 && food_y>=52 && food_y<=104)
            goto food;

///right-down
        if(food_x>=507 && food_x<=585 && food_y>=299 && food_y<=312)
            goto food;
        if(food_x>=507 && food_x<=520 && food_y>=312 && food_y<=377)
            goto food;

///left-down
        if(food_x>=39 && food_x<=117 && food_y>=364 && food_y<=377)
            goto food;
        if(food_x>=39 && food_x<=52 && food_y>=299 && food_y<=364)
            goto food;

///left-line
        if(food_x>=221 && food_x<=234 && food_y>=78 && food_y<=338)
            goto food;

///right line
        if(food_x>=403 && food_x<=416 && food_y>=78 && food_y<=338)
            goto food;


        ///for border
        ///left-up
        if(snake_x[0]>=39 && snake_x[0]<=117 && snake_y[0]>=91 && snake_y[0]<=104)
            checkdied=true;
        if(snake_x[0]>=104 && snake_x[0]<=117 && snake_y[0]>=39 && snake_y[0]<=91 )
            checkdied=true;

///right-up
        if(snake_x[0]>=507 && snake_x[0]<=585 && snake_y[0]>=39 && snake_y[0]<=52)
            checkdied=true;
        if(snake_x[0]>=572 && snake_x[0]<=585 && snake_y[0]>=52 && snake_y[0]<=104)
            checkdied=true;

///right-down
        if(snake_x[0]>=507 && snake_x[0]<=585 && snake_y[0]>=299 && snake_y[0]<=312)
            checkdied=true;
        if(snake_x[0]>=507 && snake_x[0]<=520 && snake_y[0]>=312 && snake_y[0]<=377)
            checkdied=true;

///left-down
        if(snake_x[0]>=39 && snake_x[0]<=117 && snake_y[0]>=364 && snake_y[0]<=377)
            checkdied=true;

        if(snake_x[0]>=39 && snake_x[0]<=52 && snake_y[0]>=299 && snake_y[0]<=364)
            checkdied=true;

///left-line
        if(snake_x[0]>=221 && snake_x[0]<=234 && snake_y[0]>=78 && snake_y[0]<=338)
            checkdied=true;

///right line
        if(snake_x[0]>=403 && snake_x[0]<=416 && snake_y[0]>=78 && snake_y[0]<=338)
            checkdied=true;



        if(key == "right")
            x = x+13;
        if(x > maxx-13)
            checkdied=true;
        if(key == "left")
            x = x-13;
        if(x < 13)
            checkdied=true;
        if(key == "up")
            y = y-13;
        if(y > maxy-13)
            checkdied=true;
        if(key == "down")
            y = y+13;
        if(y < 13 )
            checkdied=true;
        check();
        if(checkdied)
        {
            gameover();
            dead();
            return;
        }
        if(BONUS)
        {
            if(bonus>0)
                bonus-=10;
        }
        setcolor(BLACK);
        circle(snake_x[0],snake_y[0],8);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(snake_x[0],snake_y[0],BLACK);

        for(int _size = 1; _size < snake_size; _size++)
        {
            circle(snake_x[_size],snake_y[_size],5);
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(snake_x[_size],snake_y[_size],BLACK);
        }
    }
}
void campaign()
{
    setcolor(YELLOW);

    clearviewport();
    stage1();
    if(bite==6)
        goto next;
    else
        return;
next:
    bite=0;

    clearviewport();
    while(!kbhit())
        outtextxy(200,160,"LEVEL UP");

    clearviewport();
    stage2();
    if(bite==6)
        goto next2;
    else
        return;
next2:
    bite=0;
    clearviewport();
    while(!kbhit())
        outtextxy(200,160,"LEVEL UP");

    clearviewport();
    stage3();
    if(bite==6)
        goto next3;
    else
        return;
next3:
    bite=0;
    clearviewport();
    while(!kbhit())
        outtextxy(200,160,"CONGRATULATIONS!!!");
    clearviewport();
    stage=0;
    flag=0;
    return;
}
void check()
{
    freopen("GameData.dat","w",stdout);
    if(highscore < score)
        cout << score << endl;
    else
        cout << highscore << endl;

    for(int i = 1; i < snake_size; i++)
    {
        if(snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i])
        {
            delay(1000);
            setcolor(WHITE);
            for(int i = 0; i < snake_size; i++)
            {
                circle(snake_x[i],snake_y[i],5);
                setfillstyle(SOLID_FILL,RED);
                floodfill(snake_x[i],snake_y[i],WHITE);
            }
            while(1)
            {
                if(kbhit())
                {
                    char ch = getch();
                    if(ch == 13)
                    {
                        checkdied = true;
                        return;
                    }
                }
            }
        }
    }
}
void gameover()
{
    setcolor(RED);
    settextstyle(3,0,5);
    clearviewport();
    outtextxy(180,160,"GAME OVER!!!");
    setcolor(CYAN);
    settextstyle(3,0,3);
    outtextxy(180,210,"Better Luck Next Time");

    setcolor(BLUE);
    settextstyle(3,0,3);
    char ara[100];
    sprintf(ara,"YOUR SCORE: %d",score);
    outtextxy(180,250,ara);

    char ch = getch();
    clearviewport();
    return;
}
void dead()
{
    clearviewport();
    checkdied = false;
    snake_size = 5;
    score = 0;
    die = 1;
    return;
}
void level()
{
    char ch;
    char ara[100];
    while(true)
    {

        int i = abs(spd/10.-10);
        sprintf(ara,"SPEED: %d",i);
        settextstyle(3,0,3);
        setcolor(WHITE);
        outtextxy(230,190,ara);
        setcolor(RED);
        settextstyle(3,0,1);
        outtextxy(130,250,"<USE UP AND DOWN ARROW KEY>");
        if(kbhit())
        {
            ch = getch();
            if(ch == 72)
            {
                spd-=10;
                if(spd < 0)
                    spd = 100;
            }
            else if(ch == 80)
            {
                spd+=10;
                if(spd > 100)
                    spd = 0;
            }
            else if(ch == 13)
                break;
            sprintf(ara,"SELECT LEVEL : %d",i);
            setcolor(BLACK);
            outtextxy(180,190,ara);
        }
    }
    clearviewport();
}
void high()
{
    freopen("GameData.dat","r",stdin);
    cin >> highscore;
    char ara[100];
    sprintf(ara,"Highscore: %d",highscore);
    setcolor(WHITE);
    outtextxy(200,350,ara);
    char ch = getch();
    clearviewport();
}

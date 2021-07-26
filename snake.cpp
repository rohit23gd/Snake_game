#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;

bool gameover;
const int width=30;
const int height =20;
int x,y,fx,fy,score;
int tailx[100],taily[100];
int ntail=0;
enum eDirection{STOP =0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void  setup(){
    gameover = false;
    dir =STOP;
    x = width/2;
    y = height/2;
    fx = rand() % (width-1);
    fy = rand() % (height-1);
    score =0;
}

void draw(){
    system("cls");
    for(int i=0 ;i<width+2;i++) printf("#");
    printf("\n");
    for(int i=0;i<height ;i++){
        for(int j=0;j<width; j++){

            if(j==0 ) printf("#");
            if(i==y && j==x) printf("O");
            else if(i==fy && j==fx) printf("@");
            else{
                    bool prnt = false;
                    for(int k=0;k<ntail ;k++){
                        if(tailx[k]==j && taily[k]==i){
                            cout<<"o";
                            prnt =true;
                            break;
                        }
                    }
                    if(!prnt)
                        printf(" ");
            }

            if(j==width-1)
                printf("#");
        }
        printf("\n");
    }
    for(int i=0 ;i<width+2;i++) printf("#");
    printf("\n");

    printf("\n\n");
    printf(">>>> Score = %d",score);
}
void input(){
     if(_kbhit()){
        switch(_getch()){
    case 'a':
        dir =LEFT;
        break;
    case 'd':
        dir =RIGHT;
        break;
    case 'w':
         dir =UP;
         break;
    case 's':
          dir = DOWN;
          break;
    case 'x':
        gameover=true;
        break;
        }
     }
}
void logic(){
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x ,prev2y;
    for(int i=1;i<ntail;i++){
        prev2x =tailx[i];
        prev2y =taily[i];
        tailx[i]= prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    tailx[0] =x;
    taily[0]=y;
    switch(dir){
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
         y--;
         break;
    case DOWN:
         y++;
          break;
    default:
        break;
    }
    if(x>width || x<0 || y>height || y<0) gameover =true;
    for(int h=0;h<ntail;h++){
        if(tailx[h]==x && taily[h]==y){
            gameover=true;
        }
    }
    if(x==fx && y==fy) {
        score ++;
        fx = rand() % (width-1);
        fy = rand() % (height-1);
        ntail++;
    }
}
int main(){

    setup();
    while(!gameover){
        draw();
        input();
        logic();
        Sleep(10);
    }
    return 0;
}

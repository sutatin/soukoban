#include <stdio.h>

    //
    //TODO
    //
    //bug
    //・clear when P on target
    //・vanish after o through
    //
    //function
    //・input figure
    //

    int y,x;
    enum nowField{normal,goal};
    enum nowField nowfieldType;
    int arrow;
    int isFinish=0;

//渡された配列のフィールドの描画
    void writeField(char witdh[7][9]){
     int i = 0;
     int k = 0;
     while (i < 7){
        while (k < 9){
            char field = witdh[i][k];
            printf("%c",field);
            if(field=='P'){
                y=i;
                x=k;
            }
            k++;            
        };
        k= 0;
        i++;
        printf("\n");
    };
};

void moveAction(char witdh[7][9],int y,int x,enum nowField e,int targetY, int targetX){

    char now = witdh[y][x];
    char target = witdh[targetY][targetX];
    char nowfield;

    if(e==normal){
        nowfield = ' ';
    }else{
        nowfield = '.';
    }

    if(target==' '){
        witdh[y][x] = nowfield;
        witdh[targetY][targetX] ='P';
        nowfieldType = normal;
    }else if(target == '.'){
        witdh[y][x] = nowfield;
        witdh[targetY][targetX] ='P';
        nowfieldType = goal;
    }else if(target == 'o'){
       int differenceX = targetX - x;
       int differenceY = targetY - y;


       //canpush?
       if(witdh[targetY+differenceY][targetX+differenceX]==' '
          ||witdh[targetY+differenceY][targetX+differenceX]=='.'){
       //上向きならdifferenceY:-1
       //下向きならdifferenceY:1
       //左向きならdifferenceY:-1
       //右向きならdifferenceY:1
        witdh[y][x] = nowfield;
        witdh[targetY][targetX] ='P';
        witdh[targetY+differenceY][targetX+differenceX]='o';
        nowfieldType = normal;
    }
    }
};

void checkFinish(char witdh[7][9]){
     int i = 0;
     int k = 0;
     isFinish = 1;

     while (i < 7){
        while (k < 9){
            char field = witdh[i][k];
            if(field=='.'){
                isFinish = 0;
            }
            k++;            
        };
        k= 0;
        i++;
    };

    if(isFinish==1){
        arrow = 6;
    }
}

void init(char witdh[7][9]){
    writeField(witdh);
    nowfieldType = normal;
}

int main(){

    start:  printf("\n");
    char witdh[7][9] = {
        { '0','1', '2', '3', '4', '5', '6', '7', '8' }
        , { '1','#', '#', '#', '#', '#', '#', '#', '#' }
        , { '2','#', ' ', '.', ' ', 'P', ' ', ' ', '#' }
        , { '3','#', ' ', 'o', 'o', ' ', ' ', ' ', '#' }
        , { '4','#', ' ', ' ', ' ', '.', ' ', ' ', '#' }
        , { '5','#', ' ', ' ', ' ', ' ', ' ', ' ', '#' }
        , { '6','#', '#', '#', '#', '#', '#', '#', '#' } };

        //初期処理
        init(witdh);

        while(arrow!=6){
        //input
            printf("\n");
            printf("移動コマンド　←：1　↑：2　↓：3　→：4　リセット：５　終了：６\n");
            scanf("%d",&arrow);
            printf("\n");

        //set targetXY from input
            int targetY,targetX;
            if(arrow==2){
                targetY = y-1;
                targetX = x;
            }else if(arrow==3){
                targetY = y+1;
                targetX = x;        
            }else if(arrow==1){
                targetY = y;
                targetX = x-1;        
            }else if(arrow==4){
                targetY = y;
                targetX = x+1;        
            }else if(arrow == 5){
                //リセット
                printf("リセットしました。\n");
                goto start;
            }else{
                targetY = y;
                targetX = x;                
            }

            moveAction(witdh,y,x,nowfieldType,targetY,targetX);
            writeField(witdh);
            checkFinish(witdh);

        }

        if(isFinish==1){
                printf("クリアおめでとう！\n");            
        }else{
                printf("終了します。\n");                        
        }

    };





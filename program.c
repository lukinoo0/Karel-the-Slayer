#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

void map(const int rows,const int columns,char map[rows][columns]){
    srand(time(NULL));
    int random;
    int i;
    int x;
    char text[]={"ITEMS:"};
    char house[7][5]={
        {' ',' ','!',' ',' '},
        {' ','|','_','|',' '},
        {'|',' ','O',' ','|'},
        {'|',' ','O',' ','|'},
        {'|','_','#','_','|'},
        {' ','.',' ','.',' '},
        {' ','.',' ','.',' '},

    };
    char lumberjackhouse[7][20]={
        {' ','_','_','_','_','_','_','_','|',' ','|','_','_','_',' ',' ',' ','@',' ',' '},
        {'/','_','_','_','_','_','_','_','_','_','_','_','_','_','\\',' ','@','@','@',' '},
        {' ','|','|','_','|',' ','_','_','_',' ','|','_','|','|',' ','@','@','@','@','@'},
        {' ','|','|','_','|',' ','|','#','|',' ','|','_','|','|',' ',' ','@','|','@',' '},
        {' ','|','_','_','_','_','|','#','|','_','_','_','_','|',' ',' ',' ','|',' ',' '},
        {' ',' ',' ',' ',' ',' ','.',' ','.',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' '},
        {' ',' ',' ',' ',' ',' ','.',' ','.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    };
    char mountain[9][35]={
        {' ',' ',' ','o',' ',' ',' ','/','\\','_',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ','/','\\','/',' ','\\',' ',' ',' ',' ',' ',' ','/','W',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','/','#','#','\\',' ',' ','\\',' ',' ',' ',' ','/',' ','/','\\',' ',' ',' ',' ','_',' ',' ',' ','/','X','\\',' ',' ',' ',' '},
        {' ',' ',' ','/','/','#','#','#','#','\\','-','-','\\',' ',' ','/',' ','/','%','(','\\',' ',' ','/',' ','\\',' ','/','#','#',' ','\\',' ',' ',' '},
        {' ',' ','/','/','.',' ','.',' ','.',' ','\\','/',' ','\\','/',' ','/','%','(',' ',' ','\\','/',' ','\\',' ','/','#','#','#',' ',' ','\\',' ',' '},
        {' ','/','/','.','/','%','/','\\','.','.','.','\\',' ',' ','\\','/','.','.','.','_',' ','.','\\',' ',' ','/','\\','.','.','.','.','.','/','\\',' '},
        {'/','.','.','\\','.','/','.','.','\\','.','.','.','\\','.','.','\\','-','-','/','#','\\','-','-','\\','/','.','.','\\','.','.','.','/','.','.','\\'},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.',' ','.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.',' ','.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    };
    //inicializovanie mapy
    for(i=0;i<rows;i++){
        for(x=0;x<columns;x++){
            map[i][x]=' ';
        }
    }
    for(i=0;i<strlen(text);i++){
        map[1][columns-7+i]=text[i];
    }
    for(i=1;i<8;i++){
        map[i][columns-8]='o';
    }
    for(i=columns-8;i<columns-1;i++){
        map[8][i]='o';
    }
    //radnica
    do{
        random=rand()%columns-6-7;
    }while(random<3);
    for(i=0;i<7;i++){
        for(x=0;x<5;x++){
            map[2+i][random+x]=house[i][x];
        }
    }
    //lumberjackhouse
    do{
        random=rand()%columns-20;
    }while(random<3);
    for(i=0;i<7;i++){
        for(x=0;x<20;x++){
            map[rows-26+i][random+x]=lumberjackhouse[i][x];
        }
    }
    //mountain
    do{
        random=rand()%columns-35;
    }while(random<3);
    for(i=0;i<9;i++){
        for(x=0;x<35;x++){
            map[rows-12+i][random+x]=mountain[i][x];
        }
    }

}

void cave(const int rows, const int columns, char map[rows][columns]){
    int i;
    int x;
    for(i=0;i<rows;i++){
        for(x=0;x<columns;x++){
            map[i][x]=' ';
        }
    }
    char mountain[7][16]={
        {' ',' ',' ',' ',' ',' ',' ','/','#','\\',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ','^',' ',' ','/','\\','/',' ','\\',' ',' ',' ',' ',' '},
        {' ',' ','^',' ',' ','/','#','#','\\',' ',' ','\\',' ',' ',' ',' '},
        {' ',' ',' ','/','/','#','#','#','#','\\','-','-','\\',' ',' ',' '},
        {' ',' ','/','/','.',' ','.',' ','.',' ','\\','/',' ','\\',' ',' '},
        {' ','/','/','.','/',' ','/','\\','.','.','.','\\',' ',' ','\\',' '},
        {'/','.','.','\\','.','/','.','.','\\','.','.','.','\\','.','.','\\'}        
    };
    char rock[4][10]={
        {' ',' ','_','_','-','\\','_',' ',' ',' '},
        {'|','/','_',' ',' ',' ',' ','&','\\',' '},
        {'\\',' ','|',' ','|',' ','/','_','/','\\'},
        {' ','-','/','_','|','-','_','/','\\','\\'}

    };
    char iron[2][3]={
        {' ','@',' '},
        {'@','%','@'}
    };
    int count=0;
    while(count!=39){
        for(i=0;i<4;i++){
            for(x=0;x<10;x++){
                map[i+2][count+x+2]=rock[i][x];
            }
        }
        count+=13;
    }
    count=0;
    while(count!=35){
        for(i=0;i<4;i++){
            for(x=0;x<10;x++){
                map[count+i+2][x+2]=rock[i][x];
            }
        }
        count+=7;        
    }
    count=0;
    while(count!=35){
        for(i=0;i<4;i++){
            for(x=0;x<10;x++){
                map[count+i+2][columns-12+x]=rock[i][x];
            }
        }
        count+=7;        
    }

    int count1=0;
    int count2=0;
    while(1){
        for(i=0;i<2;i++){
            for(x=0;x<+3;x++){
                map[count2+i+7][count1+x+14]=iron[i][x];
            }
        }
        count1+=9;
        if(count1==18){
            count2+=4;
            count1=0;
        }
        if(count2==24){
            break;
        }
    }
    for(i=0;i<7;i++){
        for(x=0;x<16;x++){
            map[rows-1-7+i][12+x]=mountain[i][x];
        }
    }   

    
}

void displaycave(const int rows, const int columns, char map[rows][columns]){
    int i;
    int x;
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    for(i=0;i<rows;i++){
        map[i][0]='|';
    }
    for(i=0;i<rows;i++){
        map[i][columns-1]='|';
    }
    for(i=0;i<columns;i++){
        map[0][i]='-';
    }
    for(i=0;i<columns;i++){
        map[rows-1][i]='-';
    }
    attroff(COLOR_PAIR(1));
    for(i=0;i<rows;i++){
        for(x=0;x<columns;x++){
            printw("%c ",map[i][x]);
        }
        printw("\n");
    }
}

void forest(const int rows, const int columns,char forest[rows][columns]){
    srand(time(NULL));
    int i;
    int x;
    char exit[7][36]={
        {' ',' ',' ',' ','@','@','@',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','@','@','o',' ',' ',' ',' ',' '},
    {' ',' ',' ','@','o','@','@','@','!','_','!','_','!','.',' ',' ',' ','.','!','_','!','_','!','_','!','_','!','@','o','|','@','/',' ',' ','/','o'},
    {' ',' ',' ',' ',' ','@','o','@','@','@','|','_','|','.',' ',' ',' ','.','|','_','|','_','|','_','|','@','\\','@','\\','@','o','@','@','/',' ',' '},
    {'@','o','@','\\','@','|','@','/','@','@','@',' ',' ',' ','.',' ','.',' ',' ',' ',' ',' ',' ',' ','@','o','@','\\','@','|','@','/','@','o','o',' '},
    {' ','@','@','@','\\','|','/','@','o','@',' ',' ',' ',' ','.',' ','.',' ',' ',' ',' ',' ',' ',' ',' ','o','@','@','\\','|','/','@','o','@',' ',' '},
    {' ',' ','@',' ','}','|','{',' ',' ','@',' ',' ',',','/','|','#','|','\\',',',' ',' ',' ',' ',' ',' ',' ','@',' ','}','|','{',' ','@','@',' ',' '},
    {' ',' ',' ',' ','}','|','{',' ',' ',' ',' ','{','/','_','|','#','|','_','\\','}',' ',' ',' ',' ',' ',' ',' ',' ','}','|','{',' ',' ',' ',' ',' '}
    };
    char tree[6][6]={
        {' ','@','@','@','@',' '},
        {'@','@','\\','@','@','@'},
        {'@','@','@','/','@','@'},
        {' ','@','&','@','@',' '},
        {' ',' ','|','|',' ',' '},
        {' ',' ','|','|',' ',' '}
    };
    char emptytree[6][6]={
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '}
    };
    for(i=0;i<rows;i++){
        for(x=0;x<columns;x++){
            forest[i][x]=' ';
        }
    }
    int err[5]={7,14,21,28,35};
    int emptyy[4];
    for(i=0;i<4;i++){
        emptyy[i]=rand()%5;
        while(emptyy[i]==0){
            emptyy[i]=rand()%5;
        }
    }
    while((emptyy[0]==emptyy[1])){
        emptyy[1]=rand()%5;
    }
    while((emptyy[1]==emptyy[2])){
        emptyy[2]=rand()%5;
    }
    while((emptyy[2]=emptyy[3])){
        emptyy[3]=rand()%5;
    }

    int empty[4];
    empty[0]=err[emptyy[0]];
    empty[1]=err[emptyy[1]];
    empty[2]=err[emptyy[2]];
    empty[3]=err[emptyy[3]];
    
    
    int count1=0;
    int count2=1;
    while(1){
        for(i=0;i<6;i++){
            for(x=0;x<6;x++){
                forest[count2+i][count1+x+3]=tree[i][x];
            }
        }
        count1+=7;
        if(count1==35){
            count2+=7;
            count1=0;
        }
        if(count2==29){
            break;
        }
    }
    int count=0;
    count1=0;
    count2=1;
    while(count!=4){
        for(i=0;i<6;i++){
            for(x=0;x<6;x++){
                forest[count2+i][empty[count]+x+3]=emptytree[i][x];
            }
        }
        count++;
        count1+=7;
        count2+=7;
        if(count1==35){
            count1=0;
        }
        if(count2==29){
            break;
        }
    }
    for(i=0;i<7;i++){
        for(x=0;x<36;x++){
            forest[rows-7+i][x]=exit[i][x];
        }
    }

}

void displayforest(const int rows, const int columns, char forest[rows][columns],char map[rows][columns]){
    int i;
    int x;
    
    for(i=0;i<rows;i++){
        forest[i][0]='|';
    }
    for(i=0;i<rows;i++){
        forest[i][columns-1]='|';
    }
    for(i=0;i<columns;i++){
        forest[0][i]='-';
    }
    for(i=0;i<columns;i++){
        forest[rows-1][i]='-';
    }

    for(i=0;i<rows;i++){
        for(x=0;x<columns;x++){
            printw("%c ",forest[i][x]);
        }
        printw("\n");
    }
    

}

void display(const int rows, const int columns, char map[rows][columns]){
    int i;
    int x;
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    for(i=0;i<rows;i++){
        map[i][0]='|';
    }
    for(i=0;i<rows;i++){
        map[i][columns-1]='|';
    }
    for(i=0;i<columns;i++){
        map[0][i]='-';
    }
    for(i=0;i<columns;i++){
        map[rows-1][i]='-';
    } 
    attroff(COLOR_PAIR(1));
    for(i=0;i<rows;i++){
        for(x=0;x<columns;x++){
            printw("%c ",map[i][x]);
        }
        printw("\n");
    }
    
}

void endgame(){
    FILE* inp; 
    inp = fopen("endgame.txt","r");
    char arr[17][54];			
    int i = 0; 
    while(1){ 
        char r = (char)fgetc(inp); 
        int k = 0; 
        while(r!=',' && !feof(inp)){	 
            arr[i][k++] = r;			 
            r = (char)fgetc(inp); 
        } 
        arr[i][k]='\0';		  
        if(feof(inp)){		
            break; 
        } 
        i++;

    }
    clear();
    fclose(inp);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    for (i=0; i <7; i++) {
        for (int x=0; x < 54; x++) {
            printw("%c ",arr[i][x]);
        }
        printw("\n");
    }
    printw("\n");
    attroff(COLOR_PAIR(1));
    for (i=8; i <17; i++) {
        for (int x=0; x < 54; x++) {
            printw("%c ",arr[i][x]);
        }
        printw("\n");
    }
    refresh();
}

void lost(){
    FILE* inp; 
    inp = fopen("lost.txt","r");
    char arr[16][54];			
    int i = 0; 
    while(1){ 
        char r = (char)fgetc(inp); 
        int k = 0; 
        while(r!=',' && !feof(inp)){	 
            arr[i][k++] = r;			 
            r = (char)fgetc(inp); 
        } 
        arr[i][k]='\0';		  
        if(feof(inp)){		
            break; 
        } 
        i++;

    }
    clear();
    fclose(inp);  
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    for (i=0; i <7; i++) {
        for (int x=0; x < 54; x++) {
            printw("%c ",arr[i][x]);
        }
        printw("\n");
    }
    printw("\n");
    attroff(COLOR_PAIR(1));
    for (i=8; i <16; i++) {
        for (int x=0; x < 54; x++) {
            printw("%c ",arr[i][x]);
        }
        printw("\n");
    }
    refresh();

}

void movement(const int rows,const int columns, char map[rows][columns]){
              char emptytree[6][6]={
            {' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' '}
        };
        int a;
        int b;
        int e;
        int d;
        int x;
        int y;
        int lastlevel=0;
        for(y=0;y<rows;y++){
            for(x=0;x<columns;x++){
                if(map[y][x]=='^'){
                    map[y][x]=' ';
                    map[y][x]=' ';
                    refresh();      
                }
            }
        }

        x=columns/2;
        y=(rows/2)+1;
        int c;
        char player='>';
        char clear=' ';
        int upgrade=0;
        int forestt=0;
        map[y][x]=player;
        int lives=7;
        do{ 
        lastlevel=0;
        c=getch();
        if(c == KEY_LEFT || c == KEY_RIGHT || c == KEY_UP || c == KEY_DOWN){
            map[y][x]=clear;
            refresh();
        }
        switch(c){
            case KEY_LEFT: player = '<';
                           if(map[y][x-1]==' '){
                                x--;
                           }
                           if(map[y][x-1]== '|'&&map[y][x-2]=='|'&&map[y][x-3]==' '){
                               map[y][x-1]=' ';
                               map[y][x-2]=' ';
                               for(e=0;e<rows;e++){
                                    for(d=0;d<columns;d++){
                                        if(map[e][d]=='&'&&map[e+1][d]!='|'&&map[e+2][d]!='|'){
                                            for(a=0;a<6;a++){
                                                for(b=0;b<6;b++){
                                                    map[e-3+a][d-2+b]=emptytree[a][b];
                                                }
                                            }   
                                        }
                                    }
                                }      
                           }   
                           if(map[y-2][x]=='X'||map[y+2][x]=='X'||map[y][x-2]=='X'||map[y][x+2]=='X'){
                               lives--;
                               mvprintw(rows+2,1,"L i v e s :  %d",lives);
                               refresh();
                           }                        
                           break;
            case KEY_RIGHT: player= '>';
                           if (map[y][x+1]== ' '){
                                x++;
                           }
                           if(map[y][x+1]== '|'&&map[y][x+2]=='|'&&map[y][x+3]==' '){
                               map[y][x+1]=' ';
                               map[y][x+2]=' ';
                               for(e=0;e<rows;e++){
                                    for(d=0;d<columns;d++){
                                        if(map[e][d]=='&'&&map[e+1][d]!='|'&&map[e+2][d]!='|'){
                                            for(a=0;a<6;a++){
                                                for(b=0;b<6;b++){
                                                    map[e-3+a][d-2+b]=emptytree[a][b];
                                                }
                                            }   
                                        }
                                    }
                                }      
                           }
                           if(map[y-2][x]=='X'||map[y+2][x]=='X'||map[y][x-2]=='X'||map[y][x+2]=='X'){
                               lives--;
                               mvprintw(rows+2,1,"L i v e s :  %d",lives);
                               refresh();
                           }
                           break;
            case KEY_UP: player = '^';
                           if (map[y-1][x]== ' '&&map[y-1][x]!='#'){
                                y--;
                           }
                           if (map[y-1][x]=='#'){
                                upgrade=1;
                                
                           }
                           if(map[y-1][x]=='X'){
                               lives--;
                           }
                           if(map[y-1][x]=='#'&&map[y-2][x]=='#'){
                                forestt=1;       
                           }
                           if(map[y-1][x]=='%'&&map[y-2][x]=='@'){
                               map[y-1][x]=' ';
                               map[y-2][x]=' ';
                               map[y-1][x-1]=' ';
                               map[y-1][x+1]=' ';
                           }
                           if(map[y-2][x]=='X'){
                               map[y-3][x]='&';
                               map[y-3][x-1]='&';
                               map[y-3][x+1]='&';
                               map[y-2][x-1]='&';
                               map[y-2][x+1]='&';
                               map[y-1][x+1]='&';
                               map[y-1][x-1]='&';
                               map[y-1][x]='&';
                           }
                           break;
            case KEY_DOWN: player = 'v';
                           if (map[y+1][x]== ' '){
                                y++;
                           }
                           if(map[y+1][x]=='#'){
                                forestt=1;       
                           }
                           if(map[y+1][x]=='X'){
                               lives--;
                           }
                           if(map[y+2][x]=='X'){
                               map[y+3][x]='&';
                               map[y+3][x-1]='&';
                               map[y+3][x+1]='&';
                               map[y+2][x-1]='&';
                               map[y+2][x+1]='&';
                               map[y+1][x+1]='&';
                               map[y+1][x-1]='&';
                               map[y+1][x]='&';
                           }
                           break;
            default: continue; break;               
        }

        map[y][x]=player;
        clear();
        display(rows,columns,map);
        init_pair(3,COLOR_YELLOW, COLOR_BLACK);
        attron(COLOR_PAIR(3));
        mvprintw(rows+2,1,"L i v e s :  %d",lives);
        for(int l=0;l<rows-1;l++){
            for(int k=0;k<columns-1;k++){
                if(map[l][k]=='X'){
                    lastlevel++;
                }
            }
        }
        if(lastlevel>3){
            mvprintw(rows+4,1,"H i n t: You can trap enemies by walking to them from behind or front.");
            mvprintw(rows+5,1,"         Do not get too close to them from left side or right because ");
            mvprintw(rows+6,1,"         you can lost live, when you lost all of them, you gonna die! ");
        }
        attroff(COLOR_PAIR(3));

        refresh();
    }while(c!='q'&&c!='Q'&&upgrade==0&&forestt==0&&lives!=0);
    map[y][x]=player;
    int lostend=0;
    if(player=='v'&&map[y+1][x]=='#'&&map[y+2][x]=='%'&&map[y+3][x]=='='){
        for(int m=0;m<rows-3;m++){
            for(int n=0;n<columns-1;n++){
                if(map[m][n]=='X'&&map[m][n-1]!='&'){
                    clear();
                    lost();
                    refresh();
                    lostend=1;
                    printw("Press Q to exit");
                    refresh();
                    int c;
                    while(c!='q'&&c!='Q'){
                        c=getch();
                    }
                }
            }
        }
        if(lostend==0){
                    clear();
                    endgame();
                    refresh();
                    printw("Press Q to exit");
                    refresh();
                    int c;
                    while(c!='q'&&c!='Q'){
                        c=getch();
                    }
        }
    }
    if(lives==0){
        clear();
        lost();
        refresh();
    }
}

void upgrade(const int rows,const int columns,const int wood, const int iron, char map[rows][columns],char forest[rows][columns]){
    char upgradewindow[rows][columns];
    int i;
    int x;
    char pickaxe[3][3]={
        {' ','_',' '},
        {'/','|','\\'},
        {' ','|',' '}
    };
    char sword[3][11]={      
        {' ',' ',' ','/',' ',' ',' ',' ',' ',' ',' '},
        {'@','x','x','[','{','=','=','=','=','=','>'},
        {' ',' ',' ','\\',' ',' ',' ',' ',' ',' ',' '}    
    };
    char sword1[3][6]={
        {' ','/',' ',' ',' ',' '},
        {'@','x','{','=','=','>'},
        {' ','\\',' ',' ',' ',' '}
    };
    for(i=0;i<rows-10;i++){
        printw(" ");
    }
    printw("I N V E N T O R Y\n");
    for(i=0;i<rows;i++){
        for(x=0;x<columns;x++){
            upgradewindow[i][x]=' ';
        }
    }
    for(i=0;i<rows;i++){
        upgradewindow[i][0]='|';
    }
    for(i=0;i<rows;i++){
        upgradewindow[i][columns-1]='|';
    }
    for(i=0;i<columns;i++){
        upgradewindow[0][i]='-';
    }
    for(i=0;i<columns;i++){
        upgradewindow[rows-1][i]='-';
    }
    //text
    char text1[]={"WOOD:"};
    char text2[]={"IRON:"};
    char text3[]={"Press [E] to leave the upgrading house"};
    char text4[]={"Things that you can craft:"};
    char text5[]={"1. Wooden pickaxe - PRESS[A]"};
    char text6[]={"2. Stone sword - PRESS[B]"};
    for(i=0;i<strlen(text1);i++){
        upgradewindow[2][i+2]=text1[i];
    }
    
    for(i=0;i<strlen(text2);i++){
        upgradewindow[4][i+2]=text2[i];
    }
    for(i=0;i<strlen(text3);i++){
        upgradewindow[rows-3][i+1]=text3[i];
    }
    for(i=1;i<columns-1;i++){
        upgradewindow[rows-5][i]='_';
    }
    for(i=1;i<columns-1;i++){
        upgradewindow[6][i]='_';
    }
    for(i=0;i<strlen(text4);i++){
        upgradewindow[9][i+6]=text4[i];
    }
    int bought1=0;
    int bought2=0;
    for(i=1;i<rows-1;i++){
        for(x=1;x<columns-1;x++){
            if(map[i][x]=='E'&&map[i+1][x]=='_'){
                bought1=1;
            }
            if(map[i][x]=='E'&&map[i+5][x]=='{'){
                bought2=1;
            }
        }
    }
    if(bought1==0){    
        for(i=0;i<3;i++){
            for(x=0;x<3;x++){
                upgradewindow[13+i][18+x]=pickaxe[i][x];
            }
        }    
        for(i=0;i<strlen(text5);i++){
            upgradewindow[11][i+5]=text5[i];
        }
    }
    if(bought2==0){
        for(i=0;i<3;i++){
            for(x=0;x<11;x++){
                upgradewindow[14+7+i][13+x]=sword[i][x];
            }
        }
        for(i=0;i<strlen(text6);i++){
            upgradewindow[18][i+6]=text6[i];
        }
    }
    attron(COLOR_PAIR(3));
    //vykreslenie okna
    for(i=0;i<rows;i++){
        for(x=0;x<columns;x++){
            
            if(i==2&&x==8){
                printw("%d",wood);

            }
            if(i==4&&x==8){
                printw("%d",iron);
            }
            else{
                printw("%c ",upgradewindow[i][x]);
            }
        }
        printw("\n");
    }
    attroff(COLOR_PAIR(3));
    refresh();
    int c;
    while(c!='e'&&c!='E'){
        c=getch();
        if((c=='a'||c=='A')&&bought1==0){
            if(wood>=10){
                for(i=0;i<3;i++){
                    for(x=0;x<3;x++){
                        map[2+i][columns-6+x]=pickaxe[i][x];
                    }
                }
                break;
            }
        }
        if((c=='b'||c=='B')&&bought2==0){
            if(wood>=10&&iron>=5){
                for(i=0;i<3;i++){
                    for(x=0;x<6;x++){
                        map[5+i][columns-7+x]=sword1[i][x];
                    }
                }
                break;
            }
        }
    }
    clear();
    display(rows,columns,map);
    refresh();
    
}
void welcome(){
    FILE* inp; 
    inp = fopen("welcome.txt","r");
    char arr[69][54];			
    int i = 0; 
    while(1){ 
        char r = (char)fgetc(inp); 
        int k = 0; 
        while(r!=',' && !feof(inp)){	 
            arr[i][k++] = r;			 
            r = (char)fgetc(inp); 
        } 
        arr[i][k]='\0';		  
        if(feof(inp)){		
            break; 
        } 
        i++;

    }
    fclose(inp);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    for (i=0; i <10; i++) {
        for (int x=0; x < 54; x++) {
            printw("%c ",arr[i][x]);
        }
        printw("\n");
    }
    attroff(COLOR_PAIR(1));
    printw("\n");
    for (i=11; i <15; i++) {
        for (int x=0; x < 54; x++) {
            printw("%c ",arr[i][x]);
        }
        printw("\n");
    }
    printw("\n");
    printw("Press E to continue");
    refresh();
    int c;
    while(c!='e'&&c!='E'){
        c=getch();
    }
    clear();
    for (i=16; i <26; i++) {
        for (int x=0; x < 54; x++) {
            printw("%c ",arr[i][x]);
        }
        printw("\n");
    }
    printw("\n");
    printw("Press E to continue");
    refresh();
    c=0;
    while(c!='e'&&c!='E'){
        c=getch();
    }
    clear();
    for (i=27; i <36; i++) {
        for (int x=0; x < 54; x++) {
            printw("%c ",arr[i][x]);
        }
        printw("\n");
    }
    printw("\n");
    printw("Press E to continue");
    refresh();
    c=0;
    while(c!='e'&&c!='E'){
        c=getch();
    }
    clear();
    for (i=37; i <49; i++) {
        for (int x=0; x < 54; x++) {
            printw("%c ",arr[i][x]);
        }
        printw("\n");
    }
    printw("\n");
    printw("Press E to continue");
    refresh();

    c=0;
    while(c!='e'&&c!='E'){
        c=getch();
    }
    clear();
    for (i=50; i <68; i++) {
        for (int x=0; x < 54; x++) {
            printw("%c ",arr[i][x]);
        }
        printw("\n");
    }
    refresh();

}

void finalmap1(const int rows, const int columns, char map[rows][columns]){
    srand(time(NULL));
    int r[5];
    int c[5];
    int i;
    int x;
    for(i=0;i<rows;i++){
        for(x=0;x<columns;x++){
            map[i][x]=' ';
        }
    }
    for(i=0;i<5;i++){
        do{
          r[i]=rand()%rows-10;      
        }while(r[i]<=2);
    }
    for(i=0;i<5;i++){
        do{
          c[i]=rand()%columns-2;      
        }while(c[i]<=2);
    }
    for(i=0;i<5;i++){
        map[r[i]][c[i]]='X';
    }
    char exit[4][7]={
    {' ',' ','/','#','\\',' ',' '},
    {' ','/',' ','%',' ','\\',' '},
    {'@','|',' ','=',' ','|','@'},
    {'E',' ','x',' ','I',' ','T'}
    };
    int random=0;
    do{
        random=rand()%columns-7-2;
    }while(random<3);
    for(i=0;i<4;i++){
        for(x=0;x<7;x++){
            map[rows-1-4+i][random+x]=exit[i][x];
        }
    }

    refresh();
}

void finalmap2(const int rows, const int columns, char map[rows][columns]){
    srand(time(NULL));
    int r[10];
    int c[10];
    int i;
    int x;
    for(i=0;i<rows;i++){
        for(x=0;x<columns;x++){
            map[i][x]=' ';
        }
    }
    for(i=0;i<10;i++){
        do{
          r[i]=rand()%rows-10;      
        }while(r[i]<=2);
    }
    for(i=0;i<10;i++){
        do{
          c[i]=rand()%columns-2;      
        }while(c[i]<=2);
    }
    for(i=0;i<10;i++){
        map[r[i]][c[i]]='X';
    }
    char exit[4][7]={
    {' ',' ','/','#','\\',' ',' '},
    {' ','/',' ','%',' ','\\',' '},
    {'@','|',' ','=',' ','|','@'},
    {'E',' ','x',' ','I',' ','T'}
    };
    int random=0;
    do{
        random=rand()%columns-7-2;
    }while(random<3);
    for(i=0;i<4;i++){
        for(x=0;x<7;x++){
            map[rows-1-4+i][random+x]=exit[i][x];
        }
    }

    refresh();
}

void finalmap3(const int rows, const int columns, char map[rows][columns]){
    srand(time(NULL));
    int r[15];
    int c[15];
    int i;
    int x;
    for(i=0;i<rows;i++){
        for(x=0;x<columns;x++){
            map[i][x]=' ';
        }
    }
    for(i=0;i<15;i++){
        do{
          r[i]=rand()%rows-10;      
        }while(r[i]<=2);
    }
    for(i=0;i<15;i++){
        do{
          c[i]=rand()%columns-2;      
        }while(c[i]<=2);
    }
    for(i=0;i<15;i++){
        map[r[i]][c[i]]='X';
    }
    char exit[4][7]={
    {' ',' ','/','#','\\',' ',' '},
    {' ','/',' ','%',' ','\\',' '},
    {'@','|',' ','=',' ','|','@'},
    {'E',' ','x',' ','I',' ','T'}
    };
    int random=0;
    do{
        random=rand()%columns-7-2;
    }while(random<3);
    for(i=0;i<4;i++){
        for(x=0;x<7;x++){
            map[rows-1-4+i][random+x]=exit[i][x];
        }
    }

    refresh();
}

void game(){
    keypad(initscr(),TRUE);
    curs_set(FALSE);
    nodelay(stdscr,TRUE);
    noecho();
     int first=0;
    int rows=40;
    int columns=40;
    char result[rows][columns];
    char forestresult[rows][columns];
    char caveresult[rows][columns];
    cave(rows,columns,caveresult);
    int wood=0;
    int iron=0;
    int i;
    int x;
    int bought1=0;
    int bought2=0;
    int countmax=0;
    int countmax1=0;
    int count=0;
    int count1=0;
    char finalresult1[rows][columns];
    finalmap1(rows,columns,finalresult1);

    char finalresult2[rows][columns];
    finalmap2(rows,columns,finalresult2);

    char finalresult3[rows][columns];
    finalmap3(rows,columns,finalresult3);

    char castle[15][23]={
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','T','~','~',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/','&','\\',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ','T','~','~',' ',' ',' ',' ',' ','|','.','|',' ','T','~','~',' ',' '},
        {' ',' ','T','~','~',' ','|',' ',' ',' ',' ','T','~',' ','W','W','W','W','|',' ',' ',' ',' '},
        {' ',' ','|',' ',' ','/','-','\\',' ',' ',' ','|',' ',' ','|',' ',' ','|','/','\\','T','~','~'},
        {' ','/','-','\\',' ','W','W','W',' ',' ','/','-','\\',' ','|','.',' ','|','W','W','|',' ',' '},
        {'W','W','W','W','W','/','\\','|',' ','/',' ',' ',' ','\\','|','.','/','\\','|','/','.','\\',' '},
        {'|',' ',' ',' ','/',' ',' ','\\','/',']','W','W','W','[','\\','/','_','_','\\','W','W','W','W'},
        {'|',' ',' ',' ','W','W','W','W',' ','|','I','_','I','|','.','W','W','W','W','.',' ',' ','|'},
        {'|',' ',' ',' ','|',' ',' ','|','/',' ',' ','-',' ',' ',' ','|',' ',' ','|',' ',' ',' ','|'},
        {'|',' ',' ',' ','|',' ',' ','|','{','F','I','N','A','L','}','|',' ',' ','|',' ',' ',' ','|'},
        {'|',' ',' ',' ','|',' ',' ','|',' ','|','[','_',']','|',' ','|',' ',' ','|','.',' ',' ','|'},
        {'|',' ',' ',' ','|',' ',' ','|','_','|','#','#','#','|',' ','|',' ',' ','|',' ',' ',' ','|'},
        {'.','-','-','-','.','-','-','.','-','/','_','#','_','\\','-','.','-','-','.','-','-','-','.'}
    };
    forest(rows,columns,forestresult);
    for(i=0;i<28;i++){
        for(x=1;x<columns-1;x++){
            if(forestresult[i][x]=='|'){
                countmax++;
            }
        }
    }  
    for(i=1;i<rows-1;i++){
        for(x=1;x<columns-1;x++){
            if(caveresult[i][x]=='%'){
                countmax1++;
            }
        }
    }  
    
    int difficulty=0;
    map(rows,columns,result);
    welcome();
    printw("\n");
    printw("\n");
    printw("P l e a s e  C h o o s e  t h e  d i f f i c u l y:\n");
    printw("\n");
    printw("E A S Y      [ P R E S S  (A) ]\n");
    printw("M E D I U M  [ P R E S S  (S) ]\n");
    printw("H A R D      [ P R E S S  (D) ]\n");
    printw("\n");
    refresh();
    int c;
    refresh();
    while(difficulty==0){
        c=getch();
        if(c=='A'||c=='a'){
            difficulty=1;
        }
        if(c=='S'||c=='s'){
            difficulty=2;
        }
        if(c=='D'||c=='d'){
            difficulty=3;
        }
    }

    while(bought2==0){    
        for(i=0;i<rows;i++){
            for(x=0;x<columns;x++){
                if(result[i][x]=='^'&&result[i-1][x]=='#'&&result[i-2][x]!='#'&&result[i-2][x]!='_'){
                    result[i][x]=' ';
                    clear();
                    upgrade(rows,columns,wood,iron,result,forestresult);
                    result[i][x]=' ';
                    refresh();                    
                }
            }
        }
        for(i=0;i<rows;i++){
            for(x=0;x<columns;x++){
                if(result[i][x]=='^'&&result[i-1][x]=='#'&&result[i-2][x]=='#'){
                    result[i][x]=' ';
                    clear();
                    displayforest(rows,columns,forestresult,result);
                    result[i][x]=' ';
                    refresh();
                    movement(rows,columns,forestresult);   
                }
            }
        }
        for(i=0;i<rows;i++){
            for(x=0;x<columns;x++){
                if(result[i][x]=='^'&&result[i-2][x]=='_'){
                    result[i][x]=' ';
                    clear();
                    displaycave(rows,columns,caveresult);
                    result[i][x]=' ';
                    refresh();
                    movement(rows,columns,caveresult);   
                }
            }
        }

        for(i=0;i<rows;i++){
            for(x=0;x<columns;x++){
                if(caveresult[i][x]=='v'&&caveresult[i+1][x]=='#'){
                    caveresult[i][x]=' ';
                    clear();
                    display(rows,columns,result);
                    caveresult[i][x]=' ';
                    refresh();
                                for(i=1;i<rows-1;i++){
                                    for(x=1;x<columns-1;x++){
                                        if(caveresult[i][x]=='%'){
                                            count1++;
                                        }
                                    }
                                } 
                            iron=(countmax1-count1);
                            count1=0;  
                }
            }
        }

        for(i=0;i<rows;i++){
            for(x=0;x<columns;x++){
                if(forestresult[i][x]=='v'&&forestresult[i+1][x]=='#'){
                    forestresult[i][x]=' ';
                    clear();
                    display(rows,columns,result);
                    forestresult[i][x]=' ';
                    refresh();
                            for(i=0;i<28;i++){
                                for(x=1;x<columns-1;x++){
                                    if(forestresult[i][x]=='|'){
                                        count++;
                                    } 
                                }
                            } 
                            wood=(countmax-count);
                            count=0;      
                }
            }
        }
        for(i=1;i<rows-1;i++){
            for(x=1;x<columns-1;x++){
                if(result[i][x]=='E'&&result[i+1][x]=='_'){
                    bought1=1;
                }
                if(result[i][x]=='E'&&result[i+5][x]=='{'){
                    bought2=1;
                }
            }
        }
        if(bought1==0){
            for(i=1;i<rows-1;i++){
                for(x=1;x<columns;x++){
                    if(result[i][x]=='#'&&result[i-1][x]=='_'&&result[i+1][x]==' '){
                        result[i+3][x]='=';
                        result[i+3][x-1]='=';
                        result[i+3][x+1]='=';
                    }
                }
            }
        }
       
        if(bought1==1&&first==0){
            wood=wood-10;
            first=1;
            for(i=1;i<rows-1;i++){
                for(x=1;x<columns;x++){
                    if(result[i][x]=='#'&&result[i-1][x]=='_'&&result[i+1][x]==' '){
                        result[i+3][x]=' ';
                        result[i+3][x-1]=' ';
                        result[i+3][x+1]=' ';
                    }
                }
            }

        }
        if(bought2==1){
            iron=iron-5;
            wood=wood-10;
            for(i=1;i<rows-8;i++){
                for(x=1;x<columns-9;x++){
                    result[i][x]=' ';
                }
            } 
            for(i=10;i<rows-1;i++){
                for(x=1;x<columns-1;x++){
                    result[i][x]=' ';
                }
            }
            for(i=0;i<15;i++){
                for(x=0;x<23;x++){
                    result[(rows/2)-1-15+i][(columns/2)-1-11+x]=castle[i][x];
                }
            }

            
        }
       
        clear();
        display(rows,columns,result);
        refresh();
        movement(rows,columns,result);
        clear(); 
    } 
        for(i=0;i<rows;i++){
            for(x=0;x<columns;x++){
                if(result[i][x]=='^'&&result[i-1][x]=='#'&&result[i-2][x]=='#'&&result[i-3][x]=='_'&&result[i-4][x]=='N'){
                    result[i][x]=' ';
                    clear();
                    if(difficulty==1){
                        display(rows,columns,finalresult1);
                    }
                    if(difficulty==2){
                        display(rows,columns,finalresult2);   
                    }
                    if(difficulty==3){
                        display(rows,columns,finalresult3);   
                    }                   
                        
                    result[i][x]=' ';
                    refresh();
                    if(difficulty==1){
                        movement(rows,columns,finalresult1);   
                    }
                    if(difficulty==2){
                        movement(rows,columns,finalresult2);      
                    }
                    if(difficulty==3){
                        movement(rows,columns,finalresult3);      
                    }  
                                     
                }
            }
        }
 
    getchar();
    endwin();

}
int main(){
    game();
}

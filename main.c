
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <stdbool.h>
#define MAX_SIZE 100
typedef struct
{
    char player1_name[MAX_SIZE];
    char player2_name[MAX_SIZE];
    int  player1_score;
    int  player2_score;
    int moves1;
    int moves2;
} player_inf;



void assign_arr( int row,int col,int game[row][col])
{
//nis number of sides 2 or 5
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            game[i][j]=32;
        }
    }
    for(i=0; i<row; i+=4)
    {
        for(j=0; j<col; j+=4)
        {
            game[i][j]=111;
        }
    }

}
void print_arr( int row,int col,int game[row][col],int color[][col])
{
    HANDLE hConSole=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConSole,&consoleInfo);
    WORD saved_attributes =consoleInfo.wAttributes;
    int ronu=1,conu=1,k=0;
    /*ronu numbers print on row
    conu number print on col*/
    printf("   ");
    for(int i=0; i<col; i+=2)
    {
        if(ronu>=10)
        {
            printf("%d      ",ronu);
        }
        else
        {
            printf("%d       ",ronu);
        }
        ronu++;
    }

    printf("\n\n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(i==k)
            {
                k+=2;
                if(conu>=10)
                {
                    printf("%d ",conu);
                }

                else
                {
                    printf("%d  ",conu);
                }
                conu++;
            }
            else
            {
                printf("   ");
            }
            if(color[i][j]==0)
            {
                SetConsoleTextAttribute(hConSole,FOREGROUND_BLUE);

                printf("%c",game[i][j]);
                SetConsoleTextAttribute(hConSole,saved_attributes);
            }
            else if(color[i][j]==1)
            {
                SetConsoleTextAttribute(hConSole,FOREGROUND_GREEN);
                printf("%c",game[i][j]);
                SetConsoleTextAttribute(hConSole,saved_attributes);
            }
            else
            {
                printf("%c",game[i][j]);
            }












        }
        printf("\n");
    }

}
void print_enter_face()
{
    HANDLE hConSole=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConSole,&consoleInfo);
    WORD saved_attributes =consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConSole,FOREGROUND_RED);
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t *           * *      **********     *  *     * *        *                 *     *\n");
    printf("\t\t\t *  *      *     *        **        *        *   *       *                  *   *                  **\n");
    printf("\t\t\t * * *    *       *       **         *        * *        *         * *       * *       * *        *\n");
    printf("\t\t\t * ** *   *       *       **           *      * *   *    **      *    *       *      *    *        *\n");
    printf("\t\t\t * *  *   *       *       **           *    *    * *     *  *    *    *      * *     * * *          *\n");
    printf("\t\t\t *   *     *     *        **           *    *     *      *  *    *    *     *   *     *             *\n");
    printf("\t\t\t * *         * *          **       * *       *  *   *    ***      * *      *     *      * *      **\n");

    SetConsoleTextAttribute(hConSole,saved_attributes);
    SetConsoleTextAttribute(hConSole,FOREGROUND_BLUE);
    printf("\t\t\t");
    for(int i=0; i<101; i++)
    {
        printf("%c",196);
    }

    SetConsoleTextAttribute(hConSole,saved_attributes);



}
void check_occurance(int col,int *row_index,int *col_index,int game[][col],int num,int turn,int n,int l)
{
    int x,y;
    int iRandom,jRandom;
    int g;
    if(n==2)
    {
        g=5;
    }
    else if(n==5)
    {
        g=11;
    }
    srand(time(0));
    /*x indicate row of the arr y indicate col of the arr*/
    if(num==2)
    {
        y=(*col_index-1)*2;
        x=(*row_index-1)*2;
        while(game[x][y]==111||game[x][y]==196||game[x][y]==124||(*col_index%2==0&&*row_index%2==0)||*col_index==0||*row_index==0||*row_index>g||*col_index>g)
        {
            printf("\t\tInvalid\n");
            printf("Enter Row:");
            scanf("%d",&*row_index);
            printf("Enter Column:");
            scanf("%d",&*col_index);
            printf("\n");
            y=(*col_index-1)*2;
            x=(*row_index-1)*2;
        }
    }
    else if(num==1)
    {
        y=(*col_index-1)*2;
        x=(*row_index-1)*2;
        while(game[x][y]==111||game[x][y]==196||game[x][y]==124||(*col_index%2==0&&*row_index%2==0)||*col_index==0||*row_index==0||*row_index>g||*col_index>g)
        {
            if(turn==0)
            {
                printf("\t\tInvalid\n");
                printf("Enter Row:");
                scanf("%d",&*row_index);
                printf("Enter Column:");
                scanf("%d",&*col_index);
                printf("\n");
                y=(*col_index-1)*2;
                x=(*row_index-1)*2;
            }
            else if (turn==1)
            {

                iRandom=rand()%l+1;
                jRandom =rand()%l+1;
                *row_index=iRandom;
                *col_index=jRandom;
                y=(*col_index-1)*2;
                x=(*row_index-1)*2;
            }
        }
    }
}
int players()
{
    int num;
    scanf("%d",&num);
    //if num invalid
    return num;
}
void place_line(int col,int row_index,int col_index,int game[][col],int color[][col],int turn )
{
    int x,y;
    /*x indicate row of the arr y indicate col of the arr*/
    y=(col_index-1)*2;
    x=(row_index-1)*2;

    if(row_index%2==0)
    {
        x-=1;
        for(int i=0; i<3; i++,x++)
        {
            game[x][y]=124;
            if(turn==0)
            {
                color[x][y]=0;
            }
            else
            {
                color[x][y]=1;
            }
        }
    }
    else
    {
        y-=1;
        for(int i=0; i<3; i++,y++)
        {
            game[x][y]=196;
            if(turn==0)
            {
                color[x][y]=0;
            }
            else
            {
                color[x][y]=1;
            }
        }
    }



}

int check_box(int col,int n,int turn,int game[][col],int color[][col])
{

    int i,j,score=0;
    for(i=2; i<col; i+=4)
    {
        for(j=2; j<col; j+=4)
        {
            if(game[i][j+2]!=32&&game[i][j-2]!=32&&game[i+2][j]!=32&&game[i-2][j]!=32&&game[i][j]==32)
            {
                score++;
                if(turn==0)
                {
                    color[i][j]=0;
                    game[i][j]=65;
                }
                else
                {
                    color[i][j]=1;
                    game[i][j]=66;
                }

            }
        }
    }

    return score ;
}


int check_box_redo(int col,int n,int turn,int game[][col],int color[][col])
{

    int i,j,score=0;
    for(i=2; i<col; i+=4)
    {
        for(j=2; j<col; j+=4)
        {
            if(game[i][j+2]!=32&&game[i][j-2]!=32&&game[i+2][j]!=32&&game[i-2][j]!=32&&game[i][j]==32)
            {
                score++;
                if(turn==0)
                {
                    color[i][j]=1;
                    game[i][j]=66;
                }
                else
                {
                    color[i][j]=0;
                    game[i][j]=65;
                }

            }
        }
    }

    return score ;
}


int start()
{
    int n;
    print_enter_face();
    printf("\n\n\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t*******Main Menu*******\n");
    printf("\t\t\t\t\t\t\t\t\t1-Start game\n\t\t\t\t\t\t\t\t\t2-Load game\n\t\t\t\t\t\t\t\t\t3-Show the Top 10\n\t\t\t\t\t\t\t\t\t4-Exit\n");
    int operation;
    scanf("%d",&operation);
    //we will remember to test if user press wrong input
    system("cls");
    switch (operation)
    {
    case 1:
        printf("\n\n\n\t\t\t\t\t\t\t\t\tChoose Difficulty:\n");
        printf("\t\t\t\t\t\t\t\t\t1-Beginner\n\t\t\t\t\t\t\t\t\t2-Expert\n");
        /*computer vs human or human vs human */
        int difficulty;
        scanf("%d",&difficulty);
        system("cls");
        if(difficulty==1)
        {
            printf("\n\n\n\t\t\t\t\t\t\t\t\tchoose number of players:\n");
            printf("\t\t\t\t\t\t\t\t\t1-1 player\n\t\t\t\t\t\t\t\t\t2-2 players\n");
            n=2;
        }
        else if(difficulty==2)
        {
            printf("\n\n\n\t\t\t\t\t\t\t\t\tchoose number of players:\n");
            printf("\t\t\t\t\t\t\t\t\t1-1 player\n\t\t\t\t\t\t\t\t\t2-2 players\n");
            n=5;
        }
        else {}


        break;
    case 2:
        break;

    case 3:
        break;

    case 4:
        break;
    default:
        break;

    }
    return n ;


}
void player_print(player_inf vs)
{
    HANDLE hConSole=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConSole,&consoleInfo);
    WORD saved_attributes =consoleInfo.wAttributes;
    printf("\n\t\tPlayer's Names");
    SetConsoleTextAttribute(hConSole,FOREGROUND_BLUE);
    printf("\t%s\t",vs.player1_name);
    SetConsoleTextAttribute(hConSole,saved_attributes);
    SetConsoleTextAttribute(hConSole,FOREGROUND_GREEN);
    printf("%s\n",vs.player2_name);
    SetConsoleTextAttribute(hConSole,saved_attributes);
    printf("\t\tPlayer's Score");
    SetConsoleTextAttribute(hConSole,FOREGROUND_BLUE);
    printf("\t%d\t",vs.player1_score);
    SetConsoleTextAttribute(hConSole,saved_attributes);
    SetConsoleTextAttribute(hConSole,FOREGROUND_GREEN);
    printf("%d\n",vs.player2_score);
    SetConsoleTextAttribute(hConSole,saved_attributes);
    printf("\t\tPlayer's moves");
    SetConsoleTextAttribute(hConSole,FOREGROUND_BLUE);
    printf("\t%d\t",vs.moves1);
    SetConsoleTextAttribute(hConSole,saved_attributes);
    SetConsoleTextAttribute(hConSole,FOREGROUND_GREEN);
    printf("%d\t\n",vs.moves2);
    SetConsoleTextAttribute(hConSole,saved_attributes);
}
bool back_letter(int col,int n,int turn,int game[][col],int color[][col])
{

    int i,j;
    for(i=2; i<col; i+=4)
    {
        for(j=2; j<col; j+=4)
        {
            if((game[i][j+2]==32&&game[i][j-2]!=32&&game[i+2][j]!=32&&game[i-2][j]!=32&&game[i][j]!=32)||
                    (game[i][j+2]!=32&&game[i][j-2]==32&&game[i+2][j]!=32&&game[i-2][j]!=32&&game[i][j]!=32)||
                    (game[i][j+2]!=32&&game[i][j-2]!=32&&game[i+2][j]==32&&game[i-2][j]!=32&&game[i][j]!=32)||
                    (game[i][j+2]!=32&&game[i][j-2]!=32&&game[i+2][j]!=32&&game[i-2][j]==32&&game[i][j]!=32))
            {
                if(turn==0)
                {
                    color[i][j]=0;
                    game[i][j]=32;
                    return true;
                }
                else
                {
                    color[i][j]=1;
                    game[i][j]=32;
                    return true;
                }

            }
        }
    }
    return false;
}

void undo(int col,int row_index,int col_index,int game[][col],int color[][col],int turn)
{
    int x,y;
    y=(col_index-1)*2;
    x=(row_index-1)*2;

    if(row_index%2==0)
    {
        x-=1;
        for(int i=0; i<3; i++,x++)
        {
            game[x][y]=' ';
        }
    }
    else
    {
        y-=1;
        for(int i=0; i<3; i++,y++)
        {
            game[x][y]=' ';
        }
    }
}

void turn(int n,int row,int col,int game[][col],int num,int color[][col])
{
    int l;
    int r;
    int undo_counter=0;
    int op;
    int end_loop=n*(n+1)*2;
    int row_index,col_index;
    int k,turn;
    int check;
    print_arr(row,col,game,color);
    printf("\n\n\n");
    player_inf h_vs_h;
    player_inf h_vs_c =
    {
        .player2_name = "Computer\0"
    };
    h_vs_h.player1_score=0;
    h_vs_h.player2_score=0;
    h_vs_c.player1_score=0;
    h_vs_c.player2_score=0;
    h_vs_h.moves1=0;
    h_vs_h.moves2=0;
    h_vs_c.moves1=0;
    h_vs_c.moves2=0;
    int total_moves_left=end_loop;

    if(num==2)
    {
        printf("Enter Player First Name  : ");
        scanf("%s",h_vs_h.player1_name);
        printf("\nEnter Player Second Name : ");
        scanf("%s",h_vs_h.player2_name);
        system("cls");
        print_arr(row,col,game,color);
        printf("Total moves left = %d",total_moves_left);
        printf("\n\t\t\t\t\t\t\t\t\t\tM:Main Menu\n\t\t\t\t\t\t\t\t\t\tS:Save\n\t\t\t\t\t\t\t\t\t\te:Exit");
        player_print(h_vs_h);

        for(k=0; k<end_loop; k++)
        {
            if((k%2)==0)
            {
                h_vs_h.moves1++;
                turn=0;
                printf("\t\t%c %s Turn %c\n",186,h_vs_h.player1_name,186);

                /*chech succes i++*/
            }
            else
            {
                h_vs_h.moves2++;
                turn=1;

                printf("\t\t%c %s Turn %c\n",186,h_vs_h.player2_name,186);

            }
            //fuction to check and to print line
            printf("\t\tEnter Row:");
            scanf("%d",&row_index);
            printf("\t\tEnter Column:");
            scanf("%d",&col_index);
            printf("\n");
            check_occurance(col,&row_index,&col_index,game,num,turn,n,l);
            check_box(col,n,turn,game,color);
            place_line(col,row_index,col_index,game,color,turn);
            system("cls");
            check=check_box(col,n,turn,game,color);
            if(check!=0)
            {
                if(turn==0)
                {
                    h_vs_h.player1_score+=check;
                }
                else
                {
                    h_vs_h.player2_score+=check;
                }
                k++,end_loop++;
            }
            total_moves_left--;
            print_arr(row,col,game,color);
            printf("Total moves left = %d",total_moves_left);
            printf("\t\t\t\t\t\t\t\tM:Main Menu\n\t\t\t\t\t\t\t\t\t\tS:Save\n\t\t\t\t\t\t\t\t\t\te:Exit");
            player_print(h_vs_h);
            printf("\t\t\t\t\n\n\n1:Undo or 2:Continue\n");
                scanf("%d",&op);
         while(op==1)
            {
            if(undo_counter==0)
            {
                undo(col,row_index,col_index,game,color,turn);
                while (back_letter(col,n,turn,game,color))
                {
                    if(turn==0)
                    {
                        h_vs_h.player1_score--;
                    }
                    else if (turn==1)
                    {
                        h_vs_h.player2_score--;
                    }
                }
                 total_moves_left++;
                 if(turn==0)
                 {
                     h_vs_h.moves1--;
                 }
                 else if(turn==1)
                 {
                     h_vs_h.moves2--;
                 }
                 system("cls");
                 print_arr(row,col,game,color);
                printf("Total moves left = %d",total_moves_left);
                printf("\n\t\t\t\t\t\t\t\t\t\tM:Main Menu\n\t\t\t\t\t\t\t\t\t\tS:Save\n\t\t\t\t\t\t\t\t\t\te:Exit");
                player_print(h_vs_h);
                printf("\n\n");
                 printf("\t\t\t\t\n1:Redo or 2:Continue\n");
                 scanf("%d",&r);
                 if(r==1)
                 {
                     place_line(col,row_index,col_index,game,color,turn);
                     if(turn==0){turn=1;}
                     else if(turn==1){turn=0;}
                    total_moves_left--;
                     if(turn==0)
                     {
                        h_vs_h.moves2++;
                     }
                     else if(turn==1)
                     {
                          h_vs_h.moves1++;
                     }
                     check_box_redo(col,n,turn,game,color);
                    if(check!=0)
                    {
                        if(turn==0)
                        {
                            h_vs_h.player2_score+=check;
                        }
                        else
                        {
                            h_vs_h.player1_score+=check;
                        }
                        k++,end_loop++;
                    }
                     if(check!=0)
                    {
                        k++,end_loop++;
                    }
                    system("cls");
                    print_arr(row,col,game,color);
                    printf("\t\t\t\t\t\t\t\tM:Main Menu\n\t\t\t\t\t\t\t\t\t\tS:Save\n\t\t\t\t\t\t\t\t\t\te:Exit");
                    printf("Total moves left = %d",total_moves_left);
                     break;
                 }
                 system("cls");
                 print_arr(row,col,game,color);
                printf("Total moves left = %d",total_moves_left);
                printf("\n\t\t\t\t\t\t\t\t\t\tM:Main Menu\n\t\t\t\t\t\t\t\t\t\tS:Save\n\t\t\t\t\t\t\t\t\t\te:Exit");
                player_print(h_vs_h);
                printf("\n\n");
                     if(turn==0)
                     {
                        h_vs_h.moves1++;
                        printf("\t\t%c %s Turn %c\n",186,h_vs_h.player1_name,186);
                     }
                     else if(turn==1)
                     {
                          h_vs_h.moves2++;
                          printf("\t\t%c %s Turn %c\n",186,h_vs_h.player2_name,186);
                     }
                     if(check!=0)
                    {
                        k++,end_loop++;
                    }
                    printf("\t\tEnter Row:");
                    scanf("%d",&row_index);
                    printf("\t\tEnter Column:");
                    scanf("%d",&col_index);
                    printf("\n");
                    check_occurance(col,&row_index,&col_index,game,num,turn,n,l);
                    check_box(col,n,turn,game,color);
                    place_line(col,row_index,col_index,game,color,turn);
                    check=check_box(col,n,turn,game,color);
                    if(check!=0)
                    {
                        if(turn==0)
                        {
                            h_vs_h.player1_score+=check;
                        }
                        else
                        {
                            h_vs_h.player2_score+=check;
                        }
                        k++,end_loop++;
                    }
                     total_moves_left--;
                     system("cls");
                     print_arr(row,col,game,color);
                     printf("Total moves left = %d",total_moves_left);
                     player_print(h_vs_h);
                     undo_counter==1;
            }
            op++;
        }
        system("cls");
        print_arr(row,col,game,color);
        printf("Total moves left = %d",total_moves_left);
        printf("\n\t\t\t\t\t\t\t\t\t\tM:Main Menu\n\t\t\t\t\t\t\t\t\t\tS:Save\n\t\t\t\t\t\t\t\t\t\te:Exit");
        player_print(h_vs_h);
        printf("\n\n");

    }
}
else if (num==1)
{
    int iRandom;
    int jRandom;
    if(n==2)
        l=6;
    else if(n==5)
        l=12;


    printf("Enter Player First Name  : ");
    scanf("%s",h_vs_c.player1_name);
    system("cls");
    print_arr(row,col,game,color);
    printf("Total moves left = %d",total_moves_left);
    printf("\t\t\t\t\t\t\t\tM:Main Menu\n\t\t\t\t\t\t\t\t\t\tS:Save\n\t\t\t\t\t\t\t\t\t\te:Exit");
    player_print(h_vs_c);
    for(k=0; k<end_loop; k++)
    {

        if((k%2)==0)
        {
            h_vs_c.moves1++;
            turn=0;
            printf("\n\n\n\t\t%c %s Turn %c\n",186,h_vs_c.player1_name,186);

            /*chech succes i++*/
        }
        else if((k%2)==1)
        {
            h_vs_c.moves2++;
            turn=1;

            printf("\n\n\n\t\t%c %s Turn %c\n",186,h_vs_c.player2_name,186);
        }
        //fuction to check and to print line
        if(turn==0)
        {
            printf("\t\tEnter Row:");
            scanf("%d",&row_index);
            printf("\t\tEnter Column:");
            scanf("%d",&col_index);
            printf("\n");
        }
        else  if(turn==1)
        {
            srand(time(0));
            iRandom=rand()%l+1, jRandom =rand()%l+1 ;
            row_index=iRandom;
            col_index=jRandom;
        }
        check_occurance(col,&row_index,&col_index,game,num, turn,n,l);
        check_box(col,n,turn,game,color);
        place_line(col,row_index,col_index,game,color,turn);
        if(turn==1)
        {
            system("pause");
        }
        system("cls");
        int check;
        check=check_box(col,n,turn,game,color);
        if(check!=0)
        {
            if(turn==0)
            {
                h_vs_c.player1_score+=check;
            }
            else
            {
                h_vs_c.player2_score+=check;
            }
            k++,end_loop++;
        }
        total_moves_left--;

        print_arr(row,col,game,color);
        printf("Total moves left = %d",total_moves_left);
        printf("\t\t\t\t\t\t\t\tM:Main Menu\n\t\t\t\t\t\t\t\t\t\tS:Save\n\t\t\t\t\t\t\t\t\t\te:Exit");
        player_print(h_vs_c);
        printf("\n\n");
        if(turn==0)
        {
           printf("\t\t\t\t\n\n1:Undo or 2:Continue\n");
                scanf("%d",&op);
               while(op==1)
            {
            if(undo_counter==0)
            {
                undo(col,row_index,col_index,game,color,turn);
                while (back_letter(col,n,turn,game,color))
                {
                        h_vs_c.player1_score--;
                }
                 total_moves_left++;
                     h_vs_c.moves1--;
                 system("cls");
                 print_arr(row,col,game,color);
                 printf("Total moves left = %d",total_moves_left);
                 printf("\t\t\t\t\t\t\t\tM:Main Menu\n\t\t\t\t\t\t\t\t\t\tS:Save\n\t\t\t\t\t\t\t\t\t\te:Exit");
                 player_print(h_vs_c);
                 printf("\t\t\t\t\n\n\n\n\n\n1:Redo or 2:Continue\n");
                 scanf("%d",&r);
                 if(r==1)
                 {
                     place_line(col,row_index,col_index,game,color,turn);
                     turn=1;
                     total_moves_left--;
                    h_vs_c.moves1++;
                     check_box_redo(col,n,turn,game,color);
                    if(check!=0)
                    {
                            h_vs_c.player1_score+=check;
                        k++,end_loop++;
                    }
                     if(check!=0)
                    {
                        k++,end_loop++;
                    }
                    system("cls");
                    print_arr(row,col,game,color);
                    printf("Total moves left = %d",total_moves_left);
                    printf("\t\t\t\t\t\t\t\tM:Main Menu\n\t\t\t\t\t\t\t\t\t\tS:Save\n\t\t\t\t\t\t\t\t\t\te:Exit");
                    player_print(h_vs_c);
                     break;
                 }
                 system("cls");
                 print_arr(row,col,game,color);
                 printf("Total moves left = %d",total_moves_left);
                 printf("\t\t\t\t\t\t\t\tM:Main Menu\n\t\t\t\t\t\t\t\t\t\tS:Save\n\t\t\t\t\t\t\t\t\t\te:Exit");
                 player_print(h_vs_c);
                        h_vs_c.moves1++;
                        printf("\t\t%c %s Turn %c\n",186,h_vs_c.player1_name,186);
                     if(check!=0)
                    {
                        k++,end_loop++;
                    }
                    printf("\t\tEnter Row:");
                    scanf("%d",&row_index);
                    printf("\t\tEnter Column:");
                    scanf("%d",&col_index);
                    printf("\n");
                    check_occurance(col,&row_index,&col_index,game,num,turn,n,l);
                    check_box(col,n,turn,game,color);
                    place_line(col,row_index,col_index,game,color,turn);
                    check=check_box(col,n,turn,game,color);
                    if(check!=0)
                    {
                        h_vs_c.player1_score+=check;
                        k++,end_loop++;
                    }
                     total_moves_left--;
                     system("cls");
                     print_arr(row,col,game,color);
                     printf("Total moves left = %d",total_moves_left);
                     player_print(h_vs_c);
                     undo_counter==1;
            }
            op++;
        }
           }
        }

    }
}


int main()
{
    int col,row,n;
    int num;

    n=start();
    num=players();
    system("cls");
    col=n+n*3+1,row=n+n*3+1;
    int game[row][col],color[row][col];
    for(int i=0; i<col; i++)
    {
        for(int j=0; j<row; j++)
        {
            color[i][j]=2;
        }
    }
    /* 5 as i have 5 - bet two horizontal points
    3 as i have 3 | bet two vertical points*/
    assign_arr(row,col,game);
    turn(n,row,col,game,num,color);
    return 0;
}

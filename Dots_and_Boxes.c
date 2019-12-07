

#include <stdio.h>
#include<conio.h>
# include <math.h>//has math functions; exp(x,y)
# include <stdlib.h>//defines rand()
# include <string.h>//
# include <time.h>//defines time()
void start();
void print_array_game();
void choose_line();
void print_array_matrix();
char game [5] [5]= {'.',' ','.',' ','.',' ',' ',' ',' ',' ','.',' ','.',' ','.',' ',' ',' ',' ',' ','.',' ','.',' ','.'};
char matrix [5] [5]= {'.','1','.','2','.','8',' ','A',' ','3','.','B','.','D','.','7',' ','C',' ','4','.','6','.','5','.'};
char line;
int color1=-1,color2=0;

int main()
{
    char operation;
    printf("Dots and Boxes\n");
    printf("Main Menu\n");
    printf("To start anew game press \'s\'\nTo load a game press \'l\'\nTo show the Top 10 press \'t\'\nTo exit the game press \'e\'\n");
    scanf("%s",&operation);
    //we will remember to test if user press wrong input
    system("cls");
    switch (operation)
    {
    case 's':
        start();
        break;
    case 'l':
        break;

    case 't':
        break;

    case 'e':
        break;
    default:
        break;
    }

    return 0;


}
void start()
{
    char difficulty;
    printf("Difficulty : Beginner Or Expert\n");
    printf("To choose Beginner press b\nTo choose expert press x\n");
    scanf("%s",&difficulty);
    system("cls");
    printf("Choose 1 player or 2 player\n");
     int player;
        scanf("%d",&player);
    system("cls");
    if(difficulty=='b')
    {
        //guid1 matrix

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%c  ", matrix [i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
        if(player==1)
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    printf("%c  ", game [i][j]);
                }
                printf("\n");
            }
        }
        else if (player==2)
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    printf("%c  ", game [i][j]);
                }
                printf("\n");
            }
            choose_line();
        }
    }
    else if (difficulty=='x')
    {

        printf("Choose 1 player or 2 player\n");
        int player;
        scanf("%d",&player);
    }
}
void print_array_game()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c  ", game [i][j]);
        }
        printf("\n");
    }
}
    void print_array_matrix()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c  ", matrix [i][j]);
        }
        printf("\n");
    }
}
void choose_line()//12 is the number of moves,cases for choosing place of the move
{
    int i=0;
    while(i<=12)
    {
        scanf("%s",&line);
        switch (line)
        {
        case '1' :
            system("cls");
            game[0][1]=196;
            print_array_matrix();
            printf("\n\n");
            print_array_game();
            i++;
            break;
        case '2':
            system("cls");
            game[0][3]=196;
            print_array_matrix();
            printf("\n\n");
            print_array_game();
            i++;
            break;
        case '3':
            system("cls");
            game[1][4]='|';
            print_array_matrix();
            printf("\n\n");
            print_array_game();
            i++;
            break;
        case '4':
            system("cls");
            game[3][4]='|';
            print_array_matrix();
            printf("\n\n");
            print_array_game();
            i++;
            break;
        case '5':
            system("cls");
            game[4][3]=196;
            print_array_matrix();
            printf("\n\n");
            print_array_game();
            i++;
            break;
        case '6':
            system("cls");
            game[4][1]=196;
            print_array_matrix();
            printf("\n\n");
            print_array_game();
            i++;
            break;
        case '7':
            system("cls");
            game[3][0]='|';
            print_array_matrix();
            printf("\n\n");
            print_array_game();
            i++;
            break;
        case '8':
            system("cls");
            game[1][0]='|';
            print_array_matrix();
            printf("\n\n");
            print_array_game();
            i++;
            break;
        case 'A':
            system("cls");
            game[1][2]='|';
            print_array_matrix();
            printf("\n\n");
            print_array_game();
            i++;
            break;
        case 'B':
            system("cls");
            game[2][1]=196;
            print_array_matrix();
            printf("\n\n");
            print_array_game();
            i++;
            break;
        case 'C':
            system("cls");
            game[3][2]='|';
            print_array_matrix();
            printf("\n\n");
            print_array_game();
            i++;
            break;
        case 'D':
            system("cls");
            game[2][3]=196;
            print_array_matrix();
            printf("\n\n");
            print_array_game();
            i++;
            break;
        default:
            //input invalid
            break;
        }
    }
}

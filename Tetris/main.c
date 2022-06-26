#include <stdio.h>
#include <stdlib.h>
#include "Tetris.c"
#include <ctype.h>


int main(int argc, const char * argv[])
{
    //Party 1
    int r, r2,choice,choice2,choice2_2, choice3, choice3_3;
    int SIZE;
    int **gameboard;
    //Party 2
    int blocks[57][5][5], random[37];
    int **blocks2, possible_blocks[3];
    int error =0, OK;
    int chosen, choiceB, co_x=0, co_y=1, check,wrg=0;
    char co_x2, co_y2;
    int i,j;
    //Party 3
    int stateL, stateC, scoreL=0, scoreC=0, computescore=0, CorL;

    printf("---------------Welcome to Tetris !--------------- \n");
    //Party 1 choose the parameters of the game
    do
    {
        printf ("You have two options :\n\n1.Display the rule of this game\n2.Start the Game\nWhat do you want to do ?\n");
        r=scanf("%d",&choice);
        getchar();
        if (choice==1)
        {
            printf("Rules : The idea is to place each block in the location that eliminates as many rows and / or columns as possible to have the best score. To do this, These last are deleted automatically when they are full.\n");
            printf("Press any key to play \n");
            getchar();
        }
        system("cls");  //Clear the the menu
    }while (r!=1 || choice<1 || choice>2);
    do
    {
        printf("What shape of the gameboard do you want ?\n");
        printf ("1.For the Triangle\n");
        printf ("2.For the Diamond\n");
        printf ("3.For the Circle\n");
        r=scanf("%d",&choice2);
        getchar();
        switch(choice2)
        {
            case 1 :
                printf("You chose the Triangle. Are you sure ?\n");
                do
                {
                    printf("1.Yes\n2.No\n");
                    r=scanf("%d",&choice2_2);
                    getchar();
                } while (r!=1 || choice2_2<1 || choice2_2>2);
                break;
            case 2 :
                printf("You chose the Diamond. Are you sure ?\n");
                do
                {
                    printf("1.Yes\n2.No\n");
                    r=scanf("%d",&choice2_2);
                    getchar();
                } while (r!=1 || choice2_2<1 || choice2_2>2);
                break;
            case 3 :
                printf("You chose the Circle. Are you sure ?\n");
                do
                {
                    printf("1.Yes\n2.No\n");
                    r=scanf("%d",&choice2_2);
                    getchar();
                } while (r!=1 || choice2_2<1 || choice2_2>2);
                break;
        }
    }while (r!=1 ||choice2<1 || choice2>3 || choice2_2==2);
    do
    {
        printf("Do you want :\n1.At each game turn all the available blocks are displayed and you select one\n2.The game select randomly 3 blocks\n");
        r=scanf("%d",&choice3);
        getchar();
        switch (choice3)
        {
            case 1 :
                printf("You chose to have all blocks. Are you sure ?\n");
                do
                {
                    printf("1.Yes\n2.No\n");
                    r=scanf("%d", &choice3_3);
                    getchar();
                }while (r!=1 || choice3_3<1 || choice3_3>2);
                break;
            case 2 :
                printf("You chose to have 3 random blocks. Are you sure ?\n");
                do
                {
                    printf("1.Yes\n2.No\n");
                    r=scanf("%d", &choice3_3);
                    getchar();
                }while (r!=1 || choice3_3<1 || choice3_3>2);
                break;
        }
    }while (r!=1 || choice3<1 || choice3>2 || choice3_3 >1);
    system("cls");
    choicesize (&SIZE, choice2);
    SIZE+=3;
    gameboard = create_2D_dyn(SIZE);
    fill_2D_board(gameboard, SIZE, choice2);
    printf("This is your game-board !\n");
    display_board(gameboard, SIZE,computescore);

    // party 2 : blocks
    do
    {
        block(blocks);
        select_blocks(choice3, choice2, random);
        if (choice3==1)
            display_block1(choice2, blocks);
        else
            display_block2(choice2, blocks, random, possible_blocks);
        do
        {
            do{
                OK=0;
                printf("Choose one block !\n");
                r = scanf("%d", &chosen);
                getchar();
                if (choice3==2)
                    for (i=0; i<3; i++)
                        if (possible_blocks[i] == chosen)
                            OK=1;
            }while((r!=1) || (chosen<0) || ((choice2== 1) && (chosen>57)) || ((choice2== 2) && (chosen>46)) || ((choice2== 3) && (chosen>32)) || ((choice3==2)&& (OK==0)));
            blocks2=create_2D_dyn(5);
            blocks2 = fill_location_tab(chosen);
            choiceB = choice_block (blocks2);
        }while(choiceB!=1);
        do
        {
            printf("Be careful, if you put wrong coordinate three times the game stops\n");
            co_x = choose_coordinate(co_x, SIZE);
            co_y = choose_coordinate(co_y, SIZE);
            check = check_validity(gameboard, SIZE, co_x, co_y, blocks2);
            if (check == 0){
                error += 1;
                wrg+=1;
                printf("Wrong coordinate, you have % chance\n",3-wrg);}
            else
                place_block(gameboard, co_x, co_y, blocks2);
            co_x=0;
            if (error == 3){
                break;
            }
        }while (check==0);

        // Party 3 : check if a line or column is empty, eliminate it and shift + compute the score.
        for (i=SIZE-1; i>1; i--)
        {
            stateL = state_line(gameboard, i, SIZE);
            stateC = state_column(gameboard, i, SIZE);
            if (stateL==1)
            {
                CorL=1;
                scoreL=scoreL + score(gameboard,i,SIZE,CorL);
                eliminate_line(gameboard, i, SIZE);
                if (scoreL!=0)
                    shift_line(gameboard, i, SIZE);
            }
            if (stateC==1)
            {
                CorL = 2;
                scoreC= scoreC + score(gameboard,i,SIZE, CorL);
                eliminate_column(gameboard,i,SIZE);
            }
            computescore=computescore+scoreL+scoreC;
            scoreL=0;
            scoreC=0;
        }
        display_board(gameboard, SIZE,computescore);
    }while (error < 3);
    free2D(gameboard,SIZE);
    free2D(blocks2,5);
    system("cls");
    printf("Sorry you lose ! This your final score : %d\n\n",computescore);
}




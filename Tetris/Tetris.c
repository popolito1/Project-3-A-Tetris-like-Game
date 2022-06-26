#include "Tetris.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>

void choicesize(int *s, int choiceshape)
{
    int size, character;
    do{
        printf("Give the size of the game-board you want (minimum 21 and maximum 26).\n For triangles and diamonds, you have to choose a odd number.\n");
        size = scanf("%d",s);
        while ((character = (int)getchar()) != '\n' && character != EOF);
    }while (size!=1 || (size==1 && (*s<21 || *s>26)) || (choiceshape==1 && *s%2 == 0) || (choiceshape==2 && *s%2 == 0));
}

//function 1: function which creates a dynamic array in 2D
int **create_2D_dyn(int size)
{
    int **A;
    int i;
    A=(int **)malloc(size*sizeof(int*));
    for(i=0;i<size;i++)
        A[i]=(int*)malloc(size*sizeof(int));
    return A;
}

// Each "for" represents a line to fill of 1. Sometimes it's correspond to the column, it depend on the shape of the block but mainly it's the line.
//COMMON BLOCK
int **create_block_1()
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (j=0;j<2;j++)
        B[4][j]=1;
    B[3][0]=1;
    return B;
}

int **create_block_2()
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (j=0;j<2;j++)
        B[4][j]=1;
    B[3][1]=1;
    return B;
}

int **create_block_3()
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (j=0;j<2;j++)
        B[3][j]=1;
    B[4][1]=1;
    return B;
}

int **create_block_4()
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (j=0;j<2;j++)
        B[3][j]=1;
    B[4][0]=1;
    return B;
}

int **create_block_5(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    B[3][0]=1;
    for (j=0; j<3; j++)
        B[4][j] =1;
    return B;
}

int **create_block_6(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    B[3][2]=1;
    for (j=0; j<3; j++)
        B[4][j] =1;
    return B;
}

int **create_block_7(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    B[4][1]=1;
    for (i=2; i<5; i++)
        B[i][0] =1;
    return B;
}

int **create_block_8(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    B[2][0]=1;
    for (i=2; i<5; i++)
        B[i][1] =1;
    return B;
}

int **create_block_9(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i = 2;i<5; i++)
        B[i][0]=1;
    B[3][1]=1;
    return B;
}

int **create_block_10(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i = 2;i<5; i++)
        B[i][1]=1;
    B[3][0]=1;
    return B;
}

int **create_block_11(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (j = 0;j<3; j++)
        B[4][j]=1;
    B[3][1]=1;
    return B;
}

int **create_block_12(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (j = 0;j<3; j++)
        B[3][j]=1;
    B[4][1]=1;
    return B;
}


int **create_block_13(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (j=0; j<2; j++)
        B[3][j]=1;
    for (j=1; j<3; j++)
        B[4][j]=1;
    return B;
}

int **create_block_14(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (j=0; j<2; j++)
        B[4][j]=1;
    for (j=1; j<3; j++)
        B[3][j]=1;
    return B;
}

int **create_block_15(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i=2; i<4; i++)
        B[i][0]=1;
    for (i=3; i<5; i++)
        B[i][1]=1;
    return B;
}

int **create_block_16(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i=2; i<4; i++)
        B[i][1]=1;
    for (i=3; i<5; i++)
        B[i][0]=1;
    return B;
}

int **create_block_17(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i = 1; i<5; i++)
        B[i][0]=1;
    return B;
}

int **create_block_18(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (j = 0; j<4; j++)
        B[4][j]=1;
    return B;
}


int **create_block_19(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    B[4][0]=1;
    return B;
}

int **create_block_20(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i = 3; i<5; i++)
        for (j=0; j<2; j++)
            B[i][j]=1;
    return B;
}

//CIRCLE
int **create_block_21(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j] =0;
    for (i = 1; i<5; i++)
        for (j=0;j<4;j++)
            B[i][j] =1;
    return B;
}

int **create_block_22(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j] =0;
    for (i = 3; i<5; i++)
        for (j=0;j<4;j++)
            B[i][j] =1;
    return B;
}

int **create_block_23(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j] =0;
    for (i = 1; i<5; i++)
        for (j=0;j<2;j++)
            B[i][j] =1;
    return B;
}

int **create_block_24(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j] =0;
    for (i = 1; i<5; i++)
        for (j=1;j<3;j++)
            B[i][j] =1;
    for (i = 2; i<4; i++)
        for (j=0;j<4;j++)
            B[i][j] =1;
    return B;
}

int **create_block_25(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j] =0;
    for (i = 1; i<5; i++)
    {
        B[i][0] =1;
        B[i][3]=1;
    }
    for (j = 0; j<4; j++)
        B[4][j] =1;
    return B;
}

int **create_block_26(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);

    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j] =0;

    for (i = 1; i<5; i++)
        B[i][2] =1;
    for (j = 0; j<3; j++)
    {
        B[1][j] =1;
        B[4][j]=1;
    }
    return B;
}

int **create_block_27(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
    {
        for (j=0;j<5;j++)
        {
            B[i][j] =0;
        }
    }
    for (i = 3; i<5; i++)
    {
        B[i][0] =1;
        B[i][4]=1;
    }
    for (j = 0; j<5; j++)
        B[3][j] =1;
    return B;
}

int **create_block_28(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
    {
        for (j=0;j<5;j++)
        {
            B[i][j] =0;
        }
    }
    for (i = 3; i<5; i++)
        for (j=0; j<3; j++)
            B[i][j] =1;
    B[3][3] =1;
    return B;
}

int **create_block_29(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j] =0;
    for (i = 1; i<5; i++)
        B[i][3] =1;
    for (j = 0; j<4; j++)
        B[1][j] =1;
    return B;
}
int **create_block_30(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j] =0;
    for (i =1; i<5; i++)
        B[i][0] =1;
    for (j = 0; j<4; j++)
        B[4][j] =1;
    B[3][3]=1;
    return B;
}

int **create_block_31(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j] =0;
    for (i = 0;i<5; i++)
        B[i][0] =1;
    return B;
}
int **create_block_32(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j] =0;
    for (j=0;j<5;j++)
        B[4][j] =1;
    return B;
}


//DIAMOND
int **create_block_33(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i=3;i<5;i++)
        B[i][0]=1;
    for (i=2;i<4;i++)
        B[i][1]=1;
    for (i=1;i<3;i++)
        B[i][2]=1;
    B[1][3]=1;
    return B;
}
int **create_block_34(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i=1;i<3;i++)
        B[i][1]=1;
    for (i=2;i<4;i++)
        B[i][2]=1;
    for (i=3;i<5;i++)
        B[i][3]=1;
    B[1][0]=1;
    return B;
}
int **create_block_35(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i=1;i<3;i++)
        B[i][0]=1;
    for (i=2;i<4;i++)
        B[i][1]=1;
    for (i=3;i<5;i++)
        B[i][2]=1;
    B[4][3]=1;
    return B;
}
int **create_block_36(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i=1;i<3;i++)
        B[i][3]=1;
    for (i=2;i<4;i++)
        B[i][2]=1;
    for (i=3;i<5;i++)
        B[i][1]=1;
    B[4][0]=1;
    return B;
}

int **create_block_37(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i=1;i<5;i++)
        for(j=1;j<3;j++)
            B[i][j]=1;
    for (j=0;j<4;j++)
        B[1][j]=1;
    return B;
}
int **create_block_38(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
    {
        for (j=0;j<5;j++)
        {
            if ((i==1 && j==3)||(i==4 && j==3 )||(i==1 && j==0)||(i==4 && j==0))
                B[i][j]=1;
            else
                B[i][j]=0;
        }
    }
    for (i=2;i<4;i++)
        for(j=1;j<3;j++)
            B[i][j]=1;
    return B;
}

int **create_block_39(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
    {
        for (j=0;j<5;j++)
        {
            if ((i==4 && j==2))
                B[i][j]=1;
            else
                B[i][j]=0;
        }
    }
    for (j=0;j<5;j++)
        B[2][j]=1;
    for (j=1;j<4;j++)
        B[3][j]=1;
    return B;
}
int **create_block_40(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i=2;i<5;i++)
        B[i][3]=1;
    for (j=0;j<4;j++)
        B[3][j]=1;
    return B;
}

int **create_block_41(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
    {
        for (j=0;j<5;j++)
        {
            if (i==4 && j==3)
                B[i][j]=1;
            else
                B[i][j]=0;
        }
    }
    for(j=0;j<4;j++)
        B[3][j]=1;
    return B;
}
int **create_block_42(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
    {
        for (j=0;j<5;j++)
        {
            if (i==1&&j==0)
                B[i][j]=1;
            else
                B[i][j]=0;
        }
    }
    for (i=1;i<5;i++)
        B[i][1]=1;
    return B;
}
int **create_block_43(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
    {
        for (j=0;j<5;j++)
        {
            if (i==4&&j==1)
                B[i][j]=1;
            else
                B[i][j]=0;
        }
    }
    for (i=1;i<5;i++)
        B[i][0]=1;
    return B;
}


//TRIANGLE
int **create_block_44(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i=3; i<5; i++)
        B[i][0]=1;
    return B;
}
int **create_block_45(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <3; i++)
        for (j=0;j<3;j++)
            B[i][j]=0;
    for (j=0; j<2; j++)
        B[4][j]=1;
    return B;
}

int **create_block_46(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (j=0; j<3; j++)
        B[4][j]=1;
    return B;
}

int **create_block_47(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i=2; i<5; i++)
        B[i][0]=1;
    return B;
}

int **create_block_48(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
    {
        for (j=0;j<5;j++)
        {
            if ((i==4 && j==2) || (i==3 & j==1)||(i==2 && j==0))
                B[i][j]=1;
            else
                B[i][j]=0;
        }
    }
    return B;
}
int **create_block_49(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
    {
        for (j=0;j<5;j++)
        {
            if ((i==3 && j==1) || (i==4 & j==0)||(i==2 &&j==2))
                B[i][j]=1;
            else
                B[i][j]=0;
        }
    }
    return B;
}

int **create_block_50(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
    {
        for (j=0;j<5;j++)
        {
            if ((i==2 && j==2)|| (i==4 && j==0))
                B[i][j] =1;
            else
                B[i][j]=0;
        }
    }
    for (i=2;i<5;i++)
        B[i][1]=1;
    return B;
}
int **create_block_51(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
    {
        for (j=0;j<5;j++)
        {
            if ((i==2 && j==2)|| (i==4 && j==0))
                B[i][j] =1;
            else
                B[i][j]=0;
        }
    }
    for (j=0;j<3;j++)
        B[3][j]=1;
    return B;
}
int **create_block_52(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
    {
        for (j=0;j<5;j++)
        {
            if ((i==2 && j==0)|| (i==4 && j==2))
                B[i][j] =1;
            else
                B[i][j]=0;
        }
    }
    for (i=2;i<5;i++)
        B[i][1]=1;
    return B;
}
int **create_block_53(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
    {
        for (j=0;j<5;j++)
        {
            if ((i==2 && j==0)|| (i==4 && j==2))
                B[i][j] =1;
            else
                B[i][j]=0;
        }
    }
    for (j=0;j<3;j++)
        B[3][j]=1;
    return B;
}

int **create_block_54(void)
{
    int **B=NULL;
    int i,j;
    B=create_2D_dyn(5);
    for (i = 0; i <5; i++)
        for (j=0;j<5;j++)
            B[i][j]=0;
    for (i=2;i<5;i++)
        B[i][1]=1;
    for (j=0;j<3;j++)
        B[3][j]=1;
    return B;
}

int **fill_location_tab(int i)
{
    int **A = NULL;
    switch(i)
    {
        case 1 :
            // COMMON BLOCK
            A=create_block_1();
            break;
        case 2:
            A=create_block_2();
            break;
        case 3:
            A=create_block_3();
            break;
        case 4 :
            A=create_block_4();
            break;
        case 5:
            A=create_block_5();
            break;
        case 6:
            A=create_block_6();
            break;
        case 7:
            A=create_block_7();
            break;
        case 8:
            A=create_block_8();
            break;
        case 9:
            A=create_block_9();
            break;
        case 10:
            A=create_block_10();
            break;
        case 11:
            A=create_block_11();
            break;
        case 12:
            A=create_block_12();
            break;
        case 13:
            A=create_block_13();
            break;
        case 14:
            A=create_block_14();
            break;
        case 15:
            A=create_block_15();
            break;
        case 16:
            A=create_block_16();
            break;
        case 17:
            A=create_block_17();
            break;
        case 18:
            A=create_block_18();
            break;
        case 19:
            A=create_block_19();
            break;
        case 20:
            A=create_block_20();
            break;
        case 21 :
            //CIRCLE
            A=create_block_21();
            break;
        case 22:
            A=create_block_22();
            break;
        case 23:
            A=create_block_23();
            break;
        case 24:
            A=create_block_24();
            break;
        case 25:
            A=create_block_25();
            break;
        case 26:
            A=create_block_26();
            break;
        case 27:
            A=create_block_27();
            break;
        case 28:
            A=create_block_28();
            break;
        case 29 :
            A=create_block_29();
            break;
        case 30:
            A=create_block_30();
            break;
        case 31:
            A=create_block_31();
            break;
        case 32:
            A=create_block_32();
            break;
        case 33:
            // DIAMOND
            A=create_block_33();
            break;
        case 34:
            A=create_block_34();
            break;
        case 35:
            A=create_block_35();
            break;
        case 36:
            A=create_block_36();
            break;
        case 37:
            A=create_block_37();
            break;
        case 38:
            A=create_block_38();
            break;
        case  39:
            A=create_block_39();
            break;
        case 40:
            A=create_block_40();
            break;
        case 41:
            A=create_block_41();
            break;
        case 42:
            A=create_block_42();
            break;
        case 43 :
            A=create_block_43();
            break;
        case 44:
            A=create_block_21(); //from 44 to 46 is the same block as the circle
            break;
        case 45 :
            A=create_block_31();
            break;
        case 46 :
            A=create_block_32();
            break;
        case 47:
            //TRIANGLE
            A=create_block_44();
            break;
        case 48:
            A=create_block_45();
            break;
        case 49:
            A=create_block_46();
            break;
        case 50:
            A=create_block_47();
            break;
        case 51:
            A=create_block_48();
            break;
        case 52:
            A=create_block_49();
            break;
        case 53:
            A=create_block_50();
            break;
        case 54 :
            A=create_block_51();
            break;
        case 55:
            A=create_block_52();
            break;
        case 56:
            A=create_block_53();
            break;
        case 57:
            A=create_block_54();
            break;
    }
    return A;
}

// 4 - function which fill the board according to the choice of the shape
void fill_2D_board (int **A, int size,int choiceshape)
{
    int i,j;
    //initialization with space everywhere
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            A[i][j]=1;
    //Now, create the border ( with letter and lines)
    for (j=2; j<size-1; j++)
    {

        A[0][j]= 5; // Correspond to letters
        A[1][j]= 2; // correspond to lines
        A[size-1][j]=2;
    }

    for(i=2;i<size-1;i++)
    {
        A[i][0]= 4;
        A[i][1]= 3;
        A[i][size-1]=3;
    }
    // Now fill with point to create the form
    if (choiceshape==1){

        // Triangle
        for (i=size-2; i>size/2-1; i--)
            for (j=2; j<(size/2)+1; j++) // left part
                if (i+j >= size)
                    A[i][j]=0;

        for (i=size-2; i>size/2; i--)
            for (j=size-2; j>size/2; j--) //right part
                if (i>=j)
                    A[i][j]=0;
    }

    if (choiceshape==2)
    {
        // Diamant

        //Top left
        for (i=2; i<size/2+1; i++)
            for (j=2; j<(size/2)+1; j++)
                if (i+j >= (size/2)+2)
                    A[i][j]=0;

        //Top right
        for (i=2; i<(size/2)+1; i++)
            for (j=size-2; j>(size/2)-1; j--)
                if (j-i <=(size/2)-2)
                    A[i][j]=0;

        //Bottom left
        for (i=size-2; i>size/2-1; i--)
            for (j=2; j<(size/2)+1; j++)
                if (i-j <= (size/2)-2)
                    A[i][j]=0;

        //Bottom right
        for (i=size-2; i>(size/2)-1; i--)
            for (j=size-2; j>(size/2)-1; j--)
                if (i+j<= size+((size/2)-2))
                    A[i][j]=0;

    }
    if (choiceshape==3)
    {
        //circle
        //First, put point everywhere and then eliminate the four angle
        for (i=2; i<size-1; i++)
            for (j=2; j<size-1; j++)
                A[i][j]=0;

        //Eliminate top left
        for (i=2; i<(size/3)-1; i++)
            for (j=2; j<(size/3)-1; j++)
                if (i+j <= size-(size/2)-(size/4)+1)
                    A[i][j]=1;

        //Eliminate top right
        for (i=2; i<(size/3)-1; i++)
            for (j=size-2; j>2*(size/3)+1; j--)
                if (j-i >=(size/2)+(size/4)-1)
                    A[i][j]=1;

        //Eliminate bottom left
        for (i=size-2; i>2*(size/3)+1; i--)
            for (j=2; j<(size/3)-1; j++)
                if (i-j >= (size/2)+(size/4)-1)
                    A[i][j]=1;

        //Eliminate bottom right
        for (i=size-2; i>2*(size/3)+1; i--)
            for (j=size-2; j>2*(size/3)+1; j--)
                if (i+j >=size+(size/2)+(size/4)-1 )
                    A[i][j]=1;
    }
}

// 4 - Display of the Gameboard with ASCII table
void display_board(int **A, int size, int sco)
{
    int i,j;
    char letter[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(A[i][j]==0) //0 corresponds to a point
                printf ("%c\u00B7",32);
            if(A[i][j]==1) //1 corresponds to spaces
                printf("%c ",32);
            if(A[i][j]==2) //2 corresponds to the little horizontal lines
                printf("\u2500 ");
            if(A[i][j]==3)//3 corresponds to the little vertical lines
                printf("\u2551");
            if (A[i][j]==4)//4 corresponds to the letters by lines
                printf("%c ",letter[i-2]);
            if (A[i][j]==5)//5 correspond to the letters by columns
                printf("%c ",letter[j-2]);
            if (A[i][j]==6)//6 correspond to a little square (block)
                printf("\u25a0 ");
        }
        printf("\n");
    }
    printf("                                                  this is your score: %d\n",sco);
}

void block(int block_tab[57][5][5]){
    int **Ar,index,j,k;
    for (index=0; index<32; index++)// Circle blocks : from 0 to 31.
    {
        Ar=fill_location_tab(index+1);
        for (j=0;j<5;j++)
            for (k=0;k<5;k++)
                block_tab[index][j][k]=Ar[j][k];
    }
    for (index=0; index<46; index++) //Diamond block : from 0 to 19 and from 30 to 45.
    {
        Ar=fill_location_tab(index+1);
        if (index<20 || index > 29)
            for (j=0;j<5;j++)
                for (k=0;k<5;k++)
                    block_tab[index][j][k]=Ar[j][k];
    }

    for (index=0; index<57; index++) //Triangle block : from 0 to 19 and from 46 to 56.
    {
        Ar=fill_location_tab(index+1);
        if (index < 20 || index > 45)
            for (j=0;j<5;j++)
                for (k=0;k<5;k++)
                    block_tab[index][j][k]=Ar[j][k];
    }
}

void display_block1(int choiceshape,int C[57][5][5])
{
    int triangle_array[31] ={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,46,47,48,49,50,51,52,53,54,55,56};
    int diamond_array[37]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45};
    int circle_array[32]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
    int i,j,k;
    if (choiceshape==1)
        for (i=0; i<31; i++){
            for (j=0;j<5;j++)
            {
                for (k=0;k<5;k++)
                {
                    if(C[triangle_array[i]][j][k]==1)
                        printf("\u25a0 ");
                    else
                        printf("%c ",' ');
                }
                printf("\n");
            }
            printf("%d\n",triangle_array[i]+1);
        }
    if (choiceshape==2)
        for (i=0; i<37; i++)
        {
            for (j=0;j<5;j++)
            {
                for (k=0;k<5;k++)
                {
                    if(C[diamond_array[i]][j][k]==1)
                        printf("\u25a0 ");
                    else
                        printf("%c ",' ');
                }
                printf("\n");
            }
            printf("\n");
            printf("%d\n",diamond_array[i]+1);
        }

    if (choiceshape==3)
        for (i=0;i<32;i++)
        {
            for (j=0;j<5;j++)
            {
                for (k=0;k<5;k++)
                {
                    if(C[circle_array[i]][j][k]==1)
                        printf("\u25a0 ");
                    else
                        printf("%c ",' ');
                }
                printf("\n");
            }
            printf("\n");
            printf("%d\n",circle_array[i]+1);
        }
}

void display_block2(int choiceshape,int C[57][5][5], int randomblock[37],int pb[3])
{
    int i,j,k;
    for (i=0; i<3; i++)
    {
        for (j=0;j<5;j++)
        {
            for (k=0;k<5;k++)
            {
                if(C[randomblock[i]][j][k]==1)
                    printf("\u25a0 ");
                else
                    printf("%c ",' ');
            }
            printf("\n");
        }
        printf("\n");
        printf("%d\n",randomblock[i]+1);
        pb[i]=randomblock[i]+1;
    }
}

void select_blocks (int choicepolicy, int choiceshape,int randomblocks[37])
{
    srand((unsigned)time(NULL));
    int triangle_array[31] ={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,46,47,48,49,50,51,52,53,54,55,56};
    int diamond_array[37]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45};
    int circle_array[32]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
    int random,j,i;
    //for the fist policy and for each shape
    if (choicepolicy==1 && choiceshape==1)
        for(i=0;i<31;i++)
            triangle_array[i]=randomblocks[i];

    if (choicepolicy==1 && choiceshape==2)
        for(i=0;i<37;i++)
            diamond_array[i]=randomblocks[i];

    if (choicepolicy==1 && choiceshape==3)
        for(i=0;i<32;i++)
            circle_array[i]=randomblocks[i];

    //for the second policy and for each shape
    if (choicepolicy==2 && choiceshape==1)
        for (i=0;i<3;i++)
        {
            if(i==0)
                random = rand()%31;

            if(i==1)
            {
                do{
                    random = rand()%31;
                }while(random==randomblocks[0]);
            }
            if(i==2)
            {
                do{
                    random = rand()%31;
                }while(random==randomblocks[0] || random==randomblocks[1]);
            }
            randomblocks[i]=triangle_array[random];
        }

    if (choicepolicy==2 && choiceshape==2)
        for (i=0;i<3;i++)
        {
            if(i==0)     // it chooses 3 times 3 different blocks in the 37 being in the array diamond
                random = rand()%37;

            if(i==1){
                do{
                    random = rand()%37;
                }while(random==randomblocks[0]);
            }
            if(i==2){
                do{
                    random = rand()%37;
                }while(random==randomblocks[0] || random==randomblocks[1]);
            }
            randomblocks[i]=diamond_array[random];
        }

    if (choicepolicy==2 && choiceshape==3)
        for (i=0;i<3;i++)
        {
            if(i==0)
                random = rand()%32;

            if(i==1){
                do{
                    random = rand()%32;
                }while(random==randomblocks[0]);
            }
            if(i==2){
                do{
                    random = rand()%32;
                }while(random==randomblocks[0] || random==randomblocks[1]);
            }
            randomblocks[i]=circle_array[random];
        }
}

int choice_block (int**block)
{
    int i,j,choice;
    printf("You chose this block. Are you sure ?\n1/Yes\n2/No\n");
    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            if (block [i][j] ==1)
                printf("\u25a0 ");
            else
                printf("%c ",32);
        }
        printf("\n");
    }
    scanf("%d",&choice);
    return choice;
}

int choose_coordinate (int x, int c)
{
    int okay=0,i,j;
    char x2,y2;
    char letter1[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char letter2[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    do
    {
        if (x==0)
            printf("Where do you want to place your block ?(which line ?)\n");
        else
            printf("Where do you want to place your block ? (which column ?)\n");
        getchar();
        scanf("%c",&x2);
        for (i=0; i<c-3; i++)
            if (x2 == letter1[i] || x2 == letter2[i])
            {
                okay =1;
                x = i+2;
            }
    }while (okay==0);
    return x;
}

int check_validity (int **A, int size, int posR, int posC, int **block)
// r = nb total of lines of the board, c=nb total of columns of the board, posR = num of line we want to place, posC= num of column we want to place.
{
    int i,j;
    int hb=0, wb=0;
    // in order to know width and high
    for (i=4; i>0; i--)
        for (j=4; j>=0; j--)
            if (block[i][j]==1)
            {
                if (i== 0)
                    hb=5;
                if (i== 1)
                    hb=4;
                if (i== 2)
                    hb=3;
                if (i== 3)
                    hb=2;
                if (i== 4)
                    hb=1;
                if (wb < j+1)
                    wb= j+1;
            }
    if ((posR - hb < 2)||(posC +wb > size-1))// means we are out of range.
        return 0;

    for (i=4; i>=0; i--)
        for (j=0; j<5; j++)
            if ((A[posR-4+i][j+posC]==1 && block[i][j]==1)||(A[posR-4+i][j+posC]==2 && block[i][j]==1)||(A[posR-4+i][j+posC]==3 && block[i][j]==1) || (A[posR-4+i][j+posC]==6 && block[i][j]==1))
                return 0;
    return 1;
}

void place_block (int **A, int x, int y, int **btp) //btp = block to place
{
    int i,j;
    int hb=0, wb=0;
    // in order to know the width and high
    for (i=4; i>0; i--)
        for (j=4; j>=0; j--)
            if (btp[i][j]==1)
            {
                if (i== 0)
                    hb=5;
                if (i== 1)
                    hb=4;
                if (i== 2)
                    hb=3;
                if (i== 3)
                    hb=2;
                if (i== 4)
                    hb=1;
                if (wb < j+1)
                    wb= j+1;
            }
    for (i=4; i>=0; i--)
        for (j=0; j<5; j++)
            if (A[x-4+i][y+j]==0 && btp[i][j]==1)
                A[x-4+i][y+j]= 6;
}


void shift_line (int **A, int line, int size)
{
    int i,j;
    for (i=line; i>2; i--)
        for (j=2; j<size-2; j++)
        {
            if (A[i][j]==6)
                A[i][j]=0;
            if ((A[i-1][j]==6)&& (A[i][j]==0))
                A[i][j]=6;
            //A[i-1][j]=0;
        }

}


/*fonction 9 : verifier qu'une ligne est complète*/
int state_line(int **A, int numR, int size)
{
    int i;
    for (i=2; i<size-1; i++)
    {
        if (A[numR][i] == 0) /* If there is a point in the line */
            return 0;
    }
    return 1;
}

/*fonction 10 : verifier qu'une colone est complète*/
int state_column(int **A, int numC, int size)
{
    int i;
    for (i=2; i<size-1; i++)
    {
        if (A[i][numC]== 0)
            return 0;
    }
    return 1;
}

/*fonction 11 : eliminer une ligne pleine*/
void eliminate_line(int **A, int l, int size) /* l = row to eliminate*/
{
    int i;
    for (i=2; i<size-1; i++)
        if (A[l][i]==6)
            A[l][i] = 0; /*5 correspond au point donc la case devient un point*/
}

/*fonction 12 : eliminer une colonne pleine*/
void eliminate_column (int **A, int size, int co) /* co = column to eliminate*/
{
    int i;
    for (i=2; i<size-1; i++)
        if (A[i][co]==6)
            A[i][co] = 0; /*5 correspond au point donc la case devient un point*/
}



int score (int **A, int num, int size, int corl)
{
    int i,j,score=0;
    if (corl == 1)
        for (i=2; i<size-1; i++){ /*count the elimination of line*/
            if (A[num][i]==6)
                score+=10;
        }
    if (corl ==2)
        for(j=2;j<size-1;j++){ /*count the elimination of column (more difficult so more points)*/
            if (A[j][num]==6)
                score +=20;
        }
    return score;
}

void free2D (int **A, int l)
{
    int i;
    for (i=0;i<l;i++)
        free (A[i]);
    free(A);
}

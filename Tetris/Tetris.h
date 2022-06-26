#ifndef Tetris_h
#define Tetris_h
#include <stdio.h>



int **create_2D_dyn(int);
void choicesize(int *, int);

//COMMON BLOCK
int **create_block_1(void);
int **create_block_2(void);
int **create_block_3(void);
int **create_block_4(void);
int **create_block_5(void);
int **create_block_6(void);
int **create_block_7(void);
int **create_block_8(void);
int **create_block_9(void);
int **create_block_10(void);
int **create_block_11(void);
int **create_block_12(void);
int **create_block_13(void);
int **create_block_14(void);
int **create_block_15(void);
int **create_block_16(void);
int **create_block_17(void);
int **create_block_18(void);
int **create_block_19(void);
int **create_block_20(void);
//CIRCLE
int **create_block_21(void);
int **create_block_22(void);
int **create_block_23(void);
int **create_block_24(void);
int **create_block_25(void);
int **create_block_26(void);
int **create_block_27(void);
int **create_block_28(void);
int **create_block_29(void);
int **create_block_30(void);
int **create_block_31(void);
int **create_block_32(void);
//DIAMOND
int **create_block_33(void);
int **create_block_34(void);
int **create_block_35(void);
int **create_block_36(void);
int **create_block_37(void);
int **create_block_38(void);
int **create_block_39(void);
int **create_block_40(void);
int **create_block_41(void);
int **create_block_42(void);
int **create_block_43(void);
//TRIANGLE
int **create_block_44(void);
int **create_block_45(void);
int **create_block_46(void);
int **create_block_47(void);
int **create_block_48(void);
int **create_block_49(void);
int **create_block_50(void);
int **create_block_51(void);
int **create_block_52(void);
int **create_block_53(void);
int **create_block_54(void);

int **fill_location_tab(int i);
void fill_2D_board (int **,int,int);
void display_board (int **, int, int);
void block(int block_tab[57][5][5]);
void display_blocks1(int, int C[57][5][5]);
void display_blocks2(int, int C[57][5][5],int randomblock[37], int pb[3]);
void select_blocks (int, int,int randomblocks[37]);

int choice_block (int **);
int choose_coordinate (int, int);
int check_validity (int **, int, int , int , int **);
void place_block (int **, int , int , int **);

void shift_line (int **, int , int);
int state_line(int **, int, int);
int state_column(int **, int , int );
void eliminate_line (int **, int , int );
void eliminate_column (int **, int , int );

int score (int **, int, int, int);






#endif /* Tetris_h */

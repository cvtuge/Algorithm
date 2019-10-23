#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static int result[8]={0};

bool is_ok(int row, int column)
{
	int leftup = column - 1, rightup = column + 1;
	for (int i = row-1; i >= 0; --i) { // 逐行往上考察每一行
		if (result[i] == column) return false; // 第 i 行的 column 列有棋子吗？
		if (leftup >= 0) { // 考察左上对角线：第 i 行 leftup 列有棋子吗？
			if (result[i] == leftup) return false;
		}
		if (rightup < 8) { // 考察右上对角线：第 i 行 rightup 列有棋子吗？
			if (result[i] == rightup) return false;
		}
		--leftup; ++rightup;
	}

	return true;
}

void print_queen(int result[])
{
    for(int row = 0; row < 8; ++row){
        for(int col = 0; col < 8; ++col){
            if(result[row]==col){
                printf("Q ");
            }else{
                printf("* ");
            }
        }
        printf("\n");
    }
}

void cal8queen(int row)
{
	if(8 == row){
		print_queen(result);
		return;
	}
	for(int col = 0; col < 8; ++col){
		if(is_ok(row,col)){
			result[row] = col;
			cal8queen(row+1);
		}
	}
}

void main()
{
	cal8queen(0);
}




















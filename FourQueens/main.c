//
//  main.c
//  FourQueens
//
//  Created by hgl on 2018/2/11.
//  Copyright © 2018年 hgl. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
  
    void Trial(char cb[][4],int n,int i);
    int i,j;
    char cb[4][4];//代表棋盘
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cb[i][j]='-';
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%c\t",cb[i][j]);
            if(j%3==0&&j!=0){
                printf("\n");
            }
        }
    }
    printf("#################################\n");
    printf("四皇后的解是:\n");
    Trial(cb,4,0);
    return 0;
}

void Trial(char cb[][4],int n,int i){
    //进入Trial时，在这个棋盘前i-1行已经放置了互不攻击的i-1个棋子
    //现从第i行起后续棋子选择合适的位置
    int s;
    int judgeLegal(char cb[][4],int i,int j);
    if(i==n){//递归结束条件，4颗棋子已经全部放完了（其实就是找到符合条件的布局了，当i=3结束时，4颗棋子都已经放好了），递归结束
        int j,k;
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                printf("%c\t",cb[j][k]);
                if(k%3==0&&k!=0){
                    printf("\n");
                }
            }
        }
        printf("#################################\n");
    }else{
        for(s=0;s<n;s++){//在第i行第s列放置一个棋子
            cb[i][s]='*';
            if(judgeLegal(cb,i,s)){//判断当前布局是否合法
                Trial(cb, n, i+1);
            }
            cb[i][s]='-';//回溯
        }
    }
}

int judgeLegal(char cb[][4],int i,int j){//任何棋子都不占据棋盘上的同一列 或者同一行 或者同一对角线
    int k,n,t,m,row;
    for(k=0;k<4;k++){//判断同一行
        if(k==j){
            continue;
        }
        if(cb[i][k]==cb[i][j]){//i行
            return 0;
        }
    }
    for(t=i-1;t>=0;t--){//判断同一列
        if(cb[t][j]==cb[i][j]){//j列
            return 0;
        }
    }
   //判断对角线
    //判断左上角
    for(row=i-1,n=j-1;row>=0&&n>=0;n--,row--){
        if(cb[row][n]==cb[i][j]){
            return 0;
        }
    }
    //判断右上角
    for(row=i-1,m=j+1;m<4&&row>=0;m++,row--){
        if(cb[row][m]==cb[i][j]){
            return 0;
        }
    }
    return 1;
}

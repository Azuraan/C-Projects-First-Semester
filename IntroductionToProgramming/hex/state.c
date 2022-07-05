#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ai.h"
#include "state.h"

void printstate(char **ch,int size){
int i,j=0,k,m;
char letter;
printf("    W  H  I  T  E\n   ");
letter='A'-1;
for(k=0;k<size;k++){
 letter++;
 printf("  %c ",letter);
                   }
printf("\n    ");
for(k=0;k<size;k++)
 printf(" -  ");
printf("\n    ");
for(k=0;k<2*size;k++){
 if(k%2==0)
  printf("/ ");
 else
  printf("\\ ");     }
 printf(" B");
printf("\n");
for(k=0;k<size;k++){
for(i=0;i<=k+j;i++)
 printf(" ");
printf("%2d|",k+1);
for(i=0;i<size;i++){
 if(ch[k][i]!='n')
  printf(" %c |",ch[k][i]);
 else
  printf("   |");  }
printf("\n");
for(i=0;i<k+4+j;i++)
 printf(" ");
for(m=0;m<2*size+1;m++){
 if(m%2==0){
  if(m==1)
   printf(" ");
  printf("\\");}
 else
  printf("_/ ");       }
if(k==0)
 printf("  L");
else if(k==1)
 printf("  A");
else if(k==2)
 printf("  C");
else if(k==3)
 printf("  K");

printf("\n");
j++;              }

                   }

Listptr addmv(Listptr olist,char player,int j,int i){
Listptr templist;
templist=malloc(sizeof(struct moves));
templist->prevmv=olist;
templist->p=player;
templist->lpawn=j;
templist->npawn=i;
return templist;                                    }

void undo(Listptr *list,char **board){
Listptr templist;
templist=*list;
(*list)=(*list)->prevmv;
board[templist->npawn][templist->lpawn]='n';
free(templist);         }

int checkwin(char **board,int size){
int i,j=0;
for(i=0;i<size;i++)
 if(board[i][size-1]=='b'){   /*Prin arxisw na elegxw oloklhro ton pinaka gia nikh elegxw thn prwth kai teleutaia lwrida tou asprou kai tou maurou paixth*/
   j++;                                                       /*Gt prokeimenou na upar3ei nikh prepei kai oi duo lwrides na exoun toulaxiston ena pioni*/
   break;                 }
if(j==1)
 for(i=0;i<size;i++)
  if(board[i][0]=='b'){
   b2blacks(board,size);               /*Epeidh xrhsimopoiw thn idia sunarthsh gia na brw poios paixths nikaei metatrepw ton pinaka ston anastrofo tou*/
   if(tracepath(board,0,i,'b',size))                 /*Wste na eleg3w thn panw kai katw lwrida opws kanw kai sta aspra pionia*/
    return 1;
   b2blacks(board,size);
                      }
j=0;
for(i=0;i<size;i++)
 if(board[size-1][i]=='w'){
  j++;
  break;                  }
if(j==1)
 for(i=0;i<size;i++)
  if(board[0][i]=='w')
   if(tracepath(board,0,i,'w',size))
    return 2;
return 0;
}

int tracepath(char **board,int row,int col,char pawn,int size){

  if((row>=size)||(col>=size))
   return 0;
  else if(col==0){
    if(row<size-1){
     if(board[row][col+1]==pawn && tracepath(board,row,col+1,pawn,size))          /*H sunarthsh psaxnei anadromika na brei monopati pou na xei idia pionia*/
      return 1;                                                                     /*Apo panw pros ta katw*/
     else if(board[row+1][col]==pawn && tracepath(board,row+1,col,pawn,size))      /*An bgei ektos oriwn h den odhgei se nikh to monopati h sunarthsh epistrefei 0*/
      return 1;                                                                    /*An odhgei omws epistrefei 1*/
     else
      return 0;   }
    else if(row==size-1){
      if (board[row][col]==pawn)
       return 1;
      else
       return 0;        }
                 }
  else if(col==size-1){
    if(row<size-1){
     if(board[row+1][col]==pawn && tracepath(board,row+1,col,pawn,size))
      return 1;
     else if(board[row+1][col-1]==pawn && tracepath(board,row+1,col-1,pawn,size))
      return 1;
     else
      return 0;
                  }
    else{
      if(board[row][col]==pawn)
       return 1;
      else
       return 0;
        }
                     }
  else{
    if(row<size-1){
     if(board[row+1][col]==pawn && tracepath(board,row+1,col,pawn,size))
      return 1;
     else if(board[row+1][col-1]==pawn && tracepath(board,row+1,col-1,pawn,size))
      return 1;
     else if(board[row][col+1]==pawn && tracepath(board,row,col+1,pawn,size))
      return 1;
     else
      return 0;
                  }
    else{
     if(board[row][col]==pawn)
      return 1;
     else
      return 0;
        }
      }
}

void swap(char *x,char *y){
char temp;
temp=*x;
*x=*y;
*y=temp;
}

void b2blacks(char **board,int size){
int i,j,k;
for(i=0;i<size;i++)
 for(j=0;j<i;j++)
  swap(&board[i][j],&board[j][i]);
}


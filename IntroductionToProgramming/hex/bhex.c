#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "state.h"

Listptr ai(char **,int ,char,char *,int,Listptr );


int main(int argc,char *argv[]){
int size=11,d=1,rule=0,i,j,k,m,turns,prevturn,n;
char player='w',*parametre,**board,order='h',x,buf[678];
char command[80];
FILE *data;
Listptr mvlist=NULL;
while(--argc){
 parametre=*(++argv);
if(!strcmp(parametre,"-n")){
 if (argc-->1)
  size=atoi(*++argv);}
else if(!strcmp(parametre,"-d")){
 if(argc-->1)
  d=atoi(*++argv);        }
else if(!strcmp(parametre,"-b")){
 order='p';           /*seira tou p,pc,an o human,p, exei maura pionia*/
 player='b';                    }
else if(!strcmp(parametre,"-s"))
 rule=1;        /*kanonas antallaghs*/
            }
printf("Size %d Difficulty %d Rule %d Player %c\n",size,d,rule,player);
board=malloc(size*sizeof(char *));
if(board==NULL){
 perror("Board=NULL\n");
 return -1;    }
for(i=0;i<size;i++){
 board[i]=malloc(size*sizeof(char));
 if(board[i]==NULL){
  perror("Board=NULL\n");
  return -1;       }
 for(j=0;j<size;j++)
  board[i][j]='n'; }
 printstate(board,size);
prevturn=-1;
turns=0;
                                             /*H seira e dhlwnei telos tou paixnidiou*/
while(order!='e'){                               /*Kai epanaleiptika diabazw entoles tou xrhsth*/
if(prevturn!=turns)
 if(order=='h')
  printf("%s player (human) plays now\n",(player=='w')? "White" : "Black");
 else
  printf("%s player (computer) plays now\n",(player=='w')? "Black" : "White");
prevturn=turns;
 scanf("%s",command);

 if(!strcmp(command,"swap")){
  if (turns==1 && player=='b' && rule==1){
   i=mvlist->npawn;         /*lpawn=suntetagmenh gramma(A-Z),npawn=suntetagmenh ari8mos(1-26) ,gia ka8e i,j pou anhkei sto [0,25]*/
   j=mvlist->lpawn;         /*antimeta8esh se sxesh me thn kinhsh tou asprou*/
   undo(&mvlist,board);
   board[j][i]='b';
   mvlist=addmv(mvlist,player,i,j);             /*An ginei to swap,paizei to pc ston epomeno guro*/
   order='p';
   printstate(board,size);
   printf("Move played: swap\n");
   continue;                             }
  else if(rule!=1)
   printf("Rule of swaping is not applied\n");
  else if(turns!=1)
   printf("You can only swap places in the second round of the game\n");
  else if(player=='w')
   printf("White player can't swap\n");
                            }

 if(!strcmp(command,"newgame")){
  if(player=='w')
   order='h';
  else
   order='p';
  for(i=0;i<turns;i++)
   undo(&mvlist,board);
  turns=0;
  while((x=getchar())==' ');
  if(x=='w' || x=='b'){
   ungetc(x,stdin);
   scanf("%s",command);
  if(!strcmp(command,"white")){     /*Xrhsimopoiw thn char x gia na e3etasw an mporw na diabasw parakatw,analoga me thn alh8eia twn sun8hkwn*/
   player='w';order='h';
   ungetc('y',stdin);         }
  else if(!strcmp(command,"black")){
   player='b';order='p';
   ungetc('y',stdin);              }
  else
   ungetc('n',stdin);
 if((x=getchar())=='y'){
  while((x=getchar())==' ');
  if(x=='s'){
   ungetc(x,stdin);
   scanf("%s",command);
   if(!strcmp(command,"swapon")){
    rule=1;
    ungetc('c',stdin);          }
   else if(!strcmp(command,"swapoff")){
    rule=0;
    ungetc('c',stdin);                }
   else
    ungetc('n',stdin);
            }
  else
   ungetc(x,stdin);
                       }

if((x=getchar())=='c'){
  while((x=getchar())==' ');
  if(x>='0' && x<='9'){
   ungetc(x,stdin);
   scanf("%s",command);
  for(k=0;k<size;k++)
    free(board[k]);
   free (board);
   size=atoi(command);
   board=malloc(size*sizeof(char *));
   if(board==NULL){
    perror("Board=NULL\n");                /*An alla3ei mege8os,allazw tis diastaseis tou pinaka*/
    return -1;    }
   for(k=0;k<size;k++){
    board[k]=malloc(size*sizeof(char));
    if(board[k]==NULL){
     perror("Board=NULL\n");
     return -1;      }
                      }
                   }
  else
   ungetc(x,stdin);
                     }
                             }
  else
   ungetc(x,stdin);
  printf("Size %d Difficulty %d Rule %d Player %c\n",size,d,rule,player);
  for(i=0;i<size;i++)
   for(j=0;j<size;j++)                 /*Kai "adeiazw" to tamplo*/
    board[i][j]='n';
  printstate(board,size);      }

 if(!strcmp(command,"load")){
  scanf("%s",command);
  if((data=fopen(command,"rb"))==NULL){  /*Anoigw to arxeio me to onoma pou orizetai sthn sumboloseira command,gia diabasma xwris sbhsimo twn prohgoumenwn*/
   printf("File not found\n");                                                                                                        /*periexomenwn tou*/
   return -1;                         }
  n=fread(buf,sizeof(char),678,data); /*Diabasma to polu 678(megisto mege8os tablo 676(26*26)+1(poianou seira einai)+1(mege8os tou tablo)*/
  printf("N is %d\n",n);                                                              /*kai perasma twn xarakthrwn pou diabazontai sto buf*/
   for(k=0;k<size;k++)
    free(board[k]);
   free (board);
  size=buf[0];
  printf("Size is %d\n",size);
  player=buf[1];
  j=1;
  board=malloc(size*sizeof(char *));
   if(board==NULL){
    perror("Board=NULL\n");
    return -1;    }
  for(k=0;k<size;k++){
   board[k]=malloc(size*sizeof(char));
   if(board[k]==NULL){
    perror("Board=NULL\n");
    return -1;    }  }
  for(k=0;k<size;k++)
   for(m=0;m<size;m++)
    board[k][m]=buf[++j];
  printstate(board,size);
  fclose(data);             }
 else if(!strcmp(command,"save")){
  buf[0]=size;
  buf[1]=player;
  n=1;
  for(k=0;k<size;k++)
   for(m=0;m<size;m++) {
    buf[++n]=board[k][m];}
  n++;
  buf[n]='\0';
  scanf("%s",command);
  if((data=fopen(command,"wb"))==NULL)              /*Anoigma tou arxeiou pou orizetai apo thn sumboloseira command gia grapsimo newn dedomenwn kai diagrafh paliwn*/
   printf("Error opening the file\n");                               /*Grafoume sto arxeio oti brisketai sto buf akolou8wntas anapodh diadikasia apo to load*/
  fwrite(buf,sizeof(char),strlen(buf),data);
  fclose(data);                  }

 if(!strcmp(command,"level")){
  while((x=getchar())==' ');
  if(x!='\n'){            /*An akolou8ei ari8mos to level,allazei to d*/
   if(x>='0' && x<='9'){
    d=0;
   while(x>='0' && x<='9'){
     d=x-'0'+d*10;
     x=getchar();         }
                       }
   else
    printf("Error: Unexpected command\n");
             }
  else
   printf("Current level of difficulty %d\n",d);  /*Alliws apla tupwnetai to d*/
                             }

if(!strcmp(command,"suggest")){
 if(order=='h')
  ai(board,size,player,"suggest",d,NULL);
 else
  printf("It's not player's turn");
                              }

if(!strcmp(command,"play")){
if(order=='h'){
  scanf("%s",command);
  i=0;
  m=strlen(command);
  for(k=0;k<m;k++){        /*O prwtos xarakthras meta to play einai kapoio kefalaio gramma*/
   if(k==0){
    j=command[k];
    if(j>='A' && j<='Z'){
     j=j-'A';
     if(j>size){
      printf("Out of the bounds of the board\n");
      break;   }
                        }
    else{
     while((x=getchar())!='\n');
     printf("Error: Unexpected character\n"); /*An den einai gramma tote 3anadiabase entolh*/
     break;
        }
           }
   else{
    if(command[k]>='0' && command[k]<='9')
     i=(command[k]-'0')+i*10;                             /*Metatroph tou ari8mou pou akolou8ei to gramma*/
    else{
     printf("Error: Unexpected character\n");
     break;
        }
    if(i>size){
     printf("Out of the bounds of the board\n");
     break;
              }
       }
                 }
 if(k!=m)
  continue;
  i=i-1;
  if(board[i][j]=='n'){
   turns++;
   board[i][j]=player;
   printstate(board,size);
   printf("Move played: %c%d\n",j+'A',i+1);
   mvlist=addmv(mvlist,player,j,i);
   order='p';
                      }
  else
   printf("This block of board has already a pawn on it\n");

             }
else
 printf("It's not player's turn\n");
                       }

if (!strcmp(command,"cont"))
 if(order=='p'){
  turns++;
  mvlist=ai(board,size,player,"cont",d,mvlist);
  order='h';   }
 else
  printf("It's not computer's turn\n");

if(!strcmp(command,"undo")){
 if((mvlist==NULL)||((mvlist->prevmv==NULL)&&(mvlist->p!=player))){
  printf("There're not any more moves to undo\n");
  continue;                                                       }
 if(mvlist->p==player){
  order='h';
  undo(&mvlist,board);
  printstate(board,size);}
 else{
  for(k=0;k<2;k++)
   undo(&mvlist,board);
  printstate(board,size);
     }
                           }

if(!strcmp(command,"showstate"))
 printstate(board,size);

if(!strcmp(command,"quit"))
 order='e';

if((n=checkwin(board,size))==2){
 printf("White player wins\n");
 order='e';                    }
else if(n==1){
 printf("Black player wins\n");
 order='e';  }

           }
for(i=0;i<size;i++)
 free(board[i]);
free (board);
 }

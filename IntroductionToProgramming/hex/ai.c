#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ai.h"
#include "state.h"

static int r,c;

Listptr ai(char **board,int size,char pawn,char *str,int d,Listptr mvlist){
int i,j,k=0;
if(!strcmp("cont",str)){
 if(pawn=='w')
  pawn='b';                /*Allazw to pioni me to anti8eto tou paixth*/
 else if(pawn=='b')
  pawn='w';
 minimax(board,d,1,pawn,size);  /*O minimax upologizei poia einai h pio suferousa kinhsh me ena sugkekrimeno metro*/
 board[r][c]=pawn;
 printstate(board,size);
 printf("Move played: %c%d\n",c+'A',r+1);
 return addmv(mvlist,pawn,c,r);
                      }
else if(!strcmp("suggest",str)){
 minimax(board,d,1,pawn,size);
 printf("You may play at %c%d\n",c+'A',r+1);
 r=0;c=0;
 return NULL;
                               }
}


int minimax(char **state,int depth,int maxP,char pawn,int size){
int v,i,j,prev;
char **newstate;
newstate=malloc(size*sizeof(char *));      /*Gia ka8e klhsh tou minimax ftiaxnw kainoyrio pinaka gia na mhn alla3w ton arxiko ka8e fora pou briskw ta epomena states*/
 if(newstate==NULL){
  perror("Newstate=NULL\n");               /*San katastash exw ta "stigmiotupa" tou tamplo meta apo ka8emia kinhsh eite tou paixth eite tou upologisth*/
  exit(1);         }

 for(i=0;i<size;i++){
  newstate[i]=malloc(size*sizeof(char));
  if(newstate[i]==NULL){
   perror("Board=NULL\n");
   exit(1);            }
  for(j=0;j<size;j++)
   newstate[i][j]=state[i][j];
                    }

 if(depth==0 || checkwin(newstate,size)){
   v=value(newstate,pawn,size);               /*To telos ths anadromhs orizetai otan ftasoume sto depth(epipedo duskolias pou xoume orisei)h an nwritera */
   for(i=0;i<size;i++)                                                                                                             /*exoume katastash nikhs*/
    free (newstate[i]);
   free(newstate);
   return v;                            }
 else if(maxP){
   v=-677;                  /*An o paixths einai o arxikos paixths pou 8elei na ma8ei thn pio sumferousa kinhsh gia auton*/
   for(i=0;i<size;i++)                                                   /*To maxP einai 1 kai 8eloume thn kaluterh(megisth) katastash gia auton*/
    for(j=0;j<size;j++)
     if((pawn=='b' && state[i][j]=='n')||(pawn=='w' && state[j][i]=='n')){
      if(pawn=='b')
       newstate[i][j]=pawn;
      else
       newstate[j][i]=pawn;
      prev=v;
      v=max(v,minimax(newstate,depth-1,0,pawn,size));    /*Opote kalo thn minimax gia oles tis kinhseis kai briskw poia exei to to megisto metro*/
      if(pawn=='b')                                          /*Epishs na sumeiw8ei oti h8ela ths kinhseis na ths kanei orizontia an to pioni einai mauro kai*/
       newstate[i][j]='n';                                                                 /*ka8eta an einai aspro wste na plhsiazei pio konta sthn sun8hkh nikhs*/
      else
       newstate[j][i]='n';                               /*Epishs prin kanw kapoia kinhsh checkarw an einai keno to block kai afou kanw mia kinhsh*/
      if(prev<v)                                                       /*Kai exw hdh kalesei thn minimax gia authn thn kinhsh*/
       if(pawn=='b'){                                        /*Diagrafw thn kinhsh auth kai elegxw thn epomenh,afou exw eleg3ei ka8e katastash pou prokuptei apo authn*/
        r=i;c=j;}
       else{                                                   /*Otan to v allazei shmainei oti h kainouria katastash einai kaluterh apo thn prohgoymenh*/
        r=j;c=i;}              /*gia auto mesw twn ka8olikwn metablhtwn autou tou arxeiou krataw tis suntetagmenes ths kinhshs pou odhghse sthn sugkekrimenh katastash*/
                                                                         }  /*epishs autes allazoun teleutaia fora sthn ektelesh ths sunarthshs pou kalesame sthn arxh*/
   for(i=0;i<size;i++)                                                         /*opote einai mia apo tis polles pi8anes kinhseis pou odhgoun sthn kaluterh katastash*/
    free (newstate[i]);
   free(newstate);
   return v;
              }
 else if(!maxP){
   v=size*size+1;
   for(i=0;i<size;i++)
    for(j=0;j<size;j++)
     if((pawn=='w' && state[i][j]=='n')||(pawn=='b' && state[j][i]=='n')){
      if(pawn=='w')                  /*Otan einai h seira tou antipalou na pai3ei prepei na kanoume kinhsh me ta dika tou pionia gia auto allazw to arxiko tupo pawn*/
        pawn='b';
      else
        pawn='w';
      if(pawn=='b')
       newstate[i][j]=pawn;                              /*Afou kanw thn kinhsh metatrepw ta pionia ston tupo tou paixth pou mas endiaferei(pc h human)*/
      else
       newstate[j][i]=pawn;
      if(pawn=='w')
       pawn='b';
      else
       pawn='w';
      v=min(v,minimax(newstate,depth-1,1,pawn,size));  /*Sthn sugkekrimenh periptwsh o antipalos 8a kanei thn kinhsh pou mas sumferei to ligotero*/
      if(pawn=='w')
        pawn='b';
      else
        pawn='w';
      if(pawn=='b')
       newstate[i][j]='n';                      /*Efarmozw idia logika me parapanw gia na diagrapsw thn kinhsh auth kai na kanw thn epomenh*/
      else
       newstate[j][i]='n';
      if(pawn=='w')
        pawn='b';
      else
        pawn='w';

                                                                         }
   for(i=0;i<size;i++)
    free (newstate[i]);
   free(newstate);
   return v;
              }
}


int min(int x,int y){
 if(x<y)
  return x;
 else
  return y;         }

int max(int x,int y){
 if(x>y)
   return x;
 else
   return y;        }

int value(char **state,char pawn,int size){
int i,j,mxw=0,mxb=0;
for(i=0;i<size;i++)
 for(j=0;j<size;j++)
  if(state[i][j]!='x')
   mxw=max(maxseq(state,'w',i,j,size),mxw);

for(i=0;i<size;i++)
 for(j=0;j<size;j++)                   /*San metro exw parei thn megaluterh akolou8ia sunexomenwn pioniwn tou paixth meiwn thn antistoixh tou antiapalou tou*/
  if(state[i][j]=='x')
   state[i][j]='w';          /*Me x exw markarei ta pionia pou exw hdh brei oti anhkoun se mia akolou8ia wste na mhn kanw anadromikous kuklous sthn maxseq*/
                                                                       /*Elegxontas to idio block parapanw apo mia fores*/
for(i=0;i<size;i++)
 for(j=0;j<size;j++)
  if(state[i][j]!='x')
   mxb=max(maxseq(state,'b',i,j,size),mxb);

for(i=0;i<size;i++)
 for(j=0;j<size;j++)
  if(state[i][j]=='x')
   state[i][j]='b';

if(pawn=='w')
 return mxw-mxb;
else
 return mxb-mxw;
}

int maxseq(char **x,char p,int row,int col,int size){
int value=0;
 if((col>=size||row>=size||row<0||col<0)|| !((x[row][col]=='x')||(x[row][col]==p)))
  return 0;
 else if(x[row][col]==p||(x[row][col]=='x')){
  if(row-1>=0){
    if(x[row-1][col]==p){                        /*H sunarthsh auth psaxnei tis sunexomenes akolou8ies opote elegxei ta 6 geitonika block tou tamplo*/
     x[row-1][col]='x';value++;
     value+=maxseq(x,p,row-1,col,size);}        /*An brei ena idio me auto to markarei kai pros8etei thn sunexomenh akolou8ia sthn opoia anhkei auto anadromika*/
    if(col+1<size &&  x[row-1][col+1]==p){                                   /*+1 afou kai auto anoikei sthn akolou8ia*/
     x[row-1][col+1]='x';value++;
     value+=maxseq(x,p,row-1,col+1,size);}
             }
  if(row+1<size){
    if(x[row+1][col]==p){
     x[row+1][col]='x';value++;
     value+=maxseq(x,p,row+1,col,size);}
    if(col-1>=0 && x[row+1][col-1]==p){
     x[row+1][col-1]='x';value++;
     value+=maxseq(x,p,row+1,col-1,size);}
                }
  if(col+1<size && x[row][col+1]==p){
   x[row][col+1]='x';value++;
   value+=maxseq(x,p,row,col+1,size);}
  if(col-1>=0 && x[row][col-1]==p){
   x[row][col-1]='x';value++;
   value+=maxseq(x,p,row,col-1,size);}

                                            }
if(value==0 && x[row][col]==p)                  /*An den broume sunexomenes akolou8ies alla blocks ta opoia einai "mona" tous tote h sunarthsh epistrefei 1*/
value++;
return value;
}

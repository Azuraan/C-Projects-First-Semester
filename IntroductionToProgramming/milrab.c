#include <stdio.h>
#include <time.h>
#define MINNUM 3990000000
#define MAXNUM 4010000000
int main() {
unsigned int i,j,total,pr,c;
double sttime, endtime ;
sttime= ((double) clock())/CLOCKS_PER_SEC;
printf("Checking range [%ld,%ld] for primes\n",MINNUM,MAXNUM);
total=0;
 if (MINNUM%2==0){                                                      /*Metatroph apo artio se peritto gia na meiw8oun oi elegxoi sto prwto meros*/
   c=MINNUM+1;
   if (MINNUM==2)
      total=2;
                 }
 else
   c=MINNUM;
         if ((MINNUM==1)||(MINNUM==3))
             total=1;
 for (i=c ; i<=MAXNUM ; i+=2){                                        /*O ari8mos au3anetai kata duo prokeimenou na elegxontai mono perittoi*/
    pr=1;
if (i%3==0)                                                          /*Arxika elegxw an diaireitai me to 3*/
  pr=0;
else{
  j=5;
   while (j*j<=i){
      if ((i%j==0)||(i%(j+2)==0)){                            /*Se ka8e eksada ari8wmn,3ekinwntas apo to 2,(2-7),(8-13),...,exei nohma na elegxoumai mono 2 ari8mous*/
       pr=0;
       break;}                                                /*Ka8ws oi upoloipoi mesa sthn e3ada einai pollaplasia tou 2 h tou 3*/
      else
       j+=6; }                                           /*Oi ari8moi pou elegxoume ka8e fora 3ekinane apo to 5 kai to 7, kai sthn sunexeia au3anontai kata 6*/
        }
 if (pr)
 total++; }                                            /*H sun8hkh pr einai 1 otan o ari8mos einai prwtos,enw an bre8ei diaireths tou i,to pr ginetai 0*/
printf ("Deterministic Algorithm: %d\n", total);
endtime=((double) clock())/CLOCKS_PER_SEC;
printf("Time: %.2f secs \n", endtime-sttime);


unsigned long long x,a;
int r,k;
unsigned int temp,d;
total=0;
sttime= ((double) clock())/CLOCKS_PER_SEC;
for (i=c ; i<=MAXNUM ; i+=2){
r=0;
temp=i-1;                          /*Prokeimenou na xrhsimopoihsw ton algori8mo Miller-Rabin prepei na ferw ton i-1 se sthn morfh (2^r)*d  */
pr=0;
 while (temp%2==0){           /*Gia ton logo auto prepei na diaresw ton i-1 mexri to puliko na nai perittos ari8mos,o d dhladh */
    temp/=2;                  /*Upologizontas parallhla poses fores periexei o i-1 ton ari8mo 2,dhladh thn dunamh r */
    r++;          }
for (j=1 ;j<=3 ;j++){              /*Domh epanalhpshs gia na pilegoume san a prwta to 2,epeita to 7 kai telos to 61,pragmatopoiwntas tous endedeigmenous elegxous */
   if (j==1)
     a=2;
   else if(j==2)
     a=7;
   else
     a=61;
d=temp;
 x=1;
  a=a%i;                /*A3iopoiw ton algori8mo Modular Exponentiation Right to left binary method*/
while (d>0){
      if (d%2==1)
        x=(x*a)%i;
d= d >> 1;
a=(a*a)%i; }
if ((x==1)||(x==i-1)){  /*Elegxw thn prwth idiothta, an o ari8mos thn ikanopoiei proxwrame sthn epomenh epanalhpsh dhladh sto epomeno a*/
    pr++;                                     /*Thn a3ia tou metrhth pr thn e3hgw parakatw*/
    continue;        }
for (k=1 ; k<=r-1 ; k++){
 x=((x%i)*(x%i))%i;                       /*Prokeimenou na apofugw ton upologismo tou x^2modi pou pera apo xronoboro, polu pi8ano na upologistei la8os */
  if (x==i-1){                           /*Efarmozw thn idiothta (a*b)modn=((amodn)*(bmodn))modn */
    pr++;                                              /*Elegxw thn allh idiothta,kai an isxuei pera apo thn au3hsh kata 1 tou metrhth,stamatame ton eswteriko broxo*/
    break;   }                                         /*Sunexizontas ston elegxo tou epomenou a*/
                        }
if (k==r)                         /*O metrhths pr sthn ousia deixnei oti o ari8mos i ikanopoiei tis idiothtes kai gia tous 3 a*/
   break;                 }         /*An o ari8mos k ginei r,upodhlwnetai oti o i den ikanopoiei tis idiothtes gia enan a kai sunepws einai sun8etos*/
if (pr==3)                        /*Ara den exei nohma na eleg3oume kai ta upoloipa a*/
  total++;                        /*Sto telos ka8e epanalhpshs ,efoson exoun elegxei oloi oi a an to pr einai 3, o  ari8mos einai prwtos*/
                             }
endtime=((double) clock())/CLOCKS_PER_SEC;
printf ("Miller-Rabin Algorithm: %d\n", total);
printf("Time: %.2f secs \n", endtime-sttime);
}

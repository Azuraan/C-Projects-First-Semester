#include <stdio.h>
#include <time.h>
#define MINNUM 3990000000
#define MAXNUM 4010000000
int main() {
unsigned int i,j,total,pr,c;
double sttime, endtime ;
sttime= ((double) clock())/CLOCKS_PER_SEC;
total=0;
 if (MINNUM%2==0){
   c=MINNUM+1;
   if (MINNUM==2)
      total=2;
                 }
 else
   c=MINNUM;γ
         if (MINNUM==1)
             total=1;
 for (i=c ; i<=MAXNUM ; i+=2){
    pr=1;
if (i%3==0)
  pr=0;
else{
  j=5;
   while (j*j<=i){
      if ((i%j==0)||(i%(j+2)==0)){
       pr=0;
       break;}
      else
       j+=6; }
        }
 if (pr)
 total++; }
printf ("Total of prime numbers between the given numbers is %d\n", total);
endtime=((double) clock())/CLOCKS_PER_SEC;
printf("Time: %.2f secs \n", endtime-sttime);


unsigned long long x,a;
int r,k;
unsigned int temp,d;
total=0;
sttime= ((double) clock())/CLOCKS_PER_SEC;
for (i=c ; i<=MAXNUM ; i+=2){
r=0;
temp=i-1;
pr=0;
 while (temp%2==0){
    temp/=2;
    r++;         }
d=temp;
for (j=1 ;j<=3 ;j++){
   if (j==1)
     a=2;
   else if(j==2)
     a=7;
   else
     a=61;
d=temp;
x=1;
a=a%((long long)i);
while (d>0){
  if (d%2==1)
    x=(x*a)%((long long)i);
d= d >> 1;
a=(a*a)%((long long)i); }
if ((x==1)||(x==((long long)(i-1)))){
    pr++;
    continue;        }
for (k=1 ; k<=r-1 ; k++){
 x=((x%(long long)i)*(x%(long long)i))%((long long)i);
  if (x==((long long)(i-1))){
    pr++;
    break;   }
                        }
 if (k==r)
   break;                 }
if (pr==3)
 total++;
                             }
endtime=((double) clock())/CLOCKS_PER_SEC;
printf ("Total of prime numbers between the given number ,found by the Miller-Rabin determenistic method, is %d\n", total);
printf("Time: %.2f secs \n", endtime-sttime);
}

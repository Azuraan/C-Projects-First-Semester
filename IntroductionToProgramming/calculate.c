#include <stdio.h>
int bracket(int , int, int *);

int main(void){
int x,error;
while ((x=getchar())!=EOF){
error=0;
bracket(x,'\n',&error);          }
             }

int calculate(int a,int sym,int b){        /*Sunarthsh gia thn ektelesh twn praksewn wste na mhn xreiazetai na grafw ton sugkekrimeno kwdika opou xreiazontai pra3eis*/
if (sym=='+')
  return a+b;
else if (sym=='-')
  return a-b;
else if (sym=='*')
  return a*b;
                                  }
int bracket(int x,int stop, int *error){  /*H metablhth stop ka8orizei thn timh gia thn opoia stamataei na ekteleitai h sunarthsh, enw h error deixnei pote*/
int res,numb,z,n,sign,val,y,prev,times;                                                                                                       /*uparxei la8os*/
times=0; /*Metablhth pou katagrafei poses fores exw balei kapoio proshmo wste na emfanistei la8os ka8e fora pou uparxoun parapanw apo ena proshma*/
prev=0; /*Metablhth pou krataei thn timh pou dw8hke sthnn prohgoumenh eisodo */
numb=0; /*Metablhth pou pairnei thn timh tou ari8mou pou dinetai sthn eisodo */
val=0; /*Metablhth pou pairnei thn timh tou ari8mou pou exoume mexri stigmhs,afou h getchar pou 8a xrhsimopoihsw parakatw diabazei mono ena xarakthra thn fora*/
res=0; /*Metablhth pou fulasei thn timh tou apotelesmatos*/
z='+'; /*Metablhth pou fulasei thn prohgoumenh pra3h, dhladh +,- h * */
n=0;  /*Metablhth pou fulaei thn timh tou ari8mou pou brisketai aristera apo thn pra3h prin kapoion pollaplasiasmo,(e3hgw parakatw) */
y=0; /*Metablhth pou fulaei thn prohgoumenh timh pou dw8hke sthn eisodo alla den pairnei timh an sthn prohgoumenh dw8hke keno */
sign=1; /*Metablhth pou fulaei to proshmo, an dw8ei alliws einai panta 8etiko,tou ari8mou numb */
if (*error==0){
if (x==stop){
 if (stop=='\n') /*An den do8oun times alla path8ei kateu8eian enter tote apla proxwraei sthn epomenh eisodo ari8mhtikhs parastashs*/
  return 0;
 else{
  printf("There's nothing in the panthesis\n");/*An exoume kanei anadromh se paren8esh alla dw8ei kateu8eian to ) tote h paren8esh einai adeia*/
  *error=1;}
            }
while (x!=stop){
if ((x=='\n')&&(stop==')')){
 printf("Missing closing parenthesis\n");/*An briskomaste mesa se paren8esh kai path8ei enter tote h paren8esh den "kleinei" */
 *error=2;
 break;                    }
if ((((x<'0')|| (x>'9'))&&(x!=' ')&&(x!='\t')&&(x!='+')&&(x!='-')&&(x!='*')&&(x!='('))||((x=='*')&&(y=='*'))){
 printf("Unexpected character\n");
 *error=1;
 break;                                                                     }
if (((y>='0')&&(y<='9'))&&((prev==' ')||(prev=='\t'))&&((x>='0')&&(x<='9'))){
 printf("Unexpected gap between the digits of a number\n");
 *error=1;
 break;                                                     }
if ((x>='0')&&(x<='9')){    /*Ypologismos tou ari8mou bhma bhma mexri na do8ei eisodos diaforetikh twn psufiwn tou dekadikou susthmatos se kwdika ascii*/
 val=val*10+(x-'0');
 numb=val*sign;        }
if ((x=='+')||(x=='-')||(x=='*')) {
 if (((y=='+')||(y=='-')||(y=='*'))||(y==0)){
  times++;                                     /*An do8hke pra3h sthn prohgoumenh eisodo kai 3anado8hke pra3h kai sthn trexousa tote an auto einai - allazei to proshmo*/
  if (times<=1){       /*Wstoso prokeimenou na thrh8ei h grammatikh,<snumber> ::= <unumber> |'+' <unumber> |'-'<unumber>,den ginetai na exoume parapanw apo ena proshma*/
   if (x=='-')      /*Gia auto xrhsimopoiw thn pr wste na emfanistei mhnuma la8ous otan dw8oun parapanw apo ena proshma*/
    sign=sign*(-1);
   else if (x=='*'){                       /*An omws do8ei * meta apo  pra3h dw8ei prokuptei pali la8os*/
    printf("Unexpected character\n");
    *error=1;
    break;         }
               }
  else{
   printf("Unexpected character\n");
   *error=1;
   break;}
                                           }
 else{
  times=0;                          /*Prokeimenou na kanw pra3eis prepei na krathsw duo ari8mous, opote sthn res apo8hkeuw ton prwto ari8mo*/
  res=calculate(res,z,numb);    /*Ka8e fora pou sunantaw sumbolo pra3hs kanw thn prohgoumenh kai krataw to sumbolo pou do8hke twra mexri na dw8ei epomenh*/
   if ((z!='*')&&(x=='*')){
    n=calculate(res,z,(-1)*numb); /*Me authn thn logikh prepei omws na akurwsw thn pra3h prin ton pollaplasiasmo an einai pros8afairesh kai na thn kanw argotera*/
    res=res-n;            }
   if ((x!='*')&&(z=='*'))        /*Sugkekrimena otan teleiwsei o pollaplasiasmos*/
    res=res+n;
  sign=1;
  z=x;
  numb=0;
  val=0;}
                                 }
prev=x;
if (x=='('){
 if (times){
  printf("Did not expect a sign before the parenthesis\n");
  *error=1;                   /*Otan do8ei ( mpainoume se paren8esh,kai upologizetai h parastash me ton idio tropo pou 8a upologizotan kai prin,me tous idious kanones*/
  break;}               /*Opote xrhsimopoiw anadromh ths parousas sunarthshs,upologizontas prwta thn parastash entos ths paren8esh kai epeita ekxwrwntas thn sthn numb*/
  if ((y!='*')&&(y!='+')&&(y!='-')&&(y!=0)&&(y!='(')){
   printf("Expected +,* or - before the parenthesis\n");
   *error=1;
   break;                         }
 numb=bracket(x=getchar(),')',error);
 if (*error)   /*An bre8ei error mesa sthn paren8esh tote stamataei h epanalhpsh*/
  break;
 x=')';   }
if ((x!=' ')&&(x!='\t'))
 y=x;
x=getchar();
if (x==stop){         /*Otan do8ei h sun8hkh termatismou tou upologismou ths parastashs prepei na ektelestei h teleutaia pra3h pou do8hke, afou den 8a do8ei h epomenh*/
 res=calculate(res,z,numb);
  if (z=='*')
  res=res+n;
            }
                }
      }
if (*error){  /*An exei bre8ei la8os tote an eimaste mesa se paren8esh prepei na bgoume apo authn kai epeita na paroume olous tous xarakthres mexri thn allagh grammhs*/
 if(stop==')'){  /*Gia na mpoume sthn epomenh seira kai na dextoume nees eisodous, oxi autes pou 8a epairne h getchar gia thn lan8asmenh parastash*/
   return 1;}
 if(stop=='\n')
  if(*error==2)   /*An to problhma htan oti den uphrxe ) gia na kleisei h paren8esh tote den uparxoun alloi xarakthres na do8oun gia auto termatizw egw thn parastash*/
   x=stop;
  while (x!=stop){
   x=getchar();}}
if ((*error==0)&&(x==stop)){
 if ((y=='*')||(y=='-')||(y=='+')){
  printf("Unexpected end of input\n");
  *error=1;}
 else if (stop=='\n'){
  if (y!=0)
  printf("Result is %d\n",res);
  return 0;          }
 else if (stop==')')
  if (y!=0)
   return res;
  else{
   *error=1;
   printf("There's nothing in the parenthesis\n");
      }
    }
}

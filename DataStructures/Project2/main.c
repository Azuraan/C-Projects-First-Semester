/*Onomateponumo: Gewrgios Galanhs
  AM:1115201800024
*/

#include <stdio.h>
#include <stdlib.h>
#include "Session.h"
#include <string.h>
#include "print_opts.h"

int main(int argc, char *argv[]) {
	int x,stop=0,sesindex = 1;
	char name[80]="default";
	InfoSessionPtr 	MySession1=NULL, MySession2=NULL, CurrSession;
	print_options();
	scanf("%d",&x);
	CurrSession = MySession1;
	while(!stop){
		switch(x){
			case 0: stop = 1;	/*flag pou deixnei pote prepei na stamathsei h sunarthsh*/
				break;
			case 1:	strcpy(name,"default");
				CurrSession = SessionNew(name);
				if(sesindex == 1)	/*Index gia to poio session xeirizomaste*/
					MySession1 = CurrSession;	/*Kai analoga me thn timh tou index pername thn nea dieu8hnsh ston antistoixo InfoSessionPtr*/
				else
					MySession2 = CurrSession;
				break;
			case 2:	SessionNewTab(CurrSession);
				break;
			case 3: SessionTabShow(CurrSession);
				break;
			case 4: SessionTabNext(CurrSession);
				break;
			case 5: SessionTabPrev(CurrSession);
				break;
			case 6: SessionTabMoveLeft(CurrSession);
				break;
			case 7:	SessionTabMoveRight(CurrSession);
				break;
			case 8: scanf("%s",name);
				SessionNewOpeningAddress(CurrSession,name);
				break;
			case 9: SessionShowOpeningAddress(CurrSession);
				break;
			case 10:SessionSiteNext(CurrSession);
				break;
			case 11:SessionSitePrev(CurrSession);
				break;
			case 12:SessionSiteShow(CurrSession);
				break;
			case 13:SessionTabClose(&CurrSession);
				break;
			case 14:SessionClose(&CurrSession);
				break;
			case 15:scanf("%s",name);
				SessionNewAddress(CurrSession,name);
				break;
			case 16:scanf("%d",&x);
				if(x==1){
					sesindex = 1; /*Ka8e fora poy epilegei o xrhsths kapoio Session allazoume thn die8unsh tou CurrSession kai to index analoga*/
					CurrSession = MySession1;
				}else if(x==2){
					sesindex = 2;
					CurrSession = MySession2;
				}else
					printf("This Session doesn't exist\n");
				break;
			default:printf("Unknown command\n");
		}
		if(!stop){
			print_options();
			scanf("%d",&x);
		}
	}
}

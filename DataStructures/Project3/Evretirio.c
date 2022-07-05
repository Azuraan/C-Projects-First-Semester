#include "Evretirio.h"

#define Simple 0 /* 0 for AVL - any Evr integer for Simple  */
/* Oi diafores tvn ylopoihsevn Simple kai AVL einai mikres - mporeite na xrhsimopoihsete 
   thn  domh #if ... #else ...#endif gia na diaforopihsete tis dyo ylopoihseis  */

#if (Simple)
#include "BST/ch8_BSTpointer.h" /* gia Simple Ylopoihsh */
void Tree_endodiatajh(EvrPtr E,FILE *out,typos_deikti root,int *counter);
#else
#include "AVL/ch8_AVLpointer.h" /* gia AVL Ylopoihsh */
void AVLTree_endodiatajh(EvrPtr E,FILE *out,typos_deikti root,int *counter);
#endif


struct EvrNode{
       TStoixeiouEvr *DataArray; /* array of size MaxSize */
       int Index;              /* index of first available element in array */
       typos_deikti TreeRoot;     /* Root of DDA */
} EvrNode;
/*Genika se oles tis synarthseis Evr pou zhtaei h ekfwnhsh xrhsimopoiw sunarthseis twn BST kai AVL*/
EvrPtr EvrConstruct(int MaxSize){
/* Oi diafores tvn ylopoihsevn Simple kai AVL einai mikres -
	mporeite na xrhsimopoihsete thn  domh #if ... #else ...#endif */
	EvrPtr NewEvr = malloc(sizeof(EvrNode));
	NewEvr->DataArray = malloc(MaxSize*sizeof(TStoixeiouEvr));
	NewEvr->Index = 0;

   typos_deikti TreeRoot;
	#if (Simple)
   		printf("use simple BST\n");
   		Tree_dimiourgia(&TreeRoot);
	#else
    		printf("use AVL BST\n");
    		AVLTree_dimiourgia(&TreeRoot);
	#endif
   NewEvr->TreeRoot = TreeRoot;
	return NewEvr;
}
int EvrAVLorBST(){
	return Simple;
}

int EvrInsert(EvrPtr E, TStoixeiouEvr Data){
	if(E==NULL)
		return 2;
							/*Gia error checking sthn insert 8ewrw san error kuriws na dwsoume san parametro keno Evr*/
	int error=0;
	E->DataArray[E->Index] = Data;				/*Kai epeita prokeimenou na mhn sunexisei parakatw se periptwsh pou den brei to stoixeio*/
	TStoixeiouDDA stoixeio;						/*8ewrw san apotuxeia-error na mhn brei to stoixeio*/
	stoixeio.key = Data.AirportID;
	stoixeio.arrayIndex = E->Index;

	#if(Simple)
		Tree_eisagogi(&(E->TreeRoot), stoixeio, &error);
		if(error)
			return error;
	#else
		int ypsylotero;
		AVLTree_eisagogi(&(E->TreeRoot), stoixeio,&ypsylotero ,&error);
		if(error)
			return error;
	#endif

	E->Index++;
	return 0;
 }

int EvrSearch(EvrPtr E, keyType key, int InOut, int * found){
	if(E==NULL)			/*8ewrw error pali to keno Evr kai epeita prokeimenou na mhn sunexisei parakatw se periptwsh pou den brei to stoixeio*/
		return 1;			/*8ewrw san apotuxeia-error na mhn brei to stoixeio*/

	typos_deikti deiktis;
	TStoixeiouDDA stoixeio;			/*Arxikopoiw to melos key enos stoixeiou typou TStoixeiouDDA afou mono auto xreiazomai sthn anazhthsh gia tis sygkriseis*/
	stoixeio.key = key;

	#if(Simple)
		Tree_anazitisi(E->TreeRoot, stoixeio , &deiktis , found);
		 if(*found==0)
                  return 2;
		Tree_periexomeno(deiktis, &stoixeio);
	        if((*found) && InOut==0)
	                E->DataArray[stoixeio.arrayIndex].countIN++;
        	else if((*found) && InOut==1)
                	E->DataArray[stoixeio.arrayIndex].countOUT++;

	#else
		AVLTree_anazitisi(E->TreeRoot, stoixeio , &deiktis , found);
		if(*found==0)
                  return 2;
		AVLTree_periexomeno(deiktis, &stoixeio);
		if((*found) && InOut==0)
                	E->DataArray[stoixeio.arrayIndex].countIN++;
        	else if((*found) && InOut==1)
                	E->DataArray[stoixeio.arrayIndex].countOUT++;
	#endif

return 0;
}


int EvrPrintAll(EvrPtr E, FILE *out, int * counter){
//typos_deikti a=E->TreeRoot;
if(E==NULL)
	return 1;	/*Kurio error keno Evr*/

#if (Simple)	/*Ylopoihsa dyo nees anadromikes sunarthseis basismenos sthn endodiatajh poy eidame kata thn diarkeia twn ma8hmatwn*/
	Tree_endodiatajh(E,out,E->TreeRoot,counter);
#else
	AVLTree_endodiatajh(E,out,E->TreeRoot,counter);
#endif


return 0;
}

int EvrDestruct(EvrPtr *E){
int i;
	if(*E==NULL)
		return 1;
	for(i=0;i< (*E)->Index;i++)
		TSEvr_eraseValue(&((*E)->DataArray[i]));	/*kanw free otan ta malloc pou ekane h TSEvr_readvalue*/

	free((*E)->DataArray);
	#if(Simple)
		Tree_katastrofi(&((*E)->TreeRoot));
	#else
		AVLTree_katastrofi(&((*E)->TreeRoot));
	#endif

	free(*E);
	*E = NULL;
return 0;
}

#if(Simple)
void Tree_endodiatajh(EvrPtr E,FILE *out,typos_deikti root,int *counter){
	if(!Tree_keno(root)){
	 Tree_endodiatajh(E,out,Tree_apaidi(root),counter);
	 TStoixeiouDDA stoixeio;
         Tree_periexomeno(root, &stoixeio);
         fprintf(out,"AirportID;%d;Anaxwrhseis=%d;Afijeis=%d\n",stoixeio.key,E->DataArray[stoixeio.arrayIndex].countOUT,E->DataArray[stoixeio.arrayIndex].countIN);
	 (*counter)++;
	 Tree_endodiatajh(E,out,Tree_dpaidi(root),counter);
	}
}
#else
void AVLTree_endodiatajh(EvrPtr E,FILE *out,typos_deikti root,int *counter){
        if(!AVLTree_keno(root)){
         AVLTree_endodiatajh(E,out,AVLTree_apaidi(root),counter);
	 TStoixeiouDDA stoixeio;
	 AVLTree_periexomeno(root, &stoixeio);	/*Xrhsimopoiw thn sunarthsh periexomeno wste na anakthsw ta dedomena tou dentrou ta opoia einai krufa logw olikhs apokrupshs*/
	 fprintf(out,"AirportID;%d;Anaxwrhseis=%d;Afijeis=%d\n",stoixeio.key,E->DataArray[stoixeio.arrayIndex].countOUT,E->DataArray[stoixeio.arrayIndex].countIN);
	 (*counter)++;
         AVLTree_endodiatajh(E,out,AVLTree_dpaidi(root),counter);
        }
}
#endif

/*Anaxwrhseis einai 3es kai afijeis einai 5es*/

int Evr_EisagwghAnaxwrhsewnAfijewn(FILE *from,EvrPtr E,int *notFound,int *yesFound){
  keyType key;
  int i,j,k,found;
  char buf[1024],temp[80];

         fgets(buf,1024,from);
                j=0;

                for(i=0;i<9;i++){
                     if((i!= 3)&&(i!=5)){
                        while(buf[j] != ';' && buf[j] != '\n')	/*Xrhsimopoiw paromoia logikh me thn readvalue*/
                                j++;				/*Mono pou diabazw dedomena mono otan exw i=3 h i=5 gt einai ta antistoixa source kai destination ids*/
                        j++;					/*Kai epeita kanw search auta me thn EvrSearch kai analoga metabalw tous metrhtes*/
                     }else if(i==5){
                        k=0;
                        while(buf[j] != ';' && buf[j] != '\n'){
                           temp[k] = buf[j];
                           k++;
                           j++;
                        }
                        temp[k]='\0';
                        j++;

                        key = atoi(temp);
                        if(EvrSearch(E,key,0,&found)==1){
				printf("Evr pointer points at NULL : You must create an Evr first\n");
				return 1;
			}
			if(found)
				(*yesFound)++;
			else
				(*notFound)++;
                     }else if(i==3){
                        k=0;
                        while(buf[j] != ';' && buf[j] != '\n'){
                           temp[k] = buf[j];
                           k++;
                           j++;
                        }
                        temp[k]='\0';
                        j++;

                        key = atoi(temp);
                        if(EvrSearch(E,key,1,&found)==1){
                                printf("Evr pointer points at NULL : You must create an Evr first\n");
                                return 1;
                        }
			if(found)
				(*yesFound)++;
			else
				(*notFound)++;
		     }
     		}

return 0;
}

int power(int x){	/*Ypologismos dunameis tou duo*/
int i,y=1;
	for(i=0;i<x;i++)
		y=y*2;
return y;
}

int MetraEisagwgh(int x){
int n;
	for(n=9;n<13;n++)	/*Sunarthsh pou ka8orizei poteektupwnetai o xronos gia stoixeia 2^n-1*/
		if(x == power(n)-1){
			printf("N %d\n",n);return 1;}
return 0;
}

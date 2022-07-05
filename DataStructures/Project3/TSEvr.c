#include "TSEvr.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int TSEvr_setValue (TStoixeiouEvr *target, TStoixeiouEvr source){
	*target =source;
	return 0;
}

int TSEvr_readValue (FILE *from,  TStoixeiouEvr *Elem){
int i,j,k;
char buf[1024],temp[80];

                fgets(buf,1024,from);
                j=0;
	if(!feof(from)){
                for(i=0;i<6;i++){
                        k=0;
                        while(buf[j] != ';' && buf[j] != '\n'){
                                temp[k] = buf[j];
                                k++;
                                j++;
                        }
                        temp[k]='\0';
                        j++;

                        switch(i){
                                case 0: Elem->AirportID = atoi(temp);
					break;
                                case 1: Elem->Name = malloc((strlen(temp)+1)*sizeof(char));
					assert(Elem->Name);
                                        strcpy(Elem->Name,temp);
                                        break;
                                case 2: Elem->City = malloc((strlen(temp)+1)*sizeof(char));
					assert(Elem->City);
                                        strcpy(Elem->City,temp);
                                        break;
                                case 3: Elem->Country = malloc((strlen(temp)+1)*sizeof(char));
					assert(Elem->Country);
                                        strcpy(Elem->Country,temp);
                                        break;
                                case 4: if(strlen(temp)+1 > 4){
                                         printf("Error:Too many letters for IATA\n");
					 return 1;
					}
                                        else{
                                         strcpy(Elem->IATA,temp);
                                        }
                                        break;
                                case 5: if(strlen(temp)+1 > 5){
                                         printf("Error:Too many letters for ICAO\n");
					 return 1;
					}
                                        else{
                                         strcpy(Elem->ICAO,temp);
                                        }
                                        break;
                        }/*end of switch*/
                }/*end of for(i=0;i<6;i++)*/
		Elem->countIN=0;
		Elem->countOUT=0;
		return 0;
	}else{
		return 1;
	}

}

int TSEvr_writeValue(FILE *to, TStoixeiouEvr Elem){
	int n=fprintf(to,"%d;%s;%s;%s;%s;%s\n",Elem.AirportID,Elem.Name,Elem.City,Elem.Country,Elem.IATA,Elem.ICAO);
	return (n==6);
}

void TSEvr_eraseValue(TStoixeiouEvr *Elem){
	Elem->AirportID = 0;
	free(Elem->Name);Elem->Name=NULL;
	free(Elem->City);Elem->City=NULL;
	free(Elem->Country);Elem->Country=NULL;
}

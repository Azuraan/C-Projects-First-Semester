#include "AirportManagement.h"

int AirportInput(FILE *AirportFile,EvrPtr E,int *totalNumbOfElems,clock_t t1,clock_t t2,double ratio){
TStoixeiouEvr Input;

        t1 = clock();

        while(!feof(AirportFile)){
                if(!TSEvr_readValue(AirportFile, &Input)){
                     if(EvrInsert(E, Input)){
                         printf("Error occured while inserting items\n");
			 return 1;
                     }else{
                        (*totalNumbOfElems)++;

                     	if(MetraEisagwgh(*totalNumbOfElems)){
                        	t2 = clock();
                        	printf("Time passed until 2^N-1(N={9,10,11,12}) = %g seconds\n", ratio*(long)t2 - ratio*(long)t1 );
                     	}
		     }/*else*/
                }
        }/*end of while(!feof(DataFile))*/
        t2 = clock();

        printf("\nTime of inserting = %g seconds\n", ratio*(long)t2 - ratio*(long)t1 );
        printf("Total number of elements inserted: %d\n",*totalNumbOfElems);
	printf("Mesos oros eisagwghs %g\n",(ratio*(long)t2 - ratio*(long)t1 )/(*totalNumbOfElems));
return 0;
}

int AirportEnhmerwsh(FILE *RoutesFile,FILE *OutPutFile,EvrPtr E,int *connections,clock_t *t1,clock_t *t2,int *notFound,int *Found,double ratio){

        *t1 = clock();

        while(!feof(RoutesFile)){
                (*connections)++;
                if(Evr_EisagwghAnaxwrhsewnAfijewn(RoutesFile,E,notFound,Found)==1)
			return 1;
        }
        *t2 = clock();

        fprintf(OutPutFile,"Time of searching = %g seconds\n",ratio*(long)(*t2) - ratio*(long)(*t1));
return 0;
}

int AirportEnhmerwshSunexeia(FILE *OutPutFile,int connections,clock_t t1,clock_t t2,int notFound,int Found,int totalNumbOfElems,double ratio){
double mesos;
        fprintf(OutPutFile,"Total :%d ; NotFound :%d ; Found :%d\n",connections,notFound,Found);
	if(totalNumbOfElems==0)
		return 1;
        mesos=(ratio*(long)t2 - ratio*(long)t1)/totalNumbOfElems;
        fprintf(OutPutFile,"Mesos Xronos Anazhthshs : %g s\n",mesos);
	fprintf(OutPutFile,"Mesos Xronos Anazhthshs ws pros to plh8os autwn poy bre8hkan : %g s\n",(ratio*(long)t2 - ratio*(long)t1)/Found);
return 0;
}

int AirportEktupwsh(FILE *OutPutFile,EvrPtr E,clock_t t1,clock_t t2,int *counter,double ratio){

        t1 = clock();
        EvrPrintAll( E, OutPutFile, counter);
        t2 = clock();
        printf("\nTime of printing = %g seconds\n", ratio*(long)t2 - ratio*(long)t1 );
        printf("Printed %d elements\n",*counter);
return 0;
}

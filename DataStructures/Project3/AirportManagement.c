/************************************************************************
Programma pelaths	: AirportManagement.c
Syggrafeas			: 
Skopos				: skeleton main for askhsh 3
*************************************************************************/
#include "AirportManagement.h"

int main(int argc, char *argv[])
{

/*File Management and Airport management Variables*/
  EvrPtr E;
  FILE *AirportFile,*RoutesFile,*OutPutFile;
  int totalNumbOfElems=0,connections=0,Found=0,notFound=0,counter=0;
  E=EvrConstruct(7200);
  char *strAirport,*strOutput;

/*Time Variables*/
   clock_t t1, t2;
   double ratio = 1./CLOCKS_PER_SEC;

/*Checking user's options*/
if(argc<2){
 printf("Wrong Input!\n");
 return 1;
}
/*Ginetai epilogi tou katallhlou arxeiou gia eisodo kai to antistoixoy gia e3odo xrhsimopoiwntas ta orismata ths main kai thn synarthsh EvrAVLorBST pou epistrefei to simple*/
if(!strcmp(argv[1],"sorted"))
	strAirport = "airportsLinuxSorted.txt";
else if(!strcmp(argv[1],"random"))
	strAirport = "airportsLinuxRandom.txt";
else{
	printf("Wrong Input!Type sorted or random\n");
	return 1;
}
printf("Current Input from %s file\n",strAirport);

if(!strcmp(argv[1],"random") &&  EvrAVLorBST())
	strOutput = "OUTPUTRandomBST.txt";
else if(!strcmp(argv[1],"random") && !EvrAVLorBST())
	strOutput = "OUTPUTRandomAVL.txt";
else if(!strcmp(argv[1],"sorted") && EvrAVLorBST())
	strOutput = "OUTPUTSortedBST.txt";
else if(!strcmp(argv[1],"sorted") && !EvrAVLorBST())
	strOutput = "OUTPUTSortedAVL.txt";
else{
	printf("Wrong Input!Type sorted or random\n");
	return 1;
}
printf("Current Output to %s file\n",strOutput);

  if((AirportFile = fopen(strAirport,"r"))==NULL){
	printf("Error occured while opening airports' source file\n");
	return 1;
  }

  if((RoutesFile = fopen("routesLinux.txt","r"))==NULL){
        printf("Error occured while opening routes' source file\n");
        return 1;
  }

  if((OutPutFile = fopen(strOutput,"w"))==NULL){
	printf("Error occured while opening destination file\n");
	return 1;
  }

	if(AirportInput(AirportFile,E,&totalNumbOfElems,t1,t2,ratio))
		return 1;

  	if(AirportEnhmerwsh(RoutesFile,OutPutFile,E,&connections,&t1,&t2,&notFound,&Found,ratio))
		return 1;

	fclose(OutPutFile);
/*Anoigw arxika to OutPutFile me w mode prokeimenou na diagraf8oun ta prohgoymena stoixeia tou arxeiou an uphrxe kai epeite to kleinw kai to jananoigw*/
  if((OutPutFile = fopen(strOutput,"a"))==NULL){			/*Me mode a wste na sunexistei h ektupwsh xwris diagrafh twn newn dedomenwn pou pros8esa*/
        printf("Error occured while opening destination file\n");
        return 1;
  }

	if(AirportEnhmerwshSunexeia(OutPutFile,connections,t1,t2,notFound,Found,totalNumbOfElems,ratio))
		return 1;
	if(AirportEktupwsh(OutPutFile,E,t1,t2,&counter,ratio))
		return 1;

	if(EvrDestruct(&E))
		printf("Error while destroying Evr: Empty Evr!\n");

	fclose(AirportFile);
	fclose(RoutesFile);
	fclose(OutPutFile);

  getchar();
  return 0;
}

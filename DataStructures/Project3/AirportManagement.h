#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TSEvr.h"
#include "TSDDA.h"
#include "Evretirio.h"

int AirportInput(FILE *AirportFile,EvrPtr E,int *totalNumbOfElems,clock_t t1,clock_t t2,double ratio);
int AirportEnhmerwsh(FILE *RoutesFile,FILE *OutPutFile,EvrPtr E,int *connections,clock_t *t1,clock_t *t2,int *notFound,int *Found,double ratio);
int AirportEnhmerwshSunexeia(FILE *OutPutFile,int connections,clock_t t1,clock_t t2,int notFound,int Found,int totalNumbOfElems,double ratio);
int AirportEktupwsh(FILE *OutPutFile,EvrPtr E,clock_t t1,clock_t t2,int *counter,double ratio);

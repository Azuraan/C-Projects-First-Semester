#ifndef __TSEvr__
#define __TSEvr__

#include <stdio.h>
#include "TSDDA.h"

typedef struct data {
        /*  members for airport data in array */
	keyType AirportID;
	char *Name;
	char *City;
	char *Country;
	char IATA[4];
	char ICAO[5];
	int countIN;
	int countOUT;
} TStoixeiouEvr;

int TSEvr_setValue (TStoixeiouEvr *target, TStoixeiouEvr source);

int TSEvr_readValue (FILE *from,  TStoixeiouEvr *Elem);

int TSEvr_writeValue(FILE *to, TStoixeiouEvr Elem);

void TSEvr_eraseValue(TStoixeiouEvr *Elem);
#endif

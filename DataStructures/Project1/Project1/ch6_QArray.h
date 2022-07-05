/**********************************************+**************************
Header File Name		: QArray.h
Author Date				: Y. Cotronis 07/03/2016
Purpose					: Header file of ATD Queue - counter - array
Revision				:  <Your Name - Date>
Onomatepwnhmo:Gewrgios Galanhs
AM:1115201800024
**************************************************************************/
#ifndef __CH2_QARRAY__ 
#define __CH2_QARRAY__
#include "TStoixeiouOuras.h"


#define QSIZE 1000

typedef struct {
	int embros;		/* position of first element */
	int piso;		/* position of last  element */
	int metritis;   /* counter - elements in queue */
	TSOuras pinakas[QSIZE];	/* array of queue elements */
        int CountIn;
        int CountOut;
} TOuras;	   /* New Name of Type Queue */

void OuraDimiourgia(TOuras *oura);

int	OuraKeni	(TOuras oura);

int OuraProsthesi	(TOuras *oura, TSOuras stoixeio);
int OuraApomakrynsh (TOuras *oura, TSOuras *stoixeio);

int OuraGetSize(TOuras);
int GetCountIn(TOuras);
int GetCountOut(TOuras);
#endif


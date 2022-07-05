/*Onomateponumo: Gewrgios Galanhs
  AM:1115201800024
*/

#ifndef __SESSION__
#define __SESSION__

typedef struct InfoSession *InfoSessionPtr;

InfoSessionPtr SessionNew(char *);
void SessionNewTab(InfoSessionPtr);

/* The rest of the interface functions follow */
void SessionTabShow(InfoSessionPtr);
void SessionTabNext(InfoSessionPtr);
void SessionTabPrev(InfoSessionPtr);
void SessionTabMoveLeft(InfoSessionPtr);
void SessionTabMoveRight(InfoSessionPtr);
void SessionNewOpeningAddress(InfoSessionPtr,char *);
void SessionShowOpeningAddress(InfoSessionPtr);
void SessionSiteNext(InfoSessionPtr);
void SessionSitePrev(InfoSessionPtr);
void SessionSiteShow(InfoSessionPtr);
void SessionTabClose(InfoSessionPtr *);
void SessionClose(InfoSessionPtr *);
void SessionNewAddress(InfoSessionPtr ,char *);
#endif

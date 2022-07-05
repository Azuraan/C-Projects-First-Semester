/********************************
Onomatepwnhmo:Gewrgios Galanhs
AM:1115201800024
*********************************/
#ifndef _CONTROLLER_
#define _CONTROLLER_

typedef struct {
      int TimeBusy;
      int TimeInactive;
      int ArithmoPelaton;
      int enapomenonXronos;
} TController;

void ControllerDimiourgia(TController *Controller);
void ControllerNewCustomer(TController *Controller);
void ControllerSetXrono(TController *Controller,int xronosEksipiretisis);

void ControllerNoWork(TController *Controller);
void ControllerBusy(TController *Controller);

int ControllerFree(TController Controller);
int ControllerGetArithmosPelatwn(TController Controller);
int ControllerGetEnapomenonXronos(TController Controller);
int ControllerGetInactiveXronos(TController Controller);
int ControllerGetBusyXronos(TController Controller);
#endif

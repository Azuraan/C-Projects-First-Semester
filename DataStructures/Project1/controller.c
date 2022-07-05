/***********************************************
Onomatepwnhmo:Gewrgios Galanhs
AM:1115201800024
************************************************/
#include "controller.h"

void ControllerDimiourgia(TController *Controller)	/*Arxikopoiei tis metablhtes pou xeirizomaste gia ton elegkth*/
{           Controller->TimeBusy=0;
            Controller->TimeInactive=0;
            Controller->ArithmoPelaton=0;
            Controller->enapomenonXronos=0;
}

void ControllerNewCustomer(TController *Controller)
{
            Controller->ArithmoPelaton++;
            Controller->TimeBusy++;
}

void ControllerSetXrono(TController *Controller,int xronosEksipiretisis)
{
            Controller->enapomenonXronos = xronosEksipiretisis;
}

void ControllerNoWork(TController *Controller)
{
            Controller->TimeInactive++;
}

void ControllerBusy(TController *Controller)
{
            Controller->TimeBusy++;
            Controller->enapomenonXronos--;
}

int ControllerFree(TController Controller)
{
            return (Controller.enapomenonXronos == 0);
}

int ControllerGetArithmosPelatwn(TController Controller)
{
            return Controller.ArithmoPelaton;
}

int ControllerGetEnapomenonXronos(TController Controller)
{
            return Controller.enapomenonXronos;
}

int ControllerGetInactiveXronos(TController Controller)
{
            return Controller.TimeInactive;
}

int ControllerGetBusyXronos(TController Controller)
{
            return Controller.TimeBusy;
}

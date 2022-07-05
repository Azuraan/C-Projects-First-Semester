/*************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 07/03/2016
Skopos				: Ylopoihsh ouras prosomoiwshs
Revision 			:  <Your Name - Date>
Onomatepwnhmo:Gewrgios Galanhs
AM:1115201800024
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMEIA 5	/*Plh8os tameiwn kai antistoixa ourwn*/

#include "ch6_QArray.h"
#include "TStoixeiouOuras.h"
#include "controller.h"

int main(void)
{	TOuras		oura[TAMEIA];				 /*oura pelatwn-aytokinhtvn */
	float			pithanotita_afiksis; /*pi8anothta afikshs*/
	unsigned int	megistos;	/*megistos kai elaxistos xronos e3yphrethshs enos pelath*/
        unsigned int    elaxistos;
	unsigned int	xronos_prosomoiosis;	 /*synolikos xronos prosomoiwshs*/
	TController	Tamias[TAMEIA];
	unsigned int	xronos;				 /*roloi prosomoiwshs*/
	unsigned int	arithmos_pelatwn; 	 /*plh8os e3yphreth8entwn pelatwn*/
	unsigned int	xronos_anamonis;	 /*synolikos xronos anamonhs*/

	TSOuras		Pelatis;		 	/* o pelaths sthn oyra*/
	float			mesos_xronos;		 /*mesos xronos anamonhs tvn pelatvn*/
	float			randomAfixi;
	time_t			t;
	int		i,pos,min;

	printf("Dwste units of time prosomoiwshs (0 <=), pi8anothta afikshs in unit of time (0,1), elaxisto kai megisto xrono e3yphrethshs (>=1) in unit of times )\n");
	scanf("%u %f %u %u",&xronos_prosomoiosis,&pithanotita_afiksis,&elaxistos,&megistos);
	getchar();
	printf("H prosomoiwsh 8a diarkesei %4u units of time.\n",xronos_prosomoiosis);
	printf("H pi8anothta afikshs pelath se ena unit of time einai: %4.2f.\n",pithanotita_afiksis);
	printf("O megistos xronos e3yphrethshs einai %d kai o elaxistos xronos e3yphrethshs einai %d .\n",megistos,elaxistos);

   for(i=0;i<TAMEIA;i++){
        OuraDimiourgia(&oura[i]);
        ControllerDimiourgia(&Tamias[i]);
   }
	xronos = 0;
	arithmos_pelatwn = 0;
	xronos_anamonis =0;
	srand(time(&t));

	while( xronos < xronos_prosomoiosis )
	{	/* Pelatis- Aytokinhto  */
		randomAfixi = (float)rand()/(float)RAND_MAX; 

		if ( randomAfixi < pithanotita_afiksis ){
			PelatisSetXronoEisodou(&Pelatis, xronos);
                        PelatisSetXronoEksipiretisis(&Pelatis,rand()%(megistos-elaxistos+1)+elaxistos); /*Ypologismos tuxaiou ari8mou sto diasthma [min,max]*/
			min=QSIZE+1;
			for(i=0;i<TAMEIA;i++)
			  if(OuraGetSize(oura[i])<min){		/*Eyresh ths ouras me to elaxisto plh8os atomwn gia na paei o pelaths se authn*/
                            min=OuraGetSize(oura[i]);
			    pos=i;
			  }
			if (!OuraProsthesi(&oura[pos], Pelatis)){
                  printf("H oyra einai mikrh! H prosomoivsh stamataei \n");
                  getchar();
                  return 0;
        	};
    	};

    	/* Tamias-Elegxos */
    	  for(i=0;i<TAMEIA;i++){
		if ( ControllerFree(Tamias[i]) )	/*eley8eros tamias*/
			if (!OuraKeni(oura[i]))			/*yparxei pelaths*/
			{	OuraApomakrynsh(&oura[i],&Pelatis);		/*phgainei sto tamio*/
				xronos_anamonis += ControllerGetInactiveXronos(Tamias[i]) + ControllerGetBusyXronos(Tamias[i]) - PelatisGetXronoEisodou(Pelatis);
									/*ypologismos xronoy paramonhs sthn oura*/
			/*Me tis synarthseis ControllerGetInactiveXronos kai ControllerGetBusyXronos exoume san apotelesma tou a8roismatos tous ton perasmeno xrono */
				ControllerNewCustomer(&Tamias[i]);
				ControllerSetXrono(&Tamias[i], PelatisGetXronoEksipiretisis(Pelatis)-1); /* kallyptei to trexon unit time*/
			}else ControllerNoWork(&Tamias[i]);   /*Bazw PelatisGetXronoEksipiretisis(Pelatis)-1) giati perase mia monada hdh otan arxise na e3uphreteitai*/
		else ControllerBusy(&Tamias[i]);		/*o tamias apasxolhmenos me pelath opote au3anetai to TimeBusy kai meiwnetai o enapomenon xronos */
	  }
		xronos++; /*o xronos prosomoivshs ay3anetai kata 1 unit of time*/
	} /*while( xronos < xronos_prosomoiosis )*/

	printf("\n");
	for(i=0;i<TAMEIA;i++){
	   arithmos_pelatwn+=ControllerGetArithmosPelatwn(Tamias[i]);
	   printf("O elegkths %d eksyphrethse %d pelates\n",i,ControllerGetArithmosPelatwn(Tamias[i]));
	   printf("Htan apasxolhmenos gia %d units of time\n", ControllerGetBusyXronos(Tamias[i]));
	   printf("Htan adranhs gia %d units of time\n", ControllerGetInactiveXronos(Tamias[i]));
	   printf("Sthn oura %d:\nExoun meinei %d autokinhta\n",i,OuraGetSize(oura[i])); /*Ta amaksia pou emeinan einai sthn ousia osa paremeinan sthn oura*/
           printf("Den eksyphreth8hkan %d pelates\n",GetCountIn(oura[i])-GetCountOut(oura[i]));/*Amaksia pou mphkan kai den bghkan profanws den eksuphreth8hkan*/
           printf("Mphkan sthn oura %d pelates\n",GetCountIn(oura[i]));
           printf("Bghkan apo thn oura %d pelates\n\n",GetCountOut(oura[i]));

	}
	if ( arithmos_pelatwn == 0)
		mesos_xronos = 0.0;
	else
		mesos_xronos = ((float)xronos_anamonis)/((float) arithmos_pelatwn);

	printf("O mesos xronos anamonhs htan %4.2f units of time.\n",mesos_xronos);

    getchar();
	return 0;
}


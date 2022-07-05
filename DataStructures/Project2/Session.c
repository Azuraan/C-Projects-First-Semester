/*Onomateponumo: Gewrgios Galanhs
  AM:1115201800024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Session.h"
#include <assert.h>
typedef struct TabNode *TabNodePtr;
typedef struct SiteNode *SiteNodePtr;


struct InfoSession {
	TabNodePtr FirstTab;
	TabNodePtr LastTab;
	TabNodePtr CurrTab;
	TabNodePtr AuxTab;
	char* 	  OpeningAddress;
};

struct TabNode{
	TabNodePtr PrevTab, NextTab;
	SiteNodePtr FirstSite;
	SiteNodePtr CurrSite;
};
					/*Opou kanw malloc xrhsimopoiw assert gia na sigoureutw oti den epistrefei NULL*/
struct SiteNode{				/*Ka8e sunarthsh kanei oti zhtaei h ekfwnhsh kai threi thn sundesh malloc-free(opou uparxei) sto module */
	SiteNodePtr PrevSite, NextSite;
	TabNodePtr UpTab;
	char *Address;
};


InfoSessionPtr SessionNew(char * OpeningAddress){
	InfoSessionPtr	newSes = malloc(sizeof(struct InfoSession));
	assert(newSes);
	TabNodePtr tab = malloc(sizeof(struct TabNode));
	assert(tab);
	SiteNodePtr site = malloc(sizeof(struct SiteNode));
	assert(site);
	newSes->OpeningAddress = malloc(strlen(OpeningAddress)+1);
	assert(newSes->OpeningAddress);
	strcpy(newSes->OpeningAddress,OpeningAddress);
	newSes->FirstTab = tab;
	newSes->LastTab = tab;
	newSes->CurrTab = tab;
	newSes->AuxTab = NULL;
	tab->PrevTab = tab;
	tab->NextTab = tab;
	tab->FirstSite = site;
	tab->CurrSite = site;
	site->PrevSite = NULL;
	site->NextSite = NULL;
	site->UpTab = tab;
	site->Address = malloc(strlen(OpeningAddress)+1);
	assert(site->Address);
	strcpy(site->Address,OpeningAddress);
return newSes;
}

void SessionNewTab(InfoSessionPtr Session){
	SiteNodePtr site = malloc(sizeof(struct SiteNode));
	assert(site);
	TabNodePtr newtab = malloc(sizeof(struct TabNode));
	assert(newtab);
	Session->LastTab = newtab;
	Session->FirstTab->PrevTab = Session->LastTab;
	Session->CurrTab = newtab;
	Session->AuxTab = Session->FirstTab;
		while(Session->AuxTab->NextTab != Session->FirstTab)
			Session->AuxTab = Session->AuxTab->NextTab;
		Session->AuxTab->NextTab = newtab;
		newtab->NextTab = Session->FirstTab;
		newtab->PrevTab = Session->AuxTab;
		newtab->FirstSite = site;
		newtab->CurrSite = site;
        	site->PrevSite = NULL;
	        site->NextSite = NULL;
		site->UpTab = newtab;
		site->Address = malloc(strlen(Session->OpeningAddress)+1);
		assert(site->Address);
		strcpy(site->Address,Session->OpeningAddress);
}

/* The rest of the interface functions follow */
void SessionTabShow(InfoSessionPtr Session){

	printf("Contents of current tab's current site: %s\n",Session->CurrTab->CurrSite->Address);
}

void SessionTabNext(InfoSessionPtr Session){

	Session->CurrTab = Session->CurrTab->NextTab;
}

void SessionTabPrev(InfoSessionPtr Session){

	Session->CurrTab = Session->CurrTab->PrevTab;
}

void SessionTabMoveLeft(InfoSessionPtr Session){
	if(Session->CurrTab != Session->FirstTab){
		if(Session->CurrTab == Session->LastTab)
			Session->LastTab = Session->CurrTab->PrevTab;	/*Xrhsimopoiwntas ton AuxTab deikth sthn ousia allazw tis times sugkekrimenwn deiktwn*/
		if(Session->FirstTab == Session->CurrTab->PrevTab)	/*Wste na metakinhsw thn CurrTab aristera kai h lista na mhn xanei kapoia sundesh kombwn*/ 
			Session->FirstTab = Session->CurrTab;
		Session->AuxTab = Session->CurrTab->PrevTab;
		Session->AuxTab->PrevTab->NextTab = Session->CurrTab;
		Session->CurrTab->PrevTab = Session->AuxTab->PrevTab;
		Session->AuxTab->NextTab = Session->CurrTab->NextTab;
		Session->CurrTab->NextTab = Session->AuxTab;
		Session->AuxTab->NextTab->PrevTab = Session->AuxTab;
		Session->AuxTab->PrevTab = Session->CurrTab;
	}else{
		printf("You can't place current tab to the left any further\n");
	}
}

void SessionTabMoveRight(InfoSessionPtr Session){
	if(Session->CurrTab != Session->LastTab){
		if(Session->CurrTab == Session->FirstTab)
			Session->FirstTab = Session->CurrTab->NextTab;
		if(Session->CurrTab->NextTab == Session->LastTab)
			Session->LastTab = Session->CurrTab;
		Session->CurrTab = Session->CurrTab->NextTab;	/*H SessionTabMoveRight apotelei antigrafh ths SessionTabMoveLeft*/
                Session->AuxTab = Session->CurrTab->PrevTab;	/*Wstoso epi8umw na alla3w thn 8esh tou epomenou Tab apo to CurrTab mia 8esh aristera prokeimenou*/
                Session->AuxTab->PrevTab->NextTab = Session->CurrTab;	/*sto telos to CurrTab na topo8eth8ei mia 8esh de3ia*/
                Session->CurrTab->PrevTab = Session->AuxTab->PrevTab;
                Session->AuxTab->NextTab = Session->CurrTab->NextTab;
                Session->CurrTab->NextTab = Session->AuxTab;
                Session->AuxTab->NextTab->PrevTab = Session->AuxTab;
                Session->AuxTab->PrevTab = Session->CurrTab;
                Session->CurrTab = Session->AuxTab;
	}else{
		printf("You can't place current tab to the right any further\n");
	}
}

void SessionNewOpeningAddress(InfoSessionPtr Session,char *str){

	free(Session->OpeningAddress);
	Session->OpeningAddress = malloc(strlen(str)+1);
	strcpy(Session->OpeningAddress,str);
}

void SessionShowOpeningAddress(InfoSessionPtr Session){

	printf("Current Opening address is %s\n",Session->OpeningAddress);
}

void SessionSiteNext(InfoSessionPtr Session){
	if(Session->CurrTab->CurrSite->NextSite != NULL)
		Session->CurrTab->CurrSite = Session->CurrTab->CurrSite->NextSite;
	else
		printf("There's no site that follows current site\n");
}

void SessionSitePrev(InfoSessionPtr Session){
	if(Session->CurrTab->CurrSite->PrevSite != NULL)
		Session->CurrTab->CurrSite = Session->CurrTab->CurrSite->PrevSite;
	else
		printf("There's no site prior to the current site\n");
}

void SessionSiteShow(InfoSessionPtr Session){

	printf("Contents of current site: %s\n",Session->CurrTab->CurrSite->Address);
}

void SessionTabClose(InfoSessionPtr *Session){
	assert(*Session);
	while((*Session)->CurrTab->FirstSite->NextSite != NULL){
		(*Session)->CurrTab->FirstSite = (*Session)->CurrTab->FirstSite->NextSite;
		free((*Session)->CurrTab->FirstSite->PrevSite->Address);	/*Diagrafw ola ta sites tou CurrTab*/
		free((*Session)->CurrTab->FirstSite->PrevSite);
		(*Session)->CurrTab->FirstSite->PrevSite = NULL;
	}
	free((*Session)->CurrTab->FirstSite);
	(*Session)->CurrTab->CurrSite = NULL;
	(*Session)->CurrTab->FirstSite = NULL;
	if((*Session)->CurrTab == (*Session)->CurrTab->NextTab){	/*Efoson h lista einai kuklika sundedemenh elegxw an o CurrTab einai o monos kombos ths*/
		free((*Session)->OpeningAddress);				/*Pragma pou sumbainei otan o epomenos kombos ston opoio deixnei einai o eautos tou*/
		free((*Session)->CurrTab);
		(*Session)->CurrTab = NULL;
		(*Session)->FirstTab = NULL;
		(*Session)->LastTab = NULL;
		free(*Session);
		*Session = NULL;
	}else{
		(*Session)->AuxTab = (*Session)->CurrTab->NextTab;
		if((*Session)->CurrTab == (*Session)->FirstTab)
			(*Session)->FirstTab = (*Session)->CurrTab->NextTab;
		else if((*Session)->CurrTab == (*Session)->LastTab)
			(*Session)->LastTab = (*Session)->CurrTab->PrevTab;
		(*Session)->CurrTab->PrevTab->NextTab = (*Session)->CurrTab->NextTab;
		(*Session)->CurrTab->NextTab->PrevTab = (*Session)->CurrTab->PrevTab;
		free((*Session)->CurrTab);
		(*Session)->CurrTab = (*Session)->AuxTab;
	}
}

void SessionClose(InfoSessionPtr *Session){
	assert(*Session);
	while(*Session != NULL)
		SessionTabClose(Session);
}

void SessionNewAddress(InfoSessionPtr Session,char *str){
SiteNodePtr temp;
	if(Session->CurrTab->CurrSite->NextSite != NULL){
		temp = Session->CurrTab->CurrSite->NextSite;
		while(temp->NextSite !=NULL)
			temp = temp->NextSite;
		while(temp != Session->CurrTab->CurrSite){	/*Arxika diagrafw tis listes meta to CurrSite*/
			temp = temp->PrevSite;
			free(temp->NextSite->Address);
			free(temp->NextSite);
			temp->NextSite = NULL;
		}
	}
	temp = malloc(sizeof(struct SiteNode));
	assert(temp);
	temp->PrevSite = Session->CurrTab->CurrSite;	/*Sundew ta sites kai arxikopoiw ta dedomena tou neou site me to antistoixo str orisma*/
        temp->NextSite = NULL;
        temp->Address = malloc(strlen(str)+1);
	assert(temp->Address);
	strcpy(temp->Address,str);
        temp->UpTab = Session->CurrTab;
        Session->CurrTab->CurrSite->NextSite = temp;
	Session->CurrTab->CurrSite = Session->CurrTab->CurrSite->NextSite;	/*To neo site einai to CurrSite*/
}

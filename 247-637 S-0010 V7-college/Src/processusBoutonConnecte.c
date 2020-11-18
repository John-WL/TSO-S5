//processusBoutonConnecte:
//Historique: 
// 2018-10-28, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "serviceBaseDeTemps.h"
#include "interfaceT2.h"
#include "interfaceT3.h"
#include "interfaceT4.h"
#include "interfaceB1.h"
#include "interfaceS0008.h"
#include "processusBoutonConnecte.h"

//Definitions privees
#define PROCESSUSBOUTONCONNECTE_COMPTE_MAXIMAL_POUR_RECEVOIR (\
    (unsigned int)(PROCESSUSBOUTONCONNECTE_TEMPS_MAXIMAL_POUR_RECEVOIR_EN_MS \
    *FREQUENCE_DE_LA_BASE_DE_TEMPS_EN_HZ / 1000.0))

#define PROCESSUSBOUTONCONNECTE_PAS_D_ERREURS 0
#define PROCESSUSBOUTONCONNECTE_ERREUR 1
#define PROCESSUSBOUTONCONNECTE_NOMBRE_D_OCTETS_A_TRANSMETTRE  INTERFACES0008_NOMBRE_D_OCTETS_A_TRANSMETTRE
#define PROCESSUSBOUTONCONNECTE_NOMBRE_D_OCTETS_A_RECEVOIR PROCESSUSBOUTONCONNECTE_NOMBRE_D_OCTETS_A_TRANSMETTRE

//Declarations de fonctions privees:
void processusBoutonConnecte_changeT2(void);
void processusBoutonConnecte_prepareLaTransmission(void);
void processusBoutonConnecte_recupereLesDonneesRecues(void);
unsigned char processusBoutonConnecte_valideLesDonneesRecues(void);
void processusBoutonConnecte_traiteLesDonneesRecues(void);
void processusBoutonConnecte_attendApresLeBouton(void);
void processusBoutonConnecte_attendUneDemande(void);
void processusBoutonConnecte_attendUneReponse(void);

//Definitions de variables publiques:
//pas de variables publiques

//Definitions de variables privees:
unsigned char processusBoutonConnecte_etatDeT2;
unsigned char processusBoutonConnecte_compteur;
unsigned char processusBoutonConnecte_octetsRecus[PROCESSUSBOUTONCONNECTE_NOMBRE_D_OCTETS_A_RECEVOIR];
unsigned char processusBoutonConnecte_octetsATransmettre[PROCESSUSBOUTONCONNECTE_NOMBRE_D_OCTETS_A_TRANSMETTRE];


//Definitions de fonctions publiques:
void processusBoutonConnecte_initialise(void)
{
unsigned char i;
  processusBoutonConnecte_compteur = 0;
  processusBoutonConnecte_etatDeT2 = 0;
  interfaceT2_eteint();
  interfaceT3_eteint();
  interfaceT4_eteint();
  for (i = 0; i < PROCESSUSBOUTONCONNECTE_NOMBRE_D_OCTETS_A_TRANSMETTRE; i++)
  {
    processusBoutonConnecte_octetsATransmettre[i] = i+1;
  }
  serviceBaseDeTemps_execute[PROCESSUSBOUTONCONNECTE_PHASE] =
      processusBoutonConnecte_attendApresLeBouton;
}

//Definitions de fonctions privees:
// wait for button to UNBOUNCE
void processusBoutonConnecte_attendApresLeBouton(void)
{
  if (interfaceB1.etatDuModule == MODULE_PAS_EN_FONCTION)
  {
    return;
  }
  serviceBaseDeTemps_execute[PROCESSUSBOUTONCONNECTE_PHASE] =
    processusBoutonConnecte_attendUneDemande;
  processusBoutonConnecte_attendUneDemande(); //on sauve une interruption    
}

// POURQUOI APPUYER SUR UN BOUTON, C'EST UNE "DEMANDE"?
// Ça veut dire quoi, "demande"? 
// Rien pour moi quand je le regarde pour la première fois... 
// "Attend une demande". Quelle demande? J'ai rien demandé, j'appuis sur un bouton!
// Je crois que je dois laisser tomber l'idée de "clean code" que j'ai dans la tête,
// et accepter que les autres programment d'une façon que je n'apprécis pas nécessairement. 
// Donc, quand je regarde le code d'une autre personne, je dois plus me poser la question: 
// "Bon, qu'est-ce qu'il essaie de faire, exactement,
// en écrivant ces lignes de codes qui ne semblent pas faire de sens pour moi?".
// Il faut que j'apprenne à lire les intentions dans l'execution du code, plus qu'à assumer
// une certaine forme qui fait intuitivement du sens pour moi. 
// Je dois abandonner tous mes repères formels de programmation,
// et chercher des repères fondamentaux. 
// Ça sera pas facile mais j'ai pu le choix. 

// ici en gros on attends que le bouton soit appuyé, 
// pis on transmet en can dès que c'est le cas
void processusBoutonConnecte_attendUneDemande(void)
{
  if (interfaceB1.information == INFORMATION_TRAITEE)
  {
    return;
  }
  interfaceB1.information = INFORMATION_TRAITEE;
  if (interfaceB1.etatDuBouton == INTERFACEB1_RELACHE)
  {
    return;
  }
  processusBoutonConnecte_compteur = 0;
  interfaceT4_eteint(); //T4 sert a indiquer les erreurs detectees par interfaceS0008
  interfaceT3_eteint(); //T3 sert a indiquer les erreurs detectees par processusBoutonConnecte
  //processusBoutonConnecte_prepareLaTransmission();
  //interfaceS0008.requete = REQUETE_ACTIVE;
  piloteCAN1_transmetDesDonnes(PILOTECAN1_IDENTIFICATION_EN_TRANSMISSION,
                                     processusBoutonConnecte_octetsATransmettre,
                                     PROCESSUSBOUTONCONNECTE_NOMBRE_D_OCTETS_A_TRANSMETTRE);
  serviceBaseDeTemps_execute[PROCESSUSBOUTONCONNECTE_PHASE] =
    processusBoutonConnecte_attendUneReponse;
}

// ici on attends de recevoir quelque chose par can,
// pis on allume une led si on a rien reçu. 
// On allume une autre si y'a une erreure de comm
void processusBoutonConnecte_attendUneReponse(void)
{
  // update le timeout et go back to attends une "demande" si on l'a traité 
  processusBoutonConnecte_compteur++;
  if (processusBoutonConnecte_compteur ==
      PROCESSUSBOUTONCONNECTE_COMPTE_MAXIMAL_POUR_RECEVOIR)
  {
    processusBoutonConnecte_compteur = 0;
    interfaceT4_allume();
    serviceBaseDeTemps_execute[PROCESSUSBOUTONCONNECTE_PHASE] =
        processusBoutonConnecte_attendUneDemande;
    return;
  }
  
  // si y'a rien sur le port can, go back to waiting
  if(!piloteCAN1_messageDisponible()) {
    return;
  }
  // si y'a quelque chose sur le port can, 
  // lit-le, et valide. Allume la led bleu si c'est valide
  // then go back to waiting for button click
  else {
    processusBoutonConnecte_recupereLesDonneesRecues();
    if(processusBoutonConnecte_valideLesDonneesRecues()) {
      processusBoutonConnecte_changeT2();
    }
    
    serviceBaseDeTemps_execute[PROCESSUSBOUTONCONNECTE_PHASE] =
      processusBoutonConnecte_attendUneDemande;
    return;
  }
  
  
  /*
  processusBoutonConnecte_compteur++;
  if (processusBoutonConnecte_compteur ==
      PROCESSUSBOUTONCONNECTE_COMPTE_MAXIMAL_POUR_RECEVOIR)
  {
    processusBoutonConnecte_compteur = 0;
    interfaceT4_allume();
    serviceBaseDeTemps_execute[PROCESSUSBOUTONCONNECTE_PHASE] =
        processusBoutonConnecte_attendUneDemande;
    return;
  }
  if (interfaceS0008.information == INFORMATION_TRAITEE)
  {
    return;
  }
  interfaceS0008.information = INFORMATION_TRAITEE;
  serviceBaseDeTemps_execute[PROCESSUSBOUTONCONNECTE_PHASE] =
    processusBoutonConnecte_attendUneDemande;
 
  processusBoutonConnecte_changeT2();
  if (interfaceS0008.statut != INTERFACES0008_PAS_D_ERREURS)
  {
    interfaceT4_allume();
    return;
  }
  processusBoutonConnecte_recupereLesDonneesRecues();
  if (processusBoutonConnecte_valideLesDonneesRecues() == PROCESSUSBOUTONCONNECTE_ERREUR)
  {
    interfaceT3_allume();
    return;
  }
  processusBoutonConnecte_traiteLesDonneesRecues();
  interfaceT3_eteint();
  */
}

void processusBoutonConnecte_changeT2(void)
{
  if (processusBoutonConnecte_etatDeT2 == 0)
  {
    processusBoutonConnecte_etatDeT2 = 1;
    interfaceT2_allume();
    return;
  }
  processusBoutonConnecte_etatDeT2 = 0;
  interfaceT2_eteint();  
}

void processusBoutonConnecte_prepareLaTransmission(void)
{
  unsigned char i;
  for (i = 0; i < PROCESSUSBOUTONCONNECTE_NOMBRE_D_OCTETS_A_TRANSMETTRE; i++)
  {
    //interfaceS0008.octetsATransmettre[i] = processusBoutonConnecte_octetsATransmettre[i];
  }
}

void processusBoutonConnecte_recupereLesDonneesRecues(void)
{
  piloteCAN1_litUnMessageRecu(processusBoutonConnecte_octetsRecus);
  /*
  unsigned char i;
  for (i = 0; i < PROCESSUSBOUTONCONNECTE_NOMBRE_D_OCTETS_A_RECEVOIR; i++)
  {
    processusBoutonConnecte_octetsRecus[i] = interfaceS0008.octetsRecus[i];
  }*/
}

unsigned char processusBoutonConnecte_valideLesDonneesRecues(void)
{
  unsigned char i;
  for (i = 0; i < PROCESSUSBOUTONCONNECTE_NOMBRE_D_OCTETS_A_RECEVOIR; i++)
  {
    if (processusBoutonConnecte_octetsRecus[i] != 2*(i+1))
    {
      return PROCESSUSBOUTONCONNECTE_ERREUR;
    }
  }
  return PROCESSUSBOUTONCONNECTE_PAS_D_ERREURS;  
}

void processusBoutonConnecte_traiteLesDonneesRecues(void)
{ //exemple de traitement qui divise les donnees recues par 2. 
  //Le processus pourrait faire autre chose (exemple: transmettre les donnees par lien CAN)
  unsigned char i;
  for (i = 0; i < PROCESSUSBOUTONCONNECTE_NOMBRE_D_OCTETS_A_RECEVOIR; i++)
  {
    processusBoutonConnecte_octetsATransmettre[i] = processusBoutonConnecte_octetsRecus[i];
  }  
}

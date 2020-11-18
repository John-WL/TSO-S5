//piloteTimer1Mode2:
//Historique: 
// 2018-09-08, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "piloteTimer1Mode2.h"

//Definitions privees
#define PILOTETIMER1MODE2_COMPTE_DE_DEPART ( \
     256-((1 + PILOTETIMER1MODE2_UTILISE_LE_DOUBLEUR_DE_TAUX)* \
     MAIN_FREQUENCE_D_OSCILLATEUR_EN_KHZ*1000.0)/ \
     (32.0 * PILOTETIMER1MODE2_TAUX_DE_BITS))

//Declarations de fonctions privees:
__interrupt void PiloteTimer2Autoreload_interruption(void);

//Definitions de variables privees:
//pas de variables privees

//Definitions de fonctions privees:
//pas de fonctions privees

//Definitions de variables publiques:
// pas de variables publiques

//Definitions de fonctions publiques:
void piloteTimer1Mode2_initialise(void)
{
 //initialise le timer1 en mode 1 pour utiliser le UART0
  TCON_bit.TR1 = 0; //arrete le compteur
  TCON_bit.TF1 = 0; //efface toutes demandes d'interruptions
  TMOD_bit.M10 = 0;
  TMOD_bit.M11 = 1;
  TMOD_bit.C_T1 = 0;
  TMOD_bit.GATE1 = 0;
  CKMOD_bit.T1MH = 1;
  CKCON_bit.T1M = 1;

  TL1 = (unsigned char)(PILOTETIMER1MODE2_COMPTE_DE_DEPART);
  TH1 = (unsigned char)(PILOTETIMER1MODE2_COMPTE_DE_DEPART);
  TCON_bit.TR1 = 1; //lance le compteur
}




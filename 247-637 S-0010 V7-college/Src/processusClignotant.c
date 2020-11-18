//processusClignotant:
//Historique: 
// 2019-10-27, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "piloteCAN1.h"
#include "serviceBaseDeTemps.h"
#include "interfaceT1.h"
#include "processusClignotant.h"

//Definitions privees
#define PROCESSUSCLIGNOTANT_COMPTE_COURT_ETEINT (\
  PROCESSUSCLIGNOTANT_TEMPS_COURT_ETEINT_EN_MS * FREQUENCE_DE_LA_BASE_DE_TEMPS_EN_HZ \
  /1000.0)
#define PROCESSUSCLIGNOTANT_COMPTE_COURT_ALLUME (\
  PROCESSUSCLIGNOTANT_TEMPS_COURT_ALLUME_EN_MS * FREQUENCE_DE_LA_BASE_DE_TEMPS_EN_HZ \
  /1000.0)
#define PROCESSUSCLIGNOTANT_COMPTE_LONG_ETEINT (\
  PROCESSUSCLIGNOTANT_TEMPS_LONG_ETEINT_EN_MS * FREQUENCE_DE_LA_BASE_DE_TEMPS_EN_HZ \
  /1000.0)
#define PROCESSUSCLIGNOTANT_COMPTE_LONG_ALLUME (\
  PROCESSUSCLIGNOTANT_TEMPS_LONG_ALLUME_EN_MS * FREQUENCE_DE_LA_BASE_DE_TEMPS_EN_HZ \
  /1000.0)

    
//Declarations de fonctions privees:
void processusClignotant_eteintUnPeu(void);
void processusClignotant_allumeUnPeu(void);
void processusClignotant_eteintLongtemps(void);
void processusClignotant_allumeLongtemps(void);

//Definitions de variables privees:
unsigned int processusClignotant_compteur;
unsigned char processusClignotant_donneesRecues[8];
unsigned char processusClignotant_donneesATransmettre[8];



//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:
void processusClignotant_initialise(void)
{
  processusClignotant_donneesATransmettre[0] = 0;
  processusClignotant_compteur = 0;
  interfaceT1_eteint();
  serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
      processusClignotant_eteintUnPeu;
}

//Definitions de fonctions privees:
void processusClignotant_eteintUnPeu(void)
{
    processusClignotant_compteur++;
    if (processusClignotant_compteur >= PROCESSUSCLIGNOTANT_COMPTE_COURT_ETEINT)
    {
        // reset the counter and light up the led
        processusClignotant_compteur = 0;
        interfaceT1_allume();
        
        // why would you transmit anything here?? We are in the process that controls a led!!!
        // I think this is wrong. You are supposed to either:
        // 1) change the name of the process. It's no longer only about switching leds on and off
        // 2) or create another process that works in parallel with this one, but that handles only the can comm.
        // this is just plain wrong names, and it's missleading. 
        // 
        // view it this way:
        // If I tell you that when I say "car", what I really mean is the word "chiken", you'd tell me I need glasses,
        // or a better sorting function than what my brain is capable of, because something is definitely wrong here. 
        // 
        // Well, here, you're telling me that "flashing a led" means "transmitting data over a can port".
        // I think this is ridiculous. 
        serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
            processusClignotant_allumeUnPeu;
        
       
        /*piloteCAN1_transmetDesDonnes(PILOTECAN1_IDENTIFICATION_EN_TRANSMISSION,
                                     processusClignotant_donneesATransmettre,
                                     1);*/
        processusClignotant_donneesATransmettre[0]++; 
    }
}

void processusClignotant_allumeUnPeu(void)
{
    processusClignotant_compteur++;
    if (processusClignotant_compteur >= PROCESSUSCLIGNOTANT_COMPTE_COURT_ALLUME)
    {
        processusClignotant_compteur = 0;
        interfaceT1_eteint();
        serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
            processusClignotant_eteintLongtemps;  
        
        //piloteCAN1_litUnMessageRecu(processusClignotant_donneesRecues); 
    }
}

void processusClignotant_eteintLongtemps(void)
{
    processusClignotant_compteur++;
    if (processusClignotant_compteur >= PROCESSUSCLIGNOTANT_COMPTE_LONG_ETEINT)
    {
        processusClignotant_compteur = 0;
        interfaceT1_allume();
        serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
            processusClignotant_allumeLongtemps;
    }
}

void processusClignotant_allumeLongtemps(void)
{
  processusClignotant_compteur++;
  if (processusClignotant_compteur >= PROCESSUSCLIGNOTANT_COMPTE_LONG_ALLUME)
  {
      processusClignotant_compteur = 0;
      interfaceT1_eteint();
      serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
          processusClignotant_eteintUnPeu;  
  }
}

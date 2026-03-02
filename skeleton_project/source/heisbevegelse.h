#pragma once

/**
* @file
* @brief Kontrollerer bevegelsen til heismodellen
*/


/**
* @brief Får den nåværende retningen.

* @return -1 ved retning ned, 1 ved retning opp
*/
int getRetning();

/**
* @brief Setter ny retning
*
* @param[in] nyRetning Ny retning
*/
void setRetning(int nyRetning);

/**
* @brief Kalles hver gang heismodellen passerer en etasjesensor, og kaller sjekkEtasje
* for å sjekke om den skal stoppe. Hvis den skal det, kaller stoppPåEtasje.
*
* @param[in] floor Nåværende etasje.
*/
void ankomEtasje(int floor);

/**
* @brief Stopper bevegelse, clearer bestillinger, åpner og lukker dør, starter inaktiv syklus og setter rentning når inaktiv er ferdig
* kaller setRetning(0), clearBestillinger(floor), åpneDør(), lukkeDør(),
* inaktiv(), setRetning(Retningsvelger(floor, retning))
*
* @param[in] floor Nåværende etasje.
*/
void stoppPåEtasje(int floor);

/**
* @brief Oppstartsyklus for å få heismodellen ut av ugyldig posisjon
*
*/
void oppstart();

/**
* @brief Inaktiv syklus, kalles når det ikke finnes noen bestillinger
* 
*
* @param[in] floor Nåværende etasje.
*/
void inaktiv();

void stoppKnappFunksjon();

void setForrigeEtasje(int nyForrigeEtasje);

int getForrigeEtasje();
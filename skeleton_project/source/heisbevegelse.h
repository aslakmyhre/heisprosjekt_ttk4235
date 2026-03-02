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
* @param[in] p_from Ny retning
*/
void setRetning(int nyRetning);


void ankomEtasje(int floor);

void stoppPåEtasje(int floor);

void oppstart();
// inaktiv returnerer når den skal starte opp igjen
void inaktiv();

void stoppKnappFunksjon();

void setForrigeEtasje(int nyForrigeEtasje);

int getForrigeEtasje();
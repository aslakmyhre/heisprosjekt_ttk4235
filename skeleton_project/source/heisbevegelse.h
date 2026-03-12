/**
 * @file heisbevegelse.h
 * @brief Heisbevegelse definerer og deklarerer alle funksjoner som omhandler bevegelse av heisen
 */

#pragma once

/**
 * @brief returnerer hvilken retning heisen har eller hadde før evt. stans
 * 
 * @return 1: retning = opp
 * @return -1: retning = ned
 */
int getRetning();

/**
 * @brief Bestemmer hvilken retning heisen skal bevege seg i \n
 * Lagrer retningen til bruk i getRetning() dersom nyRetning != 0
 * @param nyRetning Retningen som skal brukes
 */
void setRetning(int nyRetning);

/**
 * @brief Prosedyre for hva som skjer når heisen kjører forbi en heissensor (stoppe, ikke stoppe?)
 * 
 * @param floor Etasjen som er ankommet
 */
void ankomEtasje(int floor);

/**
 * @brief Prosedyre for stans av heis \n
 * Stopper heisen, ekspederer alle bestillinger i etasjen, åpner og lukker dør,
 * starter inaktiv() til slutt
 * 
 * @param floor Etasjen som skal stoppes i
 */
void stoppPåEtasje(int floor);

/**
 * @brief Oppstarts-script \n
 * Skrur av alle lys, sjekker om heisen er i en gyldig posisjon. Går alltid til etasjen under ved ugyldig posisjon.
 * Skrur på rett etasjelys og går inaktiv()
 */
void oppstart();

/**
 * @brief Inaktiv modus \n
 * Stopper heisen, venter på nye bestillinger. Brytes når bestilling mottas
 */
void inaktiv();

/**
 * @brief Implementerer logikk for stopp-knapp \n
 * Stopper heisen og Skrur på stopp-lys. Åpner døren dersom heisen er i en etasje og ignorerer alle bestillinger når knappen er trykket.
 * Dersom heisen er mellom etasjer, brukes forrige etasje og retning før stopp til ny automatisk initialisering
 */
void stoppKnappFunksjon();

/**
 * @brief Oppdaterer hva den forrige etasjen var
 * 
 * @param nyForrigeEtasje Ny verdi
 */
void setForrigeEtasje(int nyForrigeEtasje);

/**
 * @brief Henter verdien for hva den forrige etasjen var
 * 
 * @return Forrige etasje
 */
int getForrigeEtasje();
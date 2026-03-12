/**
 * @file bestillinger.h
 * @brief Bestillinger definerer og deklarerer alle funksjoner som omhandler bestillinger, bestillingslogikk og knappetrykk
 */

#pragma once
#include <stdbool.h>

/**
 * @brief Oppretter en bestilling for knapp som har blitt trykket
 * @param floor Etasjen knappen hører til. 0 indeksert
 * @param button Type knapp
 */
void opprettBestilling(int floor, int button);

/**
 * @brief Løkke for å sjekke om en/flere knapp(er) har blitt trykket på \n
 * Brukes når heisen utfører en funksjon som tar noe tid eller når heisen er inaktiv, slik at alle knappetrykk blir registrert.
 * @param kanVekkes Dersom kanVekkes = true, vil løkken brytes når den oppdager at en knapp er trykket
 * @return Returnerer 1 kun dersom kanVekkes = true. Har ingen returverdi dersom kanVekkes = false
 */
int loopKnapper(bool kanVekkes);

/**
 * @brief Sjekker om det finnes en bestilling for etasjen som blir sjekket. 
 * 
 * @param floor Etasjen som blir sjekket
 * @return true: Finnes bestilling i etasjen
 * @return false: Finnes ingen bestilling i etasjen
 */
bool finnesBestilling(int floor);

/**
 * @brief Sjekker om heisen skal stoppe i etasjen \n Blir kalt av ankomEtasje()
 * 
 * @param floor Etasjen som sjekkes
 * @param retning Retningen heisen kjører i når den ankommer etasjen
 * @return true: Heisen skal stoppe
 * @return false: Heisen skal ikke stoppe
 */
bool sjekkEtasje(int floor, int retning);

/**
 * @brief Fjerner alle bestillinger i etasjen \n 
 * Kalles når heisen stopper i en etasje, og brukes i oppstart() til å skru av alle lamper
 * 
 * @param floor Etasjen man fjerner bestillinger fra
 */
void clearBestillinger(int floor);

/**
 * @brief Bestemmer hvilken retning heisen skal kjøre \n 
 * Kalles når heisen skal starte igjen etter stans
 * 
 * @param floor Etasjen heisen står i
 * @param retning Retningen heisen hadde før stans
 * @return 1: Velg retning oppover
 * @return -1: Velg retning nedover
 * @return 0: Ingen retning valgt, stå stille
 */
int retningsVelger(int floor, int retning);
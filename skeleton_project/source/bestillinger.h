/**
 * @file bestillinger.h
 * @brief Bestillinger definerer og deklarerer alle funksjoner som omhandler bestillinger, bestillingslogikk og knappetrykk
 */

#pragma once
#include <stdbool.h>

/**
 * @brief Tar inn type knapp som ble trykket og hvilken etasje brukerer vil dra til \n 
 * Typen (button) knapp bestemmer hvilken array (oppBestillinger, nedBestillinger, innvendigeBestillinger) bestillinger skal lagres \n 
 * og etasjer (floor) bestemmer hvilken posisjon den skal ha \n 
 * For eksempel vil en opp-knapp i 2. etasje lagres i oppBestillinger[1]
 * @param floor Etasjen knappen hører til. 0 indeksert
 * @param button Type knapp
 */
void opprettBestilling(int floor, int button);

/**
 * @brief Looper gjennom alle etasjer og knapptyper og sjekker om elevio_callButton() for etasje og knapptype er true \n
 * Kaller opprettBestillig() for knappen som er trykket.
 * 
 * @param kanVekkes Dersom kanVekkes = true, vil løkken brytes når den oppdager at en knapp er trykket
 * @return Returnerer 1 kun dersom kanVekkes = true. Har ingen returverdi dersom kanVekkes = false
 */
int loopKnapper(bool kanVekkes);

/**
 * @brief Sjekker om det finnes en bestilling for etasjen som blir sjekket, altså om en av knappelistene har \n 
 * true for elementet floor
 * 
 * @param floor Etasjen som blir sjekket
 * @return true: En av listene har en bestilling i denne etasjen
 * @return false: Ingen av listene har en bestilling i denne etasjen
 */
bool finnesBestilling(int floor);

/**
 * @brief Sjekker om heisen skal stoppe i etasjen. Blir kalt av ankomEtasje() \n 
 * Fungerer slik: Finnes det en panelbestilling eller en bestilling i samme retning? \n 
 * Hvis ja: stopp. \n 
 * Hvis nei: Finnes det en bestilling i etasjen i motsatt retning, men ingen andre bestillinger i samme retning? \n 
 * Hvis ja: stopp. Hvis nei: ikke stopp.
 * 
 * @param floor Etasjen som sjekkes
 * @param retning Retningen heisen kjører i når den ankommer etasjen
 * @return true: Heisen skal stoppe
 * @return false: Heisen skal ikke stoppe
 */
bool sjekkEtasje(int floor, int retning);

/**
 * @brief Fjerner alle bestillinger i etasjen (Setter alle elementet tilhørende denne etasjen i alle knappelistene til false) \n 
 * Kalles når heisen stopper i en etasje, og brukes i oppstart() til å skru av alle lamper
 * 
 * @param floor Etasjen man fjerner bestillinger fra
 */
void clearBestillinger(int floor);

/**
 * @brief Bestemmer hvilken retning heisen skal kjøre. Kalles når heisen har stoppet. \n
 * Sjekker om det finnes en bestilling i retningen heisen hadde før stoppet. Hvis ja: fortsett i samme retning \n 
 * Hvis nei: Sjekker om det finnes en bestilling i mostatt retning. Hvis ja: bytt retning \n 
 * Hvis nei: stå stille
 * 
 * @param floor Etasjen heisen står i
 * @param retning Retningen heisen hadde før stans
 * @return 1: oppover, -1: nedover, 0: stille
 */
int retningsVelger(int floor, int retning);
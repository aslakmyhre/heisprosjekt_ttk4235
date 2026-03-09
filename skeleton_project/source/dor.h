/**
 * @file dor.h
 * @brief Dør definerer og deklarerer funksjoner som omhandler dør-logikk
 */

#pragma once

/**
 * @brief Skrur på dør-lys dersom heisen er i en etasje. Kalles av stoppPåEtasje
 * 
 */
void åpneDør();

/**
 * @brief Skrur av dør lys etter 3 sekunder. Sjekker underveis om det er en obstruksjon som gjør at døren ikke kan lukkes. 
 * Hvis det er en obstruksjon, venter den 3 nye sekunder etter den er borte på å skru av lyset, og fortsetter å se etter obstruksjoner. \n
 * Kaller loopKnapper() #false for å sjekke om noen av knappene blir trykket i mellomtiden. Den skal ikke brytes.
 */
void lukkDør();

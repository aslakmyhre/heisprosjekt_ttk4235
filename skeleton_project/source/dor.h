/**
 * @file dor.h
 * @brief Dør definerer og deklarerer funksjoner som omhandler dør-logikk
 */

#pragma once

/**
 * @brief Åpner døren (skrur på dør-lys) når heisen har stoppet på en etasje
 * 
 */
void åpneDør();

/**
 * @brief Logikk for lukking av heisdørene (slukke dør-lys) \n
 * 3 sekunder etter funksjonen kalles lukkes dørene så lenge det ikke er en obstruksjon, da resettes timeren
 */
void lukkDør();

#pragma once

/**
 * @file 
 * @brief Heisbevegelse definerer og deklarerer alle funksjoner som omhandler bevegelse av heisen
 */


/**
 * @brief Kalles når man må vite hvilken retning man kjører i
 * 
 * @return int retning
 */
int getRetning();

/**
 * @brief Bestemmer hvilken retning heisen skal bevege seg i
 * 
 * @param nyRetning Retningen som skal brukes
 */
void setRetning(int nyRetning);

/**
 * @brief Kalles når elevio_floorSensor != 0, og kaller 
 * sjekkEtasje(floor) for å se om heisen skal stoppe i denne etasjen.
 * Hvis ja kaller stoppPåEtasje(floor)
 * Skrur på etasjelys, elevio_floorIndicator(floor)
 * 
 * @param floor Etasjen som er ankommet
 */
void ankomEtasje(int floor);

/**
 * @brief Kalles av ankomEtasje(floor) når heisen skal stoppe.
 * Kaller funksjonene 
 *   setRetning(0);
 *   clearBestillinger(floor);
 *   åpneDør();
 *   lukkDør();
 *   inaktiv();
 * som får heisen til å stoppe, fjerne bestillinger i etasjen, åpner/lukker dør og starter inaktiv modus
 * @param floor Etasjen som skal stoppes i
 */
void stoppPåEtasje(int floor);

/**
 * @brief Oppstarts-script
 * Skrur av alle lys, sjekker om heisen er i en gyldig posisjon med elevio_floorSensor()
 *   Hvis posisjonen er ugyldig: Setter retning nedover, alltid, frem til den treffer en etasje.
 *   Ignorerer alle input frem til gyldig etasje er funnet
 * Når heisen er i gyldig posisjon: Kaller ankomEtasje() for å skru på etasjelys
 * Går inaktiv
 */
void oppstart();

/**
 * @brief Inaktiv kalles når det ikke er noen bestillinger, eller det ikke er åpenbart at det finnes noen bestillinger
 * Stopper heisen, setRetning(0)
 * Kjører en evig løkke gjennom alle knapper, loopKnapper(kanVekkes=true)
 * Når en knapp trykkes, breakes inaktiv
 * 
 */
void inaktiv();

/**
 * @brief Implementerer logikk for stopp-knapp
 * 
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
 * @return int, forrige etasje
 */
int getForrigeEtasje();
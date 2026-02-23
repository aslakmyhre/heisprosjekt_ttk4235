#include "lys.h"
#include "driver/elevio.h"
#include <stdio.h>

// antar at å sette et element i lyslisten til true også aktiverer lyset på boksen
/*
REDUNTANT:
aktiverLys(Enum lysType, int lysIndex, bool On):
	knappLys[lysType][lysIndex] = On

aktiverEtasjeLys(int floor){
    // clear lysene som er aktive:
	for (int i = 0; i < 4; ++i){
		elevio_floorIndicator(floor))
	}
}
	
*/


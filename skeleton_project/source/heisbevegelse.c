#include "heisbevegelse.h"
#include "bestillinger.h"
#include "driver/elevio.h"
#include <stdio.h>
#include <unistd.h>

int retning = 0;

int getRetning(void) {
    return retning;
}

void setRetning(int nyRetning) {
    retning = nyRetning;
}

void ankomEtasje(int floor) {
    if (sjekkEtasje(floor, retning)) {
        stoppPåEtasje(floor);
    }
}

void stoppPåEtasje(int floor){
    elevio_motorDirection(DIRN_STOP);
}

void oppstart(){
    int floor = elevio_floorSensor();
    if (floor==-1){
        elevio_motorDirection(DIRN_DOWN);
    }

}
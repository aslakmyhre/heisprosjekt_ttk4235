#include "heisbevegelse.h"
#include "driver/elevio.h"
#include <stdio.h>
#include <unistd.h>

void ankomEtasje(int floor) {
    stoppPåEtasje(floor);
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
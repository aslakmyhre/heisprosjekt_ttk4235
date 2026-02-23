#include "dør.h"
#include "driver/elevio.h"
#include <stdio.h>


void åpneDør(){
    if (elevio_floorSensor()!=-1) {
        elevio_doorOpenLamp(1);
    }
}

void lukkDør(){
    elevio_doorOpenLamp(0);
}
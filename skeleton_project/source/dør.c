#include "dør.h"
#include "driver/elevio.h"
#include <stdio.h>


void åpneDør(int floor){
    if (floor!=-1) {
        elevio_doorOpenLamp(1);
    }
}

void lukkDør(){
    elevio_doorOpenLamp(0);
}
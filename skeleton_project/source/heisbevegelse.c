#include <stdio.h>
#include <unistd.h>
#include "heisbevegelse.h"
#include "bestillinger.h"
#include "driver/elevio.h"
#include "dør.h"

int retning = 0;

int getRetning(void) {
    return retning;
}

void setRetning(int nyRetning) {
    retning = nyRetning;
    elevio_motorDirection(retning);
}

void ankomEtasje(int floor) {
    if (sjekkEtasje(floor, retning)) {
        stoppPåEtasje(floor);
    }
}

void stoppPåEtasje(int floor){
    setRetning(0);
    åpneDør();
    lukkDør();
    clearBestillinger(floor);
    setRetning(retningsVelger(floor, retning));
}

void oppstart(){
    int floor = elevio_floorSensor();
    if (floor==-1){
        setRetning(-1);
    }

}

void inaktiv(void) {
    while(1) {
        for(int i = 0; i < N_FLOORS; ++i) {
            if(finnesBestilling(i)) {
                return;
            }
        }
    }
}
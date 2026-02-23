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
    if(retning != 0) {
        retning = nyRetning;
    }
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
    inaktiv();
    setRetning(retningsVelger(floor, retning));
}

void oppstart(){
    int floor = elevio_floorSensor();
    if (floor==-1){
        setRetning(-1);
    }
}

void inaktiv(void) {
    int floor = elevio_floorSensor();
    while(1) {
        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
                if(btnPressed){
                    opprettBestilling(f, b);
                }
            }
            if(finnesBestilling(f)) {
                return;
            }
        }
    }
}
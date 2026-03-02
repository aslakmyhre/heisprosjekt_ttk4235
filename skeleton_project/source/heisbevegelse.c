#include <stdio.h>
#include <unistd.h>
#include "heisbevegelse.h"
#include "bestillinger.h"
#include "driver/elevio.h"
#include "dor.h"

int retning = 0; // retning er den forrige ikke-null retningen til heisen

int getRetning() {
    return retning;
}

void setRetning(int nyRetning) {
    if(retning != 0) {
        retning = nyRetning;
    }
    elevio_motorDirection(nyRetning);
}

void ankomEtasje(int floor) {
    elevio_floorIndicator(floor);
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

void inaktiv() {
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
        // stoppknapp breaker programmet
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
    }
}

void stoppKnappFunksjon() {
    int stoppTrukket = 1;
    elevio_stopLamp(1);
    // slett alle ubetjente bestillinger
    for(int f = 0; f < 4; ++f) {
        clearBestillinger(f);
    }
    while (stoppTrukket == 1) {
        stoppTrukket = elevio_stopButton();
    } // går ut av løkka når stoppknappen slippes
    elevio_stopLamp(0);
    inaktiv();
}
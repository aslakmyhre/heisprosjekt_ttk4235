#include <stdio.h>
#include <unistd.h>
#include "heisbevegelse.h"
#include "bestillinger.h"
#include "driver/elevio.h"
#include "dor.h"

int retning = -1; // retning er den forrige ikke-null retningen til heisen

int getRetning() {
    return retning;
}

void setRetning(int nyRetning) {
    printf("starter setRetning()\n");
    if(nyRetning != 0) {
        retning = nyRetning;
    }
    elevio_motorDirection(nyRetning);
    printf("ferdig setRetning(), return:%d\n", retning);
}

void ankomEtasje(int floor) {
    printf("starter ankometasje\n");
    elevio_floorIndicator(floor);
    if (sjekkEtasje(floor, retning)) {
        stoppPåEtasje(floor);
        printf("stopper på %d\n", floor);
    }
}

void stoppPåEtasje(int floor){
    printf("starter stoppPåEtasje()\n");
    setRetning(0);
    åpneDør();
    lukkDør();
    clearBestillinger(floor);
    inaktiv();
    printf("ferdig med inaktiv\n");
    setRetning(retningsVelger(floor, retning));
    printf("valgte retning%d\n", retning);
}

void oppstart(){
    printf("starter oppstart()\n");
    int floor = elevio_floorSensor();
    if (floor==-1){
        setRetning(-1);
        printf("fra oppstart: setRetning():%d\n", floor);
    }
}

void inaktiv() {
    printf("går inaktiv\n");
    while(1) {
        if (loopKnapper(true)==1) {
            break;
        }
        // stoppknapp breaker programmet
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
    }
    //return;
}

void stoppKnappFunksjon() {
    printf("stoppknapp kallet\n");
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
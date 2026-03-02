#include "dor.h"
#include "driver/elevio.h"
#include <stdio.h>
#include <unistd.h>
#include "bestillinger.h"


void åpneDør(){
    if (elevio_floorSensor()!=-1) {
        elevio_doorOpenLamp(1);
    }
}

void lukkDør(){
    int sekUtenObst = 0;
    while (sekUtenObst <= 3) {
        sleep(1);
        if (elevio_obstruction()) {
            sekUtenObst = 0;
        }
        else {
            ++sekUtenObst;
        }
        // sjekk om hver knapp er trykket
        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
                if(btnPressed){
                    opprettBestilling(f, b);
                }
            }
        }
        // TODO: legg til de andre nødvendige knappene her
    }
    // lukk døra
    elevio_doorOpenLamp(0);
}
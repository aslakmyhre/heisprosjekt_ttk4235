#include "dor.h"
#include "driver/elevio.h"
#include <stdio.h>
#include <unistd.h>
#include "bestillinger.h"
#include <time.h>


void åpneDør(){
    printf("åpner dør\n");
    if (elevio_floorSensor()!=-1) {
        elevio_doorOpenLamp(1);
    }
}

void lukkDør(){
    printf("lukker dør\n");
    
    time_t stoppTid = time(NULL) + 3;

    while (time(NULL) < stoppTid) {
        //nanosleep(&(struct timespec){0, 20*1000}, NULL);

        if (elevio_obstruction()) {
            stoppTid = time(NULL) + 3;
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
    printf("dør lukket \n");
}
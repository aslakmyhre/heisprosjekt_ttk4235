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
    if(elevio_floorSensor() != -1) {
        printf("lukker dør\n");
    
        time_t stoppTid = time(NULL) + 3;

        while (time(NULL) <= stoppTid) {
            //nanosleep(&(struct timespec){0, 20*1000}, NULL);

            if (elevio_obstruction()) {
                stoppTid = time(NULL) + 3;
            }
            // sjekk om hver knapp er trykket
            loopKnapper(false);
        }
        // lukk døra
        elevio_doorOpenLamp(0);
        printf("dør lukket \n");     
    }
}
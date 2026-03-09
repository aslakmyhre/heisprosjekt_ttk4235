/**
 * @file 
 * @brief main fil brukes til å starte og holde programmet kjørende
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "heisbevegelse.h"
#include "bestillinger.h"
#include "dor.h"

int main(){
    elevio_init();
   
    oppstart();

    while(1){
        int floor = elevio_floorSensor();
        // sjekk om heisen har nådd en etasje
        if (floor!=-1 && (floor!=getForrigeEtasje())) {
            setForrigeEtasje(floor);
            ankomEtasje(floor);
        }
        // bør være redundant ved ferdig heis, men greit å ha
        if(floor == 0){
            setRetning(1);
        }

        if(floor == N_FLOORS-1){
            setRetning(-1);
        }

        // sjekk om hver knapp er trykket

        loopKnapper(false);

        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        if(elevio_stopButton()){
            stoppKnappFunksjon();
        }
        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    return 0;
}

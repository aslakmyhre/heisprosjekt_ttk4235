#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "heisbevegelse.h"
#include "bestillinger.h"
#include "dor.h"
#include "lys.h"





int main(){
    elevio_init();
    
    oppstart();

    while(1){
        int floor = elevio_floorSensor();
        // sjekk om heisen har nådd en etasje
        if (floor!=-1) {
            ankomEtasje(floor);
        }

        if(floor == 0){
            setRetning(1);
        }

        if(floor == N_FLOORS-1){
            setRetning(-1);
        }


        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
                if(btnPressed){
                    opprettBestilling(f, b);
                }
            }
        }

        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    return 0;
}

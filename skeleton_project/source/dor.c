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
    
    int msekUtenObst = 0;
    while (msekUtenObst <= 150) {
        //nanosleep(&(struct timespec){0, 20*1000}, NULL);

        if (elevio_obstruction()) {
            msekUtenObst = 0;
        }
        else {
            msekUtenObst += 20;
            printf("%d\n", msekUtenObst);
        }
        // sjekk om hver knapp er trykket
        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
                printf("aaa\n");
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
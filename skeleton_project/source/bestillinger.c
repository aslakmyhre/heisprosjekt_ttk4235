#include "bestillinger.h"
#include <stdio.h>
#include "driver/elevio.h"

bool oppBestillinger[] = {false, false, false, false};
bool nedBestillinger[] = {false, false, false, false};
bool innvendigeBestillinger[] = {false, false, false, false};


void opprettBestilling(int floor, int button){
    if(elevio_floorSensor() != floor){
        elevio_buttonLamp(floor, button, 1); // skru på knapplys
        switch(button) {
            case 0: // UP
                oppBestillinger[floor]=true;
                printf("oppbestillinger=true for%d\n", floor);
                break;
            case 1: // DOWN
                nedBestillinger[floor]=true;
                printf("nedbestillinger=true for%d\n", floor);
                break;
            case 2: // CAB
                innvendigeBestillinger[floor]=true;
                printf("innvendigeBestillinger=true for%d\n", floor);
                break;
            default: break;
        }
    }
}

int loopKnapper(bool kanVekkes) {
    for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                if(btnPressed){
                    opprettBestilling(f, b);
                }
            }
            if (kanVekkes==true){
                if(finnesBestilling(f)) {
                return 1;
            }
            }
        }
    return 0;
}

bool finnesBestilling(int floor){
    if (oppBestillinger[floor] || nedBestillinger[floor] || innvendigeBestillinger[floor]) {
        //printf("finnesbestillinger=true\n");
        return true;
    }
    else {
        //printf("finnesbestillinger=false\n");
        return false;
    }
}

bool sjekkEtasje(int floor, int retning){
    printf("sjekketasje kallet\n");
    bool panel = innvendigeBestillinger[floor];
    bool opp = oppBestillinger[floor];
    bool ned = nedBestillinger[floor];

    if (panel==true) {
        return true;
    }
    else if(opp==true && retning==1) {
        return true;
    }
    else if(ned==true && retning==-1) {
        return true;
    }
    else {
        return false;
    }
}

void clearBestillinger(int floor){
    printf("clearbestillinger kallet\n");
    oppBestillinger[floor]=false;
    nedBestillinger[floor]=false;
    innvendigeBestillinger[floor]=false;
    for (int b = 0; b <= 2; ++b) { // slukk knapplys
        elevio_buttonLamp(floor, b, 0);
    }
}
/*
int retningsVelger(int floor, int retning){
    switch (floor) {
    case 0: 
        retning = 1;
        return retning;
    case 1:
        if (retning==1) {
            if (finnesBestilling(floor+1)||finnesBestilling(floor+2)) {
                retning = 1;
                return retning;
            }
            else if (finnesBestilling(floor-1)) {
                retning = -1;
                return retning;
            }
            else {
                retning = 0;
                return retning;
            }
        }
    case 2:
        if (retning==1){
            if (finnesBestilling(floor+1)){
                retning = 1;
                return retning;
            }
            else if (finnesBestilling(floor-1)||finnesBestilling(floor-2)) {
                retning = -1;
                return retning;
            }
            else {
                retning = 0;
                return retning;
            }
        }
        else {
            retning = -1;
            return retning;
        }
    case 3:
        retning = -1;
        return retning;
    default: return 0;
    }
}

*/


//25-02: lagt inn return 0 dersom ingen bestillinger finnes (redundant, men greit å ha)
int retningsVelger(int floor, int retning){
    printf("retningsVelger\n");
    printf("retning, %d\n", retning);
    int ret; 
    for (int f = floor + retning; f >= 0 && f < 4; f += retning) {
        //printf("+retning, %d\n", f);
        if (finnesBestilling(f)) {
            ret= retning;
        }
    }
    for (int f = floor - retning; f >= 0 && f < 4; f -= retning) {
        printf("-retning, %d\n", f);
        if (finnesBestilling(f)) {
            ret= -1 * retning;
        }
    }
    
    if (ret) {
        printf("ferdig retningsVelger\n");
        return ret;
    }
    else {
        printf("ferdig retningsVelger\n");
        return 0; 
    }
}
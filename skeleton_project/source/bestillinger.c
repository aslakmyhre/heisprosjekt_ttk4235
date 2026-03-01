#include "bestillinger.h"
#include <stdio.h>
#include "driver/elevio.h"

bool oppBestillinger[] = {false, false, false, false};
bool nedBestillinger[] = {false, false, false, false};
bool innvendigeBestillinger[] = {false, false, false, false};


void opprettBestilling(int floor, int button){
    elevio_buttonLamp(floor, button, 1); // skru på knapplys
    switch(button) {
        case 0: // UP
            oppBestillinger[floor]=true;
        case 1: // DOWN
            nedBestillinger[floor]=true;
        case 2: // CAB // 01-03: endra fra 3 til 2, tror det er riktig? må sjekke
            innvendigeBestillinger[floor]=true;
        default: break;
    }
}

bool finnesBestilling(int floor){
    if (oppBestillinger[floor] || nedBestillinger[floor] || innvendigeBestillinger[floor]) {
        return true;
    }
    else {
        return false;
    }
}

bool sjekkEtasje(int floor, int retning){
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
    int ret; 
    for (int f = floor + retning; f >= 0 && f < 4; f += retning) {
        if (finnesBestilling(f)) {
            ret= retning;
        }
    }
    for (int f = floor - retning; f >= 0 && f < 4; f -= retning) {
        if (finnesBestilling(f)) {
            ret= -1 * retning;
        }
    }
    if (ret) {
        return ret;
    }
    else {
        return 0; 
    }
}
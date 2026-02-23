#include "bestillinger.h"
#include <stdio.h>

bool oppBestillinger[] = {false, false, false, false};
bool nedBestillinger[] = {false, false, false, false};
bool innvendigeBestillinger[] = {false, false, false, false};


void opprettBestilling(int floor, int button){
    switch(button) {
        case 0: // UP
            oppBestillinger[floor]=true;
        case 1: // DOWN
            nedBestillinger[floor]=true;
        case 3: // CAB
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

int retningsVelger(int floor, int retning){
    for (int f = floor + retning; f >= 0 && f < 4; f += retning) {
        if (finnesBestilling(f)) {
            return retning;
        }
    }
    for (int f = floor - retning; f >= 0 && f < 4; f -= retning) {
        if (finnesBestilling(f)) {
            return -1 * retning;
        }
    }
}
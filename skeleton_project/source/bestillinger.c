#include "bestillinger.h"
#include <stdio.h>

bool oppBestillinger[] = {false, false, false, false};
bool nedBestillinger[] = {false, false, false, false};
bool innvendigeBestillinger[] = {false, false, false, false};

bool finnesBestilling(int floor){
    if (oppBestillinger[floor] || nedBestillinger[floor] || innvendigeBestillinger[floor]) {
        return true;
    }
    else {
        return false;
    }
}

bool sjekkEtasje(int floor, int retning){
    // sjekk 
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

int retningsVelger(int floor, int retning){
    /**
    if (floor==0) {
        retning=1;
        return retning; //opp
    }
    else if (floor==3) {
        retning=-1;
        return retning;
    }
    else {

    }
    **/
    switch (floor) {
    case 0: 
        retning = 1;
        return retning;
    case 1:
        if (retning==1) {
            // hvis retning opp, og det finnes bestillinger over -> fortsett oppover
            if (finnesBestilling(floor+1)||finnesBestilling(floor+2)) {
                retning = 1;
                return retning;
            }
        }
        //???? hvis ikke return retning
        else {
            retning = -1;
            return retning;
        }
    case 2:
    case 3:
        retning = -1;
        return retning;
    }
    // ...

}

#include "bestillinger.h"
#include <stdio.h>

bool oppBestillinger[] = {false, false, false, false};
bool nedBestillinger[] = {false, false, false, false};
bool innvendigeBestillinger[] = {false, false, false, false};

bool sjekkEtasje(int floor, int retning){
    // sjekk 
}

void clearBestillinger(int floor){

}

int retningsVelger(int floor, int retning){
    if (floor==0) {
        retning=1;
        return retning; //opp
    }
    else if (floor==3) {
        retning=-1;
        return retning;
    }
    // ...

}

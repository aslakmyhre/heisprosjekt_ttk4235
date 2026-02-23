#pragma once
#include <stdbool.h>

bool finnesBestilling(int floor);

bool sjekkEtasje(int floor, int retning);

void clearBestillinger(int floor);

int retningsVelger(int floor, int retning);
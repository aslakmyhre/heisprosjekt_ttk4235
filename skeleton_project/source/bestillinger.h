#pragma once
#include <stdbool.h>

void opprettBestilling(int floor, int button);

int loopKnapper(bool kanVekkes);

bool finnesBestilling(int floor);

bool sjekkEtasje(int floor, int retning);

void clearBestillinger(int floor);

int retningsVelger(int floor, int retning);
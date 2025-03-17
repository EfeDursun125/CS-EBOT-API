
#ifndef MAIN_H
#define MAIN_H

#ifdef WIN32
#include <windows.h>
#endif
#include <sys/types.h>	
#include <string.h>
#include <malloc.h>
#include "../sdk/amxxmodule.h"

extern AMX_NATIVE_INFO ebot_natives[];
void LoadEBot(void);

#endif
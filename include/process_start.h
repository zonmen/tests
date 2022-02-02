#ifndef _PROCESS_START
#define _PROCESS_START
#include <cstring>
#include <iostream>
#include <string>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

#include "types.h"

int start_process(const set_prog_start &programm);

#endif
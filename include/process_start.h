#ifndef _PROCESS_START
#define _PROCESS_START
#include <cstring>
#include <errno.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

#include "types.h"

pid_t start_process(set_prog_start &programm);

#endif
#ifndef _PROCESS_START
#define _PROCESS_START
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "types.h"

pid_t start_process(set_prog_start &program);

#endif
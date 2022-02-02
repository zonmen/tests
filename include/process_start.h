#ifndef _PROCESS_START
#define _PROCESS_START
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

#include "types.h"

int start_process(std::string name, std::string path);

int start_process(std::string name, std::string path, std::vector<std::string> arg);

int start_process(std::string name, std::string path, std::string stdout_file, bool stdout_mode = 0);

int start_process(struct set_prog_start *programm);

#endif 
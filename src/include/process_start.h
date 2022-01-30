#ifndef _PROCESS_START
#define _PROCESS_START
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

int start_process(string name, string path);

int start_process(string name, string path, vector<string> arg);

int start_process(string name, string path, string stdout_file, bool stdout_mode = 0);

#endif 
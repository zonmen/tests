#ifndef _TYPES_
#define _TYPES_

#include <iostream>
#include <vector>

struct set_prog_start {
  std::string name;             // Process name
  std::string executable_path;  // Absolute path to executable file
  std::string
      stdout_config_file;  // Path to log file storing stdout (no log file is
                           // created by default, provided path should exist).
  bool stdout_config_truncate;  // stdout redirect file write mode append or
                                // truncate (default: truncate).
  pid_t pid;                    // Program pid(0 - if not started)
  std::vector<std::string>
      cmd_arguments;  // Option name(e.g. -h, -filename my_file)
};

#endif

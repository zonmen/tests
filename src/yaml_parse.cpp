#include "yaml_parse.h"

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "logger.h"

using namespace std;

std::vector<set_prog_start> parse_yaml(const std::string &filename) {
  std::string line;
  std::vector<set_prog_start> out;

  ifstream file(filename);

  if (!file) {
    LOG("Could not open config file " + filename, ERROR);
    throw std::runtime_error("Could not open config file " + filename);
  }
  set_prog_start config_buffer;
  while (getline(file, line)) {
    if (line.find("  - name: ") == 0) {
      if (config_buffer.name != "" and config_buffer.executable_path != "") {
        out.push_back(config_buffer);
        LOG("Parsed from config file: " + config_buffer.name, INFO);
      }
      config_buffer = {};
      config_buffer.stdout_config_truncate = true;
      config_buffer.name = line.substr(10);
      continue;
    }

    if (line.find("    executable-path: ") == 0) {
      config_buffer.executable_path = line.substr(21);
      continue;
    }
    if (line.find("      file: ") == 0) {
      config_buffer.stdout_config_file = line.substr(12);
      continue;
    }

    if (line.find("      - option-name: ") == 0) {
      config_buffer.cmd_arguments.push_back(line.substr(21));
      continue;
    }

    if (line.find("      mode: ") == 0) {
      if (line.substr(12) == "truncate") {
        config_buffer.stdout_config_truncate = true;
      } else {
        config_buffer.stdout_config_truncate = false;
      }
      continue;
    }

    // ToDo: convert line.find to separate function with line leng checks
    // ToDo: add check requiered fields
  }
  if (config_buffer.name != "" and config_buffer.executable_path != "") {
    out.push_back(config_buffer);
  }

  file.close();
  return out;
}
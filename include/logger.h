#ifndef _LOGGER
#define _LOGGER

#include <fstream>
#include <iostream>

// todo : add mutex , add log-level

enum typelog { DEBUG, INFO, WARN, ERROR };

class Logger {
 public:
  static Logger *getInstance() {
    static Logger instance;
    return &instance;
  }

  void test();

  void set_log_path(const std::string &path) {
    out.close();
    log_path = path;
  }

  void log(const std::string &text, typelog type = WARN);

 private:
  std::ofstream out;
  std::string log_path = "log.log";
  inline std::string getLabel(typelog type);
  Logger() {}
};

void LOG(const std::string &s, typelog tp);
#endif
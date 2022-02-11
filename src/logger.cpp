#include "logger.h"

#include <ctime>
#include <iomanip>
#include <iostream>

void Logger::log(const std::string &text, typelog type) {
  if (!out.is_open()) {
    out.open(log_path, std::ios_base::app);
  }

  if (out.is_open()) {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    out << std::put_time(&tm, "%d-%m-%Y %H-%M-%S")
        << (" [" + getLabel(type) + "] ") << text << std::endl;
  }
}

inline std::string Logger::getLabel(typelog type) {
  std::string label;
  switch (type) {
    case DEBUG:
      label = "DEBUG";
      break;
    case INFO:
      label = "INFO ";
      break;
    case WARN:
      label = "WARN ";
      break;
    case ERROR:
      label = "ERROR";
      break;
  }
  return label;
}

void LOG(const std::string &s, typelog tp) {  // alias
  Logger::getInstance()->log(s, tp);
}

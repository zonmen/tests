#include <iostream>

#include "logger.h"
#include "process_start.h"
#include "yaml_parse.h"

using namespace std;

int main(int argc, char *argv[]) {
  Logger::getInstance()->set_log_path("custom.log");
  LOG("Started", INFO);

  if (argc > 1) {
    try {
      auto program = parse_yaml(argv[1]);
      // TODO: add logic there
      // start all process
      for (auto &one_program : program) {
        // pid changes in function
        one_program.pid = start_process(one_program);
      }
      // wait until processes are done
      wait(nullptr);
    } catch (std::exception &ex) {
      //!!! stdout stream doesn't work in CHILD process(redirected to file)
      LOG(std::string("Ouch! That hurts, because: ") + ex.what(), ERROR);
      cout << "Ouch! That hurts, because: " << ex.what() << "!" << endl;
    }
  } else {
    LOG("Cant find config file: ", ERROR);
    cout << "Pass config filename as first argument to program" << endl;
  }
  LOG("Finished", INFO);
  return 0;
}

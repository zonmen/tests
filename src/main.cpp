#include <iostream>

#include "process_start.h"
#include "yaml_parse.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc > 1) {
    try {
      auto program = parse_yaml(argv[1]);
      // TODO: add logic there
      // start all process
      for (auto one_program : program) {
        // save pid in struct variable
        // one_program.pid = start_process(one_program);
        start_process(one_program);
      }
      // wait until processes are done
      wait(nullptr);
    } catch (std::exception &ex) {
      //!!! stdout stream doesn't work in CHILD process(redirected to file)
      cout << "Ouch! That hurts, because: " << ex.what() << "!" << endl;
    }
  } else {
    cout << "Pass config filename as first argument to program" << endl;
  }

  return 0;
}

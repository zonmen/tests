#include <iostream>

#include "include/yaml_parse.h"
#include "include/process_start.h"
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
  argc++;
  argv[1] = new char[200];
  strcpy(argv[1], "/home/prutek/programms/vs_workspace/DeLorean_Team/tests/example.yml");
  if (argc > 1) {
    try {
      auto program = parse_yaml(argv[1]);
      // TODO: add logic there
      // start all process
      for ( auto one_program : program )
      {
        start_process( &one_program );
      }
      //wait until processes are done
      wait(nullptr);
    } catch (std::exception &ex) {
      cout << "Ouch! That hurts, because: " << ex.what() << "!" << endl;
    }
  } else {
    cout << "Pass config filename as first argument to program" << endl;
  }
  
  return 0;
}
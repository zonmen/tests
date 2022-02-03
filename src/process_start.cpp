#include "process_start.h"

pid_t start_process(set_prog_start &program) {
  pid_t pid;
  // create new process
  pid = fork();
  if (pid == -1) {
    // error of creation process
    std::cout << "error" << std::endl;
    exit(1);
  } else if (pid != 0) {
    // parent process
    // return child pid
    return pid;
  } else {
    // child process
    // save executable path into string
    std::string path = program.executable_path + "/" + program.name;
    // number of process arguments(first - program name, last - NULL)
    int argc = program.cmd_arguments.size() + 2;
    // pointer to process arguments
    char **argv = new char *[argc];
    // first argument - program name
    int word_length = 0;
    word_length = program.name.length() + 1;
    argv[0] = new char[word_length];
    // copy program name to arguments array
    strncpy(argv[0], program.name.c_str(), word_length);
    // copy all arguments to arguments array
    for (int i = 1; i < argc - 1; i++) {
      word_length = program.cmd_arguments[i - 1].length() + 1;
      argv[i] = new char[word_length];
      strncpy(argv[i], program.cmd_arguments[i - 1].c_str(), word_length);
    }
    // last arguments - NULL
    argv[argc - 1] = nullptr;
    // check if we need to redirect programm's stdout
    if (program.stdout_config_file.size() != 0) {
      // change file mode depending of stdout_mode
      if (program.stdout_config_truncate) {
        // truncate - true
        freopen(program.stdout_config_file.c_str(), "w", stdout);
      } else {
        // append - false
        freopen(program.stdout_config_file.c_str(), "a", stdout);
      }
    }
    // change run program status
    program.run_prog = true;
    // start new process(change current process to new)
    if (execv(path.c_str(), argv) == -1) {
      // error occurred, program isn't executed
      //!!! stdout stream doesn't work here(redirected to file)
      // change run program status
      program.run_prog = false;
      delete[] argv;
      // string to display error
      std::string error_name;
      error_name.append("Process abort\n");
      error_name.append("Name = ");
      error_name.append(program.name);
      error_name.append(", pid = ");
      // get pid of this process
      error_name.append(std::to_string(getpid()));
      error_name.append("\nError type");
      // print error log
      perror(error_name.c_str());
      // closed child process(errno - id last error)
      exit(errno);
    }
    // these line is never reached(things below just for cppchecker)
    delete[] argv;
    return -1;
  }
}
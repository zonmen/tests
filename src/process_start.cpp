#include "process_start.h"

#include "logger.h"

pid_t start_process(set_prog_start &program) {
  pid_t process_pid;
  // create new process
  process_pid = fork();
  if (process_pid == -1) {
    // error of creation process
    LOG("Error in process_start. Function fork(), couldn't do fork, for "
        "program_name: " +
            program.name,
        ERROR);
    return 0;
  } else if (process_pid != 0) {
    // parent process
    // return child pid
    return process_pid;
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
      // change file mode depending of stdout_mode config
      char file_mode = 0;
      if (program.stdout_config_truncate) {
        // true - truncate
        file_mode = 'w';
      } else {
        // false - append
        file_mode = 'a';
      }
      // open a log file
      if (!freopen(program.stdout_config_file.c_str(), &file_mode, stdout)) {
        // it doesn't open
        // close stdout
        fclose(stdout);
        LOG("Error in process_start. Function freopen(), couldn't open stdout "
            "config "
            "file: " +
                program.stdout_config_file,
            ERROR);
      }
    }
    // change run program status
    program.pid = getpid();
    // start new process(change current process to new)
    if (execv(path.c_str(), argv) == -1) {
      // error occurred, program isn't executed
      //!!! stdout stream doesn't work here(redirected to file)
      // change run program status
      program.pid = 0;
      // delete argv array
      for (int i = 0; i < argc; i++) {
        delete[] argv[i];
      }
      delete[] argv;
      argv = nullptr;
      // add error info
      std::string error_message(
          "Error in proscess_start. Function execv(), couldn't start program, "
          "error_info: ");
      error_message.append(strerror(errno));
      LOG(error_message, ERROR);
      exit(1);
    }
    // these line is never reached(things below just for cppchecker)
    delete[] argv;
    return -1;
  }
}
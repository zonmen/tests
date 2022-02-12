#include "../../src/process_start.cpp"

#include <gtest/gtest.h>

TEST(process_start_test, ParentHandles) {
  set_prog_start test_program = {
      .name = "echo",
      .executable_path = "/bin/",
      .stdout_config_file = "",
      .stdout_config_truncate = 0,
      .pid = 0,
      .cmd_arguments = {},
  };
  int result = start_process(test_program);
  // value_1 > value_2
  EXPECT_GT(result, 0);

  // check fork -1 case
}

// TEST(process_start_test, ChildHandles) {
// set_prog_start test_program = {.name = "",
//                                .executable_path = "",
//                                .stdout_config_file = "",
//                                .stdout_config_truncate = 0,
//                                .pid = 0,
//                                .cmd_arguments = {"arg1", "arg2"}};

// }
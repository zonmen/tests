#include "../../src/yaml_parse.cpp"

#include <gtest/gtest.h>

#include "../../src/logger.cpp"

TEST(yaml_parce_test, BasicAssertions) {
  std::vector<set_prog_start> parced = parse_yaml("../tests/example_1.yml");

  EXPECT_EQ(parced[0].name, "a1");
  EXPECT_EQ(parced[0].executable_path, "a2");
  EXPECT_EQ(parced[0].stdout_config_file, "");
  EXPECT_EQ(parced[0].stdout_config_truncate, true);
  EXPECT_EQ(parced[0].cmd_arguments.size(), 0);

  EXPECT_EQ(parced[1].name, "b1");
  EXPECT_EQ(parced[1].executable_path, "b2");
  EXPECT_EQ(parced[1].stdout_config_file, "b3");
  EXPECT_EQ(parced[1].stdout_config_truncate, true);
  EXPECT_EQ(parced[1].cmd_arguments.size(), 0);

  EXPECT_EQ(parced[2].name, "c1");
  EXPECT_EQ(parced[2].executable_path, "c2");
  EXPECT_EQ(parced[2].stdout_config_file, "c3");
  EXPECT_EQ(parced[2].stdout_config_truncate, false);
  EXPECT_EQ(parced[2].cmd_arguments.size(), 0);

  EXPECT_EQ(parced[3].name, "d1");
  EXPECT_EQ(parced[3].executable_path, "d2");
  EXPECT_EQ(parced[3].stdout_config_file, "");
  EXPECT_EQ(parced[3].stdout_config_truncate, false);
  EXPECT_EQ(parced[3].cmd_arguments.size(), 0);

  EXPECT_EQ(parced[4].name, "e1");
  EXPECT_EQ(parced[4].executable_path, "e2");
  EXPECT_EQ(parced[4].stdout_config_file, "e3");
  EXPECT_EQ(parced[4].stdout_config_truncate, true);
  EXPECT_EQ(parced[4].cmd_arguments.size(), 0);

  EXPECT_EQ(parced[5].name, "f1");
  EXPECT_EQ(parced[5].executable_path, "f2");
  EXPECT_EQ(parced[5].stdout_config_file, "f3");
  EXPECT_EQ(parced[5].stdout_config_truncate, true);
  EXPECT_EQ(parced[5].cmd_arguments[0], "f4");
  EXPECT_EQ(parced[5].cmd_arguments.size(), 1);

  EXPECT_EQ(parced[6].name, "g1");
  EXPECT_EQ(parced[6].executable_path, "g2");
  EXPECT_EQ(parced[6].stdout_config_file, "g3");
  EXPECT_EQ(parced[6].stdout_config_truncate, true);
  EXPECT_EQ(parced[6].cmd_arguments[0], "g4");
  EXPECT_EQ(parced[6].cmd_arguments[1], "g5");
  EXPECT_EQ(parced[6].cmd_arguments.size(), 2);
}
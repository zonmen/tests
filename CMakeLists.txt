project(DeLorianExecutionManager)
cmake_minimum_required(VERSION 3.11) 


include_directories(include
                    src)

add_executable(main 
              src/logger.cpp
              src/main.cpp 
              src/yaml_parse.cpp
              src/process_start.cpp)	


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")



include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  tests
  tests/unit
  tests/unit/tests.cpp
  tests/unit/yaml_parse_test.cpp
  tests/unit/process_start_test.cpp
)
target_link_libraries(
  tests
  gtest_main
  gmock_main
)

include(GoogleTest)
gtest_discover_tests(tests)


# make target for gcov reports(if we have gcovr app)
find_program( GCOVR_PATH gcovr PATHS ${CMAKE_SOURCE_DIR}/scripts/test)
if(GCOVR_PATH)
  # add special cmake file to use gcov
  LIST(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/tests/code_coverage")
  include(CodeCoverage)
  append_coverage_compiler_flags()
   # we need to turn off optimization for non-skewed coverage reports
  set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O0")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
  setup_target_for_coverage_gcovr_html(
            NAME code_coverage
            EXECUTABLE tests
            DEPENDENCIES tests
            EXCLUDE "build/_deps/*")
endif() # NOT GCOVR_PATH

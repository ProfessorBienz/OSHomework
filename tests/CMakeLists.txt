include_directories(${hw_INCDIR})

add_executable(additional_tests additional_tests.cpp)
target_link_libraries(additional_tests homework gtest)
add_test(AdditionalTests ./additional_tests)

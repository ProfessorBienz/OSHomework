include_directories(${hw_INCDIR})

add_executable(example example.cpp)
target_link_libraries(example mutex)

add_executable(example_spin example.cpp)
target_link_libraries(example_spin mutex)

add_executable(example_yield example.cpp)
target_link_libraries(example_yield mutex)

add_executable(example_queue example.cpp)
target_link_libraries(example_queue mutex)

add_executable(example_semaphore example.cpp)
target_link_libraries(example_semaphore mutex)


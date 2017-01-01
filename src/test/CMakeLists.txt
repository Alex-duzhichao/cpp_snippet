set(src_test_srcs 
    Singleton_test.cpp
    )

message(STATUS "gtest_SOURCE_DIR : " ${gtest_SOURCE_DIR})
message(STATUS "gmock_SOURCE_DIR : " ${gmock_SOURCE_DIR})
add_executable(Singleton_test ${src_test_srcs})
target_link_libraries(Singleton_test gtest gmock_main)
add_test(NAME Singleton_test_case COMMAND Singleton_test)


message(STATUS "gtest_SOURCE_DIR : " ${gtest_SOURCE_DIR})
message(STATUS "gmock_SOURCE_DIR : " ${gmock_SOURCE_DIR})

##########################################################
set(SingletonTest_srcs 
    SingletonTest.cpp
    GTestMain.cpp
    )

add_executable(SingletonTest ${SingletonTest_srcs})
target_link_libraries(SingletonTest gtest)
add_test(NAME SingletonTestCase COMMAND SingletonTest)

##########################################################
set(RandomGeneratorTest_srcs 
    RandomGeneratorTest.cpp
    GTestMain.cpp
    )

add_executable(RandomGeneratorTest ${RandomGeneratorTest_srcs})
target_link_libraries(RandomGeneratorTest gtest)
add_test(NAME RandomGeneratorTestCase COMMAND RandomGeneratorTest)

##########################################################
set(StdMinMaxTest_srcs 
    StdMinMaxTest.cpp
    GTestMain.cpp
    )

add_executable(StdMinMaxTest ${StdMinMaxTest_srcs})
target_link_libraries(StdMinMaxTest gtest)
add_test(NAME StdMinMaxTestCase COMMAND StdMinMaxTest)

##########################################################
set(TypeTransformTest_srcs 
    TypeTransformTest.cpp
    GTestMain.cpp
    )

add_executable(TypeTransformTest ${TypeTransformTest_srcs})
target_link_libraries(TypeTransformTest gtest)
add_test(NAME TypeTransformTestCase COMMAND TypeTransformTest)

##########################################################
set(GTestValueParameterizedTest_srcs 
    GTestValueParameterizedTest.cpp
    GTestMain.cpp
    )

add_executable(GTestValueParameterizedTest ${GTestValueParameterizedTest_srcs})
target_link_libraries(GTestValueParameterizedTest gtest)
add_test(NAME GTestValueParameterizedTestCase COMMAND GTestValueParameterizedTest)

##########################################################
set(GTestScopedTraceTest_srcs 
    GTestScopedTraceTest.cpp
    GTestMain.cpp
    )

add_executable(GTestScopedTraceTest ${GTestScopedTraceTest_srcs})
target_link_libraries(GTestScopedTraceTest gtest)
add_test(NAME GTestScopedTraceTestCase COMMAND GTestScopedTraceTest)

##########################################################
set(GTestTypeParameterizedTest_srcs 
    GTestTypeParameterizedTest.cpp
    GTestMain.cpp
    )

add_executable(GTestTypeParameterizedTest ${GTestTypeParameterizedTest_srcs})
target_link_libraries(GTestTypeParameterizedTest gtest)
add_test(NAME GTestTypeParameterizedTestCase COMMAND GTestTypeParameterizedTest)

##########################################################
set(GTestSampleFunctionTest_srcs 
    GTestSampleFunctionTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    GTestMain.cpp
    )

add_executable(GTestSampleFunctionTest ${GTestSampleFunctionTest_srcs})
target_link_libraries(GTestSampleFunctionTest gtest)
add_test(NAME GTestSampleFunctionTestCase COMMAND GTestSampleFunctionTest)

##########################################################
set(GTestSampleClassTest_srcs 
    GTestSampleClassTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    GTestMain.cpp
    )

add_executable(GTestSampleClassTest ${GTestSampleClassTest_srcs})
target_link_libraries(GTestSampleClassTest gtest)
add_test(NAME GTestSampleClassTestCase COMMAND GTestSampleClassTest)

##########################################################
set(GTestSampleFixtureTest_srcs 
    GTestSampleFixtureTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    GTestMain.cpp
    )

add_executable(GTestSampleFixtureTest ${GTestSampleFixtureTest_srcs})
target_link_libraries(GTestSampleFixtureTest gtest)
add_test(NAME GTestSampleFixtureTestCase COMMAND GTestSampleFixtureTest)

##########################################################
set(GTestSampleFixtureReuseTest_srcs 
    GTestSampleFixtureReuseTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    GTestMain.cpp
    )

add_executable(GTestSampleFixtureReuseTest ${GTestSampleFixtureReuseTest_srcs})
target_link_libraries(GTestSampleFixtureReuseTest gtest)
add_test(NAME GTestSampleFixtureReuseTestCase COMMAND GTestSampleFixtureReuseTest)

##########################################################
set(GTestSampleListenerLeakCheckerTest_srcs 
    GTestSampleListenerLeakCheckerTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    )

add_executable(GTestSampleListenerLeakCheckerTest ${GTestSampleListenerLeakCheckerTest_srcs})
target_link_libraries(GTestSampleListenerLeakCheckerTest gtest)
add_test(NAME GTestSampleListenerLeakCheckerTestCase COMMAND GTestSampleListenerLeakCheckerTest)

##########################################################
set(GTestSampleListenerOutputTest_srcs 
    GTestSampleListenerOutputTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    )

add_executable(GTestSampleListenerOutputTest ${GTestSampleListenerOutputTest_srcs})
target_link_libraries(GTestSampleListenerOutputTest gtest)
add_test(NAME GTestSampleListenerOutputTestCase COMMAND GTestSampleListenerOutputTest)

##########################################################
set(GTestSampleTypeParameterizedTest_srcs 
    GTestSampleTypeParameterizedTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    GTestMain.cpp
    )

add_executable(GTestSampleTypeParameterizedTest ${GTestSampleTypeParameterizedTest_srcs})
target_link_libraries(GTestSampleTypeParameterizedTest gtest)
add_test(NAME GTestSampleTypeParameterizedTestCase COMMAND GTestSampleTypeParameterizedTest)

##########################################################
set(GTestSampleInterfaceTest_srcs 
    GTestSampleInterfaceTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    GTestMain.cpp
    )

add_executable(GTestSampleInterfaceTest ${GTestSampleInterfaceTest_srcs})
target_link_libraries(GTestSampleInterfaceTest gtest)
add_test(NAME GTestSampleInterfaceTestCase COMMAND GTestSampleInterfaceTest)

##########################################################
set(GTestSampleCombineTest_srcs 
    GTestSampleCombineTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    GTestMain.cpp
    )

add_executable(GTestSampleCombineTest ${GTestSampleCombineTest_srcs})
target_link_libraries(GTestSampleCombineTest gtest)
add_test(NAME GTestSampleCombineTestCase COMMAND GTestSampleCombineTest)

##########################################################
set(GTestReverseGuardTest_srcs 
    GTestReverseGuardTest.cpp
    GTestMain.cpp
    )

add_executable(GTestReverseGuardTest ${GTestReverseGuardTest_srcs})
target_link_libraries(GTestReverseGuardTest gtest)
add_test(NAME GTestReverseGuardTestCase COMMAND GTestReverseGuardTest)


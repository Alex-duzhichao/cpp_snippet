message(STATUS "gtest_SOURCE_DIR : " ${gtest_SOURCE_DIR})
message(STATUS "gmock_SOURCE_DIR : " ${gmock_SOURCE_DIR})

##########################################################
set(SingletonTest_srcs 
    SingletonTest.cpp
    GTestMain.cpp
    )

add_executable(SingletonTest ${SingletonTest_srcs})
target_link_libraries(SingletonTest gtest gmock)
add_test(NAME SingletonTestCase COMMAND SingletonTest)

##########################################################
set(RandomGeneratorTest_srcs 
    RandomGeneratorTest.cpp
    GTestMain.cpp
    )

add_executable(RandomGeneratorTest ${RandomGeneratorTest_srcs})
target_link_libraries(RandomGeneratorTest gtest gmock)
add_test(NAME RandomGeneratorTestCase COMMAND RandomGeneratorTest)

##########################################################
set(StdAlgorithmTest_srcs 
    StdAlgorithmTest.cpp
    GTestMain.cpp
    )

add_executable(StdAlgorithmTest ${StdAlgorithmTest_srcs})
target_link_libraries(StdAlgorithmTest gtest gmock)
add_test(NAME StdAlgorithmTestCase COMMAND StdAlgorithmTest)

##########################################################
set(TypeTransformTest_srcs 
    TypeTransformTest.cpp
    GTestMain.cpp
    )

add_executable(TypeTransformTest ${TypeTransformTest_srcs})
target_link_libraries(TypeTransformTest gtest gmock)
add_test(NAME TypeTransformTestCase COMMAND TypeTransformTest)

##########################################################
set(GTestValueParameterizedTest_srcs 
    GTestValueParameterizedTest.cpp
    GTestMain.cpp
    )

add_executable(GTestValueParameterizedTest ${GTestValueParameterizedTest_srcs})
target_link_libraries(GTestValueParameterizedTest gtest gmock)
add_test(NAME GTestValueParameterizedTestCase COMMAND GTestValueParameterizedTest)

##########################################################
set(GTestScopedTraceTest_srcs 
    GTestScopedTraceTest.cpp
    GTestMain.cpp
    )

add_executable(GTestScopedTraceTest ${GTestScopedTraceTest_srcs})
target_link_libraries(GTestScopedTraceTest gtest gmock)
add_test(NAME GTestScopedTraceTestCase COMMAND GTestScopedTraceTest)

##########################################################
set(GTestTypeParameterizedTest_srcs 
    GTestTypeParameterizedTest.cpp
    GTestMain.cpp
    )

add_executable(GTestTypeParameterizedTest ${GTestTypeParameterizedTest_srcs})
target_link_libraries(GTestTypeParameterizedTest gtest gmock)
add_test(NAME GTestTypeParameterizedTestCase COMMAND GTestTypeParameterizedTest)

##########################################################
set(GTestSampleFunctionTest_srcs 
    GTestSampleFunctionTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    GTestMain.cpp
    )

add_executable(GTestSampleFunctionTest ${GTestSampleFunctionTest_srcs})
target_link_libraries(GTestSampleFunctionTest gtest gmock)
add_test(NAME GTestSampleFunctionTestCase COMMAND GTestSampleFunctionTest)

##########################################################
set(GTestSampleClassTest_srcs 
    GTestSampleClassTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    GTestMain.cpp
    )

add_executable(GTestSampleClassTest ${GTestSampleClassTest_srcs})
target_link_libraries(GTestSampleClassTest gtest gmock)
add_test(NAME GTestSampleClassTestCase COMMAND GTestSampleClassTest)

##########################################################
set(GTestSampleFixtureTest_srcs 
    GTestSampleFixtureTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    GTestMain.cpp
    )

add_executable(GTestSampleFixtureTest ${GTestSampleFixtureTest_srcs})
target_link_libraries(GTestSampleFixtureTest gtest gmock)
add_test(NAME GTestSampleFixtureTestCase COMMAND GTestSampleFixtureTest)

##########################################################
set(GTestSampleFixtureReuseTest_srcs 
    GTestSampleFixtureReuseTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    GTestMain.cpp
    )

add_executable(GTestSampleFixtureReuseTest ${GTestSampleFixtureReuseTest_srcs})
target_link_libraries(GTestSampleFixtureReuseTest gtest gmock)
add_test(NAME GTestSampleFixtureReuseTestCase COMMAND GTestSampleFixtureReuseTest)

##########################################################
set(GTestSampleListenerLeakCheckerTest_srcs 
    GTestSampleListenerLeakCheckerTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    )

add_executable(GTestSampleListenerLeakCheckerTest ${GTestSampleListenerLeakCheckerTest_srcs})
target_link_libraries(GTestSampleListenerLeakCheckerTest gtest gmock)
add_test(NAME GTestSampleListenerLeakCheckerTestCase COMMAND GTestSampleListenerLeakCheckerTest)

##########################################################
set(GTestSampleListenerOutputTest_srcs 
    GTestSampleListenerOutputTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    )

add_executable(GTestSampleListenerOutputTest ${GTestSampleListenerOutputTest_srcs})
target_link_libraries(GTestSampleListenerOutputTest gtest gmock)
add_test(NAME GTestSampleListenerOutputTestCase COMMAND GTestSampleListenerOutputTest)

##########################################################
set(GTestSampleTypeParameterizedTest_srcs 
    GTestSampleTypeParameterizedTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    GTestMain.cpp
    )

add_executable(GTestSampleTypeParameterizedTest ${GTestSampleTypeParameterizedTest_srcs})
target_link_libraries(GTestSampleTypeParameterizedTest gtest gmock)
add_test(NAME GTestSampleTypeParameterizedTestCase COMMAND GTestSampleTypeParameterizedTest)

##########################################################
set(GTestSampleInterfaceTest_srcs 
    GTestSampleInterfaceTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    GTestMain.cpp
    )

add_executable(GTestSampleInterfaceTest ${GTestSampleInterfaceTest_srcs})
target_link_libraries(GTestSampleInterfaceTest gtest gmock)
add_test(NAME GTestSampleInterfaceTestCase COMMAND GTestSampleInterfaceTest)

##########################################################
set(GTestSampleCombineTest_srcs 
    GTestSampleCombineTest.cpp
    GTestSampleHelperFunctionAndClass.cpp
    GTestMain.cpp
    )

add_executable(GTestSampleCombineTest ${GTestSampleCombineTest_srcs})
target_link_libraries(GTestSampleCombineTest gtest gmock)
add_test(NAME GTestSampleCombineTestCase COMMAND GTestSampleCombineTest)

##########################################################
set(ReverseGuardTest_srcs 
    ReverseGuardTest.cpp
    GTestMain.cpp
    )

add_executable(ReverseGuardTest ${ReverseGuardTest_srcs})
target_link_libraries(ReverseGuardTest gtest gmock)
add_test(NAME ReverseGuardTestCase COMMAND ReverseGuardTest)

##########################################################
set(CGITest_srcs 
    CGITest.cpp
    ../CGI.cpp
    GTestMain.cpp
    )

add_executable(CGITest ${CGITest_srcs})
target_link_libraries(CGITest gtest gmock)
add_test(NAME CGITestCase COMMAND CGITest)

##########################################################
set(EaStlTest_srcs 
    EaStlTest.cpp
    GTestMain.cpp
    )

add_executable(EaStlTest ${EaStlTest_srcs})
target_link_libraries(EaStlTest gtest gmock)
add_test(NAME EaStlTestCase COMMAND EaStlTest)

##########################################################
set(TemplateTest_srcs 
    TemplateTest.cpp
    GTestMain.cpp
    )

add_executable(TemplateTest ${TemplateTest_srcs})
target_link_libraries(TemplateTest gtest gmock)
add_test(NAME TemplateTestCase COMMAND TemplateTest)

##########################################################
set(SwapTest_srcs 
    SwapTest.cpp
    GTestMain.cpp
    )

add_executable(SwapTest ${SwapTest_srcs})
target_link_libraries(SwapTest gtest gmock)
add_test(NAME SwapTestCase COMMAND SwapTest)

##########################################################
set(GTestMockTest_srcs 
    GTestMockTest.cpp
    GTestMain.cpp
    )

add_executable(GTestMockTest ${GTestMockTest_srcs})
target_link_libraries(GTestMockTest gtest gmock)
add_test(NAME GTestMockTestCase COMMAND GTestMockTest)

##########################################################
set(TreeTest_srcs 
    TreeTest.cpp
    GTestMain.cpp
    )

add_executable(TreeTest ${TreeTest_srcs})
target_link_libraries(TreeTest gtest gmock)
add_test(NAME TreeTestCase COMMAND TreeTest)

##########################################################
set(FunctionTest_srcs 
    FunctionTest.cpp
    GTestMain.cpp
    )

add_executable(FunctionTest ${FunctionTest_srcs})
target_link_libraries(FunctionTest gtest gmock)
add_test(NAME FunctionTestCase COMMAND FunctionTest)

##########################################################
set(SortTest_srcs 
    SortTest.cpp
    GTestMain.cpp
    )

add_executable(SortTest ${SortTest_srcs})
target_link_libraries(SortTest gtest gmock)
add_test(NAME SortTestCase COMMAND SortTest)

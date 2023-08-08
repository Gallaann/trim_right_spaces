set(TESTS_BINARY_DIR ${CMAKE_BINARY_DIR}/test)
file(MAKE_DIRECTORY ${TESTS_BINARY_DIR})

# Create bash script to run test executables
file(WRITE ${TESTS_BINARY_DIR}/run_test.sh "#!/bin/bash\n")

function(add_test_and_update_script TEST_NAME TEST_EXECUTABLE_PATH)
    file(APPEND ${TESTS_BINARY_DIR}/run_test.sh "echo '' '---------------------------------------'")
    file(APPEND ${TESTS_BINARY_DIR}/run_test.sh "echo 'Executing test: ''${TEST_NAME}'' ''")
    file(APPEND ${TESTS_BINARY_DIR}/run_test.sh "echo '---------------------------------------' ''")
    file(APPEND ${TESTS_BINARY_DIR}/run_test.sh "${TEST_EXECUTABLE_PATH}\n")
endfunction()

# Set execute permissions for run_test.sh
file(
        INSTALL ${TESTS_BINARY_DIR}/run_test.sh
        DESTINATION ${TESTS_BINARY_DIR}
        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
)

execute_process(
        COMMAND chmod +x ${TESTS_BINARY_DIR}/run_test.sh
)

set(TEST_EXECUTABLE TrimRightTest)

add_executable(${TEST_EXECUTABLE} "")

set(TRIM_RIGHT_DIR "${PROJECT_SOURCE_DIR}/trim_right")

set(PRIVATE_INCLUDE_DIRECTORIES
        "${TRIM_RIGHT_DIR}/include"
)

target_include_directories(${TEST_EXECUTABLE} PRIVATE ${PRIVATE_INCLUDE_DIRECTORIES})

target_sources(${TEST_EXECUTABLE} PRIVATE
        "test.cpp"
)

set(PRIVATE_LINK_LIBRARIES
        "GTest::gtest_main"
        "${TRIM_RIGHT}"
)

target_link_libraries(${TEST_EXECUTABLE} PRIVATE ${PRIVATE_LINK_LIBRARIES})

include(GoogleTest)
gtest_discover_tests(${TEST_EXECUTABLE})

add_test_and_update_script (TEST_EXECUTABLE ${TESTS_BINARY_DIR})

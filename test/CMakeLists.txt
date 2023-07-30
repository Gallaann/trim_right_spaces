set(TEST_BINARY_DIR ${CMAKE_BINARY_DIR}/test)
file(MAKE_DIRECTORY ${TEST_BINARY_DIR})

# Create bash script to run test executables
file(WRITE ${TEST_BINARY_DIR}/run_test.sh "#!/bin/bash\n")

function(add_test_and_update_script TEST_NAME TEST_EXECUTABLE_PATH)
    file(APPEND ${TEST_BINARY_DIR}/run_test.sh "echo '' '---------------------------------------'")
    file(APPEND ${TEST_BINARY_DIR}/run_test.sh "echo 'Executing test: ''${TEST_NAME}'' ''")
    file(APPEND ${TEST_BINARY_DIR}/run_test.sh "echo '---------------------------------------' ''")
    file(APPEND ${TEST_BINARY_DIR}/run_test.sh "${TEST_EXECUTABLE_PATH}\n")
endfunction()

# Set execute permissions for run_test.sh
file(
        INSTALL ${TEST_BINARY_DIR}/run_test.sh
        DESTINATION ${TEST_BINARY_DIR}
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

execute_process(
        COMMAND chmod +x ${TEST_BINARY_DIR}/run_test.sh
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
gtest_discover_test(${TEST_EXECUTABLE})

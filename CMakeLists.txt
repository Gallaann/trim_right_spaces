cmake_minimum_required(VERSION 3.26)
project(dr_web_test_task)

set(CMAKE_CXX_STANDARD 17)

option(CLEAR_CACHE "Set to \"ON\" to clear cache" ON)

option(ENABLE_TEST "Set to \"ON\" for test build" ON)

option(ENABLE_CLANG_FORMAT "Set to \"ON\" to add clang-format build target" OFF)

option(ENABLE_CLANG_TIDY "Set to \"ON\" to enable clang-tidy" OFF)
option(ENABLE_CPPLINT "Set to \"ON\" to enable cpplint" OFF)
option(ENABLE_CPPCHECK "Set to \"ON\" to enable cppcheck" OFF)

option(ENABLE_SANITIZER "Set to \"ON\" to enable sanitizer in debug build" OFF)

include(cmake/apply_options.cmake)

set(TRIM_RIGHT ${PROJECT_NAME}_trim_right)

add_subdirectory(trim_right)

add_executable(${PROJECT_NAME} "")

target_sources(${PROJECT_NAME} PUBLIC
        "example.cpp"
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${TRIM_RIGHT})

if (ENABLE_TEST)
    add_subdirectory(test)
endif()

if (CLEAR_CACHE)
    unset(ENABLE_TEST CACHE)

    unset(ENABLE_CLANG_FORMAT CACHE)
    unset(ENABLE_CPPLINT CACHE)
    unset(ENABLE_CLANG_TIDY CACHE)
    unset(ENABLE_CPPCHECK CACHE)

    unset(ENABLE_SANITIZER CACHE)
endif()

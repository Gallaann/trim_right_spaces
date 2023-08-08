add_library(${TRIM_RIGHT} STATIC "")

target_sources(${TRIM_RIGHT} PRIVATE
        "src/TrimRight.cpp"
)

set(PUBLIC_INCLUDE_DIRECTORIES
        "include"
)

target_include_directories(${TRIM_RIGHT} PUBLIC ${PUBLIC_INCLUDE_DIRECTORIES})

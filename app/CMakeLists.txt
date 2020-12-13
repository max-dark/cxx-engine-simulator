cmake_minimum_required(VERSION 3.15)

add_executable(simulator)

target_sources(simulator
    PRIVATE
        main.cxx
)

target_link_libraries(simulator
    PRIVATE
        engine
)

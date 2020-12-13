cmake_minimum_required(VERSION 3.15)

add_library(utility STATIC)

target_sources(utility
    PRIVATE
        utility/piecewiselinearfunction.cxx
    PUBLIC
        utility/piecewiselinearfunction.hxx
)

target_include_directories(utility
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(engine STATIC)

target_sources(engine
    PUBLIC
        engine/engine.hxx
        engine/icengine.hxx
        engine/enginetest.hxx
        engine/overheattest.hxx
    PRIVATE
        engine/engine.cxx
        engine/icengine.cxx
        engine/enginetest.cxx
        engine/overheattest.cxx
)
target_include_directories(engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(engine
    PUBLIC
        utility
)
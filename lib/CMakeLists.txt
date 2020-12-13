cmake_minimum_required(VERSION 3.15)

add_library(engine STATIC)

target_sources(engine
    PUBLIC
        engine/engine.hxx
        engine/icengine.hxx
        engine/enginetest.hxx
    PRIVATE
        engine/engine.cxx
        engine/icengine.cxx
        engine/enginetest.cxx
)
target_include_directories(engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
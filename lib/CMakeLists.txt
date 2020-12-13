cmake_minimum_required(VERSION 3.15)

add_library(engine STATIC)

target_sources(engine
    PUBLIC
        engine/engine.hxx
    PRIVATE
        engine/engine.cxx
)

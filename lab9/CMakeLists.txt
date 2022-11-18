cmake_minimum_required(VERSION 3.4)

project(lab9 LANGUAGES CXX)

add_library(circle Circle.cpp)
add_library(shape shape.cpp)
# cxx_constexpr is a usage-requirement
target_compile_features(circle PUBLIC cxx_std_11)
target_compile_features(shape PUBLIC cxx_std_11)

add_executable(a.out
    main.cpp
)

target_link_libraries(circle shape a.out)

target_compile_features(a.out PUBLIC cxx_std_11)

function(print)
    foreach(var ${ARGN})
        message("${var} = ${${var}}")
    endforeach()
endfunction()

print(PROJECT_NAME)

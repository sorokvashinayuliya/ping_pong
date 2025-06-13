cmake_minimum_required(VERSION 3.15)
project(PongV2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
    GIT_SHALLOW TRUE
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
set(SHARED OFF CACHE BOOL "" FORCE)
set(USE_AUDIO ON CACHE BOOL "" FORCE)
set(PLATFORM "Desktop" CACHE STRING "" FORCE)
set(GRAPHICS "GRAPHICS_API_OPENGL_43" CACHE STRING "" FORCE)

FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE SOURCES 
    "src/*.cpp" 
    "tests/*.cpp"  
)
file(GLOB_RECURSE HEADERS "include/*.h")

add_executable(${PROJECT_NAME} 
    ${SOURCES} 
    ${HEADERS}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    include
    ${raylib_SOURCE_DIR}/src
    ${raylib_SOURCE_DIR}/src/external
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    raylib
    opengl32
    gdi32
    winmm
)

if(EXISTS "${CMAKE_SOURCE_DIR}/assets")
    file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/Release)
    file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/Debug)
endif()

if(MSVC)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS "/SUBSYSTEM:CONSOLE"
    )
endif()
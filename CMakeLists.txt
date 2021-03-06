cmake_minimum_required(VERSION 2.8.4)
project(hackpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

if (WIN32)
  set(CMAKE_LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
  set(CMAKE_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
endif(WIN32)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
  set(CMAKE_CXX_FLAGS_RELEASE "{CMAKE_CXX_FLAGS -O2")
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
endif()

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

set(ENGINE_SRC  ${PROJECT_SOURCE_DIR}/engine/Render/App.cpp
                ${PROJECT_SOURCE_DIR}/engine/Render/Renderable.cpp)

set(HACKPP_SRC  ${PROJECT_SOURCE_DIR}/main.cpp)

add_executable(hackpp ${ENGINE_SRC} ${HACKPP_SRC})
target_link_libraries(hackpp ${SDL2_LIBRARY})

if (WIN32)
  add_custom_command(TARGET hackpp
                     POST_BUILD COMMAND ${CMAKE_COMMAND} -E echo "Detected Win32 build env, copying DLLs...")
                     
  file(GLOB SDL2_DLLS
       "${SDL2_INCLUDE_DIR}/../../bin/*.dll")

  foreach( file_i ${SDL2_DLLS} )
    add_custom_command(TARGET hackpp
                       POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy_if_different ${file_i} $<TARGET_FILE_DIR:hackpp>)
    add_custom_command(TARGET hackpp POST_BUILD COMMAND ${CMAKE_COMMAND} -E echo ${file_i})
  endforeach( file_i )
endif()

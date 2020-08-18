cmake_minimum_required( VERSION 3.5 )

project( poker )

set( CMAKE_CXX_FLAGS " -Wall -Werror -O2 -Wextra -std=c++17 -Wno-error=maybe-uninitialized" )

include_directories( ${CMAKE_STAGING_PREFIX}/usr/include )
link_directories( ${CMAKE_STAGING_PREFIX}/usr/lib )

# find_package(Boost 1.73.0 REQUIRED COMPONENTS program_options)
# if(Boost_FOUND)
#   include_directories( ${Boost_INCLUDE_DIRS} )
# endif()

option(SPDLOG_LOGGING "Use spdlog for logging" ON)

if( SPDLOG_LOGGING )
add_definitions("-DSPGLOG_LOGGING_ENABLED -DSPDLOG_COMPILED_LIB")
endif()

option(TCMALLOC "Use tcmalloc for allocating memory" OFF)

set( POKER_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/lib )

add_subdirectory( ${POKER_LIBRARY} )
add_subdirectory( poker )
add_subdirectory( calculator )

cmake_minimum_required( VERSION 3.5 )

project( poker )

set ( exe_src_files
      src/main.cpp
)

add_executable( ${PROJECT_NAME} ${exe_src_files} )

target_include_directories( ${PROJECT_NAME} PRIVATE ${POKER_LIBRARY}/include/poker )
target_include_directories( ${PROJECT_NAME} PRIVATE ${POKER_LIBRARY}/include/logging )

target_link_libraries( ${PROJECT_NAME} poker_lib )

if( TCMALLOC )
target_link_libraries( ${PROJECT_NAME} tcmalloc )
endif()

if( SPDLOG_LOGGING )
target_link_libraries( ${PROJECT_NAME} spdlog )
target_link_libraries( ${PROJECT_NAME} pthread )
endif()
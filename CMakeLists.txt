cmake_minimum_required( VERSION 3.5 )

project( poker_odds )

set( CMAKE_CXX_FLAGS " -Wall -Werror -Wextra -O2 -std=c++17 -DSPDLOG_COMPILED_LIB " )

include_directories( ${CMAKE_STAGING_PREFIX}/usr/include )
link_directories( ${CMAKE_STAGING_PREFIX}/usr/lib )

find_package(Boost 1.73.0 REQUIRED COMPONENTS program_options)
if(Boost_FOUND)
  include_directories( ${Boost_INCLUDE_DIRS} )
endif()

set ( src_files
      src/engines/FindPairs.cpp
      src/engines/FindRuns.cpp
      src/HandDatabase.cpp
      src/ResolveSameRankWinner.cpp
      src/CalculateOdds.cpp
      src/ComparePlayerHands.cpp
      src/TransposeHands.cpp
      src/ValidateHand.cpp
      src/PossibleHands.cpp
      src/Hand.cpp
      src/Dealer.cpp
      src/Player.cpp
      src/DeckBuilder.cpp
      src/ShuffleDeck.cpp
      src/main.cpp
)

add_executable( ${PROJECT_NAME} ${src_files} )

target_include_directories( ${PROJECT_NAME} PRIVATE include )
target_include_directories( ${PROJECT_NAME} PRIVATE include/engines )

target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )

target_link_libraries( ${PROJECT_NAME} spdlog )

target_link_libraries( ${PROJECT_NAME} pthread )

set ( src_files_test
      src/engines/FindPairs.cpp
      src/engines/FindRuns.cpp
      src/Hand.cpp
      src/TransposeHands.cpp
      src/ValidateHand.cpp
      src/DeckBuilder.cpp
      src/HandDatabase.cpp
      test/TestSuiteFindPairs.cpp
      test/TestSuiteFindRuns.cpp
      test/TestSuiteHandRank.cpp
      test/TestSuiteSuit.cpp
      test/TestSuiteRank.cpp
      test/TestSuiteTranspose.cpp
      test/TestSuiteCard.cpp
      test/TestSuiteHand.cpp
      test/TestSuitePermutations.cpp
      test/TestSuiteHandDatabase.cpp
)

add_executable( test_poker_odds ${src_files_test} )

target_include_directories( test_poker_odds PRIVATE include )
target_include_directories( test_poker_odds PRIVATE include/engines )

target_link_libraries( test_poker_odds gtest )
target_link_libraries( test_poker_odds gtest_main )
target_link_libraries( test_poker_odds gmock )

target_link_libraries( test_poker_odds spdlog )

target_link_libraries( test_poker_odds pthread )
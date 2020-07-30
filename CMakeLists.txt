cmake_minimum_required( VERSION 3.5 )

project( poker )

set( CMAKE_CXX_FLAGS " -Wall -Werror -O2 -Wextra -std=c++17 " )

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

set ( lib_src_files
      src/engines/FindHighCard.cpp
      src/hands/HandFactory.cpp
      src/hands/HighCardHand.cpp
      src/hands/OnePairHand.cpp
      src/hands/TwoPairHand.cpp
      src/hands/ThreeOfAKindHand.cpp
      src/hands/StraightAceLowHand.cpp
      src/hands/StraightHand.cpp
      src/hands/FlushHand.cpp
      src/hands/FourOfAKindHand.cpp
      src/hands/FullHouseHand.cpp
      src/hands/StraightFlushAceLowHand.cpp
      src/hands/StraightFlushHand.cpp
      src/hands/RoyalFlushHand.cpp
      src/hands/ExplicitHand.cpp
      src/hands/BaseHand.cpp
      src/cards/BaseCard.cpp
      src/poker/Poker.cpp
      src/poker/PokerImpl.cpp
      src/player/Player.cpp
      src/CalculateOdds.cpp
      src/Dealer.cpp
      src/DeckBuilder.cpp
      src/ShuffleDeck.cpp
)

add_library( ${PROJECT_NAME}_lib STATIC ${lib_src_files} )

target_include_directories( ${PROJECT_NAME}_lib PRIVATE include )
target_include_directories( ${PROJECT_NAME}_lib PRIVATE include/engines )
target_include_directories( ${PROJECT_NAME}_lib PRIVATE include/hands )
target_include_directories( ${PROJECT_NAME}_lib PRIVATE include/cards )
target_include_directories( ${PROJECT_NAME}_lib PRIVATE include/poker )
target_include_directories( ${PROJECT_NAME}_lib PRIVATE include/logging )
target_include_directories( ${PROJECT_NAME}_lib PRIVATE include/state )
target_include_directories( ${PROJECT_NAME}_lib PRIVATE include/buffer )
target_include_directories( ${PROJECT_NAME}_lib PRIVATE include/statistics )
target_include_directories( ${PROJECT_NAME}_lib PRIVATE include/player )

# target_link_libraries( ${PROJECT_NAME}_lib ${Boost_LIBRARIES} )

if( TCMALLOC )
target_link_libraries( ${PROJECT_NAME}_lib tcmalloc )
endif()

if( SPDLOG_LOGGING )
target_link_libraries( ${PROJECT_NAME}_lib spdlog )
target_link_libraries( ${PROJECT_NAME}_lib pthread )
endif()

set ( exe_src_files
      src/main.cpp
)

add_executable( ${PROJECT_NAME} ${exe_src_files} )

target_include_directories( ${PROJECT_NAME} PRIVATE include/poker )
target_include_directories( ${PROJECT_NAME} PRIVATE include/logging )

target_link_libraries( ${PROJECT_NAME} ${PROJECT_NAME}_lib )

if( TCMALLOC )
target_link_libraries( ${PROJECT_NAME} tcmalloc )
endif()

if( SPDLOG_LOGGING )
target_link_libraries( ${PROJECT_NAME} spdlog )
target_link_libraries( ${PROJECT_NAME} pthread )
endif()

option(ENABLE_UNIT_TESTS "Enable unit tests" ON)

set ( src_files_test
      src/engines/FindHighCard.cpp
      src/hands/HandFactory.cpp
      src/hands/HighCardHand.cpp
      src/hands/OnePairHand.cpp
      src/hands/TwoPairHand.cpp
      src/hands/ThreeOfAKindHand.cpp
      src/hands/StraightAceLowHand.cpp
      src/hands/StraightHand.cpp
      src/hands/FlushHand.cpp
      src/hands/FourOfAKindHand.cpp
      src/hands/FullHouseHand.cpp
      src/hands/StraightFlushAceLowHand.cpp
      src/hands/StraightFlushHand.cpp
      src/hands/RoyalFlushHand.cpp
      src/hands/ExplicitHand.cpp
      src/hands/BaseHand.cpp
      src/cards/BaseCard.cpp
      src/player/Player.cpp
      src/DeckBuilder.cpp
      test/TestSuiteFindHighCard.cpp
      test/TestSuiteFindPairs.cpp
      test/TestSuiteFindAllPairs.cpp
      test/TestSuiteFindStraightsAndFlushes.cpp
      test/TestSuiteHandRank.cpp
      test/TestSuiteSuit.cpp
      test/TestSuiteRank.cpp
      test/TestSuiteCard.cpp
      test/TestSuiteHand.cpp
      test/TestSuitePermutations.cpp
      test/TestSuitePossibleHands.cpp
      test/TestSuiteHandFactory.cpp
      test/TestSuiteValidateHand.cpp
      test/TestSuiteWinningHands.cpp
      test/main.cpp
)

if( ENABLE_UNIT_TESTS )
add_executable( test_poker_odds ${src_files_test} )

target_include_directories( test_poker_odds PRIVATE include )
target_include_directories( test_poker_odds PRIVATE include/engines )
target_include_directories( test_poker_odds PRIVATE include/hands )
target_include_directories( test_poker_odds PRIVATE include/cards )
target_include_directories( test_poker_odds PRIVATE include/buffer )
target_include_directories( test_poker_odds PRIVATE include/statistics )
target_include_directories( test_poker_odds PRIVATE include/player )

target_link_libraries( test_poker_odds gtest )
target_link_libraries( test_poker_odds gtest_main )
target_link_libraries( test_poker_odds gmock )

if( SPDLOG_LOGGING )
target_link_libraries( test_poker_odds spdlog )
target_link_libraries( test_poker_odds pthread )
endif()

endif()
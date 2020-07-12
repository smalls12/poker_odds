cmake_minimum_required( VERSION 3.5 )

project( poker_odds )

set( CMAKE_CXX_FLAGS " -Wall -Werror -Wextra -O2 -std=c++17 " )

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

set ( lib_src_files
      src/engines/FindHighCard.cpp
      src/engines/FindPairs.cpp
      src/engines/FindStraightsAndFlushes.cpp
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
      src/hands/BaseHand.cpp
      src/cards/BaseCard.cpp
      src/poker/Poker.cpp
      src/poker/PokerImpl.cpp
      src/AnalyzeRounds.cpp
      src/DealerPermutations.cpp
      src/HandDatabase.cpp
      src/CalculateOdds.cpp
      src/ComparePlayerHands.cpp
      src/TransposeHands.cpp
      src/ValidateHand.cpp
      src/PossibleHands.cpp
      src/Dealer.cpp
      src/Player.cpp
      src/DeckBuilder.cpp
      src/ShuffleDeck.cpp
)

add_library( ${PROJECT_NAME} STATIC ${lib_src_files} )

target_include_directories( ${PROJECT_NAME} PRIVATE include )
target_include_directories( ${PROJECT_NAME} PRIVATE include/engines )
target_include_directories( ${PROJECT_NAME} PRIVATE include/hands )
target_include_directories( ${PROJECT_NAME} PRIVATE include/cards )
target_include_directories( ${PROJECT_NAME} PRIVATE include/poker )
target_include_directories( ${PROJECT_NAME} PRIVATE include/logging )

# target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )

if( SPDLOG_LOGGING )
target_link_libraries( ${PROJECT_NAME} spdlog )
target_link_libraries( ${PROJECT_NAME} pthread )
endif()

set ( exe_src_files
      src/main.cpp
)

add_executable( poker ${exe_src_files} )

target_include_directories( poker PRIVATE include )
target_include_directories( poker PRIVATE include/engines )
target_include_directories( poker PRIVATE include/hands )
target_include_directories( poker PRIVATE include/cards )
target_include_directories( poker PRIVATE include/poker )
target_include_directories( poker PRIVATE include/logging )

target_link_libraries( poker ${PROJECT_NAME} )

if( SPDLOG_LOGGING )
target_link_libraries( poker spdlog )
target_link_libraries( poker pthread )
endif()

option(ENABLE_UNIT_TESTS "Enable unit tests" ON)

set ( src_files_test
      src/engines/FindHighCard.cpp
      src/engines/FindPairs.cpp
      src/engines/FindStraightsAndFlushes.cpp
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
      src/hands/BaseHand.cpp
      src/cards/BaseCard.cpp
      src/TransposeHands.cpp
      src/ValidateHand.cpp
      src/DeckBuilder.cpp
      src/HandDatabase.cpp
      src/DealerPermutations.cpp
      src/PossibleHands.cpp
      test/TestSuiteFindHighCard.cpp
      test/TestSuiteFindPairs.cpp
      test/TestSuiteFindStraightsAndFlushes.cpp
      test/TestSuiteHandRank.cpp
      test/TestSuiteSuit.cpp
      test/TestSuiteRank.cpp
      test/TestSuiteTranspose.cpp
      test/TestSuiteCard.cpp
      test/TestSuiteHand.cpp
      test/TestSuitePermutations.cpp
      test/TestSuiteHandDatabase.cpp
      test/TestSuiteDealerPermutations.cpp
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

target_link_libraries( test_poker_odds gtest )
target_link_libraries( test_poker_odds gtest_main )
target_link_libraries( test_poker_odds gmock )

if( SPDLOG_LOGGING )
target_link_libraries( test_poker_odds spdlog )
target_link_libraries( test_poker_odds pthread )
endif()

endif()
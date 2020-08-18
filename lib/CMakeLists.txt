cmake_minimum_required( VERSION 3.5 )

project( poker_lib )

set ( lib_src_files
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
      src/calculator/Calculator.cpp
      src/calculator/CalculatorImpl.cpp
      src/player/Player.cpp
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
target_include_directories( ${PROJECT_NAME} PRIVATE include/state )
target_include_directories( ${PROJECT_NAME} PRIVATE include/buffer )
target_include_directories( ${PROJECT_NAME} PRIVATE include/statistics )
target_include_directories( ${PROJECT_NAME} PRIVATE include/player )
target_include_directories( ${PROJECT_NAME} PRIVATE include/calculator )
target_include_directories( ${PROJECT_NAME} PRIVATE include/pool )

# target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )

if( TCMALLOC )
target_link_libraries( ${PROJECT_NAME} tcmalloc )
endif()

if( SPDLOG_LOGGING )
target_link_libraries( ${PROJECT_NAME} spdlog )
target_link_libraries( ${PROJECT_NAME} pthread )
endif()

option(ENABLE_UNIT_TESTS "Enable unit tests" ON)

set ( src_files_test
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
      test/TestSuiteFindStraights.cpp
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
target_include_directories( test_poker_odds PRIVATE include/state )
target_include_directories( test_poker_odds PRIVATE include/buffer )
target_include_directories( test_poker_odds PRIVATE include/statistics )
target_include_directories( test_poker_odds PRIVATE include/player )
target_include_directories( test_poker_odds PRIVATE include/pool )

target_link_libraries( test_poker_odds gtest )
target_link_libraries( test_poker_odds gtest_main )
target_link_libraries( test_poker_odds gmock )

if( SPDLOG_LOGGING )
target_link_libraries( test_poker_odds spdlog )
target_link_libraries( test_poker_odds pthread )
endif()

endif()
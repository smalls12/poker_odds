#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "HandDatabase.hpp"

class TestSuiteHandDatabase : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteHandDatabase() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteHandDatabase() {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case for Project1.
};

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access the test fixture (from google test primer)
TEST_F(TestSuiteHandDatabase, DISABLED_Testing)
{
    HandDatabase handDatabase;
}

// }  // namespace - could surround Project1Test in a namespace
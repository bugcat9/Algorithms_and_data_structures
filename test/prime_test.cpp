#include "prime.h"
#include <gtest/gtest.h>

TEST(Primes, case0) 
{

	EXPECT_EQ(GetPrimes(10), 4);
}

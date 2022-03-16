// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

#include <iostream>
#include <string>
#include <bitset>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);

  //Test Case 3
  //Test whether the LFSR works, for 16 bits, after 2^16-1 steps, 
  //the bits should be shifted back to its orignal state.
  FibLFSR l3("1010101010010101");
  
  for (int i = 0; i < ((1<<16) - 1); i++)
  {
    l3.step();
  }

  BOOST_REQUIRE(l3 == "1010101010010101");
  //End of Test Case 3

  //Test Case 4
  //This test checks whether the seed has 16 bits or not, 
  //because if it doesn not, the tapping position 
  //wouldn't be right, and it some cases, it may crash
  //the program
  FibLFSR l4("0100110000100110");
  int bit_count = l4.getLength();
  BOOST_REQUIRE(bit_count == 16);
  //End of Tesst Case 4
}


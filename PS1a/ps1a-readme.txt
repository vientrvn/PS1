/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt
 **********************************************************************/

Name: Vien Tran
Hours to complete assignment: About 7.5 hours in total
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
- This program produces pseudo-random bits by simulating a linear
Feedback shift register.
- I've accomplished most of the checkpoints such as implementing the 
Constructor, step() function, generate() function and overloading the 
outStream operator.
- Also produced two additional Boost tests

/**********************************************************************
 *  Explain the representation you used for the register bits 
 *  (how it works, and why you selected it)
 **********************************************************************/
- I just use std::bitset as the internal representation for the seed.
- Bitset is a class template that can represent a fixed-size sequence
of bits. 
- The reason why I selected it is because for exactly how it works for 
convenience and efficiency. Bitsets can be handled and modified by
Standard logic operators and easily converted from and to other data 
types.
- I also used int to store the number of bits of the seed, and use that
data for one of the Boost unit tests.
 
/**********************************************************************
 * Discuss what's being tested in your two additional Boost unit tests
  **********************************************************************/
- The first addtional Boost unit tests whether the LFSR worked properly,
for a 16-bit seed, after 2^16-1 times of shifting, it should be shifted 
back to its original state.
- The second additional Boost unit tests if the seed as 16 bits or not,
because if it does not, the tapping position wouldn't be right, and in 
some cases, it may even crash the program

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
- Keep failing at linking boost library to Xcode, a peer suggested to
just run boost in Mac Terminal instead of in Xcode (which later found
out that didn't work in terminal either)
- A classmate suggested to use std::bitset to make everything easier.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
- Error codes from missing boost.hpp
- Tried to link boost library to Xcode for couple hours and kept failing.
- Decided to just run test.cpp in terminal instead of in the IDE Xcode
but that also failed.
- Fixed this during the 24-hour grace window by running the tests in 
cs server and that worked.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

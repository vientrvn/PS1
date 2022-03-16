//
//  FibLFSR.h
//  PS1a
//
//  Created by Vien Tran on 1/31/22.
//

#ifndef FibLFSR_h
#define FibLFSR_h

#include <iostream>
#include <bitset>

class FibLFSR {
public:
    FibLFSR(std::string seed); // constructor to create LFSR with the given initial seed
    int step(); // simulate one step and return the new bit as 0 or 1
    int generate(int k); // simulate k steps and return k-bit integer

    int getLength(void) const;
    
    friend bool operator==(const FibLFSR &leftOp, const std::string &rightOp);
    friend std::ostream& operator<< (std::ostream& outStream, const FibLFSR& seed);
private:
    std::bitset<16> initSeed;
    int length;
};

#endif /* FibLFSR_h */

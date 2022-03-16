//
//  FibLFSR.cpp
//  PS1a
//
//  Created by Vien Tran on 1/31/22.
//

#include <iostream>
#include <bitset>
#include <string>
#include "FibLFSR.h"

// constructor to create LFSR with the given initial seed
FibLFSR::FibLFSR(std::string seed) {
    std::bitset<16> tempSeed(seed);
    initSeed = tempSeed;
    length = seed.size();
}

// simulate one step and return the new bit as 0 or 1
int FibLFSR::step() {
    int result = ((initSeed[15] ^ initSeed[13]) ^ initSeed[12]) ^ initSeed[10];
    initSeed <<= 1;
    initSeed |= result;
    
    return result;
}

// simulate k steps and return k-bit integer
int FibLFSR::generate(int k) {
    int var = 0;
    
    for (int i  = 0; i < k; i++) {
        var = var * 2 + step();
    }
    
    return var;
}

int FibLFSR::getLength(void) const {
    return length;
}

std::ostream& operator<< (std::ostream& outStream, const FibLFSR& seed) {
    outStream << seed.initSeed;
    
    return outStream;
}

bool operator==(const FibLFSR &leftOp, const std::string &rightOp){
    std::string lHS = leftOp.initSeed.to_string();
    return lHS == rightOp;
}



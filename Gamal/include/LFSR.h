#ifndef LFSR_H
#define LFSR_H
#include "RC4.h"

class LFSR
{
    public:
        LFSR(int,vector<int>,vector<int>);
        void fill_seed();

    private:
        vector<int> our_seed;
        int n_bits;
        vector<int> tap;

};

#endif // LFSR_H

//
// Created by nstan on 14/05/2022.
//

#ifndef GENTLEASSERT_H
#define GENTLEASSERT_H
#include <iostream>

using namespace std;

#ifdef NDEBUG
int tRun = 0;
int tPass = 0;

#define gentle_assert(EX) (void)( ((__doTest(), 1) && (EX)) || (__gentle_asset (#EX, __FILE__, __LINE__),0))

void __doTest() {
    tRun++;
    tPass++;
}

void __gentle_asset(const char *msg, const char *file, int line) {
    cerr << "Assertion failed in " << file << ":" << endl << "\t" << msg << endl;
    tPass--;
    cerr << tRun << endl;
}
#endif

#endif //GENTLEASSERT_H

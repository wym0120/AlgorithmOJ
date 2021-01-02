/**
 * <------Description------>
 * There are Infinite People Standing in a row, indexed from 1.
 * A person having index 'i' has strength of (i*i).You have Strength 'P'.
 * You need to tell what is the maximum number of People You can Kill With your Strength P.
 * You can only Kill a person with strength 'X' if P >= 'X' and after killing him, Your Strength decreases by 'X'.
 *
 * <------Input------>
 * First line contains an integer 'T' - the number of testcases,Each of the next 'T' lines contains an integer 'P'- Your Power.Constraints:1<=T<=100001<=P<=1000000000000000
 *
 * <------Output------>
 * For each testcase Output The maximum Number of People You can kill.
 *
 * */

#include <iostream>

using namespace std;

void CountMaxP(long p) {
    long count = 0;
    long index = 1;
    while (p >= 0) {
        p -= index * index;
        index++;
        count++;
    }
    count--;
    cout << count << endl;
}

int main() {
    long T, P;
    cin >> T;
    for (long i = 0; i < T; i++) {
        cin >> P;
        CountMaxP(P);
    }
    return 0;
}


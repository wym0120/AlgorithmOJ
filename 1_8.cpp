/**
 * <------Description------>
 * Implement Pow(A, B) % C.In other words, given A, B and C, find (A^B)%C
 *
 * <------Input------>
 * The first line of input consists number of the test cases.
 * The following T lines consist of 3 numbers each separated by a space and in the following order:A B C
 * 'A' being the base number, 'B' the exponent (power to the base number) and 'C' the modular.
 * Constraints:1 ≤ T ≤ 70,1 ≤ A ≤ 10^5,1 ≤ B ≤ 10^5,1 ≤ C ≤ 10^5
 *
 * <------Output------>
 * In each separate line print the modular exponent of the given numbers in the test case.
 * */

#include <iostream>

using namespace std;

long long int Pow(long long int A, long long int B, long long int C) {
    long long int result = 1;
    A = A % C;
    while (B > 0) {
        if (B & 1) {
            result = (result * A) % C;
        }
        B >>= 1;
        A = (A * A) % C;
    }
    return result;

}

int main() {
    int T;
    cin >> T;
    while (T > 0) {
        long long A, B, C;
        cin >> A >> B >> C;
        cout << Pow(A, B, C) << endl;
        T--;
    }
}

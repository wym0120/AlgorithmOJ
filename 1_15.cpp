/**
 * <------Description------>
 * Given an array of N distinct elementsA[ ], find the minimum number of swaps required to sort the array.
 * Your are required to complete the function which returns an integer denoting the minimum number of swaps, required to sort the array.
 *
 * <------Input------>
 * The first line of input contains an integer T denoting the no of test cases .
 * Then T test cases follow . Each test case contains an integer N denoting the no of element of the array A[ ].
 * In the next line are N space separated values of the array A[ ] .(1<=T<=100;1<=N<=100;1<=A[] <=1000)
 *
 * <------Output------>
 * For each test case in a new line output will be an integer denoting minimum umber of swaps that are required to sort the array.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T > 0) {
        int length = 0;
        cin >> length;
        vector<int> v;
        int value = 0;
        int i = 0;
        while (i < length) {
            cin >> value;
            v.push_back(value);
            i++;
        }
        vector<int> sorted_v(v);
        sort(sorted_v.begin(), sorted_v.end());

        int count = 0;
        for (int j = 0; j < length; j++) {
            if (sorted_v[j] != v[j]) {
                for (int k = 0; k < length; k++) {
                    if (v[k] == sorted_v[j]) {
                        swap(v[k], v[j]);
                    }
                }
                count++;
            }
        }
        cout << count << endl;
        T--;
    }
}
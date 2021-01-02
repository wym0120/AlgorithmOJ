/**
 * <------Description------>
 * Implement insert sort
 * <------Input------>
 * First number n is the length of array which followed by n numbers to be sorted.
 * <------Output------>
 * Sorted array
 * */

#include<iostream>
#include<vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int T = 0;
    cin >> T;
    cin.get();
    const string delimiter = " ";
    while (T > 0) {
        string input;
        getline(cin, input);
        stringstream iss(input);
        vector<int> v;
        int number;
        while (iss >> number) {
            v.push_back(number);
        }
        sort(v.begin(), v.end());
        stringstream s;
        copy(v.begin(), v.end(), ostream_iterator<int>(s, delimiter.c_str()));
        cout << s.str().substr(0, s.str().size() - 1) << endl;
        T--;
    }
}

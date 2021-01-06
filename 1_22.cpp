/**
 * <------Description------>
 * Implement shell sort
 * <------Input------>
 *
 * <------Output------>
 *
 * */

#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

void read_line_to_vec(vector<int> &v) {
    string input;
    getline(cin, input);
    stringstream iss(input);
    int value;
    while (iss >> value) {
        v.push_back(value);
    }
}

void printVec(vector<int> &v) {
    const string delimiter = " ";
    stringstream s;
    copy(v.begin(), v.end(), ostream_iterator<int>(s, delimiter.c_str()));
    cout << s.str().substr(0, s.str().size() - 1) << endl;
}

int main() {
    int T;
    cin >> T;
    cin.get();
    while (T-- > 0) {
        vector<int> nums, intervals;
        ReadLineToVec(nums);
        ReadLineToVec(intervals);
        int length = nums.size();
        // assert(step > 0, decrease, contains 1)
        for (int step : intervals) {
            for (int offset = 0; offset < step; offset++) {
                // subarr: [ off, step + off, step * 2 + off, step * 3 + off, ... ]
                for (int i = offset; i < length; i += step) {
                    int prev = i - step, next = i;
                    while (prev >= 0 && nums[prev] > nums[next]) {
                        swap(nums[prev], nums[next]);
                        prev -= step;
                        next -= step;
                    }
                }
            }
        }
        printVec(nums);
    }
}


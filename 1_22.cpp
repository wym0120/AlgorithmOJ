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

void ReadLineToVec(vector<int> &v) {
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
    while (T > 0) {
        vector<int> nums, intervals;
        ReadLineToVec(nums);
        ReadLineToVec(intervals);
        int length = nums.size();
        for (auto it:intervals) {
            for (int i = it; i < length; i++) {
                for (int j = i - it; j >= 0; j -= it) {
                    if (nums[j] > nums[j + it]) {
                        swap(nums[j], nums[j + it]);
                    }
                }
            }
        }
        printVec(nums);
        T--;
    }
}


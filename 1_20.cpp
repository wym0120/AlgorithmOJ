/**
 * <------Description------>
 * Implement non-recursive merge sort.
 *
 * <------Input------>
 * Array to be sorted
 *
 * <------Output------>
 * Sorted array
 *
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

void read_line_to_vec(vector<int> &v, string &input) {
    stringstream iss(input);
    int length, num;
    iss >> length;
    for (int i = 0; i < length; i++) {
        iss >> num;
        v.emplace_back(num);
    }
}

void merge(vector<int> &nums, vector<int> &tmp, int L1, int R1, int L2, int R2) {
    while (L1 <= R1 && L2 <= R2) {
        if (nums[L1] < nums[L2]) {
            tmp.emplace_back(nums[L1]);
            L1++;
        } else {
            tmp.emplace_back(nums[L2]);
            L2++;
        }
    }
    bool l1_remain = L1 <= R1;
    bool l2_remain = !l1_remain;
    if (l1_remain) {
        while (L1 <= R1) {
            tmp.emplace_back(nums[L1]);
            L1++;
        }
    } else if (l2_remain) {
        while (L2 <= R2) {
            tmp.emplace_back(nums[L2]);
            L2++;
        }
    }
}

void merge_sort(vector<int> &nums) {
    int step = 1;
    int array_length = nums.size();
    while (step <= array_length) {
        int i = 0;
        while (i < array_length) {
            int L1 = i;
            int R1 = i + step - 1;
            int L2 = i + step;
            int R2 = min(i + step * 2 - 1, (int) (nums.size() - 1));
            //make sure l2 have elements
            if (L2 > array_length - 1) break;
            vector<int> tmp;
            merge(nums, tmp, L1, R1, L2, R2);
            for (int j = 0; j < 2 * step; j++) {
                nums[i + j] = tmp[j];
            }
            i += step * 2;
        }
        step *= 2;
    }
}

void print_res(vector<int> &nums) {
    const string delimiter = " ";
    stringstream s;
    copy(nums.begin(), nums.end(), ostream_iterator<int>(s, delimiter.c_str()));
    cout << s.str().substr(0, s.str().size() - 1) << endl;
}

int main() {
    string input;
    while (getline(cin, input) && !input.empty()) {
        vector<int> nums;
        read_line_to_vec(nums, input);
        merge_sort(nums);
        print_res(nums);
    }
}
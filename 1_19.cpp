/**
 * <------Description------>
 * Implement non-recursive quick sort.
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
#include <stack>

using namespace std;

void print_res(vector<int> &nums) {
    const string delimiter = " ";
    stringstream s;
    copy(nums.begin(), nums.end(), ostream_iterator<int>(s, delimiter.c_str()));
    cout << s.str().substr(0, s.str().size() - 1) << endl;
}

void read_line_to_vec(vector<int> &v, string &input) {
    stringstream iss(input);
    int length, num;
    iss >> length;
    for (int i = 0; i < length; i++) {
        iss >> num;
        v.emplace_back(num);
    }
}

int partition(vector<int> &nums, int low, int high) {
    int mid = (low + high) / 2;
    int pivot = nums[mid];
    int left = low - 1, right = high + 1;
    while (true) {
        do {
            left++;
        } while (nums[left] < pivot);
        do {
            right--;
        } while (nums[right] > pivot);
        if (left >= right) {
#ifdef DEBUG
            print_res(nums);
#endif
            return right;
        }
        swap(nums[left], nums[right]);
    }
}

void merge_sort(vector<int> &nums) {
    stack<int> low_high_stack;
    int low = 0;
    int high = (int) (nums.size() - 1);
    low_high_stack.push(low);
    low_high_stack.push(high);
    while (!low_high_stack.empty()) {
        high = low_high_stack.top();
        low_high_stack.pop();
        low = low_high_stack.top();
        low_high_stack.pop();
        int pivot_index = partition(nums, low, high);
        if (pivot_index > low) {
            low_high_stack.push(low);
            low_high_stack.push(pivot_index);
        }
        if (pivot_index < high) {
            low_high_stack.push(pivot_index + 1);
            low_high_stack.push(high);
        }
    }
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
/**
 * <------Description------>
 * Find the maximum sum produced by any subset under the condition:
 * The elements present in the subset should not have any digit in common.
 * Note: Subset {12, 36, 45} does not have any digit in common and Subset {12, 22, 35} have digits in common.
 *
 * <------Input------>
 * First Line of the input consist of an integer T denoting the number of test cases.
 * Then T test cases follow. Each test case consist of a numbe N denoting the length of the array.
 * Second line of each test case consist of N space separated integers denoting the array elements.
 * Constraints:
 * 1 <= T <= 100
 * 1 <= N <= 100
 *
 * <------Output------>
 * Corresponding to each test case, print output in the new line.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            nums.emplace_back(num);
        }
        //不是dp，类似某个一个元素选或不选，造成了一定影响，然后返回剩下部分的最值，pass
    }
}
/**
 * <------Description------>
 * Given an array, the task is to complete the function which finds the maximum sum subarray, where you may remove at most one element to get the maximum sum.
 * <------Input------>
 * 第一行为测试用例个数T；后面每两行表示一个用例，第一行为用例中数组长度N，第二行为数组具体内容。
 * <------Output------>
 * 每一行表示对应用例的结果。
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int length;
        cin >> length;
        vector<int> v;
        for (int i = 0; i < length; ++i) {
            int num;
            cin >> num;
            v.emplace_back(num);
        }

        int dp_i_0 = -2147483648;
        int dp_i_1 = -2147483648;
        int res = -2147483648;
        for (int i = 0; i < length; i++) {
            dp_i_1 = max(dp_i_0, dp_i_1 + v[i]);
            dp_i_0 = max(dp_i_0 + v[i], v[i]);
            res = max(res, max(dp_i_0, dp_i_1));
        }
        cout << res << endl;
    }
}
/**
 * <------Description------>
 * Given an array A of size N, find all combination of four elements in the array whose sum is equal to a given value K.
 * For example, if the given array is {10, 2, 3, 4, 5, 9, 7, 8} and K = 23, one of the quadruple is “3 5 7 8” (3 + 5 + 7 + 8 = 23).
 *
 * <------Input------>
 * The first line of input contains an integer T denoting the no of test cases.
 * Then T test cases follow. Each test case contains two lines.
 * The first line of input contains two integers N and K.
 * Then in the next line are N space separated values of the array.（1<=T<=100；1<=N<=100；-1000<=K<=1000；-100<=A[]<=100）
 *
 * <------Output------>
 * For each test case in a new line print all the quadruples present in the array separated by space which sums up to value of K.
 * Each quadruple is unique which are separated by a delimeter "$" and are in increasing order.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int res[101];
int pointer = 0;//pointer to last num

void SortVec(vector<int> &v, int length) {
    for (int i = 0; i < length; i++) {
        int num;
        cin >> num;
        v.emplace_back(num);
    }
    sort(v.begin(), v.end(), greater<>());
}

#ifdef DEBUG
void printVec(vector<int> &v) {
    const string delimiter = " ";
    stringstream s;
    copy(v.begin(), v.end(), ostream_iterator<int>(s, delimiter.c_str()));
    cout << s.str().substr(0, s.str().size() - 1) << endl;
}
#endif

void SumKNums(vector<int> &v, int target_sum, int array_length) {
    if (array_length < 0 || target_sum < 0) {
        return;
    }
    int last_number = v[array_length - 1];
    if (target_sum == last_number) {
        if (pointer == 3) {
            for (int i = 0; i < pointer; i++) {
                cout << res[i] << " ";
            }
            cout << last_number << "$";
        }
    }
    res[pointer++] = last_number; //put v[length-1] in res
    SumKNums(v, target_sum - last_number, array_length - 1);
    pointer--; //not put v[length-1] in res
    SumKNums(v, target_sum, array_length - 1);
}

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int length, target_sum;
        cin >> length >> target_sum;
        vector<int> nums;
        SortVec(nums, length);
        SumKNums(nums, target_sum, length);
    }
}
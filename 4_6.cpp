/**
 * <------Description------>
 * Given an array of N numbers, we need to maximize the sum of selected numbers.
 * At each step, you need to select a number Ai, delete one occurrence of Ai-1 (if exists) and Ai each from the array.
 * Repeat these steps until the array gets empty. The problem is to maximize the sum of selected numbers.
 *
 * <------Input------>
 * The first line of the input contains T denoting the number of the test cases.
 * For each test case, the first line contains an integer n denoting the size of the array.
 * Next line contains n space separated integers denoting the elements of the array.
 * Constraints:1<=T<=100，1<=n<=50，1<=A[i]<=20
 * Note: Numbers need to be selected from maximum to minimum.
 *
 * <------Output------>
 * For each test case, the output is an integer displaying the maximum sum of selected numbers.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        //无意义题目，pass
    }
}
/**
 * <------Description------>
 * Dilpreet wants to paint his dog- Buzo's home that has n boards with different lengths[A1, A2,..., An].
 * He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.The problem is to find the minimum time to get this job done under the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.
 *
 * <------Input------>
 * The first line consists of a single integer T, the number of test cases.
 * For each test case, the first line contains an integer k denoting the number of painters and integer n denoting the number of boards.
 * Next line contains n- space separated integers denoting the size of boards.
 * Constraints:1<=T<=1001<=k<=301<=n<=501<=A[i]<=500
 *
 * <------Output------>
 * For each test case, the output is an integer displaying the minimum time for painting that house.
 * */

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool check_up_bound(vector<int> &v, int num_of_books, int num_of_students, int up_bound) {
    int cur_sum = 0;
    int cur_students = 1;
    for (int i = 0; i < num_of_books; i++) {
        if (cur_sum + v[i] > up_bound) {
            cur_students++;
            cur_sum = v[i];
        } else {
            cur_sum += v[i];
        }
    }
    return cur_students <= num_of_students;
}

void allocate(vector<int> &pages, int num_of_books, int num_of_students) {
    int start, end;
    int ans = INT_MAX;
    start = *max_element(pages.begin(), pages.end());
    end = accumulate(pages.begin(), pages.end(), 0);

    while (start <= end) {
        int mid = (int) ((end + start) / 2);
        bool success = check_up_bound(pages, num_of_books, num_of_students, mid);
        if (success) {
            ans = min(mid, ans);
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    cout << ((ans == INT_MAX) ? -1 : ans) << endl;
}

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int num_of_books, num_of_students;
        cin >> num_of_students >> num_of_books;
        vector<int> pages;
        for (int i = 0; i < num_of_books; i++) {
            int page;
            cin >> page;
            pages.push_back(page);
        }

        if (num_of_books < num_of_students) {
            cout << -1 << endl;
            return 0;
        } else {
            allocate(pages, num_of_books, num_of_students);
        }

    }
}
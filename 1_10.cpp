/**
 * <------Description------>
 * You are given N number of books.
 * Every ith book has Pi number of pages.
 * You have to allocate books to M number of students.
 * There can be many ways or permutations to do so.
 * In each permutation one of the M students will be allocated the maximum number of pages.
 * Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations, and print this minimum value. Each book will be allocated to exactly one student.
 * Each student has to be allocated at least one book.
 * Each Student can be allocated with contiguous books.
 *
 * <------Input------>
 * The first line contains 'T' denoting the number of testcases.
 * Then follows description of T testcases:Each case begins with a single positive integer N denoting the number of books.
 * The second line contains N space separated positive integers denoting the pages of each book.
 * And the third line contains another integer M, denoting the number of studentsConstraints:1<= T <=70，1<= N <=50，1<= A [ i ] <=250，1<= M <=50，Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see explanation for better understanding)
 *
 * <------Output------>
 * For each test case, output a single line containing minimum number of pages each student has to read for corresponding test case.
 * */

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

bool check_upbound(vector<int> &v, int num_of_books, int num_of_students, int up_bound) {
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
        bool success = check_upbound(pages, num_of_books, num_of_students, mid);
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
        int num_of_books;
        cin >> num_of_books;
        vector<int> pages;
        for (int i = 0; i < num_of_books; i++) {
            int page;
            cin >> page;
            pages.push_back(page);
        }
        int num_of_students;
        cin >> num_of_students;

        if (num_of_books < num_of_students) {
            cout << -1 << endl;
            return 0;
        } else {
            allocate(pages, num_of_books, num_of_students);
        }

    }
}
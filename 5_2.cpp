/**
 * <------Description------>
 * Description
 * There are two parallel roads, each containing N and M buckets, respectively.
 * Each bucket may contain some balls.
 * The buckets on both roads are kept in such a way that they are sorted according to the number of balls in them.
 * Geek starts from the end of the road which has the bucket with a lower number of balls
 * (i.e. if buckets are sorted in increasing order, then geek will start from the left side of the road).
 * The geek can change the road only at the point of intersection(which means, buckets with the same number of balls on two roads).
 * Now you need to help Geek to collect the maximum number of balls.
 *
 * <------Input------>
 * The first line of input contains T denoting the number of test cases.
 * The first line of each test case contains two integers N and M, denoting the number of buckets on road1 and road2 respectively.
 * 2nd line of each test case contains N integers, number of balls in buckets on the first road.
 * 3rd line of each test case contains M integers, number of balls in buckets on the second road.

 * <------Output------>
 * For each test case output a single line containing the maximum possible balls that Geek can collect.
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int N, M;
        cin >> N >> M;
        cin.get();
        vector<int> N_buckets;
        vector<int> M_buckets;
        string firstLine, secondLine;
        getline(cin, firstLine);
        getline(cin, secondLine);

        stringstream ss(firstLine);
        int num;
        while (ss >> num) {
            N_buckets.emplace_back(num);
        }
        stringstream ss2(secondLine);
        while (ss2 >> num) {
            M_buckets.emplace_back(num);
        }


        int i = 0, j = 0;
        int total = 0;
        int N_sum = 0, M_sum = 0;
        while (i < N && j < M) {
            if (N_buckets[i] < M_buckets[j]) {
                N_sum += N_buckets[i++];
            } else if (N_buckets[i] > M_buckets[j]) {
                M_sum += M_buckets[j++];
            } else {
                total += (max(N_sum, M_sum) + N_buckets[i]);
                i++;
                j++;
                N_sum = 0;
                M_sum = 0;
            }
        }

        while (j < M) {
            M_sum += M_buckets[j++];
        }
        while (i < N) {
            N_sum += N_buckets[i++];
        }
        total += max(N_sum, M_sum);

        cout << total << endl;
    }

}
/**
 * <------Description------>
 * Consider a big party where a log register for guest’s entry and exit times is maintained.
 * Find the time at which there are maximum guests in the party.
 * Note that entries in register are not in any order.
 *
 * <------Input------>
 * The first line of input contains an integer T denoting the number of test cases.
 * Then T test cases follow.
 * Each test case contains an integer n denoting the size of the entry and exit array.
 * Then the next two line contains the entry and exit array respectively.
 * (1<=T<=10^5;1<=N<=10^5;1<=entry[i],exit[i]<=10^5)
 *
 * <------Output------>
 * Print the maximum no of guests and the time at which there are maximum guests in the party.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

//#define DEBUG

using namespace std;

bool cmp(pair<int, bool> a, pair<int, bool> b) {
    if (a.first != b.first)return a.first < b.first;
    else return a.second > b.second;
}

int main() {
    int T;
    cin >> T;
    while (T > 0) {
        int length;
        cin >> length;
        vector<pair<int, bool>> v; // true for entry,false for exit
        for (int i = 0; i < length; i++) {
            int time;
            cin >> time;
            v.emplace_back(pair<int, bool>(time, true));
        }
        for (int i = 0; i < length; i++) {
            int time;
            cin >> time;
            v.emplace_back(pair<int, bool>(time, false));
        }
        sort(v.begin(), v.end(), cmp);
#ifdef DEBUG
        for(auto it:v){
            cout<<it.first<<" "<<it.second<<endl;
        }
#endif
        int current = 0, max = 0;
        int max_time = 0;
        for (auto it:v) {
            if (it.second) {
                current++;
                if (current > max) {
                    max = current;
                    max_time = it.first;
                }
            } else {
                current--;
            }
        }
        cout << max << " " << max_time << endl;
        T--;
    }
}
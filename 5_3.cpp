/**
 * <------Description------>
 * Given the list of coins of distinct denominations and total amount of money.
 * Output the minimum number of coins required to make up that amount.
 * Output -1 if that money cannot be made up using given coins.
 * You may assume that there are infinite numbers of coins of each type.
 *
 * <------Input------>
 * The first line contains ‘T’ denoting the number of test cases.
 * Then follows description of test cases.
 * Each cases begins with the two space separated integers ‘n’ and ‘amount’ denoting the total number of distinct coins and total amount of money respectively.
 * The second line contains N space-separated integers A1, A2, …, AN denoting the values of coins.
 *
 * <------Output------>
 * Print the minimum number of coins required to make up that amount or return -1 if it is impossible to make that amount using given coins.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    int const MAX = 100001;
    while (T-- > 0) {
        int types;
        int target;
        cin >> types >> target;
        vector<int> coins;
        for (int i = 0; i < types; i++) {
            int coin;
            cin >> coin;
            coins.emplace_back(coin);
        }

        vector<int> dp(target + 1, MAX);
        dp[0] = 0;
        for (int i = 1; i < target + 1; i++) {
            for (int j = 0; j < types; j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        if (dp[target] == MAX) {
            cout << -1 << endl;
        } else {
            cout << dp[target] << endl;
        }
    }
}
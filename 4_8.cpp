/**
 * <------Description------>
 * Rahul and Ankit are the only two waiters in Royal Restaurant.
 * Today, the restaurant received N orders.
 * The amount of tips may differ when handled by different waiters, if Rahul takes the ith order, he would be tipped Ai rupees
 * and if Ankit takes this order, the tip would be Bi rupees.In order to maximize the total tip value they decided to distribute the order among themselves.
 * One order will be handled by one person only. Also, due to time constraints Rahul cannot take more than X orders and Ankit cannot take more than Y orders.
 * It is guaranteed that X + Y is greater than or equal to N, which means that all the orders can be handled by either Rahul or Ankit.
 * Find out the maximum possible amount of total tip money after processing all the orders.
 *
 * <------Input------>
 * Input
 * • The first line contains one integer, number of test cases.
 * • The second line contains three integers N, X, Y.
 * • The third line contains N integers. The ith integer represents Ai.
 * • The fourth line contains N integers. The ith integer represents Bi.
 *
 * <------Output------>
 * Print a single integer representing the maximum tip money they would receive.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int N, X, Y;
        cin >> N >> X >> Y;
        vector<int> X_tips(N, 0);
        vector<int> Y_tips(N, 0);
        for (int i = 0; i < N; i++) {
            int X_tip;
            cin >> X_tip;
            X_tips[i] = X_tip;
        }
        for (int i = 0; i < N; i++) {
            int Y_tip;
            cin >> Y_tip;
            Y_tips[i] = Y_tip;
        }

        vector<vector<int>> dp(X + 1, vector<int>(Y + 1, 0));
        for (int i = 1; i < X + 1; i++) {
            dp[i][0] = dp[i - 1][0] + X_tips[i - 1];
        }
        for (int j = 1; j < Y + 1; j++) {
            dp[0][j] = dp[0][j - 1] + Y_tips[j - 1];
        }
        for (int i = 1; i < X + 1; i++) {
            for (int j = 1; j < Y + 1; j++) {
                if (i + j <= N) {
                    dp[i][j] = max(dp[i][j - 1] + Y_tips[i + j - 1], dp[i - 1][j] + X_tips[i + j - 1]);
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        cout << dp[X][Y] << endl;
    }
}
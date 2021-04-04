/**
 * <------Description------>
 * Rahul wanted to purchase vegetables mainly brinjal, carrot and tomato.
 * There are N different vegetable sellers in a line.
 * Each vegetable seller sells all three vegetable items, but at different prices.
 * Rahul, obsessed by his nature to spend optimally, decided not to purchase same vegetable from adjacent shops.
 * Also, Rahul will purchase exactly one type of vegetable item (only 1 kg) from one shop. Rahul wishes to spend minimum money buying vegetables using this strategy.
 * Help Rahul determine the minimum money he will spend.

 * <------Input------>
 * First line indicates number of test cases T.
 * Each test case in its first line contains N denoting the number of vegetable sellers in Vegetable Market.
 * Then each of next N lines contains three space separated integers denoting cost of brinjal, carrot and tomato per kg with that particular vegetable seller.
 *
 * <------Output------>
 * For each test case, output the minimum cost of shopping taking the mentioned conditions into account in a separate line.
 * Constraints:1 <= T <= 101 <= N <= 100000 Cost of each vegetable(brinjal/carrot/tomato) per kg does not exceed 10^4
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int num_of_shops;
        cin >> num_of_shops;
        vector<vector<int>> prices(num_of_shops, vector<int>(3, 0));
        for (int i = 0; i < num_of_shops; i++) {
            for (int j = 0; j < 3; j++) {
                int price;
                cin >> price;
                prices[i][j] = price;
            }
        }

        vector<vector<int>> dp(num_of_shops + 1, vector<int>(3, 0));
        for (int i = 0; i < 3; i++) {
            dp[0][i] = prices[0][i];
        }

        for (int i = 1; i < num_of_shops; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = prices[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
            }
        }

        cout << min(dp[num_of_shops - 1][0], min(dp[num_of_shops - 1][1], dp[num_of_shops - 1][2])) << endl;
    }
}
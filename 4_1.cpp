/**
 * <------Description------>
 * Given a grid with each cell consisting of positive, negative or no points i.e, zero points.
 * We can move across a cell only if we have positive points ( > 0 ).
 * Whenever we pass through a cell, points in that cell are added to our overall points.
 * We need to find minimum initial points to reach cell (m-1, n-1) from (0, 0) by following these certain set of rules :
 * 1.From a cell (i, j) we can move to (i+1, j) or (i, j+1).
 * 2.We cannot move from (i, j) if your overall points at (i, j) is <= 0.
 * 3.We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.
 *
 * <------Input------>
 * The first line contains an integer ‘T’ denoting the total number of test cases.
 * In each test cases, the first line contains two integer ‘R’ and ‘C’ denoting the number of rows and column of array.
 * The second line contains the value of the array i.e the grid, in a single line separated by spaces in row major order.
 * Constraints:
 * 1 ≤ T ≤ 30
 * 1 ≤ R,C ≤ 10
 * -30 ≤ A[R][C] ≤ 30
 *
 * Input: points[m][n] =
 * { {-2, -3, 3},
 * {-5, -10, 1},
 * {10, 30, -5}};
 *
 * <------Output------>
 * Print the minimum initial points to reach the bottom right most cell in a separate line.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int num;
                cin >> num;
                matrix[i][j] = num;
            }
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (matrix[m - 1][n - 1] > 0) {
            dp[m - 1][n - 1] = 1;
        } else {
            dp[m - 1][n - 1] = abs(matrix[m - 1][n - 1]) + 1;
        }

        for (int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = max(dp[i + 1][n - 1] - matrix[i][n - 1], 1);
        }

        for (int j = m - 2; j >= 0; j--) {
            dp[m - 1][j] = max(dp[m - 1][j + 1] - matrix[m - 1][j], 1);
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                int choose = min(dp[i][j + 1], dp[i + 1][j]);
                dp[i][j] = max(choose - matrix[i][j], 1);
            }
        }

        cout << dp[0][0] << endl;
    }
}
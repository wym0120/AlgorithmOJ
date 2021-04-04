/**
 * <------Description------>
 * 小张想要通过明天的考试。他知道考题的分值分布，也知道考试中要拿到每一个题目需要耗费的时间。
 * 假设考试时长为h，共n个题目，需要拿到p分才能通过考试。
 * 现在已知每个考题的得分与耗时，请你判断小张能否通过合理安排时间，而通过考试，并给出通过考试的最短时间。
 *
 * <------Input------>
 * 输入第一行为测试用例个数.每一个用例有若干行，第一行为任务数量n、考试时常h、通过分数p，下面的n行是每一个题目的耗时和得分。所有数值用空格分开。
 *
 * <------Output------>
 * 对每一个用例输出一行，如果能够通过考试，则输出“YES”和消耗最短时间，用空格隔开。 否则，输出“NO”。
 *
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int n, h, p;
        cin >> n >> h >> p;
        vector<int> times;
        vector<int> scores;
        for (int i = 0; i < n; i++) {
            int time, score;
            cin >> time >> score;
            times.emplace_back(time);
            scores.emplace_back(score);
        }

        vector<vector<int>> dp(n + 1, vector<int>(h + 1, 0));
        int min_time = 2147483647;
        bool find = false;
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < h + 1; j++) {
                int cur_time = times[i - 1];
                int cur_score = scores[i - 1];
                if (cur_time <= j) { // 可以放
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cur_time] + cur_score);
                } else { //不能放
                    dp[i][j] = dp[i - 1][j];
                }
                if (dp[i][j] >= p) {
                    find = true;
                    min_time = min(min_time, j);
                }
            }
        }
        if (find) {
            cout << "YES " << min_time << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
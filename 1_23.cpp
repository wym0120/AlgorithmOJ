/**
 * <------Description------>
 * 棋盘覆盖问题
 *
 * */

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int num = 1;

bool check_same_area(int x1, int y1, int x2, int y2, int x_center, int y_center) {
    double x1_p1 = ((double) x1 * 2 + 1) / 2;
    double y1_p1 = ((double) y1 * 2 + 1) / 2;
    double x2_p2 = ((double) x2 * 2 + 1) / 2;
    double y2_p2 = ((double) y2 * 2 + 1) / 2;
    bool not_same_area =
            (((x1_p1 - x_center) * (x2_p2 - x_center)) < 0) || (((y1_p1 - y_center) * (y2_p2 - y_center)) < 0);
    return !not_same_area;
}

void cover(vector<vector<int>> &chess_board, int x_start, int y_start, int x_special, int y_special, int length) {
    int x_center = x_start + length / 2;
    int y_center = y_start + length / 2;

    int group_num = num++;
    vector<pair<int, int>> special_point_list;
    vector<pair<int, int>> start_point_list;
    for (int i = x_center - 1; i <= x_center; i++) {
        for (int j = y_center - 1; j <= y_center; j++) {
            if (!check_same_area(i, j, x_special, y_special, x_center, y_center)) {
                chess_board[i][j] = group_num;
                special_point_list.emplace_back(pair<int, int>(i, j));
            } else {
                special_point_list.emplace_back(pair<int, int>(x_special, y_special));
            }
            int x_interval = abs(x_center - 1 - i);
            int y_interval = abs(y_center - 1 - j);
            int new_x_start = x_start + x_interval * length / 2;
            int new_y_start = y_start + y_interval * length / 2;
            start_point_list.emplace_back(pair<int, int>(new_x_start, new_y_start));
        }
    }
    if (length == 2) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        pair<int, int> special_point = special_point_list[i];
        pair<int, int> start_point = start_point_list[i];
        cover(chess_board, start_point.first, start_point.second, special_point.first, special_point.second,
              length / 2);
    }
}

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int length = pow(2, n);
        vector<vector<int>> chess_board(length, vector<int>(length));
        chess_board[x1][y1] = -1;
        cover(chess_board, 0, 0, x1, y1, length);
#ifdef DEBUG
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                cout << chess_board[i][j] << "\t";
            }
            cout << endl;
        }
#endif
        stringstream s;
        int target_group = chess_board[x2][y2];
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if ((chess_board[i][j] == target_group) && ((i != x2) || (j != y2))) {
                    s << i << " " << j << ",";
                }
            }
        }
        cout << s.str().substr(0, s.str().size() - 1) << endl;
    }
}
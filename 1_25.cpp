/**
 * <------Description------>
 * 对给定数组中的元素按照元素出现的次数排序，出现次数多的排在前面，如果出现次数相同，则按照数值大小排序。
 * 例如，给定数组为{2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12}，则排序后结果为{3, 3, 3, 3, 2, 2, 2, 12, 12, 4, 5}。
 *
 * <------Input------>
 * 输入的第一行为用例个数；后面每一个用例使用两行表示，第一行为数组长度，第二行为数组内容，数组元素间使用空格隔开。
 *
 * <------Output------>
 * 每一个用例的排序结果在一行中输出，元素之间使用空格隔开
 * */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> b) {
    if (a.second < b.second) {
        return false;
    } else if (a.second > b.second) {
        return true;
    } else {
        return a.first < b.first;
    }
}

void SortMap(map<int, int> &m) {
    vector<pair<int, int> > v;
    for (auto &it:m) {
        v.push_back(it);
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> res;
    for (auto &it:v) {
        int n = it.second;
        while (n > 0) {
            res.push_back(it.first);
            n--;
        }
    }
    const string delimiter = " ";
    stringstream s;
    copy(res.begin(), res.end(), ostream_iterator<int>(s, delimiter.c_str()));
    cout << s.str().substr(0, s.str().size() - 1) << endl;
}

int main() {
    int T;
    cin >> T;
    while (T > 0) {
        int n;
        cin >> n;
        map<int, int> m;
        while (n > 0) {
            int value;
            cin >> value;
            if (m.count(value)) {
                m[value] += 1;
            } else {
                m[value] = 1;
            }
            n--;
        }
        SortMap(m);
        T--;
    }
}


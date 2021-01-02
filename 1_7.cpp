/**
 * <------Description------>
 * Given a Complete Binary tree, print the level order traversal in sorted order.
 *
 * <------Input------>
 *
 * The first line of the input contains integer T denoting the number of test cases.
 * For each test case, the first line takes an integer n denoting the size of array
 * i.e number of nodes followed by n-space separated integers denoting the nodes of the tree in level order fashion.
 * (1<=T<=100；1<=n<=10^5)
 *
 * <------Output------>
 * For each test case, the output is the level order sorted tree. ( Note: For every level, we only print distinct elements.)
 *
 * */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int T, N = 0;
    cin >> T;

    while (T > 0) {
        cin >> N;
        vector<int> v;
        while (N > 0) {
            int num;
            cin >> num;
            v.push_back(num);
            N--;
        }
        int i = 0;
        int sum = 0;
        while (pow(2, i) - 1 < v.size()) {
            int head_offset = sum;
            int tail_offset = sum + (int) (pow(2, i));

            sort(v.begin() + head_offset, min(v.begin() + tail_offset, v.end()));
            sum += (int) (pow(2, i));
            i++;
            std::vector<int>::iterator it;
            for (it = v.begin() + head_offset; it != min(v.begin() + tail_offset, v.end()); ++it) {
                cout << ' ' << *it;
            }
            cout << endl;
        }
        T--;
    }
    return 0;
}
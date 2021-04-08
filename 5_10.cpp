#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.get();
    while (T-- > 0) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.emplace_back(num);
        }
        int width;
        cin >> width;
        cin.get();

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < width; i++) {
            pq.push(pair(nums[i], i));
        }

        int sum = pq.top().first;
        for (int i = width; i < nums.size(); i++) {
            pq.push(pair(nums[i], i));
            while (pq.top().second <= i - width) {
                pq.pop();
            }
            sum += pq.top().first;
        }

        cout << sum << endl;
    }
}
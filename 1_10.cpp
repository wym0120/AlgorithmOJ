/**
 * <------Description------>
 *
 * <------Input------>
 *
 * <------Output------>
 *
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T > 0) {
        int num_of_books;
        cin >> num_of_books;
        vector<int> books;
        for (int i = 0; i < num_of_books; i++) {
            int pages;
            cin >> pages;
            books.push_back(pages);
        }
        int num_of_students;
        cin >> num_of_students;
        T--;
    }
}
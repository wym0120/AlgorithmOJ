/**
 * <------Description------>
 * Implement bubble sort
 * <------Input------>
 * First number n is the length of array which followed by n numbers to be sorted.
 * <------Output------>
 * Sorted array
 * */

#include<iostream>
#include<vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;
int main(){
    int length = 0;
    cin >> length;
    const string delimiter = " ";
    vector<int> v;
    while (length > 0){
        int num = 0;
        cin >> num;
        v.push_back(num);
        length--;
    }
    sort(v.begin(),v.end());
    stringstream s;
    copy(v.begin(),v.end(),ostream_iterator<int>(s,delimiter.c_str()));
    cout << s.str().substr(0,s.str().size()-1) << endl;
}

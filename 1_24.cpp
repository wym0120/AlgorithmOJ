/**
 * <------Description------>
 * 最近对问题：使用分治算法解决最近对问题。
 *
 * <------Input------>
 * 第一行为测试用例个数。后面每一行表示一个用例，一个用例为一些平面上点的集合，点与点之间用逗号隔开，一个点的两个坐标用空格隔开。坐标值都是正数。
 *
 * <------Output------>
 * 对每一个用例输出两个距离最近的点（坐标使用空格隔开），用逗号隔开，先按照第一个坐标大小排列，再按照第二个坐标大小排列。
 * 如果有多个解，则按照每个解的第一个点的坐标排序，连续输出多个解，用逗号隔开。
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cfloat>


using namespace std;
//#define DEBUG

struct Point {
    explicit Point(const string &s) {
        stringstream point(s);
        point >> this->x;
        point >> this->y;
    }

    double x{};
    double y{};
};

bool compareX(Point A, Point B) {
    return A.x < B.x;
}

bool compareY(Point A, Point B) {
    return A.y < B.y;
}

vector<pair<Point, Point>> res;
double minDist = DBL_MAX;

void reset() {
    res.clear();
    minDist = DBL_MAX;
}

void printRes() {
    stringstream ss;
    for (pair<Point, Point> point_pair : res) {
        ss << point_pair.first.x << " " << point_pair.first.y
           << ","
           << point_pair.second.x << " " << point_pair.second.y
           << ",";
    }
    cout << ss.str().substr(0, ss.str().size() - 1) << endl;
}

void printPoints(vector<Point> &points) {
    for (Point p : points) {
        cout << p.x << " " << p.y << " ";
    }
    cout << endl;
}


void preSort(vector<Point> &sort_by_X, vector<Point> &sort_by_Y) {
    sort(sort_by_X.begin(), sort_by_X.end(), compareX);
    sort(sort_by_Y.begin(), sort_by_Y.end(), compareY);
}

//----------------------------------------------------------------------

double countDistance(Point A, Point B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

void bruteForce(vector<Point> &points) {
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            double dist = countDistance(points[i], points[j]);
            if (dist < minDist) {
                res.clear();
                res.emplace_back(pair<Point, Point>(points[i], points[j]));
                minDist = dist;
            } else if (dist == minDist) {
                res.emplace_back(pair<Point, Point>(points[i], points[j]));
            }
        }
    }
}

void closestPair(vector<Point> &sorted_by_X, vector<Point> &sorted_by_Y) {
    int size = sorted_by_X.size();
    if (size <= 3) {
        bruteForce(sorted_by_X);
        return;
    }
    vector<Point> sorted_by_X_left(sorted_by_X.begin(), sorted_by_X.begin() + size / 2);
    vector<Point> sorted_by_X_right(sorted_by_X.begin() + size / 2, sorted_by_X.end());

    Point mid = sorted_by_X[size / 2];
    vector<Point> sorted_by_Y_left;
    vector<Point> sorted_by_Y_right;
    for (Point p : sorted_by_Y) {
        if (p.x < mid.x) {
            sorted_by_Y_left.emplace_back(p);
        } else {
            sorted_by_Y_right.emplace_back(p);
        }
    }

#ifdef DEBUG
    printPoints(sorted_by_X_left);
    printPoints(sorted_by_X_right);
    printPoints(sorted_by_Y_left);
    printPoints(sorted_by_Y_right);
#endif
    closestPair(sorted_by_X_left, sorted_by_Y_left);
    closestPair(sorted_by_X_right, sorted_by_Y_right);

    vector<Point> strip;
    for (Point p : sorted_by_Y) {
        if (fabs(p.x - mid.x) < minDist) {
            strip.emplace_back(p);
        }
    }
    bruteForce(strip);

}


//----------------------------------------------------------------------
void readPoints(vector<Point> &points) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        Point p(substr);
        points.emplace_back(p);
    }
}

int main() {
    string caseNum;
    getline(cin, caseNum);
    int T;
    stringstream caseNumSS(caseNum);
    caseNumSS >> T;

    while (T-- > 0) {
        reset();
        vector<Point> points;
        readPoints(points);
        vector<Point> sorted_by_X(points);
        vector<Point> sorted_by_Y(points);
        preSort(sorted_by_X, sorted_by_Y);
        closestPair(sorted_by_X, sorted_by_Y);
        printRes();
    }
}

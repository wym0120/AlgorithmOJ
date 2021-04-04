/**
 * <------Description------>
 * Convex Hull of a set of points, in 2D plane, is a convex polygon with minimum area such that each point lies either on the boundary of polygon or inside it.
 * Now given a set of points the task is to find the convex hull of points.
 *
 * <------Input------>
 * The first line of input contains an integer T denoting the no of test cases.
 * Then T test cases follow.
 * Each test case contains an integer N denoting the no of points.
 * Then in the next line are N*2 space separated values denoting the points ie x and y.
 * Constraints:1<=T<=100,1<=N<=100,1<=x,y<=1000
 *
 * <------Output------>
 * For each test case in a new line print the points x and y of the convex hull separated by a space in sorted order (increasing by x) where every pair is separated from the other by a ','.
 * If no convex hull is possible print -1.
 *
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <sstream>

using namespace std;

struct Point {
    int x{};
    int y{};

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Point() = default;
};

Point p0;
stack<Point> res;

/*
 * angle OAB,if res > 0, then OA is counterclockwise of OB*/
int cross(Point &O, Point &A, Point &B) {
    int value = (A.x - O.x) * (B.y - O.y) - (B.x - O.x) * (A.y - O.y);
    return value;
}

bool compareByX(const Point &A, const Point &B) {
    return A.x < B.x;
}

bool compareByYX(const Point &A, const Point &B) {
    if (A.y == B.y) {
        return A.x < B.x;
    } else {
        return A.y < B.y;
    }
}

bool compareByAngle(Point &A, Point &B) {
    int crossValue = cross(p0, A, B);
    if (crossValue == 0) {
        return A.x < B.x;
    } else return crossValue > 0;
}

void printRes() {
    vector<Point> points;
    while (!res.empty()) {
        points.emplace_back(res.top());
        res.pop();
    }
    if (points.size() <= 2) {
        cout << "-1" << endl;
    } else {
        sort(points.begin(), points.end(), compareByX);
        stringstream ss;
        for (Point p : points) {
            ss << p.x << " " << p.y << ", ";
        }
        cout << ss.str().substr(0, ss.str().size() - 2) << endl;
    }
}

void calConvexHull(vector<Point> &points) {
    sort(points.begin(), points.end(), compareByYX);
    p0 = points[0];
    points.erase(points.begin());
    sort(points.begin(), points.end(), compareByAngle);
//#define DEBUG
#ifdef DEBUG
    for (Point p :points) {
        cout << "(" << p.x << "," << p.y << ") ";
    }
    cout << endl;
#endif
    res.push(p0);
    res.push(points[0]);
    res.push(points[1]);
    Point nextTop = points[0], top = points[1];

    for (int i = 2; i < points.size(); i++) {
        while (cross(nextTop, points[i], top) >= 0) {
            res.pop();
            top = res.top();
            res.pop();
            nextTop = res.top();
            res.push(top);
        }
        res.push(points[i]);
    }
    printRes();
}


int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int N;
        cin >> N;
        int x, y;
        vector<Point> points;
        while (N-- > 0) {
            cin >> x >> y;
            Point p(x, y);
            points.emplace_back(p);
        }
        calConvexHull(points);
    }
}
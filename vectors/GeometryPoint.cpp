#include <bits/stdc++.h>
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
struct Point{
	double x,y;
	Point(){}
	Point(double a, double b){
		x = a;
		y = b;
	}	
};
Point operator+(const Point&a, const Point &b){
	return Point(a.x + b.x, a.y + b.y);
}
Point operator-(const Point&a, const Point &b){
	return Point(a.x - b.x, a.y - b.y);
}
Point operator*(const Point&a, double k){
	return Point(a.x * k, a.y *k);
}
bool operator ==(const Point &a, const Point &b){
	return fabs(a.x-b.x) < EPS && fabs(a.y-b.y) < EPS;
}
double distance(const Point &A, const Point &B){
	return hypot(A.x-B.x, A.y-B.y);
}

int main(){
	set<pair<int,int>> points;
	points.insert({5,3});
	points.insert({2,4});
	points.insert({3,2});
	for(auto &p: points){
		cout << p.first << " " << p.second << '\n';
	}
	return 0;
}
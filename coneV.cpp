/*
题目： B君的圆锥
要求：已知圆锥的表面积，求最大的体积为多少？

思路：圆锥的表面积M和体积V的关系为M^3>=72*pi*V^2。
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define pi 3.1415926

int main()
{
	double M;
	cin >> M;
	cout << fixed << setprecision(6) << sqrt(pow(M, 3)/(72*pi)) << endl;
	system("pause");
	return 0;
}
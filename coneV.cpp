/*
��Ŀ�� B����Բ׶
Ҫ����֪Բ׶�ı���������������Ϊ���٣�

˼·��Բ׶�ı����M�����V�Ĺ�ϵΪM^3>=72*pi*V^2��
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
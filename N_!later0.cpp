/*
��Ŀ���׳˺���0������

˼·����ʵ����0�����ֻ����2�ı�����5�ı���������10�ı�����10�ı����ܺ�ͳ�ƣ�
��Ҫ��2�ı�����5�ı����ĳ˻���εõ���ÿ10�����ڣ���10�ı�����2�ı�����4����
��5�ı���ֻ��1����������������0��Ҳֻ��10�ı�����5����������10�ı���Ҳ���Բ�
��2��5�����ĳ˻�����������ֻ����5���ݼ����ĸ�����
*/

#include <iostream>
using namespace std;

int N_laternum0(int N)
{
	int sum=0, t=5;
	while(t<=N)
	{
		sum+=N/t;
		t*=5;
	}
	return sum;
}

int main()
{
	int N;
	cin >> N;
	cout << N_laternum0(N) << endl;
	system("pause");
	return 0;
}
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int max0(int n1, int n2)
{
	return n1>n2?n1:n2;
}

int main()
{
	int M;
	cin >> M;
//	int temp=max0(M, 100);
	int num[]={153, 370, 371, 407, 1634};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	auto it=lower_bound(nums.begin(), nums.end(), M);
	cout << *it << endl;
	
//	int t=temp, count=0, q=(int)pow(temp, 1.0/3);
//	while(t)
//	{
////		num.push_back(t%10);
//		count++;
//		t/=10;
//	}
//
//	while(1)
//	{
//		if(temp>=pow(10, count+1))
//			count++;
//		int sum=0, t0=temp;
//		for(int i=0; i<count; i++)
//		{
//			sum+=pow(t0%10, count);
//			t0/=10;
//		}
//		if(sum==temp++)
//			break;
//	}

//	cout << temp-1 << endl;
	system("pause");
	return 0;
}
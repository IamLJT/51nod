#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t, N;
	cin >> t;
	while(t--)
	{
		cin >> N;
		if(N%7==0||N%7==2)
			printf("B\n");
		else
			printf("A\n");
	}
	system("pause");
	return 0;
}
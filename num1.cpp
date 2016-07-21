#include <iostream>
using namespace std;

    int countDigitOne(int n) {
    if(n<=0) return 0;
    int left = n;	
    int Right = 0;
	int Result = 0;
	int RightSize = 0;
	long num=n;
	while(left)
	{
		left/=10;
		Right=num%(long)pow(10,RightSize);
		if(n%10 > 1)
		    Result+=(left+1)*pow(10,RightSize);
		if(n%10 == 1)
		    Result+=left*pow(10,RightSize)+Right+1;
		if(n%10 == 0)
		    Result+=left*pow(10,RightSize);
		n=left;
		RightSize++;
	}
	return Result;
    }

int main()
{
	int n;
	cin >> n;
	cout << countDigitOne(n) << endl;
	system("pause");
	return 0;
}
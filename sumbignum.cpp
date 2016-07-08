#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    string A,B,res="";
    int A0=1, B0=1;
    cin >> A >> B;
    if(A.size()==0||B.size()==0) 
	{
		cout << A+B << endl;
		system("pause");
		return 0;
	}
    while(A[0]=='-'||A[0]=='+') 
    {
        if(A[0]=='-')
            A0=-1;
        A=A.substr(1);
    }
    while(B[0]=='-'||B[0]=='+') 
    {
        if(B[0]=='-')
            B0=-1;
        B=B.substr(1);
    }
    int len = max(A.size(), B.size());
    int e=0;        // 进位
	int C0=1;		//	判断最后的为正或负
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    for(int i=A.size();i<len;i++)
        A+='0';
    for(int i=B.size();i<len;i++)
        B+='0';
	for(int i=len-1; i>=0; i--)
	{
		if(A[len-1]>B[len-1])
		{
			C0=A0;
			break;
		}
		if(B[len-1]>A[len-1])
		{
			C0=B0;
			break;
		}
	}
    for(int i=0; i<len; i++)
    {
		int sum;
		if(A0*B0<1)
		{
			sum=(A[i]-'0')*A0+(B[i]-'0')*B0;
			if(sum>0)
				sum+=e;
		}
		else
			sum=(A[i]-'0')+(B[i]-'0')+e;
        if(sum%10<0)
		{
            e=sum/10-1;
			sum=-sum;
        }
		else
            e=sum/10;
		if((C0>0&&e<0)||(C0<0&&sum>0))
			res+=(10-sum%10)+'0';
		else 
			res+=sum%10+'0';
    }
    if(e>0)
        res+=e+'0';
	if(e<0)
	{
		if(e!=-1)
			res+=(-e-1)+'0';
		res+='-';
	}
	if(A0==-1&&B0==-1)
		res+='-';
	reverse(res.begin(), res.end());
	while(res[0]=='0'&&res.size()>1)
		res=res.substr(1);
    cout << res << endl;
    system("pause");
    return 0;
}
/*
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> sum0(vector<int> num)
{
	vector<vector<int>> res;
	vector<int> sum;
	for(int i=0; i<num.size()-2; i++)
	{
		int temp=num[i];
		if(temp>0) break;
		int l=i+1, r=num.size()-1;
		while(l<r)
		{
			if(num[l]+num[r]>-temp)
			{
				r--;
			}
			else if(num[l]+num[r]<-temp)
			{
				l++;
			}
			else
			{
				sum.push_back(temp);
				sum.push_back(num[l]);
				sum.push_back(num[r]);
				res.push_back(sum);
				sum.clear();
				while(l<r&&num[l+1]==num[l++]);
				while(l<r&&num[r-1]==num[r--]);
			}
		}
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	vector<int> num(N, 0);
	for(int i=0; i<N; i++)
		cin >> num[i];
	sort(num.begin(), num.end());
	vector<vector<int>> res=sum0(num);
	if(res.size()==0) cout << "No Solution" << endl;
	for(int i=0; i<res.size(); i++)
	{
		cout << res[i][0] << " "
			<< res[i][1] << " "
			<< res[i][2] << endl;
	}
	system("pause");
	return 0;
}
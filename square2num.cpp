#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> square2num(int N)
{
	vector<vector<int>> res;
	int t=sqrt(N);
	int left=0, right=t;
	while(left<=right)
	{
		if(left*left+right*right<N)
			left++;
		else if(left*left+right*right>N)
			right--;
		else
		{
			vector<int> num;
			num.push_back(left);
			num.push_back(right);
			res.push_back(num);
			left++;
			right--;
		}
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> num=square2num(N);
	if(num.size()==0) cout << "No Solution" << endl;
	for(int i=0; i<num.size(); i++)
		cout << num[i][0] << " " << num[i][1] << endl;
	system("pause");
	return 0;
}
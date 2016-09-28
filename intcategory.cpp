/*
��Ŀ������������
Ҫ�󣺽�һ����������Ϊ2�飬Ҫ��2��ĺ������С��
���磺1 2 3 4 5����1 2 4��Ϊ1�飬3 5��Ϊ1�飬��������1�������з�����������ٵġ�
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int isbigstr(char str1[], char str2[])
{
	for(int i=0;i<4;i++)
	{
		if(str1[i]<str2[i])
			return 0;
		else if(str1[i]>str2[i])
			return 2;
		else
			continue;
	}
	return 1;
}

struct Person
{
	char name[10];
	char Pnumber[11];
	char IDnumber[12];
};

int cmp(Person p1, Person p2)
{
	int res1=isbigstr(p1.Pnumber,p2.Pnumber);
	int res2=isbigstr(p1.IDnumber,p2.IDnumber);
	if(res1==1)
		return res2==0?1:0;
	return res1==0?1:0;
}

int main()
{
	vector<string> filestr;
	ifstream in("C:\\Users\\Iam_luffy\\Desktop\\1.txt");
	string s;
	while(!in.eof())
	{
		getline(in,s);
		if(s.size())
			filestr.push_back(s);
		s.clear();
	}
	vector<Person> person(filestr.size());
	for(int i=0;i<filestr.size();i++)
	{
		strcpy(person[i].name,filestr[i].substr(0,filestr[i].size()-23).c_str());
		strcpy(person[i].Pnumber,filestr[i].substr(filestr[i].size()-23,filestr[i].size()-12).c_str());
		strcpy(person[i].IDnumber,filestr[i].substr(filestr[i].size()-12,filestr[i].size()).c_str());
	}
	sort(person.begin(),person.end(),cmp);
	system("pause");
	return 0;
}

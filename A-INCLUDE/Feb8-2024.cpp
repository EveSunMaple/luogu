#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int n = 0, m = 0;
	//vector<int> q;
	vector<vector<string> > q_s;
	cin >> n >> m;
	string q;
	cin >> q;
	int h = 0, e = 0;
	for(int i = 0; i < q.size(); i++)
	{
		if(q[i] == ' ') 
		{
			e = i;
			q_s.push_back({&q[0]+h, &q[0]+e});
			h = i;
		}
	}
	for(int i = 0; i< q_s.size(); i++)
	{
		for(int j = 0; j < q_s[i].size(); j++)
		{
			cout << q_s[i][j];
		}
		cout << endl;
	}
	
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

void rot(pair <int, int > pos, vector < vector < int > >&mat, queue < pair < int, int > > &que) {
	int i = pos.first;
	int j = pos.second;
	
	if (i - 1 >= 0 && mat[i - 1][j] == 1) {
		mat[i - 1][j] = 2;
		que.push(make_pair(i-1, j));
	}

	if (j - 1 >= 0 && mat[i][j - 1] == 1) {
		mat[i][j - 1] = 2;
		que.push(make_pair(i, j - 1));
	}

	if (i + 1 < mat.size() && mat[i + 1][j] == 1) {
		mat[i + 1][j] = 2;
		que.push(make_pair(i + 1, j));
	}

	if (j + 1 < mat[0].size() && mat[i][j + 1] == 1) {
		mat[i][j + 1] = 2;
		que.push(make_pair(i, j + 1));
	}
}

int timeToRot(vector < vector < int > > &basket)
{
	queue < pair < int, int > > q1;
	queue < pair < int, int > > q2;
	
	int count = 0;
	int freshCount = 0;

	for (int i = 0; i < basket.size(); i++) {
		for (int j = 0; j < basket[0].size(); j++) {
			if (basket[i][j] == 2) {
				q1.push(make_pair(i, j));
			}	

		}
	}

	while (q1.empty() != true || q2.empty() != true) {
	
		while (q1.empty() != true) {
			pair < int, int > p = q1.front();
			q1.pop();
			rot(p, basket, q2);
		}
		if (q2.empty() != true)
			count++;
		while (q2.empty()!= true) {
			pair < int , int > p = q2.front();
			q2.pop();
			rot(p, basket, q1);
		}

		if(q1.empty() != true)
			count++;
	}
	
	for (int i = 0; i < basket.size();i++) {
		for (int j = 0; j < basket[0].size(); j++) {
			if (basket[i][j] == 1) {
				return -1;
			}
		}
	}
	
	return count;
}

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		int m, n;
		cin>>m>>n;
		vector < vector < int > > basket(m, vector < int >(n, 0));

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin>>basket[i][j];
			}
		}
		
		int result = timeToRot(basket);
		cout<<result<<endl;

		test--;
	}
	return 0;
}

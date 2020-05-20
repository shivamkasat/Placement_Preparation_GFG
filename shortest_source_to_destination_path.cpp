#include<bits/stdc++.h>

using namespace std;

int shortestPath(vector < vector < int > > &mat, pair < int, int > dest)
{
	if (mat[0][0] == 0) {
		return -1
	}

	queue < pair < int , int > > q;
	q.push(make_pair(0, 0));
	q.push(make_pair(-1, -1));
	mat[0][0] = 0;

	int n = mat.size();
	int m = mat[0].size();
	
	bool found = false;
	int count = -1;

	while (q.empty() != true) {
		
		pair < int, int > pos = q.front();
		q.pop();

		int i = pos.first;
		int j = pos.second;

		if (pos == dest) {
			found = true;
			break;
		}

		if (pos == make_pair(-1, -1)) {
		    count++;
		    
		    if (q.empty()!= true)
			    q.push(make_pair(-1, -1));
			
		    continue;	    
		
		}

		if (i - 1 >= 0 && mat[i - 1][j] == 1) {
			q.push(make_pair(i - 1, j));
			mat[i - 1][j] = 0;
		}

		if (i + 1 < n && mat[i + 1][j] == 1) {
			q.push(make_pair(i + 1, j));
			mat[i + 1][j] = 0;
		}

		if (j - 1 >= 0 && mat[i][j - 1] == 1) {
			q.push(make_pair(i, j - 1));
			mat[i][j - 1] = 0;
		}		

		if (j + 1 < m && mat[i][j + 1] == 1) {
			q.push(make_pair(i, j + 1));
			mat[i][j + 1] = 0;
		}		

	}

	if (found == true) {
		return count + 1;
	}

	return -1;
}

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		int n, m;
		cin>>n>>m;

		vector < vector < int > >mat(n, vector < int >(m, 0));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin>>mat[i][j];
			}
		}

		pair < int , int > dest;
		cin>>dest.first>>dest.second;
		cout<<shortestPath(mat, dest)<<endl;
		mat.clear();
		test--;
	}
	return 0;
}

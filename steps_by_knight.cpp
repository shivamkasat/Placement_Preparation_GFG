#include<bits/stdc++.h>

using namespace std;

int steps(pair < int, int > source, pair <int, int> dest, int board_size)
{
	queue < pair <int, int > > q;
	int step_count = 0;
	q.push(source);
	q.push(make_pair(-1, -1));
	bool found = false;

	vector < vector < bool > > check(board_size, vector < bool >(board_size, false));
	
	while (1) {
		while (1) {
			pair <int, int > p = q.front();
			q.pop();
			cout<<"step_count = "<<step_count<<endl;	
			int i = p.first;
			int j = p.second;

			if (p == make_pair(-1,-1)) break;
			
			if (p == dest) {
				found = true;
				break;
			}
				
			if ( i - 2 >= 0 && j - 1 >= 0 && check[i - 2][j - 1] == false ) {
				q.push(make_pair(i - 2, j - 1));
				check[i - 2][j - 1] = true;
			}	
			
			if ( i - 1 >= 0 && j - 2 >= 0  && check[i - 1][j - 2] == false) {
				q.push(make_pair(i - 1, j - 2));
				check[i - 1][j - 2] = true;
			}
				
			if ( i - 2 >= 0 && j + 1 < board_size && check[i -2][j + 1] == false ) {
				q.push(make_pair(i - 2, j + 1));
				check[i - 2][j + 1] = true;
			}
			
			if ( i - 1 >= 0 && j + 2 < board_size && check[i - 1][j + 2] == false ) {
				q.push(make_pair(i - 1, j + 2));
				check[i - 1][j + 2] = true;
			}
		
			if ( i + 1 < board_size && j + 2 < board_size && check[i + 1][j + 2] == false ) {
				q.push(make_pair(i + 1, j + 2));
				check[i + 1][j + 2] = true;
			}
		
			if ( i + 2 < board_size && j + 1 < board_size && check[i + 2][j + 1] == false ) {
				q.push(make_pair(i + 2, j + 1));
				check[i + 2][j + 1] = true;
			}
		
			if ( i + 2 < board_size && j - 1 >= 0 && check[i + 2][j - 1] == false ) {
				q.push(make_pair(i + 2, j - 1));
				check[i + 2][j - 1] = true;
			}
		
			if ( i + 1 < board_size && j - 2 >= 0 && check[i + 1][j - 2] == false ) {
				q.push(make_pair(i + 1, j - 2));
				check[i + 1][j - 2] = true;
			}
		
		}

		if (found == true) break;
		step_count++;
		q.push(make_pair(-1, -1));
	}

	return step_count;
	
}

int main() 
{
	int test;
	cin>>test;
	while (test > 0) {
		int board_size; 
		cin>> board_size;
		
		pair < int, int > source;
		pair < int , int > dest;

		cin>>source.first>>source.second;
		cin>>dest.first>>dest.second;

		cout<<steps(make_pair(source.first - 1, source.second - 1), make_pair(dest.first - 1, dest.second - 1), board_size)<<endl;
		
		test--;
	}
	return 0;
}

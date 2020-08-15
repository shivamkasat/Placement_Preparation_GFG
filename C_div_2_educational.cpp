#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int R;
	int G;
	int B;
	cin>>R>>G>>B;
	priority_queue < pair <int, int >, vector < pair < int, int > > > redpq;
	priority_queue < pair <int, int >, vector < pair < int, int > > > greenpq;
	priority_queue < pair <int, int >, vector < pair < int, int > > > bluepq;

	priority_queue < pair < int, int >, vector < pair < int, int > > >pq;
	
	int len = 0;
	for (int i = 0; i < R; i++) {
		cin>>len;
		redpq.push({len, 0});
	}
	for (int i = 0; i < G; i++) {
		cin>>len;
		greenpq.push({len, 1});
	}
	for (int i = 0; i < B; i++) {
		cin>>len;
		bluepq.push({len, 2});
	}
	pair < int, int > red;
	pair < int, int > green;
	pair < int , int > blue;
	pair < int , int > emp;
	emp = {-1, -1};
	int ans = 0;
	while (1) {
		red = {-1, -1};
		green = {-1, -1};
		blue = {-1, -1};
		if (redpq.empty() != true) {
			red = redpq.top();
			redpq.pop();	
		}
		if (greenpq.empty() != true){
			green = greenpq.top();
			greenpq.pop();
		}
		if (bluepq.empty() != true) {
			blue = bluepq.top();
			bluepq.pop();
		}

		if ((red == emp && green == emp) || (green == emp && blue == emp) || (blue == emp && red == emp))	break;
		
		pq.push(red);
		pq.push(green);
		pq.push(blue);

		int l = pq.top().first;
		pq.pop();
		int b = pq.top().first;
		pq.pop();
		ans += (l * b);
		pair < int, int > c = pq.top();
		pq.pop();
		if (c.second == 0) {
			redpq.push(c);
		} else if (c.second == 1) {
			greenpq.push(c);
		} else if (c.second == 2) {
			bluepq.push(c);
		}
	}

	cout<<ans<<endl;
	return 0;
}
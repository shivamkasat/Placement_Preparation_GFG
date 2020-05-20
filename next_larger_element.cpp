#include <bits/stdc++.h>

using namespace std;

vector < int > findNextLarger(vector < int > &data) {
	stack < int > st;
	vector < int > result;

	for (int i = data.size() - 1; i > -1; i--) {
		while (st.empty() == false && data[i] > st.top()) {
			st.pop();
		}

		if (st.empty() == true) {
			result.push_back(-1);
		} else {
			result.push_back(st.top());
		}

		st.push(data[i]);
	}

	reverse(result.begin(), result.end());
	return result;
}

int main() {
	int test;
	cin>>test;
	while (test > 0) {
		int n;
		cin>>n;
		vector < int > data(n, 0);

		for (int i = 0; i < data.size(); i++) {
			cin>>data[i];
		} 

		vector < int > result;
		result = findNextLarger(data);
		
		for (int i = 0; i < result.size(); i++) {
			cout<<result[i]<<" ";
		}
		cout<<endl;
		
		test--;
	}
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
struct comp {
	bool operator()(pair <int, int > a, pair < int, int > b) {
		if (a.first != b.first) {
			return a.first > b.first;
		} else {
			return a.second < b.second;
		}
	}
};

set < pair < int, int >, comp > pq;

bool isPossible(int mid, int n, vector < int > &nums) {
	vector < int > count(N, 0);
	pq.clear();
	for (int i = 0; i < n; i++) {
		count[nums[i]]++;
	}			

	for (int i = 0; i < n; i++) {
			pq.insert({count[nums[i]], nums[i]});
	}		

	vector < int > temp;
	for (int i = 0; i < n; i++) {
		if (i >= mid && count[temp[i - mid]] > 0) {
			pq.insert({count[temp[i - mid]], temp[i - mid]});
		}

		if (pq.empty() == true) {
			return false;
		}

		temp.push_back(pq.begin()->second);
		count[pq.begin()->second]--;
		pq.erase(pq.begin());
	}

	return true;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		vector < int > nums(n, 0);
		for (int i = 0; i < n; i++) {
			cin>>nums[i];
		}
		int low = 0;
		int high = n;
		int mid = 0;
		int ans = 0;
		while (low <= high) {
			mid = low + (high - low) / 2;
			if (isPossible(mid, n, nums)) {
				ans = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}

		cout<<ans - 1<<endl;
	}
	return 0;
}
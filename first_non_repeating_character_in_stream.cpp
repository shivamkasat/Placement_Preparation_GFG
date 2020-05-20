#include <bits/stdc++.h>

using namespace std;

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		int n;
		cin>>n;
		unordered_map < char , int > hmap;
		vector < char > vec(n);

		for (int i = 0; i < n; i++) {
			cin>>vec[i];
		}

		int first = 0;
		int current = 0;

		while (current < vec.size()) {
			hmap[vec[current]]++;

			while (first <= current) {
				if (hmap[vec[first]] == 1) {
					printf("%c ", vec[first]);
					break;
				}

				first++;
			}

			if (first > current) {
				printf("-1 ");
			}

			current++;
		}
		printf("\n");
		test--;
	}
}


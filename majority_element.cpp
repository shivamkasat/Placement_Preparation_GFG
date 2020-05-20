#include <bits/stdc++.h>

using namespace std;

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		vector < int > hmap(1000001,0);
		
		int n;
		cin>>n;
		int num = n;
		
		while (n > 0) {
			int elem;
			cin>>elem;
			hmap[elem]++;
			n--;
		}
		
		int ans = -1;
		for (int i = 0; i < hmap.size(); i++) {
			if (hmap[i] > (num /2)) {
				ans = i;		
			break;		
			}
		}

		printf("%d\n", ans);

		test--;
	}

	return 0;
}

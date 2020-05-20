#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	int test;
	cin>>test;
	while (test > 0) {
		int num;
		cin>>num;
		string snum;
		snum = to_string(num);
		
		for (int i = 0; i < snum.length(); i++) {
			snum[i] = snum[i] == '0' ? '5' : snum[i];
		}
	
		cout<<"string "<<snum<<endl;
		num = stoi(snum);

		printf("%d\n", num);

		test--;
	}
	return 0;
}

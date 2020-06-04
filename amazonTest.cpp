#include <bits/stdc++.h>
using namespace std;

string findPerm(int num) {
	string s = "DDDDDDDD";
	string result = "123456789";
	// string input = to_string(num);
	int lastDigit = 0;
	int i = 7;
	while (num != 0) {
		lastDigit = num % 10;
		if (lastDigit % 2 == 0) {
			s[i] = 'I';
		} else {
			s[i] = 'D';
		}
		i--;
		num = num / 10;
	}

	cout<<s<<endl;

	i = 0;
	int j = 0;
	while (i < 8) {
    cout<<"lets see"<<endl;
		while (i < 8 && s[i] == 'I') {
			i++;
		}

		j = i;

		while (j < 8 && s[j] == 'D') {
			j++;
		}

		reverse(result.begin() + i, result.begin() + j + 1);

		i = j;
	}

	return result;
}

int main() {
	int test;
	cin>>test;
	while (test--) {
		int num;
		cin>>num;
		cout<<findPerm(num);
	}
	return 0;
}

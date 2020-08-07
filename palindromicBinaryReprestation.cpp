#include <bits/stdc++.h>
using namespace std;

int findNthPalin(int n) {
	if (n == 1) {
		return 1;
	} else if (n == 2) {
		return 3;
	} 

	int count = 2;
	queue < string > q;
	q.push("11");

	string temp;
	string firstHalf;
	string temp2;
	string secondHalf;
	int mid;
	while (1) {
		temp = q.front();
		q.pop();
		if (int(temp.length()) % 2 == 0) {
			mid = temp.length() / 2;
			firstHalf = temp.substr(0, mid);
			secondHalf = temp.substr(mid, mid);
			temp2 = firstHalf + "0" + secondHalf;
			count++;
			if (count == n) {
				return stoi(temp2, nullptr, 2);
			}
			q.push(temp2);
			count++;
			temp2 = firstHalf + "1" + secondHalf;
			if (count == n) {
				return stoi(temp2, nullptr, 2);
			}
			q.push(temp2);
		} else {
			mid = temp.length() / 2;
			firstHalf = temp.substr(0, mid);
			secondHalf = temp.substr(mid, mid + 1);
			count++;
			temp = firstHalf + temp[mid] + secondHalf;
			if (count == n) {
				return stoi(temp, nullptr, 2);
			}
			q.push(temp);
		}
	}

	return -1;
}

int main() {
	int test;
	cin>>test;
	while (test--) {
		int n;
		cin>>n;
		cout<<findNthPalin(n)<<endl;

	}
	return 0;
}
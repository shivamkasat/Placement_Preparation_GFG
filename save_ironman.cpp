#include <bits/stdc++.h>

using namespace std;

bool isPalin(string str)
{
	int left = 0;
	int right = str.length() - 1;
	char leftChar = str[left];
	char rightChar = str[right];
	//cout<<"inside isPalin"<<endl;	
	while (left <= right) {
			//cout<<"inside outer while loop"<<endl;
			while (!((str[left] >= '0' && str[left] <= '9') || (str[left] >= 'A' && str[left] <= 'Z') || (str[left]>= 'a' && str[left] <= 'z'))) {
				//cout<<"inside inner while incr left"<<endl;	
				left++;
			}

			while (!((str[right] >= '0' && str[right] <= '9') || (str[right] >= 'A' && str[right] <= 'Z') || (str[right] >= 'a' && str[right] <= 'z'))) {
				//cout<<"inside inner while incr right"<<endl;
				right--;

			}

			if(toupper(str[left]) != toupper(str[right])) {
				return false;
			}
			left++;
			right--;
	}

	return true;
}
int main()
{
	int test;
	string ignore;
	cin>>test;
	getline(cin, ignore);
	while (test > 0) {
		string str;
		getline(cin, str);
		bool result = isPalin(str);
		if(result) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
		test--;
	}
	return 0;
}

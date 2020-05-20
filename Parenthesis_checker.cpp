#include <bits/stdc++.h>

using namespace std;

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		string str;
		stack < char > st;
		cin>>str;
		bool result = true;
		for (int i = 0;i < str.length(); i++) {
			if (str[i] == '[' || str[i] == '{' || str[i] == '(') {
				st.push(str[i]);
			} else if(str[i] == ']') {
				if(st.empty() == true || st.top() != '[') {
					result = false;
					break;	
				} else {
					st.pop();
				}
			} else if(str[i] == '}') {
				if(st.empty() == true ||st.top() != '{')  {
					result = false;
					break;	
				} else {
					st.pop();
				}
			} else if(str[i] == ')') {
				if(st.empty() == true || st.top() != '(') {
					result = false;
					break;	
				} else {
					st.pop();
				}
			}

			if (st.empty() == false) {
				cout<<"top of stack"<<st.top()<<endl;
			}
		}
		if (st.empty() == false) {
				cout<<"top of stack"<<st.top()<<endl;
		}		

		if (result == true && st.empty() == true) {
			cout<<"balanced"<<endl;
		} else {
			cout<<"unbalanced"<<endl;
		}
		
	}
	return 0;
}

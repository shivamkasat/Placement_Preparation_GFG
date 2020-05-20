#include <bits/stdc++.h>

using namespace std;

int main()
{
	int test;
	cin>>test;

	while (test > 0) {
		int n;
		cin>>n;
		vector < int > data(n, 0);

		for (int i = 0; i < data.size(); i++) {
			cin>>data[i];
		}

		stack < int > st;
		int elem;
		int span_size;

		for (int i = 0; i < data.size(); i++) {
			elem = data[i];
			span_size = 1;
			
			while (st.empty() != true && st.top() <= elem) {
				st.pop();
				span_size += st.top();
				st.pop();
			}
			
			st.push(span_size);
			st.push(elem);
			printf("%d ", span_size);	
		}
		test--;
	}
	return 0;
}

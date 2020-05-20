#include<bits/stdc++.h>

using namespace std;

vector < int > f(10000, -1);

int fib(int n)
{

	if (f[n] != -1) {
		return f[n];
	}

	if (n == 0 || n == 1) {
		return n;
	}


	f[n] = fib(n-1) + fib(n-2);
	return f[n];
}

int main()
{
	cout<<fib(3)<<endl;
	cout<<fib(5)<<endl;	
	for(int i = 0; i < 6; i++) {
		cout<<f[i]<<" ";
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

class Stack {


	private:
		int arr[1000];
		int top;

	public :
	
		Stack() {
			top = -1;
		}
		void push(int x);
		int pop();
		
};

void Stack :: push(int x)
{
	if (top == 999) {
		printf("Stack is full");
		return;
	}

	top++;
	this->arr[top] = x;
}

int Stack :: pop()
{
	if (top == -1) {
		return -1;
	}
	
	int elem = this->arr[this->top];
	(this->top)--;
	return elem;

}

int main()
{
	int test;
	cin>>test;
	while (test > 0) {
		Stack s1;
		int query;
		cin>>query;
		int queryType, elem;
		while (query > 0) {
			cin>>queryType;
			if (queryType == 1) {
				cin>>elem;
				s1.push(elem);
			} else {
				cout<<s1.pop()<<endl;
			}
			query--;
		}
		test--;
	}
	return 0;
}


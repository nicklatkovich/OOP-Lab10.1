#include <iostream>
#include <stack>

using namespace std;

void printStack(stack <char> st) {
	stack <char> temp = st;
	while (!temp.empty()) {
		cout << temp.top();
		temp.pop();
	}
	cout << endl;
}

void main() {
	cout << "\nCREATE STACK\n";
	stack <char> st;
	for (int i = 0; i < 60; i++) {
		st.push(rand() % 26 + 'A');
	}
	printStack(st);

	cout << "\nDELETE ALL 'B'\n";
	{
		stack <char> temp;
		while (!st.empty()) {
			char ch = st.top();
			st.pop();
			if (ch != 'B') {
				temp.push(ch);
			}
		}
		st = temp;
	}
	printStack(st);

	cout << "\nCHANGE 'A' TO 'C'\n";
	{
		stack <char> temp;
		while (!st.empty()) {
			char ch = st.top();
			st.pop();
			if (ch != 'A') {
				temp.push(ch);
			}
			else {
				temp.push('C');
			}
		}
		st = temp;
	}
	printStack(st);

	{
		int n = 6;
		cout << "\nDELETE " << n << " SIMBOLS AFTER FIRST 'G'\n";
		stack <char> temp;
		bool b = true;
		while (!st.empty()) {
			char ch = st.top();
			st.pop();
			if (b) {
				if (ch == 'G') {
					b = false;
				}
				temp.push(ch);
			}
			else if (n > 0) {
				n--;
			}
			else {
				temp.push(ch);
			}
		}
		st = temp;
	}
	printStack(st);

	cout << "\nCREATE SECOND STACK\n";
	stack <char> st2;
	for (int i = 0; i < 60; i++) {
		st2.push(rand() % 26 + 'A');
	}
	printStack(st2);

	cout << "\nCOPY ELEMENTS FROM SECOND STACK INTO FIRST\n";
	while (!st2.empty()) {
		st.emplace(st2.top());
		st2.pop();
	}
	printStack(st);
	cout << endl;
}
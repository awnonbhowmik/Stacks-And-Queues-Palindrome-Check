#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;

void PrintFromStack(string expr) {
	stack<char>myStack;
	for (int i = 0; i < expr.length(); i++)
		myStack.push(expr[i]);

	cout << "My stack is popped in this order:" << endl;
	while (!myStack.empty()) {
		cout << myStack.top()<<" ";
		myStack.pop();
	}
}

void PrintFromQueue(string expr) {
	queue<char>myQueue;
	for (int i = 0; i < expr.length(); i++)
		myQueue.push(expr[i]);

	while (!myQueue.empty()) {
		cout << myQueue.front();
		myQueue.pop();
	}
}

bool isPalindrome(string expr) {
	stack<char>myStack;
	queue<char>myQueue;
	bool isPalindrome = true;

	for (int i = 0; i < expr.length(); i++) {
		myQueue.push(expr[i]);
		myStack.push(expr[i]);
	}

	while (isPalindrome == true && !myQueue.empty() && !myStack.empty()) {
		if (myStack.top() != myQueue.front()) {
			isPalindrome = false;
			break;
		}
		else {
			myQueue.pop();
			myStack.pop();
		}
	}
	return isPalindrome;
}

int main(int argc, const char* argv[])
{
	string expression;
	while (expression != "end") {
		cout << "Please enter an expression that you want to store:";
		cin >> expression;

		PrintFromStack(expression);
		cout << endl;
		PrintFromQueue(expression);
		cout << endl;
		cout << "Your expression: " << expression << " is " << (isPalindrome(expression) ? "a palindrome!" : "not a palindrome!")<<endl;
	}
	system("pause");
	return 0;
}
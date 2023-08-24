/* C++ program to implement basic stack operations using arrays */
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack {
	int top;

public:
	int a[MAX]; // Maximum size of Stack
    
	Stack() { top = -1; }
	bool push(int x);
	int pop();
	int peek();
    void view();
	bool isEmpty();
};
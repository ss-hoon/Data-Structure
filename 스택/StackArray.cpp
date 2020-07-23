#include <iostream>
#define MAX_SIZE 100
using namespace std;

class Stack {
private:
	int top; // 스택의 top
	int stack[MAX_SIZE]; // stack 배열
public:
	Stack() { // Stack 생성자
		top = -1; // top 변수를 -1로 초기화
	}

	void push(int data) { // push(stack에 값을 input) 함수
		if (top >= MAX_SIZE - 1)	cout << "Stack is Full" << endl;
		else stack[++top] = data;
	}

	int pop() { // pop(stack의 top부분 값 반환) 함수
		if (top == -1) { 
			cout << "Stack is Empty" << endl;
			return 0;
		}
		else return stack[top--];
	}

	void peek() { // peek(stack의 top부분 출력) 함수
		if (top == -1)	cout << "Stack is Empty" << endl;
		else cout << stack[top] << endl;
	}
};

int main() {
	Stack stack;
	stack.push(1);
	stack.push(2);
	stack.peek();
	cout << stack.pop() << endl;
	stack.peek();
	return 0;
}
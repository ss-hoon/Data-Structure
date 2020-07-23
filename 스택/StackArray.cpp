#include <iostream>
#define MAX_SIZE 100
using namespace std;

class Stack {
private:
	int top; // ������ top
	int stack[MAX_SIZE]; // stack �迭
public:
	Stack() { // Stack ������
		top = -1; // top ������ -1�� �ʱ�ȭ
	}

	void push(int data) { // push(stack�� ���� input) �Լ�
		if (top >= MAX_SIZE - 1)	cout << "Stack is Full" << endl;
		else stack[++top] = data;
	}

	int pop() { // pop(stack�� top�κ� �� ��ȯ) �Լ�
		if (top == -1) { 
			cout << "Stack is Empty" << endl;
			return 0;
		}
		else return stack[top--];
	}

	void peek() { // peek(stack�� top�κ� ���) �Լ�
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
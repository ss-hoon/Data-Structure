#include <iostream>
#include <stack>
using namespace std;

typedef struct treeNode {
	treeNode * left;
	char data;
	treeNode * right;
}treeNode;

class Tree {
private:
	int size;
	treeNode * root;
public:
	Tree(char X) { // 트리 초기화 생성자
		treeNode * node = new treeNode;

		node->data = X;	
		node->left = NULL;
		node->right = NULL;
		root = node;
		size = 1;
	}

	treeNode * getRoot() { // root 노드 위치 반환
		return root;
	}

	void makeTree(char X) { // 노드 추가 함수
		stack<char> st;
		int location = size + 1;
		treeNode * temp = root;
		treeNode * newNode = new treeNode;

		newNode->data = X;
		newNode->left = NULL;
		newNode->right = NULL;

		while (location != 1) { // 완전 이진트리를 만들기 위한 전처리 작업
			if (location % 2 == 0)	st.push('L');
			else st.push('R');
			location /= 2;
		}

		while (st.size() != 1) { // 추가하려는 위치까지 이동
			if (st.top() == 'L')	temp = temp->left;
			else temp = temp->right;
			st.pop();
		}

		// 해당 위치에 추가
		if (st.top() == 'L')	temp->left = newNode;
		else temp->right = newNode;

		size++; // 트리 전체 사이즈 증가
	}

	void preorder(treeNode * node) { // 전위 순회 출력
		if (node != NULL) {
			cout << node->data << " ";
			preorder(node->left);
			preorder(node->right);
		}
	}

	void inorder(treeNode * node) { // 중위 순회 출력
		if (node != NULL) {
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
		}
	}

	void postorder(treeNode * node) { // 후위 순회 출력
		if (node != NULL) {
			postorder(node->left);
			postorder(node->right);
			cout << node->data << " ";
		}
	}
};

int main() {
	Tree tree('A');
	tree.makeTree('B');
	tree.makeTree('C');
	tree.makeTree('D');
	tree.makeTree('E');
	tree.makeTree('F');
	tree.makeTree('G');
	tree.makeTree('H');
	tree.makeTree('I');

	cout << "Preorder -> ";
	tree.preorder(tree.getRoot());
	cout << endl;

	cout << "Inorder -> ";
	tree.inorder(tree.getRoot());
	cout << endl;

	cout << "Postorder -> ";
	tree.postorder(tree.getRoot());
	cout << endl;
	return 0;
}
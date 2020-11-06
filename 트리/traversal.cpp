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
	Tree(char X) { // Ʈ�� �ʱ�ȭ ������
		treeNode * node = new treeNode;

		node->data = X;	
		node->left = NULL;
		node->right = NULL;
		root = node;
		size = 1;
	}

	treeNode * getRoot() { // root ��� ��ġ ��ȯ
		return root;
	}

	void makeTree(char X) { // ��� �߰� �Լ�
		stack<char> st;
		int location = size + 1;
		treeNode * temp = root;
		treeNode * newNode = new treeNode;

		newNode->data = X;
		newNode->left = NULL;
		newNode->right = NULL;

		while (location != 1) { // ���� ����Ʈ���� ����� ���� ��ó�� �۾�
			if (location % 2 == 0)	st.push('L');
			else st.push('R');
			location /= 2;
		}

		while (st.size() != 1) { // �߰��Ϸ��� ��ġ���� �̵�
			if (st.top() == 'L')	temp = temp->left;
			else temp = temp->right;
			st.pop();
		}

		// �ش� ��ġ�� �߰�
		if (st.top() == 'L')	temp->left = newNode;
		else temp->right = newNode;

		size++; // Ʈ�� ��ü ������ ����
	}

	void preorder(treeNode * node) { // ���� ��ȸ ���
		if (node != NULL) {
			cout << node->data << " ";
			preorder(node->left);
			preorder(node->right);
		}
	}

	void inorder(treeNode * node) { // ���� ��ȸ ���
		if (node != NULL) {
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
		}
	}

	void postorder(treeNode * node) { // ���� ��ȸ ���
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
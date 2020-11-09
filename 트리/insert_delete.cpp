#include <iostream>
using namespace std;

typedef struct treeNode {
	treeNode * left;
	int data;
	treeNode * right;
}treeNode;

class Tree {
private:
	int size;
	treeNode * root;
public:
	Tree(int X) { // Ʈ�� �ʱ�ȭ ������
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

	treeNode * insertTree(treeNode * p, int X) { // ��� �߰� �Լ�
		if (p == NULL) {
			treeNode * newNode = new treeNode;
			newNode->data = X;
			newNode->left = NULL;
			newNode->right = NULL;
			size++; // Ʈ�� ��ü ������ ����
			cout << X << " ��尡 �߰��Ǿ����ϴ�." << endl;
			return newNode;
		}
		else if (p->data > X)	p->left = insertTree(p->left, X);
		else if (p->data < X)	p->right = insertTree(p->right, X);
		else cout << "�ش� Ű�� �ֽ��ϴ�." << endl;
		return p;
	}

	void deleteTree(int X) { // ��� ���� �Լ�
		treeNode * parent = NULL;
		treeNode * child = root;

		while (child != NULL && child->data != X) { // �����Ϸ��� ��� Ž��
			parent = child;
			if (child->data > X)	child = child->left;
			else child = child->right;
		}

		if (child == NULL) { // �����Ϸ��� ��尡 ���� ���
			cout << "�ش� ��尡 �����ϴ�." << endl;
			return;
		}

		if (child->left == NULL && child->right == NULL) { // �����Ϸ��� ��尡 �ܸ������ ���
			if (parent != NULL) { // �����Ϸ��� ��尡 ��Ʈ ��尡 �ƴ� ���
				if (parent->left == child)	parent->left = NULL;
				else parent->right = NULL;
			}
			else root = NULL; // �����Ϸ��� ��尡 ��Ʈ ����� ���
		}
		else if (child->left == NULL || child->right == NULL) { // �����Ϸ��� ��尡 �ϳ��� �ڽĳ�带 ���� ���
			treeNode * grandChild;
			if (child->left == NULL)	grandChild = child->right;
			else grandChild = child->left;

			if (parent != NULL) { // �����Ϸ��� ��尡 ��Ʈ ��尡 �ƴ� ���
				if (parent->left == child)	parent->left = grandChild;
				else parent->right = grandChild;
			}
			else root = grandChild; // �����Ϸ��� ��尡 ��Ʈ ����� ���

		}
		else { // �����Ϸ��� ��尡 �� �ڽĳ�带 ���� ���(���� �ڽĳ���� �� ������ ���� ��ü)
			treeNode * temp_parent = child;
			treeNode * temp_child = child->left;
			while (temp_child->right != NULL) {
				temp_parent = temp_child;
				temp_child = temp_child->right;
			}

			if (temp_parent->left == temp_child)	temp_parent->left = temp_child->left;
			else temp_parent->right = temp_child->left;
			
			child->data = temp_child->data;
			child = temp_child;
		}

		delete child;
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
	Tree tree(20);
	tree.insertTree(tree.getRoot(), 30);
	tree.insertTree(tree.getRoot(), 8);
	tree.insertTree(tree.getRoot(), 15);
	tree.insertTree(tree.getRoot(), 4);
	tree.insertTree(tree.getRoot(), 13);
	tree.deleteTree(20);
	tree.deleteTree(13);
	tree.deleteTree(8);
	return 0;
}
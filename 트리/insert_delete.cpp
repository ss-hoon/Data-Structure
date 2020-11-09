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
	Tree(int X) { // 트리 초기화 생성자
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

	treeNode * insertTree(treeNode * p, int X) { // 노드 추가 함수
		if (p == NULL) {
			treeNode * newNode = new treeNode;
			newNode->data = X;
			newNode->left = NULL;
			newNode->right = NULL;
			size++; // 트리 전체 사이즈 증가
			cout << X << " 노드가 추가되었습니다." << endl;
			return newNode;
		}
		else if (p->data > X)	p->left = insertTree(p->left, X);
		else if (p->data < X)	p->right = insertTree(p->right, X);
		else cout << "해당 키가 있습니다." << endl;
		return p;
	}

	void deleteTree(int X) { // 노드 삭제 함수
		treeNode * parent = NULL;
		treeNode * child = root;

		while (child != NULL && child->data != X) { // 삭제하려는 노드 탐색
			parent = child;
			if (child->data > X)	child = child->left;
			else child = child->right;
		}

		if (child == NULL) { // 삭제하려는 노드가 없을 경우
			cout << "해당 노드가 없습니다." << endl;
			return;
		}

		if (child->left == NULL && child->right == NULL) { // 삭제하려는 노드가 단말노드인 경우
			if (parent != NULL) { // 삭제하려는 노드가 루트 노드가 아닌 경우
				if (parent->left == child)	parent->left = NULL;
				else parent->right = NULL;
			}
			else root = NULL; // 삭제하려는 노드가 루트 노드인 경우
		}
		else if (child->left == NULL || child->right == NULL) { // 삭제하려는 노드가 하나의 자식노드를 가진 경우
			treeNode * grandChild;
			if (child->left == NULL)	grandChild = child->right;
			else grandChild = child->left;

			if (parent != NULL) { // 삭제하려는 노드가 루트 노드가 아닌 경우
				if (parent->left == child)	parent->left = grandChild;
				else parent->right = grandChild;
			}
			else root = grandChild; // 삭제하려는 노드가 루트 노드인 경우

		}
		else { // 삭제하려는 노드가 두 자식노드를 가진 경우(왼쪽 자식노드의 맨 오른쪽 노드로 대체)
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
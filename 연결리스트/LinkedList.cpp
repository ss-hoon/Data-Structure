#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
	int data; // Node ������ data ��
	struct Node * link; // List�� ���� ��带 ����ų Node ������
};

class LinkedList {
private:
	Node * head; // LinkedList�� ù ��� ������
	Node * tail; // LinkedList�� ������ ��� ������
	int ListSize; // LinkedList�� ��ü ��� ����
public:
	LinkedList() { // LinkedList Ŭ������ ������ (head, tail �����Ϳ� ListSize ������ �ʱ�ȭ ���ش�)
		head = tail = NULL;
		ListSize = 0;
	}
	
	// ----------------------------- insert �Լ� ----------------------------- 
	// parameter�� 1���� ���� �� ������ ��带 ����
	// parameter�� 2���� ���� �� ��° parameter�� ��ġ�� ��带 ����

	void insert(int data) { // LinkedList�� �� ������ ��忡 ���ο� ��带 �����Ű�� insert �Լ�
		Node * newNode = (Node*)malloc(sizeof(Node)); // ���ο� ����� �޸� ������ Ȯ�� (�����Ҵ�)
		newNode->data = data; // parameter�� data���� ���� �Ҵ��� newNode�� data �ʵ忡 input
		newNode->link = NULL; // newNode�� �����͸� �ƹ��͵� ����Ű�� �ʰ� �Ѵ�

		if (head == NULL)	head = tail = newNode; // head �����Ͱ� �ƹ��͵� ����Ű�� �ʴ� ��� LinkedList���� �ƹ��͵� �����Ƿ� head, tail �����͸� ���� �Ҵ��� newNode�� ����Ű�� �Ѵ�
		else {
			tail->link = newNode; // tail�� ����Ű�� ����� link �����͸� ���� �Ҵ��� newNode�� ����Ű�� �Ѵ�
			tail = newNode; // tail�� newNode�� ����Ű�� �Ѵ�
		}
		
		ListSize++; // ListSize�� 1 ������Ų��
	}

	void insert(int data, int position) { // LinkedList�� postion ��ġ�� ���ο� ��带 �����Ű�� insert �Լ�
		Node * temp_front = head; // Node���� ����Ű�� �����͸� �ϳ� �����ؼ� head �����Ͱ� ���� ����Ű�� �ִ� ��带 ����Ű�� �Ѵ�
		Node * temp_next;
		Node * newNode = (Node*)malloc(sizeof(Node)); // ���ο� ����� �޸� ������ Ȯ�� (�����Ҵ�)
		newNode->data = data; // parameter�� data���� ���� �Ҵ��� newNode�� data �ʵ忡 input
		
		if (position > ListSize + 1) { // ���� LinkedList ����� �� ���� + 1���� position�� ū ��� return (��带 �����ϸ� ���� ListSize�� + 1���� �Ǳ� ����)
			cout << "��ġ�� �ٽ� �������ּ���" << endl;
			return;
		}

		if (head == NULL) { // ���� LinkedList�� �ƹ��͵� ���� ���
			newNode->link = NULL; // newNode�� link �����͸� �ƹ��͵� ����Ű�� �ʰ� �� ��
			head = tail = newNode; // head, tail �����͸� newNode�� ����Ű�� �Ѵ�
		}
		else { // ���� LinkedList�� �ϳ� �̻��� ��尡 �ִ� ���
			for (int index = 1; index < position - 1; index++)	temp_front = temp_front->link;	// �ݺ����� ����� link �����͸� ���� �����Ϸ��� ��ġ�� �ձ��� temp�� �̵���Ų��
			
			if (position == 1) { // �����Ϸ��� ����� ��ġ�� �� ó���� ���
				newNode->link = head; // newNode�� link �����Ͱ� head�� ����Ű�� ��带 ����Ű�� �� ��
				head = newNode; // head�� newNode�� ����Ű�� �Ѵ�
			}
			else if (temp_front->link == NULL) { // �����Ϸ��� ����� ��ġ�� �� �������� ���
				newNode->link = NULL; // newNode�� link �����͸� �ƹ��͵� ����Ű�� �ʰ� �� ��
				temp_front->link = newNode; // �ռ� �ݺ����� ���� �̵��� temp_front�� link �����͸� newNode�� ����Ű�� �Ѵ�
				tail = newNode; // tail�� newNode�� ����Ű�� �Ѵ�
			}
			else { // �����Ϸ��� ����� ��ġ�� �߰��� ���
				temp_next = temp_front->link; // temp_next �����ʹ� �����Ϸ��� ��ġ�� ���� ��带 ����Ų��
				newNode->link = temp_next; // newNode�� link �����͸� temp_next�� ����Ű�� ��带 ����Ű�� �Ѵ�
				temp_front->link = newNode; // temp_front�� ����Ű�� ����� link �����͸� newNode�� ����Ű�� �Ѵ�
			}
		}

		ListSize++; // ListSize�� 1 ������Ų��
	}

	// --------------------------------------------------------------------- 

	// ----------------------------- erase �Լ� -----------------------------
	// parameter�� 0���� ���� �Ǹ����� ��带 ����
	// parameter�� 1���� ���� parameter ��ġ�� ��带 ����

	void erase() { // LinkedList�� �� ������ ��带 �����ϴ� erase �Լ�
		if (head == NULL) { // LinkedList�� ��尡 ���� ���
			cout << "������ ��尡 �����ϴ�" << endl;
			return;
		}
		else if (head->link == NULL) { // LinkedList�� ��尡 1���� ���
			Node * temp = head; // temp �����͸� head�� ����Ű�� ��带 ����Ű�� �� ��
			free(temp); // ���ο� ��带 ����� ���� �������� �Ҵ��ߴ� �� ������ �޸𸮸� �ٽ� ��ȯ
			head = tail = NULL; // head, tail �����͸� �ƹ��͵� ����Ű�� �ʰ� �Ѵ�
		}
		else {
			Node * temp_front;
			Node * temp_next = tail;
			for (temp_front = head; temp_front->link != tail; temp_front = temp_front->link); // temp_front �����͸� LinkedList �� ������ ����� �� ��带 ����Ű�� �Ѵ�
			free(temp_next); // LinkedList ������ ��� �޸� ������ ��ȯ
			temp_front->link = NULL; // temp_front�� link �����͸� �ƹ��͵� ����Ű�� �ʰ� �Ѵ�
			tail = temp_front; // tail �����͸� temp_front�� ����Ű�� ��带 ����Ű�� �Ѵ�
		}
		ListSize--; // ListSize�� 1 ���ҽ�Ų��
	}

	void erase(int position) { // LinkedList�� position ��ġ�� ��带 �����ϴ� erase �Լ�
		if (position > ListSize) { // ���� LinkedList ����� �� ���� + 1���� position�� ū ��� return
			cout << "��ġ�� �ٽ� �������ּ���" << endl;
			return;
		}

		if (head == NULL) { // LinkedList�� ��尡 ���� ���
			cout << "������ ��尡 �����ϴ�" << endl;
			return;
		}
		else { // LinkedList�� ��尡 ���� ���
			Node * temp_front = head;
			Node * temp_next;
			for (int index = 1; index < position - 1; index++)	temp_front = temp_front->link; // �ݺ����� ����� link �����͸� ���� �����Ϸ��� ��ġ�� �ձ��� temp_front�� �̵���Ų��
			if (position == 1) { // �����Ϸ��� ����� ��ġ�� �� ó�� ����� ���   ex) ����Ʈ�� 1-2-3�� ��� 1�� �����ϴ� ���
				head = temp_front->link; // head �����Ͱ� temp_front�� link �����Ͱ� ����Ű�� ��带 ����Ű�� �� ��   ex) head �����Ͱ� 2�� ����Ű�� �Ѵ�
				free(temp_front); // temp_front�� ����Ű�� ����� �޸𸮸� ��ȯ�Ѵ�   ex) 1�� �޸� ��ȯ�Ѵ�
			}
			else if (temp_front->link == tail) { // �����Ϸ��� ����� ��ġ�� �� ������ ����� ���  ex) ����Ʈ�� 1-2-3�� ��� 3�� �����ϴ� ���
				temp_next = tail; // temp_next �����Ͱ� �� ������ ��带 ����Ű�� �Ѵ�   ex) temp_next �����Ͱ� 3�� ����Ű�� �Ѵ�
				temp_front->link = NULL; // temp_front�� link �����Ͱ� �ƹ��͵� ����Ű�� �ʰ� �Ѵ�   ex) 2���� 3���� ���� ������ ���´�
				tail = temp_front; // tail �����Ͱ� temp_front�� ����Ű�� ��带 ����Ű�� �� ��   ex) tail�� 2�� ����Ű�� �Ѵ�
				free(temp_next); // temp_next�� ����Ű�� ����� �޸𸮸� ��ȯ�Ѵ�   ex) 3�� �޸� ��ȯ�Ѵ�
			}
			else { // �����Ϸ��� ����� ��ġ�� �߰��� ���  ex) ����Ʈ�� 1-2-3�� ��� 2�� �����ϴ� ���
				temp_next = temp_front->link; // temp_next �����Ͱ� temp_front�� link �����Ͱ� ����Ű�� ��带 ����Ű�� �Ѵ�  ex) temp_next �����Ͱ� 2�� ����Ű�� ��
				temp_front->link = temp_next->link; // temp_front�� link �����Ͱ� temp_next�� link �����͸� ����Ű�� �� ��   ex) 1�� 3�� �����Ų��
				free(temp_next); //temp_next�� ����Ű�� ����� �޸𸮸� ��ȯ�Ѵ�   ex) 2�� �޸� ��ȯ�Ѵ�
			}
		}
		ListSize--; // ListSize�� 1 ���ҽ�Ų��
	}

	// ---------------------------------------------------------------------

	int size() { // LinkedList�� ��� �� ������ ��ȯ�Ѵ�
		return ListSize;
	}

	void print() {
		for (Node * temp = head; temp != tail->link; temp = temp->link)	cout << temp->data << " "; // LinkedList�� ��ȸ�ϸ鼭 data ���� ����Ѵ�
		cout << endl;
	}
};

int main() {
	LinkedList list;
	list.insert(8, 1);
	list.insert(1);
	list.print();
	list.insert(2);
	list.print();
	list.insert(3, 2);
	list.print();
	list.insert(4, 3);
	list.print();
	list.erase(2);
	list.print();
	list.erase();
	list.print();
	cout << "���� LinkedList�� ��� �� ������ " << list.size() << "���Դϴ�." << endl;
}
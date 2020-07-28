#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
	int data; // Node 내부의 data 값
	struct Node * link; // List의 다음 노드를 가리킬 Node 포인터
};

class LinkedList {
private:
	Node * head; // LinkedList의 첫 노드 포인터
	Node * tail; // LinkedList의 마지막 노드 포인터
	int ListSize; // LinkedList의 전체 노드 개수
public:
	LinkedList() { // LinkedList 클래스의 생성자 (head, tail 포인터와 ListSize 변수를 초기화 해준다)
		head = tail = NULL;
		ListSize = 0;
	}
	
	// ----------------------------- insert 함수 ----------------------------- 
	// parameter가 1개일 때는 맨 마지막 노드를 삽입
	// parameter가 2개일 때는 두 번째 parameter의 위치에 노드를 삽입

	void insert(int data) { // LinkedList의 맨 마지막 노드에 새로운 노드를 연결시키는 insert 함수
		Node * newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드의 메모리 공간을 확보 (동적할당)
		newNode->data = data; // parameter의 data값을 새로 할당한 newNode의 data 필드에 input
		newNode->link = NULL; // newNode의 포인터를 아무것도 가리키지 않게 한다

		if (head == NULL)	head = tail = newNode; // head 포인터가 아무것도 가리키지 않는 경우 LinkedList에는 아무것도 없으므로 head, tail 포인터를 새로 할당한 newNode를 가리키게 한다
		else {
			tail->link = newNode; // tail이 가리키는 노드의 link 포인터를 새로 할당한 newNode를 가리키게 한다
			tail = newNode; // tail이 newNode를 가리키게 한다
		}
		
		ListSize++; // ListSize를 1 증가시킨다
	}

	void insert(int data, int position) { // LinkedList의 postion 위치에 새로운 노드를 연결시키는 insert 함수
		Node * temp_front = head; // Node형을 가리키는 포인터를 하나 선언해서 head 포인터가 현재 가리키고 있는 노드를 가리키게 한다
		Node * temp_next;
		Node * newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드의 메모리 공간을 확보 (동적할당)
		newNode->data = data; // parameter의 data값을 새로 할당한 newNode의 data 필드에 input
		
		if (position > ListSize + 1) { // 현재 LinkedList 노드의 총 개수 + 1보다 position이 큰 경우 return (노드를 삽입하면 현재 ListSize의 + 1개가 되기 때문)
			cout << "위치를 다시 설정해주세요" << endl;
			return;
		}

		if (head == NULL) { // 현재 LinkedList에 아무것도 없는 경우
			newNode->link = NULL; // newNode의 link 포인터를 아무것도 가리키지 않게 한 후
			head = tail = newNode; // head, tail 포인터를 newNode를 가리키게 한다
		}
		else { // 현재 LinkedList에 하나 이상의 노드가 있는 경우
			for (int index = 1; index < position - 1; index++)	temp_front = temp_front->link;	// 반복문과 노드의 link 포인터를 통해 삽입하려는 위치의 앞까지 temp를 이동시킨다
			
			if (position == 1) { // 삽입하려는 노드의 위치가 맨 처음일 경우
				newNode->link = head; // newNode의 link 포인터가 head가 가리키는 노드를 가리키게 한 후
				head = newNode; // head가 newNode를 가리키게 한다
			}
			else if (temp_front->link == NULL) { // 삽입하려는 노드의 위치가 맨 마지막일 경우
				newNode->link = NULL; // newNode의 link 포인터를 아무것도 가리키지 않게 한 후
				temp_front->link = newNode; // 앞서 반복문을 통해 이동한 temp_front의 link 포인터를 newNode를 가리키게 한다
				tail = newNode; // tail이 newNode를 가리키게 한다
			}
			else { // 삽입하려는 노드의 위치가 중간일 경우
				temp_next = temp_front->link; // temp_next 포인터는 삽입하려는 위치의 다음 노드를 가리킨다
				newNode->link = temp_next; // newNode의 link 포인터를 temp_next가 가리키는 노드를 가리키게 한다
				temp_front->link = newNode; // temp_front가 가리키는 노드의 link 포인터를 newNode를 가리키게 한다
			}
		}

		ListSize++; // ListSize를 1 증가시킨다
	}

	// --------------------------------------------------------------------- 

	// ----------------------------- erase 함수 -----------------------------
	// parameter가 0개일 때는 맨마지막 노드를 삭제
	// parameter가 1개일 때는 parameter 위치의 노드를 삭제

	void erase() { // LinkedList의 맨 마지막 노드를 삭제하는 erase 함수
		if (head == NULL) { // LinkedList의 노드가 없을 경우
			cout << "삭제할 노드가 없습니다" << endl;
			return;
		}
		else if (head->link == NULL) { // LinkedList의 노드가 1개일 경우
			Node * temp = head; // temp 포인터를 head가 가리키는 노드를 가리키게 한 후
			free(temp); // 새로운 노드를 만들기 위해 동적으로 할당했던 힙 영역의 메모리를 다시 반환
			head = tail = NULL; // head, tail 포인터를 아무것도 가리키지 않게 한다
		}
		else {
			Node * temp_front;
			Node * temp_next = tail;
			for (temp_front = head; temp_front->link != tail; temp_front = temp_front->link); // temp_front 포인터를 LinkedList 맨 마지막 노드의 앞 노드를 가리키게 한다
			free(temp_next); // LinkedList 마지막 노드 메모리 공간을 반환
			temp_front->link = NULL; // temp_front의 link 포인터를 아무것도 가리키지 않게 한다
			tail = temp_front; // tail 포인터를 temp_front가 가리키는 노드를 가리키게 한다
		}
		ListSize--; // ListSize를 1 감소시킨다
	}

	void erase(int position) { // LinkedList의 position 위치의 노드를 삭제하는 erase 함수
		if (position > ListSize) { // 현재 LinkedList 노드의 총 개수 + 1보다 position이 큰 경우 return
			cout << "위치를 다시 설정해주세요" << endl;
			return;
		}

		if (head == NULL) { // LinkedList에 노드가 없을 경우
			cout << "삭제할 노드가 없습니다" << endl;
			return;
		}
		else { // LinkedList에 노드가 있을 경우
			Node * temp_front = head;
			Node * temp_next;
			for (int index = 1; index < position - 1; index++)	temp_front = temp_front->link; // 반복문과 노드의 link 포인터를 통해 삽입하려는 위치의 앞까지 temp_front를 이동시킨다
			if (position == 1) { // 삭제하려는 노드의 위치가 맨 처음 노드일 경우   ex) 리스트가 1-2-3일 경우 1을 삭제하는 경우
				head = temp_front->link; // head 포인터가 temp_front의 link 포인터가 가리키는 노드를 가리키게 한 후   ex) head 포인터가 2를 가리키게 한다
				free(temp_front); // temp_front가 가리키는 노드의 메모리를 반환한다   ex) 1을 메모리 반환한다
			}
			else if (temp_front->link == tail) { // 삭제하려는 노드의 위치가 맨 마지막 노드일 경우  ex) 리스트가 1-2-3일 경우 3을 삭제하는 경우
				temp_next = tail; // temp_next 포인터가 맨 마지막 노드를 가리키게 한다   ex) temp_next 포인터가 3을 가리키게 한다
				temp_front->link = NULL; // temp_front의 link 포인터가 아무것도 가리키지 않게 한다   ex) 2에서 3으로 가는 연결을 끊는다
				tail = temp_front; // tail 포인터가 temp_front가 가리키는 노드를 가리키게 한 후   ex) tail을 2를 가리키게 한다
				free(temp_next); // temp_next가 가리키는 노드의 메모리를 반환한다   ex) 3을 메모리 반환한다
			}
			else { // 삭제하려는 노드의 위치가 중간일 경우  ex) 리스트가 1-2-3일 경우 2를 삭제하는 경우
				temp_next = temp_front->link; // temp_next 포인터가 temp_front의 link 포인터가 가리키는 노드를 가리키게 한다  ex) temp_next 포인터가 2를 가리키게 함
				temp_front->link = temp_next->link; // temp_front의 link 포인터가 temp_next의 link 포인터를 가리키게 한 후   ex) 1을 3과 연결시킨다
				free(temp_next); //temp_next가 가리키는 노드의 메모리를 반환한다   ex) 2를 메모리 반환한다
			}
		}
		ListSize--; // ListSize를 1 감소시킨다
	}

	// ---------------------------------------------------------------------

	int size() { // LinkedList의 노드 총 개수를 반환한다
		return ListSize;
	}

	void print() {
		for (Node * temp = head; temp != tail->link; temp = temp->link)	cout << temp->data << " "; // LinkedList를 순회하면서 data 값을 출력한다
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
	cout << "현재 LinkedList의 노드 총 개수는 " << list.size() << "개입니다." << endl;
}
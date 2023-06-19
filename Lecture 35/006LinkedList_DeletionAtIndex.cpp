#include<iostream>

using namespace std;

class ListNode {

public :

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};


void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) {

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

void deleteAtHead(ListNode*& head) {

	if (!head) { // head == NULL
		// linkedList is empty
		return;
	}

	ListNode* temp = head;
	head = head->next;
	delete temp;
}

ListNode* getNode(ListNode* temp, int j) {

	int k = 0;
	while (temp != NULL && k < j) { // while(temp && k < j)
		temp = temp->next;
		k++;
	}

	return temp;

}

// time : O(n)

void deleteAtIndex(ListNode*& head, int i) {

	if (i == 0) {
		deleteAtHead(head);
		return;
	}

	// 1. get hold of the pointer to the node at the ith index
	ListNode* cur  = getNode(head, i);

	if (cur == NULL) {
		// i exceeds the length of the LL
		return;
	}

	// 2. get hold of the pointer to the node at the (i-1)th index
	ListNode* prev = getNode(head, i - 1);

	// 3. update the next field of the prev node to point to the node that comes after the cur node
	prev->next = cur->next;

	// 4. delete the cur node
	delete cur;
}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	// insertAtHead(head, 40);
	// insertAtHead(head, 30);
	// insertAtHead(head, 20);
	// insertAtHead(head, 10);

	// printLinkedList(head);

	// deleteAtIndex(head, 2);

	// printLinkedList(head);

	// deleteAtIndex(head, 0);

	// printLinkedList(head);

	// deleteAtIndex(head, 10);

	// printLinkedList(head);

	deleteAtIndex(head, 1);

	printLinkedList(head);

	return 0;
}
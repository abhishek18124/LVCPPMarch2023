#include<iostream>

using namespace std;

class ListNode {
public:

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

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

ListNode* kthNodeFromEnd(ListNode* head, int k) {

	ListNode* fast = head;

	// 1. move the fast pointer k-steps forward
	while (k--) {
		fast = fast->next;
	}

	ListNode* slow = head;

	// 2. iterate over the LL using slow and fast pointer at the same speed

	while (fast != NULL) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 70);
	insertAtHead(head, 60);
	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	int k = 1;

	ListNode* kthNode = kthNodeFromEnd(head, k);

	cout << kthNode->val << endl;

	return 0;
}
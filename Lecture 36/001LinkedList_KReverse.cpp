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

	while (head) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

ListNode* kReverse(ListNode* head, int k) {

	// base case
	if (head == NULL) {
		// LL is empty
		return head;
	}

	// recursive case

	ListNode* prev = NULL;
	ListNode* cur = head;
	int j = 0;

	while (cur != NULL and j < k) {
		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
		j++;
	}

	// recursively k-reverse the subList that contains the remaining n-k nodes
	ListNode* headFromMyFriend = kReverse(cur, k);
	head->next = headFromMyFriend;
	return prev;

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	int k = 3;

	head = kReverse(head, k);

	printLinkedList(head);

	return 0;
}
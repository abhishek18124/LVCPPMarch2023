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

ListNode* merge(ListNode* head1, ListNode* head2) {

	// base case
	if (head1 == NULL) {
		// first LL is empty
		return head2;
	}

	if (head2 == NULL) {
		// first LL is non-empty and second LL is empty
		return head1;
	}

	// recursive case

	ListNode* head = NULL;

	if (head1->val < head2->val) {
		// 1. head1 will be the head of the merged LL
		head = head1;
		// 2. merge the subList that starts from the node which comes after head1 with the second LL
		ListNode* headFromMyFriend = merge(head1->next, head2);
		head->next = headFromMyFriend;
	} else {
		// 1. head2 will be the head of the merged LL
		head = head2;
		// 2. merge the subList that starts from the node which comes after head2 with the first LL
		ListNode* headFromMyFriend = merge(head1, head2->next);
		head->next = headFromMyFriend;
	}

	return head;

}

int main() {

	ListNode* head2 = NULL;

	insertAtHead(head2, 50);
	insertAtHead(head2, 30);
	insertAtHead(head2, 10);

	printLinkedList(head2);

	ListNode* head1 = NULL;

	insertAtHead(head1, 60);
	insertAtHead(head1, 40);
	insertAtHead(head1, 20);

	printLinkedList(head1);

	ListNode* head = merge(head1, head2);

	printLinkedList(head);

	return 0;
}
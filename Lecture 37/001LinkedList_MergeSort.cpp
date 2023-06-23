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

ListNode* getMidPoint(ListNode* head) {
	if (!head) { // head == NULL
		return head;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

ListNode* merge(ListNode* head1, ListNode* head2) {

	ListNode* dummy = new ListNode(0);
	ListNode* temp  = dummy;

	while (head1 != NULL and head2 != NULL) {

		if (head1->val < head2->val) {

			temp->next = head1;
			head1 = head1->next;
			temp = temp->next;

		} else {

			temp->next = head2;
			head2 = head2->next;
			temp = temp->next;

		}

	}

	while (head1 != NULL) {

		temp->next = head1;
		head1 = head1->next;
		temp = temp->next;

	}

	while (head2 != NULL) {

		temp->next = head2;
		head2 = head2->next;
		temp = temp->next;

	}

	return dummy->next;

}

// time : O(n.logn) space : O(logn) due to function call stack

ListNode* mergeSort(ListNode* head1) {

	// base case
	if (head1 == NULL || head1->next == NULL) {
		// LL is either empty or it has a single node then it is already sorted
		return head1;
	}

	// recursive case

	// 1. divide the LL around the midPoint into two subLists

	ListNode* midPoint = getMidPoint(head1);
	ListNode* head2 = midPoint->next;
	midPoint->next = NULL;

	// 2. recursively sort the two subList
	head1 = mergeSort(head1);
	head2 = mergeSort(head2);

	// 3. merge the two sorted subLists
	return merge(head1, head2);

}


int main() {

	ListNode* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);

	printLinkedList(head);

	head = mergeSort(head);

	printLinkedList(head);

	return 0;
}
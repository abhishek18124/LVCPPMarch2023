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
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

// total steps = n + (n-(k%n)-1) ~ O(n) space : O(1)

ListNode* rotateLinkedList(ListNode* head, int k) {

	// 1. form a loop by connecting the tail ListNode of  the
	//    linkedList with the head ListNode of the linkedList
	int n = 1;
	ListNode* tail = head;
	while (tail->next != NULL) {
		n++;
		tail = tail->next;
	}

	tail->next = head;

	// 2. get hold of the pointer to the new tail ListNode
	//    that can be found at the (n-(k%n)-1)th index
	ListNode* newTail = head;
	for (int i = 0; i < n - (k % n) - 1; i++) {
		newTail = newTail->next;
	}

	// 3. get hold of the pointer to the new head ListNode
	ListNode* newHead = newTail->next;

	// 4. remove the cycle by updating the next pointer of
	//    the new tail ListNode to contain the NULL address
	newTail->next = NULL;

	return newHead;

}


// int computeLengthIterative(ListNode* head) {

// 	int cnt = 0;
// 	while (head) { // head != NULL
// 		cnt++;
// 		head = head->next;
// 	}

// 	return cnt;

// }

// // time : n+n = 2n ~ O(n) space : O(1)

// ListNode* rotateLinkedList(ListNode* head, int k) {

// 	int n = computeLengthIterative(head); // n-steps

// 	k = k % n;

// 	// 1. find the newTail i.e. the (k+1)th from the end // n-steps

// 	ListNode* fast = head;
// 	int j = 0;
// 	while (j < k + 1) {
// 		fast = fast->next;
// 		j++;
// 	}

// 	ListNode* slow = head;
// 	ListNode* tail;
// 	while (fast != NULL) {
// 		if (fast->next == NULL) {
// 			tail = fast;
// 		}
// 		slow = slow->next;
// 		fast = fast->next;
// 	}

// 	// 2. create a loop by connecting the tail of the LL with the head

// 	tail->next = head;

// 	ListNode* newTail = slow;

// 	// 3. find the newHead

// 	ListNode* newHead = newTail->next;

// 	// 4. break the loop

// 	newTail->next = NULL;

// 	return newHead;


// }


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

	int k = 8;

	head = rotateLinkedList(head, k);

	printLinkedList(head);

	return 0;
}
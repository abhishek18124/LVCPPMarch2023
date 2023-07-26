/*

Given an infinite stream of non-negative integers, design an algorithm to output the
top-K integers every time you encounter -1.

Example : Input = 4, 1, 2, -1, 3, -1 7 1 2 -1 8 -1 . . . ; K = 3
          Output = 1 2 4
                   2 3 4
                   3 4 7
                   4 7 8
                   . . .

*/

#include<iostream>
#include<queue>

#define pqmin priority_queue<int, vector<int>, greater<int>>

using namespace std;

void printTopK(pqmin minHeap) {

    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    cout << endl;

}

int main() {

    int k = 3;
    pqmin minHeap;

    int data;
    for (int i = 0; i < k; i++) {
        cin >> data;
        minHeap.push(data);
    }

    while (true) {

        cin >> data;

        if (data == 0) {
            // stream has ended
            break;
        }

        if (data == -1) {
            // print k-largest elements seen so far in the stream
            printTopK(minHeap);
        } else {
            if (data > minHeap.top()) {
                minHeap.pop();
                minHeap.push(data);
            }
        }

    }

    return 0;
}
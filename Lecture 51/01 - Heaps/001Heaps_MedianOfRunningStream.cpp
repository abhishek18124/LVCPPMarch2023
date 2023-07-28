/*

Given a running stream of integers, design an algorithm to print the median
of the numbers in the stream each time a new integer is added to the stream.

Example : Input = 4, 6, 2, 5,   3, 1,   7, 9,   8 . . .
          Output= 4, 5, 4, 4.5, 4, 3.5, 4, 4.5, 5 . . .

*/

#include<iostream>
#include<queue>

using namespace std;

int main() {

    int x;
    cin >> x;

    double median;
    median = x;

    cout << median << " ";

    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

    leftMaxHeap.push(x);

    while (true) {

        cin >> x;

        if (x > median) {

            // insert x into the rightMinHeap

            if (rightMinHeap.size() < leftMaxHeap.size()) {

                // you can insert 'x' into the rightMinHeap

                rightMinHeap.push(x);
                median = (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;

            } else if (rightMinHeap.size() == leftMaxHeap.size()) {

                // you can insert 'x' into the rightMinHeap

                rightMinHeap.push(x);
                median = rightMinHeap.top();

            } else { // rightMinHeap.size() > leftMaxHeap.size()

                // you can insert 'x' into the rightMinHeap after rebalance

                leftMaxHeap.push(rightMinHeap.top());
                rightMinHeap.pop();

                rightMinHeap.push(x);
                median = (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;

            }


        } else {

            // insert x into the leftMaxHeap

            if (leftMaxHeap.size() < rightMinHeap.size()) {

                // insert 'x' into the leftMaxHeap

                leftMaxHeap.push(x);
                median = (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;

            } else if (leftMaxHeap.size() == rightMinHeap.size()) {

                // insert 'x' into the leftMaxHeap

                leftMaxHeap.push(x);
                median = leftMaxHeap.top();

            } else { // leftMaxHeap.size() > rightMinHeap.size()

                // insert 'x' into the leftMaxHeap after rebalance

                rightMinHeap.push(leftMaxHeap.top());
                leftMaxHeap.pop();

                leftMaxHeap.push(x);
                median = (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;

            }

        }

        cout << median << " ";

    }



    return 0;
}
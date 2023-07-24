/*

    There are given n ropes of different lengths, we need to connect these ropes into one rope.
    The cost to connect two ropes is equal to the sum of their lengths. We need to connect the
    ropes with minimum cost.

    Example :

    Input : {4, 3, 2, 6}
    Output: 29

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

    vector<int> ropeLengths = {4, 3, 2, 6};

    priority_queue<int, vector<int>, greater<int>> minHeap(ropeLengths.begin(), ropeLengths.end());


    int minCost = 0;

    while (minHeap.size() > 1) {

        // 1. extract two minimum ropes

        int x = minHeap.top(); minHeap.pop();
        int y = minHeap.top(); minHeap.pop();

        // 2. merge the two minimum ropes

        minCost += (x + y);

        // 3. push the merged rope

        minHeap.push(x + y);

    }

    cout << minCost << endl;


    return 0;
}
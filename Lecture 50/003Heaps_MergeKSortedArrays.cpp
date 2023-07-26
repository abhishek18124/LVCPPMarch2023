/*

    Given k sorted arrays, merge them and print the sorted output.

    k = 3
    Input : {
                {1, 3, 5, 7},
                {2, 4, 6, 8},
                {0, 9, 10, 11}
            }

    Output: 0 1 2 3 4 5 6 7 8 9 10 11

*/

#include<iostream>
#include<queue>
#include<vector>

#define p_iii pair<int, pair<int, int>>

using namespace std;

class triple {

public :

    int val;
    int row;
    int col;

    triple(int val, int row, int col) {
        this->val = val;
        this->row = row;
        this->col = col;
    }

};

// tripleComparator class is used to build a minHeap of triples based on their values

class tripleCompartor {

public :

    bool operator()(triple a, triple b) {
        if (b.val < a.val) {
            // you need a swap to build a minHeap of triples based triple.val
            return true;
        }
        // you don't a swap to build a minHeap of triples based triple.val
        return false;

    }

};

int main() {

    vector<vector<int>> inp = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };

    int k = inp.size();

    vector<int> out;


    // priority_queue<triple, vector<triple>, tripleCompartor> minHeap;

    // for (int i = 0; i < k; i++) {
    //     minHeap.push(triple(inp[i][0], i, 0));
    // }


    // while (!minHeap.empty()) {

    //     triple t = minHeap.top(); minHeap.pop();

    //     int val = t.val;
    //     int row = t.row;
    //     int col = t.col;

    // out.push_back(val);

    // if (col + 1 < inp[row].size()) {
    //     minHeap.push(triple(inp[row][col + 1], row, col + 1));
    // }

    // }

    priority_queue<p_iii, vector<p_iii>, greater<p_iii>> minHeap;

    for (int i = 0; i < k; i++) {
        minHeap.push({inp[i][0], {i, 0}});
    }

    while (!minHeap.empty()) {

        p_iii p = minHeap.top();
        minHeap.pop();

        int val = p.first;
        int row = p.second.first;
        int col = p.second.second;

        out.push_back(val);

        if (col + 1 < inp[row].size()) {
            minHeap.push({inp[row][col + 1], {row, col + 1}});
        }

    }

    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << " ";
    }

    cout << endl;

    return 0;
}




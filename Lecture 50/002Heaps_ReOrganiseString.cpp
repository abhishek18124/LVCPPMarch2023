
#include<iostream>
#include<queue>

using namespace std;

bool reOrganise(string str) {

    int freq[26];
    memset(freq, 0, sizeof(freq));

    for (char ch : str) {
        freq[ch - 'a']++;
    }

    priority_queue<pair<int, char>> maxHeap;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            maxHeap.push({freq[i], i + 'a'});
        }
    }

    string outString = "";

    while (!maxHeap.empty()) {

        if (maxHeap.size() == 1) {

            pair<int, char> lastPair = maxHeap.top();
            maxHeap.pop();

            if (lastPair.first == 1) {
                // you can reOrganise the string
                outString += lastPair.second;
            } else {
                // lastPair.first > 1 therefore we cannot reOrganise the string
                outString = "";
            }

        } else {

            // extract the two characters with the highest frequencies

            pair<int, char> firstMaxPair = maxHeap.top();
            maxHeap.pop();

            outString += firstMaxPair.second;
            firstMaxPair.first--;

            pair<int, char> secondMaxPair = maxHeap.top();
            maxHeap.pop();

            outString += secondMaxPair.second;
            secondMaxPair.first--;

            if (firstMaxPair.first > 0) {
                maxHeap.push(firstMaxPair);
            }

            if (secondMaxPair.first > 0) {
                maxHeap.push(secondMaxPair);
            }

        }

    }

    cout << outString << endl;

    return outString == "" ? false : true;

}

int main() {

    string str = "aaaaabbbbcccdd";

    reOrganise(str) ? cout << str << " can be reOrganised" << endl :
                           cout << str << " cannot be reOrganised" << endl;

    return 0;
}
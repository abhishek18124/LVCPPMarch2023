/*

Given a phone keypad as shown below, and an n digit number, print all words which are possible by
pressing the n digits on the keypad.

 1()     2(abc) 3(def)
 4(ghi)  5(jkl) 6(mno)
 7(pqrs) 8(tuv) 9(wxyz)

 n <= 9

*/

#include<iostream>

using namespace std;

string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// void generateWords(char* inp, int i, char* out, int j) {

//     // base case
//     if (inp[i] == '\0') { // or i == n
//         out[j] = '\0';
//         cout << out << endl;
//         return;
//     }

//     // recursive case

//     // take decisions for the remaining digits inp[i...n-1]

//     // take a decision for the ith digit

//     int d_i = inp[i] - '0';

//     if (d_i == 0 || d_i == 1) {
//         generateWords(inp, i + 1, out, j);
//         return;
//     }

//     string options = keypad[d_i];
//     int k = options.size();

//     for (int l = 0; l <= k - 1; l++) {
//         out[j] = options[l]; // c_l
//         generateWords(inp, i + 1, out, j + 1);
//     }

// }


void generateWords(char* inp, int i, string& out) {

    // base case
    if (inp[i] == '\0') {
        cout << out << endl;
        return;
    }

    // recursive case

    // take decisions for inp[i...n-1]

    // take the decision for the ith digit of the inp[]

    int d_i = inp[i] - '0';

    if (d_i == 0 || d_i == 1) {
        // skip the ith digit
        generateWords(inp, i + 1, out);
        return;
    }

    string options = keypad[d_i];
    for (char c_l : options) {
        out.push_back(c_l); // out += c_l
        generateWords(inp, i + 1, out);
        out.pop_back(); // backtracking step
    }

}

int main() {

    char inp[] = "923";

    // char out[10];
    // generateWords(inp, 0, out, 0);

    string out = "";
    generateWords(inp, 0, out);

    return 0;
}
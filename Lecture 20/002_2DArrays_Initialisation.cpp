#include<iostream>

using namespace std;

int main() {
  	
  	// int arr[3][4] = {{10, 15, 20, 25},
    //                 {30, 35, 40, 45},
    //                 {50, 55, 60, 65}};

    // int m = 3;
    // int n = 4;

    // for(int i=0; i<m; i++) {
    // 	for(int  j=0; j<n; j++) {
    // 		cout << arr[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }

    int brr[3][4];

    memset(brr, 0, sizeof(brr)); // zero init of brr[][]

    int mm = 3;
    int nn = 4;

    for(int i=0; i<mm; i++) {
        for(int  j=0; j<nn; j++) {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}
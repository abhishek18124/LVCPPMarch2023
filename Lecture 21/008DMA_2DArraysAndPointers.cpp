#include <iostream>

using namespace std;
int main()
{
    int arrs[3][3] = {{1,2,3} ,
                      {4,5,6},
                      {7,8,9}};

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << arrs[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    //static array
    cout << "arrs+1 = " << arrs + 1 << " arrs[1] = " << arrs[1] << " *(arrs+1) = " << *(arrs+1) << endl;

    
    int **arrd = new int*[3];
    for (int i=0; i<3; i++) {
         arrd[i] = new int[3];
         for (int j=0; j<3; j++) {
             arrd[i][j] = i;
         }
    }

     //dynamic array
    cout << "arrd+1 = " << arrd+1 << " arrd[1] = " << arrd[1] << " *(arrd+1) = " << *(arrd+1) << endl;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << arrd[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;



    
   
    return 0;
}
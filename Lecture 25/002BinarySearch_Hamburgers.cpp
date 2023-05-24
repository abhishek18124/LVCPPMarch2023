/*
    
    @author : abhishek srivastava https://twitter.com/srivabhishekml
    Hamburgers : https://codeforces.com/contest/371/problem/C
    
    constraints : 
    
    1 ≤ s.length ≤ 100
    n_b, n_s, n_c (1 ≤ n_b,n_s,n_c ≤ 100)
    p_b, p_s, p_c (1 ≤ p_b,p_s,p_c ≤ 100)
    1 ≤ r ≤ 10^12

    What is the minimum no. of hamburgers Polycarpus can make ? 

    assume,

        * s.length = 1 (say s = "B") 
        * n_b, n_s, n_c = 1 
        * p_b, p_s, p_c > 1 
        * r = 1

        under these contraints, Polycarpus can only make a single hamburger.

    What is the maximum no. of hamburgers Polycarpus can make ? 

    assume,

        * s.length = 1 (say s = "B") 
        * n_b, n_s, n_c = 100 
        * p_b, p_s, p_c = 1 
        * r = 10^12

        under these contraints, Polycarpus can only make a 10^12 + 100 hamburgers.


*/

#include<iostream>
#define ll long long

using namespace std;

string s;          // to store the hamburger's recipe 
int n_b, n_s, n_c; // to store the inventory of 'B', 'S' and 'C' 
int p_b, p_s, p_c; // to store the price of 'B', 'S' and 'C'
int c_b, c_s, c_c; // to store the frequencies of 'B', 'S' and 'C' hamburger's recipe
ll r;              // to store the money Polycarpus has

bool canPolycarpusCook(ll x) {

    // check if Polycarpus can cook 'x' hamburgers ?

    // to cook 'x' hamburgers, Polycarpus needs x.c_b bread, x.c_s sausage & x.c_c cheese pieces
    // in the inventory, Polycarpus already has n_b bread, n_s sausage & n_c cheese pieces

    ll e_b = max((ll)0, x*c_b - n_b); // to store extra bread   pieces required to cook 'x' hamburgers
    ll e_s = max((ll)0, x*c_s - n_s); // to store extra sausage pieces required to cook 'x' hamburgers
    ll e_c = max((ll)0, x*c_c - n_c); // to store extra cheese  pieces required to cook 'x' hamburgers

    ll e_r = e_b*p_b + e_s*p_s + e_c*p_c; // to store the money Polycarpus needs to purchase extra ingredients
    
    return e_r <= r;

}

int main() {
    
    cin >> s;
    cin >> n_b >> n_s >> n_c;
    cin >> p_b >> p_s >> p_c;
    cin >> r;
    
    for(char c : s) {
        if(c == 'B') c_b++; 
        else if(c == 'S') c_s++; 
        else if(c == 'C') c_c++; 
    }

    ll lo = 0; // min. no. of hamburgers Polycarpus can make
    ll hi = 1000000000100; // max. no. of hamburgers Polycarpus can make

    ll n_h = 0; // to track max. no. of hamburgers Polycarpus can make

    while(lo <= hi) {
        ll mid = lo+(hi-lo)/2;
        if(canPolycarpusCook(mid)) {
            // Polycarpus can cook 'mid' hamburgers therefore move right
            // so the search space reduces from [lo, hi] to [mid+1, hi].
            n_h = mid;
            lo  = mid+1;
        } else {
            // Polycarpus cannot cook 'mid' hamburgers hence move left
            // so the search space reduces from [lo, hi] to [lo, mid-1].
            hi = mid-1;
        }
    }

    cout << n_h << endl;

    return 0;
}
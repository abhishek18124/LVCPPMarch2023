#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool find132pattern(vector<int>& nums) {

   int n = nums.size();
   vector<int> leftMin(n); // to track the minimum element upto the ith index

   leftMin[0] = nums[0];
   for (int i = 1; i < n; i++) {
      leftMin[i] = min(nums[i], leftMin[i - 1]);
   }

   for (int i = 0; i < leftMin.size(); i++) {
      cout << leftMin[i] << " ";
   }

   stack<int> s; // used to track nearest greater to the right of nums_i

   for (int j = n - 1; j >= 0; j--) {

      int nums_i = leftMin[j];

      // find the nearest greater element to the right of nums_i

      // intuitively, we should find next greater element for nums_i

      // but, why is this working ? todo ...

      while (!s.empty() and s.top() <= nums_i) {
         s.pop();
      }

      if (!s.empty() and s.top() < nums[j]) { // !s.empty() -> you've found next greater element of nums_i
         // s.top() is nums_k therefore you've found 132 pattern
         return true;
      }

      s.push(nums[j]);

   }

   // there is no 132 pattern in nums[]
   return false;

}

int main() {

   vector<int> nums = {2, 4, 5, 3, 7};

   find132pattern(nums) ? cout << "true" << endl :
                               cout << "false" << endl ;

}
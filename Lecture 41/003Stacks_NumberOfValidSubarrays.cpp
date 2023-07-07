#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// time : O(n) space : O(n)

int validSubarrays(vector<int>& nums) {

   stack<pair<int, int>> s; // {value, index}
   vector<int> out;

   int n = nums.size();

   for (int i = n - 1; i >= 0; i--) {

      // find the index of the nearest smaller element to the right of nums[i]

      while (!s.empty() and s.top().first >= nums[i]) {
         s.pop();
      }

      if (s.empty()) {
         // nums[i] doesn't have a nearest smaller element to its right
         out.push_back(n);
      } else {
         // s.top().first represent the value which is nearest smaller to the right of nums[i]
         out.push_back(s.top().second);
      }

      s.push({nums[i], i});

   }

   reverse(out.begin(), out.end());

   int count = 0; // to store the no. of valid subarrays

   for (int i = 0; i < n; i++) {
      count += out[i] - i; // no. of valid subarrays that start at the ith index
   }

   return count;

}

int main() {

   vector<int> nums = {1, 4, 2, 5, 3, 9};

   cout << validSubarrays(nums) << endl;

}
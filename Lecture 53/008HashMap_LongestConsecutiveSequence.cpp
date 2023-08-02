/*
	https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {

		unordered_map<int, bool> startMap;

		for (int i = 0; i < nums.size(); i++) {

			if (startMap.find(nums[i] - 1) != startMap.end()) {
				startMap[nums[i]] = false;
			} else {
				startMap[nums[i]] = true;
			}

			if (startMap.find(nums[i] + 1) != startMap.end()) {
				startMap[nums[i] + 1] = false;
			}

		}

		int maxLen = 0;

		for (pair<int, bool> p : startMap) {
			int key = p.first;
			bool value = p.second;
			if (value == true) {
				// we can start a sequence of consecutive elements from 'key'
				int count = 0;
				while (startMap.find(key) != startMap.end()) {
					count++;
					key++;
				}
				maxLen = max(maxLen, count);
			}
		}

		return maxLen;

	}
};

int main() {

	Solution s;

	vector<int> nums = {0, 1, 4, 5, 6, 11, 12, 13, 14};

	cout << s.longestConsecutive(nums) << endl;

}

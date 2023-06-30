#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {

	stack<int> s;

	// time : O(n) space : O(n)

	for (int ast : asteroids) {
		if (ast < 0 and !s.empty() and s.top() > 0) {
			// collision
			bool flag = true; // assume current asteroid 'ast' will be not be destroyed
			while (!s.empty() and s.top() > 0) {
				if (s.top() < abs(ast)) {
					// asteroid on top of the stack will be destroyed
					s.pop();
				} else if (s.top() > abs(ast)) {
					// current asteroid 'ast' will be destroyed
					flag = false;
					break;
				} else { // s.top() == abs(ast)
					// asteroid on top of the stack and current asteroid 'ast' will be destroyed
					s.pop();
					flag = false;
					break;
				}
			}
			if (flag == true) {
				s.push(ast);
			}
		} else {
			// no collision
			s.push(ast);
		}
	}

	vector<int> out;

	while (!s.empty()) {
		out.push_back(s.top());
		s.pop();
	}

	reverse(out.begin(), out.end());

	return out;

}

int main() {

	vector<int> asteroids = {7, 3, -4, 5, 2, -8, 2, 4, 1, -4};

	vector<int> out = asteroidCollision(asteroids);

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

	return 0;
}
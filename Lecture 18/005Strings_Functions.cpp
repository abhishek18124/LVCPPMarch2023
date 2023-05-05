#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	// // computing the size or length of a string

	// string str = "coding blocks";

	// cout << str.length() << endl;
	// cout << str.size() << endl;

	// appending / concatnating str2 to str1

	string str1 = "new";
	string str2 = "delhi";
	
	// // 1. using append()
	
	// str1.append(str2);
	// cout << str1 << " " << str2 << endl;

	// // 2. using '+' operator

	// cout << str1+str2 << endl;
	// cout << str1 << endl;
	// cout << str2 << endl;

	// str1 = str1 + str2;
	// cout << str1 << endl;
	// cout << str2 << endl;

	// comparing two strings

	// string str3 = "abc";
	// string str4 = "zzzz";

	// // // 1. using compare
	// // cout << str3.compare(str4) << endl;

	// // 2. using relational operators
	// if(str3 > str4) {
	// 	cout << str3 << " is greater" << endl;
	// } else {
	// 	cout << str4 << " is greater" << endl;
	// }

	// // searching for a substring in a string using find()

	// string str5 = "mississippi";

	// cout << str5.find("si") << endl; // 3
	// cout << str5.rfind("si") << endl; // 6
	// cout << str5.find("hello") << endl;
	// cout << string::npos << endl;

	// string key = "hello";
	// if(str5.find(key) != string::npos) {
	// 	cout << key << " is present" << endl;
	// } else {
	// 	cout << key << " is not present" << endl;
	// }

	// // extracting a substring from a string using substr()

	// string str6 = "helloworld";
	// string subString = str6.substr(6);
	// cout << subString << endl;

	// subString = str6.substr(7, 2);
	// cout << subString << endl;

	// // converting a string into char array

	// string str7 = "new delhi";
	// char* arr = (char*)str7.c_str();
	// cout << arr << endl;

	// // converting a char array into a string

	// char a[] = "hello world";
	// string str(a);
	// cout << str << endl;

	// string st(10, 'z');
	// cout << st << endl;

	// reversing a string using reverse()

	string str9 = "hello";

	// reverse str9 from index 1 to 3 i.e. hlleo
	reverse(str9.begin()+1, str9.end()-1); // [start, end)
	
	cout << str9 << endl;

	reverse(str9.begin()+1, str9.begin()+4); // [start, end)
	
	cout << str9 << endl;

	reverse(str9.begin(), str9.end());

	cout << str9 << endl;

	return 0;
}
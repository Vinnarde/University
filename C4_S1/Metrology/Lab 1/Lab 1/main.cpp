#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reverseString(string& str)
{
	reverse(str.begin(), str.end());
}

int main()
{
	string str;
	cout << "Enter some text: ";
	getline(cin, str);

	cout << "Your text: " << str << '\n';
	reverseString(str);
	cout << "Reverse text: " << str << '\n';
}

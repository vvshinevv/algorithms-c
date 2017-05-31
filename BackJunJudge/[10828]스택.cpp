#if 0
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {

	stack<int> stack;
	int count;

	cin >> count;

	for (int i = 0; i < count; i++) {
		string str;
		cin >> str;

		if (str == "top") {
			if (stack.empty())
				cout << -1 << "\n";
			else
				cout << stack.top() << "\n";
		}
		else if (str == "pop") {
			if (stack.empty())
				cout << -1 << "\n";
			else {
				cout << stack.top() << "\n";
				stack.pop();
			}
		}
		else if (str == "size") {

			cout << stack.size() << "\n";
		}
		else if (str == "empty") {
			if (stack.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else {
			int num;
			cin >> num;
			stack.push(num);
		}
	}
	return 0;

}
#endif
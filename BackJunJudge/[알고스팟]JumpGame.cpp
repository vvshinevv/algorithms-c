/**
* [JUMPGAME] https://algospot.com/judge/problem/read/JUMPGAME
*/
#if 0

#include <iostream>
using namespace std;

int gameTable[][7] = {
	2, 5, 1, 6, 1, 4, 1,
	6, 1, 1, 2, 2, 9, 3,
	7, 2, 3, 2, 1, 3, 1,
	1, 1, 3, 1, 7, 1, 2,
	4, 1, 2, 3, 4, 1, 2,
	3, 3, 1, 2, 3, 4, 1,
	1, 5, 2, 9, 4, 7, 0
};

bool cache[][7] = { false, };

bool playGame(int row, int col) {
	if (row > 7 || col > 7)
		return false;

	if (gameTable[row][col] == 0)
		return true;

	bool &ret = cache[row][col];
	if (ret != false) return ret;

	int val = gameTable[row][col];
	return playGame(row + val, col) || playGame(row, col + val);
}

int main(void) {
	cout << playGame(0, 0);
	return 0;
}

#endif
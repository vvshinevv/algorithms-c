/**
* [이진탐색트리1]https://www.acmicpc.net/problem/2957
*/
#if 0
#include <iostream>
#include <map>

using namespace std;

int main(void) {

	int num, C = 0;

	cin >> num;
	map<long long int, int> mapArr;

	for (int i = 0; i < num; i++) {
		int data, key = 1;
		cin >> data;

		while (mapArr.count(key)) { // key가 존재하지 않을때까지 반복
			if (mapArr[key] < data) {
				key = 2 * key + 1;
				C++;
			}
			else {
				key = 2 * key;
				C++;
			}
		}
		mapArr.insert(pair<long long int, int>(key, data));
		cout << C << endl;
	}

	return 0;
}
#endif

/**
* [이진탐색트리2]https://www.acmicpc.net/problem/2957
*/
#if 0
#include <iostream>

using namespace std;

int C = 0;

typedef struct _bTreeNode {
	int data;
	struct _bTreeNode * left, *right;
} BTreeNode;

BTreeNode * MakeNode() {
	BTreeNode * bt = (BTreeNode *)malloc(sizeof(BTreeNode));
	bt->left = NULL;
	bt->right = NULL;

	return bt;
}

void Insert(int x, BTreeNode * N) {
	C++;
	BTreeNode * nNode = NULL;
	if (x < N->data) {
		if (N->left == NULL) {
			nNode = MakeNode(); nNode->data = x;
			N->left = nNode;
		}
		else {
			Insert(x, N->left);
		}
	}
	else {
		if (N->right == NULL) {
			nNode = MakeNode(); nNode->data = x;
			N->right = nNode;
		}
		else {
			Insert(x, N->right);
		}
	}
}

int main(void) {
	int num, data;
	cin >> num;

	BTreeNode * main = MakeNode();
	cin >> data; main->data = data;
	cout << C << endl;

	for (int i = 1; i < num; i++) {
		cin >> data;
		Insert(data, main);
		cout << C << endl;
	}
	return 0;
}

#endif

/**
* [이진탐색트리3]https://www.acmicpc.net/problem/2957
*/
#if 0

#include <iostream>

using namespace std;

int C = 0;

typedef struct _bTreeNode {
	int data;
	struct _bTreeNode *right, *left;
} BTreeNode;

BTreeNode * MakeNode() {
	BTreeNode * bt = (BTreeNode *)malloc(sizeof(BTreeNode));
	bt->left = NULL;
	bt->right = NULL;

	return bt;
}

void Insert(int x, BTreeNode * N) {
	BTreeNode * nNode = NULL;
	while (1) {
		C++;
		if (x < N->data) {
			if (N->right == NULL) {
				nNode = MakeNode(); nNode->data = x;
				N->right = nNode; break;
			}
			else {
				N = N->right;

			}
		}
		else {
			if (N->left == NULL) {
				nNode = MakeNode(); nNode->data = x;
				N->left = nNode; break;
			}
			else {
				N = N->left;
			}
		}
	}
}

int main(void) {
	int num, data;
	cin >> num >> data;

	BTreeNode * main = MakeNode();
	main->data = data; cout << C << endl;

	for (int i = 1; i < num; i++) {
		int data;
		cin >> data;

		Insert(data, main);
		cout << C << endl;
	}

	return 0;
}
#endif

/**
* [이진탐색트리4]https://www.acmicpc.net/problem/2957
*/
#if 0

#include <iostream>
using namespace std;
int C = 0;
typedef struct _bTreeNode {
	int data;
	struct _bTreeNode *right, *left;
} TreeNode;

void Insert(TreeNode ** root, int key) {
	TreeNode *p, *t;
	TreeNode *n;

	t = *root; p = NULL;

	while (t != NULL) {
		p = t; C++;
		if (key < t->data) t = t->left;
		else t = t->right;
	}

	n = (TreeNode *)malloc(sizeof(TreeNode));
	n->data = key; n->left = n->right = NULL;

	if (p != NULL) {
		if (key < p->data) p->left = n;
		else p->right = n;
	}
	else {
		*root = n;
	}
}
int main(void) {
	int num, data;
	cin >> num >> data;

	TreeNode * main = (TreeNode *)malloc(sizeof(TreeNode));
	main->data = data; main->left = main->right = NULL;
	cout << C << endl;

	for (int i = 1; i < num; i++) {
		int data;
		cin >> data;

		Insert(&main, data);
		cout << C << endl;
	}
	return 0;
}
#endif

/**
* [이진탐색트리5]https://www.acmicpc.net/problem/2957
*/
#if 0
#include <iostream>
using namespace std;
int C = 0;
int Tree[3000001][2];
void insert(int x, int root) {
	C++;
	if (root < x) {
		if (Tree[root][1] == -1) {
			Tree[x][0] = -1; Tree[x][1] = -1;
			Tree[root][1] = x;
		}
		else {
			root = Tree[root][1];
			insert(x, root);
		}
	}
	else {
		if (Tree[root][0] == -1) {
			Tree[x][0] = -1; Tree[x][1] = -1;
			Tree[root][0] = x;
		}
		else {
			root = Tree[root][0];
			insert(x, root);
		}
	}
}
int main(void) {
	int num, root;
	cin >> num >> root;
	Tree[root][0] = -1; Tree[root][1] = -1;
	cout << C << endl;
	for (int i = 1; i < num; i++) {
		int in; cin >> in;
		insert(in, root);
		cout << C << endl;
	}
	return 0;
}
#endif

/**
* [이진탐색트리6]https://www.acmicpc.net/problem/2957
*/
#if 0
#include <iostream>

using namespace std;

int C = 0;
int Tree[3000001][2];

void insert(int x, int root) {
	while (1) {
		C++;
		if (root < x) {
			if (Tree[root][1] == -1) {
				Tree[x][0] = -1; Tree[x][1] = -1;
				Tree[root][1] = x; break;
			}
			else {
				root = Tree[root][1];
			}
		}
		else {
			if (Tree[root][0] == -1) {
				Tree[x][0] = -1; Tree[x][1] = -1;
				Tree[root][0] = x; break;
			}
			else {
				root = Tree[root][0];
			}
		}
	}
}

int main(void) {
	int num, root;
	cin >> num >> root;

	Tree[root][0] = -1; Tree[root][1] = -1;
	cout << C << endl;
	for (int i = 1; i < num; i++) {
		int in; cin >> in;
		insert(in, root);
		cout << C << endl;
	}
	return 0;
}
#endif

/**
* [이진탐색트리7]https://www.acmicpc.net/problem/2957
*/
#if 0
#include <iostream>

#define left	0
#define right	1
#define value	2

using namespace std;

int Tree[3000001][3];
int C = 0;

void Insert(int x, int root) {
	if (Tree[x - 1][value] == 0 && Tree[x + 1][value] == 0) {
		// 일반 이진 탐색 트리
		//while (1) {
		if (root < x) {
			if (Tree[root][right] == -1) {
				Tree[x][left] = Tree[x][right] = -1;
				Tree[x][value] = Tree[root][value] + 1;

				Tree[root][right] = x;
				//break;
			}
			else {
				Insert(x, Tree[root][right]);
				//root = Tree[root][right];
			}
		}
		else {
			if (Tree[root][left] == -1) {
				Tree[x][left] = Tree[x][right] = -1;
				Tree[x][value] = Tree[root][value] + 1;

				Tree[root][left] = x;
				//break;
			}
			else {
				Insert(x, Tree[root][left]);
				//root = Tree[root][left];
			}
		}
		//}
	}
	else {
		if (Tree[x + 1][value] == 0) {
			// x+1이 트리에 존재하지 않는 경우
			Tree[x][left] = Tree[x][right] = -1;
			Tree[x][value] = Tree[x - 1][value] + 1;

			Tree[x - 1][right] = x;
		}
		else if (Tree[x - 1][value] == 0) {
			// x-1이 트리에 존재하지 않는 겨우
			Tree[x][left] = Tree[x][right] = -1;
			Tree[x][value] = Tree[x + 1][value] + 1;

			Tree[x + 1][left] = x;
		}
		else {
			// 둘 다 값이 존재하는 경우
			if (Tree[x - 1][right] != -1) {
				// x-1오른쪽에 값이 있는경우
				Tree[x][left] = Tree[x][right] = -1;
				Tree[x][value] = Tree[x + 1][value] + 1;

				Tree[x + 1][left] = x;
			}
			else {
				// x+1왼쪽에 값이 있는 경우
				Tree[x][left] = Tree[x][right] = -1;
				Tree[x][value] = Tree[x - 1][value] + 1;

				Tree[x - 1][right] = x;
			}
		}
	}
}

int main(void) {
	int num, root;
	cin >> num >> root;
	Tree[root][left] = Tree[root][right] = -1; // -1은 자식이 없음을 뜻함
	cout << C << endl;
	for (int i = 1; i < num; i++) {
		int in; cin >> in;
		Insert(in, root);

		C += Tree[in][value];
		cout << C << endl;
	}
	return 0;
}

#endif

/**
* [이진탐색트리8]https://www.acmicpc.net/problem/2957
*/
#if 0
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int check[3000001];
map<int, int> mapArr;
int C = 0;

void SelectSort(int len) {
	int maxIdx;
	int temp;

	for (int i = 0; i < len; i++) {
		maxIdx = i;
		for (int j = i + 1; j <= len; j++) {
			if (check[j] < check[maxIdx])
				maxIdx = j;
		}

		temp = check[i];
		check[i] = check[maxIdx];
		check[maxIdx] = temp;
	}
}

int BSearch(int target, int len) {
	int first = 0;
	int last = len;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;

		if (target == check[mid]) {
			return mid;
		}
		else {
			if (target < check[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return 0;
}

void Insert(int x, int len) {
	int tmp = x; int max = 0, min = 0;
	int count = 0;

	max = check[BSearch(x, len) - 1];
	min = check[BSearch(x, len) + 1];

	if (max == 0 && min == 0) {
		mapArr[x] = 0;
	}
	else {
		if (max != 0 && min != 0) {
			if (mapArr[max] < mapArr[min]) {
				mapArr[x] = mapArr[min] + 1;
			}
			else {
				mapArr[x] = mapArr[max] + 1;
			}
		}
		else if (max != 0) {
			mapArr[x] = mapArr[max] + 1;
		}
		else {
			mapArr[x] = mapArr[min] + 1;
		}
	}
}

int main(void) {

	int num; cin >> num;


	for (int i = 0; i < num; i++) {
		int in; cin >> in;

		check[i] = in;
		SelectSort(i);

		Insert(in, i);

		C += mapArr[in];
		cout << C << endl;

	}
	return 0;
}
#endif

/**
* [이진탐색트리9]https://www.acmicpc.net/problem/2957
*/
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

int C = 0;

typedef struct _bTreeNode {
	int data, height;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
	bool isThread;
} ThreadTree;

ThreadTree * MakeTreeNode() {
	ThreadTree * bt = (ThreadTree *)malloc(sizeof(ThreadTree));
	bt->left = NULL;
	bt->right = NULL;
}

void MakeLeftSubTree(ThreadTree * main, ThreadTree * sub) {
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
	main->isThread = false;
	sub->isThread = true;
}

void MakeRightSubTree(ThreadTree * main, ThreadTree * sub) {
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
	main->isThread = false;
	sub->isThread = true;
}

ThreadTree * SearchPredecessor(ThreadTree * main) {
	ThreadTree * tmpTree = main->left;
	while (tmpTree->right != NULL)
		tmpTree = tmpTree->right;

	return tmpTree;
}

ThreadTree * SearchSuccessor(ThreadTree * main) {
	ThreadTree * tmpTree = main->right;
	while (tmpTree->left != NULL)
		tmpTree = tmpTree->left;

	return tmpTree;
}

ThreadTree * RotateLL(ThreadTree * main) {
	ThreadTree * sub = main->left;

	MakeLeftSubTree(main, sub->right);
	MakeRightSubTree(sub, main);

	return sub;
}

ThreadTree * RotateRR(ThreadTree * main) {
	ThreadTree * sub = main->right;

	MakeRightSubTree(main, sub->left);
	MakeLeftSubTree(sub, main);

	return sub;
}

ThreadTree * RotateLR(ThreadTree * main) {
	MakeRightSubTree(RotateRR(main->left), RotateLL(main));
}

ThreadTree * RotateRL(ThreadTree * main) {
	MakeLeftSubTree(RotateLL(main->right), RotateRR(main));
}

int GetTreeHeight(ThreadTree * main) {
	int height = 0;
	if (main != NULL)
		height = 1 + max(GetTreeHeight(main->left), GetTreeHeight(main->right));

	return height;
}

int GetHeightGap(ThreadTree * main) {
	if (main == NULL)
		return 0;

	return GetTreeHeight(main->left) - GetTreeHeight(main->right);
}

ThreadTree * MakeAVLThreadTree(ThreadTree ** mt) {
	int heightGap = GetHeightGap(*mt);
	if (heightGap > 1) {
		if (GetHeightGap((*mt)->left) > 0)
			*mt = RotateLL(*mt);
		else
			*mt = RotateLR(*mt);
	}
	else if (heightGap < -1) {
		if (GetHeightGap((*mt)->right) < 0)
			*mt = RotateRR(*mt);
		else
			*mt = RotateRL(*mt);
	}
	return *mt;
}

void Insert(int x, ThreadTree * main) {

}

int main(void) {


	return 0;
}
#endif
/**
* [이진탐색트리10]https://www.acmicpc.net/problem/2957
*/
#if 0

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct AvlNode {
	int data;
	struct AvlNode * left_child, *right_child;
} AvlNode;

AvlNode * rotate_LL(AvlNode * parent) {
	AvlNode * child = parent->left_child;
	parent->left_child = child->right_child;
	child->right_child = parent;
	return child;
}

AvlNode * rotate_RR(AvlNode * parent) {
	AvlNode * child = parent->right_child;
	parent->right_child = child->left_child;
	child->left_child = parent;
	return child;
}

AvlNode * rotate_RL(AvlNode * parent) {
	AvlNode * child = parent->right_child;
	parent->right_child = rotate_LL(child);
	return rotate_RR(parent);
}

AvlNode * rotate_LR(AvlNode * parent) {
	AvlNode * child = parent->left_child;
	parent->left_child = rotate_RR(child);
	return rotate_LL(parent);
}

int get_height(AvlNode * node) {
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left_child), get_height(node->right_child));
	return height;
}

int get_height_diff(AvlNode * node) {
	if (node == NULL) return 0;
	return get_height(node->left_child) - get_height(node->right_child);
}

AvlNode * rebalance(AvlNode ** node) {
	int heigth_diff = get_height_diff(*node);
	if (heigth_diff > 1) {
		if (get_height_diff((*node)->left_child) > 0)
			*node = rotate_LL(*node);
		else
			*node = rotate_LR(*node);
	}
	else if (heigth_diff < -1) {
		if (get_height_diff((*node)->right_child) < 0)
			*node = rotate_RR(*node);
		else
			*node = rotate_RL(*node);
	}
	return *node;
}

AvlNode * avl_add(AvlNode ** root, int new_key) {
	if (*root == NULL) {
		*root = (AvlNode *)malloc(sizeof(AvlNode));
		if (*root == NULL) {
			fprintf(stderr, "메모리 할당 에러\n");
			exit(1);
		}
		(*root)->data = new_key;
		(*root)->left_child = (*root)->right_child = NULL;
	}
	else if (new_key < (*root)->data) {
		(*root)->left_child = avl_add(&((*root)->left_child), new_key);
		*root = rebalance(root);
	}
	else if (new_key >(*root)->data) {
		(*root)->right_child = avl_add(&((*root)->right_child), new_key);
		(*root) = rebalance(root);
	}
	else {
		fprintf(stderr, "중복된 키 에러\n");
		exit(1);
	}
	return *root;
}

int main(void) {

	AvlNode * root = NULL;

	avl_add(&root, 8);
	avl_add(&root, 9);
	avl_add(&root, 10);
	avl_add(&root, 2);
	avl_add(&root, 1);
	avl_add(&root, 5);
	avl_add(&root, 3);
	avl_add(&root, 6);
	avl_add(&root, 4);
	avl_add(&root, 7);
	avl_add(&root, 11);
	avl_add(&root, 12);

	return 0;
}


#endif

/**
* [이진탐색트리11]https://www.acmicpc.net/problem/2957
*/
#if 0
#include <cstdio>
#include <map>

#pragma warning(disable: 4995)

using namespace std;

int main(void) {
	int num, C = 0;
	map<int, int> mapArr;
	map<int, int>::iterator lower_bound;
	map<int, int>::iterator upper_bound;

	mapArr.insert(pair<int, int>(0, -1));
	mapArr.insert(pair<int, int>(3000001, -1));
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		int in; scanf_s("%d", &in);
		mapArr.insert(pair<int, int>(in, i));
		lower_bound = (--mapArr.lower_bound(in));
		upper_bound = (mapArr.upper_bound(in));

		if ((lower_bound->second == -1) && (upper_bound->second == -1)) {
			// 첫 노드 삽입
			mapArr.insert(pair<int, int>(in, 0));
		}
		else if (lower_bound->second == -1) {
			// 작은 것들 중 가장 큰 것이 없다면
			mapArr[in] = upper_bound->second + 1;
			C += mapArr[in];
		}
		else if (upper_bound->second == -1) {
			// 큰 것들 중 가장 작은 것이 없다면
			mapArr[in] = lower_bound->second + 1;
			C += mapArr[in];
		}
		else {
			// 그렇지 않다면 비교
			if (lower_bound->second < upper_bound->second) {
				mapArr[in] = upper_bound->second + 1;
				C += mapArr[in];
			}
			else {
				mapArr[in] = lower_bound->second + 1;
				C += mapArr[in];
			}
		}
		printf("%d\n", C);
	}

	return 0;
}
#endif

/**
* [이진탐색트리12]https://www.acmicpc.net/problem/2957
* 정답...
*/
#if 0
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
	int num;
	long long int C = 0;
	map<int, long long int> mapArr;
	map<int, long long int>::iterator lower_bound;
	map<int, long long int>::iterator upper_bound;

	mapArr.insert(pair<int, long long int>(0, -1));
	mapArr.insert(pair<int, long long int>(3000001, -1));
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		int in; scanf_s("%d", &in); long long int dep = 0;
		lower_bound = (--mapArr.lower_bound(in));
		upper_bound = (mapArr.upper_bound(in));
		dep = max(lower_bound->second, upper_bound->second) + 1;

		mapArr.insert(pair<int, long long int>(in, dep));
		C += dep;
		printf("%lld\n", C);
	}
	return 0;
}
#endif

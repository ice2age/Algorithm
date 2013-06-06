#include <cstdio>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;

int value;
bool yes;
struct Node
{
	Node(int v, Node* l, Node* r) : v(v), l(l), r(r) {}
	int v;
	Node *l, *r;
};

Node* input()
{
	int ch, v;
	while ((ch = getchar()) == ' ' || ch == '\n')
		;

	assert (ch == '(');
	Node* newnode = NULL;
	if (scanf ("%d", &v) == 1)
	{
		Node* l = input();
		Node* r = input();
		newnode = new Node(v, l, r);
	}
	
	while ((ch = getchar()) == ' ' || ch == '\n')
		;
	assert (ch == ')');
	return newnode;
}

void solve(Node* tree, int sum)
{
	if (yes || !tree)
		return;
	
	sum -= tree->v;
	if (!tree->l && !tree->r && sum == 0)
	{
		yes = true;
		return;
	}

	if (tree->l)
		solve(tree->l, sum);
	if (tree->r)
		solve(tree->r, sum);
}

int main()
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	while (cin >> value)
	{
		Node* tree = input();
		yes = false;
		solve(tree, value);
		cout << (yes ? "yes" : "no") << endl;
	}
	return 0;
}
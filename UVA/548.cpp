#include <iostream>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <string>
#include <limits>

using namespace std;

const int SIZE = 10000;
int n, m, mvalue;
int inor[SIZE];
int post[SIZE];

struct Node
{
    Node(int v, Node* l = NULL, Node* r = NULL)
        : v(v), l(l), r(r) {}

    int v;
    Node *l, *r;
};

Node* reconstruct(int l1, int r1, int l2, int r2)
{
    if (l1 > r1 || l2 > r2)
        return NULL;

    if (l1 == r1)
    {
        assert (inor[l1] == post[l2]);
        return new Node(inor[l1]);
    }
    int i;
    for (i = l1; i <= r1 && inor[i] != post[r2]; ++i)
        ;
    return new Node(inor[i],
        reconstruct(l1, i-1, l2, i-1+l2-l1),
        reconstruct(i+1, r1, i+l2-l1, r2-1));
}

void solve(Node* tree, int path)
{
    path += tree->v;
    if (tree->l == NULL && tree->r == NULL && path < m)
    {
        m = path;
        mvalue = tree->v;
    }
    if (tree->l) solve(tree->l, path);
    if (tree->r) solve(tree->r, path);
}

bool input(int* d)
{
    n = 0;
    if (scanf ("%d", &d[n++]) == EOF)
        return false;
    while (getchar() != '\n')
        scanf ("%d", &d[n++]);
    return true;
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    string line;
    while(true)
    {
        if (!input(inor) || !input(post))
            break;

        m = numeric_limits<int>::max();
        Node* tree = reconstruct(0,n-1,0,n-1);
        solve(tree, 0);
        cout << mvalue << endl;
    }

    return 0;
}

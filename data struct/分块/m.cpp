#include <bits/stdc++.h>

using namespace std;

const int N = 10000100;

int pos[N];

struct Node {
    int l, r, id;
}Q[N];

long long Ans[N];
long long flag[N];
int a[N];
int L = 1, R = 0, k;
long long ans = 0;

bool cmp(Node a, Node b) {
    return (pos[a.l] == pos[b.l] ? a.r < b.r : pos[a.l] < pos[b.l]);
}

void del(int i)
{
    flag[a[i]]--;
    ans -= flag[a[i] ^ k];
}

void add(int i)
{
    ans += flag[a[i] ^ k];
    flag[a[i]]++;
}

int main()
{
    int n, m;
    scanf("%d%d%d", &n, &m, &k);
    int block = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] = a[i] ^ a[i - 1];
        pos[i] = i / block;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &Q[i].l, &Q[i].r);
        Q[i].id = i;
    }
    flag[0] = 1;
    sort(Q + 1, Q + m + 1);
    for (int i = 1; i <= m; i++) {
        while (L < Q[i].l) {
            del(L - 1);
            L++;
        }
        while (L > Q[i].l) {
            L--;
            add(L - 1);
        }
        while (R < Q[i].r) {
            R++;
            add(R);
        }
        while (R > Q[i].r) {
            del(R);
            R--;
        }
        Ans[Q[i].id] = ans;
    }
    for (int i = 1; i <= m; i++) cout << Ans[i] << endl;
    return 0;
}
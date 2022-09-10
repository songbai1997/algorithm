#include <bits/stdc++.h>

using namespace std;

const int N = 100050;

int wa[N], wb[N], wv[N], ws[N];

inline bool cmp(int *r, int a, int b, int len) {
    return r[a] == r[b] && r[a + len] == r[b + len];
}

void SA(char *r, int *sa, int n, int m) {
    int i, j, p, *x = wa, *y = wb, *t;
    for (i = 0; i < m; i++) ws[i] = 0;
    for (i = 0; i < n; i++) ws[x[i] = r[i]]++;
    for (i = 1; i < m; i++) ws[i] += ws[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--ws[x[i]]] = i;
    for (j = p = 1; p < n; j <<= 1, m = p) {
        for (p = 0, i = n - j; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
        for (int i = 0; i < m; i++) ws[i] = 0;
        for (int i = 0; i < n; i++) ws[wv[i] = x[y[i]]]++;
        for (int i = 1; i < m; i++) ws[i] += ws[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--ws[wv[i]]] = y[i];
        for (t = x, x = y, y = t, x[sa[0]] = 0, p = i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1: p++;
    }
}
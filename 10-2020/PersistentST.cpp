//
// Created by admin on 24/10/2020.
//

#include <iostream>

using namespace std;

struct Node {
    int left;
    int right;
    int optimal;

    Node(int left, int right, int optimal) : left(left), right(right), optimal(optimal) {}

    Node() : left(0), right(0), optimal(0) {}

} seg_tree[100005];

int nNode = 0;
int ver[100005];

inline void optimize(int id) {
    seg_tree[id].optimal = max(seg_tree[seg_tree[id].left].optimal, seg_tree[seg_tree[id].right].optimal);
}

int update(int l, int r, int pos, int val, int id) {
    if (l == r) {
        seg_tree[++nNode] = Node(0, 0, val);
        return nNode;
    }
    int cur = ++nNode;

    int mid = (l + r) >> 1;

    if (pos <= mid) {
        seg_tree[cur].left = update(l, mid, pos, val, id);
        seg_tree[cur].right = seg_tree[id].right;
        optimize(cur);
    } else {
        seg_tree[cur].left = seg_tree[id].left;
        seg_tree[cur].right = update(mid + 1, r, pos, val, id);
        optimize(cur);
    }

    return cur;
}

int get(int l, int r, int u, int v, int id) {
    if (v < l || u > r)return -1000000;
    if (u <= l && r <= v)return seg_tree[id].optimal;

    int mid = (l + r) >> 1;
    return max(get(l, mid, u, v, seg_tree[id].left), get(mid + 1, r, u, v, seg_tree[id].right));
}

int main() {
    /*
    // When update:
    ++nVer;
    ver[nVer] = update(1, n, u, x, ver[nVer-1]);

    // When query:
    res = get(ver[t], 1, n, u, v);
    */
    return 0;
}
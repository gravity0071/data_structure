 //
// Created by Shawn Wan on 2022/8/1.
//
/*

#include <iostream>
using namespace std;
#define MAX_NUM 10000
int root = 1;
int arr[MAX_NUM + 5];

int getLeft(int n){return n << 1;}
int getRight(int n){return n << 1 | 1;}

struct segmentTree{
    int sum;
} tree[(MAX_NUM << 2) + 5];

void UP(int ind){
    tree[ind].sum = tree[getLeft(ind)].sum + tree[getRight(ind)].sum;
    return;
}
 /*
  * ind: ind'th node of the tree
  * l,r : the left side and the right side of the segmentation node
  * build segment tree
  */
/*
 void build(int ind, int l, int r){
     if(l == r) {
         tree[ind].sum = arr[l];
         return;
     }
     int mid = (l + r) >> 1;
     build(getLeft(ind), l, mid);
     build(getRight(ind), mid + 1, r);
     UP(ind);
     return;
 }

/*
 * ind: ind'th node of the tree
 * x, y: chang the x node value to y
 * modify one node of the segment tree
 */
/*
 void modify(int ind, int x, int y, int l, int r){
     if(l == r){
         tree[ind].sum = y;
         return;
     }
     int mid = (l + r) >> 1;
     if(x <= mid) modify(getLeft(ind), x, y, l, mid);
     else modify(getRight(ind), x, y, mid + 1, r);
     UP(ind);
     return;
 }

/*
 * find the sum from x to y in the arr
 */
/*
 int query(int ind, int x, int y, int l, int r){
     int que = 0;
     if(x <= l && r <= y) return tree[ind].sum;
     int mid = (l + r) >> 1;
     if(x <= mid) que += query(getLeft(ind), x, y, l, mid);
     if(y > mid) que += query(getRight(ind), x, y, mid + 1, r);
     return que;
 }

 int main(){
     int n, m;
     cin >> n >> m;
     for (int i = 1; i <= n; i++) cin >> arr[i];
     build(root, 1, n);
     for (int i = 0; i < m; i++) {
         int a, b, c;
         cin >> a >> b >> c;
         if (a == 1) modify(root, b, c, 1, n);
         else  cout << query(root, b, c, 1, n) << endl;
     }
 }
*/

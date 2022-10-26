//
// Created by Shawn Wan on 2022/6/19.
// check the nearest small one on both side, using monoStack to achieve the func
/*
#include <iostream>
#include<stack>
using namespace std;

#define MAX_N 1000
int arr[MAX_N];
int l[MAX_N], r[MAX_N];

int main() {
    stack<int> q;
    int n;
    cin >> n;
    arr[0] = arr[n + 1] = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    q.push(0);
    for(int i = 1; i <= n; i++){
        while (arr[i] <= arr[q.top()]) q.pop();
        l[i] = i - q.top();
        q.push(i);
    }
    while(!q.empty()) q.pop();
    q.push(n+1);
    for(int i = n; i >= 1; i --){
        while(arr[i] <= arr[q.top()]) q.pop();
        r[i] = q.top() - i;
        q.push(i);
    }
    int ans = 0;
    for(int i = 1; i < n + 1; i ++){
        ans  = max(ans, arr[i] * (l[i] + r[i] - 1));
    }
    cout << ans<< endl;
    return 0;
}
*/
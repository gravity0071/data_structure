//
// Created by Shawn Wan on 2022/6/19.
//
/*
#include<iostream>
#include<algorithm>
#define MAX_OP 30000
int q[MAX_OP + 5], head, tail;
long long arr[MAX_OP + 5], ans;

using namespace std;

void monotonousQueue(){
    int n, m;
    arr[0] = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    head = 0, tail = 0;
    q[tail++] = 0;
    ans = arr[1];
    for(int i = 1; i <= n; i++){
        ans = max(ans, arr[i] - arr[q[head]]);
        while((head - tail) && arr[i] <= arr[q[tail - 1]]) //add the new data to the q arr, to get the increasing list
            tail --;
        q[tail ++ ] = i;
        if(q[head] == (i - m)) head++;
    }
    cout << ans << endl;
    return;
}
*/
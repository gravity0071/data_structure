//
// Created by Shawn Wan on 2022/7/5.
//


/*
#include<iostream>
#include<time.h>
using namespace std;


//normal search
int binary_search1(int * arr, int n, int x){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(arr[mid] == x) return mid;
        else if(arr[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

//11111110000 the last place of 1
int binary_search2(int * arr, int n){
    int l = -1, r = n - 1, mid;
    while(l < r){
        mid = (l + r + 1) >> 1;
        if(arr[mid] == 1) l = mid;
        else r = mid - 1;
    }
    return l;
}

//000000111 the first place of 1
int binary_search3(int * arr, int n){
    int l = 0, r = n, mid;
    while (l < r){
        mid = (r + l) >> 1;
        if(arr[mid] == 1) r = mid;
        else l = mid + 1;
    }
    return (mid == n) ? -1 : r;
}

int main(){
    int arr[10] = {1, 3,5 , 5, 6, 7, 10, 23, 35, 44};
    cout << binary_search1(arr, 10, 23) << endl;

    int arr1[10] = {1,1,1,1,1,0,0,0,0,0};
    cout<< binary_search2(arr1, 10) << endl;

    int arr3[10] = {0,0,0,0,0,1,1,1,1,1};
    cout<< binary_search3(arr3, 10) << endl;
}


 */
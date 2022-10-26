//
// Created by Shawn Wan on 2022/7/2.
//

#include<iostream>
#include<time.h>
#define MAX_OP 20
using namespace std;

void outputArr(int * arr, int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

}

void swap(int & a, int & b){
    int c = a;
    a = b;
    b = c;
}

void insert_sort(int * arr, int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0 && arr[j] < arr[j-1]; j--){
            swap(arr[j], arr[j - 1]);
        }
    }
}

void bubble_sort(int * arr, int n){
    int times = 1;
    for(int i = 1; i < n && times; i++) {
        times = 0;
        for(int j = 0; j < n - i; j++){
            if(arr[j + 1] < arr[j]){
                swap(arr[j], arr[j+1]);
                times++;
            }
        }
    }
}

void merge_sort(int * arr, int l, int r){
    int n = r - l;
    if(n <= 1){
        if(n == 1 && arr[l] > arr[r]) {
            swap(arr[l], arr[r]);
        }
        return;
    }
    int mid = (r + l) >> 1;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    int lp = l, rp = mid + 1;
    int * temp = (int * ) malloc(sizeof(int) * (r - l + 1));
    int tempp = 0;
    while(lp <= mid || rp <= r){
        if((lp <= mid && arr[lp] < arr[rp]) || !(rp <=r)){
            temp[tempp] = arr[lp++];
            tempp++;
        }
        else{
            temp[tempp] = arr[rp++];
            tempp++;
        }
    }
    for(int i = 0; i < (r - l + 1); i ++){
        arr[l + i] = temp[i];
    }
    free(temp);
    return;
}
/*
int main(){
    srand(time(0));
    int arr[MAX_OP];
    for(int i = 0; i < MAX_OP; i++){
        arr[i] = rand()%100;
    }
    outputArr(arr, MAX_OP);
    merge_sort(arr, 0, MAX_OP - 1);
    outputArr(arr, MAX_OP);
}

 */
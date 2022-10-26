//
// Created by Shawn Wan on 2022/7/4.
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

void select_sort(int * arr, int n){
    for(int i = 0; i < n - 1; i++){
        int ind = i;
        for(int j = i +1; j < n; j++){
            if(arr[ind] > arr[j])
                ind = j;
        }
        swap(arr[i], arr[ind]);
    }
}

void quick_sort(int * arr, int l, int r){
    if(l >= r) return;
    int lp = l, rp = r;
    int z = arr[l];
    while(lp < rp){
        while(lp < rp && z <= arr[rp]) rp--;
        if(lp < rp)  arr[lp++] = arr[rp];
        while(lp < rp && z >= arr[lp]) lp ++;
        if(lp < rp) arr[rp--] = arr[lp];
    }
    arr[lp] = z;
    quick_sort(arr, l, lp - 1);
    quick_sort(arr, lp + 1, r);
    return;
}
/*
int main(){
    srand(time(0));
    int arr[MAX_OP];
    for(int i = 0; i < MAX_OP; i ++){
        arr[i] = rand()%100;
    }
    outputArr(arr, MAX_OP);
    quick_sort(arr, 0, MAX_OP - 1);
    outputArr(arr, MAX_OP);
}

 */
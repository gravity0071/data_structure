//
// Created by Shawn Wan on 2022/6/30.
//利用堆排序对数组进行从小到达排序
//复杂度为NlogN, 先将数组初始化为大顶堆，然后利用弹出对规律，依次把最大对顶放到数组最后，最后剩一个时即排序完成
//



#include<iostream>
#include<time.h>
using namespace std;

void outputArr(int * arr, int n);

void swap(int & a, int & b){
    int c = a;
    a = b;
    b = c;
}


//n: arr size
//ind: the place start update the whole heap
void updateHeap(int * arr, int n, int ind){
    while((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[ind]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (ind == temp) break;
        swap(arr[ind], arr[temp]);
        ind = temp;
    }
}

int heap_sort(int * arr, int n){
    if(arr == NULL) return 0;
    arr -= 1;
    for(int i = n >> 1; i >= 1; i --){
        int ind = i;
        updateHeap(arr, n, ind);
    }
    outputArr(arr, n);
    for(int i = n; i > 1; i--){
        swap(arr[1], arr[i]);
        updateHeap(arr, i - 1, 1);
    }
    return 1;
}

void outputArr(int * arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    srand(time(0));
    #define MAX_OP 20
    int arr[MAX_OP];
    for(int i = 0; i < MAX_OP; i ++){
        arr[i] = rand()%100;
    }
    outputArr(arr, MAX_OP);
    heap_sort(arr, MAX_OP);
    outputArr(arr, MAX_OP);

    return 0;
}
 

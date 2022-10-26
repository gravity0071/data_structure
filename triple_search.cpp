//
// Created by Shawn Wan on 2022/7/5.
//

/*
#include<iostream>
#include<time.h>
using namespace std;


 //return the largest value of ax^2 + bx + c
int triple_search(int a, int b, int c){
    int l, r, tl = -15, tr = 15;
    l = -15;
    r = 15;
    while (tr - tl > 0){
        tl = (r - l)/3 + l;
        tr = (r - l)/3 * 2 + l;
        if((a * tl * tl + b * tl + c) > (a * tr * tr + b * tr + c)) r = tr;
        else l = tl;
    }
    return ((r - l) >> 1) + l;
}

int main(){
    cout << triple_search(-1, 4, 10)<< endl;
}
 */
//
// Created by Shawn Wan on 2022/7/21.
//
/*
#include <iostream>
#include <string>
using namespace std;

int kmp(char * s, char * t){
    int slen = strlen(s);
    int tlen = strlen(t);
    int * next = (int *)malloc(sizeof(int) * tlen);
    next[0] = -1;

    for(int i = 1, j = -1; i < tlen; i++){
        while(j != -1 && t[i] != t[j + 1]) j = next[j];
        if(t[j + 1] == t[i]) j += 1;
        next[i] = j;
    }

    for(int i = 0, j = -1; s[i]; i++){
        while(j != -1 && t[j + 1] != s[i]) j = next[j];
        if(s[i] == t[j + 1]) j+=1;
        if(t[j + 1] == 0) return i - tlen + 1;
    }
    return -1;
}

int sunday(char * s, char * t){
    int slen = strlen(s);
    int tlen = strlen(t);
    int ind[128] = {0};
    for(int i = 0; i < 128; i++){
        ind[i] = tlen + 1;
    }
    for(int i = 0; i < tlen; i++){
        ind[t[i]] = tlen - i;
    }
    for(int i = 0; i < slen - tlen + 1;){
        int flag = 1;
        for(int j = 0; j < tlen; j++){
            if(t[j] == s[i + j]) continue;
            i += ind[s[i + tlen]];
            flag = 0;
            break;
        }
        if(flag) return i;
    }
    return -1;
}

int shiftAnd(char * s, char * t){
    int slen = strlen(s);
    int tlen = strlen(t);
    int ind[128] = {0};
    int p = 0;
    for(int i = 0; i < tlen; i++){
        ind[t[i]] |= (1 << i);
    }

    for(int i = 0; i < slen; i++){
        p = (p << 1 | 1) & ind[s[i]];
        if(p & (1 << tlen - 1)) return i - tlen + 1;
    }
    return -1;
}

int main() {
    int i= 0;
    int next[5];
    char s1[] = "helloworldhello";
    char s2[] = "world";
    cout << "kmp: " << kmp(s1, s2) << endl;
    cout << "sun: " << sunday(s1, s2) << endl;
    cout << "shift: " << shiftAnd(s1, s2) << endl;
    return 0;
}
 */
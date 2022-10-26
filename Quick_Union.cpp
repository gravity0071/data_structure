//
// Created by Shawn Wan on 2022/7/28.
//

#include <iostream>
using namespace std;

typedef struct set{
    int * fa, * size;
    int n;
}set;

set * init_set(int n){
    set * s = (set *) malloc(sizeof(set));
    s->fa = (int * ) malloc(sizeof(int) * (n + 1));
    s->size = (int * ) malloc(sizeof(int) * (n + 1));
    for(int i = 1; i <= n; i++){
        s->size[i] = 1;
        s->fa[i] = i;
    }
    s->n = n + 1;
    return s;
}

int find(set * s, int x){
    if(s->fa[x] == x) return x;
    return s->fa[x] = find(s, s->fa[x]);
}

int merge(set * s, int a, int b){
    int fa = find(s, a);
    int fb = find(s, b);
    if(fa == fb) return 0;
    if(s->size[fa] > s->size[fb]) swap(fa, fb);
    s->size[fb] += s->size[fa];
    s->fa[fa] = fb;
    return 1;
}

void clear_set(set * s){
    if(s == NULL) return;
    free(s->fa);
    free(s->size);
    free(s);
    return;
}
/*
int main(){
    // weighted Quick-Union algorithm
    // when use find()
    // the find() method will update the father node of the current node
    set * s = init_set(6);
    merge(s, 1, 2);
    cout << (find(s,1) == find(s, 3)) << endl;
    merge(s, 2, 4);
    merge(s, 4, 3);
    cout << (find(s,1) == find(s, 3)) << endl;
}


*/
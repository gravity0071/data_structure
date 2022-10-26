//
// Created by Shawn Wan on 2022/7/26.
//

#include <iostream>
#include <string>
using namespace std;

#define BASE 26
#define BASE_LETTER 'a'

typedef struct Node{
    int flag;
    Node * next[BASE];
} Node;

typedef struct DATrie{
    int * base, * check;
    int root, size;
}DATrie;

DATrie * getDATrie(int n){
    DATrie * d = (DATrie *) calloc(sizeof (DATrie), 1);
    d->root = 1;
    d->size = n;
    d->base = (int *) calloc(sizeof (int), n);
    d->check = (int *) calloc(sizeof (int), n);
    d->check[1] = 1;
    return d;
}

int convert_num(char c){
    return c - BASE_LETTER;
}

char convert_word(int num){
    return BASE_LETTER + num;
}

Node * init_node(){
    Node * p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int getBaseValue(Node * root, DATrie * d){
    int flag, base = 0;
    do{
        flag = 1;
        base ++;
        for(int i = 0; i < BASE; i++){
            if(root->next[i] == NULL) continue;
            if(d->check[base + i] == 0) continue;
            flag = 0;
            break;
        }
    }while(!flag);
    return base;
}

void buildDATrie(int ind, Node * root, DATrie * d){
    int base = d->base[ind] = getBaseValue(root, d); //上面的方程只考虑了子节点是否有位置，所以父节点的位置已经定下来了，为ind位置
    for(int i = 0; i < BASE; i++){
        if(root->next[i] == NULL) continue;
        d->check[base + i] = ind;
    }
    for(int i = 0; i < BASE; i++){
        if(root->next[i] == NULL) continue;
        buildDATrie(base + i, root->next[i], d);
    }
    if(root->flag) d->check[ind] = -d->check[ind];
    return;
}

int DATrie_search(DATrie * d, char * c){
    int p = d->root;
    for(int i = 0; c[i]; i++){
        int ind = convert_num(c[i]);
        if(abs(d->check[d->base[p] + ind]) != p) return 0;
        p = d->base[p] + ind;
    }
    return d->check[p] < 0;
}

void insert(Node * root, char * ch){
    int len = strlen(ch);
    for(int i = 0; i < len; i++){
        if(root->next[convert_num(ch[i])] == NULL) {
            root->next[convert_num(ch[i])] = init_node();
        }
        root = root->next[convert_num(ch[i])];
    }
    root->flag = 1;
    return;
}

int search(Node * root, char * ch){
    for(int i = 0; i < strlen(ch); i++){
        if(root->next[convert_num(ch[i])] == NULL) return 0;
        root = root->next[convert_num(ch[i])];
    }
    if(root->flag) return 1;
    return 0;
}

void print_data(Node * node, int k, char * buff){
    if(node == NULL) return;
    if(node->flag == 1) cout << buff << endl;
    buff[k + 1] = '\0';
    for(int i = 0; i < BASE; i++){
        buff[k] = convert_word(i);
        print_data(node->next[i], k + 1, buff);
    }
    return;
}

void free_node(Node * node){
    if(node == NULL) return;
    for(int i = 0; i < BASE; i++){
        free_node(node->next[i]);
    }
    free(node);
    return;
}

void free_DATrie(DATrie * d){
    if(d == NULL) return;
    free(d->base);
    free(d->check);
    free(d);
    return;
}

/*
int main() {
    Node *root = init_node();
    root->flag = 0;

    insert(root, "hello");
    insert(root, "a");
    insert(root, "world");
    insert(root, "wor");
    insert(root, "hel");
    insert(root, "niho");
    cout << search(root, "hello") << endl;
    cout << search(root, "a") << endl;
    cout << search(root, "world") << endl;
    cout << search(root, "wo") << endl;
    cout << search(root, "hel") << endl;
    cout << search(root, "nhao") << endl;

    cout << endl;
    DATrie *d = getDATrie(5 * BASE + 5);
    buildDATrie(d->root, root, d);
    cout << DATrie_search(d, "hello") << endl;
    cout << DATrie_search(d, "a") << endl;
    cout << DATrie_search(d, "world") << endl;
    cout << DATrie_search(d, "wo") << endl;
    cout << DATrie_search(d, "hel") << endl;
    cout << DATrie_search(d, "nhao") << endl;
    cout << endl;
}

 */
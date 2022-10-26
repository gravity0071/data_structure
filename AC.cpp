//
// Created by Shawn Wan on 2022/7/27.
//
/*
#include <iostream>
#include <queue>
using namespace std;

#define BASE 26
#define BASE_LETTER 'a'

typedef struct Node{
  int flag;
  Node * next[26], * fail;
}Node;

Node * getNewNode(){
    return (Node * ) calloc(sizeof(Node), 1);
}

void insert(Node * root, char * str){
    for(int i = 0; str[i]; i++){
        if(root->next[str[i] - BASE_LETTER] == NULL) root->next[str[i] - BASE_LETTER] = getNewNode();
        root = root->next[str[i] - BASE_LETTER];
    }
    root -> flag = 1;
}

void build_ac(Node * root){
    queue<Node *>q;
    root->fail = NULL;
    q.push(root);
    while(!q.empty()){
        Node * now_node = q.front();
        q.pop();
        for(int i = 0; i < BASE; i++){
            if(now_node->next[i] == NULL) continue;
            Node * p = now_node->fail;
            while(p && p->next[i] == NULL) p = p->fail;
            if(p == NULL) now_node->next[i]->fail = root;
            else now_node->next[i]->fail = p->next[i];
            q.push(now_node->next[i]);
        }
    }
    return;
}

int match(Node * root, char * str){
    int cnt = 0;
    Node * p = root;
    for(int i = 0; str[i]; i++){
        while(p && p->next[str[i]- BASE_LETTER] == NULL) p = p->fail;
        if(p == NULL) p = root;
        else p = p->next[str[i] - BASE_LETTER];
        Node * q = p;
        while(q) cnt += q->flag, q = q->fail;
    }
    return cnt;
}

void clearNode(Node * root){
    if(root == NULL) return;
    for(int i = 0; i < BASE; i++){
        clearNode(root->next[i]);
    }
    free(root);
    return;
}
int main(){
    Node * root = getNewNode();
    root->flag = 0;

    insert(root, "hello");
    insert(root, "a");
    insert(root, "world");
    insert(root, "wor");
    insert(root, "hel");
    insert(root, "niho");
    build_ac(root);
    char * c = "hello worl a niho";
    cout << match(root, c);
    return 0;
}
 */
//
// Created by Shawn Wan on 2022/7/22.
//
/*
#include <iostream>
#include <string>
using namespace std;

#define BASE 26
#define BASE_LETTER 'a'

typedef struct Node{
    int flag;
    Node * next[BASE];
} Node;

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

void free_node(Node * node){
    if(node == NULL) return;
    for(int i = 0; i < BASE; i++){
        free_node(node->next[i]);
    }
    free(node);
    return;
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

int main(){
    Node * root = init_node();
    root->flag = 0;
    insert(root, "hello");
    insert(root, "a");
    insert(root, "world");
    insert(root, "wor");
    insert(root, "hel");
    insert(root, "niho");
    cout << search(root,"hello") << endl;
    cout << search(root,"a") << endl;
    cout << search(root,"world") << endl;
    cout << search(root,"wo") << endl;
    cout << search(root,"hel") << endl;
    cout << search(root,"nhao") << endl;

    cout << endl;
    char buff[100] = {0};
    print_data(root, 0, buff);
    free_node(root);
}
 */
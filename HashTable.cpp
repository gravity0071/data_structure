//
// Created by Shawn Wan on 2022/7/20.
//
/*

#include<iostream>
#include<string>
using namespace std;

typedef struct Node{
    char * data;
    struct Node * next;
}Node;

typedef struct HashTable{
    Node ** data;
    int size;
}HashTable;

Node * init_Node(char * c, Node * head){
    Node * p = (Node  *)malloc(sizeof(Node));
    p->data = c;
    p->next = head;
    return p;
}

HashTable * init_hashTable(int n){
    HashTable * h = (HashTable *) malloc(sizeof(HashTable));
    h->size = n << 2;
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}

int BKDRHash(char * str){
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; ++i) {
        hash = hash * seed + str[i];
    }
    return hash & 0x7fffffff;
}

int insert(HashTable * h, char * str){
    int hash = BKDRHash(str) % h->size;
    h->data[hash] = init_Node(str, h->data[hash]);
    return 1;
}

int search(HashTable * h, char * str){
    int hash = BKDRHash(str) % h->size;
    Node * n = h->data[hash];
    while(n && strcmp(str, n->data)) n = n->next;
    return n != NULL;
}

void clearNode(Node * h){
    if(h == NULL) return;
    Node * now = h, * next;
    while(now) {
        next = now->next;
        free(h->data);
        free(h);
        now = next;
    }
    return;
}

void clear_hashTable(HashTable * h){
    if(h == NULL) return;
    for(int i = 0; i < h->size; i ++){
        clearNode(h->data[i]);
    }
    free(h->data);
    free(h);
}

int main(){
    int choice;
    HashTable * h = init_hashTable(100);
    char str[100];
    while(true){
        cout << "type choice: ";
        cin >> choice;
        switch (choice) {
            case 0:
                cout  << "insert string: ";
                cin >> str;
                if(insert(h, str))
                    cout  << "insert success" << endl;
                break;
            case 1:
                cin >> str;
                cout << search(h, str) << endl ;
                break;
            default:
                return 0;
        }
    }
}
 */
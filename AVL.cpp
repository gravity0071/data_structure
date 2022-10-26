//
// Created by Shawn Wan on 2022/8/5.
//

#include<iostream>
#include<queue>
using namespace std;

typedef struct Node{
    int key, h;
    Node * lchild, * rchild;
}Node;

Node _NIL, *NIL = &_NIL;

__attribute__((constructor))
void init_NIL(){
    NIL->key = 0;
    NIL->rchild = NIL->lchild = NIL;
    NIL->h = 0;
    return;
}

Node *getNewNode(int key){
    Node * n = (Node * ) malloc(sizeof (Node));
    n->key = key;
    n->lchild = n->rchild = NIL;
    n->h = 1;
    return n;
}

void updateHeight(Node * root){
    int h1 = root->lchild->h, h2 = root->rchild->h;
    root->h = (h1 > h2 ? h1 + 1 : h2 + 1);
    return;
}

Node * leftRotate(Node * root){
    Node * temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    return temp;
}
Node * rightRotate(Node * root){
    Node * temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    return temp;
}

Node * maintain(Node * root){
    if(abs(root->lchild->h - root->rchild->h) <= 1) return root;
    else{
        if(root->lchild->h > root->rchild->h){
            if(root->lchild->rchild->h > root->lchild->rchild->h){
                root->lchild = leftRotate(root->lchild);
            }
            root =  rightRotate(root);
        }
        else{
            if(root->rchild->lchild->h > root->rchild->lchild->h){
                root->rchild = rightRotate(root->rchild);
            }
            root = leftRotate(root);
        }
    }
    return root;
}

Node * insert(Node * root, int key){
    if(root == NIL) return getNewNode(key);
    if(root->key == key) return root;
    if(root->key < key) root->rchild = insert(root->rchild, key);
    else root->lchild = insert(root->lchild, key);
    updateHeight(root);
    return maintain(root);
}

Node * predeccessor(Node * root){
    Node * temp = root->lchild;
    while(temp->rchild != NIL){
        temp = temp->rchild;
    }
    return temp;
}

Node * erase(Node * root, int key){
    if(root == NIL) return root;
    if(root->key > key) root->lchild = erase(root->lchild, key);
    else if(root->key < key) root->rchild = erase(root->rchild, key);
    else{
        if(root->rchild == NIL || root->lchild == NIL){
            Node * temp = (root->lchild == NIL ? root->rchild : root->lchild);
            free(root);
            return temp;
        }
        else{
            Node * temp = predeccessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    updateHeight(root);
    return maintain(root);
}

void clear(Node * root){
    if(root == NIL) return;
    clear(root->rchild);
    clear(root->lchild);
    free(root);
    return;
}

void outputTree(Node * root){
    queue<Node * > q;
    q.push(root);
    while(q.front() != NIL){
        cout << q.front()->key << " ";
        q.push(q.front()->lchild);
        q.push(q.front()->rchild);
        q.pop();
    }
}
/*
int main(){
    Node * root = NIL;
    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 7);
    outputTree(root);
}
 */
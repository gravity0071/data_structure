//
// Created by Shawn Wan on 2022/8/11.
//
/*
#include<iostream>
#include<queue>
#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2
using namespace std;

typedef struct Node{
    int key, color;
    Node * lchild, * rchild;
}Node;

Node __NIL, * const NIL = &__NIL;
__attribute__((constructor))
void init_NIL(){
    NIL->key = 0;
    NIL->color = BLACK;
    NIL->lchild = NIL->rchild = NIL;
    return;
}

Node * getNewNode(int key){
    Node * p = (Node *) malloc(sizeof(Node));
    p->lchild = p->rchild = NIL;
    p->key = key;
    p->color = RED;
    return p;
}

Node * leftRotate(Node * root){
    Node * temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node * rightRotate(Node * root){
    Node * temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

int hasRedChild(Node * root){
    return (root->rchild->color == RED || root->lchild->color == RED);
}

Node * insert_maintain(Node * root){
    if(!hasRedChild(root)) return root; //如果此根结点下面节点都是黑色，则不需要调整
    //如果父节点和叔节点都是红节点，则进入以下判断中
    if(root->rchild->color == RED && root->lchild->color == RED){
        //祖父节点的两个子节点都没有红色子节点，不需要调整
        if(!hasRedChild(root->lchild) && !hasRedChild(root->rchild)) return root;
        //父节点下面一定有红色子节点，即父节点和子节点之间存在连续的两个红色节点，将祖父节点改为红色，父节点和叔节点改为黑色
        goto insert_end;
    }
    //以下为叔节点为黑色的情况
    if(root->lchild->color == RED){
        //父节点下没有红色，不需要调整
        if(!hasRedChild(root->lchild)) return root;
        //为LL或LR型，进行旋转后进行祖父节点、父节点和叔节点的颜色修改
        if(root->lchild->rchild->color == RED) root->lchild = leftRotate(root->lchild);
        root = rightRotate(root);
        goto insert_end;
    }
    //同上一个if
    if(root->rchild->color == RED){
        if(!hasRedChild(root->rchild)) return root;
        if(root->rchild->lchild->color == RED) root->rchild = rightRotate(root->rchild);
        root = leftRotate(root);
        goto insert_end;
    }
insert_end:
    root->color = RED;
    root->rchild->color = root->lchild->color = BLACK;
    return root;
}

Node * __insert(Node * root, int key){
    if(root == NIL) return getNewNode(key);
    if(root->key == key) return root;
    if(root->key > key) root->lchild = __insert(root->lchild, key);
    else root->rchild = __insert(root->rchild, key);
    return insert_maintain(root);
}

//嵌套一层循环，从而将根结点改为黑色
Node * insert(Node * root, int key){
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

Node * predecessor(Node * root){
    Node * p = root->lchild;
    while(p->rchild != NIL) p = p->rchild;
    return p;
}
//画图！！！！！记住哪些节点是确定的，哪些是不确定的
Node * erase_maintain(Node * root){
    //没有含有DOUBLE BLACK的节点，所以不需要变动
    if(root->lchild->color != DOUBLE_BLACK && root->rchild->color != DOUBLE_BLACK) return root;
    //当右边的节点是双重黑的时候，进行调整
    if(root->rchild->color == DOUBLE_BLACK){
        //当叔节点为红色时，进行转换，变换后变成叔节点为黑色的情况，此时叔节点为root进行迭代
        if(root->lchild->color == RED){
            root->color = RED;
            root->lchild->color = BLACK;
            root = rightRotate(root);
            root = erase_maintain(root->rchild);
            return root;
        }
        //当叔节点没有红色子孩子时，可以不用旋转直接改变颜色就可以
        if(!hasRedChild(root->lchild)){
            root->color += 1;
            root->lchild->color -= 1;
            root->rchild->color -=1;
            return root;
        }
        //当为LR情况时，先进行小左旋，变成LL情况，再进行变换
        if(root->lchild->lchild->color != RED){
            root->lchild->color = RED;
            root->lchild->rchild->color = BLACK;
            root->lchild = leftRotate(root->lchild);
        }
        //LL情况进行变换，进行大右旋
        root->lchild->color = root->color;
        root->rchild->color -= 1;
        root = rightRotate(root);
        root->lchild->color = root->rchild->color = BLACK;
        return root;
    }
    else{
        if(root->rchild->color == RED){
            root->color = RED;
            root->rchild->color = BLACK;
            root = leftRotate(root);
            root = erase_maintain(root->lchild);
            return root;
        }
        if(!hasRedChild(root->rchild)){
            root->color += 1;
            root->rchild->color -= 1;
            root->lchild->color -=1;
            return root;
        }
        if(root->rchild->rchild->color != RED){
            root->rchild->color = RED;
            root->rchild->lchild->color = BLACK;
            root->rchild = rightRotate(root->rchild);
        }
        root->rchild->color = root->color;
        root->lchild->color -= 1;
        root = leftRotate(root);
        root->rchild->color = root->lchild->color = BLACK;
        return root;
    }
}

Node * __erase(Node * root, int key){
    if(root == NIL) return root;
    if(root->key > key) root->lchild = __erase(root->lchild, key);
    else if(root->key < key) root->rchild = __erase(root->rchild, key);
    else{
        if(root->lchild == NIL || root->rchild == NIL){
            Node * temp = (root->lchild == NIL ? root->rchild : root->lchild);
            temp->color += root->color;
            free(root);
            return temp;
        }
        else{
            Node * temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}

Node * erase(Node * root, int key){
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}

queue<Node * > q;
void __output(Node * root){
    while(!q.empty()) {
        Node *node = q.front();
        if(root == NIL) continue;
        cout << node->key << " " << node->color << ", ";
        if(node->lchild != NIL)q.push(node->lchild);
        if(node->rchild != NIL)q.push(node->rchild);
        q.pop();
    }
}

void output(Node * root){
    if(root == NIL) return;
    q.push(root);
    __output(root);
    return;
}
int main(){
    Node * root = getNewNode(1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    output(root);
    root = erase(root, 7);
    cout << endl;
    output(root);
}


 */

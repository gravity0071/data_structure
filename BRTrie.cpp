//
// Created by Shawn Wan on 2022/8/11.
//

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
    if(!hasRedChild(root)) return root; //����˸��������ڵ㶼�Ǻ�ɫ������Ҫ����
    //������ڵ����ڵ㶼�Ǻ�ڵ㣬����������ж���
    if(root->rchild->color == RED && root->lchild->color == RED){
        //�游�ڵ�������ӽڵ㶼û�к�ɫ�ӽڵ㣬����Ҫ����
        if(!hasRedChild(root->lchild) && !hasRedChild(root->rchild)) return root;
        //���ڵ�����һ���к�ɫ�ӽڵ㣬�����ڵ���ӽڵ�֮�����������������ɫ�ڵ㣬���游�ڵ��Ϊ��ɫ�����ڵ����ڵ��Ϊ��ɫ
        goto insert_end;
    }
    //����Ϊ��ڵ�Ϊ��ɫ�����
    if(root->lchild->color == RED){
        //���ڵ���û�к�ɫ������Ҫ����
        if(!hasRedChild(root->lchild)) return root;
        //ΪLL��LR�ͣ�������ת������游�ڵ㡢���ڵ����ڵ����ɫ�޸�
        if(root->lchild->rchild->color == RED) root->lchild = leftRotate(root->lchild);
        root = rightRotate(root);
        goto insert_end;
    }
    //ͬ��һ��if
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

//Ƕ��һ��ѭ�����Ӷ���������Ϊ��ɫ
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
//��ͼ������������ס��Щ�ڵ���ȷ���ģ���Щ�ǲ�ȷ����
Node * erase_maintain(Node * root){
    //û�к���DOUBLE BLACK�Ľڵ㣬���Բ���Ҫ�䶯
    if(root->lchild->color != DOUBLE_BLACK && root->rchild->color != DOUBLE_BLACK) return root;
    //���ұߵĽڵ���˫�غڵ�ʱ�򣬽��е���
    if(root->rchild->color == DOUBLE_BLACK){
        //����ڵ�Ϊ��ɫʱ������ת�����任������ڵ�Ϊ��ɫ���������ʱ��ڵ�Ϊroot���е���
        if(root->lchild->color == RED){
            root->color = RED;
            root->lchild->color = BLACK;
            root = rightRotate(root);
            root = erase_maintain(root->rchild);
            return root;
        }
        //����ڵ�û�к�ɫ�Ӻ���ʱ�����Բ�����תֱ�Ӹı���ɫ�Ϳ���
        if(!hasRedChild(root->lchild)){
            root->color += 1;
            root->lchild->color -= 1;
            root->rchild->color -=1;
            return root;
        }
        //��ΪLR���ʱ���Ƚ���С���������LL������ٽ��б任
        if(root->lchild->lchild->color != RED){
            root->lchild->color = RED;
            root->lchild->rchild->color = BLACK;
            root->lchild = leftRotate(root->lchild);
        }
        //LL������б任�����д�����
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
 /*
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

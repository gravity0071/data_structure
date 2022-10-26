//
// Created by Shawn Wan on 2022/6/22.
//
/*
#include <iostream>
#include<stack>
#include <string>
using namespace std;

string outcode;

typedef struct Node{
    int nums;
    char data;
    Node * next[2];
}Node;

typedef struct HuffmanTree{
    Node * root;
    int n;
}HuffmanTree;

Node * getNewNode(char val, int nums){
    Node * n = (Node * ) malloc(sizeof (Node));
    n->data = val;
    n->nums = nums;
    n ->next[0] = n->next[1] = NULL;
    return n;
}

Node ** getNewNodeList(int n){
    Node ** nodeList = (Node **) malloc((sizeof(Node * ) * n));
    return nodeList;
}

HuffmanTree * getNewHuffmanTree(){
    HuffmanTree * huffmanTree = (HuffmanTree *) malloc(sizeof(HuffmanTree));
    huffmanTree->root = NULL;
    huffmanTree->n = 0;
    return huffmanTree;
}


 //* sort from large to small

void NodeSort(Node ** node, int n){
    for(int i = n; i > 0; i --){
        for(int j = 0; j < i - 1; j ++){
            if(node[j]->nums < node[j + 1]->nums){
                Node * temp = node[j];
                node[j] = node[j + 1];
                node[j + 1] = temp;
            }
        }
    }
}

void printNodeList(Node ** nodeList, int n){
    for(int i = 0; i < n; i ++) cout << nodeList[i]->data << " ";
    cout << endl;
    return;
}

Node * addSmallTwoNodes(Node * node1, Node * node2){
    Node * node = (Node *) malloc(sizeof(Node));
    node->nums = node1->nums + node2->nums;
    node->data = '*';
    node->next[0] = node1;
    node->next[1] = node2;
    return node;
}

HuffmanTree * buildHuffmanTree(Node ** nodeList, int n){
    HuffmanTree * huffmanTree = (HuffmanTree * ) malloc(sizeof(HuffmanTree));
    int len = n;
    for(int i = 0; i < n - 2; i++){
        Node * node = (Node *) malloc(sizeof(Node));
        node = addSmallTwoNodes(nodeList[len - 1], nodeList[len - 2]);
        len --;
        nodeList[len- 1] = node;
        NodeSort(nodeList, len);
        printNodeList(nodeList,len);
    }
    printNodeList(nodeList, len);
    huffmanTree->root = addSmallTwoNodes(nodeList[0], nodeList[1]);
    return huffmanTree;
}

void outputpNode(Node * root){
    if(root == NULL) return;
    cout << root->data << "(";
    outputpNode(root->next[0]);
    cout << " , ";
    outputpNode(root->next[1]);
    cout << ")" ;
    return;
}
void outputTree(HuffmanTree * huffmanTree){
    cout << "Tree: [";
    outputpNode( huffmanTree->root);
    cout << " ]" << endl;
    return;
}

void inorderNode(Node * node){
    if(node->next[0] == NULL && node->next[1] == NULL) {
        cout << node->data << ": " << outcode << endl;
        return;
    }
    outcode.push_back('0');
    inorderNode(node->next[0]);
    outcode.pop_back();
    cout << node->data;
    cout << ", ";
    outcode.push_back('1');
    inorderNode(node->next[1]);
    outcode.pop_back();
    return;
}

void inorder(HuffmanTree * tree){
    cout << "out code: " << endl;
    inorderNode(tree->root);
    cout << endl;
    return;
}

int main(){
    int n;
    cin >> n;
    Node * nodeList[n];
    for(int i = 0; i < n; i ++){
        char val;
        int nums;
        cin >> val >> nums;
        nodeList[i] = getNewNode(val, nums);
    }

    NodeSort(nodeList, n); //sort the nodeList from small to large
    HuffmanTree * huffmanTree = (HuffmanTree * ) malloc(sizeof(HuffmanTree));
    huffmanTree = buildHuffmanTree(nodeList, n);
    outputTree(huffmanTree);
    inorder(huffmanTree);
}
*/
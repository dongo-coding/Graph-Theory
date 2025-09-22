#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* fChild = NULL;
    TreeNode* nSib = NULL;
};

TreeNode* newNode(char x){
    TreeNode* q = new TreeNode();
    q->data = x;
    return q;
}


void addChild(TreeNode* parent, TreeNode* child){
    if(parent->fChild == NULL) parent->fChild = child;
    else {
        TreeNode* cur = parent->fChild;
        while(cur->nSib) cur = cur->nSib;
        cur->nSib = child;
    }
}


void preOrder(TreeNode* p){
    if(!p) return;
    cout << p->data << " ";
    for(TreeNode* q = p->fChild; q; q = q->nSib)
        preOrder(q);
}


void inOrder(TreeNode* p){
    if(!p) return;
    TreeNode* q = p->fChild;
    if(q) inOrder(q);  
    cout << p->data << " ";
    if(q){
        q = q->nSib;
        while(q){
            inOrder(q);
            q = q->nSib;
        }
    }
}


void postOrder(TreeNode* p){
    if(!p) return;
    for(TreeNode* q = p->fChild; q; q = q->nSib)
        postOrder(q);
    cout << p->data << " ";
}

int main(){
    int n;
    cout << "Nhap so cap (cha-con): ";
    cin >> n;

    map<char, TreeNode*> nodes;
    set<char> children;
    char parent, child;

    for(int i=0; i<n; i++){
        cin >> parent >> child;
        if(nodes.find(parent) == nodes.end()) nodes[parent] = newNode(parent);
        if(nodes.find(child) == nodes.end()) nodes[child] = newNode(child);
        addChild(nodes[parent], nodes[child]);
        children.insert(child);
    }

    
    TreeNode* root = NULL;
    for(auto &p : nodes){
        if(children.find(p.first) == children.end()){
            root = p.second;
            break;
        }
    }

    cout << "\n========= PREORDER =========\n";
    preOrder(root);
    cout << "\n========= INORDER =========\n";
    inOrder(root);
    cout << "\n========= POSTORDER =========\n";
    postOrder(root);
    cout << endl;
    return 0;
}

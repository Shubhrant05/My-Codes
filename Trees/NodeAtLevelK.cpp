#include<iostream>
#include<queue>
#include"treeNodeClass.h"
using namespace std;

treeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter the data of the root: ";
    cin>>rootData;

    treeNode<int>* root = new treeNode<int>(rootData);

    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        treeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the number of childs of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i = 0 ; i < numChild ; i++){
            int childData;
            cout<<"Enter the "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            treeNode<int>* child = new treeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void nodeAtLevelK(treeNode<int>* root , int k){
    if(root == NULL)//edge case
    return;
    if(k == 0){//base case
    cout<<root->data<<endl;
    return;
    }

    for(int i = 0 ; i < root->children.size() ; i++){
        nodeAtLevelK(root->children[i] , k-1);
    }
}

int main() {
    treeNode<int>* root = takeInputLevelWise();
    int k ;
    cout<<"Enter the level : ";
    cin>>k;
    nodeAtLevelK(root , k);
}
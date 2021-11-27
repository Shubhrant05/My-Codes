#include<iostream>
#include"treeNodeClass.h"
#include<queue>
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
void printTree(treeNode<int>* root){
    if(root == NULL){ //This is an edge case not a basecase.
        return;
    }

    cout<<root->data<<":";
    for(int i = 0 ; i < root->children.size() ; i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i = 0 ; i < root->children.size() ; i++){
        printTree(root->children[i]);
    }

}

int main(){
//    treeNode<int>* root = new treeNode<int>(1); 
//    treeNode<int>* node1 = new treeNode<int>(2); 
//    treeNode<int>* node2 = new treeNode<int>(3); 

//    root->children.push_back(node1);
//    root->children.push_back(node2);
treeNode<int>* root = takeInputLevelWise();
   printTree(root);
   return 0;
}
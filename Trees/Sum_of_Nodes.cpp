#include<iostream>
#include<queue>
#include"treeNodeClass.h"
using namespace std;

void printLevelWise(treeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return;
    }
    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        treeNode<int>* front = pendingNodes.front();
        cout<<front->data<<":";
     	pendingNodes.pop();
        if(front->children.size() != 0){
        for(int i = 0 ; i < front->children.size()-1 ; i++){
            pendingNodes.push(front->children[i]);
            cout<<front->children[i]->data<<",";
        }
        
        pendingNodes.push(front->children[front->children.size()-1]);
        cout<<front->children[front->children.size()-1]->data;
        }
        cout<<endl;
    }
}

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

int sumOfNodes(treeNode<int>* root) {
    // Write your code here
    int sum = root->data;
    for(int i = 0 ; i < root->children.size() ; i++){
        sum = sum + sumOfNodes(root->children[i]);
    }
    return sum ;
}

int main(){
    treeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout<<"Sum of nodes in tree is "<<sumOfNodes(root)<<endl;
    return 0 ;
}
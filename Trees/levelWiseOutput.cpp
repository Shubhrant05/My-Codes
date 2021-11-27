#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class treeNode {
   public:
    T data;
    vector<treeNode<T>*> children;

    treeNode(T data) { this->data = data; }

    ~treeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

#include<queue>
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


int main() {
    treeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}
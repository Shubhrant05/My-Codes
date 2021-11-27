-------------------------------------------------This is a header file containing class structure of generic tree----------------------------------------------------------------
  #include<vector>
using namespace std ;

template<typename T>
class treeNode{
    public : 

    T data;
    vector<treeNode*> children;//We can write treeNode<T>* in place of treeNode* but even if we don't do that it will get the datatype defined for data by default

    treeNode(T data){
        this->data = data;
    }
};

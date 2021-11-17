      //-----------------------------------------------Following is for linked list implementation of stack----------------------------------------------------------//

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


class Stack{
    Node* head;
    int size;
    
    public:
    
    Stack(){
        this->head = NULL;
        this->size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        if(head == NULL)
        return true;
        else 
        return false;
    }

    void push(int data)
    {
        Node * newNode = new Node(data);
            if(head == NULL){
            head = newNode;
            }

            else{
            newNode->next = head;
            head = newNode; 
            }

            size++;
    }

    int pop(){

        if(!isEmpty())
        {
            int ans = head->data;
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            
            return ans;

        }
        else
        {
            return -1;
        }
    }

    int top(){
        if(!isEmpty())
        return head->data;
        else
        return -1;
    }
};


int main(){
    Stack *s = new Stack();
    s->push(17);
    s->push(23);
    s->push(11);
    cout<<s->pop()<<endl;
    cout<<s->pop()<<endl;
    cout<<s->pop()<<endl;
    cout<<s->pop()<<endl;



    return 0;
}

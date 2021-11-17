   //---------------------------------------------------THE FOLLOWING CODE IS FOR IMPLEMENTING STACKS USING ARRAY-----------------------------------------------------//

#include<iostream>
using namespace std;

class Stack{
 int *arr;
 int top;
 int capacity;

 public:
 Stack(int s){
    arr = new int[s];
    top = 0;
    capacity = s;
 }

 int size(){
     return top;
 }

  bool isEmpty(){
     if(top == 0)
     return true;
     else
     return false;
 }

 void push(int data){
     if(capacity != top){
     arr[top] = data;
     top++;
     }
     else
     cout<<"Stack Overflow!!"<<endl;
 }

 int pop(){
     if(!isEmpty()){
     top = top-1;
     return arr[top];
     }
     else
     cout<<"Stack Underflow!!"<<endl;
     return INT64_MIN;
 }

 int top_ele(){
     if(!isEmpty())
     return arr[top-1];
     else
     return INT64_MIN;
 }

};

int main(){
    Stack *s = new Stack(5);
    s->push(10);
    s->push(20);
    s->push(30);
    s->push(40);
   
    cout<<s->top_ele()<<endl;
    cout<<s->pop()<<endl;
    cout<<s->isEmpty()<<endl;
    cout<<s->size()<<endl;

    return 0;
}

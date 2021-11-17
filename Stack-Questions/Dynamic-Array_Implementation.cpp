           //-------------------------------------Following is implementaion of Stacks using dynamic arrays to avoid overflow-------------------------------//

#include<iostream>
#include<climits>
using namespace std;

class Stack{
 int *arr;
 int top;
 int capacity;

 public:
 //Since we are dynamicvally creating our array so now we don't need any input in our constructor also we have to give capacity a value from our side.
 
 Stack(){
    arr = new int[4];
    top = 0;
    capacity = 4;
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
          //Here we are just creating a new array with the capacity equal to twice of the previous one and we are dealllocating the previous array and putting values in new array and updating the cpacity
     if(capacity == top){
        int *newArr = new int[2 *capacity];
         for(int i = 0 ; i < capacity; i++){
             newArr[i] = arr[i];
         }
         delete [] arr;
         arr = newArr;
         arr[top] = data;
         capacity = capacity * 2;
     }

     arr[top] = data;
     top++;
 }

 int pop(){
     if(!isEmpty()){
     top = top-1;
     return arr[top];
     }
     else
     cout<<"Stack Underflow!!"<<endl;
     return INT_MIN;
 }

 int top_ele(){
     if(!isEmpty())
     return arr[top-1];
     else
     return INT_MIN;
 }

};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.top_ele()<<endl;
    cout<<s.size()<<endl;
    s.push(50);
    s.push(60);
    s.push(70);
    cout<<s.top_ele()<<endl;
    cout<<s.size()<<endl;

    return 0;
}

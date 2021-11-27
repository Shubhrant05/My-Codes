---------------------------------------------------Following  File contains array implementation of Queue--------------------------------------------------------------------


#include<iostream>
#include<climits>
using namespace std;

class Queue{
    int * arr;
    int front , rear , capacity;
    public:
    
    Queue(int s){
        arr = new int[s];
        front = 0 ;
        rear = 0;
        capacity = s;
    }
    int size(){
        if(rear >= front)
        return rear - front;
        else
        return 0;
    }

    bool isEmpty(){
        if(rear <= front){
            return true;
        }
        else
        return false;
    }

    void enqueue(int x){
        if(rear == capacity){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear] = x;
            rear++;
        }
    }

    int dequeue(){
        if(!isEmpty()){
            int temp = arr[front];
            front++;
            return temp;
        }
        else{
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
    }

    int front_ele(){
        if(!isEmpty())
        return arr[front];
        else{
        cout<<"Queue is Empty"<<endl;
        return INT_MIN;
        }
    }
};

int main(){
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.size()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.front_ele()<<endl;
    return 0;
}

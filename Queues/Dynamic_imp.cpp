#include<iostream>
#include<climits>
using namespace std;

class Queue{
    int * arr;
    int front , rear , capacity;
    public:
    
    Queue(){
        arr = new int[5];
        front = 0 ;
        rear = 0;
        capacity = 5;
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
            int *newArr = new int[capacity * 2];
            for(int i = 0 ; i < capacity ; i++){
                newArr[i] = arr[i];
            }
            delete [] arr;
            arr = newArr;
            capacity = capacity*2;
        }
            arr[rear] = x;
            rear++;
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
    Queue q;
    int m , n;
    cout<<"Enter the number of elements you want in queue : ";
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        q.enqueue(i*i);
    }
    cout<<"Enter the number of elements you want to dequeue : ";
    cin>>m;

    for(int i = 0 ; i < m ; i++){
        cout<<q.dequeue()<<endl;
    }
    cout<<"Size = "<<q.size()<<endl;
    cout<<"Front element = "<<q.front_ele()<<endl;
    cout<<"Is queue empty = ";
    if(q.isEmpty() == true)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;

    return 0;
}
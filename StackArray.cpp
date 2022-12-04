#include <iostream>
using namespace std;

//Array implementation
class ArrayStack{
private:
    int* items;
    int capacity; //pojemnosc stosu
    int top;
public:
    ArrayStack(int c);
    bool empty();
    bool full();
    void push(int x);
    int peek();
    void pop();
    void clear();
    friend ostream& operator<<(ostream& out, ArrayStack& s);
    ~ArrayStack();
};

ArrayStack::ArrayStack(int c){
    top=-1;
    capacity=c;
    items=new int[c];
}
ArrayStack::~ArrayStack(){

}
bool ArrayStack::empty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

bool ArrayStack::full(){
    if(capacity==top+1){
        return true;
    }
    else{
        return false;
    }
}

void ArrayStack::push(int x){
    if(full()){
        cout<<"stack full"<<endl;
    }
    else{
        top++;
        items[top]=x;
    }
}

int ArrayStack::peek(){
    if(empty()){
        cout<<"stack empty error:";
        return 420;

    }else{
        return items[top];
    }
}

void ArrayStack::pop(){
    if(empty()){
        cout<<"stack empty"<<endl;
    }
    else{
        top--;
    }
}

void ArrayStack::clear(){
    if(empty()){
        cout<<"stack empty"<<endl;
    }
    else{
        top=-1;
    }
}

ostream& operator<<(ostream& out, ArrayStack& s){

    if(s.empty()){
        cout<<"stack empty"<<endl;
    }
    else{
        for(int i=0; i<s.top+1; i++){
            out<<s.items[i]<<endl;
        }
    }
}

int main()
{
    //Example
    ArrayStack s(3);
    cout<<"Peek: ";
    cout<<s.peek()<<endl;

    s.push(1);
    cout<<"Peek: ";
    cout<<s.peek()<<endl;

    s.push(2);
    cout<<"Peek: ";
    cout<<s.peek()<<endl;

    s.push(3);
    cout<<"Peek: ";
    cout<<s.peek()<<endl;

    s.push(4);

    cout<< s;

    cout<<"Peek: ";
    cout<<s.peek()<<endl;

    s.pop();
    cout<<"Peek: ";
    cout<<s.peek()<<endl;

    cout<< s;

    s.pop();
    cout<<"Peek: ";
    cout<<s.peek()<<endl;

    s.pop() ;
    cout<<"Peek: ";
    cout<<s.peek()<<endl;

    cout<< s;
    cout<<endl<<endl<<endl;
}

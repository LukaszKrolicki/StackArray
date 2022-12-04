#include <iostream>
using namespace std;

class StackArray{

private:
    int capacity;
    int top;
    int* items;
public:
    StackArray(int c);
    bool empty();
    bool full();
    void enque(int x);
    void pop();
    int peek();
    void clear();

    friend ostream& operator<<(ostream& out, StackArray& a);
    ~StackArray();
};

StackArray::StackArray(int c)
{
    capacity=c;
    top=-1;
    items=new int[c];
}

StackArray::~StackArray(){
    clear();
}
bool StackArray::empty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

bool StackArray::full(){
    if(top+1==capacity){
        return true;
    }
    else{
        return false;
    }
}

void StackArray::enque(int x){
    top++;
    items[top]=x;
}
int StackArray::peek(){
    return items[top];
}
void StackArray::pop(){
    top--;
}
void StackArray::clear(){
    top=-1;
}

ostream& operator<<(ostream& out, StackArray& a){
    for(int i=0; i<=a.top; i++){
        out<<a.items[i]<<" ";
    }
}

int main(){
    //exmaple
    StackArray a(5);
    a.enque(1);
    a.enque(2);
    a.enque(3);
    a.enque(4);
    a.enque(5);
    a.pop();
    a.pop();
    cout<<a.peek()<<endl;
    cout<<a;
}

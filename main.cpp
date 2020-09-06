#include <iostream>
using namespace std;


class stack
{
private:
    int* mas;
    int _top;

public:

    int* resize(const int *mas, unsigned size, unsigned new_size)
    {
        int* n = new int[new_size];
        for (unsigned i = 0; i < ((size > new_size)?new_size:size); ++i) n[i] = mas[i];
        delete[] mas;
        
        return n;
    }

    stack()
    {
        mas = new int[0];
        _top = -1;
    }
    stack(int a)
    {
        mas = new int[1];
        _top = 0;
        mas[_top] = a;
    }
    int top() 
    { 
        if(!(*this).isEmpty())
        return mas[_top]; 
        else 
        return 0;
    }

    bool isEmpty() {if (_top == -1) return true; else return false;}
    void push(int a)
    {
        mas = resize(mas, _top+1, _top+2);
        _top++;
        mas[_top] = a;
    }
    bool pop()
    {
        if ((*this).isEmpty()) return false;
        mas = resize(mas, _top+1, _top);
        _top--;
        return true;
    } 
    ~stack();
};

class queue
{
private:
    int* mas;
    int size;

public:

    int* enresize(const int *mas)
    {
        int* n = new int[size+1];
        for (unsigned i = 0; i < size; ++i) n[i] = mas[i];
        delete[] mas;
        
        return n;
    }
    int* deresize(const int *mas)
    {
        int* n = new int[size-1];
        for (unsigned i = 0; i < size-1; ++i) n[i] = mas[i+1];
        delete[] mas;
        
        return n;
    }

    queue()
    {
        mas = new int[0];
        size = 0;
    }
    queue(int a)
    {
        mas = new int[1];
        size = 1;
        mas[0] = a;
    }
    bool isEmpty() {if (size == 0) return true; else return false;}
    
    void enqueue(int a)
    {
        mas = enresize(mas);
        size++;
        mas[size-1] = a;
    }
    bool dequeue()
    {
        if (this->isEmpty()) return false;
        mas = deresize(mas);
        size--;
        return true;
    }
    int pic() {return mas[0];}

    ~queue();
};

int main()
{
    /*stack myStack(3);
    int tmp = 0;
    char sign;
    while(true)
    {
        cin >> sign;
        if(sign == '+')
        {
            cin >> tmp;
            myStack.push(tmp);
        }
        else if (sign == '-')
        {
            if(myStack.pop()) cout << "OK" << endl;
            else cout << "STACK IS EN+MPTY" << endl;
        }
        else if (sign == '=')
        {
            cout << myStack.top() << endl;
        }
    }*/

    queue myQueue;

    int tmp;
    char sign;
    while (true)
    {
        cin >> sign;
        if(sign == '+')
        {
            cin >> tmp;
            myQueue.enqueue(tmp);
        }
        else if (sign == '-')
        {
            if(myQueue.dequeue()) cout << "OK" << endl;
            else cout << "QUEUE IS EMPTY" << endl;
        }
        else if (sign == '=')
        {
            cout << myQueue.pic() << endl;
        }
    }

    return 0;
}
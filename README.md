# Stack-Queue
Trying to replicate STL

### Stack

```c++
stack::stack();       //creates empty stack
stack::stack(int a);  //creates stack with element a

bool stack::isEmpty();    //state of stack
int  stack::top();        //returns top element
void stack::push(int a);  //places a on a stack top
bool stack::pop();        //removes top element
                          //returns true if element was removed
```

### Queue

```c++
queue::queue();        //creates empty queue
queue::queue(int a);   //creates queue with element a

bool queue::isEmpty();       //state of queue
void queue::enqueue(int a);  //places element in queue
int  queue::pic();           //returns first element
bool queue::enqueue();       //removes first element from queue
                             //returns true if element was removed
```


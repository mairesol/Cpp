/*
queue

FIFO queue
queues are a type of container adaptor, specifically designed to operate in a FIFO context(first-in first-out),
where elements are inserted into one end of the container and extracted from the other.

queues are implemented as containers adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container,
roviding a specific set of member functions to access its elements. Elements are pushed into the "back" of the specific container and popped from its "front".

The underlying container may be one of the standard container class template or some other specifically designed container class.
This underlying container shall support at least the following operations:
empty
size
front
back
push_back
pop_front

The standard container classes deque and list fulfill these requirements. By default, if no container class is specified for a particular queue class instantiation, the standard container deque is used.
*/

/*
Member types:
value_type:	The first template parameter(T)

container_type:	The second template parameter(Container)

reference:	container_type::reference

const_reference:	container_type::const_reference

size_type:	an unsigned integral type
*/
#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    /*
    constructor:
    initialize:                 explicit queue(const container_type& ctnr);
    move-initialize:            explicit queue(container_type&& ctnr = container_type());
    allocator:                  template <class Alloc> explicit queue(const Alloc& alloc);
    init + allocator:           template <class Alloc> queue(const container_type& ctnr, const Alloc& alloc);
    move-init + allocator:      template <class Alloc> queue(container_type&& ctnr, const Alloc& alloc);
    copy + allocator:           template <class Alloc> queue(const queue& x, const Alloc& alloc);
    move + allocator:           template <class Alloc> queue(queue&& x, const Alloc& alloc);
    */
    deque<int> mydeck(3, 100); // deque with 3 elements
    list<int> mylist(2, 200);  // list with 2 elements

    queue<int> first;          // empty queue
    queue<int> second(mydeck); // queue initialized to copy of deque

    queue<int, list<int>> third; // empty queue with list as underlying container
    queue<int, list<int>> fourth(mylist);

    cout << "size of first: " << first.size() << '\n';
    cout << "size of second: " << second.size() << '\n';
    cout << "size of third: " << third.size() << '\n';
    cout << "size of fourth: " << fourth.size() << '\n';
    // size of first: 0
    // size of second: 3
    // size of third: 0
    // size of fourth: 2

    // empty       Test whether container is empty:    bool empty() const;
    queue<int> myqueue;
    int sum(0);
    for (int i = 1; i <= 10; i++)
        myqueue.push(i);
    while (!myqueue.empty())
    {
        sum += myqueue.front();
        myqueue.pop();
    }
    cout << "total: " << sum << '\n';
    // total: 55

    // size        Return size:    size_type size() const;
    queue<int> myints;
    cout << "0. size: " << myints.size() << '\n';

    for (int i = 0; i < 5; i++)
        myints.push(i);
    cout << "1. size: " << myints.size() << '\n';

    myints.pop();
    cout << "2. size: " << myints.size() << '\n';
    // 0. size: 0
    // 1. size: 5
    // 2. size: 4

    // front       Access next element:    reference& front();     const_reference& front() const;
    queue<int> myqueue;
    myqueue.push(77);
    myqueue.push(16);
    myqueue.front() -= myqueue.back(); // 77-16=61
    cout << "myqueue.front() is now " << myqueue.front() << '\n';
    // myqueue.front() is now 61

    // back        Access last element:    reference& back();      const_reference& back() const;
    queue<int> myqueue;
    myqueue.push(12);
    myqueue.push(75); // this is now the back
    myqueue.back() -= myqueue.front();
    cout << "myqueue.back() is now " << myqueue.back() << '\n';
    // myqueue.back() is now 63

    // push        Insert element:     void push(const value_type& val);    void push(value_type&& val);

    // emplace     Construct and insert element:   template <class... Args> void emplace(Args&&... args);
    queue<string> myqueue;
    myqueue.emplace("First sentence");
    myqueue.emplace("Second sentence");
    cout << "myqueue contains:\n";
    while (!myqueue.empty())
    {
        cout << myqueue.front() << '\n';
        myqueue.pop();
    }
    // myqueue contains:
    // First sentence
    // Second sentence

    // pop         Remove next element:    void pop();

    // swap        Swap contents:      void swap(queue& x) noexcept();
    queue<int> foo, bar;
    foo.push(10);
    foo.push(20);
    foo.push(30);
    bar.push(111);
    bar.push(222);

    foo.swap(bar);

    cout << "size of foo: " << foo.size() << '\n';
    cout << "size of bar: " << bar.size() << '\n';
    // size of foo: 2
    // size of bar: 3

    return 0;
}
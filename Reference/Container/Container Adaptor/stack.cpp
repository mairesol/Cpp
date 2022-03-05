/*
std::stack

LIFO stack
Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out),
where elements are inserted and extracted only from one end of the container.

stacks are implemented as container adaptors, which are classes that use an encapsulated object of a specific container class
as its underlying container, providing a specific set of member functions to access its elements.
Elements are pushed/popped from the "back" of the specific container, which is known as the top of the stack.

The underlying container may be any of the standard container class templates or
some other specifically designed container class. The container shall support the following operations:
empty
size
back
push_back
pop_back

The standard container classes vector, deque and list fulfill these requirements.
By default, if no container class is specified for a particular stack class instantiation, the standard container deque is used.
*/

/*
Member types:
value_type: The first template parameter (T)

container_type:	The second template parameter (Container)

reference:	container_type::reference

const_reference:	container_type::const_reference

size_type:	an unsigned integral type
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    constructor:
    initialize:              explicit stack (const container_type& ctnr);
    move-initialize:         explicit stack (container_type&& ctnr = container_type());
    allocator:               template <class Alloc> explicit stack (const Alloc& alloc);
    init + allocator:        template <class Alloc> stack (const container_type& ctnr, const Alloc& alloc);
    move-init + allocator:   template <class Alloc> stack (container_type&& ctnr, const Alloc& alloc);
    copy + allocator:        template <class Alloc> stack (const stack& x, const Alloc& alloc);
    move + allocator:        template <class Alloc> stack (stack&& x, const Alloc& alloc);
    */
    std::deque<int> mydeque(3, 100);   // deque with 3 elements
    std::vector<int> myvector(2, 200); // vector with 2 elements

    std::stack<int> first;           // empty stack
    std::stack<int> second(mydeque); // stack initialized to copy of deque

    std::stack<int, std::vector<int>> third; // empty stack using vector
    std::stack<int, std::vector<int>> fourth(myvector);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';
    std::cout << "size of fourth: " << fourth.size() << '\n';
    // size of first: 0
    // size of second: 3
    // size of third: 0
    // size of fourth: 2

    /*
    empty       Test whether container is empty:     bool empty() const;

    size        Return size:     size_type size() const;

    top         Access next element:     reference top();    const_reference top() const;

    push        Insert element:  void push (const value_type& val);  void push (value_type&& val);

    emplace     Construct and insert element:    template <class... Args> void emplace (Args&&... args);

    pop         Remove top element:  void pop();

    swap        Swap contents:   void swap (stack& x) noexcept();
    */
    std::stack<int> mystack;
    int sum(0);

    for (int i = 1; i <= 10; i++)
        mystack.push(i);

    while (!mystack.empty())
    {
        sum += mystack.top();
        mystack.pop();
    }

    std::cout << "total: " << sum << '\n';
    // total: 55

    std::stack<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';

    for (int i = 0; i < 5; i++)
        myints.push(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.pop();
    std::cout << "2. size: " << myints.size() << '\n';
    // 0. size: 0
    // 1. size: 5
    // 2. size: 4

    std::stack<int> mystack;

    mystack.push(10);
    mystack.push(20);

    mystack.top() -= 5;

    std::cout << "mystack.top() is now " << mystack.top() << '\n';
    // mystack.top() is now 15

    std::stack<std::string> mystack;

    mystack.emplace("First sentence");
    mystack.emplace("Second sentence");

    std::cout << "mystack contains:\n";
    while (!mystack.empty())
    {
        std::cout << mystack.top() << '\n';
        mystack.pop();
    }
    // mystack contains:
    // Second sentence
    // First sentence

    std::stack<int> foo, bar;
    foo.push(10);
    foo.push(20);
    foo.push(30);
    bar.push(111);
    bar.push(222);

    foo.swap(bar);

    std::cout << "size of foo: " << foo.size() << '\n';
    std::cout << "size of bar: " << bar.size() << '\n';
    // size of foo: 2
    // size of bar: 3

    return 0;
}
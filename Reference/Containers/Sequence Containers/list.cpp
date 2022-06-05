/*
Lists are sequence containers that allow constant time insert and erase operations anywhere within the sequence, and iteration in both directions.

List containers are implemented as doubly-linked lists; Doubly linked lists can store each of the elements they contain in different and unrelated storage locations.
The ordering is kept internally by the association to each element of a link to the element preceding it and a link to the element following it.

They are very similar to forward_list: The main difference being that forward_list objects are single-linked lists,
and thus they can only be iterated forwards, in exchange for being somewhat smaller and more efficient.

Compared to other base standard sequence containers (array, vector and deque), lists perform generally better in inserting,
extracting and moving elements in any position within the container for which an iterator has already been obtained, and therefore also in algorithms that make intensive use of these, like sorting algorithms.

The main drawback of lists and forward_lists compared to these other sequence containers is that they lack direct access to the elements by their position;
For example, to access the sixth element in a list, one has to iterate from a known position (like the beginning or the end) to that position,
which takes linear time in the distance between these. They also consume some extra memory to keep the linking information associated
to each element (which may be an important factor for large lists of small-sized elements).

Container properties:
Sequence
Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their position in this sequence.

Doubly-linked list
Each element keeps information on how to locate the next and the previous elements,
allowing constant time insert and erase operations before or after a specific element (even of entire ranges), but no direct random access.

Allocator-aware
The container uses an allocator object to dynamically handle its storage needs.
*/

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    // TODO: constructor
    //* default: explicit list (const allocator_type& alloc = allocator_type());
    //* fill: explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
    //* range: list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
    //* copy: list (const list& x);
    std::list<int> first;                               // empty list of ints
    std::list<int> second(4, 100);                      // four ints with value 100
    std::list<int> third(second.begin(), second.end()); // iterating through second
    std::list<int> fourth(third);                       // a copy of third

    int myints[] = {16, 2, 77, 29};
    std::list<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
    std::cout << "The contents of fifth are: ";
    for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
        std::cout << *it << ' ';
    std::cout << '\n';
    // The contents of fifth are: 16 2 77 29

    // TODO: Operators
    //* copy: list& operator= (const list& x);
    std::list<int> first(3);  // list of 3 zero-initialized ints
    std::list<int> second(5); // list of 5 zero-initialized ints

    second = first;
    first = std::list<int>();

    std::cout << "Size of first: " << int(first.size()) << '\n';
    std::cout << "Size of second: " << int(second.size()) << '\n';
    // Size of first: 0
    // Size of second: 3

    // TODO: Iterators
    //* begin	    Return iterator to beginning: iterator begin(); const_iterator begin() const;
    //* end	        Return iterator to end: iterator end(); const_iterator end() const;
    int myints[] = {75, 23, 65, 42, 13};
    std::list<int> mylist(myints, myints + 5);
    std::cout << "mylist contains:";
    for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    // mylist contains: 75 23 65 42 13

    //* rbegin	    Return reverse iterator to reverse beginning:
    //* rend	    Return reverse iterator to reverse end:
    //* cbegin	    Return const_iterator to beginning:
    //* cend	    Return const_iterator to end:
    //* crbegin	    Return const_reverse_iterator to reverse beginning:
    //* crend	    Return const_reverse_iterator to reverse end:

    // TODO: Capacity
    //* empty	    Test whether container is empty: bool empty() const;
    //* size	        Return size: size_type size() const;
    //* max_size	    Return maximum size: size_type max_size() const;

    // TODO: Element access
    //* front	Access first element: reference front(); const_reference front() const;
    //* back	    Access last element: reference back(); const_reference back() const;
    std::list<int> mylist;
    mylist.push_back(77);
    mylist.push_back(22);

    // now front equals 77, and back 22
    mylist.front() -= mylist.back();
    std::cout << "mylist.front() is now " << mylist.front() << '\n';
    // list.front() is now 55

    // TODO: Modifiers
    //* assign	        Assign new content to container:
    // range: void assign (InputIterator first, InputIterator last);
    // fill: void assign (size_type n, const value_type& val);
    std::list<int> first;
    std::list<int> second;

    first.assign(7, 100);                      // 7 ints with value 100
    second.assign(first.begin(), first.end()); // a copy of first
    int myints[] = {1776, 7, 4};
    first.assign(myints, myints + 3); // assigning from array
    std::cout << "Size of first: " << int(first.size()) << '\n';
    std::cout << "Size of second: " << int(second.size()) << '\n';
    // Size of first: 3
    // Size of second: 7

    //* emplace_front	Construct and insert element at beginning: void emplace_front (Args&&... args);
    //* push_front	    Insert element at beginning: void push_front (const value_type& val);
    //* pop_front	    Delete first element: void pop_front();
    //* emplace_back	Construct and insert element at the end: void emplace_back (Args&&... args);
    //* push_back	    Add element at the end: void push_back (const value_type& val);
    //* pop_back	    Delete last element: void pop_back();
    //* emplace	        Construct and insert element: iterator emplace (const_iterator position, Args&&... args);
    //* insert	        Insert elements:
    // single element:iterator insert (iterator position, const value_type& val);
    // fill: void insert (iterator position, size_type n, const value_type& val);
    // range: void insert (iterator position, InputIterator first, InputIterator last);
    std::list<int> mylist;
    std::list<int>::iterator it;
    // set some initial values:
    for (int i = 1; i <= 5; ++i)
        mylist.push_back(i); // 1 2 3 4 5

    it = mylist.begin();
    ++it;                  // it points now to number 2
    mylist.insert(it, 10); // 1 10 2 3 4 5
    // "it" still points to number 2
    mylist.insert(it, 2, 20); // 1 10 20 20 2 3 4 5
    --it;                     // it points now to the second 20
    std::vector<int> myvector(2, 30);
    mylist.insert(it, myvector.begin(), myvector.end());
    // 1 10 20 30 30 20 2 3 4 5
    std::cout << "mylist contains:";
    for (it = mylist.begin(); it != mylist.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    // mylist contains: 1 10 20 30 30 20 2 3 4 5

    //* erase	        Erase elements: iterator erase (iterator position); iterator erase (iterator first, iterator last);
    std::list<int> mylist;
    std::list<int>::iterator it1, it2;

    // set some values:
    for (int i = 1; i < 10; ++i)
        mylist.push_back(i * 10);

    it1 = it2 = mylist.begin();
    advance(it2, 6);
    ++it1;
    it1 = mylist.erase(it1); // 10 30 40 50 60 70 80 90
    it2 = mylist.erase(it2); // 10 30 40 50 60 80 90
    ++it1;
    --it2;

    mylist.erase(it1, it2); // 10 30 60 80 90
    std::cout << "mylist contains:";
    for (it1 = mylist.begin(); it1 != mylist.end(); ++it1)
        std::cout << ' ' << *it1;
    std::cout << '\n';
    // mylist contains: 10 30 60 80 90

    //* swap	        Swap content: void swap (list& x);
    //* resize	        Change size: void resize (size_type n, value_type val = value_type());
    //* clear	        Clear content: Void clear();

    // TODO: Operations
    //* splice	Transfer elements from list to list:
    //* remove	Remove elements with specific value:
    //* remove_if	Remove elements fulfilling condition:
    //* unique	Remove duplicate values:
    //* merge	Merge sorted lists:
    //* sort	Sort elements in container:
    //* reverse	Reverse the order of elements:

    // TODO: Observers
    //* get_allocator	Get allocator:
    return 0;
}
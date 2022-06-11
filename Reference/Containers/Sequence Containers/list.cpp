/*
Lists are sequence containers that allow constant time insert and erase operations anywhere within the sequence, and iteration in both directions.

List containers are implemented as doubly-linked lists; Doubly linked lists can store each of the elements they contain in different and unrelated storage locations.
The ordering is kept internally by the association to each element of a link to the element preceding it and a link to the element following it.

They are very similar to forward_list: The main difference being that forward_list objects are single-linked lists,
and thus they can only be iterated forwards, in exchange for being somewhat smaller and more efficient.

Compared to other base standard sequence containers(array, vector and deque), lists perform generally better in inserting,
extracting and moving elements in any position within the container for which an iterator has already been obtained, and therefore also in algorithms that make intensive use of these, like sorting algorithms.

The main drawback of lists and forward_lists compared to these other sequence containers is that they lack direct access to the elements by their position;
For example, to access the sixth element in a list, one has to iterate from a known position(like the beginning or the end) to that position,
which takes linear time in the distance between these. They also consume some extra memory to keep the linking information associated
to each element(which may be an important factor for large lists of small-sized elements).

Container properties:
Sequence
Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their position in this sequence.

Doubly-linked list
Each element keeps information on how to locate the next and the previous elements,
allowing constant time insert and erase operations before or after a specific element(even of entire ranges), but no direct random access.

Allocator-aware
The container uses an allocator object to dynamically handle its storage needs.
*/

#include <iostream>
#include <list>
#include <math.h>
#include <vector>

using namespace std;

bool single_digit(const int &value)
{
    return (value < 10);
}

struct is_odd
{
    bool operator()(const int &value) { return (value % 2) == 1; }
};

bool same_integral_part(double first, double second)
{
    return (int(first) == int(second));
}

struct is_near
{
    bool operator()(double first, double second)
    {
        return (fabs(first - second) < 5.0);
    }
};
bool mycomparison(double first, double second)
{
    return (int(first) < int(second));
}

bool compare_nocase(const string &first, const string &second)
{
    unsigned int i = 0;
    while ((i < first.length()) && (i < second.length()))
    {
        if (tolower(first[i]) < tolower(second[i]))
            return true;
        else if (tolower(first[i]) > tolower(second[i]))
            return false;
        ++i;
    }
    return (first.length() < second.length());
}

int main()
{
    // TODO: constructor
    //* default: explicit list(const allocator_type& alloc = allocator_type());
    //* fill: explicit list(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
    //* range: list(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
    //* copy: list(const list& x);
    list<int> first;                               // empty list of ints
    list<int> second(4, 100);                      // four ints with value 100
    list<int> third(second.begin(), second.end()); // iterating through second
    list<int> fourth(third);                       // a copy of third

    int myints[] = {16, 2, 77, 29};
    list<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
    cout << "The contents of fifth are: ";
    for (list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
        cout << *it << ' ';
    cout << '\n';
    // The contents of fifth are: 16 2 77 29

    // TODO: Operators
    //* copy: list& operator=(const list& x);
    list<int> first(3);  // list of 3 zero-initialized ints
    list<int> second(5); // list of 5 zero-initialized ints

    second = first;
    first = list<int>();

    cout << "Size of first: " << int(first.size()) << '\n';
    cout << "Size of second: " << int(second.size()) << '\n';
    // Size of first: 0
    // Size of second: 3

    // TODO: Iterators
    //* begin	    Return iterator to beginning: iterator begin(); const_iterator begin() const;
    //* end	        Return iterator to end: iterator end(); const_iterator end() const;
    int myints[] = {75, 23, 65, 42, 13};
    list<int> mylist(myints, myints + 5);
    cout << "mylist contains:";
    for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
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
    list<int> mylist;
    mylist.push_back(77);
    mylist.push_back(22);

    // now front equals 77, and back 22
    mylist.front() -= mylist.back();
    cout << "mylist.front() is now " << mylist.front() << '\n';
    // list.front() is now 55

    // TODO: Modifiers
    //* assign	        Assign new content to container:
    // range: void assign(InputIterator first, InputIterator last);
    // fill: void assign(size_type n, const value_type& val);
    list<int> first;
    list<int> second;

    first.assign(7, 100);                      // 7 ints with value 100
    second.assign(first.begin(), first.end()); // a copy of first
    int myints[] = {1776, 7, 4};
    first.assign(myints, myints + 3); // assigning from array
    cout << "Size of first: " << int(first.size()) << '\n';
    cout << "Size of second: " << int(second.size()) << '\n';
    // Size of first: 3
    // Size of second: 7

    //* emplace_front	Construct and insert element at beginning: void emplace_front(Args&&... args);
    //* push_front	    Insert element at beginning: void push_front(const value_type& val);
    //* pop_front	    Delete first element: void pop_front();
    //* emplace_back	Construct and insert element at the end: void emplace_back(Args&&... args);
    //* push_back	    Add element at the end: void push_back(const value_type& val);
    //* pop_back	    Delete last element: void pop_back();
    //* emplace	        Construct and insert element: iterator emplace(const_iterator position, Args&&... args);
    //* insert	        Insert elements:
    // single element:iterator insert(iterator position, const value_type& val);
    // fill: void insert(iterator position, size_type n, const value_type& val);
    // range: void insert(iterator position, InputIterator first, InputIterator last);
    list<int> mylist;
    list<int>::iterator it;
    // set some initial values:
    for (int i = 1; i <= 5; ++i)
        mylist.push_back(i); // 1 2 3 4 5

    it = mylist.begin();
    ++it;                  // it points now to number 2
    mylist.insert(it, 10); // 1 10 2 3 4 5
    // "it" still points to number 2
    mylist.insert(it, 2, 20); // 1 10 20 20 2 3 4 5
    --it;                     // it points now to the second 20
    vector<int> myvector(2, 30);
    mylist.insert(it, myvector.begin(), myvector.end());
    // 1 10 20 30 30 20 2 3 4 5
    cout << "mylist contains:";
    for (it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    // mylist contains: 1 10 20 30 30 20 2 3 4 5

    //* erase	        Erase elements: iterator erase(iterator position); iterator erase(iterator first, iterator last);
    list<int> mylist;
    list<int>::iterator it1, it2;

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
    cout << "mylist contains:";
    for (it1 = mylist.begin(); it1 != mylist.end(); ++it1)
        cout << ' ' << *it1;
    cout << '\n';
    // mylist contains: 10 30 60 80 90

    //* swap	        Swap content: void swap(list& x);
    //* resize	        Change size: void resize(size_type n, value_type val = value_type());
    //* clear	        Clear content: Void clear();

    // TODO: Operations
    //* splice	Transfer elements from list to list:
    // entire list: void splice(iterator position, list& x);
    // single element: void splice(iterator position, list& x, iterator i);
    // element range: void splice(iterator position, list& x, iterator first, iterator last);
    list<int> mylist1, mylist2;
    list<int>::iterator it;

    for (int i = 1; i <= 4; ++i)
        mylist1.push_back(i); // mylist1: 1 2 3 4
    for (int i = 1; i <= 3; ++i)
        mylist2.push_back(i * 10); // mylist2: 10 20 30

    it = mylist1.begin();
    ++it;                        // points to 2
    mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                 // mylist2(empty)
                                 // "it" still points to 2(the 5th element)
    mylist2.splice(mylist2.begin(), mylist1, it);
    // mylist1: 1 10 20 30 3 4
    // mylist2: 2
    // "it" is now invalid.
    it = mylist1.begin();
    advance(it, 3); // "it" points now to 30
    mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
    // mylist1: 30 3 4 1 10 20
    cout << "mylist1 contains:";
    for (it = mylist1.begin(); it != mylist1.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    cout << "mylist2 contains:";
    for (it = mylist2.begin(); it != mylist2.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    // mylist1 contains: 30 3 4 1 10 20
    // mylist2 contains: 2

    //* remove	    Remove elements with specific value: void remove(const value_type& val);
    int myints[] = {17, 89, 7, 14};
    list<int> mylist(myints, myints + 4);
    mylist.remove(89);
    cout << "mylist contains:";
    for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    // mylist contains: 17 7 14

    //* remove_if	Remove elements fulfilling condition: void remove_if(Predicate pred);
    int myints[] = {15, 36, 7, 17, 20, 39, 4, 1};
    list<int> mylist(myints, myints + 8); // 15 36 7 17 20 39 4 1
    mylist.remove_if(single_digit);       // 15 36 17 20 39
    mylist.remove_if(is_odd());           // 36 20
    cout << "mylist contains:";
    for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    // mylist contains: 36 20

    //* unique	    Remove duplicate values: void unique(); void unique(BinaryPredicate binary_pred);
    double mydoubles[] = {12.15, 2.72, 73.0, 12.77, 3.14,
                          12.77, 73.35, 72.25, 15.3, 72.25};
    list<double> l(mydoubles, mydoubles + 10);
    l.sort();                     // 2.72, 3.14, 12.15, 12.77, 12.77,
                                  // 15.3, 72.25, 72.25, 73.0, 73.35
    l.unique();                   // 2.72, 3.14, 12.15, 12.77
                                  // 15.3, 72.25, 73.0, 73.35
    l.unique(same_integral_part); // 2.72, 3.14, 12.15
                                  // 15.3, 72.25, 73.0
    l.unique(is_near());          // 2.72, 12.15, 72.25
    cout << "l contains:";
    for (list<double>::iterator it = l.begin(); it != l.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    // l contains: 2.72 12.15 72.25

    //* merge	    Merge sorted lists: void merge(list& x); void merge(list& x, Compare comp);
    list<double> f, s;
    f.push_back(3.1);
    f.push_back(2.2);
    f.push_back(2.9);
    s.push_back(3.7);
    s.push_back(7.1);
    s.push_back(1.4);
    f.sort();
    s.sort();
    f.merge(s);

    s.push_back(2.1);
    f.merge(s, mycomparison);
    cout << "f contains:";
    for (list<double>::iterator it = f.begin(); it != f.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    // f contains: 1.4 2.2 2.9 2.1 3.1 3.7 7.1

    //* sort	    Sort elements in container: void sort(); void sort(Compare comp);
    list<string> myl;
    list<string>::iterator iter;
    myl.push_back("one");
    myl.push_back("two");
    myl.push_back("Three");

    myl.sort();
    cout << "myl contains:";
    for (iter = myl.begin(); iter != myl.end(); ++iter)
        cout << ' ' << *iter;
    cout << '\n';

    myl.sort(compare_nocase);
    cout << "myl contains:";
    for (iter = myl.begin(); iter != myl.end(); ++iter)
        cout << ' ' << *iter;
    cout << '\n';
    // myl contains: Three one two
    // myl contains: one Three two

    //* reverse	    Reverse the order of elements: void reverse();
    list<int> mylist;
    for (int i = 1; i < 10; ++i)
        mylist.push_back(i);
    mylist.reverse();
    cout << "mylist contains:";
    for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    // mylist contains: 9 8 7 6 5 4 3 2 1

    // TODO: Observers
    //* get_allocator	Get allocator: allocator_type get_allocator() const;
    
    return 0;
}
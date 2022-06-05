/*
Vectors are sequence containers representing arrays that can change in size.

Just like arrays, vectors use contiguous storage locations for their elements, 
which means that their elements can also be accessed using offsets on regular pointers to its elements, 
and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.

Internally, vectors use a dynamically allocated array to store their elements.
This array may need to be reallocated in order to grow in size when new elements are inserted, 
which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing time, 
and thus, vectors do not reallocate each time an element is added to the container.

Instead, vector containers may allocate some extra storage to accommodate for possible growth, 
and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements (i.e., its size).
Libraries can implement different strategies for growth to balance between memory usage and reallocations, but in any case, reallocations should only happen at logarithmically growing intervals of size so that the insertion of individual elements at the end of the vector can be provided with amortized constant time complexity (see push_back).

Therefore, compared to arrays, vectors consume more memory in exchange for the ability to manage storage and grow dynamically in an efficient way.

Compared to the other dynamic sequence containers (deques, lists and forward_lists), 
vectors are very efficient accessing its elements (just like arrays) and relatively efficient adding or removing elements from its end.
For operations that involve inserting or removing elements at positions other than the end, they perform worse than the others, 
and have less consistent iterators and references than lists and forward_lists.

Container properties:
Sequence
Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their position in this sequence.

Dynamic array
Allows direct access to any element in the sequence, even through pointer arithmetics, 
and provides relatively fast addition/removal of elements at the end of the sequence.

Allocator-aware
The container uses an allocator object to dynamically handle its storage needs.
*/

#include <iostream>
#include <vector>

using namespace std;

void input(vector<int> &vect)
{
    for (int i = 0; i < vect.size(); i++)
        cin >> vect[i];
}
void output(vector<int> vect)
{
    for (auto it = vect.begin(); it != vect.end(); it++)
        cout << *it << " ";
}
int main()
{
    /*
    constructor:
    default: explicit vector (const allocator_type& alloc = allocator_type());
    fill: explicit vector (size_type n);     vector (size_type n, const value_type& val, const allocator_type& alloc = allocator_type());
    range: vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
    copy: vector (const vector& x);   vector (const vector& x, const allocator_type& alloc);
    move: vector (vector&& x);    vector (vector&& x, const allocator_type& alloc);
    initializer list: vector (initializer_list<value_type> il, const allocator_type& alloc = allocator_type());
    */
    vector<int> first;                               // empty vector of ints
    vector<int> second(4, 100);                      // four ints with value 100
    vector<int> third(second.begin(), second.end()); // iterating through second
    vector<int> fourth(third);                       // a copy of third

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16, 2, 77, 29};
    vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

    cout << "The contents of fifth are:";
    for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        cout << ' ' << *it;
    // The contents of fifth are: 16 2 77 29

    /*
    Operators:
    copy: vector& operator= (const vector &x);
    move: vector& operator= (vector &&x);
    initializer list: vector& operator= (initializer_list<value_type> il);

    bool operator== (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
    bool operator!= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
    bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
    bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
    bool operator> (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
    bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
    */

    vector<int> foo(3, 0);
    vector<int> bar(5, 0);

    bar = foo;
    foo = vector<int>();

    cout << "Size of foo: " << int(foo.size()) << '\n';
    cout << "Size of bar: " << int(bar.size()) << '\n';
    // Size of foo: 0
    // Size of bar: 3

    vector<int> foo(3, 100); // three ints with a value of 100
    vector<int> bar(2, 200); // two ints with a value of 200

    if (foo == bar)
        cout << "foo and bar are equal\n";
    if (foo != bar)
        cout << "foo and bar are not equal\n";
    if (foo < bar)
        cout << "foo is less than bar\n";
    if (foo > bar)
        cout << "foo is greater than bar\n";
    if (foo <= bar)
        cout << "foo is less than or equal to bar\n";
    if (foo >= bar)
        cout << "foo is greater than or equal to bar\n";
    // foo and bar are not equal
    // foo is less than bar
    // foo is less than or equal to bar

    /*
    Iterators:
    begin       Return iterator to beginning: iterator begin() noexcept;    const_iterator begin() const noexcept;

    end         Return iterator to end: iterator end() noexcept;   const_iterator end() const noexcept

    rbegin      Return reverse iterator to reverse beginning: reverse_iterator rbegin() noexcept;  const_reverse_iterator rbegin() const noexcept;

    rend        Return reverse iterator to reverse end: reverse_iterator rend() noexcept;    const_reverse_iterator rend() const noexcept;

    cbegin      Return const_iterator to beginning

    cend        Return const_iterator to end

    crbegin     Return const_reverse_iterator to reverse beginning

    crend       Return const_reverse_iterator to reverse end
    */

    vector<int> myvector;
    for (int i = 1; i <= 5; i++)
        myvector.push_back(i);
    cout << "myvector contains:";
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout << ' ' << *it;
    // myvector contains: 1 2 3 4 5

    vector<int> myvector(5); // 5 default-constructed ints
    int i = 0;
    vector<int>::reverse_iterator rit = myvector.rbegin();
    for (; rit != myvector.rend(); ++rit)
        *rit = ++i;

    cout << "myvector contains:";
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout << ' ' << *it;
    // myvector contains: 5 4 3 2

    /*
    Capacity:
    size                Return size: size_type size() const noexcept;

    max_size            Return maximum size: size_type max_size() const noexcept;

    resize              Change size: void resize (size_type n);    void resize (size_type n, const value_type& val);

    capacity            Return size of allocated storage capacity: size_type capacity() const noexcept;

    empty               Test whether vector is empty: bool empty() const noexcept;

    reserve             Request a change in capacity: void reserve (size_type n);

    shrink_to_fit       Shrink to fit: void shrink_to_fit();
    */

    vector<int> myvector;
    for (int i = 0; i < 100; i++)
        myvector.push_back(i);

    cout << "size: " << (int)myvector.size() << '\n';
    cout << "capacity: " << (int)myvector.capacity() << '\n';
    cout << "max_size: " << (int)myvector.max_size() << '\n';
    // size: 100
    // capacity: 128
    // max_size: 1073741823

    vector<int> myvector;
    for (int i = 1; i < 10; i++)
        myvector.push_back(i);
    myvector.resize(5);
    myvector.resize(8, 100);
    myvector.resize(12);
    cout << "myvector contains:";
    for (int i = 0; i < myvector.size(); i++)
        cout << ' ' << myvector[i];
    // myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0

    vector<int> myvector;
    int sum(0);

    for (int i = 1; i <= 10; i++)
        myvector.push_back(i);

    while (!myvector.empty())
    {
        sum += myvector.back();
        myvector.pop_back();
    }
    cout << "total: " << sum << '\n';
    // total: 55

    /*
    Element access:
    operator[]                          Access element: reference operator[] (size_type n);    const_reference operator[] (size_type n) const;

    at    Access element: reference at (size_type n);    const_reference at (size_type n) const;

    front    Access first element: reference front();  const_reference front() const;

    back    Access last element: reference back();  const_reference back() const;

    data    Access data: value_type* data() noexcept;     const value_type* data() const noexcept;
    */
    vector<int> myvector;

    myvector.push_back(78);
    myvector.push_back(16);

    myvector.front() -= myvector.back();
    cout << "myvector.front() is now " << myvector.front() << '\n';
    // myvector.front() is now 62

    vector<int> myvector(5);

    int *p = myvector.data();

    *p = 10;
    ++p;
    *p = 20;
    p[2] = 100;

    cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); ++i)
        cout << ' ' << myvector[i];
    cout << '\n';
    // myvector contains: 10 20 0 100 0

    /*
    Modifiers:
    assign              Assign vector content: fill: void assign (size_type n, const value_type& val);
                                                    range: void assign (InputIterator first, InputIterator last);
                                                    initializer list: void assign (initializer_list<value_type> il);

    push_back           Add element at the end: void push_back (const value_type& val);     void push_back (value_type&& val);

    pop_back            Delete last element: void pop_back();

    insert              Insert elements: single element: iterator insert (const_iterator position, const value_type& val);
                                            fill: iterator insert (const_iterator position, size_type n, const value_type& val);
                                            range: iterator insert (const_iterator position, InputIterator first, InputIterator last);
                                            move: iterator insert (const_iterator position, value_type&& val);
                                            initializer list: iterator insert (const_iterator position, initializer_list<value_type> il);

    erase               Erase elements: iterator erase (const_iterator position);   iterator erase (const_iterator first, const_iterator last);

    swap                Swap content: void swap (vector& x);

    clear               Clear content: void clear() noexcept;

    emplace             Construct and insert element: iterator emplace (const_iterator position, Args&&... args);

    emplace_back        Construct and insert element at the end: void emplace_back (Args&&... args);
    */
    vector<int> first;
    vector<int> second;
    vector<int> third;

    first.assign(7, 100); // 7 ints with a value of 100

    vector<int>::iterator it;
    it = first.begin() + 1;

    second.assign(it, first.end() - 1); // the 5 central values of first

    int myints[] = {1776, 7, 4};
    third.assign(myints, myints + 3); // assigning from array.

    cout << "Size of first: " << int(first.size()) << '\n';
    cout << "Size of second: " << int(second.size()) << '\n';
    cout << "Size of third: " << int(third.size()) << '\n';
    // Size of first: 7
    // Size of second: 5
    // Size of third: 3
    vector<int> myvector(3, 100);
    vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert(it, 200);

    myvector.insert(it, 2, 300);

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    vector<int> anothervector(2, 400);
    myvector.insert(it + 2, anothervector.begin(), anothervector.end());

    int myarray[] = {501, 502, 503};
    myvector.insert(myvector.begin(), myarray, myarray + 3);

    cout << "myvector contains:";
    for (it = myvector.begin(); it < myvector.end(); it++)
        cout << ' ' << *it;
    // myvector contains: 501 502 503 300 300 400 400 200 100 100 100

    vector<int> myvector;

    // set some values (from 1 to 10)
    for (int i = 1; i <= 10; i++)
        myvector.push_back(i);

    // erase the 6th element
    myvector.erase(myvector.begin() + 5);

    // erase the first 3 elements:
    myvector.erase(myvector.begin(), myvector.begin() + 3);

    cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); ++i)
        cout << ' ' << myvector[i];
    // myvector contains: 4 5 7 8 9 10

    vector<int> foo(3, 100); // three ints with a value of 100
    vector<int> bar(5, 200); // five ints with a value of 200

    foo.swap(bar);

    cout << "foo contains:";
    for (unsigned i = 0; i < foo.size(); i++)
        cout << ' ' << foo[i];
    cout << '\n';

    cout << "bar contains:";
    for (unsigned i = 0; i < bar.size(); i++)
        cout << ' ' << bar[i];
    // foo contains: 200 200 200 200 200
    // bar contains: 100 100 100
    vector<int> myvector = {10, 20, 30};

    auto it = myvector.emplace(myvector.begin() + 1, 100);
    myvector.emplace(it, 200);
    myvector.emplace(myvector.end(), 300);

    cout << "myvector contains:";
    for (auto &x : myvector)
        cout << ' ' << x;
    // myvector contains: 10 200 100 20 30 300

    vector<vector<int>> vect{
        /* Element one with 2 values in it. */
        {1, 2}, 

        /* Element two with 3 values in it. */
        {4, 5, 6}, 

        /* Element three with 4 values in it. */
        {7, 8, 9, 10}};
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
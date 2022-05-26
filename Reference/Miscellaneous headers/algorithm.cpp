/*
algorithm

The header <algorithm> defines a collection of functions especially designed to be used on ranges of elements.

A range is any sequence of objects that can be accessed through iterators or pointers, such as an array or an instance of some of the STL containers.
Notice though, that algorithms operate through iterators directly on the values, not affecting in any way the structure of any possible container
(it never affects the size or storage allocation of the container).
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

void myfunction(int i)
{
    cout << ' ' << i;
}

bool IsOdd(int i)
{
    return ((i % 2) == 1);
}

bool comp_case_insensitive(char c1, char c2)
{
    return (tolower(c1) == tolower(c2));
}

bool mypredicate(int i, int j)
{
    return (i == j);
}

bool myfn(int i, int j)
{
    return i < j;
}

int main()
{
    //----------------------------------------Non - modifying sequence operations----------------------------------------//
    // all_of              Test condition on all elements in range:    bool all_of(InputIterator first, InputIterator last, UnaryPredicate pred);
    array<int, 8> foo = {3, 5, 7, 11, 13, 17, 19, 23};
    if (all_of(foo.begin(), foo.end(), [](int i)
               { return i % 2; }))
        cout << "All the elements are odd numbers.\n";
    // All the elements are odd numbers.

    // any_of              Test if any element in range fulfills condition:    bool any_of(InputIterator first, InputIterator last, UnaryPredicate pred);
    array<int, 7> foo = {0, 1, -1, 3, -3, 5, -5};
    if (any_of(foo.begin(), foo.end(), [](int i)
               { return i < 0; }))
        cout << "There are negative elements in the range.\n";
    // There are negative elements in the range.

    // none_of             Test if no elements fulfill condition:       bool none_of(InputIterator first, InputIterator last, UnaryPredicate pred);
    array<int, 8> foo = {1, 2, 4, 8, 16, 32, 64, 128};
    if (none_of(foo.begin(), foo.end(), [](int i)
                { return i < 0; }))
        cout << "There are no negative elements in the range.\n";
    // There are no negative elements in the range.

    // for_each            Apply function to range:    Function for_each(InputIterator first, InputIterator last, Function fn);
    vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);

    cout << "myvector contains:";
    for_each(myvector.begin(), myvector.end(), myfunction);
    cout << '\n';
    // myvector contains: 10 20 30

    // find                Find value in range:    InputIterator find(InputIterator first, InputIterator last, const T& val);
    int myints[] = {10, 20, 30, 40};
    int *p;
    p = find(myints, myints + 4, 30);
    if (p != myints + 4)
        cout << "Element found in myints: " << *p << '\n';
    else
        cout << "Element not found in myints\n";
    // Element found in myints: 30

    // find_if             Find element in range:      InputIterator find_if(InputIterator first, InputIterator last, UnaryPredicate pred);
    vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(25);
    myvector.push_back(40);
    myvector.push_back(55);
    vector<int>::iterator it = find_if(myvector.begin(), myvector.end(), IsOdd);
    cout << "The first odd value is " << *it << '\n';
    // The first odd value is 25

    // find_if_not         Find element in range(negative condition):     InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred);
    array<int, 5> foos = {1, 2, 3, 4, 5};
    array<int, 5>::iterator it = find_if_not(foos.begin(), foos.end(), [](int i)
                                             { return i % 2; });
    cout << "The first even value is " << *it << '\n';
    // The first even value is 2

    // find_end            Find last subsequence in range:     ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);
    // ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred);
    int myints[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    vector<int> haystack(myints, myints + 10);

    int needle1[] = {1, 2, 3};
    // using default comparison:
    vector<int>::iterator it;
    it = find_end(haystack.begin(), haystack.end(), needle1, needle1 + 3);
    if (it != haystack.end())
        cout << "needle1 last found at position " << (it - haystack.begin()) << '\n';

    int needle2[] = {4, 5, 1};
    // using predicate comparison:
    it = find_end(haystack.begin(), haystack.end(), needle2, needle2 + 3, myfunction);
    if (it != haystack.end())
        cout << "needle2 last found at position " << (it - haystack.begin()) << '\n';
    // needle1 last found at position 5
    // needle2 last found at position 3

    // find_first_of       Find element from set in range:     ForwardIterator1 find_first_of(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);
    // ForwardIterator1 find_first_of(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred);
    int mychars[] = {'a', 'b', 'c', 'A', 'B', 'C'};
    vector<char> haystack(mychars, mychars + 6);
    vector<char>::iterator it;

    int needle[] = {'A', 'B', 'C'};
    // using default comparison:
    it = find_first_of(haystack.begin(), haystack.end(), needle, needle + 3);

    if (it != haystack.end())
        cout << "The first match is: " << *it << '\n';

    // using predicate comparison:
    it = find_first_of(haystack.begin(), haystack.end(),
                       needle, needle + 3, comp_case_insensitive);

    if (it != haystack.end())
        cout << "The first match is: " << *it << '\n';
    // The first match is: A
    // The first match is: a

    // adjacent_find       Find equal adjacent elements in range:   ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last);
    // ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last, BinaryPredicate pred);
    int myints[] = {5, 20, 5, 30, 30, 20, 10, 10, 20};
    vector<int> myvector(myints, myints + 8);
    vector<int>::iterator it;
    // using default comparison:
    it = adjacent_find(myvector.begin(), myvector.end());
    if (it != myvector.end())
        cout << "the first pair of repeated elements are: " << *it << '\n';
    // using predicate comparison:
    it = adjacent_find(++it, myvector.end(), myfunction);
    if (it != myvector.end())
        cout << "the second pair of repeated elements are: " << *it << '\n';
    // the first pair of repeated elements are: 30
    // the second pair of repeated elements are: 10

    // count               Count appearances of value in range:    count(InputIterator first, InputIterator last, const T& val);
    int myints[] = {10, 20, 30, 30, 20, 10, 10, 20}; // 8 elements
    int mycount = count(myints, myints + 8, 10);
    cout << "10 appears " << mycount << " times.\n";
    // 10 appears 3 times.

    // count_if            Return number of elements in range satisfying condition:    count_if(InputIterator first, InputIterator last, UnaryPredicate pred);
    vector<int> myvector;
    for (int i = 1; i < 10; i++)
        myvector.push_back(i); // myvector: 1 2 3 4 5 6 7 8 9
    int mycount = count_if(myvector.begin(), myvector.end(), IsOdd);
    cout << "myvector contains " << mycount << " odd values.\n";
    // myvector contains 5 odd values.

    // mismatch            Return first position where two ranges differ:   mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);
    // mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred);
    vector<int> myvector;
    for (int i = 1; i < 6; i++)
        myvector.push_back(i * 10);         // myvector: 10 20 30 40 50
    int myints[] = {10, 20, 80, 320, 1024}; // myints: 10 20 80 320 1024
    pair<vector<int>::iterator, int *> mypair;

    // using default comparison:
    mypair = mismatch(myvector.begin(), myvector.end(), myints);
    cout << "First mismatching elements: " << *mypair.first;
    cout << " and " << *mypair.second << '\n';

    ++mypair.first;
    ++mypair.second;

    // using predicate comparison:
    mypair = mismatch(mypair.first, myvector.end(), mypair.second, mypredicate);
    cout << "Second mismatching elements: " << *mypair.first;
    cout << " and " << *mypair.second << '\n';
    // First mismatching elements: 30 and 80
    // Second mismatching elements: 40 and 320

    // equal               Test whether the elements in two ranges are equal:  bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);
    // bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred);
    int myints[] = {20, 40, 60, 80, 100};     // myints: 20 40 60 80 100
    vector<int> myvector(myints, myints + 5); // myvector: 20 40 60 80 100

    // using default comparison:
    if (equal(myvector.begin(), myvector.end(), myints))
        cout << "The contents of both sequences are equal.\n";
    else
        cout << "The contents of both sequences differ.\n";

    myvector[3] = 81; // myvector: 20 40 60 81 100
    // using predicate comparison:
    if (equal(myvector.begin(), myvector.end(), myints, mypredicate))
        cout << "The contents of both sequences are equal.\n";
    else
        cout << "The contents of both sequences differ.\n";
    // The contents of both sequences are equal.
    // The contents of both sequence differ.

    // is_permutation      Test whether range is permutation of another:    bool is_permutation(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2);
    // bool is_permutation(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, BinaryPredicate pred);
    array<int, 5> foo = {1, 2, 3, 4, 5};
    array<int, 5> bar = {3, 1, 4, 5, 2};
    if (is_permutation(foo.begin(), foo.end(), bar.begin()))
        cout << "foo and bar contain the same elements.\n";
    // foo and bar contain the same elements.

    // search              Search range for subsequence:   ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);
    // ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred);
    vector<int> haystack;
    for (int i = 1; i < 10; i++)
        haystack.push_back(i * 10);

    // using default comparison:
    int needle1[] = {40, 50, 60, 70};
    vector<int>::iterator it;
    it = search(haystack.begin(), haystack.end(), needle1, needle1 + 4);

    if (it != haystack.end())
        cout << "needle1 found at position " << (it - haystack.begin()) << '\n';
    else
        cout << "needle1 not found\n";

    // using predicate comparison:
    int needle2[] = {20, 30, 50};
    it = search(haystack.begin(), haystack.end(), needle2, needle2 + 3, mypredicate);

    if (it != haystack.end())
        cout << "needle2 found at position " << (it - haystack.begin()) << '\n';
    else
        cout << "needle2 not found\n";
    // needle1 found at position 3
    // needle2 not found

    // search_n            Search range for elements:  ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Size count, const T& val);
    // ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Size count, const T& val, BinaryPredicate pred);
    int myints[] = {10, 20, 30, 30, 20, 10, 10, 20};
    vector<int> myvector(myints, myints + 8);
    vector<int>::iterator it;

    // using default comparison:
    it = search_n(myvector.begin(), myvector.end(), 2, 30);

    if (it != myvector.end())
        cout << "two 30s found at position " << (it - myvector.begin()) << '\n';
    else
        cout << "match not found\n";

    // using predicate comparison:
    it = search_n(myvector.begin(), myvector.end(), 2, 10, mypredicate);

    if (it != myvector.end())
        cout << "two 10s found at position " << int(it - myvector.begin()) << '\n';
    else
        cout << "match not found\n";
    // Two 30s found at position 2
    // Two 10s found at position 5

    //----------------------------------------Min/max----------------------------------------//
    // min	                Return the smallest:    const T& min (const T& a, const T& b, Compare comp);
    cout << "min(1,2)==" << min(1, 2) << '\n';
    cout << "min(2,1)==" << min(2, 1) << '\n';
    cout << "min('a','z')==" << min('a', 'z') << '\n';
    cout << "min(3.14,2.72)==" << min(3.14, 2.72) << '\n';
    //   min(1,2)==1
    // min(2,1)==1
    // min('a','z')==a
    // min(3.14,2.72)==2.72

    // max	                Return the largest:     const T& max (const T& a, const T& b, Compare comp);
    cout << "max(1,2)==" << max(1, 2) << '\n';
    cout << "max(2,1)==" << max(2, 1) << '\n';
    cout << "max('a','z')==" << max('a', 'z') << '\n';
    cout << "max(3.14,2.73)==" << max(3.14, 2.73) << '\n';
    //   max(1,2)==2
    // max(2,1)==2
    // max('a','z')==z
    // max(3.14,2.73)==3.14

    // minmax	            Return smallest and largest elements:   pair <const T&,const T&> minmax (const T& a, const T& b, Compare comp);
    auto result = minmax({1, 2, 3, 4, 5});
    cout << "minmax({1,2,3,4,5}): ";
    cout << result.first << ' ' << result.second << '\n';
    // minmax({1,2,3,4,5}): 1 5

    // min_element	        Return smallest element in range:    ForwardIterator min_element (ForwardIterator first, ForwardIterator last, Compare comp);
    int myints[] = {3, 7, 2, 5, 6, 4, 9};
    cout << "The smallest element is " << *min_element(myints, myints + 7, myfn) << '\n';
    cout << "The largest element is " << *max_element(myints, myints + 7, myfn) << '\n';
    // The smallest element is 2
    // The largest element is 9

    // max_element  	    Return largest element in range:    ForwardIterator max_element (ForwardIterator first, ForwardIterator last, Compare comp);

    // minmax_element	    Return smallest and largest elements in range:
    array<int, 7> foo{3, 7, 2, 9, 5, 8, 6};
    auto results = minmax_element(foo.begin(), foo.end());
    cout << "min is " << *results.first;
    cout << ", at position " << (results.first - foo.begin()) << '\n';
    cout << "max is " << *results.second;
    cout << ", at position " << (results.second - foo.begin()) << '\n';
    //     min is 2, at position 2
    // max is 9, at position 3

    //----------------------------------------Sorting----------------------------------------//
    // sort	                Sort elements in range:
    // stable_sort	        Sort elements preserving order of equivalents:
    // partial_sort	        Partially sort elements in range:
    // partial_sort_copy	Copy and partially sort range:
    // is_sorted	        Check whether range is sorted:
    // is_sorted_until	    Find first unsorted element in range:
    // nth_element	        Sort element in range:

    return 0;
}

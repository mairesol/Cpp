/*
Sets are containers that store unique elements following a specific order.

In a set, the value of an element also identifies it (the value is itself the key, of type T),
and each value must be unique. The value of the elements in a set cannot be modified once in the container (the elements are always const),
but they can be inserted or removed from the container.

Internally, the elements in a set are always sorted following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).

set containers are generally slower than unordered_set containers to access individual elements by their key,
but they allow the direct iteration on subsets based on their order.

Sets are typically implemented as binary search trees.

Container properties:
Associative
Elements in associative containers are referenced by their key and not by their absolute position in the container.

Ordered
The elements in the container follow a strict order at all times. All inserted elements are given a position in this order.

Set
The value of an element is also the key used to identify it.

Unique keys
No two elements in the container can have equivalent keys.

Allocator-aware
The container uses an allocator object to dynamically handle its storage needs.
*/

#include <iostream>
#include <list>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    // TODO: constructor
    //* empty: explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
    //* range: set(InputIterator first, InputIterator last,        const key_compare &comp = key_compare(),        const allocator_type &alloc = allocator_type());
    //* copy: set(const set &x);

    // TODO: Iterators
    //* begin	    Return iterator to beginning:
    //* end	        Return iterator to end:
    //* rbegin	    Return reverse iterator to reverse beginning:
    //* rend	    Return reverse iterator to reverse end:
    //* cbegin	    Return const_iterator to beginning:
    //* cend	    Return const_iterator to end:
    //* crbegin	    Return const_reverse_iterator to reverse beginning:
    //* crend	    Return const_reverse_iterator to reverse end:

    // TODO: Capacity
    //* empty	    Test whether container is empty:
    //* size	    Return container size:
    //* max_size	Return maximum size:

    // TODO: Modifiers
    //* insert	        Insert element:
    //* erase	        Erase elements:
    //* swap	        Swap content:
    //* clear	        Clear content:
    //* emplace	        Construct and insert element:
    //* emplace_hint	Construct and insert element with hint:

    // TODO: Observers
    //* key_comp	    Return comparison object:
    //* value_comp	    Return comparison object:

    // TODO: Operations
    //* find	        Get iterator to element:
    //* count	        Count elements with a specific value:
    //* lower_bound	    Return iterator to lower bound:
    //* upper_bound	    Return iterator to upper bound:
    //* equal_range	    Get range of equal elements:

    // TODO: Allocator
    //* get_allocator	Get allocator:

    return 0;
}
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
    return 0;
}
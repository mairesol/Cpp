/*
std::string

Strings are objects that represent sequences of characters.

The standard string class provides support for such objects with an interface similar to that
of a standard container of bytes, but adding features specifically designed to operate with strings of single-byte characters.

The string class is an instantiation of the basic_string class template that uses char (i.e., bytes)
as its character type, with its default char_traits and allocator types (see basic_string for more info on the template).

Note that this class handles bytes independently of the encoding used:
If used to handle sequences of multi-byte or variable-length characters (such as UTF-8),
all members of this class (such as length or size), as well as its iterators, will still operate in terms of bytes (not actual encoded characters).
*/

/*
Member types:
value_type: char

traits_type: char_traits<char>

allocator_type: allocator<char>

reference: char&

const_reference: const char&

pointer: char*

const_pointer: const char*

iterator: a random access iterator to char

const_iterator: a random access iterator to const char

reverse_iterator: reverse_iterator<iterator>

const_reverse_iterator: reverse_iterator<const_iterator>

difference_type: ptrdiff_t

size_type: size_t
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    /*
    constructor:
    default:                string();
    copy:                   string (const string& str);
    substring:              string (const string& str, size_t pos, size_t len = npos);
    from c-string:          string (const char* s);
    from buffer:            string (const char* s, size_t n);
    fill:                   string (size_t n, char c);
    range:                  string  (InputIterator first, InputIterator last);
    initializer list:       string (initializer_list<char> il);
    move:                   string (string&& str) noexcept;
    */
    std::string s0("Initial string");
    std::string s1;
    std::string s2(s0);
    std::string s3(s0, 8, 3);
    std::string s4("A character sequence");
    std::string s5("Another character sequence", 12);
    std::string s6a(10, 'x');
    std::string s6b(10, 42); // 42 is the ASCII code for '*'
    std::string s7(s0.begin(), s0.begin() + 7);

    std::cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
    std::cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a;
    std::cout << "\ns6b: " << s6b << "\ns7: " << s7 << '\n';
    // s1:
    // s2: Initial string
    // s3: str
    // s4: A character sequence
    // s5: Another char
    // s6a: xxxxxxxxxx
    // s6b: **********
    // s7: Initial

    /*
    Operator:
    string:                 string& operator= (const string& str);
    c-string:               string& operator= (const char* s);
    character:              string& operator= (char c);
    initializer list:       string& operator= (initializer_list<char> il);
    move:                   string& operator= (string&& str) noexcept;

    string:         string operator+ (const string& lhs, const string& rhs);
                    string operator+ (string&&      lhs, string&&      rhs);
                    string operator+ (string&&      lhs, const string& rhs);
                    string operator+ (const string& lhs, string&&      rhs);
    c-string:       string operator+ (const string& lhs, const char*   rhs);
                    string operator+ (string&&      lhs, const char*   rhs);
                    string operator+ (const char*   lhs, const string& rhs);
                    string operator+ (const char*   lhs, string&&      rhs);
    character:      string operator+ (const string& lhs, char          rhs);
                    string operator+ (string&&      lhs, char          rhs);
                    string operator+ (char          lhs, const string& rhs);
                    string operator+ (char          lhs, string&&      rhs);

    string:                 string& operator+= (const string& str);
    c-string:               string& operator+= (const char* s);
    character:              string& operator+= (char c);
    initializer list:       string& operator+= (initializer_list<char> il);

    bool operator== (const string& lhs, const string& rhs) noexcept;
    bool operator== (const char*   lhs, const string& rhs);
    bool operator== (const string& lhs, const char*   rhs);bool operator!= (const string& lhs, const string& rhs) noexcept;
    bool operator!= (const char*   lhs, const string& rhs);
    bool operator!= (const string& lhs, const char*   rhs);bool operator<  (const string& lhs, const string& rhs) noexcept;
    bool operator<  (const char*   lhs, const string& rhs);
    bool operator<  (const string& lhs, const char*   rhs);
    bool operator<= (const string& lhs, const string& rhs) noexcept;
    bool operator<= (const char*   lhs, const string& rhs);
    bool operator<= (const string& lhs, const char*   rhs);
    bool operator>  (const string& lhs, const string& rhs) noexcept;
    bool operator>  (const char*   lhs, const string& rhs);
    bool operator>  (const string& lhs, const char*   rhs);
    bool operator>= (const string& lhs, const string& rhs) noexcept;
    bool operator>= (const char*   lhs, const string& rhs);
    bool operator>= (const string& lhs, const char*   rhs);

    ostream& operator<< (ostream& os, const string& str);

    istream& operator>> (istream& is, string& str);

    istream& getline (istream&  is, string& str, char delim);
    istream& getline (istream&& is, string& str, char delim);
    istream& getline (istream&  is, string& str);
    istream& getline (istream&& is, string& str);
    */
    std::string str1, str2, str3;
    str1 = "Test string: "; // c-string
    str2 = 'x';             // single character
    str3 = str1 + str2;     // string

    std::cout << str3 << '\n';
    // Test string: x

    std::string firstlevel("com");
    std::string secondlevel("cplusplus");
    std::string scheme("http://");
    std::string hostname;
    std::string url;

    hostname = "www." + secondlevel + '.' + firstlevel;
    url = scheme + hostname;

    std::cout << url << '\n';
    // http://www.cplusplus.com

    std::string name("John");
    std::string family("Smith");
    name += " K. "; // c-string
    name += family; // string
    name += '\n';   // character

    std::cout << name;
    // John K. Smith

    std::string foo = "alpha";
    std::string bar = "beta";

    if (foo == bar)
        std::cout << "foo and bar are equal\n";
    if (foo != bar)
        std::cout << "foo and bar are not equal\n";
    if (foo < bar)
        std::cout << "foo is less than bar\n";
    if (foo > bar)
        std::cout << "foo is greater than bar\n";
    if (foo <= bar)
        std::cout << "foo is less than or equal to bar\n";
    if (foo >= bar)
        std::cout << "foo is greater than or equal to bar\n";
    // foo and bar are not equal
    // foo is less than bar
    // foo is less than or equal to bar

    std::string name;

    std::cout << "Please, enter your full name: ";
    std::getline(std::cin, name);
    std::cout << "Hello, " << name << "!\n";

    /*
    Iterators:
    begin       Return iterator to beginning:   iterator begin() noexcept;  const_iterator begin() const noexcept;

    end         Return iterator to end:   iterator end() noexcept;    const_iterator end() const noexcept;

    rbegin      Return reverse iterator to reverse beginning:  reverse_iterator rbegin() noexcept;     const_reverse_iterator rbegin() const noexcept;

    rend        Return reverse iterator to reverse end:  reverse_iterator rend() noexcept;   const_reverse_iterator rend() const noexcept;

    cbegin      Return const_iterator to beginning

    cend        Return const_iterator to end

    crbegin     Return const_reverse_iterator to reverse beginning

    crend       Return const_reverse_iterator to reverse end
    */
    std::string str("Test string");
    for (std::string::iterator it = str.begin(); it != str.end(); ++it)
        std::cout << *it;
    std::cout << '\n';

    std::string str("now step live...");
    for (std::string::reverse_iterator rit = str.rbegin(); rit != str.rend(); ++rit)
        std::cout << *rit;
    // ...evil pets won

    /*
    Capacity:
    size                Return length of string:    size_t size() const noexcept;

    length              Return length of string:  size_t length() const noexcept;

    max_size            Return maximum size of string:  size_t max_size() const noexcept;

    resize              Resize string:    void resize (size_t n);     void resize (size_t n, char c);

    capacity            Return size of allocated storage:   size_t capacity() const noexcept;

    reserve             Request a change in capacity:    void reserve (size_t n = 0);

    empty               Test if string is empty:   bool empty() const noexcept;

    shrink_to_fit       Shrink to fit:     void shrink_to_fit();
    */
    std::string str("Test string");
    std::cout << "size: " << str.size() << "\n";
    std::cout << "length: " << str.length() << "\n";
    std::cout << "capacity: " << str.capacity() << "\n";
    std::cout << "max_size: " << str.max_size() << "\n";
    // size: 11
    // length: 11
    // capacity: 15
    // max_size: 4294967291

    std::string str("I like to code in C");
    std::cout << str << '\n';

    unsigned sz = str.size();

    str.resize(sz + 2, '+');
    std::cout << str << '\n';

    str.resize(14);
    std::cout << str << '\n';
    // I like to code in C
    // I like to code in C++
    // I like to code

    std::string content;
    std::string line;
    std::cout << "Please introduce a text. Enter an empty line to finish:\n";
    do
    {
        getline(std::cin, line);
        content += line + '\n';
    } while (!line.empty());
    std::cout << "The text you introduced was:\n"
              << content;

    /*
    Element access:
    operator[]      Get character of string:  char& operator[] (size_t pos);  const char& operator[] (size_t pos) const;

    at              Get character in string:  char& at (size_t pos);  const char& at (size_t pos) const;

    front           Access first character:   char& front();    const char& front() const;

    back            Access last character:  char& back();   const char& back() const;

    data            Get string data:    const char* data() const noexcept;
    */
    std::string str("test string");
    str.front() = 'T';
    std::cout << str << '\n';
    // Test string

    std::string str("hello world.");
    str.back() = '!';
    std::cout << str << '\n';
    //   hello world!

    std::string str = "Test string";
    char *cstr = "Test string";

    if (str.length() == std::strlen(cstr))
    {
        std::cout << "str and cstr have the same length.\n";

        if (memcmp(cstr, str.data(), str.length()) == 0)
            std::cout << "str and cstr have the same content.\n";
    }
    // str and cstr have the same length.
    // str and cstr have the same content.

    /*
    Modifiers:
    append          Append to string:       string:     string& append (const string& str);
                                            substring:  string& append (const string& str, size_t subpos, size_t sublen);
                                            c-string:   string& append (const char* s);
                                            buffer:     string& append (const char* s, size_t n);
                                            fill:   string& append (size_t n, char c);
                                            range:  string& append (InputIterator first, InputIterator last);
                                            initializer list:   string& append (initializer_list<char> il);

    push_back       Append character to string:    void push_back (char c);

    pop_back        Delete last character:     void pop_back();

    assign          Assign content to string:       string:     string& assign (const string& str);
                                                    substring:  string& assign (const string& str, size_t subpos, size_t sublen);
                                                    c-string:   string& assign (const char* s);
                                                    buffer:     string& assign (const char* s, size_t n);
                                                    fill:   string& assign (size_t n, char c);
                                                    range:   string& assign (InputIterator first, InputIterator last);
                                                    initializer list:    string& assign (initializer_list<char> il);
                                                    move:   string& assign (string&& str) noexcept;

    insert          Insert into string:     string:      string& insert (size_t pos, const string& str);
                                            substring:   string& insert (size_t pos, const string& str, size_t subpos, size_t sublen);
                                            c-string:    string& insert (size_t pos, const char* s);
                                            buffer:      string& insert (size_t pos, const char* s, size_t n);
                                            single character:   iterator insert (const_iterator p, char c);
                                            fill:    string& insert (size_t pos, size_t n, char c);   iterator insert (const_iterator p, size_t n, char c);
                                            range:  iterator insert (iterator p, InputIterator first, InputIterator last);
                                            initializer list:    string& insert (const_iterator p, initializer_list<char> il);

    erase           Erase characters from string:       sequence:    string& erase (size_t pos = 0, size_t len = npos);
                                                        character:  iterator erase (const_iterator p);
                                                        range:  iterator erase (const_iterator first, const_iterator last);

    clear           Clear string:  void clear() noexcept;

    replace         Replace portion of string:      string:     string& replace (size_t pos, size_t len, const string& str);    string& replace (const_iterator i1, const_iterator i2, const string& str);
                                                    substring:  string& replace (size_t pos, size_t len, const string& str, size_t subpos, size_t sublen);
                                                    c-string:   string& replace (size_t pos, size_t len, const char* s);    string& replace (const_iterator i1, const_iterator i2, const char* s);
                                                    buffer:     string& replace (size_t pos, size_t len, const char* s, size_t n);    string& replace (const_iterator i1, const_iterator i2, const char* s, size_t n);
                                                    fill:   string& replace (size_t pos, size_t len, size_t n, char c);    string& replace (const_iterator i1, const_iterator i2, size_t n, char c);
                                                    range:  string& replace (const_iterator i1, const_iterator i2, InputIterator first, InputIterator last);
                                                    initializer list:   string& replace (const_iterator i1, const_iterator i2, initializer_list<char> il);

    swap            Swap string values:     void swap (string& str);
    */
    std::string str;
    std::string str2 = "Writing ";
    std::string str3 = "print 10 and then 5 more";

    str.append(str2);                         // "Writing "
    str.append(str3, 6, 3);                   // "10 "
    str.append("dots are cool", 5);           // "dots "
    str.append("here: ");                     // "here: "
    str.append(10u, '.');                     // ".........."
    str.append(str3.begin() + 8, str3.end()); // " and then 5 more"
    str.append(5, 0x2E);                      // "....."
    // Writing 10 dots here: .......... and then 5 more.....

    std::string str;
    std::string base = "The quick brown fox jumps over a lazy dog.";

    str.assign(base);
    std::cout << str << '\n';

    str.assign(base, 10, 9);
    std::cout << str << '\n';

    str.assign("pangrams are cool", 7);
    std::cout << str << '\n';

    str.assign("c-string");
    std::cout << str << '\n';

    str.assign(10, '*');
    std::cout << str << '\n';

    str.assign(10, 0x2D);
    std::cout << str << '\n';

    str.assign(base.begin() + 16, base.end() - 12);
    std::cout << str << '\n';
    // The quick brown fox jumps over a lazy dog.
    // brown fox
    // pangram
    // c-string
    // **********
    // ----------
    // fox jumps over

    std::string str = "to be question";
    std::string str2 = "the ";
    std::string str3 = "or not to be";
    std::string::iterator it;

    // used in the same order as described above:
    str.insert(6, str2);                                // to be (the )question
    str.insert(6, str3, 3, 4);                          // to be (not )the question
    str.insert(10, "that is cool", 8);                  // to be not (that is )the question
    str.insert(10, "to be ");                           // to be not (to be )that is the question
    str.insert(15, 1, ':');                             // to be not to be(:) that is the question
    it = str.insert(str.begin() + 5, ',');              // to be(,) not to be: that is the question
    str.insert(str.end(), 3, '.');                      // to be, not to be: that is the question(...)
    str.insert(it + 2, str3.begin(), str3.begin() + 3); // (or )

    std::cout << str << '\n';
    // to be, or not to be: that is the question...

    std::string str("This is an example sentence.");
    std::cout << str << '\n';

    str.erase(10, 8);
    std::cout << str << '\n';

    str.erase(str.begin() + 9);
    std::cout << str << '\n';

    str.erase(str.begin() + 5, str.end() - 9);
    std::cout << str << '\n';
    // This is an example sentence.
    // This is an sentence.
    // This is a sentence.
    // This sentence.

    std::string base = "this is a test string.";
    std::string str2 = "n example";
    std::string str3 = "sample phrase";
    std::string str4 = "useful.";

    // Using positions:                 0123456789*123456789*12345
    std::string str = base;           // "this is a test string."
    str.replace(9, 5, str2);          // "this is an example string." (1)
    str.replace(19, 6, str3, 7, 6);   // "this is an example phrase." (2)
    str.replace(8, 10, "just a");     // "this is just a phrase."     (3)
    str.replace(8, 6, "a shorty", 7); // "this is a short phrase."    (4)
    str.replace(22, 1, 3, '!');       // "this is a short phrase!!!"  (5)
    std::cout << str << '\n';
    // this is a short phrase!!!

    // Using iterators:                                               0123456789*123456789*
    str.replace(str.begin(), str.end() - 3, str3);                      // "sample phrase!!!"      (1)
    str.replace(str.begin(), str.begin() + 6, "replace");               // "replace phrase!!!"     (3)
    str.replace(str.begin() + 8, str.begin() + 14, "is coolness", 7);   // "replace is cool!!!"    (4)
    str.replace(str.begin() + 12, str.end() - 4, 4, 'o');               // "replace is cooool!!!"  (5)
    str.replace(str.begin() + 11, str.end(), str4.begin(), str4.end()); // "replace is useful."    (6)
    std::cout << str << '\n';
    // replace is useful.

    std::string buyer("money");
    std::string seller("goods");

    std::cout << "Before the swap, buyer has " << buyer;
    std::cout << " and seller has " << seller << '\n';

    seller.swap(buyer);

    std::cout << " After the swap, buyer has " << buyer;
    std::cout << " and seller has " << seller << '\n';
    //  Before the swap, buyer has money and seller has goods
    //  After the swap, buyer has goods and seller has money

    /*
    Others:
    c_str                   Get C string equivalent:   const char* c_str() const noexcept;

    copy                    Copy sequence of characters from string:     size_t copy (char* s, size_t len, size_t pos = 0) const;

    find                    Find content in string:     string:  size_t find (const string& str, size_t pos = 0) const noexcept;
                                                        c-string:    size_t find (const char* s, size_t pos = 0) const;
                                                        buffer:  size_t find (const char* s, size_t pos, size_type n) const;
                                                        character:   size_t find (char c, size_t pos = 0) const noexcept;

    rfind                   Find last occurrence of content in string

    find_first_of           Find character in string:  string:  size_t find_first_of (const string& str, size_t pos = 0) const noexcept;
                                                c-string:    size_t find_first_of (const char* s, size_t pos = 0) const;
                                                buffer:  size_t find_first_of (const char* s, size_t pos, size_t n) const;
                                                character:   size_t find_first_of (char c, size_t pos = 0) const noexcept;

    find_last_of            Find character in string from the end

    find_first_not_of       Find absence of character in string

    find_last_not_of        Find non-matching character in string from the end

    substr                  Generate substring:   string substr (size_t pos = 0, size_t len = npos) const;

    compare                 Compare strings:    string:  int compare (const string& str) const noexcept;
                                                substrings:  int compare (size_t pos, size_t len, const string& str) const;  int compare (size_t pos, size_t len, const string& str, size_t subpos, size_t sublen) const;
                                                c-string:    int compare (const char* s) const;  int compare (size_t pos, size_t len, const char* s) const;
                                                buffer:  int compare (size_t pos, size_t len, const char* s, size_t n) const;
    */
    std::string str("Please split this sentence into tokens");

    char *cstr = new char[str.length() + 1];
    std::strcpy(cstr, str.c_str());

    // cstr now contains a c-string copy of str

    char *p = std::strtok(cstr, " ");
    while (p != 0)
    {
        std::cout << p << '\n';
        p = std::strtok(NULL, " ");
    }
    delete[] cstr;
    // Please
    // split
    // this
    // sentence
    // into
    // tokens

    char buffer[20];
    std::string str("Test string...");
    std::size_t length = str.copy(buffer, 6, 5);
    buffer[length] = '\0';
    std::cout << "buffer contains: " << buffer << '\n';
    // buffer contains: string

    std::string str("There are two needles in this haystack with needles.");
    std::string str2("needle");

    std::size_t found = str.find(str2);
    if (found != std::string::npos)
        std::cout << "first 'needle' found at: " << found << '\n';

    found = str.find("needles are small", found + 1, 6);
    if (found != std::string::npos)
        std::cout << "second 'needle' found at: " << found << '\n';

    found = str.find("haystack");
    if (found != std::string::npos)
        std::cout << "'haystack' also found at: " << found << '\n';

    found = str.find('.');
    if (found != std::string::npos)
        std::cout << "Period found at: " << found << '\n';

    // let's replace the first needle:
    str.replace(str.find(str2), str2.length(), "preposition");
    std::cout << str << '\n';

    std::string str("The sixth sick sheik's sixth sheep's sick.");
    std::string key("sixth");

    std::size_t found = str.rfind(key);
    if (found != std::string::npos)
        str.replace(found, key.length(), "seventh");
    std::cout << str << '\n';
    // The sixth sick sheik's seventh sheep's sick.

    std::string str("Please, replace the vowels in this sentence by asterisks.");
    std::size_t found = str.find_first_of("aeiou");
    while (found != std::string::npos)
    {
        str[found] = '*';
        found = str.find_first_of("aeiou", found + 1);
    }

    std::cout << str << '\n';
    // Pl**s*, r*pl*c* th* v*w*ls *n th*s s*nt*nc* by *st*r*sks.

    std::string str1("/usr/bin/man");
    std::cout << "Splitting: " << str << '\n';
    std::size_t found = str.find_last_of("/\\");
    std::cout << " path: " << str.substr(0, found) << '\n';
    std::cout << " file: " << str.substr(found + 1) << '\n';
    //  Splitting: /usr/bin/man
    //  path: /usr/bin
    //  file: man

    std::string str("look for non-alphabetic characters...");

    std::size_t found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");

    if (found != std::string::npos)
    {
        std::cout << "The first non-alphabetic character is " << str[found];
        std::cout << " at position " << found << '\n';
    }
    // The first non-alphabetic character is - at position 12

    std::string str("Please, erase trailing white-spaces   \n");
    std::string whitespaces(" \t\f\v\n\r");

    std::size_t found = str.find_last_not_of(whitespaces);
    if (found != std::string::npos)
        str.erase(found + 1);
    else
        str.clear(); // str is all whitespace

    std::cout << '[' << str << "]\n";
    // [Please, erase trailing white-spaces]

    std::string str = "We think in generalities, but we live in details.";
    // (quoting Alfred N. Whitehead)

    std::string str2 = str.substr(3, 5); // "think"

    std::size_t pos = str.find("live"); // position of "live" in str

    std::string str3 = str.substr(pos); // get from "live" to the end

    std::cout << str2 << ' ' << str3 << '\n';
    // think live in details.

    std::string str1("green apple");
    std::string str2("red apple");

    if (str1.compare(str2) != 0)
        std::cout << str1 << " is not " << str2 << '\n';

    if (str1.compare(6, 5, "apple") == 0)
        std::cout << "still, " << str1 << " is an apple\n";

    if (str2.compare(str2.size() - 5, 5, "apple") == 0)
        std::cout << "and " << str2 << " is also an apple\n";

    if (str1.compare(6, 5, str2, 4, 5) == 0)
        std::cout << "therefore, both are apples\n";
    // green apple is not red apple
    // still, green apple is an apple
    // and red apple is also an apple
    // therefore, both are apples

    /*
    Functions:
    stod            Convert string to double:   double stod (const string&  str, size_t* idx = 0);  double stod (const wstring& str, size_t* idx = 0);

    stof            Convert string to float:    float stof (const string&  str, size_t* idx = 0);   float stof (const wstring& str, size_t* idx = 0);

    stoi            Convert string to integer:  int stoi (const string&  str, size_t* idx = 0, int base = 10);  int stoi (const wstring& str, size_t* idx = 0, int base = 10);

    stol            Convert string to long int:    long stol (const string&  str, size_t* idx = 0, int base = 10);  long stol (const wstring& str, size_t* idx = 0, int base = 10);

    stold           Convert string to long double:  long double stold (const string&  str, size_t* idx = 0);    long double stold (const wstring& str, size_t* idx = 0);

    stoll           Convert string to long long:    long long stoll (const string&  str, size_t* idx = 0, int base = 10);   long long stoll (const wstring& str, size_t* idx = 0, int base = 10);

    stoul           Convert string to unsigned long integer:     unsigned long stoul (const string&  str, size_t* idx = 0, int base = 10);   unsigned long stoul (const wstring& str, size_t* idx = 0, int base = 10);

    stoull          Convert string to unsigned long long:   unsigned long long stoull (const string&  str, size_t* idx = 0, int base = 10);     unsigned long long stoull (const wstring& str, size_t* idx = 0, int base = 10);

    to_string       Convert numerical value to string:      string to_string (int val);     string to_string (long val);    string to_string (long long val);
                                                            string to_string (unsigned val);     string to_string (unsigned long val);   string to_string (unsigned long long val);
                                                    s       tring to_string (float val);  string to_string (double val);   string to_string (long double val);

    to_wstring      Convert numerical value to wide string
    */

    std::string orbits("365.24 29.53");
    std::string::size_type sz1; // alias of size_t

    double earth = std::stod(orbits, &sz1);
    double moon = std::stod(orbits.substr(sz1));
    std::cout << "The moon completes " << (earth / moon) << " orbits per Earth year.\n";
    // The moon completes 12.3684 orbits per Earth year.

    std::string orbits("686.97 365.24");
    std::string::size_type sz2; // alias of size_t

    float mars = std::stof(orbits, &sz2);
    float earth = std::stof(orbits.substr(sz2));
    std::cout << "One martian year takes " << (mars / earth) << " Earth years.\n";
    // One martian year takes 1.88087 Earth years.

    std::string str_dec = "2001, A Space Odyssey";
    std::string str_hex = "40c3";
    std::string str_bin = "-10010110001";
    std::string str_auto = "0x7f";

    std::string::size_type sz3; // alias of size_t

    int i_dec = std::stoi(str_dec, &sz3);
    int i_hex = std::stoi(str_hex, nullptr, 16);
    int i_bin = std::stoi(str_bin, nullptr, 2);
    int i_auto = std::stoi(str_auto, nullptr, 0);

    std::cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
    std::cout << str_hex << ": " << i_hex << '\n';
    std::cout << str_bin << ": " << i_bin << '\n';
    std::cout << str_auto << ": " << i_auto << '\n';
    // 2001, A Space Odyssey: 2001 and [, A Space Odyssey]
    // 40c3:  16579
    // -10010110001: -1201
    // 0x7f: 127

    std::string pi = "pi is " + std::to_string(3.1415926);
    std::string perfect = std::to_string(1 + 2 + 4 + 7 + 14) + " is a perfect number";
    std::cout << pi << '\n';
    std::cout << perfect << '\n';
    // pi is 3.141593
    // 28 is a perfect number
    return 0;
}

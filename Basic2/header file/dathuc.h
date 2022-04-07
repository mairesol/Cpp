#ifndef _DATHUC_H
#define _DATHUC_H
#include <iostream>
using std::istream;
using std::ostream;
class dathuc
{friend ostream &operator<<(ostream & , const dathuc &);
 friend istream &operator>>(istream & , dathuc &);
 public:
    dathuc (int );
    ~dathuc()
    {delete [] ptr;
    }
    dathuc ( const dathuc & );
    const dathuc &operator=(const dathuc &);
    bool operator==(const dathuc &right )
    {if ( bacdathuc != right.bacdathuc ) return false ;
     else for ( int i = 0 ; i <= bacdathuc ; i++)
             if ( ptr[i] != right.bacdathuc ) return false ;
     return true ;
    }
    bool operator!=(const dathuc &right)
    {return !(*this == right ) ;
    }
    dathuc operator+(const dathuc &) ;
    dathuc operator-(const dathuc &) ;
    dathuc operator*(const dathuc &);
    dathuc operator/(const dathuc &);
 private:
    int *ptr;
    int bacdathuc ;
};
#endif

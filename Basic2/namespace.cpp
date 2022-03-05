#include <iostream>
using namespace std;

// Đây là namespace dau_tien
namespace dau_tien{
   void ham(){
      cout << "Ben trong namespace dau_tien" << endl;
   }
}
// Đây là namespace thu_hai
namespace thu_hai{
   void ham(){
      cout << "Ben trong namespace thu_hai" << endl;
   }
}
int main ()
{
 
   // Gọi hàm từ namespace dau_tien.
   dau_tien::ham();
   
   // Gọi hàm từ namespace thu_hai.
   thu_hai::ham(); 
   return 0;
}
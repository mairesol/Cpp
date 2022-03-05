/*
Sau khi quan sát nhân tình thế thái, Bình rút ra 3 chân lý.

1. "Mấy đứa trẻ trung đều đẹp cả"

2. "Mấy đứa đẹp đều có người yêu"

3. "Mấy đứa không đẹp mà cũng có người yêu chắc chắn là vì nó giàu"

Cho 4 biến logic tre_trung, xinh_dep, co_gau, giau_co. Tương ứng với giá trị của các mệnh đề

1. Bạn X trẻ trung

2. Bạn X xinh đẹp

3. Bạn X có người yêu

4. Bạn X giàu có

Viết chương trình kiểm tra xem X có thoã các chân lý mà Bình quan sát được không

INPUT
4 biến logic như mô tả

OUTPUT
Giá trị 0 nếu 4 biến trên không thoã mãn các chân lý của Bình

Giá trị 1 nếu 4 biến trên thoã mãn
*/
#include <iostream>

using namespace std;

int main()
{

    bool tre, dep, loved, giau;
    cin >> tre >> dep >> loved >> giau;
    cout << ((((tre == 1 && dep == 1) || tre == 0) && ((dep == 1 || giau == 1) && loved == 1)) || (tre == 0 && dep == 0 && loved == 0 && giau == 0) || (tre == 0 && dep == 0 && loved == 0 && giau == 1));
    return 0;
}

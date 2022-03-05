/*
Các nhà địa chất có nhiệm vụ khảo sát tìm khoáng sản ở một vùng đài nguyên mênh mông.
Thiết bị và nhu yếu phẩm được chở tới trại Trung tâm tại điểm có tọa độ (0, 0) trên bản đồ.
Nhóm khảo sát đi thăm dò từng điểm có tọa nguyên trên bản đồ. Nhóm di chuyển từ điểm có tọa độ nguyên này
tới điểm có tọa độ nguyên khác và luôn đi theo một trong các hướng “Đông”(-4), “Tây” (-2), “Nam” (-3) hoặc “Bắc” (-1).
Việc đổi hướng có thể được thực hiện tại các điểm có tọa độ nguyên. Khoảng cách bằng một đơn vị tọa độ được gọi là bước.
Đường đi của họ được thiết bị tự động mang theo báo về theo từng cặp số bước di chuyển và hướng.
Ví dụ, dòng thông báo “7 -1 5 -4 2 -3 3 -4” cho biết nhóm đã đi 7 bước theo hướng Bắc, sau đó đi 5 bước về hướng đông, đi tiếp theo hướng bắc 2 bước rồi đi theo hướng đông 3 bước.

Có thể tại một nơi nào đó nhóm tìm thấy những mẫu vật đặc biệt, cần phân tích ngay để có hành động phù hợp tiếp theo
và yêu cầu Trung tâm gửi thiết bị bay tới lấy về. Các thiết bị bay mang theo chỉ được lập trình cho
đường bay theo các hướng Đông, Tây, Nam, Bắc vì bay theo các hướng khác ở nơi địa hình lạ thì rất dễ bay lạc đường do vùng này chưa phủ sóng GPS.

Khi nạp thông báo về hành trình của nhóm khảo sát vào bộ nhớ, các microchips trong máy bay sẽ tính toán, tìm đường đi có biểu diễn dưới dạng của thiết bị ghi nhận đường đi đã nói ở trên là ngắn nhất. Có nhiều cách ngắn nhất để đi tới đích. Hãy xác định một trong số các xâu biểu diễn đường đi do thiết bị bay tạo ra. Đảm bảo đích cần tới không trùng với gốc tọa độ.

INPUT
Một dãy số xác định hành trình của nhóm khảo sát. Các khoảng cách có giá trị nguyên dương và không vượt quá mười triệu.

OUTPUT
Biểu diễn đường đi do thiết bị bay tạo ra. Nếu có nhiều dạng biểu diễn thì xuất cái nào cũng được.

VD:

INPUT	                                                        OUTPUT
7 -1 5 -4 2 -3 3 -4                                             5 -1 8 -4

6 -1 8 -1 3 -4 6 -1 9 -1 2 -4 2 -4 6 -4 6 -4 4 -1               33 -1 19 -4

*/
#include <iostream>
#include <math.h>
using namespace std;

int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int do_dai;
    int doc = 0, ngang = 0;
    int bien_tam;
    while (cin >> bien_tam)
    {
        //Bước đi:
        if (bien_tam > 0)
            do_dai = bien_tam;
        // Đọc hướng:
        if (bien_tam < 0)
        {
            switch (bien_tam)
            {
            case -1: // Bắc
                doc += do_dai;
                break;
            case -3: // Nam
                doc -= do_dai;
                break;
            case -2: // Tây
                ngang += do_dai;
                break;
            case -4: // Đông
                ngang -= do_dai;
                break;
            default:
                break;
            }
        }
        if (bien_tam == 0)
            break;
    }
    // Xuất kết quả
    // Xét chiều bắc nam
    if (doc > 0)
        cout << abs(doc) << " " << -1 << " ";
    if (doc < 0)
        cout << abs(doc) << " " << -3 << " ";
    // Xét chiều tây đông

    if (ngang > 0)
        cout << abs(ngang) << " " << -2;
    if (ngang < 0)
        cout << abs(ngang) << " " << -4;
    return 0;
}
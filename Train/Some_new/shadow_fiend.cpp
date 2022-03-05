/*Trong dota 2, Shadow fiend là một tướng có chỉ số ban đầu khá thấp tuy nhiên vị tướng này lại có khả năng control lane cực kì kinh ngạc, nhất là khi
nó được giao cho nhiệm vụ solo mid. Được hỗ trợ bởi kĩ năng Necromastery, cho hắn một lượng sát thương rất khủng vào đầu game, khiến cho Shadow Fiend 
trở thành một ganker và initiator "khủng" dưới bàn tay của các game thủ chuyên nghiệp. Một trong những skill đặc trưng của shadowfiend là Necromastery.
Chiêu này cho phép shadowfiend hút hồn của các con lính (creep) mà hắn đã giết, mỗi linh hồn hút được tăng sát thương (damage) của shadow fiend lên 
từ 2 đến 5 đơn vị (tùy cách hắn chọn skill). Để tập chơi shadowfiend, bạn Bình vào chế độ test mode. Trong đó có một con shadowfiend max level với lượng 
sát thương khi chưa hút được hồn nào là x và lượng sát thương tăng thêm khi hút một hồn là y. Trong rừng có sẵn n con creep, mỗi con có một lượng máu là m.
Giả sử Bình cho shadowfiend đánh chay, không cast thêm bất cứ skill nào khác thì sao bao nhiêu hit shadowfiend mới giết hết được số creep trên?

Input
Bốn số nguyên dương, cách nhau bởi khoảng trắng

Output
Một số nguyên

*/

#include <iostream>
using namespace std;

int main()
{
    int dame, increase_dame, creep_figures, creep_hp;
    float hits = 0;
    cin >> dame >> increase_dame >> creep_figures >> creep_hp;
    for (int i = 1; i <= creep_figures; i++)
    {
        if (dame < creep_hp)
        {
            if (creep_hp % dame == 0)
            {
                hits += (creep_hp / dame);
            }
            else
            {
                hits += (creep_hp / dame) + 1;
            }
        }
        else
        {
            hits += 1;
        }
        dame += increase_dame;
    }
    cout << hits << endl;
    return 0;
}
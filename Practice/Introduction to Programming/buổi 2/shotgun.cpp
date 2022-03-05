/*Bạn Bình cầm đầu cả team đi thi đấu giải vô địch Counter-strike toàn quốc. Team của Bình rất mạnh nên Bình thích "show-off",
nếu trong game này người chơi chuyên nghiệp thường chọn súng trường (rifle) thì Bình lại đi bắn shotgun.
Shotgun có ưu điểm là sát thương cao, bắn trúng gần như chết chắc nhưng ngược điểm tầm bắn ngắn và bắn rất chậm.
Hộc đạn shotgun chứa được m viên, bắn một viên mất r giây. Shotgun có 02 cách nạp đạn là thay nguyên hộc đạn mới mất c giây
hoặc nạp từng viên một vào hộc đạn cũ, mỗi viên nạp mất b giây.
Bằng kinh nghiệm chơi lâu năm khéo léo của mình Bình đã vòng ra được sau lưng team địch với một khẩu shotgun đầy đạn.
Tất cả n tên địch không để ý tới Bình. Bạn hãy tính toán xem nếu Bình bắn bách phát bách trúng và thì cần tối thiểu bao nhiêu giây để hạ hết toàn bộ team địch.

INPUT
05 số nguyên không âm b, c, m, n, r trên một hàng, cách nhau bởi khoảng trắng
b: reload_one, c: reload_all, m: ammo, n: enemies, r: shoot_time 
OUTPUT
Thời gian cần thiết để Bình diệt hết địch

VD:
1 1 2 3 1	4
1 1 2 3 2	7
1 3 5 7 2	16
1 3 5 7 1	9
1 3 5 17 3	59
2 3 5 17 3	60

*/

#include <iostream>
using namespace std;

int main()
{
    int reload_one, reload_all, ammo, enemies, shoot_time;
    cin >> reload_one >> reload_all >> ammo >> enemies >> shoot_time;
    int part_time;
    int kill_time;
    // Xet thoi gian giet tung top dich tuong ung voi so dan
    if (reload_one * ammo > reload_all)
        part_time = reload_all + shoot_time * ammo;
    else
        part_time = (reload_one + shoot_time) * ammo;

    // Tim so luong top dich tuong ung so dan
    int enemies_parts = enemies / ammo;

    // Tim so luong dich con lai ( < ammo )
    int enemies_others = enemies % ammo;

    // Thoi gian toi thieu (ban dau khong can nap dan )
    if ((enemies_others * (reload_one + shoot_time)) > (reload_all + enemies_others * shoot_time))
        kill_time = shoot_time * ammo + part_time * (enemies_parts - 1) + (reload_all + enemies_others * shoot_time);
    else
        kill_time = shoot_time * ammo + part_time * (enemies_parts - 1) + (enemies_others * (reload_one + shoot_time));
    cout << kill_time;
    return 0;
}
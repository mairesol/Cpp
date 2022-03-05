/*Viper là một heroes khá khó chịu trong Dota2 với có thể chơi ở cả vị trí carry hoặc ganker nhờ vào skill độc đáo của mình. Skill đầu tiên là Posion attack
cho phép mỗi đòn tấn công của viper sẽ làm đối thủ chậm đi tới 40% trong vòng 2 giây. Để tránh tình trạng quá imbalance thì thời gian bị slow sau mỗi lần
đòn tấn công của viper sẽ không được cộng dồn, ví dụ nếu đối thủ đang trong trạng thái bị làm chậm, còn 01 giây nữa sẽ hết bị làm chậm; thì đòn tấn công tiếp
theo sẽ đưa thời gian bị làm chậm của đối thủ trở về mức 02 giây.

INPUT
Một dãy số thực. Đây là các thời điểm một tướng bị viper tấn công tính bằng giây kể từ lúc bắt đầu game. Input kết thúc bằng số -1

OUTPUT
Tổng thời gian tướng bị làm chậm, tính bằng giây.

*/

#include <iostream>
using namespace std;
double plus_slow_time(double now, double before)
{
    if (before == -1.0)
        return 0.0;
    if (now - before >= 2.0 || now - before < 0.0)
        return 2.0;
    else
        return now - before;
}
int main()
{
    double slow_time = 0.0;
    double now;
    double before = -1.0;
    while (true)
    {
        cin >> now;
        slow_time += plus_slow_time(now, before);
        if (now == -1.0)
            break;
        before = now;
    }
    cout << slow_time;
    return 0;
}

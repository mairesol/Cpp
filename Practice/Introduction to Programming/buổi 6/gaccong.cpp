/*
Bạn Bình gia cảnh khó khăn nhưng đam mê tập tạ. Để có tiền tập tạ, hàng đêm bạn Bình đi làm ma cô gác cửa cho vũ trường Heaven.
Vũ trường heaven rất là đắt khách chưa mở cửa đã có khách đứng xếp hàng đầy. Quản lý vũ trường yêu cầu Bình
phải tính toán sao đó sao cho khi vũ trường đầy khách thì số nam với số nữ phải xấp xỉ nhau.
Bình chỉ được cho khách xếp hàng vào theo từng người một (không cần quan tâm khách có đi thành nhóm hay không, vũ trường này rất là chảnh),
tuy nhiên không phải lúc nào người xếp đầu hàng cũng được vào trước mà khi hứng lên Bình có thể cho người đứng thứ nhì trong hàng vào trước,
nói chung Bình có căn bản tập tạ từ nhỏ nên hoàn toàn có thể xử lý được vị khách đứng đầu, miễn sao cân đối được số lượng nam và nữ đi vào vũ trường.

Xui một cái là Bình giỏi tập tạ nhưng không thông minh lắm nên khả năng ghi nhớ các con số của Bình là có giới hạn.
Khi số lượng chênh lệch giữa khách nam và nữ đã vào vũ trường là quá lớn Bình sẽ bị rối não và bạn ấy sẽ thông báo là vũ trường đã hết chỗ và đuổi khách về (Bình cũng rất là chảnh).

Input
Hàng đầu tiên chứa một số nguyên dương X<100 đây con số chênh lệch giữa lượng khách nam và nữ lớn nhất mà Bình nhớ được.

Tiếp theo là một dãy số 0 và 1 cách nhau bởi các khoảng trắng. Dãy này chứa không quá 101 số và kết thúc bằng số -1.
Dãy này mô tả hàng người đang chờ trước vũ trường, số 0 là khách nam, số 1 là khách nữ và con số đầu tiên bên tay trái đại diện cho người đầu tiên trong hàng.

Ở đây chúng ta cũng giả sử là vũ trường chứa được hết tất cả người đang đứng trong hàng.

Output
Số khách tối đa Bình sẽ cho vào vũ trường mà không quên mất con số chênh lệch giữa nam và nữ

INPUT                               OUTPUT
1                                   9
0 1 1 0 1 0 0 1 0 -1

2                                   8
1 0 0 0 0 1 1 0 0 0 1 1 0 1 -1

*/
#include <iostream>
#include <math.h>
using namespace std;

int count_element(int A[10000], int n, int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == x)
            cnt++;
    }
    return cnt;
}
int count_and_check_diff(int A[10000], int n, int diff)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt++;
        int men = count_element(A, i + 1, 0);
        int women = count_element(A, i + 1, 1);
        // cout << men << " " << women << endl;
        if (men - women == diff && A[i + 1] == A[i + 2] && A[i + 1] == 0)
            break;
        else if (women - men == diff && A[i + 1] == A[i + 2] && A[i + 1] == 1)
            break;
    }
    return cnt;
}
int main()
{
    int diff;
    cin >> diff;
    int A[10000];
    int length = 0;
    while (true)
    {
        cin >> A[length];
        if (A[length] == -1)
            break;
        length++;
    }
    cout << count_and_check_diff(A, length, diff);
    return 0;
}

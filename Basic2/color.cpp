#include <windows.h>

void setcolor(WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return;
}
void setForeGroundAndBackGroundColor(int ForeGroundColor, int BackGroundColor)
{
    int color = 16 * BackGroundColor + ForeGroundColor;
    setcolor(color);
}

int main()
{
    return 0;
}
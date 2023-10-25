#include"WriteIn.h"

ll read(std::string s,int& pos)
{
    ll x = 0, f = 1;
    char ch = s[pos++];
    while (ch < '0' || ch>'9')
    {
        if (ch == '-')
            f = -1;
        ch = s[pos++];
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = s[pos++];
    return x * f;
}
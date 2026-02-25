#include <iostream>
using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int max=-1;
        int x=-1;
        for (int i=0;i<s.length();i++)
            {
                if (s[i]>='0'&&s[i]<='9')
                {
                    if (s[i]>max)
                        max=s[i];
                }
            }
        for (int i=0;i<s.length();i++)
        {
            if (s[i]>='0'&&s[i]<='9'&&s[i]<max)
                {
                    if (s[i]>x)
                        x=s[i];
                }
        }
        if (x!=-1) x-='0';
        return x;
    }
};
int main()
{
    Solution s;
    cout<<s.secondHighest("dfa12321afd")<<endl;
    cout<<s.secondHighest("abc1111");
    return 0;
}
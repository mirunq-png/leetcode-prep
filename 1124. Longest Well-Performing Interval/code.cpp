#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> v(hours.size()+2,-1); // max -n-1 -> n+2 sz
        int l=0,s=0;
        for (int i=0;i<hours.size();i++)
            {
                if (hours[i]>8)
                    s+=1;
                else s+=-1;
                if (s>0) // tiring>non-tiring direct
                    l=i+1;
                else // s<=0
                {
                    // cautam s-1 => -(1-s) ca sa fie pozitiv
                    if (v[1-s]!=-1&&1-s<=hours.size())
                    {
                        if (i-v[1-s]>=l) // intervalul
                            l=i-v[1-s];
                    }
                    if (v[-s]==-1) // neinitializat
                        v[-s]=i; // prima zi
                }
                
            }
        // for (int i=0;i<v.size();i++)
        //     cout<<v[i]<<" ";
    return l;
    }
    
};

int main()
{
    vector<int> hrs={9,9,6,0,6,6,9};
    Solution s;
    cout<<s.longestWPI(hrs);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
// first brute force attempt:
// class Solution {
// private:
//     void sort (string& s)
//     {
//         for (int i=0;i<s.length();i++)
//             for (int j=0;j<s.length()-1;j++)
//             {
//                 if (s[i]<s[j])
//                     swap(s[i],s[j]);
//             }
//     }
// public:
//     int lengthOfLongestSubstring(string s) {
//         string sol="";
//         string subs="";
//         for (int i=0;i<s.length();i++)
//         {
//             for (int j=i+1;j<=s.length();j++)
//             {
//                 subs=s.substr(i,j-i);
//                 string aux=subs;
//                 sort(aux); 
//                 int ok=1;
//                 for (int k=0;k<aux.length()-1&&ok==1;k++)
//                     {
//                         if (aux[k]==aux[k+1])
//                             ok=0;
//                     }
//                 if (ok==1)
//                     {
//                         if (subs.length()>sol.length())
//                             sol=subs;
//                     }
//         }
//     }
//     return sol.length();
//     }
// };
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>ascii(128,-1); // toate val ascii, cu pozitiile lor
        int l=0,r,maxx=0;
        for (int r=0;r<s.length();r++)
        {
            char crt=s[r]; // caracterul crt
            if (ascii[crt]>=l)
                l=ascii[crt]+1;
            ascii[crt]=r; // actualizam pozitia
            if (r-l+1>maxx)
                maxx=r-l+1;
        }
        return maxx;
    }
};
int main()
{
    return 0;
}
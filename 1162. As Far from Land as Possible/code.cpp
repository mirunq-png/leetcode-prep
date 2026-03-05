#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        const int inf=10000;
        // colt din stanga sus -> colt din dreapta jos
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
            {
                if (grid[i][j]==1)
                    grid[i][j]=0; // distanta 0 fata de apa
                else
                {
                    grid[i][j]=inf; // temp
                    if (i>0)
                        grid[i][j]=min(grid[i-1][j]+1,grid[i][j]);
                    if (j>0)
                        grid[i][j]=min(grid[i][j-1]+1,grid[i][j]);
                }
            }
        // colt dreapta sus -> colt stanga jos
        int maxx=-1;
        for (int i=n-1;i>=0;i--)
            for (int j=n-1;j>=0;j--)
            {
                if (i<n-1)
                    grid[i][j]=min(grid[i+1][j]+1,grid[i][j]);
                if (j<n-1)
                    grid[i][j]=min(grid[i][j+1]+1,grid[i][j]);
                if (grid[i][j]>maxx)
                    maxx=grid[i][j];
            }
        if (maxx==0||maxx==inf)
            return -1;
        return maxx;
    }
};

int main()
{

    return 0;
}
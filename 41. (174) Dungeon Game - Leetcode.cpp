/*
The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Return the knight's minimum initial health so that he can rescue the princess.

Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        int m=dun.size();
        int n=dun[0].size();
        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1)
                {
                    dun[i][j]=min(0,dun[i][j]);
                }
                else if(i==m-1)
                {
                    dun[i][j]=min(0,dun[i][j]+dun[i][j+1]);
                }
                else if(j==n-1)
                {
                    dun[i][j]=min(0,dun[i][j]+dun[i+1][j]);
                }
                else
                {
                    dun[i][j]=min(0,dun[i][j]+max(dun[i+1][j],dun[i][j+1]));
                }
            }
        }
        return abs(dun[0][0])+1;
    }
};
// On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

// A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


// Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

// The knight continues moving until it has made exactly k moves or has moved off the chessboard.

// Return the probability that the knight remains on the board after it has stopped moving.


class Solution {
public:
    
    bool isvalid(int r,int c,int n)
    {
        if(r>=0 && r<n && c>=0 && c<n) return true;
        return false;
    }
    double knightProbability(int n, int k, int r, int c) {
        if(k==0) return double(1);
        vector<int>x_dir={-1,1,-2,-2,2,2,-1,1};
        vector<int>y_dir={2,2,1,-1,-1,1,-2,-2};
        double curr[n][n];
        double next[n][n];
        memset(curr,0,sizeof(curr));
        memset(next,0,sizeof(next));
        
        curr[r][c]=1;
        
        for(int m=1;m<=k;m++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(curr[i][j]!=0)
                    {
                        for(int x=0;x<8;x++)
                        {
                            if(isvalid(i+x_dir[x],j+y_dir[x],n))
                                next[i+x_dir[x]][j+y_dir[x]]+=curr[i][j]/8.0;
                        }
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    curr[i][j]=next[i][j];
                }
            }
            memset(next,0.0,sizeof(next));
        }
        double sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=curr[i][j];
            }
        }
        
        return sum;
    }
};
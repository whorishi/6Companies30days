// You are given an n x n integer matrix. You can do the following operation any number of times:

// Choose any two adjacent elements of matrix and multiply each of them by -1.
// Two elements are considered adjacent if and only if they share a border.

// Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int n = mat.size();
        long long sum=0;
        int negative=0;
        int max_negative=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=abs(mat[i][j]);
                if(mat[i][j]<=0)
                {
                    negative++;
                    max_negative = max(max_negative,mat[i][j]);
                }
            }
        }
        
        if(negative%2==0)
        {
            return sum;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(abs(mat[i][j])<abs(max_negative))
                {
                    max_negative = abs(mat[i][j]);
                }
            }
        }
        return sum - (2*abs(max_negative));
    }
};
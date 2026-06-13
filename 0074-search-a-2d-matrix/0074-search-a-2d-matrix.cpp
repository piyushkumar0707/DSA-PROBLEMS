class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int lo=0, hi=m*n-1;
        while(lo<=hi){
            int mid= lo+(hi-lo)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target)return true;
            else if(matrix[row][col]>target)hi=mid-1;
            else lo=mid+1;
            
        }return false;
        
    }
};
// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = 0;
        int cntr = 0;
        while(cntr < n){
            while(j < n and matrix[cntr][j] < target)j++;
            cntr++;
            if(matrix[cntr][j] == target)return true;
            if(cntr == m)break;
            while(j < n and matrix[cntr][j] > target)j--;
            if(matrix[cntr][j] == target)return true;
        }
        return false;
    }
};
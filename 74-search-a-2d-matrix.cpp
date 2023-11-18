class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size()-1;
        int row;
        while (l<=r)
        {
            int mid = (l)+(r-l)/2;
            if (matrix[mid][matrix[mid].size()-1] < target){
                l=mid+1;
            }
            else if (matrix[mid][0] > target)
            {
                r = mid-1;
            }
            else
            {
                row = mid;
                break;
            }
        }
        l = 0;
        r = matrix[row].size()-1;
        while (l<=r){
            int mid = (l)+(r-l)/2;
            if (matrix[row][mid] > target){
                r = mid-1;
            }
            else if (matrix[row][mid] < target){
                l = mid+1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
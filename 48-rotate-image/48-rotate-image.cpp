class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // reverse한다
        reverse(matrix.begin(), matrix.end());
        
        // 매트릭스를 Transpose한다
        for (int i=0; i<matrix.size(); i++)
        {
            for (int j=i+1; j<matrix[0].size(); j++)
                swap(matrix[i][j], matrix[j][i]);
        }
                       
        
    }
};
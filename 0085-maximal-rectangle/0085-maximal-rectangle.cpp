class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) {
                    width = i;
                }
                else {
                    width = i - st.top() - 1;
                }
                int area = width * height;
                maxArea = max(maxArea, area);
            }
            if(i < n){
                st.push(i);
            }
            
        }
        return maxArea;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix[0].size();
        vector<int> height(m, 0);
        int maxArea = 0;

        for(auto& row : matrix) {
            for(int i = 0; i < m; i++) {
                if(row[i] == '1') height[i]++;
                else height[i] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }
};
class Solution {
public:


    void dfs(vector<vector<int>>& image, int r, int c, int color, int originalImage){
        int m= image.size();
        int n= image[0].size();
        if(r<0 || r>=m || c<0 || c>=n || image[r][c]!=originalImage)return;
        image[r][c]=color;
        dfs(image, r+1, c, color, originalImage);
        dfs(image, r-1, c, color, originalImage);
        dfs(image, r, c+1, color, originalImage);
        dfs(image, r, c-1, color, originalImage);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalImage= image[sr][sc];
        if(originalImage==color)return image;

        dfs(image, sr, sc, color, originalImage);
        return image;
        
    }
};
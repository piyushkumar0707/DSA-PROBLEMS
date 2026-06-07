class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int left=0, right=height.size()-1;
        while(left<right){
            int h= min(height[left],height[right]);
            int dist=right-left;
            int area= dist*h;
            maxArea=max(area,maxArea);
           
            if(height[left]<height[right])left++;
            else right--;
              

        }return maxArea;
    }
};
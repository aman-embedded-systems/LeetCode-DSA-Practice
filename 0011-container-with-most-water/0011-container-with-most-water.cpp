class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int maxarea=0;
        int area=0;
        int left=0;
        int right=n-1;
        while(left<right)
        {
            area=(right-left)*(min(height[left],height[right]));
            maxarea=max(maxarea,area);
            if(height[left]<height[right])
            {
            left++;
            }
            else
            {
              right--;
            }
           
        }
        return maxarea;
    }
};
int maxArea(int* height, int heightSize) {
    int right=heightSize-1;
    int left=0;
    int maxarea=0;
    int area=0;

    while(left<right)
    {
        area= (right-left)*(fmin(height[left],height[right]));
        maxarea=fmax(maxarea,area);
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
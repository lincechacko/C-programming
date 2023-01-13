
int maxArea(int* height, int heightSize){
int h,width,area,max_vol=0;
for(int i=0,j=heightSize-1;i<j;)
{
h=maximum(height[i],height[j]);
width=j-i;
area=h*width;
if(area>max_vol)
{
    max_vol=area;
}
if(maximum(height[i],height[j])==height[j])
{
j--;
}
else
{
    i++;
}
}
return max_vol;
}
int maximum(int a ,int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

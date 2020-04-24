//快排，从小到大
class Solution {
public:
    int randPartition(vector<int>&nums,int left,int right)//随机选取基准
    {
        srand((unsigned )time(NULL));
        int pirvot=(int)(round(1.0*rand()/RAND_MAX*(right-left)+left));//生成 [left,right]的随机数
        swap(nums[left],nums[pirvot]);
        pirvot=left;
        while (left<right)
        {
            while ((left<right&&nums[right]>nums[pirvot]))
                right--;
            while ((left<right&&nums[left]<=nums[pirvot]))
                left++;
            swap(nums[left],nums[right]);
        }
        swap(nums[left],nums[pirvot]);
        return  left;

    }
    int Partition(vector<int> &nums,int left,int right)
    {
        int  pirvot=left;
        while(left<right)
        {

            while (left<right&&nums[right]>nums[pirvot])
                right--;
            while(left<right&&nums[left]<=nums[pirvot])
                left++;
            swap(nums[left],nums[right]);
        }
        swap(nums[pirvot],nums[left]);
        return left;

    }
    void quickSort(vector<int> &nums,int left,int right)
    {
        if(left<right)
        {
            int pos=Partition(nums,left,right);
            quickSort(nums,left,pos-1);
            quickSort(nums,pos+1,right);

        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;

    }
};
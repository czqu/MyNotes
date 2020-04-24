//归并排序 递归与非递归实现  从小到大
class Solution {
public:
    void merge(vector<int> &nums,int L1,int R1,int L2,int R2)
    {
        int i=L1,j=L2;
        int temp[R2-L1+1];
        int index=0;
        while (i<=R1&&j<=R2)
        {
            if(nums[i]<=nums[j])
            {
                temp[index++]=nums[i++];

            }else
            {
                temp[index++]=nums[j++];
            }
        }
        while (i<=R1)
            temp[index++]=nums[i++];
        while ((j<=R2))
            temp[index++]=nums[j++];
        memcpy(&nums[L1],temp,sizeof(temp));
        /*等价于用for循环将temp放入nums;
         * note:对于vector 不能像数组一样用数组名代替地址，
         *首元素地址应该是 &nums[0],不过此处没用到
         */

    }
    void mergeSort(vector<int> &nums,int left,int right)
    {
        if(left<right)
        {
            int mid=(left+right)/2;
            mergeSort(nums,left,mid);
            mergeSort(nums,mid+1,right);
            merge(nums,left,mid,mid+1,right);

        }

    }
    //非递归写法
    void mergeSort(vector<int> &nums)
    {
        int n=nums.size()-1;
        for(int step=1;step/2<=n;step*=2)
        {
            for(int i=0;i<n;i+=step)
            {
                int mid=i+step/2-1;
                if(mid+1<=n)
                {
                    merge(nums,i,mid,mid+1,min(i+step-1,n));
                }
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        //mergeSort(nums,0,nums.size()-1);
        mergeSort(nums);
        return nums;

    }
};
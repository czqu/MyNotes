/*冒泡排序
 *从小到大
 *冒泡排序是一种稳定排序算法，即相同元素的前后顺序并没有改变
 * 稳定排序的意义：如今需要按照销量高低排序，
 * 使用稳定性算法，可以使得想同销量的对象依旧保持着价格高低的排序展现，
 * 只有销量不同的才会重新排序。
 */
class Solution {
public:
    void bubbleSort(vector<int> &nums)
    {
        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]>nums[j])
                    swap(nums[i],nums[j]);

            }
    }
    vector<int> sortArray(vector<int>& nums) {
        bubbleSort(nums);
        return nums;

    }
};
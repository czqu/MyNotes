//堆排序  从小到大
class Solution {
public:
    void heapify(vector<int> &tree,int i,int last)
    {
        if(i>=last)
            return;
        int c1=2*i+1;//i的左孩子
        int c2=2*i+2;//i的右孩子
        int max=i;
        if(c1<last&&tree[c1]>tree[max])
            max=c1;
        if(c2<last&&tree[c2]>tree[max])
            max=c2;
        if(i!=max)
        {
            swap(tree[i],tree[max]);
            heapify(tree,max,last);

        }


    }
    void buildHeap(vector<int> &tree)
    {
        int lastNode=tree.size()-1;
        int parent=(lastNode-1)/2;//最后一个节点的父节点
        for(int i=parent;i>=0;i--)
            heapify(tree,i,tree.size());
        /*建堆就是倒着枚举非叶节点进行调整
         * 因为这样每次调整完一个节点后
         * 最大节点就在当前子树的根节点
         * 保证了每个节点都是以其为根节点的子树的最大值
         */
    }
    void heapSort(vector<int> &nums)
    {
        /*对大顶堆来说，堆顶元素值最大
         * 取堆顶元素和末尾元素交换
         * 砍掉末尾元素，调整堆，直到最后剩下一个元素
         */
        buildHeap(nums);

        for(int i=nums.size()-1;i>=0;i--)
        {
            swap(nums[i],nums[0]);
            heapify(nums,0,i);
        }

    }
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;

    }
};
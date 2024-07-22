class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,one=0,two=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)zero++;
            else if(nums[i]==1)one++;
            else two++;
        }
       int k=0;
       while(zero>0)
       {
        nums[k]=0;k++;zero--;
       }while(one>0)
       {
        nums[k]=1;k++;one--;
       }while(two>0)
       {
        nums[k]=2;k++;two--;
       }
    }
};
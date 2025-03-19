class Solution 
{
    public:
        int minOperations(vector<int>& nums) 
        {
             int n = nums.size();
             int operation = 0;
             for(int i=0;i<n-2;i++)
             {
                  if(nums[i]==1) continue;
                  nums[i] = nums[i]^1;
                  nums[i+1] = nums[i+1]^1;
                  nums[i+2] = nums[i+2]^1;
                  operation++;
             }
             if(nums[n-2]==0 || nums[n-1]==0) return -1;
             return operation;
        }
  };

  //Time Complexity : O(n)
  //Space Complexity :O(1)
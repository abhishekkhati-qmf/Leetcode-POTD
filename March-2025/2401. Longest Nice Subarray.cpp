/* NOTE:
 1->  In sliding window we use XOR operation to shrink window while handling values in bit using bit mask.
 2-> All possible pairs &==0 ?  for that mask & nums[j] 
                                and also mask | nums[j]
 3-> Sliding window will help you in questions like 
           find longest subarray with sum = k
           find subarray with sum == 0
           find subarray having largest sum
*/
class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) 
        {
            int n = nums.size();

            int i=0;
            int j=0;

            int result = 1;
            int mask =0;

            while(j<n){
                  while((mask & nums[j])!=0){ // Shrinking window
                        mask = (mask ^ nums[i]);
                        i++
                  }

                  result = max(result,j-i+1);
                  mask = (mask | nums[j]);
                  j++;
            }
            return result;
        }
};

//  Time Complexity : O(n)
//  Space Complexity: O(1)
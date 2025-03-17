//Approach -I
class Solution {
    public:
        bool divideArray(vector<int>& nums) 
        {
             map<int,int> mpp;
             for(int i=0;i<nums.size();i++){
                   mpp[nums[i]]++;
             }
             for(auto it:mpp){
                  if(it.second%2!=0){
                     return false;
                  }
             }
             return true;
        }
    };
    //  Time Complexity : O(nlogn+n)
    //  Space Complexity: O(n)


// Approach - II

class Solution {
    public:
        bool divideArray(vector<int>& nums) 
        {
             sort(nums.begin(),nums.end());
             for(int i=1;i<nums.size();i+=2){
                  if((nums[i]^nums[i-1])!=0){
                    return false;
                  }
             }
             return true;
        }
    };
   
      //  Time Complexity : O(nlogn+n)
    //  Space Complexity:   O(1)

class Solution {
    public:
        bool isPossible(vector<int>& ranks , int cars , long long mid)
        {
                long long repairedcars = 0;
                for(int i = 0;i<ranks.size();i++)
                {
                      repairedcars += sqrt(mid/(long long)ranks[i]);
                }
                return repairedcars>=cars;
        }
        long long repairCars(vector<int>& ranks, int cars) 
        {
              long long  l = 1;
              int mini = *min_element(begin(ranks),end(ranks)); 
              long long  r = (long long)mini*(long long)cars*(long long)cars;
    
              while(l<=r)
              {
                  long long mid = l+(r-l)/2;
                  
                  if(isPossible(ranks,cars,mid)){
                       r = mid-1;
                  }
                  else{
                      l = mid+1;
                  }
              }
              return l;
        }
    };

   // Time Complexity : O((min_element_of_ranks*cars*cars)*n)
   // Space Complexity : O(1)

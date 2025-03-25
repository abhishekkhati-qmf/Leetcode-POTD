class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>> arr){
              int n = arr.size();
              sort(arr.begin(),arr.end());
              vector<vector<int>> ans;
              for(int i=0;i<arr.size();i++){
                  if(ans.empty() || ans.back()[1]<=arr[i][0])
                  {
                      ans.push_back(arr[i]);
                  }
                  else
                  {
                     ans.back()[1] = max(ans.back()[1],arr[i][1]);
                  }
              }
              return ans;
        }
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) 
        {
            //x-axis
            vector<vector<int>> hor;
            //y-axis
            vector<vector<int>> vert;
    
            for(auto &rec:rectangles){
                     int x1 = rec[0];
                     int y1= rec[1];
                     int x2 = rec[2];
                     int y2 = rec[3];
    
                     hor.push_back({x1,x2});
                     vert.push_back({y1,y2});
            }
    
            vector<vector<int>> result1 = merge(hor);
            if(result1.size() >=3)
                return true;
            vector<vector<int>> result2 = merge(vert);
            return result2.size()>=3;
        }
    };
    
    // Time Complexity : O(nlogn)
    // Space Complexity : O(n)  ya O(4n)
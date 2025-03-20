class Solution {
    public:
        //NOtes:
        //1.when you do and(&) operations the result will never increase it will be equal or    decreased.
        //2. when you take and of any number with -1 then the number itself comes in result.
        vector<int> parent;
        int find(int x)
        {
             if(parent[x]==x){
                return x;
             }
    
             return parent[x]=find(parent[x]);
        }
        void Union(int x,int y){
             parent[y]=x;
        }
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
        { 
            parent.resize(n);
            vector<int> cost(n);
    
            for(int i=0;i<n;i++){
                 parent[i]=i;
                 cost[i]=-1;
            }
    
            for(auto &edge:edges)
            {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
    
                int parent_u = find(u);
                int parent_v = find(v);
    
                if(parent_u!=parent_v){
                     Union(parent_u,parent_v);
                     cost[parent_u] &= cost[parent_v];
                }
                cost[parent_u] &= w;
            }
            
            vector<int> result;
            for(auto &q:query){
                int s = q[0];
                int e = q[1];
    
                int parent_s = find(s);
                int parent_e = find(e);
    
                if(s==e){
                    result.push_back(0);
                }
                else if(parent_s!=parent_e){
                    result.push_back(-1);
                }
                else{
                    result.push_back(cost[parent_s]);
                }
            }
             return result;   
        }
    };
    
    //Time Complexity: O(E+Q)
    // Space Complexity:O(2*E+Q);
    //where E=edges and Q = queries
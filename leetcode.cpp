#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
private:
    vector<int> visited;
    unordered_set<string> charac;
    struct pair_hash
    {
        template<class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& p) const
        {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };
    unordered_map<pair<string,string>,double,pair_hash> dict;
public:
    Solution(){

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i<equations.size(); i++){
            dict[make_pair(equations[i][0],equations[i][1])] = values[i];
            dict[make_pair(equations[i][1],equations[i][0])] = 1.0/values[i];
            charac.insert(equations[i][0]);
            charac.insert(equations[i][1]);
        }
        vector<double> ret;
        for(int i = 0; i<queries.size(); i++){
            double one = -1;
            visited = vector<int>(equations.size(),0);
            vector<string> path;path.push_back(queries[i][0]);
            if(charac.count(queries[i][0])&&charac.count(queries[i][1])&&dfs(equations,queries[i][0],queries[i][1],path))
            {
                one = 1;
                for(int ii = 1; ii<path.size(); ii++){
                    one*=dict[make_pair(path[ii-1],path[ii])];
                }
                ret.push_back(one);
            }
            else ret.push_back(one);
        }
        return ret;
    }
    bool dfs(vector<vector<string>>& equations,string a,string b,vector<string>& ret){//从a-->b
        if(a==b)return true;
        for(int i = 0; i<equations.size(); i++){
            if(visited[i])continue;
            if(equations[i][0]==a){
                ret.push_back(equations[i][1]);
                visited[i] = 1;
                if(dfs(equations,equations[i][1],b,ret)) return true;
            }
            else if(equations[i][1]==a){
                ret.push_back(equations[i][0]);
                visited[i] = 1;
                if(dfs(equations,equations[i][0],b,ret)) return true;
            }
        }
        ret.pop_back();
        return false;
    }
};
int main()
{
    Solution s;
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<vector<string>> queries{{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    vector<double> ans = s.calcEquation(equations,values,queries);
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       int len = rooms.size();
       vector<bool> V(len, false);
       V[0] = true;
       int count = 1;

       queue<int> Q;
       Q.push(0);

       while(!Q.empty())
       {
         int i = Q.front(); Q.pop();
         for(int x : rooms[i])
         {
           if(V[x] == false) {
             V[x] = true;
             count++;
             if(count == len) return true;
             Q.push(x);
           }
         }
       }
       return false;
    }
};

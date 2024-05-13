#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int last_count = 1;
        for(int i = 1; i< nums.size(); i++){
            if(nums[i] != nums[index]){
                nums[++index] = nums[i];
                last_count = 1;
            }
            else if(last_count < 2)
            {
                nums[++index] = nums[i];
                last_count++;
            }
            else last_count++;
        }
        nums.erase(nums.begin()+index+1, nums.end());
        return index+1;        
    }
};

int main()
{
  vector<int> V = { 1,2,2,2,3,3,4,4,4,5,6,7,7,8};
  for_each(V.begin(), V.end(), [](int X){cout << X <<" "; });
  cout << endl;
  cout << Solution().removeDuplicates(V)<<endl;
  for_each(V.begin(), V.end(), [](int X){cout << X <<" "; });
  cout << endl;
  return 0;
}

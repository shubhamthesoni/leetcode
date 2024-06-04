#include <iostream>
#include <vector>

using namespace std;

class Solution {
   int searchVertical(vector<vector<int>>& matrix, int target, int low, int high)
   {
     if(low > high) return -1;
     int mid = low + (high - low)/2;
     int len = matrix[0].size();

     if((matrix[mid][0] <= target ) && (target <= matrix[mid][len-1])) return mid;
     else if(matrix[mid][0] > target) return searchVertical(matrix, target, low, mid - 1);
     else return searchVertical(matrix, target, mid+1, high);
   }

   int searchHorizontal(vector<vector<int>>& matrix, int target, int row, int low, int high)
   {
     if(low > high) return -1;
     int mid = low + (high - low)/2;
     int len = matrix[row].size();
     
     if(matrix[row][mid] == target) return mid;
     else if(matrix[row][mid] > target) return searchHorizontal(matrix, target, row, low, mid-1);
     else return searchHorizontal(matrix, target, row, mid+1, high);
   }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int row = searchVertical(matrix, target, 0, matrix.size()-1);
      if(row == -1) return false;
      return (searchHorizontal(matrix, target, row, 0, matrix[0].size()-1) != -1);
    }
};

int main()
{
  vector<vector<int>> V = {{1,3,5,7,9}, {15,18,20,21,30}, {31,32,35,40,55}, {61,72,78,79,90}, {91,95,98,99,100}, {103,108,111,125,130}};
  cout << Solution().searchMatrix(V, 110) << endl;
  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      int r = image.size();
      int c = image[0].size();
      int orig_color = image[sr][sc];

      if(orig_color == color) return image;
      if(orig_color != color) image[sr][sc] = color;

      if((sr > 0  ) && (image[sr-1][sc  ] == orig_color)) floodFill(image, sr-1, sc  , color);
      if((sr < r-1) && (image[sr+1][sc  ] == orig_color)) floodFill(image, sr+1, sc  , color);
      if((sc > 0  ) && (image[sr  ][sc-1] == orig_color)) floodFill(image, sr  , sc-1, color);
      if((sc < c-1) && (image[sr  ][sc+1] == orig_color)) floodFill(image, sr  , sc+1, color);

      return image;        
    }
};

int main()
{
  //vector<vector<int>> V = {{1,1,1},{1,1,0},{1,0,1}};
  vector<vector<int>> V = {{0,0,0},{0,0,0}};
  Solution solution;
  //V = solution.floodFill(V, 1, 1, 2);
  V = solution.floodFill(V, 1, 0, 2);
  
  int r = V.size();
  int c = V[0].size();
  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++) cout << V[i][j]<<" ";
    cout <<endl;
  }

  return 0;
}

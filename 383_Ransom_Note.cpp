class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      map<int> C;
      int len = magazine.length();
      for(int i = 0; i < len ; i++) C[magazine[i]-'a']++;
      len = ransomNote.length();
      for(int i = 0; i < len ; i++)
      {
        if(C[ransomNote[i]-'a'] == 0) return false;
        C[ransomNote[i] - 'a']--;
      }      
      return true;
    }
};

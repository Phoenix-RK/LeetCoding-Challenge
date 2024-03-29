//Phoenix_RK


/*

https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3765/


Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.



*/


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
       
    
        if(s1.size()+s2.size()!=s3.size())
          return false;
        
        bool val[s2.size()+1][s1.size()+1];
        memset(val,0,sizeof(val));
   
      for(int i=0;i<=s2.size();i++)
        {
            for(int j=0;j<=s1.size();j++)
            {
                if(i==0 &&j==0)
                    val[i][j]=true;
              
                else if(i==0)
                {                   
                    if(s1[j-1]==s3[j-1])
                        val[i][j]=val[i][j-1];       
                }
                else if(j==0)
                {
                    if(s2[i-1]==s3[i-1])
                        val[i][j]=val[i-1][j];
                }
               else if(s1[j-1]==s3[i+j-1] && s2[i-1]!=s3[i+j-1])
                    val[i][j]=val[i][j-1];
                
                else if(s1[j-1]!=s3[i+j-1] && s2[i-1]==s3[i+j-1])
                    val[i][j]=val[i-1][j];
                 
                else if(s1[j-1]==s3[i+j-1] && s2[i-1]==s3[i+j-1])
                    val[i][j]=(val[i-1][j]||val[i][j-1]);

            }
        }
    return val[s2.size()][s1.size()];
        
    }
};




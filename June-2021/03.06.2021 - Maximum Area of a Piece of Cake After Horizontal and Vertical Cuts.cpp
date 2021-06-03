//Phoenix_RK


/*

https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3766/



Given a rectangular cake with height h and width w, and two arrays of integers horizontalCuts and verticalCuts where horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a huge number, return this modulo 10^9 + 7.

 

Example 1:



Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4 
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.
Example 2:



Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.
Example 3:

Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9
 

Constraints:

2 <= h, w <= 10^9
1 <= horizontalCuts.length < min(h, 10^5)
1 <= verticalCuts.length < min(w, 10^5)
1 <= horizontalCuts[i] < h
1 <= verticalCuts[i] < w
It is guaranteed that all elements in horizontalCuts are distinct.
It is guaranteed that all elements in verticalCuts are distinct.

*/


class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long int max_h=0,max_w=0;
        // h = 5, w = 4, horizontalCuts = [1,3], verticalCuts = [1]
        /*
            max_h = 1
            max_h = max(1,3-1) =2
            max_h = max(2,4-3) =2
            
            
            max_w = 1
            max_w = max(1,4-1-1) = 2
    
        */
        for(int i=0;i<=horizontalCuts.size();i++)
        {
            if(i==0)
            {
                max_h = max(max_h,(long int) horizontalCuts[i]);
            }
            else if(i==horizontalCuts.size())
            {
                max_h = max(max_h, (long int) h-horizontalCuts[i-1]);
            }
            else
            {
                max_h = max(max_h, (long int) horizontalCuts[i]-horizontalCuts[i-1]);
            }
            
          //  cout<<i<<" "<<max_h<<endl;
        }
        
        
        
        for(int i=0;i<=verticalCuts.size();i++)
        {
            if(i==0)
            {
                max_w = max(max_w, (long int) verticalCuts[i]);
            }
            else if(i==verticalCuts.size())
            {
                max_w = max(max_w, (long int) w-verticalCuts[i-1]);
            }
            else
            {
                max_w = max(max_w, (long int)verticalCuts[i]-verticalCuts[i-1]);
            }
            // cout<<i<<" "<<max_w<<endl;
        }
        
        //cout<<max_h<<" "<<max_w<<endl;
        return (max_w*max_h)%(1000000007);
    }
};

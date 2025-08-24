#include<iostream>
#include<vector>
using namespace std;

int longestSubarray(vector<int>& nums) {
        int total_cnt=0,cnt_r=0,cnt_l=0;
        bool flag=false; //For case if 0 not present on array

        for(int i=0;i<nums.size();i++){
            cnt_r=0;
            cnt_l=0;
            if(nums[i]==0){
                flag=true;
                for(int k=i-1;k>=0;k--){
                    if(nums[k]==1)
                        cnt_l++;
                    else
                        break;
                    
                }
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j]==1)
                        cnt_r++;
                    else
                        break;
                }
                if(max(total_cnt,cnt_r+cnt_l)>total_cnt)
                    total_cnt=max(total_cnt,cnt_r+cnt_l);
          
            }
        }
        if(!flag)
            return nums.size()-1;

        return total_cnt;
    }

int main(){
    vector<int> nums={0,1,1,1,0,1,1,0,1};
    cout<<"Ans"<<longestSubarray(nums);
}



/*
Qno-1493
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2

Explanation: You must delete one element.
Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

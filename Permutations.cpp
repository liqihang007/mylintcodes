/*
Given a list of numbers, return all possible permutations.

Example:
For nums [1,2,3], the permutaions are: 

[
    [1,2,3],
    [1,3,2],
    [2,1,3],
    [2,3,1],
    [3,1,2],
    [3,2,1]
]

Challenge:
Do it without recursion
*/

//Without Recursion
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<vector<int> > res;
        if(nums.size() == 0)
            return res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while(next(nums)){
            res.push_back(nums);
        }
        return res;
    }
    
    bool next(vector<int> &nums){
        int sz = nums.size();
        int i = sz - 2;
        int j = sz - 1;
        while(i >=0 && nums[i] >= nums[i+1])
            i--;
        if(i == -1)
            return false;
        
        while(j>i && nums[j]<=nums[i])
            j--;
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i +1, nums.end());
        return true;
    }
};


//Recursion
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<vector<int> > res;
        permuteHelper(nums, 0, res);
        return res;
    }
    
    void permuteHelper(vector<int> &nums, int start, vector<vector<int> > &res){
        int sz = nums.size();
        if(start == sz){
            if(sz != 0)
                res.push_back(nums);
            return;
        }
        
        for(int i = start; i < sz; i++){
            swap(nums[start], nums[i]);
            permuteHelper(nums, start+1, res);
            swap(nums[i], nums[start]);
        }
    }
};

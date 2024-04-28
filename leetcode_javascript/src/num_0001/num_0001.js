/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const hash = {}
    for (let i = 0; i < nums.length; i++) {
        if ((target - nums[i]) in hash) {
            return [i, hash[target - nums[i]]]
        }
        hash[nums[i]] = i
    }
};


let nums = [2, 7, 11, 15], target = 9
console.log(twoSum(nums, target))
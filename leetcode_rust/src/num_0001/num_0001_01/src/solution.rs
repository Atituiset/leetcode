pub struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();
        for (i, v1) in nums.iter().enumerate() {
            for (j, v2) in nums[i+1..].iter().enumerate() {
                if v1 + v2 == target {
                    res.push(i as i32);
                    res.push((j+i+1) as i32);
                    return res;
                }
            }
        }

        return res;
    }
}


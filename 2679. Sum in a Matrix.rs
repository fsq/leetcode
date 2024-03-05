impl Solution {
    pub fn matrix_sum(nums: Vec<Vec<i32>>) -> i32 {
        let mut nums = nums;
        for a in nums.iter_mut() {
        // for a in &mut nums {
            a.sort_by(|a, b| b.cmp(a));
        }
        let mut ret = 0;
        for j in 0..nums[0].len() {
            let mut mx = 0;
            for i in 0..nums.len() {
                mx = mx.max(nums[i][j]);
            }
            ret = ret + mx;
        }
        ret
    }
}
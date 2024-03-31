impl Solution {
    pub fn number_of_good_subarray_splits(mut nums: Vec<i32>) -> i32 {
        let mut p = -1;
        let ans = nums.iter().enumerate().filter(|(i, &x)| x==1)
        .fold(1 as i64, |acc, (i, &x)| {
            let mut ans = 1;
            if p != -1 {
                ans = i as i64 - p;
            }
            p = i as i64;
            (acc * ans) % 1000000007
        }) as i32;
        if p==-1 {
            0
        } else {
            ans
        }
    }
}
use std::cmp::max;

impl Solution {
    pub fn max_non_decreasing_length(a: Vec<i32>, b: Vec<i32>) -> i32 {
        let n = a.len();
        let mut f = vec![vec![1; 2]; n];
        let mut ans = 1;
        for i in 1..n {
            if a[i]>=a[i-1] {
                f[i][0] = f[i][0].max(f[i-1][0] + 1);
            }
            if a[i]>=b[i-1] {
                f[i][0] = f[i][0].max(f[i-1][1] + 1);
            }
            if b[i]>=a[i-1] {
                f[i][1] = f[i][1].max(f[i-1][0] + 1);
            }
            if b[i]>=b[i-1] {
                f[i][1] = f[i][1].max(f[i-1][1] + 1);
            }
            ans = ans.max(max(f[i][0], f[i][1]));
        }
        ans
    }
}
use std::cmp;

impl Solution {
    pub fn max_score(a: Vec<i32>, x: i32) -> i64 {
        let n = a.len();
        let mut f = vec![vec![0i64; 2]; n];
        
        let p0 = (a[0] as usize) & 1;
        f[0][p0] = a[0] as i64;
        f[0][p0^1] = i32::MIN as i64;
        for i in 1..n {
            let p = (a[i] as usize) & 1;
            f[i][p] = cmp::max(f[i-1][p] + a[i] as i64, f[i-1][p^1] + (a[i] - x) as i64);
            f[i][1^p] = f[i-1][1^p];
        }
        return f[n-1][0].max(f[n-1][1])
    }
}
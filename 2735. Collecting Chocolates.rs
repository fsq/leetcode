impl Solution {
    pub fn min_cost(a: Vec<i32>, x: i32) -> i64 {
        let n = a.len();
        let x = x as i64;
        let mut mn = vec![i64::MAX; n];
        let mut ans = i64::MAX; 
        for m in 0..n {
            let mut cur = 0 as i64;
            for i in 0..n {
                mn[i] = mn[i].min(a[(i-m+n) % n] as i64);
                cur += mn[i];
            }
            cur += (m as i64) * x;
            ans = ans.min(cur);
        }
        ans
    }
}
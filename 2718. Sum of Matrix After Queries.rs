impl Solution {
    pub fn matrix_sum_queries(n: i32, queries: Vec<Vec<i32>>) -> i64 {
        let n = n as usize;
        let mut r = vec![false; n];
        let mut c = vec![false; n];
        let mut cr = n as i64;
        let mut cc = n as i64;
        let mut ans = 0 as i64;
        for q in queries.iter().rev() {
            let (i, val) = (q[1] as usize, q[2] as i64);
            if q[0] == 0 {
                if r[i] {
                    continue;
                }
                r[i] = true;
                ans += cc * val;
                cr -= 1;
            } else {
                if c[i] {
                    continue;
                }
                c[i] = true;
                ans += cr * val;
                cc -= 1;
            }
        }
        ans
    }
}
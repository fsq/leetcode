impl Solution {
    pub fn number_of_ways(n: i32, p: i32) -> i32 {
        let p = p as usize;
        let n = n as usize;
        let mut f = vec![vec![0; 301]; 301];
        let M = 1000000007;
        f[0][0] = 1;
        for x in 1..=n {
            let mut m = 1usize;
            while m.pow(p as u32) <= x {
                let t = (x - m.pow(p as u32)) as usize;
                // f[x][m] = Sigma f[t][..m-1]
                for y in 0..m {
                    f[x][m] = (f[x][m] + f[t][y]) % M;
                    if y.pow(p as u32) > t {
                        break;
                    }
                }
                m += 1;
            }
        }
        let mut ans = 0;
        for m in 0..=n {
            ans = (ans + f[n][m]) % M;
        }
        ans
    }
}
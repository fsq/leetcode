impl Solution {
    pub fn special_perm(a: Vec<i32>) -> i32 {
        let n = a.len();
        let M = 1000000007;
        let mut f = [[0; 1<<14]; 14];

        for m in 1..(1<<n) {
            for x in 0..n {
                if (m & (1<<x)) > 0 {
                    let t = m ^ (1<<x);
                    if t == 0 {
                        f[x][m] = 1;
                        continue;
                    }
                    for y in 0..n {
                        if (t & (1<<y)) > 0 && (a[x]%a[y]==0 || a[y]%a[x]==0) {
                            f[x][m] = (f[x][m] + f[y][t]) % M;
                        }
                    }
                }
            }
        }
        
        (0..n).fold(0, |acc, x| (acc + f[x][(1<<n)-1]) % M)
    }
}
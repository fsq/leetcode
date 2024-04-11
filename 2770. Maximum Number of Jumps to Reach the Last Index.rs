impl Solution {
    pub fn maximum_jumps(a: Vec<i32>, target: i32) -> i32 {
        let target = target as i64;
        let n = a.len();
        let mut f = vec![-1; n];
        f[0] = 0;
        for i in 1..n {
            let x = a[i] as i64;
            for j in 0..i {
                let y = a[j] as i64;
                if x-target<=y && y<=x+target && f[j]!=-1{
                    f[i] = f[i].max(f[j] + 1);
                }
            }
        }
        f[n-1]
    }
}
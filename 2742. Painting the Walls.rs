impl Solution {
    pub fn paint_walls(cost: Vec<i32>, time: Vec<i32>) -> i32 {
        let n = cost.len();
        let INF = 0x3f3f3f3f;
        let mut f = vec![vec![INF; n+1]; n+1];
        f[0][0] = 0;
        for i in 1..=n {
            let ti = time[i-1] as usize;
            let ci = cost[i-1];
            for t in 0..=n {
                f[i][t] = f[i-1][t];
                if t >= ti+1 {
                    f[i][t] = f[i][t].min(f[i-1][t-ti-1] + ci);
                }
            }
            for t in n.saturating_sub(ti+1)..=n {
                f[i][n] = f[i][n].min(f[i-1][t] + ci);
            }
        }
        f[n][n]
    }
}
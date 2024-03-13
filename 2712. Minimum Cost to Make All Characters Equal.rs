impl Solution {
    pub fn minimum_cost(s: String) -> i64 {
        let s = s.chars().collect::<Vec<char>>();
        let mut ans = 0i64;
        for i in 1..s.len() {
            if s[i] != s[i-1] {
                ans += i.min(s.len()-i) as i64;
            }
        }
        ans
        // let s: Vec<char> = s.chars().collect();
        // let n = s.len();
        // let mut l = vec![vec![0 as i64; 2]; n+1];
        // let mut r = vec![vec![0 as i64; 2]; n+1];
        // if s[0] == '0' {
        //     l[0][1] = 1;
        // } else {
        //     l[0][0] = 1;
        // }
        // if s[n-1] == '0' {
        //     r[n-1][1] = 1;
        // } else {
        //     r[n-1][0] = 1;
        // }
        // for i in 1..n {
        //     if s[i] == '0' {
        //         l[i] = vec![l[i-1][0], l[i-1][0] + (i + 1) as i64];
        //     } else {
        //         l[i] = vec![l[i-1][1] + (i + 1) as i64, l[i-1][1]];
        //     }
        // }
        // for i in (0..n-1).rev() {
        //     if s[i] == '0' {
        //         r[i] = vec![r[i+1][0], r[i+1][0] + (n - i) as i64];
        //     } else {
        //         r[i] = vec![r[i+1][1] + (n - i) as i64, r[i+1][1]];
        //     }
        // }
        // (0..n)
        // .map(|x| {
        //     let to0 = l[x][0] + r[x+1][0];
        //     let to1 = l[x][1] + r[x+1][1];
        //     return to0.min(to1);
        // })
        // .min()
        // .unwrap()
    }
}
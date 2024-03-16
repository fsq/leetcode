impl Solution {

    pub fn dfs(a: &Vec<i32>, f: &[[i32; 401]; 24], i: usize, sum: usize, 
                max_sum: usize, min_sum: usize) -> i32 {
        if i == a.len() {
            if sum >= min_sum && sum <= max_sum {
                return 1;
            } else {
                return 0;
            }
        }

        let M = 1000000007;
        let mut ans = 0;
        for mut x in 0..=a[i]-1 {
            let x = x as usize;
            if max_sum < sum+x {
                break;
            }
            let upper = f[a.len()-i-1][max_sum-sum-x];
            let lower = if min_sum >= 1+sum+x {
                f[a.len()-i-1][min_sum-1-sum-x]
            } else {
                0
            };
            ans = (ans + (upper - lower + M) % M) % M;
        }
        (ans + Self::dfs(a, f, i+1, sum+a[i] as usize, max_sum, min_sum)) % M
    }

    pub fn calc(num: String, min_sum: usize, max_sum: usize, f: &[[i32; 401]; 24]) -> i32 {
        let a: Vec<i32> = num.as_bytes().iter().map(|c| (c - b'0') as i32).collect();
        Self::dfs(&a, &f, 0, 0, max_sum as usize, min_sum as usize)
    }

    pub fn count(mut num1: String, num2: String, mut min_sum: i32, mut max_sum: i32) -> i32 {
        let min_sum = min_sum as usize;
        let max_sum = max_sum as usize;
        let mut f = [[0; 401]; 24];
        f[0].iter_mut().for_each(|x| *x = 1);
        let M = 1000000007;
        for i in 1..=num2.len() {
            for j in 0..=max_sum {
                for k in 0..=9.min(j) {
                    f[i][j] = (f[i][j] + f[i-1][j-k]) % M;
                }
            }
        }
        let mut num1: Vec<_> = num1.chars().collect();
        let mut i = num1.iter().rposition(|&x| x!='0').unwrap();
        num1[i] = (num1[i] as u8 - 1) as char;
        i += 1;
        while i<num1.len() {
            num1[i] = '9';
            i += 1;
        }
        let num1: String = num1.iter().collect();
        (Self::calc(num2, min_sum, max_sum, &f) - Self::calc(num1, min_sum, max_sum, &f) + M) % M
    }
}
impl Solution {
    pub fn sum_of_power(mut a: Vec<i32>) -> i32 {
        a.sort();
        let M = (10 as i64).pow(9) + 7;
        let mut s: i64 = 0; // a0*2^i+a1*2^(i-1)+...ai
        let mut ans: i64 = 0;
        for i in 0..a.len() {
            let x = a[i] as i64;
            let cur = (s * (x * x % M) % M + (x * x % M * x % M)) % M;
            ans = (ans + cur) % M;
            s = (s*2 + x) % M;
        }
        ans as i32
    }
} 
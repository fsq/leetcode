impl Solution {
    pub fn sum_distance(a: Vec<i32>, s: String, d: i32) -> i32 {
        let d = d as i64;
        let mut tot = 0i64;
        let mut b = vec![];
        for (i, c) in s.chars().enumerate() {
            if c == 'L' {
                b.push(a[i] as i64 - d);
            } else {
                b.push(a[i] as i64 + d);
            }
            tot += b.last().unwrap();
        }
        b.sort();
        let mut ans = 0i64;
        let M = 1000000007;
        let n = b.len() as i64;
        for (i, x) in b.iter().enumerate() {
            let i = i as i64;
            tot -= x;
            ans = (ans + (tot - (n-i-1)*x)) % M;
        }
        ans as i32
    }
}
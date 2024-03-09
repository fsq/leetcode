impl Solution {

    pub fn dfs(s: &String, sum: i32, target: i32, i: usize) -> bool {
        if (i==s.len()) {
            sum == target
        } else {
            let mut cur = 0;
            for j in i..s.len() {
                cur = cur * 10 + (s.as_bytes()[j] - b'0') as i32;
                if sum + cur > target {
                    break;
                }
                if Self::dfs(s, sum+cur, target, j+1) {
                    return true;
                }
            }
            false
        }
    }

    pub fn punishment_number(n: i32) -> i32 {
        (1..=n)
        .filter(|&x| Self::dfs(&(x * x).to_string(), 0, x, 0))
        .map(|x| x*x).sum()
    }
}
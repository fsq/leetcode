impl Solution {
    pub fn max_array_value(a: Vec<i32>) -> i64 {
        let mut ans = a[a.len()-1] as i64;
        let mut cur = ans;
        for i in (1..a.len()).rev() {
            let x = a[i-1] as i64;
            if cur >= x {
                cur += x;
            } else {
                cur = x;
            }
            ans = ans.max(cur);
        }
        ans
    }
}
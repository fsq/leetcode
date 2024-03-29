impl Solution {
    pub fn maximum_number_of_string_pairs(a: Vec<String>) -> i32 {
        let n = a.len();
        let mut vis = vec![false; n];
        let mut ans = 0;
        let ok = |a: &String, b:&String| -> bool {
            let c: String = b.chars().rev().collect();
            *a == c
        };
        for i in 0..n {
            if vis[i] {
                continue;
            }
            for j in i+1..n {
                if !vis[j] && ok(&a[i], &a[j]) {
                    vis[j] = true;
                    ans += 1;
                }
            }
        }
        ans
    }
}
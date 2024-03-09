use std::collections::HashSet;

impl Solution {
    pub fn min_extra_char(s: String, dc: Vec<String>) -> i32 {
        let mut st: HashSet<String> = dc.into_iter().collect();
        let mut f = vec![0; s.len()];
        for i in 0..s.len() {
            f[i] = i + 1;
            if st.contains(&s[..=i]) {
                f[i] = 0;
                continue;
            }
            if i > 0 {
                f[i] = f[i].min(f[i-1] + 1);
            }
            for j in 1..=i {
                if st.contains(&s[j..=i]) {
                    f[i] = f[i].min(f[j-1]);
                }
            }
        }
        *f.last().unwrap() as i32
    }
}
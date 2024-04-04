use std::collections::HashSet;

impl Solution {
    pub fn find_prime_pairs(n: i32) -> Vec<Vec<i32>> {
        let n = n as usize;
        let mut v = vec![false; n+1];
        let mut st = HashSet::new();
        for i in 2..=n {
            if !v[i] {
                st.insert(i);
                let mut j = i*i;
                while j <= n {
                    v[j] = true;
                    j += i;
                }
            }
        }
        let mut ans = vec![];
        for x in 2..=n/2 {
            if st.contains(&x) && st.contains(&(n-x)) {
                ans.push(vec![x as i32, (n-x) as i32]);
            }
        }
        ans
    }
}
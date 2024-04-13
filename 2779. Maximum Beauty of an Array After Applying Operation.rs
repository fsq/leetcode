use std::collections::BTreeMap;

impl Solution {
    pub fn maximum_beauty(a: Vec<i32>, k: i32) -> i32 {
        let mut m: BTreeMap<i32, i32> = BTreeMap::new();
        for &x in a.iter() {
            if let Some(it) = m.get_mut(&(x-k)) {
                *it += 1;
            } else {
                m.insert(x-k, 1);
            }
            if let Some(it) = m.get_mut(&(x+k+1)) {
                *it -= 1;
            } else {
                m.insert(x+k+1, -1);
            }
        }
        let mut cur = 0;
        let mut ans = 1;
        for d in m.values() {
            cur += d;
            ans = ans.max(cur);
        }
        ans
    }
}
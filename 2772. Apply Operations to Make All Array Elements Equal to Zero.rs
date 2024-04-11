impl Solution {
    pub fn check_array(a: Vec<i32>, k: i32) -> bool {
        let n: usize = a.len();
        let mut s: Vec<i32> = vec![0; n];
        let mut cur: i32 = 0;
        for i in 0..n {
            cur += s[i];
            if cur > a[i] {
                return false;
            }
            let df = a[i] - cur;
            cur += df;
            let rb = i + k as usize;
            if rb < s.len() {
                s[rb] -= df;
            } else if rb>s.len() && df!=0 {
                return false;
            }
        }
        true
    }
}
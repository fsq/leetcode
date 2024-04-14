use std::collections::HashMap;
impl Solution {
    pub fn minimum_index(nums: Vec<i32>) -> i32 {
        let mut m = HashMap::new();
        let mut ld = vec![-1; nums.len()];
        let mut mf = -1;
        let mut mx = 0;
        for (i, &x) in nums.iter().enumerate() {
            *m.entry(x).or_insert(0) += 1;
            let ff = *(m.get(&x).unwrap());
            if ff > mf {
                mf = ff;
                mx = x;
            }
            if mf*2 > (i+1) as i32 {
                ld[i] = mx;
            }
        }
        mf = -1;
        mx = 0;
        m = HashMap::new();
        let mut ans = -1;
        for (i, &x) in nums.iter().enumerate().skip(1).rev() {
            *m.entry(x).or_insert(0) += 1;
            let ff = *(m.get(&x).unwrap());
            if ff > mf {
                mf = ff;
                mx = x;
            }
            if mf*2 > (nums.len()-i) as i32 && mx==ld[i-1] {
                ans = (i-1) as i32;
            }
        }
        ans
    }
}
impl Solution {
    pub fn alternating_subarray(a: Vec<i32>) -> i32 {
        for l in (2..=a.len()).rev() {
            for i in 0..=a.len()-l {
                let mut f = 1;
                let mut ok = true;
                for j in i+1..i+l {
                    if a[j]-a[j-1] != f {
                        ok = false;
                        break;
                    }
                    f = f * -1;
                }
                if ok {
                    return l as i32;
                }
            }
        }
        return -1;
    }
}
impl Solution {
    pub fn max_increasing_groups(mut a: Vec<i32>) -> i32 {
        a.sort();
        let mut h = 0i64;
        let mut tot = 0i64;
        for &x in a.iter() {
            tot += x as i64;
            if tot >= (h+1)*(h+2)/2 {
                h += 1;
            }
        }
        h as i32
    }
}
impl Solution {
    pub fn find_value_of_partition(mut a: Vec<i32>) -> i32 {
        a.sort();
        let mut ans = i32::MAX;
        for i in 0..a.len()-1 {
            ans = ans.min(a[i+1] - a[i]);
        }
        ans
    }
}
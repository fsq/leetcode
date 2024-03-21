use std::collections::BTreeSet;
impl Solution {
    pub fn find_non_min_or_max(nums: Vec<i32>) -> i32 {
        let st = BTreeSet::from_iter(nums.iter());
        if st.len() <= 2 {
            return -1;
        } else {
            return **st.iter().nth(1).unwrap();
        }
    }
}
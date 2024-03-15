use std::collections::HashSet;

impl Solution {
    pub fn minimized_string_length(s: String) -> i32 {
        HashSet::<char>::from_iter(s.chars()).len() as i32
    }
}
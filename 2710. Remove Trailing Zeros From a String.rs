impl Solution {
    pub fn remove_trailing_zeros(num: String) -> String {
        let mut i = num.len() - 1;
        // while i>=0 && num.as_bytes()[i]==b'0' {
        //     i -= 1;
        // }
        for (p, c) in num.char_indices().rev() {
            if c != '0' {
                i = p;
                break;
            }
        }
        num[0..=i].to_string()
    }
}
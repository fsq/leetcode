impl Solution {
    pub fn make_smallest_palindrome(str: String) -> String {
        // Use vector of chars
        // let mut s: Vec<_> = str.chars().into_iter().collect();
        // let (mut i, mut j) = (0, s.len()-1);
        // while i < j {
        //     if s[i] < s[j] {
        //         s[j] = s[i];
        //     } else if (s[i] > s[j]) {
        //         s[i] = s[j];
        //     }
        //     i += 1;
        //     j -= 1;
        // }
        // s.into_iter().collect()

        // Use vector of bytes
        let mut s = str.into_bytes();
        let (mut i, mut j) = (0, s.len()-1);
        while i < j {
            if s[i] < s[j] {
                s[j] = s[i];
            } else if (s[i] > s[j]) {
                s[i] = s[j];
            }
            i += 1;
            j -= 1;
        }
        String::from_utf8(s).unwrap()
    }
}
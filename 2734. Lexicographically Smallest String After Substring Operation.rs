impl Solution {
    pub fn smallest_string(s: String) -> String {
        let mut s: Vec<char> = s.chars().collect();
        let mut l = s.len();
        let mut r = s.len();
        if let Some(i)=s.iter().position(|&c| c!='a') {
            l = i;
        }
        // Can't use skip(l).position() since it consumes iterator and gives wrong index
        for i in l+1..s.len() {
            if s[i] == 'a' {
                r = i;
                break;
            }
        }
        if l == s.len() {
            s[l-1] = 'z';
        } else {
            for c in l..r {
                s[c] = std::char::from_u32(s[c] as u32 - 1).unwrap();
            }
        }
        s.iter().collect::<String>()
    }
}
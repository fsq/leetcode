impl Solution {
    pub fn min_length(str: String) -> i32 {
        let mut s = String::new();
        str
        .chars()
        .for_each(|c| {
            s.push(c);
            if s.len()>=2 && (&s[s.len()-2..] == "AB" || &s[s.len()-2..] == "CD") {
                s.pop();
                s.pop();
            }
        });
        s.len() as i32
    }
}
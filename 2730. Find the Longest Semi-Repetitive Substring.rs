impl Solution {
    pub fn longest_semi_repetitive_substring(s: String) -> i32 {
        let mut a = vec![-1];
        let s: Vec<_> = s.chars().collect();
        for i in 0..s.len()-1 {
            if s[i]==s[i+1] {
                a.push(i as i32);
            }
        }
        if a.len()==1 {
            return s.len() as i32;
        }
        a.push(s.len() as i32 - 1);
        let mut ans = 0;
        for i in 1..a.len()-1 {
            ans = ans.max(a[i+1]-a[i-1]).max(2)
        }
        ans
    }
}
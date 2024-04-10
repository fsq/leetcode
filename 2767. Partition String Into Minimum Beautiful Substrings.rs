impl Solution {

    pub fn dfs(p: &Vec<String>, s: &String, i: usize, seg: i32, ans: &mut i32) {
        if i==s.len() {
            *ans = (*ans).min(seg);
        }
        for num in p {
            if i+num.len()<=s.len() && &s[i..i+num.len()]==num {
                Self::dfs(p, s, i+num.len(), seg+1, ans);
            }
        }
    }

    pub fn minimum_beautiful_substrings(s: String) -> i32 {
        let mut p = vec![];
        for i in 0..=7 {
            let pw = 5i32.pow(i);
            let s = format!("{:b}", pw);
            p.push(s);
        }
        let mut ans = i32::MAX;
        Self::dfs(&p, &s, 0, 0, &mut ans);
        if ans == i32::MAX {
            -1
        } else {
            ans
        }
    }
}
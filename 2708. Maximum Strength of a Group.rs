impl Solution {
    pub fn max_strength(mut a: Vec<i32>) -> i64 {
        let has0 = a.iter().any(|&x: &i32| x==0);
        let mut a: Vec<_> = a.iter().filter(|&&x: && i32| x!=0).map(|x: &i32| *x).collect();
        if a.is_empty() {
            return 0;
        }
        let s = a.iter().fold(1 as i64, |acc, &x| acc * (x as i64));
        let mut ans = 
            if s < 0 && a.len() > 1 {
                let max_neg = *a.iter().filter(|x: &&i32| **x < 0).max().unwrap() as i64;
                s / max_neg
            } else {
                s
            };
        if has0 {
            ans = ans.max(0);
        }
        ans
    }
}
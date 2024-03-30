impl Solution {

    pub fn gcd(x: i32, y: i32) -> i32 {
        if y==0 {
            x
        } else {
            Self::gcd(y, x%y)
        }
    }

    pub fn count_beautiful_pairs(a: Vec<i32>) -> i32 {
        let mut ans = 0;
        for i in 0..a.len() {
            for j in i+1..a.len() {
                let x = (a[i].to_string().as_bytes().iter().nth(0).unwrap() - b'0') as i32;
                let y = a[j] % 10;
                if Self::gcd(x,y)==1 {
                    ans += 1;
                }
            }
        }
        ans
    }
}
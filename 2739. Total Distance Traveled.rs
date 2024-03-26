impl Solution {
    pub fn distance_traveled(mut a: i32, mut b: i32) -> i32 {
        let mut ans = 0;
        while a>0 {
            if a < 5 {
                ans += a * 10;
                break;
            }
            a -= 5;
            ans += 50;
            if b > 0 {
                b -= 1;
                a += 1;
            }
        }
        ans
    }
}
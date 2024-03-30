impl Solution {
    pub fn make_the_integer_zero(num1: i32, num2: i32) -> i32 {
        let num1 = num1 as i64;
        let num2 = num2 as i64;
        for i in 0..60 {
            let i = i as i64;
            let n = num1-i*num2;
            if n.count_ones()<=(i as u32) && n>=i {
                return i as i32;
            }
        }
        return -1;
    }
}
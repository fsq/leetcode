impl Solution {
    pub fn sum_of_squares(a: Vec<i32>) -> i32 {
        let mut ans = 0;
        let n = a.len();
        (0..a.len()).filter(|&i| n % (i+1) == 0).map(|i| a[i]*a[i]).sum::<i32>()
    }
}
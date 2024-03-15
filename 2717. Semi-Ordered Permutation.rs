impl Solution {
    pub fn semi_ordered_permutation(a: Vec<i32>) -> i32 {
        let n = a.len();
        let x = a.iter().position(|&x| x==1).unwrap();
        let y = a.iter().position(|&x| x as usize==n).unwrap();
        (if x < y {
            x + n - y - 1
        } else {
            x + n - y - 2
        }) as i32
    }
}
use std::cmp::Ordering;

impl Solution {

    pub fn f(a: &Vec<i32>) -> i32 {
        let mut tot: i32 = 0;
        for i in 0..a.len() {
            if (i>=1 && a[i-1]==10) ||
               (i>=2 && a[i-2]==10) {
                tot += a[i] * 2;
            } else {
                tot += a[i];
            }
        }
        return tot;
    }

    pub fn is_winner(player1: Vec<i32>, player2: Vec<i32>) -> i32 {
        match Self::f(&player1).cmp(&Self::f(&player2)) {
            Ordering::Greater => return 1,
            Ordering::Less => return 2,
            Ordering::Equal => return 0
        };
    }
}
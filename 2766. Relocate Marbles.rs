use std::collections::HashMap;

impl Solution {
    pub fn relocate_marbles(nums: Vec<i32>, move_from: Vec<i32>, move_to: Vec<i32>) -> Vec<i32> {
        let mut v = HashMap::new();
        nums.iter().for_each(|&x| {
            v.insert(x as usize, true);
        });
        for i in 0..move_from.len() {
            let x = move_from[i] as usize;
            let y = move_to[i] as usize;
            if v.get(&x)==Some(&true) {
                v.insert(x, false);
                v.insert(y, true);
            }
        }
        let mut ret = v.iter().filter(|&(i, x)| *x).map(|(i, x)| *i as i32).collect::<Vec<i32>>();
        ret.sort();
        ret
    }
}
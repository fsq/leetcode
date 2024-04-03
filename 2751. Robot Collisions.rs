use std::collections::HashMap;
impl Solution {
    pub fn survived_robots_healths(positions: Vec<i32>, healths: Vec<i32>, directions: String) -> Vec<i32> {
        let directions: Vec<char> = directions.chars().collect();
        let mut a = vec![];
        for i in 0..positions.len() {
            a.push((positions[i] as usize, i));
        }
        a.sort();
        let mut m = HashMap::new();
        let mut stk: Vec<(usize,usize)> = vec![];
        for &(_, id) in a.iter() {
            let mut h = healths[id] as usize;
            let dr = directions[id];
            if dr=='L' {
                while !stk.is_empty() && h>0 {
                    let last = stk.len() - 1;
                    let ip = stk[last].0;
                    let hp = stk[last].1;
                    if hp < h {
                        stk.pop();
                        h -= 1;
                    } else if hp > h {
                        stk[last].1 -= 1;
                        h = 0;
                        break;
                    } else {
                        h = 0;
                        stk.pop();
                        break;
                    }
                }
            }
            if h > 0 {
                if dr == 'L' {
                    m.insert(id, h);
                } else {
                    stk.push((id, h));
                }
            }
        }
        for &(id, h) in stk.iter() {
            m.insert(id, h);
        }

        let mut ans = vec![];
        for id in 0..positions.len() {
            if let Some(h) = m.get(&id) {
                ans.push(*h as i32);
            }
        }
        ans
    }
}
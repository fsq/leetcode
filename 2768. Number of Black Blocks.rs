use std::collections::HashMap;

impl Solution {
    pub fn count_black_blocks(n: i32, m: i32, crd: Vec<Vec<i32>>) -> Vec<i64> {
        let mut mp : HashMap<i32, HashMap<i32, i32>> = HashMap::new();
        let dx = vec![-1, -1, 0, 0];
        let dy = vec![-1, 0, -1, 0];
        for pr in crd {
            let (x, y) = (pr[0], pr[1]);
            for dr in 0..4 {
                let (tx, ty) = (x + dx[dr], y + dy[dr]);
                if tx>=0 && tx<n && ty>=0 && ty<m && tx+1<n && ty+1<m {
                    if !mp.contains_key(&tx) {
                        mp.insert(tx, HashMap::new());
                    }
                    let mt = mp.get_mut(&tx).unwrap();
                    if let Some(cnt) = (*mt).get_mut(&ty) {
                        *cnt += 1;
                    } else {
                        (*mt).insert(ty, 1);
                    }
                }
            }
        }
        let mut ans = vec![0 as i64; 5];
        for (_, mt) in mp.iter() {
            for (_, &cnt) in mt.iter() {
                ans[cnt as usize] += 1;
            }
        }
        ans[0] = (n as i64-1)*(m as i64-1) - (ans[1]+ans[2]+ans[3]+ans[4]) as i64;
        ans
    }
}
use std::collections::BTreeMap;

impl Solution {
    pub fn max_increasing_cells(a: Vec<Vec<i32>>) -> i32 {
        let mut bt: BTreeMap<i32, Vec<usize>> = BTreeMap::new();
        let (n, m) = (a.len(), a[0].len());
        for i in 0..n {
            for j in 0..m {
                if let Some(v)=bt.get_mut(&a[i][j]) {
                    v.push(i * m + j);
                } else {
                    bt.insert(a[i][j], vec![i * m + j]);
                }
            }
        }

        let (mut r, mut c) = (vec![0; n], vec![0; m]);
        let mut f = vec![vec![0; m]; n];
        for (_, v) in bt.iter() {
            for p in v.iter() {
                let (x, y) = (p/m, p%m);
                f[x][y] = r[x].max(c[y]) + 1;
            }
            for p in v.iter() {
                let (x, y) = (p/m, p%m);
                r[x] = r[x].max(f[x][y]);
                c[y] = c[y].max(f[x][y]);
            }
        }
        *r.iter().max().unwrap().max(c.iter().max().unwrap())
    }
}
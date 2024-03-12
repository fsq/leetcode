use std::collections::HashSet;

impl Solution {
    pub fn difference_of_distinct_values(mut a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (n, m) = (a.len(), a[0].len());
        let mut tl = vec![vec![0; m]; n];
        let mut br = vec![vec![0; m]; n];

        fn dotl(tl: &mut Vec<Vec<i32>>, a: &Vec<Vec<i32>>, mut i: usize, mut j: usize) {
            let mut hs = HashSet::new();
            while i<a.len() && j<a[0].len() {
                tl[i][j] = hs.len() as i32;
                hs.insert(a[i][j]);
                i += 1;
                j += 1;
            }
        }

        fn dobr(br: &mut Vec<Vec<i32>>, a: &Vec<Vec<i32>>, mut i: usize, mut j: usize) {
            let mut hs = HashSet::new();
             while i<a.len() && j<a[0].len() {
                br[i][j] = hs.len() as i32;
                hs.insert(a[i][j]);
                i -= 1;
                j -= 1;
            }
        }
        
        for j in 0..m {
            dotl(&mut tl, &a, 0, j);
            dobr(&mut br, &a, n-1, j);
        }

        for i in 1..n {
            dotl(&mut tl, &a, i, 0);
            dobr(&mut br, &a, i, m-1);
        }

        for i in 0..n {
            for j in 0..m {
                a[i][j] = (tl[i][j] - br[i][j]).abs();
            }
        }
        a
    }
}
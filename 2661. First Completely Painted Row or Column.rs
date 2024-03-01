impl Solution {
    pub fn first_complete_index(p: Vec<i32>, a: Vec<Vec<i32>>) -> i32 {
        let n = a.len();
        let m = a[0].len();
        let mut pos = vec![0; n*m];
        let mut r = vec![0; n];
        let mut c = vec![0; m];
        for i in 0..n {
            for j in 0..m {
                pos[(a[i][j] as usize) - 1] = i*m + j;
            }
        }
        for (i, &num) in p.iter().enumerate() {
            let p = pos[(num as usize) - 1];
            let x = p / m;
            let y = p % m;
            r[x] += 1;
            c[y] += 1;
            if (r[x]==m || c[y]==n) {
                return i as i32;
            }
        }
        -1
    }
}
impl Solution {

    const dx: [i32; 3] = [-1, 0, 1];

    pub fn dfs(a: &Vec<Vec<i32>>, f: &mut Vec<Vec<i32>>, x: usize, y: usize) -> i32 {
        if f[x][y] != -1 {
            return f[x][y];
        }
        f[x][y] = 0;
        for d in 0..3 {
            let (tx, ty) = ((x as i32+Self::dx[d]) as usize, y + 1);
            if tx>=0 && tx<a.len() && ty>=0 && ty<a[0].len() && a[tx][ty]>a[x][y] {
                f[x][y] = f[x][y].max(Self::dfs(a, f, tx, ty) + 1);
            }
        }
        f[x][y]
    }

    pub fn max_moves(a: Vec<Vec<i32>>) -> i32 {
        let mut f = vec![vec![-1; a[0].len()]; a.len()];
        (0..a.len()).map(|x| Self::dfs(&a, &mut f, x, 0)).max().unwrap()
    }
}
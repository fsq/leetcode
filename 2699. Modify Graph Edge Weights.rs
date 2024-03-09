use std::cmp;

impl Solution {
    pub fn modified_graph_edges(n: i32, mut edges: Vec<Vec<i32>>, src: i32, dest: i32, target: i32) -> Vec<Vec<i32>> {
        let (n, src, dest) = (n as usize, src as usize, dest as usize);
        let INF = 1000000007;
        let mut f = [[INF; 101]; 101];
        let mut x = 0;
        edges.iter_mut()
        .filter(|e: &&mut Vec<i32>| e[2]==-1)
        .for_each(|e: &mut Vec<i32>| e[2]=INF);
        for pr in edges.iter() {
            let (x, y) = (pr[0] as usize, pr[1] as usize);
            f[x][y] = pr[2];
            f[y][x] = pr[2];
        }
        (0..n).for_each(|i| f[i][i] = 0);

        for k in 0..n {
            for i in 0..n {
                for j in 0..n {
                    f[i][j] = f[i][j].min(f[i][k] + f[k][j]);
                }
            }
        }

        if f[src][dest] < target {
            return vec![];
        }
        if f[src][dest] == target {
            return edges;
        }
        
        let mut done = false;
        for e in edges.iter_mut() {
            if e[2]==INF {
                if (!done) {
                    e[2] = 1;
                    f[e[0] as usize][e[1] as usize] = 1;
                    f[e[1] as usize][e[0] as usize] = 1;
                    for i in 0..n {
                        for j in 0..n {
                            f[i][j] = f[i][j].min(cmp::min(
                                f[i][e[0] as usize] + e[2] + f[e[1] as usize][j],
                                f[i][e[1] as usize] + e[2] + f[e[0] as usize][j],
                            ));
                        }
                    }
                    if f[src][dest] <= target {
                        e[2] += target - f[src][dest];
                        done = true;
                    }
                } else {
                    e[2] = INF;
                }
            }
        }
        if done {
            edges
        } else {
            vec![]
        }
    }
}
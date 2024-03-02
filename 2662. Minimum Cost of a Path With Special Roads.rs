use std::cmp;

impl Solution {
    pub fn minimum_cost(start: Vec<i32>, target: Vec<i32>, special_roads: Vec<Vec<i32>>) -> i32 {
        let mut p: Vec<(i32, i32)> = Vec::new();
        let INF: i32 = 10_0000_0007;
        let mut dis = [[INF; 405]; 405];
        p.push((start[0], start[1]));
        for road in special_roads.iter() {
            p.push((road[0], road[1]));
            p.push((road[2], road[3]));
            dis[p.len()-2][p.len()-1] = road[4];
        }
        p.push((target[0], target[1]));
        for i in 0..p.len() {
            for j in 0..p.len() {
                if (dis[i][j]==INF) {
                    dis[i][j] = (p[i].0-p[j].0).abs() + (p[i].1-p[j].1).abs();
                }
            }
        }

        let mut d = vec![INF; p.len()];
        let mut vis = vec![false; p.len()];
        d[0] = 0;
        vis[0] = true;
        for t in 1..p.len() {
            let mut id = 0;
            let mut mind = INF;
            for (i, &x) in d.iter().enumerate() {
                if (!vis[i] && x<mind) {
                    mind = x;
                    id = i;
                }
            }
            vis[id] = true;
            for j in 0..p.len() {
                if (!vis[j]) {
                    d[j] = cmp::min(d[j], d[id]+dis[id][j]);
                }
            }
        }
        d[p.len()-1]
    }
}
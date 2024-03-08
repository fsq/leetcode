use std::collections::VecDeque;

impl Solution {

    pub fn getCC(x: usize, e: &Vec<Vec<usize>>, vis: &mut Vec<bool>) -> Vec<usize> {
        let mut cc = Vec::<usize>::new();
        vis[x] = true;
        cc.push(x);
        let mut q = VecDeque::new();
        q.push_back(x);
        while !q.is_empty() {
            let x = q.pop_front().unwrap();
            for &y in e[x].iter() {
                if !vis[y] {
                    vis[y] = true;
                    q.push_back(y);
                    cc.push(y);
                }
            }
        }
        cc
    }

    pub fn isCCC(e: &Vec<Vec<usize>>, a: Vec<usize>) -> i32 {
        let n = a.len();
        if n * (n-1) == a.iter().map(|&x| e[x].len()).sum::<usize>() {
            1
        } else {
            0
        }
    }

    pub fn count_complete_components(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut e = vec![vec![0 as usize; 0]; n];
        for pr in edges.iter() {
            let (x, y) = (pr[0] as usize, pr[1] as usize);
            e[x].push(y);
            e[y].push(x);
        }
        let mut vis = vec![false; n];
        let mut ans = 0;
        for x in 0..n {
            if !vis[x] {
                ans += Self::isCCC(&e, Self::getCC(x, &e, &mut vis));
            }
        }
        ans
    }
}
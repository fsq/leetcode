use std::collections::HashMap;
use std::collections::HashSet;

impl Solution {
    pub fn fac(x: i32) -> Vec<usize> {
        let mut x = x as usize;
        let mut f = vec![];
        let mut d = 2 as usize;
        while d <= (x as f64).sqrt().floor() as usize {
            if x % d == 0 {
                f.push(d);
                while x % d == 0 {
                    x /= d;
                }
            } else {
                d += 1;
            }
        }
        if x > 1 {
            f.push(x);
        }
        f
    }

    pub fn can_traverse_all_pairs(nums: Vec<i32>) -> bool {
        if nums.len() == 1 {
            return true;
        }
        let nums: HashSet<i32> = HashSet::from_iter(nums);
        if nums.contains(&1) {
            return false;
        }
        let n = nums.len();
        let mut m: HashMap<usize, Vec<usize>> = HashMap::new();
        nums.iter().enumerate().for_each(|(i, &x)| {
            Self::fac(x).iter().for_each(|&x| {
                if let Some(v)=m.get_mut(&x) {
                    v.push(i);
                } else {
                    m.insert(x, vec![i]);
                }
            })
        });

        let mut fa = vec![0; n];
        (0..n).for_each(|x| fa[x]=x);
        fn find(fa: &mut Vec<usize>, x: usize) -> usize {
            if fa[x]!=x {
                fa[x] = find(fa, fa[x])
            }
            fa[x]
        };

        let mut cc = n;
        m.iter().for_each(|(&key, v): (&usize, &Vec<usize>)| {
            for i in 1..v.len() {
                let (x,y) = (v[0], v[i]);
                let (fx, fy) = (find(&mut fa, x), find(&mut fa, y));
                if fx != fy {
                    fa[fx] = fy;
                    cc -= 1;
                }
            }
        });

        cc == 1
    }
}
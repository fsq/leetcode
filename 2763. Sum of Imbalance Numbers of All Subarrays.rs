impl Solution {
    pub fn sum_imbalance_numbers(a: Vec<i32>) -> i32 {
        let mut ans = 0;
        let n = a.len();
        for i in 0..n {
            let mut c = vec![false; n+2];
            let mut mn = a[i];
            let mut mx = a[i];
            c[a[i] as usize] = true;
            let mut inb = 0;
            for j in i+1..n {
                let x = a[j];
                if !c[x as usize] {
                    // is x imb?
                    if x>0 && !c[x as usize-1] && mn<x-1 {
                        inb += 1;
                    }
                    // x+1 become not imb?
                    if c[x as usize+1] && mn<x {
                        inb -= 1;
                    }
                    // next larger become imb? then next larger==mn
                    if mn>x+1 {
                        inb += 1;
                    }
                }
                mn = mn.min(x);
                mx = mx.max(x);
                c[x as usize] = true;
                ans += inb;
            }
        }
        ans
    }
}
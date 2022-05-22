use std::collections::BTreeSet;
use proconio::input;

fn main() {
    input! {
        n : usize,
        w : usize,
        a : [usize; n]
    }

    let mut ans = BTreeSet::new();
    for i in 0..n {
        if a[i] <= w { ans.insert(a[i]); }
        for j in i+1..n {
            if a[i] + a[j] <= w { ans.insert(a[i] + a[j]); }
            for k in j+1..n {
                if a[i] + a[j] + a[k] <= w { ans.insert(a[i] + a[j] + a[k]); }
            }
        }
    }

    println!("{}", ans.len());
}
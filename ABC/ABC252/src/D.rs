use std::collections::BTreeMap;
use proconio::input;

fn main() {
    input! {
        n : usize,
        a : [usize; n]
    }

    let mut ans = n * (n-1) / 2 * (n-2) / 3;

    let mut mp = BTreeMap::new();
    for &a in a.iter() { *mp.entry(a).or_insert(0) += 1; }

    for (_, &c) in mp.iter() {
        ans -= c * (c-1) / 2 * (n - c);
        ans -= c * (c-1) / 2 * (c-2) / 3;
    }

    println!("{}", ans);
}
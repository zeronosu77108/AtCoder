use std::collections::BTreeSet;
use proconio::input;

fn main() {
    input! {
        st : [(String, i64)]
    }

    let mut set = BTreeSet::new();
    let mut max = -1;
    let mut ans = 0;
    for (i, (s,t)) in st.into_iter().enumerate() {
        if set.insert(s) {
            if chmax(&mut max, t) { ans = i + 1; }
        }
    }

    println!("{}", ans);
}

fn chmax<T>(x:&mut T, y:T) -> bool where T : std::cmp::PartialOrd { if *x < y { *x = y; true } else { false } }
fn chmin<T>(x:&mut T, y:T) -> bool where T : std::cmp::PartialOrd { if *x > y { *x = y; true } else { false } }
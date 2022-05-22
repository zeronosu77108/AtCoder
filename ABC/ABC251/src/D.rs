use itertools::Itertools;
use proconio::input;

fn main() {
    input! { _w : usize }

    let mut ans = vec![];
    for i in 1..=100-1 { ans.push(i); }
    for i in (100..=10000-1).step_by(100) { ans.push(i); }
    for i in (10000..=1000000-1).step_by(10000) { ans.push(i); }
    ans.push(1_000_000);

    println!("{}\n{}", ans.len(), ans.iter().join(" "));
}
use std::cmp::Reverse;
use std::collections::{BinaryHeap, BTreeSet};
use proconio::input;

fn main() {
    input! {
        n : usize,
        l : usize,
        a : [usize; n]
    }


    let mut pq : BinaryHeap<_> = a.iter().map(|&a| Reverse(a)).collect();

    let sum = a.iter().sum::<usize>();
    if l != sum { pq.push(Reverse(l - sum)); }


    let mut ans = 0;
    while pq.len() > 1 {
        let Reverse(a) = pq.pop().unwrap();
        let Reverse(b) = pq.pop().unwrap();
        ans += a + b;
        pq.push(Reverse(a + b));
    }

    println!("{}", ans );
}
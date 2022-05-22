use itertools::Itertools;
use proconio::input;
use proconio::marker::Usize1;

fn main() {
    input! {
        n : usize,
        m : usize,
        edges : [(Usize1, Usize1, usize); m]
    }

    let mut g = vec![vec![]; n];
    for (i, &(a,b,c)) in edges.iter().enumerate() {
        g[a].push((b,c,i));
        g[b].push((a,c,i));
    }

    let mut used = vec![false; m];
    dijkstra(0, &g, &mut used);

    println!("{}", (1..=m).filter(|i| used[i-1]).join(" "))
}

fn dijkstra<T>(s:usize, g:&Vec<Vec<(usize,T, usize)>>, used:&mut Vec<bool>) -> Vec<Option<T>>
where
    T : Clone + Copy + num::Zero + std::ops::Add + std::cmp::Ord
{
    let mut dist = vec![None; g.len()];
    dist[s] = Some(std::cmp::Reverse(T::zero()));
    let mut pq = std::collections::BinaryHeap::from(vec![(std::cmp::Reverse(T::zero()), s, None)]);

    while let Some((std::cmp::Reverse(c),v, i)) = pq.pop() {
        if let Some(std::cmp::Reverse(d)) = *&dist[v] {
            if d < c { continue }
            if let Some(i) = i { used[i] = true; }
            for &(u, c, j) in g[v].iter() {
                if chmax(&mut dist[u], Some(std::cmp::Reverse(d + c))) {
                    pq.push((dist[u].unwrap().into(), u, Some(j)));
                }
            }
        }
    }

    dist.into_iter().map(|d| match d {Some(std::cmp::Reverse(x)) => Some(x), _ => None}).collect()
}

fn chmax<T>(x:&mut T, y:T) -> bool where T : std::cmp::PartialOrd { if *x < y { *x = y; true } else { false } }
fn chmin<T>(x:&mut T, y:T) -> bool where T : std::cmp::PartialOrd { if *x > y { *x = y; true } else { false } }
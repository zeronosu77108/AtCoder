use std::collections::VecDeque;
use itertools::Itertools;
use proconio::input;
use proconio::marker::Usize1;

fn main() {
    input! {
        n : usize,
        m : usize,
        edges : [(Usize1, Usize1); m]
    }

    let mut g = vec![vec![]; n];
    for (a,b) in edges { g[a].push(b); g[b].push(a); }

    let mut ans1 = Vec::with_capacity(n-1);
    let mut visited = vec![false; n];
    dfs(0, &mut visited, &mut ans1, &g);
    let mut ans2 = Vec::with_capacity(n-1);
    let mut visited = vec![false; n];
    bfs(0, &mut visited, &mut ans2, &g);

    println!("{}\n{}", ans1.into_iter().join("\n"), ans2.into_iter().join("\n"));
}

fn dfs(v:usize, visited:&mut Vec<bool>, ans:&mut Vec<String>,  g:&Vec<Vec<usize>>) {
    visited[v] = true;

    for &u in g[v].iter() {
        if visited[u] { continue }
        ans.push(format!("{} {}", v+1, u+1));
        dfs(u, visited, ans, g);
    }
}

fn bfs(s:usize, visited:&mut Vec<bool>, ans:&mut Vec<String>, g:&Vec<Vec<usize>>) {
    let mut q = VecDeque::new(); q.push_back(s);

    visited[s] = true;
    while let Some(v) = q.pop_front() {
        for &u in g[v].iter() {
            if visited[u] { continue }
            visited[u] = true;
            ans.push(format!("{} {}", v+1, u+1));
            q.push_back(u);
        }
    }
}
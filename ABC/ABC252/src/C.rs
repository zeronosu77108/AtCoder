use proconio::input;
use proconio::marker::{Bytes, Chars};

fn main() {
    input! {
        n : usize,
        s : [Bytes; n]
    }
    // i に揃える
    let mut ans = std::usize::MAX;
    for i in 0..10 {
        let mut used = vec![false; n];
        let mut tmp = 0;
        let mut now = 0;
        let mut a = 0;
        for k in 0..n {
            let mut min = std::usize::MAX;

            for (j, s) in s.iter().enumerate() {
                if used[j] { continue }
                let index = s.iter().position(|&c| (c-b'0') == i as u8).unwrap();
                let t = if now%10 < index || k==0 && index==0 { index - now%10 } else { 10 - now%10 + index };
                if t < min { min=t; a=j; }
            }

            now += min;
            used[a] = true;
            // eprintln!("{} {} {} {}", i, a, min, now);

        }
        // eprintln!("{} {}", i, now);
        ans = ans.min(now);
    }

    println!("{}", ans);
}
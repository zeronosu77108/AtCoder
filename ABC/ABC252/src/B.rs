use proconio::input;
use proconio::marker::Usize1;

fn main() {
    input! {
        n : usize,
        k : usize,
        a : [usize; n],
        b : [Usize1; k]
    }

    let max = *a.iter().max().unwrap();

    println!("{}", if b.iter().any(|&i| a[i] == max) {"Yes"} else {"No"});
}
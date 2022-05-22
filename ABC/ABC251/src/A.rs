use proconio::input;

fn main() {
    input! {
        mut s : String
    }

    let mut ans = s.clone();
    while ans.len() != 6 { ans.push_str(&s.clone()); }
    println!("{}", ans);
}
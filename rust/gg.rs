use std::cmp::Ordering;
use std::io::stdin;
fn main() {
    println!("Enter a number");

    let number = 69;
    let mut guess: String = String::new();

    loop {
        stdin().read_line(&mut guess).expect("Failed");
        println!("You guessed {}", guess);

        let guess: i32 = guess.trim().parse().expect("msg");

        match guess.cmp(&number) {
            Ordering::Less => println!("{}", "Lesser"),
            Ordering::Equal => {println!("{}", "Equal yay"); break;},
            Ordering::Greater => println!("{}", "Greater"),
        }
    }
}

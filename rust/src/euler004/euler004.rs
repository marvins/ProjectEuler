
fn is_palindrome( val: i32 ) -> bool {

    // Convert to string
    let s1: String = val.to_string();
    let s2: String = s1.chars().rev().collect();
    if s1 == s2 {
        return true;
    }
    return false;
}

fn main() {

    let mut answer: i32 = 0;

    // Both numbers are 3 digits long
    for val_a in 100..999 {
        for val_b in 100..999 {

            // Compute the product
            let prod = val_a * val_b;
            if is_palindrome(prod) {
                if prod > answer {
                    answer = prod;
                }
            }
        }
    }
    println!("Answer: {}", answer);
}
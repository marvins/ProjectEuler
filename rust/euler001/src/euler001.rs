
/// Main Driver
fn main() {

    let mut sum = 0;
    for x in 1..1000 {
        // Check if divisible by 3
        if ( x % 3 ) == 0 || 
           ( x % 5 ) == 0 {
            sum += x;
        }
    }
    println!( "Sum: {}", sum );
}
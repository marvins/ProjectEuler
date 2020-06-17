
fn main() {

    let max_val = 4000000; 
    let mut counter = 0;
    let mut sum = 0;

    loop {

        let val = fib( counter );
        if val > max_val {
            break;
        }

        if val % 2 == 0 {
            sum += val;
        }

        // Update counter
        counter += 1;
    }
    println!("{}", sum);
}

fn fib( val: i32 ) -> i32 {
    if val < 2 {
        return val;
    }
    return fib( val - 1 ) + fib( val - 2 );
}
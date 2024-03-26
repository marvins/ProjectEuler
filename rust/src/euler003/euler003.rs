mod sieve;

use sieve::PrimeSieve;

fn main() {

    let target_val: u64 = 20; //600851475143; // Value we are splitting up
    let max_val = target_val / 2;

    // Create a Prime Sieve for iterating over
    let sieve = PrimeSieve::new( max_val );
}
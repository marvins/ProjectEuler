
use std::collections::BTreeSet;

pub struct PrimeSieve {
    max_value: u64,
    primes: BTreeSet<u64>,
}

trait Sieve {
    fn new ( max_value: u64 ) -> Self;
}

impl Sieve for PrimeSieve {
    fn new ( max_value: u64 ) -> PrimeSieve {

        // Begin iterating from 2 until max value
        let mut primes = BTreeSet::new();
        primes.insert(2);
        primes.insert(3);

        for idx in (3..max_value).step_by(2) {
            
            if idx % 10001 == 0 {
                println!("Processing {} of {}, Size: {}", idx, max_value, primes.len());
            }

            // Check if value is divisible by any prime
            let mut is_prime = true;
            for p in &primes {
                if idx % p == 0 {
                    is_prime = false;
                    break;
                }
            }

            if is_prime == true {
                primes.insert( idx );
            }
        }

        return PrimeSieve { max_value: max_value,
                            primes: primes };
    }
}

fn main() {

    let target_val: u64 = 600851475143; // Value we are splitting up
    let max_val = (target_val as f64).sqrt() as u64;

    // Create a Prime Sieve for iterating over
    println!("Starting Prime Sieve Solver");
    let mut ps: PrimeSieve = Sieve::new( max_val );

    let mut pf : u64 = 1;

    for p in &ps.primes {
        
        if target_val % p == 0 {
            println!("Prime Factor: {}", p);
        }

    }
}
pub struct PrimeSieve {
    maxValue: u64,
}

trait Sieve {
    fn new ( maxValue: u64 ) -> Self;
}

impl Sieve for PrimeSieve {
    fn new ( maxValue: u64 ) -> PrimeSieve {
        return PrimeSieve { maxValue: maxValue };
    }
}
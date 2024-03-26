

fn main() {

    let max_value : u64 = 9999999999;

    for val in (100..max_value).step_by(2) {
        let mut solution_found = true;
        for x in 3..21 {
            if val % x != 0 {
                solution_found = false;
                break;
            }
        }
        if solution_found {
            println!("End Result: {val}");
            break;
        }
    }
}
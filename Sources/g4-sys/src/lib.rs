#[no_mangle]
pub extern "C" fn add(value0: i32, value1: i32) -> i32 {
    value0 + value1
}

#[no_mangle]
pub fn rust_function() {
    unsafe { func() }
}

pub fn aaa() {}

//
#[no_mangle]
pub fn create_generator() -> *mut std::ffi::c_void {
    unsafe { CreateGenerator() }
}

#[no_mangle]
pub fn destroy_generator(instance: *mut std::ffi::c_void) {
    unsafe { DestroyGenerator(instance) }
}

extern "C" {
    pub fn func();
    pub fn CreateGenerator() -> *mut std::ffi::c_void;
    pub fn DestroyGenerator(instance: *mut std::ffi::c_void);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }
}

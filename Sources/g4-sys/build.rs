use cmake;

fn main() {
    let dst = cmake::build("../..");
    println!("cargo:rustc-link-search=native={}", dst.display());

    // staticライブラリとして他に利用するライブラリはなし
    println!("cargo:rustc-link-lib=static=g4");

    // C++ソースコードの場合は必ずこれを追加すること
    println!("cargo:rustc-link-lib=dylib=stdc++");
}

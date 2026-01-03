# llvm-opt-tutor

👋Hi,there! 

This project was heavily inspired by **[llvm-tutor](https://github.com/banach-space/llvm-tutor)**. Having used it as my own entry point into the world of LLVM. I found it to be an incredible resource for learning pass development. I am now building this project to further my hands-on experience with compiler optimization algorithms.

This reposity is a collection of out-of-tree opt passes - based on **LLVM-21**.

**llvm-opt-tutor** is a collection of self-contained reference LLVM passes especially those passes for optimization. It's a tutorial that targets novice and aspiring LLVM developers like me. All passes are organized in the following manner :

- **🎯[Motivation]:** Why do we need this optimization?
- **🛠️[Toy Implementation]:** How does the algorithm work in its simplest form?
- **🔍[Debug & Analysis]:**How do we verify and observe the transformation?
- **⚙️[LLVM Internals]:**How do the pros do it?

## Table of Contents

- Development Environment
- **Part 1:** Canonicalization & Cleanup
  - **Module 1.1:** Mem2Reg & SROA 
- **Part 2:** Scalar Optimization 
- **Part 3:** Loop Optimizations
- **Part 4:** IPO & Advanced
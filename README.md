**Dot Product Implementation**

Link to CUDA implementation: https://colab.research.google.com/drive/1dxFkxKCokf-MbbmoTKiWeVs1MpCF6-hx?usp=sharing

Important Notes:
- Each kernel result were tested on an input size of 2^20 and the average time was taken on 30 number of runs.
- The number of blocks and threads for each input sizes are both 1024 in length.
- The implementation for CUDA uses cooperative groups with prefetching

**I. Analysis**

**Average Runtime (microseconds)**

 Kernel | 2^20 | 2^24 | 2^28
--- | --- | --- | ---
**C** | 4,633.33 us | 129,600.00 us | 1,289,266.67 us 
**x86-64**| 1,433.33 us | 28,366.67 us | 271,266.67 us
**x86-SIMD** | 1,133.33 us | 16,166.67 us | 246,133.33 us 
**CUDA** | 355.81us | 590.65 us | 80,138.00 us

**Measuring Performance of x86-64, x86-SIMD, and CUDA to C Implementation**
(How many times faster than normal C implementation)
 Kernel | 2^20 | 2^24 | 2^28
--- | --- | --- | ---
**x86-64**| 3.23 | 4.57 | 4.75
**x86-SIMD** | 4.09 | 8.02 | 5.24 
**CUDA** | 13.02 | 219.42 | 16.09 

**Measuring Performance of x86-SIMD and CUDA to x86-64**
(How many times faster than x86-64)
 Kernel | 2^20 | 2^24 | 2^28
--- | --- | --- | ---
**x86-SIMD** | 1.26 | 1.75 | 5.24 
**CUDA** | 4.02 | 48.03 | 1.10

**Measuring Performance of CUDA to x86-SIMD**
(How many times faster than x86-SIMD)
 Kernel | 2^20 | 2^24 | 2^28
--- | --- | --- | ---
**CUDA** | 3.19 | 27.37 | 3.07

   From the provided table, it is observable that the assembly implementation of dot product is always faster than normal C Programming. This is mainly because it takes several instructions to run a for loop in when translated in assembly than doing a LOOP instruction call in assembly. x86-SIMD provides an even faster computation in computing the dot matrix as it can process multiple data with a single instruction. Specifically, a single instruction can perform operations on 8 or 16 integer elements, in which you could multiply, add, and other operations on the elements. For the CUDA implementation, cooperative groups was used along with prefetching in order to obtain huge perfomance gain by having faster execution time. Threads are partitions into smaller group of threads and performs mathematical operations and binary reduction. The execution time increases as smaller group of threads are synchronized and does not wait for all the threads in a block to reach a certain barrier of the code. In addition, prefetching sends the GPU data before it is needed while the CPU executes instructions. As a result, memory latency (cost of transferring data) to decrease. 

   Although, the average execution time for all array sizes is fastest in CUDA, the consequence of GPU is the overheard costs since running the program in x64 is directly occuring in the CPU and does not need and time to transfer data. Consider the execution time of running CUDA for 30 times (results of V.). The execution time of for the kernel is 11.61 ms. Considering the overhead time (Data Transfer Time, GPU Page Fault Groups, Page Throttling), the actual runtime for executing the kernel is 20.800 ms. Consider the second best performing kernel, which is the implementation for x86-SIMD (results of IV.), the execution time for running an array size of 2^20 is 43.000 ms. With prefetching and cooperative groups implementation of CUDA, it still performs better than the x64-SIMD by 2.06 times. 

**II. C Program  Result**

![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/2e0893d5-265c-4f5f-9e73-ed5d70546ab6)

**III. x86-64 Program Result**

![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/b1d023c4-1d6c-468a-a2c2-684e6c9888ee)


**IV. x86-SIMD Program Result**

![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/44a2b189-39b8-410c-96e9-aae4b78eaaba)

- Register YMM0 stores the base address of pointer a, and loads the initial first 8 elements
![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/69c3b4ba-ff65-4dce-a201-fa0d2ddd479b)

- Register YMM1 stores the base address of pointer b, and loads the initial first 8 elements

  ![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/25bdff36-b353-477c-8813-0e2472e2bf23)

- Register YMM2 stores the vertical multiplation of pointer a and pointer b

  ![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/f7b61922-4d95-4832-90b1-442e4e2163bf)

- Register YMM3 stores the horizontal multiplaction of register YMM2 (Duplicates of the horizontal additions will occur)

  ![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/9d9da813-c8f1-4283-91f0-e790e18d8bb0)


**V. Cuda Program Result**

![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/bed41d84-9699-4ff8-a113-ceb91ced3795)

Overhead time 

![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/1ed7fe60-8d0b-47aa-8d81-6ce7a7595871)

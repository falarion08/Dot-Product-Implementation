![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/bd976b4e-3f71-40c2-8309-e34063b6164c)# Dot Product Implementation
Link to CUDA implementation: https://colab.research.google.com/drive/1dxFkxKCokf-MbbmoTKiWeVs1MpCF6-hx?usp=sharing

Note:
- Each kernel result were tested on an input size of 2^20 and the average time was taken on 30 number of runs.
- The number of blocks and threads for each input sizes are both 1024 in length.

I.

**Average Runtime (microseconds)**

 Kernel | 2^20 | 2^24 | 2^28
--- | --- | --- | ---
**C** | 4,633.33 us | 129,600.00 us | 1,289,266.67 us 
**x86-64**| 1,433.33 us | 283,66.67 us | 271,266.67 us
**x86-SIMD** | 1,133.33 us | 16,166.67 us | 246,133.33 us 
**CUDA** | 355.81us | 590.65 us | 8,0138.00 us

II. C Program  Result

![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/2e0893d5-265c-4f5f-9e73-ed5d70546ab6)

III. x64 Program Result

![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/b1d023c4-1d6c-468a-a2c2-684e6c9888ee)

IV. Assembly Program Result

![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/44a2b189-39b8-410c-96e9-aae4b78eaaba)

V. Cuda Program Result

![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/bed41d84-9699-4ff8-a113-ceb91ced3795)

Overhead time 

![image](https://github.com/falarion08/Dot-Product-Implementation/assets/113824865/1ed7fe60-8d0b-47aa-8d81-6ce7a7595871)

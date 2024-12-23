# **Grayscale Image Conversion Performance Analysis**

### The program is done under the requirements of **LBYARCH’s MP2** with the following specs:
<img src="./screenshots/Specs.jpg" alt="LBYARCH specs" width="750">

### By: del Rosario, Johann James & Sityar, Lester Anthony Jr.

---

### **Code**
This directory contains the C and Assembly files for the grayscale image conversion program. The main focus is on the implementation and performance of `imgCvtGrayInttoFloat()`.

### **Screenshots**
This directory contains screenshots for the project, including sample outputs and benchmarks captured during both **debug** and **release** modes.

---

## **The C Program**

The C program acts as a driver for testing both the **C kernel** and the **Assembly kernel** implementations. It includes:
- **Timing Mechanism**: Tracks the average execution time and the number of executions for each kernel.
- **Sanity Check**: Compares the results of both kernels to ensure correctness. For all sample images, the outputs are validated to match.

The pixel values for grayscale images are generated by simulating repetitive patterns, ensuring consistent test conditions.

---

## **Kernel Comparison and Analysis**

**Link to spreadsheet of calculated times**: [Spreadsheet Link](https://docs.google.com/spreadsheets/d/1qkgr50_etCSEWVcwX_pWXPhYjsyRcSBH_XRQo5S-RwE/edit?usp=sharing)

### **Average Time Results**

| Kernel       | Average Time (s) |
|--------------|-------------------|
| **C Kernel** | **0.002**         |
| **ASM Kernel** | **0.0036**      |

**The Assembly kernel is 78.33% slower than the C kernel.**

### **Test Configurations**
The tests were conducted with the following image sizes:
- **10 × 10 pixels**
- **100 × 100 pixels**
- **1000 × 1000 pixels**

---

## **Sample Results**

### **10 × 10 Pixels**
- **C Kernel**: 0.0 seconds  
- **ASM Kernel**: 0.0 seconds  

### **100 × 100 Pixels**
- **C Kernel**: 0.0 seconds  
- **ASM Kernel**: 0.0 seconds  

### **1000 × 1000 Pixels**
- **C Kernel**: 0.002 seconds  
- **ASM Kernel**: 0.004 seconds  

---

## **Sample Output**

<img src="./screenshots/SampleOutput.jpg" alt="LBYARCH specs" width="750">

---



## **Conclusion**

The program provides a comparative analysis of the performance of C and Assembly implementations for converting grayscale images. 

**Key Findings**:
- The **C Kernel** outperformed the **ASM Kernel** in terms of average execution time:
  - **C Average**: **0.002 seconds**
  - **ASM Average**: **0.0036 seconds**
- Compiler optimizations likely contributed to the superior performance of the C kernel.

Further improvements could focus on:
- Exploring advanced SIMD instructions.

--- 

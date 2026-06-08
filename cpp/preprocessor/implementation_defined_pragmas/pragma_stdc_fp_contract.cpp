/*
    - #pragma STDC FP_CONTRACT ON/OFF is used when there is need of more accurate results with floating point numbers.
    - (Used for performance optimization in heavy floating-point math.)
    - Generally a CPU does the below tasks in below showed operations:
      Task: (a * b) + c;    Operations: 1. Multiply; 2. Rounding; 3. Add; 4.Rounding
    - Here two times rounding operation is done, which may differ the results when large size floating point numbers are available.
    - So in order to avoid rounding two times, this pragma is used which rounds only one time for above task done at last.
    - The default value of this pragma depends on compiler(implementation defined). Generally this is ON by default for most of the compilers(GCC, Clang, etc.)
      but for msvc it depends on the control given in respective settings file.
*/

#include <iostream>
//#include <iomanip>
#include <cstdio>
using namespace std;

#pragma STDC FP_CONTRACT OFF

int main() {

    double a = 1e308;
    double b = 1e-308;
    double c = -1.0;
    double z = (a * b) + c;   // ON -> -1.11022e-16;  OFF -> -1.11022e-16
    //setprecision(2);
    //cout << z << endl;
    //setprecision(6); // default precision reset

    printf("%.2f", z);       // ON -> -0.00;  OFF -> -0.00  // However this also doesn't shows any effect, I think need more precise floating to show the difference

    return 0;
}

#include <iostream>
using namespace std;

/// @brief
// Data Type	        Memory(bytes)       Range	                    Format Specifier
// ------------------------------------------------------------------------------------------
// short int	            2              -32,768 to 32,767	            %hd
// unsigned short int	    2               0 to 65,535	                    %hu
// unsigned int	            4             0 to 4,294,967,295	            %u  
// int	                    4            -2,147,483,648 to 2,147,483,647	%d
// long int	                4           -2,147,483,648 to 2,147,483,647	    %ld
// unsigned long int	    4           0 to 4,294,967,295	                %lu
// long long int	        8           -(2^63) to (2^63)-1	                %lld
// unsigned long long int	8          0 to 18,446,744,073,709,551,615	    %llu
// signed char	            1           -128 to 127	                        %c
// unsigned char	        1           0 to 255	                        %c
// float	                4           1.2E-38 to 3.4E+38	                %f
// double	                8           2.2E-308 to 1.8E+308	            %lf
/// @return

/// @brief 
// Time Complexity: O(1)
// Space Complexity: O(1)
/// @return 
int main(){
    int i;
    char c;
    float f;
    double d;
    cout << "Size of int: " << sizeof(i) << endl;
    cout << "Size of char: " << sizeof(c) << endl;
    cout << "Size of float: " << sizeof(f) << endl;
    cout << "Size of double: " << sizeof(d) << endl;
    return 0;
}


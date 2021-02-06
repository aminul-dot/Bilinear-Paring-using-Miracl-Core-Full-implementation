# Bilinear-Paring-using-Miracl-Core-Full-implementation

# Description
# Bilinear Pairing
With pair-based cryptography we have two cyclic groups (G1 and G2), and which are of an order of a prime number (n). A pairing on (G1,G2,GT) defines the function e:G1×G2→GT, and where g1 is a generator for G1 and g2 is a generator for G2. If we have the points of U1 and U2 on G1 and V1 and V2 on G2, we get the bilinear mapping of:
e(U1+U2,V1)=e(U1,V1)×e(U2,V1)
e(U1,V1+V2)=e(U1,V1)×e(U1,V2)
If U is a point on G1, and V is a point on G2, we get:
e(aU,bV)=e(U,V)^{ab}

# Installation of Miracl Library

1. Visit https://github.com/miracl/core/tree/master/cpp and download the miracl/core zip file.
2. To create a 32-bit library python3 config32.py or To create a 64-bit library python3 config64.py
3 Then select options 1, 3, 7, 28, 30, 36, 37 and 40, which are fixed for the example programs. (For a 16-bit build select 1, 4 and 6). Select 0 then to exit.
4. For compilation of  Bilinear.cpp put this file in cpp folder and than open terminal and run this g++ -O2  Bilinear.cpp core.a -o bilinear
5. ./bilinear

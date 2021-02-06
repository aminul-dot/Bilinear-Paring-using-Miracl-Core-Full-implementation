#include "core.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <time.h>
#include "fp12_BN254.h"
#include "ecp2_BN254.h"
#include "ecp_BN254.h"
#include "arch.h"
#include "ecp_BN254.h"

#include "pair_BN254.h"

using namespace B256_56;
using namespace BN254;
using namespace core;

namespace BN254 {
static void PAIR_line(FP12 *, ECP2 *, ECP2 *, FP *, FP *);
static void PAIR_double(ECP2 *, FP2 *, FP2 *, FP2 *);
static void PAIR_add(ECP2 *, ECP2 *B, FP2 *, FP2 *, FP2 *);
static void PAIR_pack(FP4 *, FP2 *, FP2 *, FP2 *);
static void PAIR_unpack(FP12 *, FP4 *, FP *, FP *);
static void glv(BIG u[2], BIG);
static void gs(BIG u[4], BIG);
}

using namespace std;
//#ifdef HAS_MAIN
int main()
{ 

    int i;
    char byt[32];
    csprng rng;
    BIG xa, xb, ya, yb, w, a, b, t1, q, u[2], v[4], m, r;
    ECP2 P, G;
    ECP Q, R;
    FP12 g, gp;
    FP4 t, c, cp, cpm1, cpm2;
    FP2 x, y, X;
    
    int val1;
    int val2;
    int product;
    BIG e;
    BIG v1;
    BIG v2;
    BIG res1;
    BIG res2;
    
    BIG res3;
    
    
    BIG_one(v1);
    BIG_one(v2);
    
  
    cout<<"enter the first G1 coefficient"<<endl;
    cin>>val2;
    cout<<"enter the first G2 coefficient"<<endl;
    cin>>val1;
    BIG_imul(res2, v2, val2);
    BIG_imul(res1, v1, val1);

    BIG_output(res1);
    cout<<endl;
    BIG_output(res2);
    cout<<endl;
    
    BIG_smul(res3, res1,res2);
     
    
    BIG_rcopy(a, CURVE_Order);
    BIG_rcopy(b, CURVE_Order);
    FP2_from_BIGs(&X, a, b);

    BIG_rcopy(xa, CURVE_Gx);
    BIG_rcopy(ya, CURVE_Gy);

    ECP_set(&Q, xa, ya);
    cout<<"G1 is set which is Q"<<endl;
   

  

    BIG_rcopy(xa, CURVE_Pxa);
    BIG_rcopy(xb, CURVE_Pxb);
    BIG_rcopy(ya, CURVE_Pya);
    BIG_rcopy(yb, CURVE_Pyb);

    FP2_from_BIGs(&x, xa, xb);
    FP2_from_BIGs(&y, ya, yb);

    ECP2_set(&P, &x, &y);
    cout<<"G2 is set which is P"<<endl;
   
    
    cout<<("Q= ");
    ECP_output(&Q);
    cout<<endl;
    
     printf("R=Q ");
     ECP_copy(&R,&Q);
     ECP_output(&R);
     cout<<endl;

    cout<<("P= ");
    ECP2_output(&P);
    cout<<endl;
    
     cout<<("G=P ");
     ECP2_copy(&G,&P);
     ECP2_output(&G);
     cout<<endl;
    
    
    PAIR_G1mul(&R, res2);
    PAIR_G2mul(&G, res1);
    
    for (i = 0; i < 1000; i++ )
    {
        PAIR_ate(&gp, &G, &R);
        PAIR_fexp(&gp);
    }
    cout<<"LHS Pairing e(res2.G,res1.R) where  R is a point on G1, G is a point on G2"<<endl;
    FP12_output(&gp);
    printf("\n");
    
    printf("\n");
    printf("\n");
    
    

    for (i = 0; i < 1000; i++ )
    {
        PAIR_ate(&g, &P, &Q);
        PAIR_fexp(&g);
    }
    
    PAIR_GTpow(&g, res3);
    
    
    cout<<"RHS Pairing e(P,Q)^res3  where res3 = res1.res2 , Q is a point on G1, P is a point on G2"<< endl;
    FP12_output(&g);
    printf("\n");

 
    cout<<"LHS = RHS"<<endl;
    cout<<"e(res2.G,res1.R) = e(P,Q)^res3"<<endl;
    return 0;
}

#define DCT_ISLOW_SUPPORTED
#define DCTSIZE 8
#define BITS_IN_JSAMPLE 8
#define MULTIPLY16C16(var,const)  ((var) * (const))
#define DCTELEM int
#define INT32   int
#define GLOBAL
#define RIGHT_SHIFT(x,shft)	((x) >> (shft))
#define ONE	((INT32) 1)
#define DESCALE(x,n)  RIGHT_SHIFT((x) + (ONE << ((n)-1)), n)
#define SHIFT_TEMPS
#define JPEG_INTERNALS

#ifdef DCT_ISLOW_SUPPORTED


/*
 * This module is specialized to the case DCTSIZE = 8.
 */

#if BITS_IN_JSAMPLE == 8
#define CONST_BITS  13
#define PASS1_BITS  2
#else
#define CONST_BITS  13
#define PASS1_BITS  1		/* lose a little precision to avoid overflow */
#endif

#if CONST_BITS == 13
#define FIX_0_298631336  ((INT32)  2446)	/* FIX(0.298631336) */
#define FIX_0_390180644  ((INT32)  3196)	/* FIX(0.390180644) */
#define FIX_0_541196100  ((INT32)  4433)	/* FIX(0.541196100) */
#define FIX_0_765366865  ((INT32)  6270)	/* FIX(0.765366865) */
#define FIX_0_899976223  ((INT32)  7373)	/* FIX(0.899976223) */
#define FIX_1_175875602  ((INT32)  9633)	/* FIX(1.175875602) */
#define FIX_1_501321110  ((INT32)  12299)	/* FIX(1.501321110) */
#define FIX_1_847759065  ((INT32)  15137)	/* FIX(1.847759065) */
#define FIX_1_961570560  ((INT32)  16069)	/* FIX(1.961570560) */
#define FIX_2_053119869  ((INT32)  16819)	/* FIX(2.053119869) */
#define FIX_2_562915447  ((INT32)  20995)	/* FIX(2.562915447) */
#define FIX_3_072711026  ((INT32)  25172)	/* FIX(3.072711026) */
#else
#define FIX_0_298631336  FIX(0.298631336)
#define FIX_0_390180644  FIX(0.390180644)
#define FIX_0_541196100  FIX(0.541196100)
#define FIX_0_765366865  FIX(0.765366865)
#define FIX_0_899976223  FIX(0.899976223)
#define FIX_1_175875602  FIX(1.175875602)
#define FIX_1_501321110  FIX(1.501321110)
#define FIX_1_847759065  FIX(1.847759065)
#define FIX_1_961570560  FIX(1.961570560)
#define FIX_2_053119869  FIX(2.053119869)
#define FIX_2_562915447  FIX(2.562915447)
#define FIX_3_072711026  FIX(3.072711026)
#endif

#if BITS_IN_JSAMPLE == 8
#define MULTIPLY(var,const)  MULTIPLY16C16(var,const)
#else
#define MULTIPLY(var,const)  ((var) * (const))
#endif

DCTELEM data[64];

/*
 * Perform the forward DCT on one block of samples.
 */

GLOBAL void
jpeg_fdct_islow ()
{
  INT32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
  INT32 tmp10, tmp11, tmp12, tmp13;
  INT32 z1, z2, z3, z4, z5;
  DCTELEM *dataptr;
  int ctr;
  SHIFT_TEMPS

  /* Pass 1: process rows. */
  /* Note results are scaled up by sqrt(8) compared to a true DCT; */
  /* furthermore, we scale the results by 2**PASS1_BITS. */

  dataptr = data;
  for (ctr = DCTSIZE-1; ctr >= 0; ctr--) {
    tmp0 = dataptr[0] + dataptr[7];
    tmp7 = dataptr[0] - dataptr[7];
    tmp1 = dataptr[1] + dataptr[6];
    tmp6 = dataptr[1] - dataptr[6];
    tmp2 = dataptr[2] + dataptr[5];
    tmp5 = dataptr[2] - dataptr[5];
    tmp3 = dataptr[3] + dataptr[4];
    tmp4 = dataptr[3] - dataptr[4];

    /* Even part per LL&M figure 1 --- note that published figure is faulty;
     * rotator "sqrt(2)*c1" should be "sqrt(2)*c6".
     */

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    dataptr[0] = (DCTELEM) ((tmp10 + tmp11) << PASS1_BITS);
    dataptr[4] = (DCTELEM) ((tmp10 - tmp11) << PASS1_BITS);

    z1 = MULTIPLY(tmp12 + tmp13, FIX_0_541196100);
    dataptr[2] = (DCTELEM) DESCALE(z1 + MULTIPLY(tmp13, FIX_0_765366865),
				   CONST_BITS-PASS1_BITS);
    dataptr[6] = (DCTELEM) DESCALE(z1 + MULTIPLY(tmp12, - FIX_1_847759065),
				   CONST_BITS-PASS1_BITS);

    /* Odd part per figure 8 --- note paper omits factor of sqrt(2).
     * cK represents cos(K*pi/16).
     * i0..i3 in the paper are tmp4..tmp7 here.
     */

    z1 = tmp4 + tmp7;
    z2 = tmp5 + tmp6;
    z3 = tmp4 + tmp6;
    z4 = tmp5 + tmp7;
    z5 = MULTIPLY(z3 + z4, FIX_1_175875602); /* sqrt(2) * c3 */

    tmp4 = MULTIPLY(tmp4, FIX_0_298631336); /* sqrt(2) * (-c1+c3+c5-c7) */
    tmp5 = MULTIPLY(tmp5, FIX_2_053119869); /* sqrt(2) * ( c1+c3-c5+c7) */
    tmp6 = MULTIPLY(tmp6, FIX_3_072711026); /* sqrt(2) * ( c1+c3+c5-c7) */
    tmp7 = MULTIPLY(tmp7, FIX_1_501321110); /* sqrt(2) * ( c1+c3-c5-c7) */
    z1 = MULTIPLY(z1, - FIX_0_899976223); /* sqrt(2) * (c7-c3) */
    z2 = MULTIPLY(z2, - FIX_2_562915447); /* sqrt(2) * (-c1-c3) */
    z3 = MULTIPLY(z3, - FIX_1_961570560); /* sqrt(2) * (-c3-c5) */
    z4 = MULTIPLY(z4, - FIX_0_390180644); /* sqrt(2) * (c5-c3) */

    z3 += z5;
    z4 += z5;

    dataptr[7] = (DCTELEM) DESCALE(tmp4 + z1 + z3, CONST_BITS-PASS1_BITS);
    dataptr[5] = (DCTELEM) DESCALE(tmp5 + z2 + z4, CONST_BITS-PASS1_BITS);
    dataptr[3] = (DCTELEM) DESCALE(tmp6 + z2 + z3, CONST_BITS-PASS1_BITS);
    dataptr[1] = (DCTELEM) DESCALE(tmp7 + z1 + z4, CONST_BITS-PASS1_BITS);

    dataptr += DCTSIZE;		/* advance pointer to next row */
  }

  /* Pass 2: process columns.
   * We remove the PASS1_BITS scaling, but leave the results scaled up
   * by an overall factor of 8.
   */

  dataptr = data;
  for (ctr = DCTSIZE-1; ctr >= 0; ctr--) {
    tmp0 = dataptr[DCTSIZE*0] + dataptr[DCTSIZE*7];
    tmp7 = dataptr[DCTSIZE*0] - dataptr[DCTSIZE*7];
    tmp1 = dataptr[DCTSIZE*1] + dataptr[DCTSIZE*6];
    tmp6 = dataptr[DCTSIZE*1] - dataptr[DCTSIZE*6];
    tmp2 = dataptr[DCTSIZE*2] + dataptr[DCTSIZE*5];
    tmp5 = dataptr[DCTSIZE*2] - dataptr[DCTSIZE*5];
    tmp3 = dataptr[DCTSIZE*3] + dataptr[DCTSIZE*4];
    tmp4 = dataptr[DCTSIZE*3] - dataptr[DCTSIZE*4];

    /* Even part per LL&M figure 1 --- note that published figure is faulty;
     * rotator "sqrt(2)*c1" should be "sqrt(2)*c6".
     */

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    dataptr[DCTSIZE*0] = (DCTELEM) DESCALE(tmp10 + tmp11, PASS1_BITS);
    dataptr[DCTSIZE*4] = (DCTELEM) DESCALE(tmp10 - tmp11, PASS1_BITS);

    z1 = MULTIPLY(tmp12 + tmp13, FIX_0_541196100);
    dataptr[DCTSIZE*2] = (DCTELEM) DESCALE(z1 + MULTIPLY(tmp13, FIX_0_765366865),
					   CONST_BITS+PASS1_BITS);
    dataptr[DCTSIZE*6] = (DCTELEM) DESCALE(z1 + MULTIPLY(tmp12, - FIX_1_847759065),
					   CONST_BITS+PASS1_BITS);

    /* Odd part per figure 8 --- note paper omits factor of sqrt(2).
     * cK represents cos(K*pi/16).
     * i0..i3 in the paper are tmp4..tmp7 here.
     */

    z1 = tmp4 + tmp7;
    z2 = tmp5 + tmp6;
    z3 = tmp4 + tmp6;
    z4 = tmp5 + tmp7;
    z5 = MULTIPLY(z3 + z4, FIX_1_175875602); /* sqrt(2) * c3 */

    tmp4 = MULTIPLY(tmp4, FIX_0_298631336); /* sqrt(2) * (-c1+c3+c5-c7) */
    tmp5 = MULTIPLY(tmp5, FIX_2_053119869); /* sqrt(2) * ( c1+c3-c5+c7) */
    tmp6 = MULTIPLY(tmp6, FIX_3_072711026); /* sqrt(2) * ( c1+c3+c5-c7) */
    tmp7 = MULTIPLY(tmp7, FIX_1_501321110); /* sqrt(2) * ( c1+c3-c5-c7) */
    z1 = MULTIPLY(z1, - FIX_0_899976223); /* sqrt(2) * (c7-c3) */
    z2 = MULTIPLY(z2, - FIX_2_562915447); /* sqrt(2) * (-c1-c3) */
    z3 = MULTIPLY(z3, - FIX_1_961570560); /* sqrt(2) * (-c3-c5) */
    z4 = MULTIPLY(z4, - FIX_0_390180644); /* sqrt(2) * (c5-c3) */

    z3 += z5;
    z4 += z5;

    dataptr[DCTSIZE*7] = (DCTELEM) DESCALE(tmp4 + z1 + z3,
					   CONST_BITS+PASS1_BITS);
    dataptr[DCTSIZE*5] = (DCTELEM) DESCALE(tmp5 + z2 + z4,
					   CONST_BITS+PASS1_BITS);
    dataptr[DCTSIZE*3] = (DCTELEM) DESCALE(tmp6 + z2 + z3,
					   CONST_BITS+PASS1_BITS);
    dataptr[DCTSIZE*1] = (DCTELEM) DESCALE(tmp7 + z1 + z4,
					   CONST_BITS+PASS1_BITS);

    dataptr++;			/* advance pointer to next column */
  }
}

#endif /* DCT_ISLOW_SUPPORTED */


/* Main function
   Time to function execution time using logic analyzer,
   which measures the OFF time of a LED on board.

   The switching latency, including the function call/return time,
   is measured to be equal to 1.1us (22 clock cycles).
*/
int main(void)
{
  int i, seed;

  /* Worst case settings */
  /* Set array to random values */
  seed = 1;
  for (i = 0; i < 64; i++) {
    seed = ((seed * 133) + 81) % 65535;
    data[i] = seed;
  }

  jpeg_fdct_islow();
  return 0;
}

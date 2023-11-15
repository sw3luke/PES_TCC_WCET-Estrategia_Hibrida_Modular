#include "soc_AM335x.h"
#include "beaglebone.h"

//=========================== Instrumentation Definitions =========================== 

typedef signed int int32_t;

void cache_maintenance();

void init_cache_garbage_array();

static inline unsigned int get_cyclecount (void);

static inline void init_perfcounters (int32_t do_reset, int32_t enable_divider);

//=========================== Instrumentation Definitions =========================== 

// #define DO_TRACING

int	P1_is_marked = 3;
long	P1_marking_member_0[3];
int	P2_is_marked = 5;
long	P2_marking_member_0[5];
int	P3_is_marked = 0;
long	P3_marking_member_0[6];

/**void NSicherNeu()**/
int main()
{
/* ------------------- Debug de conferencia de registradores -------------------*/

/*

//====================== Hardware Instrumentation Definitions ======================

    unsigned int anotherControlRegister;
    unsigned int* newRegisterCheck = (unsigned int*)0x8009af70;
    unsigned int current_mode;
    unsigned int* currentModeStatus = (unsigned int*)0x8009af80;
    unsigned int auxiliaryControlRegister;
    unsigned int* addrAuxiliaryControlRegisterBefore = (unsigned int*)0x8009af90;


//====================== Hardware Instrumentation Definitions ======================
    
    
    asm volatile("MRC p15, 0, %0, c1, c0, 0\t\n": "=r"(anotherControlRegister)); 
    *newRegisterCheck = anotherControlRegister; 
    
    asm volatile("MRS %0, CPSR" : "=r"(current_mode));
    *currentModeStatus = current_mode;//current_mode;
    
    asm volatile("MRC p15, 0, %0, c1, c0, 1\t\n": "=r"(auxiliaryControlRegister));
    *addrAuxiliaryControlRegisterBefore = auxiliaryControlRegister;
 
*/

    init_perfcounters (1, 0);
    unsigned int numCycles = 0;
    unsigned int overhead = get_cyclecount();
    
    overhead = get_cyclecount() - overhead;
    unsigned int t = 0;
    unsigned int* addr = (unsigned int*)0x80069FF0;
    
    init_cache_garbage_array();
    int numberExecutions;
    for(numberExecutions = 0; numberExecutions < 50000; numberExecutions++){
	t = get_cyclecount();
	//====================== Target Flow ======================
   int dummy_i;
/*   dummy_i = 17; Takes too much time */
   dummy_i = 2;

   while (dummy_i > 0) {

      dummy_i--;
      /* Permutation for Place P1 : 0, 1, 2 */
      /* Transition T1 */
      if ( (P1_is_marked >= 3) &&
           (P3_is_marked + 3 <= 6) &&
           (P1_marking_member_0[1] == P1_marking_member_0[2]) ) {

         long	x;
         long	y;
         long	z;

         x = P1_marking_member_0[0];
         y = P1_marking_member_0[1];

         /* Transition condition */
         if (x < y) {

				/* demarking of input places */
            P1_is_marked -= 3;

				/* preaction */
            z = x - y;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = x;
            P3_marking_member_0[P3_is_marked+1] = y;
            P3_marking_member_0[P3_is_marked+2] = z;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P1 : 0, 2, 1 */
      /* Transition T1 */
      if ( (P1_is_marked >= 3) &&
           (P3_is_marked + 3 <= 6) &&
           (P1_marking_member_0[2] == P1_marking_member_0[1]) ) {

         long	x;
         long	y;
         long	z;

         x = P1_marking_member_0[0];
         y = P1_marking_member_0[2];

         /* Transition condition */
         if ((x < y)) {


				/* demarking of input places */
            P1_is_marked -= 3;

				/* preaction */
            z = x - y;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = x;
            P3_marking_member_0[P3_is_marked+1] = y;
            P3_marking_member_0[P3_is_marked+2] = z;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P1 : 1, 0, 2 */
      /* Transition T1 */
      if ( (P1_is_marked >= 3) &&
           (P3_is_marked + 3 <= 6) &&
           (P1_marking_member_0[0] == P1_marking_member_0[2]) ) {

         long	x;
         long	y;
         long	z;

         x = P1_marking_member_0[1];
         y = P1_marking_member_0[0];

         /* Transition condition */
         if (x < y) {


				/* demarking of input places */
            P1_is_marked -= 3;

				/* preaction */
            z = x - y;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = x;
            P3_marking_member_0[P3_is_marked+1] = y;
            P3_marking_member_0[P3_is_marked+2] = z;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P1 : 1, 2, 0 */
      /* Transition T1 */
      if ( (P1_is_marked >= 3) &&
           (P3_is_marked + 3 <= 6) &&
           (P1_marking_member_0[2] == P1_marking_member_0[0])) {

         long	x;
         long	y;
         long	z;

         x = P1_marking_member_0[1];
         y = P1_marking_member_0[2];

         /* Transition condition */
         if ((x < y)) {


				/* demarking of input places */
            P1_is_marked -= 3;

				/* preaction */
            z = x - y;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = x;
            P3_marking_member_0[P3_is_marked+1] = y;
            P3_marking_member_0[P3_is_marked+2] = z;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P1 : 2, 0, 1 */
      /* Transition T1 */
      if ( (P1_is_marked >= 3) &&
           (P3_is_marked + 3 <= 6) &&
           (P1_marking_member_0[0] == P1_marking_member_0[1]) ) {
         long	x;
         long	y;
         long	z;

         x = P1_marking_member_0[2];
         y = P1_marking_member_0[0];

         /* Transition condition */
         if ((x < y)) {

				/* demarking of input places */
            P1_is_marked -= 3;

				/* preaction */
            z = x - y;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = x;
            P3_marking_member_0[P3_is_marked+1] = y;
            P3_marking_member_0[P3_is_marked+2] = z;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P1 : 2, 1, 0 */
      /* Transition T1 */
      if ( (P1_is_marked >= 3) &&
           (P3_is_marked + 3 <= 6) &&
           (P1_marking_member_0[1] == P1_marking_member_0[0]) ) {
         long	x;
         long	y;
         long	z;

         x = P1_marking_member_0[2];
         y = P1_marking_member_0[1];

         /* Transition condition */
         if ((x < y)) {

				/* demarking of input places */
            P1_is_marked -= 3;

				/* preaction */
            z = x - y;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = x;
            P3_marking_member_0[P3_is_marked+1] = y;
            P3_marking_member_0[P3_is_marked+2] = z;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 0, 1, 2, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           (((P3_is_marked + 3) <= 6)) &&
           ( ((P2_marking_member_0[1] == P2_marking_member_0[2])) &&
             ((P2_marking_member_0[1] == P2_marking_member_0[3])) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 0, 1, 3, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           (((P3_is_marked + 3) <= 6)) &&
           ( (P2_marking_member_0[1] == P2_marking_member_0[3]) &&
             (P2_marking_member_0[1] == P2_marking_member_0[2]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 0, 2, 1, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[2] == P2_marking_member_0[1]) &&
             (P2_marking_member_0[2] == P2_marking_member_0[3]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 0, 2, 3, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[2] == P2_marking_member_0[3]) &&
             (P2_marking_member_0[2] == P2_marking_member_0[1]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 0, 3, 1, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[3] == P2_marking_member_0[1]) &&
             (P2_marking_member_0[3] == P2_marking_member_0[2]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 0, 3, 2, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[3] == P2_marking_member_0[2]) &&
             (P2_marking_member_0[3] == P2_marking_member_0[1]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 1, 0, 2, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[0] == P2_marking_member_0[2]) &&
             (P2_marking_member_0[0] == P2_marking_member_0[3]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 1, 0, 3, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[0] == P2_marking_member_0[3]) &&
             (P2_marking_member_0[0] == P2_marking_member_0[2]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 1, 2, 0, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[2] == P2_marking_member_0[0]) &&
             (P2_marking_member_0[2] == P2_marking_member_0[3]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 1, 2, 3, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[2] == P2_marking_member_0[3]) &&
             (P2_marking_member_0[2] == P2_marking_member_0[0]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {
				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 1, 3, 0, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[3] == P2_marking_member_0[0]) &&
             (P2_marking_member_0[3] == P2_marking_member_0[2]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {
				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 3, 2, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[3] == P2_marking_member_0[2]) &&
             (P2_marking_member_0[3] == P2_marking_member_0[0]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 0, 1, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[0] == P2_marking_member_0[1]) &&
             (P2_marking_member_0[0] == P2_marking_member_0[3]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {
				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 2, 0, 3, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[0] == P2_marking_member_0[3]) &&
             (P2_marking_member_0[0] == P2_marking_member_0[1]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {
				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 2, 1, 0, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[1] == P2_marking_member_0[0]) &&
             (P2_marking_member_0[1] == P2_marking_member_0[3]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {
				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 2, 1, 3, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[1] == P2_marking_member_0[3]) &&
             (P2_marking_member_0[1] == P2_marking_member_0[0]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {
				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 2, 3, 0, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[3] == P2_marking_member_0[0]) &&
             (P2_marking_member_0[3] == P2_marking_member_0[1]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {
				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 2, 3, 1, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[3] == P2_marking_member_0[1]) &&
             (P2_marking_member_0[3] == P2_marking_member_0[0]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {
				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }

      /* Permutation for Place P2 : 3, 0, 1, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ((P3_is_marked + 3) <= 6) &&
           ( (P2_marking_member_0[0] == P2_marking_member_0[1]) &&
             (P2_marking_member_0[0] == P2_marking_member_0[2]) ) ) {
         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 0, 2, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[0] == P2_marking_member_0[2]) &&
             ( P2_marking_member_0[0] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 1, 0, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[1] == P2_marking_member_0[0]) &&
             ( P2_marking_member_0[1] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 1, 2, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[1] == P2_marking_member_0[2]) &&
             ( P2_marking_member_0[1] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 2, 0, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[2] == P2_marking_member_0[0]) &&
             ( P2_marking_member_0[2] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 2, 1, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 4) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[2] == P2_marking_member_0[1]) &&
             ( P2_marking_member_0[2] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 1, 2, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[1] == P2_marking_member_0[2]) &&
             ( P2_marking_member_0[1] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[3];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 1, 3, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[1] == P2_marking_member_0[3]) &&
             ( P2_marking_member_0[1] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[2];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 1, 4, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[1] == P2_marking_member_0[4]) &&
             ( P2_marking_member_0[1] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[3];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 1, 4, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[1] == P2_marking_member_0[4]) &&
             ( P2_marking_member_0[1] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[2];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 2, 1, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[2] == P2_marking_member_0[1]) &&
             ( P2_marking_member_0[2] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[3];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 2, 3, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[2] == P2_marking_member_0[3]) &&
             ( P2_marking_member_0[2] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[1];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 2, 4, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[2] == P2_marking_member_0[4]) &&
             ( P2_marking_member_0[2] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[3];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 2, 4, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[2] == P2_marking_member_0[4]) &&
             ( P2_marking_member_0[2] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[1];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 3, 1, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[3] == P2_marking_member_0[1]) &&
             ( P2_marking_member_0[3] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[2];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 3, 2, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[3] == P2_marking_member_0[2]) &&
             ( P2_marking_member_0[3] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[1];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 3, 4, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[3] == P2_marking_member_0[4]) &&
             ( P2_marking_member_0[3] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[2];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 3, 4, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[3] == P2_marking_member_0[4]) &&
             ( P2_marking_member_0[3] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[1];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 4, 1, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[4] == P2_marking_member_0[1]) &&
             ( P2_marking_member_0[4] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[3];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 4, 1, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[4] == P2_marking_member_0[1]) &&
             ( P2_marking_member_0[4] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[2];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 4, 2, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[4] == P2_marking_member_0[2]) &&
             ( P2_marking_member_0[4] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[3];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 4, 2, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[4] == P2_marking_member_0[2]) &&
             ( P2_marking_member_0[4] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[1];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 4, 3, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[4] == P2_marking_member_0[3]) &&
             ( P2_marking_member_0[4] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[2];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 0, 4, 3, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           ( ( P2_marking_member_0[4] == P2_marking_member_0[3]) &&
             ( P2_marking_member_0[4] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[0];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
            P2_marking_member_0[0] = P2_marking_member_0[1];
            P2_is_marked -= 4;

				/* preaction */
            c = a + b;

				/* marking of output places */
            P3_marking_member_0[P3_is_marked+0] = a;
            P3_marking_member_0[P3_is_marked+1] = b;
            P3_marking_member_0[P3_is_marked+2] = c;
            P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 0, 2, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[2]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 0, 3, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[3]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 0, 4, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 0, 4, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 2, 0, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[2] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[2] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 2, 3, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[2] == P2_marking_member_0[3]) &&
            ( P2_marking_member_0[2] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 2, 4, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[2] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[2] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 2, 4, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[2] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[2] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 3, 0, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[3] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[3] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 3, 2, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[3] == P2_marking_member_0[2]) &&
            ( P2_marking_member_0[3] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 3, 4, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[3] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[3] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 3, 4, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[3] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[3] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 4, 0, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 4, 0, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 4, 2, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[2]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 4, 2, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[2]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 4, 3, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[3]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 1, 4, 3, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[3]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[1];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 0, 1, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[1]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 0, 3, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[3]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 0, 4, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 0, 4, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 1, 0, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[1] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[1] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 1, 3, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[1] == P2_marking_member_0[3]) &&
            ( P2_marking_member_0[1] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 1, 4, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[1] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[1] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 1, 4, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[1] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[1] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 3, 0, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[3] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[3] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 3, 1, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[3] == P2_marking_member_0[1]) &&
            ( P2_marking_member_0[3] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 3, 4, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[3] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[3] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 3, 4, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[3] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[3] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 4, 0, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 4, 0, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 4, 1, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[1]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 4, 1, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[1]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 4, 3, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[3]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 2, 4, 3, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[3]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[2];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 0, 1, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[1]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 0, 2, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[2]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 0, 4, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 0, 4, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 1, 0, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[1] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[1] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 1, 2, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[1] == P2_marking_member_0[2]) &&
            ( P2_marking_member_0[1] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 1, 4, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[1] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[1] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 1, 4, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[1] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[1] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 2, 0, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[2] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[2] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 2, 1, 4 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[2] == P2_marking_member_0[1]) &&
            ( P2_marking_member_0[2] == P2_marking_member_0[4]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 2, 4, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[2] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[2] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 2, 4, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[2] == P2_marking_member_0[4]) &&
            ( P2_marking_member_0[2] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 4, 0, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 4, 0, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 4, 1, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[1]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 4, 1, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[1]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 4, 2, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[2]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 3, 4, 2, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[4] == P2_marking_member_0[2]) &&
            ( P2_marking_member_0[4] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[3];
         b = P2_marking_member_0[4];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 0, 1, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[1]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 0, 1, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[1]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 0, 2, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[2]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 0, 2, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[2]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 0, 3, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[3]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 0, 3, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[0] == P2_marking_member_0[3]) &&
            ( P2_marking_member_0[0] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[0];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 1, 0, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[1] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[1] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 1, 0, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[1] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[1] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 1, 2, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[1] == P2_marking_member_0[2]) &&
            ( P2_marking_member_0[1] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 1, 2, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[1] == P2_marking_member_0[2]) &&
            ( P2_marking_member_0[1] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 1, 3, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[1] == P2_marking_member_0[3]) &&
            ( P2_marking_member_0[1] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 1, 3, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[1] == P2_marking_member_0[3]) &&
            ( P2_marking_member_0[1] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[1];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 2, 0, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[2] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[2] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 2, 0, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[2] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[2] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 2, 1, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[2] == P2_marking_member_0[1]) &&
            ( P2_marking_member_0[2] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[3];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 2, 1, 3 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[2] == P2_marking_member_0[1]) &&
            ( P2_marking_member_0[2] == P2_marking_member_0[3]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 2, 3, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[2] == P2_marking_member_0[3]) &&
            ( P2_marking_member_0[2] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 2, 3, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[2] == P2_marking_member_0[3]) &&
            ( P2_marking_member_0[2] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[2];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 3, 0, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[3] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[3] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 3, 0, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[3] == P2_marking_member_0[0]) &&
            ( P2_marking_member_0[3] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 3, 1, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[3] == P2_marking_member_0[1]) &&
            ( P2_marking_member_0[3] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[2];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 3, 1, 2 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[3] == P2_marking_member_0[1]) &&
            ( P2_marking_member_0[3] == P2_marking_member_0[2]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 3, 2, 0 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[3] == P2_marking_member_0[2]) &&
            ( P2_marking_member_0[3] == P2_marking_member_0[0]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_marking_member_0[0] = P2_marking_member_0[1];
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }


      /* Permutation for Place P2 : 4, 3, 2, 1 */
      /* Transition T2 */
      if ( (P2_is_marked >= 5) &&
           ( (P3_is_marked + 3) <= 6) &&
           (( P2_marking_member_0[3] == P2_marking_member_0[2]) &&
            ( P2_marking_member_0[3] == P2_marking_member_0[1]) ) ) {

         long	a;
         long	b;
         long	c;

         a = P2_marking_member_0[4];
         b = P2_marking_member_0[3];

         /* Transition condition */
         if ((b > a)) {

				/* demarking of input places */
         P2_is_marked -= 4;

				/* preaction */
         c = a + b;

				/* marking of output places */
         P3_marking_member_0[P3_is_marked+0] = a;
         P3_marking_member_0[P3_is_marked+1] = b;
         P3_marking_member_0[P3_is_marked+2] = c;
         P3_is_marked += 3;

         } /* end of if (Transition condition) */
      }
   }


   dummy_i = 77;

	//====================== Target Flow ======================
	
	t = get_cyclecount() - t;
	numCycles = t - overhead;
	*(addr+(numberExecutions)) = numCycles;
	cache_maintenance();
    }  
    
    
    






   //return dummy_i; //declaracao de dummy_i feita dentro do loop, logo este return nao ira funcionar


}


//============================== Hardware Measure Routine ==============================


static inline unsigned int get_cyclecount (void){
  unsigned int value;
  // Read CCNT Register
  asm volatile ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(value));
  //Referencia do registrador na documentacao pode ser encontrada no link abaixo
  /*https://developer.arm.com/documentation/ddi0344/k/system-control-coprocessor/system-control-coprocessor-registers/c9--cycle-count-register?lang=en*/
  return value;
}



static inline void init_perfcounters (int32_t do_reset, int32_t enable_divider){
  // in general enable all counters (including cycle counter)
  int32_t value = 1;

  // peform reset:  
  if (do_reset)
  {
    value |= 2;     // resetar todos os contadores para zero.
    value |= 4;     // resetar contadores de ciclo para zero.
  } 

  if (enable_divider)
    value |= 8;     // enable "by 64" divider for CCNT.

  value |= 16;

  // program the performance-counter control-register:
  asm volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(value));  

  // enable all counters:  
  asm volatile ("MCR p15, 0, %0, c9, c12, 1\t\n" :: "r"(0x8000000f));  

  // clear overflows:
  asm volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
}



void init_cache_garbage_array(){

	int* garbage_array_addr = (int*)0x80000ba0; 
	int i;
	for(i = 0; i < 8192; i++){
		*(garbage_array_addr+(i*4)) = 0; //um equivalente de j = j+1 para cada posicao do array
		
	}

}


void cache_maintenance(){
	
	//Sintaxe do comando MCR:
	//MCR<c> <coproc>,<opc1>,<Rt>,<CRn>,<CRm>{,<opc2>}
	//Rt -> valor a ser escrito no registrador do coprocessador
	//CRn -> registrador que recebera o valor
	//CRm -> registrador de destino adicional
	//opc2 -> opcode, se nao definido sera 0
	
	
	asm volatile("MCR p15, 0, %0, c7, c5, 0" :: "r"(0));//invalida conteudo da cache de instrucoes
	
	
	int* garbage_array_addr = (int*)0x80000ba0;
	int i;
	for(i = 0; i < 8192; i++){
		*(garbage_array_addr+(i*4)) = *(garbage_array_addr+(i*4)) + 1; //um equivalente de j = j+1 para cada posicao do array
	}
}


//============================== Hardware Measure Routine ==============================




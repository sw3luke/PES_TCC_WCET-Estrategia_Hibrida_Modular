#include "soc_AM335x.h"
#include "beaglebone.h"

//=========================== Instrumentation Definitions =========================== 

typedef signed int int32_t;

void cache_maintenance();

void init_cache_garbage_array();

static inline unsigned int get_cyclecount (void);

static inline void init_perfcounters (int32_t do_reset, int32_t enable_divider);

//=========================== Instrumentation Definitions =========================== 


/*
** actually, we don't really need floating point here
*/
#define float int

static char Bitlist[64];
#define SYS_bit_get(a,b) (a)[(b)]
#define SYS_bit_clr(a,b) (a)[(b)] = 0
#define SYS_bit_set(a,b) (a)[(b)] = 1
#define SYS_bit_cpy(a1,i1,a2,i2) (a1)[(i1)] = (a2)[(i2)]


#define active_KINDERSICHERUNG_CTRL_IDX 10
#define active_KINDERSICHERUNG_CTRL_copy_IDX 11
#define active_KINDERSICHERUNG_CTRL_old_IDX 12
#define active_FH_TUERMODUL_CTRL_IDX 13
#define active_FH_TUERMODUL_CTRL_copy_IDX 14
#define active_FH_TUERMODUL_CTRL_old_IDX 15
#define active_EINKLEMMSCHUTZ_CTRL_IDX 16
#define active_EINKLEMMSCHUTZ_CTRL_copy_IDX 17
#define active_EINKLEMMSCHUTZ_CTRL_old_IDX 18
#define active_BLOCK_ERKENNUNG_CTRL_IDX 19
#define active_BLOCK_ERKENNUNG_CTRL_copy_IDX 20
#define active_BLOCK_ERKENNUNG_CTRL_old_IDX 21
#define entered_EINSCHALTSTROM_MESSEN_BLOCK_ERKENNUNG_CTRL_IDX 0 
#define entered_EINSCHALTSTROM_MESSEN_BLOCK_ERKENNUNG_CTRL_copy_IDX 1 
unsigned long tm_entered_EINSCHALTSTROM_MESSEN_BLOCK_ERKENNUNG_CTRLch_BLOCK_ERKENNUNG_CTRL__N_copy; 
#define entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_IDX 4 
#define entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_copy_IDX 5 
#define exited_BEREIT_FH_TUERMODUL_CTRL_IDX 6 
#define exited_BEREIT_FH_TUERMODUL_CTRL_copy_IDX 7 
unsigned long tm_entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRLexited_BEREIT_FH_TUERMODUL_CTRL; 
unsigned long tm_entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL; 
unsigned long   sc_FH_TUERMODUL_CTRL_2375_2 ;
unsigned long   sc_FH_TUERMODUL_CTRL_2352_1 ;
unsigned long   sc_FH_TUERMODUL_CTRL_2329_1 ;
int FH_TUERMODUL_CTRL__N;
int FH_TUERMODUL_CTRL__N_copy;
int FH_TUERMODUL_CTRL__N_old;
unsigned long   sc_FH_TUERMODUL_CTRL_1781_10 ;
unsigned long   sc_FH_TUERMODUL_CTRL_1739_10 ;
float   FH_TUERMODUL__POSITION ;
float   FH_TUERMODUL__I_EIN ;
float FH_TUERMODUL__I_EIN_old;
int FH_DU__MFH;
int FH_DU__MFH_copy;
float   FH_DU__POSITION ;
float   FH_DU__I_EIN ;
float FH_DU__I_EIN_old;
float BLOCK_ERKENNUNG_CTRL__I_EIN_MAX;
float BLOCK_ERKENNUNG_CTRL__I_EIN_MAX_copy;
int BLOCK_ERKENNUNG_CTRL__N;
int BLOCK_ERKENNUNG_CTRL__N_copy;
int BLOCK_ERKENNUNG_CTRL__N_old;
char FH_TUERMODUL_CTRL__INREVERS2;
char FH_TUERMODUL_CTRL__INREVERS2_copy;
char FH_TUERMODUL_CTRL__INREVERS1;
char FH_TUERMODUL_CTRL__INREVERS1_copy;
char   FH_TUERMODUL_CTRL__FT ;
char   FH_TUERMODUL__SFHZ_ZENTRAL ;
char FH_TUERMODUL__SFHZ_ZENTRAL_old;
char   FH_TUERMODUL__SFHZ_MEC ;
char FH_TUERMODUL__SFHZ_MEC_old;
char   FH_TUERMODUL__SFHA_ZENTRAL ;
char FH_TUERMODUL__SFHA_ZENTRAL_old;
char   FH_TUERMODUL__SFHA_MEC ;
char FH_TUERMODUL__SFHA_MEC_old;
char   FH_TUERMODUL__KL_50 ;
char FH_TUERMODUL__BLOCK;
char FH_TUERMODUL__BLOCK_copy;
char FH_TUERMODUL__BLOCK_old;
char   FH_TUERMODUL__FT ;
char FH_TUERMODUL__SFHZ;
char FH_TUERMODUL__SFHZ_copy;
char FH_TUERMODUL__SFHZ_old;
char FH_TUERMODUL__SFHA;
char FH_TUERMODUL__SFHA_copy;
char FH_TUERMODUL__SFHA_old;
char FH_TUERMODUL__MFHZ;
char FH_TUERMODUL__MFHZ_copy;
char FH_TUERMODUL__MFHZ_old;
char FH_TUERMODUL__MFHA;
char FH_TUERMODUL__MFHA_copy;
char FH_TUERMODUL__MFHA_old;
char   FH_TUERMODUL__EKS_LEISTE_AKTIV ;
char FH_TUERMODUL__EKS_LEISTE_AKTIV_old;
char   FH_TUERMODUL__COM_OPEN ;
char   FH_TUERMODUL__COM_CLOSE ;
char   FH_DU__KL_50 ;
char FH_DU__S_FH_FTZU;
char FH_DU__S_FH_FTAUF;
char   FH_DU__FT ;
char   FH_DU__EKS_LEISTE_AKTIV ;
char FH_DU__EKS_LEISTE_AKTIV_old;
char FH_DU__S_FH_TMBFAUFCAN;
char FH_DU__S_FH_TMBFAUFCAN_copy;
char FH_DU__S_FH_TMBFAUFCAN_old;
char FH_DU__S_FH_TMBFZUCAN;
char FH_DU__S_FH_TMBFZUCAN_copy;
char FH_DU__S_FH_TMBFZUCAN_old;
char   FH_DU__S_FH_TMBFZUDISC ;
char FH_DU__S_FH_TMBFZUDISC_old;
char   FH_DU__S_FH_TMBFAUFDISC ;
char FH_DU__S_FH_TMBFAUFDISC_old;
char   FH_DU__S_FH_ZUDISC ;
char   FH_DU__S_FH_AUFDISC ;
char   FH_DU__DOOR_ID ;
char FH_DU__BLOCK;
char FH_DU__BLOCK_copy;
char FH_DU__BLOCK_old;
char FH_DU__MFHZ;
char FH_DU__MFHZ_copy;
char FH_DU__MFHZ_old;
char FH_DU__MFHA;
char FH_DU__MFHA_copy;
char FH_DU__MFHA_old;
#define  FH_TUERMODUL_CTRL__END_REVERS_IDX 22
#define  FH_TUERMODUL_CTRL__END_REVERS_copy_IDX 23
#define  FH_TUERMODUL__EINKLEMMUNG_IDX 24

unsigned long time;
char stable;
char step;

char NICHT_INITIALISIERT_NICHT_INITIALISIERT_next_state;  /** 2 bits **/
char ZENTRAL_KINDERSICHERUNG_CTRL_next_state;  /** 1 bits **/
char MEC_KINDERSICHERUNG_CTRL_next_state;  /** 1 bits **/
char KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state;  /** 2 bits **/
char B_FH_TUERMODUL_CTRL_next_state;  /** 2 bits **/
char A_FH_TUERMODUL_CTRL_next_state;  /** 1 bits **/
char WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_next_state;  /** 1 bits **/
char INITIALISIERT_FH_TUERMODUL_CTRL_next_state;  /** 2 bits **/
char TIPP_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state;  /** 2 bits **/
char MANUELL_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state;  /** 2 bits **/
char OEFFNEN_FH_TUERMODUL_CTRL_next_state;  /** 2 bits **/
char SCHLIESSEN_FH_TUERMODUL_CTRL_next_state;  /** 2 bits **/
char FH_STEUERUNG_DUMMY_FH_STEUERUNG_DUMMY_next_state;  /** 2 bits **/
char EINKLEMMSCHUTZ_CTRL_EINKLEMMSCHUTZ_CTRL_next_state;  /** 2 bits **/
char BEWEGUNG_BLOCK_ERKENNUNG_CTRL_next_state;  /** 2 bits **/
char BLOCK_ERKENNUNG_CTRL_BLOCK_ERKENNUNG_CTRL_next_state;  /** 2 bits **/


void interface(void)
{
   if (SYS_bit_get(Bitlist, entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_IDX))
   tm_entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL = time;
   if (SYS_bit_get(Bitlist, entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_IDX) || SYS_bit_get (Bitlist, exited_BEREIT_FH_TUERMODUL_CTRL_IDX))
   tm_entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRLexited_BEREIT_FH_TUERMODUL_CTRL = time;
   if ((sc_FH_TUERMODUL_CTRL_2375_2 != 0) && (time - sc_FH_TUERMODUL_CTRL_2375_2 >= 0.5))
   {
      FH_TUERMODUL__MFHA_copy = 0;
      sc_FH_TUERMODUL_CTRL_2375_2 = 0;
      
   }
   if ((sc_FH_TUERMODUL_CTRL_2352_1 != 0) && (time - sc_FH_TUERMODUL_CTRL_2352_1 >= 0.5))
   {
      FH_TUERMODUL__MFHZ_copy = 0;
      sc_FH_TUERMODUL_CTRL_2352_1 = 0;
      
   }
   if ((sc_FH_TUERMODUL_CTRL_2329_1 != 0) && (time - sc_FH_TUERMODUL_CTRL_2329_1 >= 0.5))
   {
      FH_TUERMODUL__MFHZ_copy = 0;
      sc_FH_TUERMODUL_CTRL_2329_1 = 0;
      
   }
   if ((sc_FH_TUERMODUL_CTRL_1781_10 != 0) && (time - sc_FH_TUERMODUL_CTRL_1781_10 >= 0.5))
   {
      sc_FH_TUERMODUL_CTRL_1781_10 = 0;
      
   }
   if ((sc_FH_TUERMODUL_CTRL_1739_10 != 0) && (time - sc_FH_TUERMODUL_CTRL_1739_10 >= 0.5))
   {
      sc_FH_TUERMODUL_CTRL_1739_10 = 0;
      
   }
   if ((SYS_bit_get(Bitlist, entered_EINSCHALTSTROM_MESSEN_BLOCK_ERKENNUNG_CTRL_IDX) || BLOCK_ERKENNUNG_CTRL__N != BLOCK_ERKENNUNG_CTRL__N_old))
   tm_entered_EINSCHALTSTROM_MESSEN_BLOCK_ERKENNUNG_CTRLch_BLOCK_ERKENNUNG_CTRL__N_copy = time;
   
   
}/** interface **/


void init(void)
{
    tm_entered_EINSCHALTSTROM_MESSEN_BLOCK_ERKENNUNG_CTRLch_BLOCK_ERKENNUNG_CTRL__N_copy = 0;
    tm_entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRLexited_BEREIT_FH_TUERMODUL_CTRL = 0;
    tm_entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL = 0;
   NICHT_INITIALISIERT_NICHT_INITIALISIERT_next_state = 0;
   ZENTRAL_KINDERSICHERUNG_CTRL_next_state = 0;
   MEC_KINDERSICHERUNG_CTRL_next_state = 0;
   KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state = 0;
   B_FH_TUERMODUL_CTRL_next_state = 0;
   A_FH_TUERMODUL_CTRL_next_state = 0;
   WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_next_state = 0;
   INITIALISIERT_FH_TUERMODUL_CTRL_next_state = 0;
   TIPP_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 0;
   MANUELL_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 0;
   OEFFNEN_FH_TUERMODUL_CTRL_next_state = 0;
   SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 0;
   FH_STEUERUNG_DUMMY_FH_STEUERUNG_DUMMY_next_state = 0;
   EINKLEMMSCHUTZ_CTRL_EINKLEMMSCHUTZ_CTRL_next_state = 0;
   BEWEGUNG_BLOCK_ERKENNUNG_CTRL_next_state = 0;
   BLOCK_ERKENNUNG_CTRL_BLOCK_ERKENNUNG_CTRL_next_state = 0;
   
   
}/** init **/



void generic_KINDERSICHERUNG_CTRL(void)
{
   if (SYS_bit_get(Bitlist,active_KINDERSICHERUNG_CTRL_IDX))
   {
      switch (KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state)
      {
         case 1 : /** state ZENTRAL in chart KINDERSICHERUNG_CTRL **/
         {
            if (!(FH_TUERMODUL__SFHA_ZENTRAL || FH_TUERMODUL__SFHZ_ZENTRAL))
            {
               stable = 0;
                FH_TUERMODUL__SFHZ_copy = 0;
                 FH_TUERMODUL__SFHA_copy = 0;
               
               KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state = 3;
               ZENTRAL_KINDERSICHERUNG_CTRL_next_state = 0;
               break;
            }
            switch (ZENTRAL_KINDERSICHERUNG_CTRL_next_state)
            {
               case 1 : /** state IN_ZENTRAL in chart KINDERSICHERUNG_CTRL **/
               {
                  if ((FH_TUERMODUL__SFHA_ZENTRAL && !(FH_TUERMODUL__SFHA_ZENTRAL_old)))
                  {
                     stable = 0;
                      FH_TUERMODUL__SFHA_copy = 1;
                     
                     ZENTRAL_KINDERSICHERUNG_CTRL_next_state = 1;
                     break;
                  }
                  if ((FH_TUERMODUL__SFHZ_ZENTRAL && !(FH_TUERMODUL__SFHZ_ZENTRAL_old)))
                  {
                     stable = 0;
                      FH_TUERMODUL__SFHZ_copy = 1;
                     
                     ZENTRAL_KINDERSICHERUNG_CTRL_next_state = 1;
                     break;
                  }
                  if ((!(FH_TUERMODUL__SFHA_ZENTRAL) && FH_TUERMODUL__SFHA_ZENTRAL_old))
                  {
                     stable = 0;
                      FH_TUERMODUL__SFHA_copy = 0;
                     
                     ZENTRAL_KINDERSICHERUNG_CTRL_next_state = 1;
                     break;
                  }
                  if ((!(FH_TUERMODUL__SFHZ_ZENTRAL) && FH_TUERMODUL__SFHZ_ZENTRAL_old))
                  {
                     stable = 0;
                      FH_TUERMODUL__SFHZ_copy = 0;
                     
                     ZENTRAL_KINDERSICHERUNG_CTRL_next_state = 1;
                     break;
                  }
                  break;
               }
               default:
               {
                  stable = 0;
                  break;
               }
            }/** switch ZENTRAL_KINDERSICHERUNG_CTRL_next_state **/
            break;
         }
         case 2 : /** state MEC in chart KINDERSICHERUNG_CTRL **/
         {
            if (!(FH_TUERMODUL__SFHA_MEC || FH_TUERMODUL__SFHZ_MEC))
            {
               stable = 0;
                FH_TUERMODUL__SFHZ_copy = 0;
                 FH_TUERMODUL__SFHA_copy = 0;
               
               KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state = 3;
               MEC_KINDERSICHERUNG_CTRL_next_state = 0;
               break;
            }
            switch (MEC_KINDERSICHERUNG_CTRL_next_state)
            {
               case 1 : /** state INMEC in chart KINDERSICHERUNG_CTRL **/
               {
                  if ((FH_TUERMODUL__SFHA_MEC && !(FH_TUERMODUL__SFHA_MEC_old)))
                  {
                     stable = 0;
                      FH_TUERMODUL__SFHA_copy = 1;
                     
                     MEC_KINDERSICHERUNG_CTRL_next_state = 1;
                     break;
                  }
                  if ((FH_TUERMODUL__SFHZ_MEC && !(FH_TUERMODUL__SFHZ_MEC_old)))
                  {
                     stable = 0;
                      FH_TUERMODUL__SFHZ_copy = 1;
                     
                     MEC_KINDERSICHERUNG_CTRL_next_state = 1;
                     break;
                  }
                  if ((!(FH_TUERMODUL__SFHA_MEC) && FH_TUERMODUL__SFHA_MEC_old))
                  {
                     stable = 0;
                      FH_TUERMODUL__SFHA_copy = 0;
                     
                     MEC_KINDERSICHERUNG_CTRL_next_state = 1;
                     break;
                  }
                  if ((!(FH_TUERMODUL__SFHZ_MEC) && FH_TUERMODUL__SFHZ_MEC_old))
                  {
                     stable = 0;
                      FH_TUERMODUL__SFHZ_copy = 0;
                     
                     MEC_KINDERSICHERUNG_CTRL_next_state = 1;
                     break;
                  }
                  break;
               }
               default:
               {
                  stable = 0;
                  break;
               }
            }/** switch MEC_KINDERSICHERUNG_CTRL_next_state **/
            break;
         }
         case 3 : /** state WAITING in chart KINDERSICHERUNG_CTRL **/
         {
            if ((!FH_TUERMODUL__KL_50) && (FH_TUERMODUL__SFHZ_MEC && FH_TUERMODUL__SFHA_MEC))
            {
               stable = 0;
                 FH_TUERMODUL__SFHZ_copy = 1;
                 FH_TUERMODUL__SFHA_copy = 1;
               
               KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state = 2;
               break;
            }
            if ((!FH_TUERMODUL__KL_50) && (FH_TUERMODUL__SFHZ_MEC && !FH_TUERMODUL__SFHA_MEC))
            {
               stable = 0;
                 FH_TUERMODUL__SFHZ_copy = 1;
               
               KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state = 2;
               break;
            }
            if ((!FH_TUERMODUL__KL_50) && (!FH_TUERMODUL__SFHZ_MEC && FH_TUERMODUL__SFHA_MEC))
            {
               stable = 0;
                 FH_TUERMODUL__SFHA_copy = 1;
               
               KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state = 2;
               break;
            }
            if ((!FH_TUERMODUL__SFHZ_ZENTRAL && FH_TUERMODUL__SFHA_ZENTRAL && !FH_TUERMODUL__KL_50))
            {
               stable = 0;
                FH_TUERMODUL__SFHA_copy = 1;
               
               KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state = 1;
               break;
            }
            if ((FH_TUERMODUL__SFHZ_ZENTRAL && FH_TUERMODUL__SFHA_ZENTRAL))
            {
               stable = 0;
                FH_TUERMODUL__SFHA_copy = 1;
                 FH_TUERMODUL__SFHZ_copy = 1;
               
               KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state = 1;
               break;
            }
            if ((FH_TUERMODUL__SFHZ_ZENTRAL && !FH_TUERMODUL__SFHA_ZENTRAL && !FH_TUERMODUL__KL_50))
            {
               stable = 0;
                FH_TUERMODUL__SFHZ_copy = 1;
               
               KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state = 1;
               break;
            }
            break;
         }
         default:
         {
            stable = 0;
            KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state = 3;
            break;
         }
      }/** switch KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state **/
   }
}

void generic_FH_TUERMODUL_CTRL(void)
{
   if (!SYS_bit_get(Bitlist, active_FH_TUERMODUL_CTRL_IDX) && SYS_bit_get(Bitlist,active_FH_TUERMODUL_CTRL_old_IDX) && !SYS_bit_get(Bitlist,active_FH_TUERMODUL_CTRL_copy_IDX))
   {
      SYS_bit_clr (Bitlist, entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_IDX);
      SYS_bit_clr (Bitlist, exited_BEREIT_FH_TUERMODUL_CTRL_IDX);
   }
   if (SYS_bit_get(Bitlist,active_FH_TUERMODUL_CTRL_IDX))
   {
      if (!SYS_bit_get(Bitlist, active_KINDERSICHERUNG_CTRL_IDX))
      {
         KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state = 3;
      }
      SYS_bit_clr (Bitlist, active_KINDERSICHERUNG_CTRL_copy_IDX);
      if (!SYS_bit_get(Bitlist, active_BLOCK_ERKENNUNG_CTRL_IDX))
      {
         SYS_bit_clr (Bitlist, entered_EINSCHALTSTROM_MESSEN_BLOCK_ERKENNUNG_CTRL_IDX);
         BLOCK_ERKENNUNG_CTRL_BLOCK_ERKENNUNG_CTRL_next_state = 1;
      }
      SYS_bit_clr (Bitlist, active_BLOCK_ERKENNUNG_CTRL_copy_IDX);
      SYS_bit_set (Bitlist, active_KINDERSICHERUNG_CTRL_copy_IDX);
      SYS_bit_set (Bitlist, active_BLOCK_ERKENNUNG_CTRL_copy_IDX);
      switch (B_FH_TUERMODUL_CTRL_next_state)
      {
         case 1 : /** state ZAEHLER_WHSP_ZU_HOCH in chart FH_TUERMODUL_CTRL **/
         {
            if ((FH_TUERMODUL_CTRL__N == 59 && !(FH_TUERMODUL_CTRL__N_old == 59)))
            {
               stable = 0;
               
               B_FH_TUERMODUL_CTRL_next_state = 3;
               INITIALISIERT_FH_TUERMODUL_CTRL_next_state = 3;
               break;
            }
            break;
         }
         case 2 : /** state NICHT_INITIALISIERT in chart FH_TUERMODUL_CTRL **/
         {
            if (((FH_TUERMODUL__BLOCK && !(FH_TUERMODUL__BLOCK_old))) && ((FH_TUERMODUL__MFHZ)))
            {
               stable = 0;
               FH_TUERMODUL__MFHZ_copy = 0;
               sc_FH_TUERMODUL_CTRL_2329_1 = time;
               
               B_FH_TUERMODUL_CTRL_next_state = 3;
               INITIALISIERT_FH_TUERMODUL_CTRL_next_state = 3;
               break;
            }
            switch (NICHT_INITIALISIERT_NICHT_INITIALISIERT_next_state)
            {
               case 1 : /** state SCHLIESSEN in chart NICHT_INITIALISIERT **/
               {
                  if (!(FH_TUERMODUL__SFHZ))
                  {
                     stable = 0;
                     FH_TUERMODUL__MFHZ_copy = 0;
                     
                     NICHT_INITIALISIERT_NICHT_INITIALISIERT_next_state = 3;
                     break;
                  }
                  break;
               }
               case 2 : /** state OEFFNEN in chart NICHT_INITIALISIERT **/
               {
                  if (!(FH_TUERMODUL__SFHA))
                  {
                     stable = 0;
                     FH_TUERMODUL__MFHA_copy = 0;
                     
                     NICHT_INITIALISIERT_NICHT_INITIALISIERT_next_state = 3;
                     break;
                  }
                  break;
               }
               case 3 : /** state BEREIT in chart NICHT_INITIALISIERT **/
               {
                  if ((FH_TUERMODUL__SFHA))
                  {
                     stable = 0;
                     FH_TUERMODUL__MFHA_copy = 1;
                     
                     NICHT_INITIALISIERT_NICHT_INITIALISIERT_next_state = 2;
                     break;
                  }
                  if ((FH_TUERMODUL__SFHZ))
                  {
                     stable = 0;
                     FH_TUERMODUL__MFHZ_copy = 1;
                     
                     NICHT_INITIALISIERT_NICHT_INITIALISIERT_next_state = 1;
                     break;
                  }
                  break;
               }
               default:
               {
                  stable = 0;
                  NICHT_INITIALISIERT_NICHT_INITIALISIERT_next_state = 3;
                  break;
               }
            }/** switch NICHT_INITIALISIERT_NICHT_INITIALISIERT_next_state **/
            break;
         }
         case 3 : /** state INITIALISIERT in chart FH_TUERMODUL_CTRL **/
         {
            if (((FH_TUERMODUL_CTRL__N > 60 && !(FH_TUERMODUL_CTRL__N_old > 60))) && ((!(FH_TUERMODUL_CTRL__INREVERS1 || FH_TUERMODUL_CTRL__INREVERS2))))
            {
               stable = 0;
               FH_TUERMODUL__MFHZ_copy = 0;
               FH_TUERMODUL__MFHA_copy = 0;
               
               B_FH_TUERMODUL_CTRL_next_state = 1;
               break;
            }
            if (((FH_TUERMODUL__BLOCK && !(FH_TUERMODUL__BLOCK_old))) && ((FH_TUERMODUL__MFHA)))
            {
               stable = 0;
               FH_TUERMODUL__MFHA_copy = 0;
               sc_FH_TUERMODUL_CTRL_2375_2 = time;
               
               B_FH_TUERMODUL_CTRL_next_state = 2;
               NICHT_INITIALISIERT_NICHT_INITIALISIERT_next_state = 3;
               break;
            }
            if (((FH_TUERMODUL__BLOCK && !(FH_TUERMODUL__BLOCK_old))) && ((FH_TUERMODUL__MFHZ)))
            {
               stable = 0;
               FH_TUERMODUL__MFHZ_copy = 0;
               sc_FH_TUERMODUL_CTRL_2352_1 = time;
               
               B_FH_TUERMODUL_CTRL_next_state = 2;
               NICHT_INITIALISIERT_NICHT_INITIALISIERT_next_state = 3;
               break;
            }
            switch (INITIALISIERT_FH_TUERMODUL_CTRL_next_state)
            {
               case 1 : /** state OEFFNEN in chart FH_TUERMODUL_CTRL **/
               {
                  if ((FH_TUERMODUL__POSITION >= 405))
                  {
                     stable = 0;
                     FH_TUERMODUL__MFHA_copy = 0;
                     
                     INITIALISIERT_FH_TUERMODUL_CTRL_next_state = 3;
                     break;
                  }
                  switch (OEFFNEN_FH_TUERMODUL_CTRL_next_state)
                  {
                     case 1 : /** state TIPP_OEFFNEN in chart FH_TUERMODUL_CTRL **/
                     {
                        if ((FH_TUERMODUL__SFHZ && !(FH_TUERMODUL__SFHZ_old)) || (FH_TUERMODUL__SFHA && !(FH_TUERMODUL__SFHA_old)))
                        {
                           stable = 0;
                           FH_TUERMODUL__MFHA_copy = 0;
                           
                           INITIALISIERT_FH_TUERMODUL_CTRL_next_state = 3;
                           OEFFNEN_FH_TUERMODUL_CTRL_next_state = 0;
                           break;
                        }
                        break;
                     }
                     case 2 : /** state MAN_OEFFNEN in chart FH_TUERMODUL_CTRL **/
                     {
                        if ((FH_TUERMODUL__SFHZ && !(FH_TUERMODUL__SFHZ_old)))
                        {
                           stable = 0;
                           
                           OEFFNEN_FH_TUERMODUL_CTRL_next_state = 1;
                           break;
                        }
                        if ((!(FH_TUERMODUL__SFHA) && FH_TUERMODUL__SFHA_old))
                        {
                           stable = 0;
                           FH_TUERMODUL__MFHA_copy = 0;
                           
                           INITIALISIERT_FH_TUERMODUL_CTRL_next_state = 3;
                           OEFFNEN_FH_TUERMODUL_CTRL_next_state = 0;
                           break;
                        }
                        break;
                     }
                     default:
                     {
                        stable = 0;
                        OEFFNEN_FH_TUERMODUL_CTRL_next_state = 2;
                        break;
                     }
                  }/** switch OEFFNEN_FH_TUERMODUL_CTRL_next_state **/
                  break;
               }
               case 2 : /** state SCHLIESSEN in chart FH_TUERMODUL_CTRL **/
               {
                  if ((FH_TUERMODUL__POSITION <= 0))
                  {
                     stable = 0;
                     FH_TUERMODUL__MFHZ_copy = 0;
                     
                     INITIALISIERT_FH_TUERMODUL_CTRL_next_state = 3;
                     break;
                  }
                  switch (SCHLIESSEN_FH_TUERMODUL_CTRL_next_state)
                  {
                     case 1 : /** state TIPP_SCHLIESSEN in chart FH_TUERMODUL_CTRL **/
                     {
                        if ((FH_TUERMODUL__SFHA && !(FH_TUERMODUL__SFHA_old)) || (FH_TUERMODUL__SFHZ && !(FH_TUERMODUL__SFHZ_old)))
                        {
                           stable = 0;
                           FH_TUERMODUL__MFHZ_copy = 0;
                           
                           INITIALISIERT_FH_TUERMODUL_CTRL_next_state = 3;
                           break;
                        }
                        switch (TIPP_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state)
                        {
                           case 1 : /** state REVERSIEREN2 in chart FH_TUERMODUL_CTRL **/
                           {
                              SYS_bit_clr (Bitlist, FH_TUERMODUL_CTRL__END_REVERS_copy_IDX);
                              if (SYS_bit_get (Bitlist, FH_TUERMODUL_CTRL__END_REVERS_IDX))
                              {
                                 stable = 0;
                                 FH_TUERMODUL__MFHZ_copy = 1;
                                 FH_TUERMODUL_CTRL__INREVERS2_copy = 0;
                                 
                                 TIPP_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 2;
                                  FH_TUERMODUL__MFHA_copy = 0;
                                  
                                 SYS_bit_set(Bitlist, active_EINKLEMMSCHUTZ_CTRL_copy_IDX);
                                 break;
                              }
                              break;
                           }
                           case 2 : /** state TIPP_SCHLIESSEN1 in chart FH_TUERMODUL_CTRL **/
                           {
                              if (SYS_bit_get (Bitlist, FH_TUERMODUL__EINKLEMMUNG_IDX))
                              {
                                 stable = 0;
                                 FH_TUERMODUL_CTRL__INREVERS2_copy = 1;
                                 
                                 SYS_bit_set (Bitlist, FH_TUERMODUL_CTRL__END_REVERS_copy_IDX);
                                 TIPP_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 1;
                                  SYS_bit_clr(Bitlist, active_EINKLEMMSCHUTZ_CTRL_copy_IDX);
                                 FH_TUERMODUL__MFHZ_copy = 0;
                                  
                                 sc_FH_TUERMODUL_CTRL_1781_10 = time;
                                 FH_TUERMODUL__MFHA_copy = 1;
                                 break;
                              }
                              break;
                           }
                           default:
                           {
                              stable = 0;
                              TIPP_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 2;
                              SYS_bit_set(Bitlist, active_EINKLEMMSCHUTZ_CTRL_copy_IDX);
                              break;
                           }
                        }/** switch TIPP_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state **/
                        break;
                     }
                     case 2 : /** state MANUELL_SCHLIESSEN in chart FH_TUERMODUL_CTRL **/
                     {
                        if ((!(FH_TUERMODUL__SFHZ) && FH_TUERMODUL__SFHZ_old))
                        {
                           stable = 0;
                           FH_TUERMODUL__MFHZ_copy = 0;
                           
                           INITIALISIERT_FH_TUERMODUL_CTRL_next_state = 3;
                           break;
                        }
                        switch (MANUELL_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state)
                        {
                           case 1 : /** state REVERSIEREN1 in chart FH_TUERMODUL_CTRL **/
                           {
                              SYS_bit_clr (Bitlist, FH_TUERMODUL_CTRL__END_REVERS_copy_IDX);
                              if (SYS_bit_get (Bitlist, FH_TUERMODUL_CTRL__END_REVERS_IDX))
                              {
                                 stable = 0;
                                 FH_TUERMODUL_CTRL__INREVERS1_copy = 0;
                                 
                                 MANUELL_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 2;
                                  FH_TUERMODUL__MFHA_copy = 0;
                                  
                                 SYS_bit_set(Bitlist, active_EINKLEMMSCHUTZ_CTRL_copy_IDX);
                                 FH_TUERMODUL__MFHZ_copy = 1;
                                 break;
                              }
                              break;
                           }
                           case 2 : /** state MAN_SCHLIESSEN in chart FH_TUERMODUL_CTRL **/
                           {
                              if (SYS_bit_get (Bitlist, FH_TUERMODUL__EINKLEMMUNG_IDX))
                              {
                                 stable = 0;
                                 FH_TUERMODUL__MFHZ_copy = 0;
                                 FH_TUERMODUL_CTRL__INREVERS1_copy = 1;
                                 
                                 SYS_bit_set (Bitlist, FH_TUERMODUL_CTRL__END_REVERS_copy_IDX);
                                 MANUELL_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 1;
                                  SYS_bit_clr(Bitlist, active_EINKLEMMSCHUTZ_CTRL_copy_IDX);
                                  
                                 sc_FH_TUERMODUL_CTRL_1739_10 = time;
                                 FH_TUERMODUL__MFHA_copy = 1;
                                 break;
                              }
                              if ((FH_TUERMODUL__SFHA && !(FH_TUERMODUL__SFHA_old)))
                              {
                                 stable = 0;
                                 
                                 SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 1;
                                 MANUELL_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 0;
                                 break;
                              }
                              break;
                           }
                           default:
                           {
                              stable = 0;
                              MANUELL_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 2;
                              SYS_bit_set(Bitlist, active_EINKLEMMSCHUTZ_CTRL_copy_IDX);
                              FH_TUERMODUL__MFHZ_copy = 1;
                              break;
                           }
                        }/** switch MANUELL_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state **/
                        break;
                     }
                     default:
                     {
                        stable = 0;
                        SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 2;
                        MANUELL_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 2;
                        SYS_bit_set(Bitlist, active_EINKLEMMSCHUTZ_CTRL_copy_IDX);
                        FH_TUERMODUL__MFHZ_copy = 1;
                        break;
                     }
                  }/** switch SCHLIESSEN_FH_TUERMODUL_CTRL_next_state **/
                  break;
               }
               case 3 : /** state BEREIT in chart FH_TUERMODUL_CTRL **/
               {
                  if (((FH_TUERMODUL__SFHZ && !(FH_TUERMODUL__SFHZ_old))) && ((FH_TUERMODUL__POSITION > 0)))
                  {
                     stable = 0;
                     
                     INITIALISIERT_FH_TUERMODUL_CTRL_next_state = 2;
                     SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 2;
                     MANUELL_SCHLIESSEN_FH_TUERMODUL_CTRL_next_state = 2;
                     SYS_bit_set(Bitlist, active_EINKLEMMSCHUTZ_CTRL_copy_IDX);
                     FH_TUERMODUL__MFHZ_copy = 1;
                     break;
                  }
                  if (((FH_TUERMODUL__SFHA && !(FH_TUERMODUL__SFHA_old))) && ((FH_TUERMODUL__POSITION < 405)))
                  {
                     stable = 0;
                     FH_TUERMODUL__MFHA_copy = 1;
                     
                     INITIALISIERT_FH_TUERMODUL_CTRL_next_state = 1;
                     OEFFNEN_FH_TUERMODUL_CTRL_next_state = 2;
                     break;
                  }
                  break;
               }
               default:
               {
                  stable = 0;
                  INITIALISIERT_FH_TUERMODUL_CTRL_next_state = 3;
                  break;
               }
            }/** switch INITIALISIERT_FH_TUERMODUL_CTRL_next_state **/
            break;
         }
         default:
         {
            stable = 0;
            B_FH_TUERMODUL_CTRL_next_state = 2;
            break;
         }
      }/** switch B_FH_TUERMODUL_CTRL_next_state **/
      switch (A_FH_TUERMODUL_CTRL_next_state)
      {
         case 1 : /** state WIEDERHOLSPERRE in chart FH_TUERMODUL_CTRL **/
         {
            SYS_bit_clr (Bitlist, entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_copy_IDX);
            if ((step == 1 && tm_entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRLexited_BEREIT_FH_TUERMODUL_CTRL != 0 && (time - tm_entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRLexited_BEREIT_FH_TUERMODUL_CTRL == 1)) && ((FH_TUERMODUL__MFHZ || FH_TUERMODUL__MFHA)))
            {
               stable = 0;
               FH_TUERMODUL_CTRL__N = FH_TUERMODUL_CTRL__N + 1;
               
               A_FH_TUERMODUL_CTRL_next_state = 1;
               SYS_bit_set (Bitlist, entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_copy_IDX);
               WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_next_state = 1;
               break;
            }
            switch (WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_next_state)
            {
               case 1 : /** state WDHSP in chart FH_TUERMODUL_CTRL **/
               {
                  if ((step == 1 && tm_entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL != 0 && (time - tm_entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL == 3)) && (((!(FH_TUERMODUL__MFHZ || FH_TUERMODUL__MFHA)) && FH_TUERMODUL_CTRL__N > 0)))
                  {
                     stable = 0;
                     FH_TUERMODUL_CTRL__N = FH_TUERMODUL_CTRL__N - 1;
                     
                     WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_next_state = 1;
                     break;
                  }
                  break;
               }
               default:
               {
                  stable = 0;
                  SYS_bit_set (Bitlist, entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_copy_IDX);
                  WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_next_state = 1;
                  break;
               }
            }/** switch WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_next_state **/
            break;
         }
         default:
         {
            stable = 0;
             FH_TUERMODUL_CTRL__N = 0;
            A_FH_TUERMODUL_CTRL_next_state = 1;
            SYS_bit_set (Bitlist, entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_copy_IDX);
            WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_next_state = 1;
            break;
         }
      }/** switch A_FH_TUERMODUL_CTRL_next_state **/
      SYS_bit_cpy(Bitlist, entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_copy_IDX, Bitlist, entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_IDX);
      SYS_bit_cpy (Bitlist, exited_BEREIT_FH_TUERMODUL_CTRL_copy_IDX, Bitlist, exited_BEREIT_FH_TUERMODUL_CTRL_IDX);
   }
}

void generic_EINKLEMMSCHUTZ_CTRL(void)
{
   if (SYS_bit_get(Bitlist,active_EINKLEMMSCHUTZ_CTRL_IDX))
   {
      switch (EINKLEMMSCHUTZ_CTRL_EINKLEMMSCHUTZ_CTRL_next_state)
      {
         case 1 : /** state NORMALBETRIEB in chart EINKLEMMSCHUTZ_CTRL **/
         {
            if (((FH_TUERMODUL__EKS_LEISTE_AKTIV && !(FH_TUERMODUL__EKS_LEISTE_AKTIV_old))) && ((!(FH_TUERMODUL__SFHZ && FH_TUERMODUL__SFHA))))
            {
               stable = 0;
                
               SYS_bit_set (Bitlist, FH_TUERMODUL__EINKLEMMUNG_IDX);
               EINKLEMMSCHUTZ_CTRL_EINKLEMMSCHUTZ_CTRL_next_state = 2;
               break;
            }
            break;
         }
         case 2 : /** state EINKLEMMUNG in chart EINKLEMMSCHUTZ_CTRL **/
         {
            SYS_bit_clr (Bitlist, FH_TUERMODUL__EINKLEMMUNG_IDX);
            if ((!(FH_TUERMODUL__EKS_LEISTE_AKTIV) && FH_TUERMODUL__EKS_LEISTE_AKTIV_old))
            {
               stable = 0;
               
               EINKLEMMSCHUTZ_CTRL_EINKLEMMSCHUTZ_CTRL_next_state = 1;
               break;
            }
            break;
         }
         default:
         {
            stable = 0;
            EINKLEMMSCHUTZ_CTRL_EINKLEMMSCHUTZ_CTRL_next_state = 1;
            break;
         }
      }/** switch EINKLEMMSCHUTZ_CTRL_EINKLEMMSCHUTZ_CTRL_next_state **/
   }
}

void generic_BLOCK_ERKENNUNG_CTRL(void)
{
   if (!SYS_bit_get(Bitlist, active_BLOCK_ERKENNUNG_CTRL_IDX) && SYS_bit_get(Bitlist,active_BLOCK_ERKENNUNG_CTRL_old_IDX) && !SYS_bit_get(Bitlist,active_BLOCK_ERKENNUNG_CTRL_copy_IDX))
   {
      SYS_bit_clr (Bitlist, entered_EINSCHALTSTROM_MESSEN_BLOCK_ERKENNUNG_CTRL_IDX);
   }
   if (SYS_bit_get(Bitlist,active_BLOCK_ERKENNUNG_CTRL_IDX))
   {
      switch (BLOCK_ERKENNUNG_CTRL_BLOCK_ERKENNUNG_CTRL_next_state)
      {
         case 1 : /** state KEINE_BEWEGUNG in chart BLOCK_ERKENNUNG_CTRL **/
         {
            if ((FH_TUERMODUL__I_EIN != FH_TUERMODUL__I_EIN_old) && ((FH_TUERMODUL__I_EIN > 0)))
            {
               stable = 0;
                FH_TUERMODUL__BLOCK_copy = 0;
               
               BLOCK_ERKENNUNG_CTRL_BLOCK_ERKENNUNG_CTRL_next_state = 2;
                BLOCK_ERKENNUNG_CTRL__N = 0;
                 BLOCK_ERKENNUNG_CTRL__I_EIN_MAX = 2;
               BEWEGUNG_BLOCK_ERKENNUNG_CTRL_next_state = 3;
               SYS_bit_set (Bitlist, entered_EINSCHALTSTROM_MESSEN_BLOCK_ERKENNUNG_CTRL_IDX);
               break;
            }
            break;
         }
         case 2 : /** state BEWEGUNG in chart BLOCK_ERKENNUNG_CTRL **/
         {
            if ((!(FH_TUERMODUL__MFHA) && FH_TUERMODUL__MFHA_old) || (!(FH_TUERMODUL__MFHZ) && FH_TUERMODUL__MFHZ_old))
            {
               stable = 0;
               
               BLOCK_ERKENNUNG_CTRL_BLOCK_ERKENNUNG_CTRL_next_state = 1;
               BEWEGUNG_BLOCK_ERKENNUNG_CTRL_next_state = 0;
               break;
            }
            switch (BEWEGUNG_BLOCK_ERKENNUNG_CTRL_next_state)
            {
               case 1 : /** state FENSTER_BLOCKIERT in chart BLOCK_ERKENNUNG_CTRL **/
               {
                  break;
               }
               case 2 : /** state FENSTER_BEWEGT_SICH in chart BLOCK_ERKENNUNG_CTRL **/
               {
                  if ((FH_TUERMODUL__I_EIN > (BLOCK_ERKENNUNG_CTRL__I_EIN_MAX - 2)))
                  {
                     stable = 0;
                      FH_TUERMODUL__BLOCK_copy = 1;
                     
                     BEWEGUNG_BLOCK_ERKENNUNG_CTRL_next_state = 1;
                     break;
                  }
                  break;
               }
               case 3 : /** state EINSCHALTSTROM_MESSEN in chart BLOCK_ERKENNUNG_CTRL **/
               {
                  SYS_bit_clr (Bitlist, entered_EINSCHALTSTROM_MESSEN_BLOCK_ERKENNUNG_CTRL_IDX);
                  if ((BLOCK_ERKENNUNG_CTRL__N == 11 && !(BLOCK_ERKENNUNG_CTRL__N_old == 11)))
                  {
                     stable = 0;
                     
                     BEWEGUNG_BLOCK_ERKENNUNG_CTRL_next_state = 2;
                     break;
                  }
                  /** static reactions: **/
                  if (BEWEGUNG_BLOCK_ERKENNUNG_CTRL_next_state == 3)
                       {
                          if (step == 1 && tm_entered_EINSCHALTSTROM_MESSEN_BLOCK_ERKENNUNG_CTRLch_BLOCK_ERKENNUNG_CTRL__N_copy != 0 && (time - tm_entered_EINSCHALTSTROM_MESSEN_BLOCK_ERKENNUNG_CTRLch_BLOCK_ERKENNUNG_CTRL__N_copy == 0.002))
                     {
                         BLOCK_ERKENNUNG_CTRL__N = BLOCK_ERKENNUNG_CTRL__N + 1;
                          if ((FH_TUERMODUL__I_EIN > BLOCK_ERKENNUNG_CTRL__I_EIN_MAX))
                        {
                           BLOCK_ERKENNUNG_CTRL__I_EIN_MAX = FH_TUERMODUL__I_EIN;
                           
                        }
                        
                     }
                  }
                  /** end static reactions **/
                  break;
               }
               default:
               {
                  stable = 0;
                   BLOCK_ERKENNUNG_CTRL__N = 0;
                    BLOCK_ERKENNUNG_CTRL__I_EIN_MAX = 2;
                  BEWEGUNG_BLOCK_ERKENNUNG_CTRL_next_state = 3;
                  SYS_bit_set (Bitlist, entered_EINSCHALTSTROM_MESSEN_BLOCK_ERKENNUNG_CTRL_IDX);
                  break;
               }
            }/** switch BEWEGUNG_BLOCK_ERKENNUNG_CTRL_next_state **/
            break;
         }
         default:
         {
            stable = 0;
            BLOCK_ERKENNUNG_CTRL_BLOCK_ERKENNUNG_CTRL_next_state = 1;
            break;
         }
      }/** switch BLOCK_ERKENNUNG_CTRL_BLOCK_ERKENNUNG_CTRL_next_state **/
   }
}



void FH_DU(void)
{
   time = 1;  /**SYS_get_clock()**/
   stable = 0;
   step   = 0;
   while (!stable)
   {
      stable = 1;
      step++;
      {
         switch (FH_STEUERUNG_DUMMY_FH_STEUERUNG_DUMMY_next_state)
         {
            case 1 : /** state SCHLIESSEN in chart FH_STEUERUNG_DUMMY **/
            {
               if ((!(FH_DU__MFHZ) && FH_DU__MFHZ_old))
               {
                  stable = 0;
                  FH_DU__MFH = 0;
                  
                  FH_STEUERUNG_DUMMY_FH_STEUERUNG_DUMMY_next_state = 2;
                  break;
               }
               break;
            }
            case 2 : /** state BEREIT in chart FH_STEUERUNG_DUMMY **/
            {
               if ((FH_DU__MFHZ && !(FH_DU__MFHZ_old)))
               {
                  stable = 0;
                  FH_DU__MFH = -100;
                  
                  FH_STEUERUNG_DUMMY_FH_STEUERUNG_DUMMY_next_state = 1;
                  break;
               }
               if ((FH_DU__MFHA && !(FH_DU__MFHA_old)))
               {
                  stable = 0;
                  FH_DU__MFH = 100;
                  
                  FH_STEUERUNG_DUMMY_FH_STEUERUNG_DUMMY_next_state = 3;
                  break;
               }
               break;
            }
            case 3 : /** state OEFFNEN in chart FH_STEUERUNG_DUMMY **/
            {
               if ((!(FH_DU__MFHA) && FH_DU__MFHA_old))
               {
                  stable = 0;
                  FH_DU__MFH = 0;
                  
                  FH_STEUERUNG_DUMMY_FH_STEUERUNG_DUMMY_next_state = 2;
                  break;
               }
               break;
            }
            default:
            {
               stable = 0;
                FH_DU__MFH = 0;
               FH_STEUERUNG_DUMMY_FH_STEUERUNG_DUMMY_next_state = 2;
               break;
            }
         }/** switch FH_STEUERUNG_DUMMY_FH_STEUERUNG_DUMMY_next_state **/
      }
      {
         {
            if (!SYS_bit_get(Bitlist, active_KINDERSICHERUNG_CTRL_IDX))
            {
               KINDERSICHERUNG_CTRL_KINDERSICHERUNG_CTRL_next_state = 3;
            }
            SYS_bit_clr(Bitlist, active_KINDERSICHERUNG_CTRL_copy_IDX);
            if (!SYS_bit_get(Bitlist, active_EINKLEMMSCHUTZ_CTRL_IDX))
            {
               EINKLEMMSCHUTZ_CTRL_EINKLEMMSCHUTZ_CTRL_next_state = 1;
            }
            SYS_bit_clr(Bitlist, active_EINKLEMMSCHUTZ_CTRL_copy_IDX);
            if (!SYS_bit_get(Bitlist, active_BLOCK_ERKENNUNG_CTRL_IDX))
            {
               SYS_bit_clr (Bitlist, entered_EINSCHALTSTROM_MESSEN_BLOCK_ERKENNUNG_CTRL_IDX);
               BLOCK_ERKENNUNG_CTRL_BLOCK_ERKENNUNG_CTRL_next_state = 1;
            }
            SYS_bit_clr(Bitlist, active_BLOCK_ERKENNUNG_CTRL_copy_IDX);
            if (!SYS_bit_get(Bitlist, active_FH_TUERMODUL_CTRL_IDX))
            {
               SYS_bit_clr (Bitlist, entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_IDX);
               SYS_bit_clr (Bitlist, exited_BEREIT_FH_TUERMODUL_CTRL_IDX);
               B_FH_TUERMODUL_CTRL_next_state = 2;
                FH_TUERMODUL_CTRL__N = 0;
               A_FH_TUERMODUL_CTRL_next_state = 1;
               SYS_bit_set (Bitlist, entered_WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_copy_IDX);
               WIEDERHOLSPERRE_FH_TUERMODUL_CTRL_next_state = 1;
            }
            SYS_bit_clr(Bitlist, active_FH_TUERMODUL_CTRL_copy_IDX);
            SYS_bit_set(Bitlist, active_KINDERSICHERUNG_CTRL_copy_IDX);
            SYS_bit_set(Bitlist, active_EINKLEMMSCHUTZ_CTRL_copy_IDX);
            SYS_bit_set(Bitlist, active_BLOCK_ERKENNUNG_CTRL_copy_IDX);
            SYS_bit_set(Bitlist, active_FH_TUERMODUL_CTRL_copy_IDX);
            /** static reactions: **/
            if (FH_DU__S_FH_TMBFZUCAN != FH_DU__S_FH_TMBFZUCAN_old)
            {
                if ((!FH_DU__DOOR_ID))
               {
                  FH_DU__S_FH_FTZU = FH_DU__S_FH_TMBFZUCAN;
                  
               }
               
            }
            if (FH_DU__S_FH_TMBFZUDISC != FH_DU__S_FH_TMBFZUDISC_old)
            {
                if (FH_DU__DOOR_ID)
               {
                  FH_DU__S_FH_TMBFZUCAN = FH_DU__S_FH_TMBFZUDISC;
                  
               }
               
            }
            if (FH_DU__S_FH_TMBFAUFCAN != FH_DU__S_FH_TMBFAUFCAN_old)
            {
                if ((!FH_DU__DOOR_ID))
               {
                  FH_DU__S_FH_FTAUF = FH_DU__S_FH_TMBFAUFCAN;
                  
               }
               
            }
            if (FH_DU__S_FH_TMBFAUFDISC != FH_DU__S_FH_TMBFAUFDISC_old)
            {
                if (FH_DU__DOOR_ID)
               {
                  FH_DU__S_FH_TMBFAUFCAN = FH_DU__S_FH_TMBFAUFDISC;
                  
               }
               
            }
            /** end static reactions **/
         }
      }
      SYS_bit_cpy(Bitlist, active_KINDERSICHERUNG_CTRL_IDX, Bitlist, active_KINDERSICHERUNG_CTRL_old_IDX);
      SYS_bit_cpy(Bitlist, active_FH_TUERMODUL_CTRL_IDX, Bitlist, active_FH_TUERMODUL_CTRL_old_IDX);
      SYS_bit_cpy(Bitlist, active_EINKLEMMSCHUTZ_CTRL_IDX, Bitlist, active_EINKLEMMSCHUTZ_CTRL_old_IDX);
      SYS_bit_cpy(Bitlist, active_BLOCK_ERKENNUNG_CTRL_IDX, Bitlist, active_BLOCK_ERKENNUNG_CTRL_old_IDX);
       FH_TUERMODUL__SFHA_MEC = FH_DU__S_FH_AUFDISC;
       FH_TUERMODUL__SFHA_ZENTRAL = FH_DU__S_FH_FTAUF;
       FH_TUERMODUL__SFHZ_MEC = FH_DU__S_FH_ZUDISC;
       FH_TUERMODUL__SFHZ_ZENTRAL = FH_DU__S_FH_FTZU;
      
      generic_KINDERSICHERUNG_CTRL();
      
       FH_DU__MFHA = FH_TUERMODUL__MFHA;
       FH_DU__MFHZ = FH_TUERMODUL__MFHZ;
       FH_DU__I_EIN = FH_TUERMODUL__I_EIN;
       FH_DU__EKS_LEISTE_AKTIV = FH_TUERMODUL__EKS_LEISTE_AKTIV;
       FH_DU__POSITION = FH_TUERMODUL__POSITION;
       FH_DU__FT = FH_TUERMODUL__FT;
       FH_DU__S_FH_AUFDISC = FH_TUERMODUL__SFHA_MEC;
       FH_DU__S_FH_FTAUF = FH_TUERMODUL__SFHA_ZENTRAL;
       FH_DU__S_FH_ZUDISC = FH_TUERMODUL__SFHZ_MEC;
       FH_DU__S_FH_FTZU = FH_TUERMODUL__SFHZ_ZENTRAL;
       FH_DU__KL_50 = FH_TUERMODUL__KL_50;
       FH_DU__BLOCK = FH_TUERMODUL__BLOCK;
      
       FH_TUERMODUL__SFHA_MEC = FH_DU__S_FH_AUFDISC;
       FH_TUERMODUL__SFHA_ZENTRAL = FH_DU__S_FH_FTAUF;
       FH_TUERMODUL__SFHZ_MEC = FH_DU__S_FH_ZUDISC;
       FH_TUERMODUL__SFHZ_ZENTRAL = FH_DU__S_FH_FTZU;
      
      generic_FH_TUERMODUL_CTRL();
      
       FH_DU__MFHA = FH_TUERMODUL__MFHA;
       FH_DU__MFHZ = FH_TUERMODUL__MFHZ;
       FH_DU__I_EIN = FH_TUERMODUL__I_EIN;
       FH_DU__EKS_LEISTE_AKTIV = FH_TUERMODUL__EKS_LEISTE_AKTIV;
       FH_DU__POSITION = FH_TUERMODUL__POSITION;
       FH_DU__FT = FH_TUERMODUL__FT;
       FH_DU__S_FH_AUFDISC = FH_TUERMODUL__SFHA_MEC;
       FH_DU__S_FH_FTAUF = FH_TUERMODUL__SFHA_ZENTRAL;
       FH_DU__S_FH_ZUDISC = FH_TUERMODUL__SFHZ_MEC;
       FH_DU__S_FH_FTZU = FH_TUERMODUL__SFHZ_ZENTRAL;
       FH_DU__KL_50 = FH_TUERMODUL__KL_50;
       FH_DU__BLOCK = FH_TUERMODUL__BLOCK;
      
       FH_TUERMODUL__SFHA_MEC = FH_DU__S_FH_AUFDISC;
       FH_TUERMODUL__SFHA_ZENTRAL = FH_DU__S_FH_FTAUF;
       FH_TUERMODUL__SFHZ_MEC = FH_DU__S_FH_ZUDISC;
       FH_TUERMODUL__SFHZ_ZENTRAL = FH_DU__S_FH_FTZU;
      
      generic_EINKLEMMSCHUTZ_CTRL();
      
       FH_DU__MFHA = FH_TUERMODUL__MFHA;
       FH_DU__MFHZ = FH_TUERMODUL__MFHZ;
       FH_DU__I_EIN = FH_TUERMODUL__I_EIN;
       FH_DU__EKS_LEISTE_AKTIV = FH_TUERMODUL__EKS_LEISTE_AKTIV;
       FH_DU__POSITION = FH_TUERMODUL__POSITION;
       FH_DU__FT = FH_TUERMODUL__FT;
       FH_DU__S_FH_AUFDISC = FH_TUERMODUL__SFHA_MEC;
       FH_DU__S_FH_FTAUF = FH_TUERMODUL__SFHA_ZENTRAL;
       FH_DU__S_FH_ZUDISC = FH_TUERMODUL__SFHZ_MEC;
       FH_DU__S_FH_FTZU = FH_TUERMODUL__SFHZ_ZENTRAL;
       FH_DU__KL_50 = FH_TUERMODUL__KL_50;
       FH_DU__BLOCK = FH_TUERMODUL__BLOCK;
      
       FH_TUERMODUL__SFHA_MEC = FH_DU__S_FH_AUFDISC;
       FH_TUERMODUL__SFHA_ZENTRAL = FH_DU__S_FH_FTAUF;
       FH_TUERMODUL__SFHZ_MEC = FH_DU__S_FH_ZUDISC;
       FH_TUERMODUL__SFHZ_ZENTRAL = FH_DU__S_FH_FTZU;
      
      generic_BLOCK_ERKENNUNG_CTRL();
      
       FH_DU__MFHA = FH_TUERMODUL__MFHA;
       FH_DU__MFHZ = FH_TUERMODUL__MFHZ;
       FH_DU__I_EIN = FH_TUERMODUL__I_EIN;
       FH_DU__EKS_LEISTE_AKTIV = FH_TUERMODUL__EKS_LEISTE_AKTIV;
       FH_DU__POSITION = FH_TUERMODUL__POSITION;
       FH_DU__FT = FH_TUERMODUL__FT;
       FH_DU__S_FH_AUFDISC = FH_TUERMODUL__SFHA_MEC;
       FH_DU__S_FH_FTAUF = FH_TUERMODUL__SFHA_ZENTRAL;
       FH_DU__S_FH_ZUDISC = FH_TUERMODUL__SFHZ_MEC;
       FH_DU__S_FH_FTZU = FH_TUERMODUL__SFHZ_ZENTRAL;
       FH_DU__KL_50 = FH_TUERMODUL__KL_50;
       FH_DU__BLOCK = FH_TUERMODUL__BLOCK;
      
      SYS_bit_cpy(Bitlist, active_KINDERSICHERUNG_CTRL_copy_IDX, Bitlist, active_KINDERSICHERUNG_CTRL_IDX);
      SYS_bit_cpy(Bitlist, active_FH_TUERMODUL_CTRL_copy_IDX, Bitlist, active_FH_TUERMODUL_CTRL_IDX);
      SYS_bit_cpy(Bitlist, active_EINKLEMMSCHUTZ_CTRL_copy_IDX, Bitlist, active_EINKLEMMSCHUTZ_CTRL_IDX);
      SYS_bit_cpy(Bitlist, active_BLOCK_ERKENNUNG_CTRL_copy_IDX, Bitlist, active_BLOCK_ERKENNUNG_CTRL_IDX);
      FH_TUERMODUL_CTRL__N_old = FH_TUERMODUL_CTRL__N;
      FH_TUERMODUL__I_EIN_old = FH_TUERMODUL__I_EIN;
      FH_DU__MFH = FH_DU__MFH_copy;
      FH_DU__I_EIN_old = FH_DU__I_EIN;
      BLOCK_ERKENNUNG_CTRL__N_old = BLOCK_ERKENNUNG_CTRL__N;
      FH_TUERMODUL__SFHZ_ZENTRAL_old = FH_TUERMODUL__SFHZ_ZENTRAL;
      FH_TUERMODUL__SFHZ_MEC_old = FH_TUERMODUL__SFHZ_MEC;
      FH_TUERMODUL__SFHA_ZENTRAL_old = FH_TUERMODUL__SFHA_ZENTRAL;
      FH_TUERMODUL__SFHA_MEC_old = FH_TUERMODUL__SFHA_MEC;
      FH_TUERMODUL__BLOCK = FH_TUERMODUL__BLOCK_copy;
      FH_TUERMODUL__BLOCK_old = FH_TUERMODUL__BLOCK;
      FH_TUERMODUL__SFHZ = FH_TUERMODUL__SFHZ_copy;
      FH_TUERMODUL__SFHZ_old = FH_TUERMODUL__SFHZ;
      FH_TUERMODUL__SFHA = FH_TUERMODUL__SFHA_copy;
      FH_TUERMODUL__SFHA_old = FH_TUERMODUL__SFHA;
      FH_TUERMODUL__MFHZ = FH_TUERMODUL__MFHZ_copy;
      FH_TUERMODUL__MFHZ_old = FH_TUERMODUL__MFHZ;
      FH_TUERMODUL__MFHA = FH_TUERMODUL__MFHA_copy;
      FH_TUERMODUL__MFHA_old = FH_TUERMODUL__MFHA;
      FH_TUERMODUL__EKS_LEISTE_AKTIV_old = FH_TUERMODUL__EKS_LEISTE_AKTIV;
      FH_DU__EKS_LEISTE_AKTIV_old = FH_DU__EKS_LEISTE_AKTIV;
      FH_DU__S_FH_TMBFAUFCAN_old = FH_DU__S_FH_TMBFAUFCAN;
      FH_DU__S_FH_TMBFZUCAN_old = FH_DU__S_FH_TMBFZUCAN;
      FH_DU__S_FH_TMBFZUDISC_old = FH_DU__S_FH_TMBFZUDISC;
      FH_DU__S_FH_TMBFAUFDISC_old = FH_DU__S_FH_TMBFAUFDISC;
      FH_DU__BLOCK = FH_DU__BLOCK_copy;
      FH_DU__BLOCK_old = FH_DU__BLOCK;
      FH_DU__MFHZ = FH_DU__MFHZ_copy;
      FH_DU__MFHZ_old = FH_DU__MFHZ;
      FH_DU__MFHA = FH_DU__MFHA_copy;
      FH_DU__MFHA_old = FH_DU__MFHA;
      
   }/** while(!stable) **/
   
}/** FH_DU **/



int main(void)
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
  	init();
  	interface();
  	FH_DU();
	//====================== Target Flow ======================
	
	t = get_cyclecount() - t;
	numCycles = t - overhead;
	*(addr+(numberExecutions)) = numCycles;
	cache_maintenance();
    }

  return 0;
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



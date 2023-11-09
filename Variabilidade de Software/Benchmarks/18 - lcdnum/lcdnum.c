unsigned char num_to_lcd(unsigned char a){
  switch(a){
    case 0x00: return 0;
    case 0x01: return 0x24;
    case 0x02: return 1+4+8+16+64;
    case 0x03: return 1+4+8+32+64;
    case 0x04: return 2+4+8+32;
    case 0x05: return 1+4+8+16+64;
    case 0x06: return 1+2+8+16+32+64;
    case 0x07: return 1+4+32;
    case 0x08: return 0x7F;     /* light all */
    case 0x09: return 0x0F + 32 + 64;
    case 0x0A: return 0x0F + 16 + 32;
    case 0x0B: return 2+8+16+32+64;
    case 0x0C: return 1+2+16+64;
    case 0x0D: return 4+8+16+32+64;
    case 0x0E: return 1+2+8+16+64;
    case 0x0F: return 1+2+8+16;
    }
  return 0;
}

unsigned char IN;
unsigned char OUT;

int main(void){
  int           i;
  unsigned char a;
  int  n; /* JG */

  n = 10;
  for(i=0; i< n; i++){
      //a = IN;                   /* scan port */
      a = 0;
      if(i<5){
          a = a &0x0F;
          OUT = num_to_lcd(a);
      }
    }
  return 0;
}

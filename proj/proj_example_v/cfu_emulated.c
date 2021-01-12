#include <stdint.h>

uint32_t Cfu(uint32_t functionid, uint32_t rs1, uint32_t rs2)
{
  uint32_t retval = 0;

  if (functionid & 0x2) {
    // bitreverse (rs1)
    for (int i=0; i<32; ++i) {
      retval |= (((rs1 >>i) & 0x1) << (31-i));
    }
  }
  else if (functionid & 0x1) {
    // byte swap (rs1)
    for (int i=0; i<32; i+=8) {
      retval |= (((rs1 >>i) & 0xff) << (24-i));
    }
  } else {
    // byte sum
    retval += (rs1 & 0xff) + (rs2 & 0xff);
    rs1 >>= 8;
    rs2 >>= 8;
    retval += (rs1 & 0xff) + (rs2 & 0xff);
    rs1 >>= 8;
    rs2 >>= 8;
    retval += (rs1 & 0xff) + (rs2 & 0xff);
    rs1 >>= 8;
    rs2 >>= 8;
    retval += (rs1 & 0xff) + (rs2 & 0xff);
  }
  return retval;
}



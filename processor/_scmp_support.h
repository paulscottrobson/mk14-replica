static void inline fetch() {
 p0 = (p0+1) & 0xFFFF;
 mar = p0;
 pcread();
}
static void inline eacIndex(WORD16 pp) {
 if (mbr == 0x80) mbr = e;
 t16 = ((mbr & 0x80) != 0) ? (mbr | 0xFF00) : mbr;
 mar = (pp & 0xF000) | ((pp+t16) & 0xFFF);
}
static void inline eacBasicIndex(WORD16 pp) {
 t16 = ((mbr & 0x80) != 0) ? (mbr | 0xFF00) : mbr;
 mar = (pp & 0xF000) | ((pp+t16) & 0xFFF);
}
static WORD16 inline eacAutoIndex(WORD16 pp) {
 if (mbr == 0x80) mbr = e;
 if ((mbr & 0x80) == 0) {
  mar = pp;
  t16 = (pp & 0xF000) | ((pp+mbr) & 0xFFF);
 } else {
  t16 = (pp & 0xF000) | ((pp+(mbr|0xFF00)) & 0xFFF);
  mar = t16;
 }
 return t16;
}
static void decimalAdd() {
 t16 = (mbr & 0x0F) + (a & 0x0F) + cyl;
 if (t16 > 9) {
  t16 = t16 + 6;
 }
 t16 = t16 + (mbr & 0xF0) + (a & 0xF0);
 cyl = 0;
 if (t16 > 0x99) {
  cyl = 1;
  t16 = t16 + 0x60;
 }
 a = (t16 & 0xFF);
}
static void inline binaryAdd() {
 t16 = a + mbr + cyl;
 overflow = 0;
 if (((a ^ mbr) & 0x80) == 0) {
  if (((a ^ t16) & 0x80) != 0) overflow = 1;
 }
 a = (t16 & 0xFF);
 cyl = (t16 >> 8) & 1;
}
static void correctStatusRegister() {
 status = status & 0x0F;
 if (io_sensea()) status = status | 0x10;
 if (io_senseb()) status = status | 0x20;
 if (overflow != 0) status = status | 0x40;
 if (cyl != 0) status = status | 0x80;
}
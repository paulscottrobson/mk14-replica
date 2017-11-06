case 0x00: /** halt **/
   ;;cycles = cycles + 8;break;
case 0x01: /** xae **/
   t16 = a;a = e;e = t16;cycles = cycles + 7;break;
case 0x02: /** ccl **/
   cyl = 0;cycles = cycles + 5;break;
case 0x03: /** scl **/
   cyl = 1;cycles = cycles + 5;break;
case 0x04: /** dint **/
   status = status & 0xF7;cycles = cycles + 6;break;
case 0x05: /** ien **/
   status = status | 0x08;cycles = cycles + 6;break;
case 0x06: /** csa **/
   correctStatusRegister();a = status;cycles = cycles + 5;break;
case 0x07: /** cas **/
   status = a;io_flags(a & 7);cyl = (a>>7) & 1;overflow = (a>>6) & 1;correctStatusRegister();cycles = cycles + 6;break;
case 0x08: /** nop **/
   ;;cycles = cycles + 5;break;
case 0x09: /** byte 09 **/
   ;;break;
case 0x0a: /** byte 0a **/
   ;;break;
case 0x0b: /** byte 0b **/
   ;;break;
case 0x0c: /** byte 0c **/
   ;;break;
case 0x0d: /** byte 0d **/
   ;;break;
case 0x0e: /** byte 0e **/
   ;;break;
case 0x0f: /** byte 0f **/
   ;;break;
case 0x10: /** byte 10 **/
   ;;break;
case 0x11: /** byte 11 **/
   ;;break;
case 0x12: /** byte 12 **/
   ;;break;
case 0x13: /** byte 13 **/
   ;;break;
case 0x14: /** byte 14 **/
   ;;break;
case 0x15: /** byte 15 **/
   ;;break;
case 0x16: /** byte 16 **/
   ;;break;
case 0x17: /** byte 17 **/
   ;;break;
case 0x18: /** byte 18 **/
   ;;break;
case 0x19: /** sio **/
   io_sout(e & 1);e = e >> 1;if (io_sin() != 0) e |= 0x80;;cycles = cycles + 5;break;
case 0x1a: /** byte 1a **/
   ;;break;
case 0x1b: /** byte 1b **/
   ;;break;
case 0x1c: /** sr **/
   a = (a >> 1) & 0x7F;cycles = cycles + 5;break;
case 0x1d: /** srl **/
   a = ((a >> 1) & 0x7F) | (cyl << 7);cycles = cycles + 5;break;
case 0x1e: /** rr **/
   a = ((a >> 1) | (a << 7)) & 0xFF;cycles = cycles + 5;break;
case 0x1f: /** rrl **/
   t16 = a | (cyl << 8);cyl = a & 1;a = (t16 >> 1) & 0xFF;cycles = cycles + 5;break;
case 0x20: /** byte 20 **/
   ;;break;
case 0x21: /** byte 21 **/
   ;;break;
case 0x22: /** byte 22 **/
   ;;break;
case 0x23: /** byte 23 **/
   ;;break;
case 0x24: /** byte 24 **/
   ;;break;
case 0x25: /** byte 25 **/
   ;;break;
case 0x26: /** byte 26 **/
   ;;break;
case 0x27: /** byte 27 **/
   ;;break;
case 0x28: /** byte 28 **/
   ;;break;
case 0x29: /** byte 29 **/
   ;;break;
case 0x2a: /** byte 2a **/
   ;;break;
case 0x2b: /** byte 2b **/
   ;;break;
case 0x2c: /** byte 2c **/
   ;;break;
case 0x2d: /** byte 2d **/
   ;;break;
case 0x2e: /** byte 2e **/
   ;;break;
case 0x2f: /** byte 2f **/
   ;;break;
case 0x30: /** xpal p0 **/
   t16 = p0;p0 = (p0 & 0xFF00) | a;a = t16 & 0xFF;cycles = cycles + 8;break;
case 0x31: /** xpal p1 **/
   t16 = p1;p1 = (p1 & 0xFF00) | a;a = t16 & 0xFF;cycles = cycles + 8;break;
case 0x32: /** xpal p2 **/
   t16 = p2;p2 = (p2 & 0xFF00) | a;a = t16 & 0xFF;cycles = cycles + 8;break;
case 0x33: /** xpal p3 **/
   t16 = p3;p3 = (p3 & 0xFF00) | a;a = t16 & 0xFF;cycles = cycles + 8;break;
case 0x34: /** xpah p0 **/
   t16 = p0;p0 = (p0 & 0x00FF) | (a << 8);a = (t16 >> 8) & 0xFF;cycles = cycles + 8;break;
case 0x35: /** xpah p1 **/
   t16 = p1;p1 = (p1 & 0x00FF) | (a << 8);a = (t16 >> 8) & 0xFF;cycles = cycles + 8;break;
case 0x36: /** xpah p2 **/
   t16 = p2;p2 = (p2 & 0x00FF) | (a << 8);a = (t16 >> 8) & 0xFF;cycles = cycles + 8;break;
case 0x37: /** xpah p3 **/
   t16 = p3;p3 = (p3 & 0x00FF) | (a << 8);a = (t16 >> 8) & 0xFF;cycles = cycles + 8;break;
case 0x38: /** byte 38 **/
   ;;break;
case 0x39: /** byte 39 **/
   ;;break;
case 0x3a: /** byte 3a **/
   ;;break;
case 0x3b: /** byte 3b **/
   ;;break;
case 0x3c: /** xppc p0 **/
   t16 = p0;p0 = p0;p0 = t16;cycles = cycles + 7;break;
case 0x3d: /** xppc p1 **/
   t16 = p0;p0 = p1;p1 = t16;cycles = cycles + 7;break;
case 0x3e: /** xppc p2 **/
   t16 = p0;p0 = p2;p2 = t16;cycles = cycles + 7;break;
case 0x3f: /** xppc p3 **/
   t16 = p0;p0 = p3;p3 = t16;cycles = cycles + 7;break;
case 0x40: /** lde **/
   a = e;cycles = cycles + 6;break;
case 0x41: /** byte 41 **/
   ;;break;
case 0x42: /** byte 42 **/
   ;;break;
case 0x43: /** byte 43 **/
   ;;break;
case 0x44: /** byte 44 **/
   ;;break;
case 0x45: /** byte 45 **/
   ;;break;
case 0x46: /** byte 46 **/
   ;;break;
case 0x47: /** byte 47 **/
   ;;break;
case 0x48: /** byte 48 **/
   ;;break;
case 0x49: /** byte 49 **/
   ;;break;
case 0x4a: /** byte 4a **/
   ;;break;
case 0x4b: /** byte 4b **/
   ;;break;
case 0x4c: /** byte 4c **/
   ;;break;
case 0x4d: /** byte 4d **/
   ;;break;
case 0x4e: /** byte 4e **/
   ;;break;
case 0x4f: /** byte 4f **/
   ;;break;
case 0x50: /** ane **/
   a = a & e;cycles = cycles + 6;break;
case 0x51: /** byte 51 **/
   ;;break;
case 0x52: /** byte 52 **/
   ;;break;
case 0x53: /** byte 53 **/
   ;;break;
case 0x54: /** byte 54 **/
   ;;break;
case 0x55: /** byte 55 **/
   ;;break;
case 0x56: /** byte 56 **/
   ;;break;
case 0x57: /** byte 57 **/
   ;;break;
case 0x58: /** ore **/
   a = a | e;cycles = cycles + 6;break;
case 0x59: /** byte 59 **/
   ;;break;
case 0x5a: /** byte 5a **/
   ;;break;
case 0x5b: /** byte 5b **/
   ;;break;
case 0x5c: /** byte 5c **/
   ;;break;
case 0x5d: /** byte 5d **/
   ;;break;
case 0x5e: /** byte 5e **/
   ;;break;
case 0x5f: /** byte 5f **/
   ;;break;
case 0x60: /** xre **/
   a = a ^ e;cycles = cycles + 6;break;
case 0x61: /** byte 61 **/
   ;;break;
case 0x62: /** byte 62 **/
   ;;break;
case 0x63: /** byte 63 **/
   ;;break;
case 0x64: /** byte 64 **/
   ;;break;
case 0x65: /** byte 65 **/
   ;;break;
case 0x66: /** byte 66 **/
   ;;break;
case 0x67: /** byte 67 **/
   ;;break;
case 0x68: /** dae **/
   mbr = e ; decimalAdd();cycles = cycles + 11;break;
case 0x69: /** byte 69 **/
   ;;break;
case 0x6a: /** byte 6a **/
   ;;break;
case 0x6b: /** byte 6b **/
   ;;break;
case 0x6c: /** byte 6c **/
   ;;break;
case 0x6d: /** byte 6d **/
   ;;break;
case 0x6e: /** byte 6e **/
   ;;break;
case 0x6f: /** byte 6f **/
   ;;break;
case 0x70: /** ade **/
   mbr = e ; binaryAdd();cycles = cycles + 7;break;
case 0x71: /** byte 71 **/
   ;;break;
case 0x72: /** byte 72 **/
   ;;break;
case 0x73: /** byte 73 **/
   ;;break;
case 0x74: /** byte 74 **/
   ;;break;
case 0x75: /** byte 75 **/
   ;;break;
case 0x76: /** byte 76 **/
   ;;break;
case 0x77: /** byte 77 **/
   ;;break;
case 0x78: /** cae **/
   mbr = e ^ 0xFF; binaryAdd();cycles = cycles + 8;break;
case 0x79: /** byte 79 **/
   ;;break;
case 0x7a: /** byte 7a **/
   ;;break;
case 0x7b: /** byte 7b **/
   ;;break;
case 0x7c: /** byte 7c **/
   ;;break;
case 0x7d: /** byte 7d **/
   ;;break;
case 0x7e: /** byte 7e **/
   ;;break;
case 0x7f: /** byte 7f **/
   ;;break;
case 0x80: /** byte 80 **/
   ;;break;
case 0x81: /** byte 81 **/
   ;;break;
case 0x82: /** byte 82 **/
   ;;break;
case 0x83: /** byte 83 **/
   ;;break;
case 0x84: /** byte 84 **/
   ;;break;
case 0x85: /** byte 85 **/
   ;;break;
case 0x86: /** byte 86 **/
   ;;break;
case 0x87: /** byte 87 **/
   ;;break;
case 0x88: /** byte 88 **/
   ;;break;
case 0x89: /** byte 89 **/
   ;;break;
case 0x8a: /** byte 8a **/
   ;;break;
case 0x8b: /** byte 8b **/
   ;;break;
case 0x8c: /** byte 8c **/
   ;;break;
case 0x8d: /** byte 8d **/
   ;;break;
case 0x8e: /** byte 8e **/
   ;;break;
case 0x8f: /** dly %c **/
   fetch();delaycyclesfour = (2 * a + (2 + 512)*mbr)/4;a = 0;cycles = cycles + 13;break;
case 0x90: /** jmp %j **/
   fetch();eacBasicIndex(p0) ; p0 = mar;cycles = cycles + 11;break;
case 0x91: /** jmp %j **/
   fetch();eacBasicIndex(p1) ; p0 = mar;cycles = cycles + 11;break;
case 0x92: /** jmp %j **/
   fetch();eacBasicIndex(p2) ; p0 = mar;cycles = cycles + 11;break;
case 0x93: /** jmp %j **/
   fetch();eacBasicIndex(p3) ; p0 = mar;cycles = cycles + 11;break;
case 0x94: /** jp %j **/
   fetch();eacBasicIndex(p0) ; if ((a & 0x80) == 0) p0 = mar;cycles = cycles + 10;break;
case 0x95: /** jp %j **/
   fetch();eacBasicIndex(p1) ; if ((a & 0x80) == 0) p0 = mar;cycles = cycles + 10;break;
case 0x96: /** jp %j **/
   fetch();eacBasicIndex(p2) ; if ((a & 0x80) == 0) p0 = mar;cycles = cycles + 10;break;
case 0x97: /** jp %j **/
   fetch();eacBasicIndex(p3) ; if ((a & 0x80) == 0) p0 = mar;cycles = cycles + 10;break;
case 0x98: /** jz %j **/
   fetch();eacBasicIndex(p0) ; if (a == 0) p0 = mar;cycles = cycles + 10;break;
case 0x99: /** jz %j **/
   fetch();eacBasicIndex(p1) ; if (a == 0) p0 = mar;cycles = cycles + 10;break;
case 0x9a: /** jz %j **/
   fetch();eacBasicIndex(p2) ; if (a == 0) p0 = mar;cycles = cycles + 10;break;
case 0x9b: /** jz %j **/
   fetch();eacBasicIndex(p3) ; if (a == 0) p0 = mar;cycles = cycles + 10;break;
case 0x9c: /** jnz %j **/
   fetch();eacBasicIndex(p0) ; if (a != 0) p0 = mar;cycles = cycles + 10;break;
case 0x9d: /** jnz %j **/
   fetch();eacBasicIndex(p1) ; if (a != 0) p0 = mar;cycles = cycles + 10;break;
case 0x9e: /** jnz %j **/
   fetch();eacBasicIndex(p2) ; if (a != 0) p0 = mar;cycles = cycles + 10;break;
case 0x9f: /** jnz %j **/
   fetch();eacBasicIndex(p3) ; if (a != 0) p0 = mar;cycles = cycles + 10;break;
case 0xa0: /** byte a0 **/
   ;;break;
case 0xa1: /** byte a1 **/
   ;;break;
case 0xa2: /** byte a2 **/
   ;;break;
case 0xa3: /** byte a3 **/
   ;;break;
case 0xa4: /** byte a4 **/
   ;;break;
case 0xa5: /** byte a5 **/
   ;;break;
case 0xa6: /** byte a6 **/
   ;;break;
case 0xa7: /** byte a7 **/
   ;;break;
case 0xa8: /** ild %d(p0) **/
   fetch(); eacBasicIndex(p0) ; read() ; mbr = (mbr + 1) & 0xFF; write() ; a = mbr;cycles = cycles + 22;break;
case 0xa9: /** ild %d(p1) **/
   fetch(); eacBasicIndex(p1) ; read() ; mbr = (mbr + 1) & 0xFF; write() ; a = mbr;cycles = cycles + 22;break;
case 0xaa: /** ild %d(p2) **/
   fetch(); eacBasicIndex(p2) ; read() ; mbr = (mbr + 1) & 0xFF; write() ; a = mbr;cycles = cycles + 22;break;
case 0xab: /** ild %d(p3) **/
   fetch(); eacBasicIndex(p3) ; read() ; mbr = (mbr + 1) & 0xFF; write() ; a = mbr;cycles = cycles + 22;break;
case 0xac: /** byte ac **/
   ;;break;
case 0xad: /** byte ad **/
   ;;break;
case 0xae: /** byte ae **/
   ;;break;
case 0xaf: /** byte af **/
   ;;break;
case 0xb0: /** byte b0 **/
   ;;break;
case 0xb1: /** byte b1 **/
   ;;break;
case 0xb2: /** byte b2 **/
   ;;break;
case 0xb3: /** byte b3 **/
   ;;break;
case 0xb4: /** byte b4 **/
   ;;break;
case 0xb5: /** byte b5 **/
   ;;break;
case 0xb6: /** byte b6 **/
   ;;break;
case 0xb7: /** byte b7 **/
   ;;break;
case 0xb8: /** dld %d(p0) **/
   fetch(); eacBasicIndex(p0) ; read() ; mbr = (mbr + 0xFF) & 0xFF; write() ; a = mbr;cycles = cycles + 22;break;
case 0xb9: /** dld %d(p1) **/
   fetch(); eacBasicIndex(p1) ; read() ; mbr = (mbr + 0xFF) & 0xFF; write() ; a = mbr;cycles = cycles + 22;break;
case 0xba: /** dld %d(p2) **/
   fetch(); eacBasicIndex(p2) ; read() ; mbr = (mbr + 0xFF) & 0xFF; write() ; a = mbr;cycles = cycles + 22;break;
case 0xbb: /** dld %d(p3) **/
   fetch(); eacBasicIndex(p3) ; read() ; mbr = (mbr + 0xFF) & 0xFF; write() ; a = mbr;cycles = cycles + 22;break;
case 0xbc: /** byte bc **/
   ;;break;
case 0xbd: /** byte bd **/
   ;;break;
case 0xbe: /** byte be **/
   ;;break;
case 0xbf: /** byte bf **/
   ;;break;
case 0xc0: /** ld %d(p0) **/
   fetch();eacIndex(p0) ; read() ; a = mbr;cycles = cycles + 18;break;
case 0xc1: /** ld %d(p1) **/
   fetch();eacIndex(p1) ; read() ; a = mbr;cycles = cycles + 18;break;
case 0xc2: /** ld %d(p2) **/
   fetch();eacIndex(p2) ; read() ; a = mbr;cycles = cycles + 18;break;
case 0xc3: /** ld %d(p3) **/
   fetch();eacIndex(p3) ; read() ; a = mbr;cycles = cycles + 18;break;
case 0xc4: /** ldi %c **/
   fetch() ; a = mbr;cycles = cycles + 10;break;
case 0xc5: /** ld @%d(p1) **/
   fetch();p1 = eacAutoIndex(p1) ; read() ; a = mbr;cycles = cycles + 18;break;
case 0xc6: /** ld @%d(p2) **/
   fetch();p2 = eacAutoIndex(p2) ; read() ; a = mbr;cycles = cycles + 18;break;
case 0xc7: /** ld @%d(p3) **/
   fetch();p3 = eacAutoIndex(p3) ; read() ; a = mbr;cycles = cycles + 18;break;
case 0xc8: /** st %d(p0) **/
   fetch();eacIndex(p0) ; mbr = a ; write();cycles = cycles + 18;break;
case 0xc9: /** st %d(p1) **/
   fetch();eacIndex(p1) ; mbr = a ; write();cycles = cycles + 18;break;
case 0xca: /** st %d(p2) **/
   fetch();eacIndex(p2) ; mbr = a ; write();cycles = cycles + 18;break;
case 0xcb: /** st %d(p3) **/
   fetch();eacIndex(p3) ; mbr = a ; write();cycles = cycles + 18;break;
case 0xcc: /** byte cc **/
   ;;break;
case 0xcd: /** st @%d(p1) **/
   fetch();p1 = eacAutoIndex(p1) ; mbr = a ; write();cycles = cycles + 18;break;
case 0xce: /** st @%d(p2) **/
   fetch();p2 = eacAutoIndex(p2) ; mbr = a ; write();cycles = cycles + 18;break;
case 0xcf: /** st @%d(p3) **/
   fetch();p3 = eacAutoIndex(p3) ; mbr = a ; write();cycles = cycles + 18;break;
case 0xd0: /** and %d(p0) **/
   fetch();eacIndex(p0) ; read() ; a = a & mbr;cycles = cycles + 18;break;
case 0xd1: /** and %d(p1) **/
   fetch();eacIndex(p1) ; read() ; a = a & mbr;cycles = cycles + 18;break;
case 0xd2: /** and %d(p2) **/
   fetch();eacIndex(p2) ; read() ; a = a & mbr;cycles = cycles + 18;break;
case 0xd3: /** and %d(p3) **/
   fetch();eacIndex(p3) ; read() ; a = a & mbr;cycles = cycles + 18;break;
case 0xd4: /** ani %c **/
   fetch() ; a = a & mbr;cycles = cycles + 10;break;
case 0xd5: /** and @%d(p1) **/
   fetch();p1 = eacAutoIndex(p1) ; read() ; a = a & mbr;cycles = cycles + 18;break;
case 0xd6: /** and @%d(p2) **/
   fetch();p2 = eacAutoIndex(p2) ; read() ; a = a & mbr;cycles = cycles + 18;break;
case 0xd7: /** and @%d(p3) **/
   fetch();p3 = eacAutoIndex(p3) ; read() ; a = a & mbr;cycles = cycles + 18;break;
case 0xd8: /** or %d(p0) **/
   fetch();eacIndex(p0) ; read() ; a = a | mbr;cycles = cycles + 18;break;
case 0xd9: /** or %d(p1) **/
   fetch();eacIndex(p1) ; read() ; a = a | mbr;cycles = cycles + 18;break;
case 0xda: /** or %d(p2) **/
   fetch();eacIndex(p2) ; read() ; a = a | mbr;cycles = cycles + 18;break;
case 0xdb: /** or %d(p3) **/
   fetch();eacIndex(p3) ; read() ; a = a | mbr;cycles = cycles + 18;break;
case 0xdc: /** ori %c **/
   fetch() ; a = a | mbr;cycles = cycles + 10;break;
case 0xdd: /** or @%d(p1) **/
   fetch();p1 = eacAutoIndex(p1) ; read() ; a = a & mbr;cycles = cycles + 18;break;
case 0xde: /** or @%d(p2) **/
   fetch();p2 = eacAutoIndex(p2) ; read() ; a = a & mbr;cycles = cycles + 18;break;
case 0xdf: /** or @%d(p3) **/
   fetch();p3 = eacAutoIndex(p3) ; read() ; a = a & mbr;cycles = cycles + 18;break;
case 0xe0: /** xor %d(p0) **/
   fetch();eacIndex(p0) ; read() ; a = a ^ mbr;cycles = cycles + 18;break;
case 0xe1: /** xor %d(p1) **/
   fetch();eacIndex(p1) ; read() ; a = a ^ mbr;cycles = cycles + 18;break;
case 0xe2: /** xor %d(p2) **/
   fetch();eacIndex(p2) ; read() ; a = a ^ mbr;cycles = cycles + 18;break;
case 0xe3: /** xor %d(p3) **/
   fetch();eacIndex(p3) ; read() ; a = a ^ mbr;cycles = cycles + 18;break;
case 0xe4: /** xri %c **/
   fetch() ; a = a ^ mbr;cycles = cycles + 10;break;
case 0xe5: /** xor @%d(p1) **/
   fetch();p1 = eacAutoIndex(p1) ; read() ; a = a & mbr;cycles = cycles + 18;break;
case 0xe6: /** xor @%d(p2) **/
   fetch();p2 = eacAutoIndex(p2) ; read() ; a = a & mbr;cycles = cycles + 18;break;
case 0xe7: /** xor @%d(p3) **/
   fetch();p3 = eacAutoIndex(p3) ; read() ; a = a & mbr;cycles = cycles + 18;break;
case 0xe8: /** dad %d(p0) **/
   fetch();eacIndex(p0) ; read() ; decimalAdd();cycles = cycles + 23;break;
case 0xe9: /** dad %d(p1) **/
   fetch();eacIndex(p1) ; read() ; decimalAdd();cycles = cycles + 23;break;
case 0xea: /** dad %d(p2) **/
   fetch();eacIndex(p2) ; read() ; decimalAdd();cycles = cycles + 23;break;
case 0xeb: /** dad %d(p3) **/
   fetch();eacIndex(p3) ; read() ; decimalAdd();cycles = cycles + 23;break;
case 0xec: /** dai %c **/
   fetch() ; decimalAdd();cycles = cycles + 15;break;
case 0xed: /** dad @%d(p1) **/
   fetch();p1 = eacAutoIndex(p1) ; read() ; decimalAdd();cycles = cycles + 23;break;
case 0xee: /** dad @%d(p2) **/
   fetch();p2 = eacAutoIndex(p2) ; read() ; decimalAdd();cycles = cycles + 23;break;
case 0xef: /** dad @%d(p3) **/
   fetch();p3 = eacAutoIndex(p3) ; read() ; decimalAdd();cycles = cycles + 23;break;
case 0xf0: /** add %d(p0) **/
   fetch();eacIndex(p0) ; read() ; binaryAdd();cycles = cycles + 19;break;
case 0xf1: /** add %d(p1) **/
   fetch();eacIndex(p1) ; read() ; binaryAdd();cycles = cycles + 19;break;
case 0xf2: /** add %d(p2) **/
   fetch();eacIndex(p2) ; read() ; binaryAdd();cycles = cycles + 19;break;
case 0xf3: /** add %d(p3) **/
   fetch();eacIndex(p3) ; read() ; binaryAdd();cycles = cycles + 19;break;
case 0xf4: /** adi %c **/
   fetch() ; binaryAdd();cycles = cycles + 11;break;
case 0xf5: /** add @%d(p1) **/
   fetch();p1 = eacAutoIndex(p1) ; read() ; binaryAdd();cycles = cycles + 19;break;
case 0xf6: /** add @%d(p2) **/
   fetch();p2 = eacAutoIndex(p2) ; read() ; binaryAdd();cycles = cycles + 19;break;
case 0xf7: /** add @%d(p3) **/
   fetch();p3 = eacAutoIndex(p3) ; read() ; binaryAdd();cycles = cycles + 19;break;
case 0xf8: /** cad %d(p0) **/
   fetch();eacIndex(p0) ; read() ; mbr = mbr ^ 0xFF ; binaryAdd();cycles = cycles + 20;break;
case 0xf9: /** cad %d(p1) **/
   fetch();eacIndex(p1) ; read() ; mbr = mbr ^ 0xFF ; binaryAdd();cycles = cycles + 20;break;
case 0xfa: /** cad %d(p2) **/
   fetch();eacIndex(p2) ; read() ; mbr = mbr ^ 0xFF ; binaryAdd();cycles = cycles + 20;break;
case 0xfb: /** cad %d(p3) **/
   fetch();eacIndex(p3) ; read() ; mbr = mbr ^ 0xFF ; binaryAdd();cycles = cycles + 20;break;
case 0xfc: /** cai %c **/
   fetch() ; mbr = mbr ^ 0xFF;binaryAdd();cycles = cycles + 12;break;
case 0xfd: /** cad @%d(p1) **/
   fetch();p1 = eacAutoIndex(p1) ; read() ; mbr = mbr ^ 0xFF ; binaryAdd();cycles = cycles + 20;break;
case 0xfe: /** cad @%d(p2) **/
   fetch();p2 = eacAutoIndex(p2) ; read() ; mbr = mbr ^ 0xFF ; binaryAdd();cycles = cycles + 20;break;
case 0xff: /** cad @%d(p3) **/
   fetch();p3 = eacAutoIndex(p3) ; read() ; mbr = mbr ^ 0xFF ; binaryAdd();cycles = cycles + 20;break;

abstract class SCMPGenerated extends SCMPBase {
private fetch() : void {
 this.p0 = (this.p0+1) & 0xFFFF;
 this.mar = this.p0;
 this.pcread();
}
private eacIndex(pp:number) : void {
 if (this.mbr == 0x80) this.mbr = this.e;
 this.t16 = ((this.mbr & 0x80) != 0) ? (this.mbr | 0xFF00) : this.mbr;
 this.mar = (pp & 0xF000) | ((pp+this.t16) & 0xFFF);
}
private eacBasicIndex(pp:number) : void {
 this.t16 = ((this.mbr & 0x80) != 0) ? (this.mbr | 0xFF00) : this.mbr;
 this.mar = (pp & 0xF000) | ((pp+this.t16) & 0xFFF);
}
private eacAutoIndex(pp:number) : number {
 if (this.mbr == 0x80) this.mbr = this.e;
 if ((this.mbr & 0x80) == 0) {
  this.mar = pp;
  this.t16 = (pp & 0xF000) | ((pp+this.mbr) & 0xFFF);
 } else {
  this.t16 = (pp & 0xF000) | ((pp+(this.mbr|0xFF00)) & 0xFFF);
  this.mar = this.t16;
 }
 return this.t16;
}
private decimalAdd() : void {
 this.t16 = (this.mbr & 0x0F) + (this.a & 0x0F) + this.cyl;
 if (this.t16 > 9) {
  this.t16 = this.t16 + 6;
 }
 this.t16 = this.t16 + (this.mbr & 0xF0) + (this.a & 0xF0);
 this.cyl = 0;
 if (this.t16 > 0x99) {
  this.cyl = 1;
  this.t16 = this.t16 + 0x60;
 }
 this.a = (this.t16 & 0xFF);
}
private binaryAdd() : void {
 this.t16 = this.a + this.mbr + this.cyl;
 this.overflow = 0;
 if (((this.a ^ this.mbr) & 0x80) == 0) {
  if (((this.a ^ this.t16) & 0x80) != 0) this.overflow = 1;
 }
 this.a = (this.t16 & 0xFF);
 this.cyl = (this.t16 >> 8) & 1;
}
private correctStatusRegister() : void {
 this.status = this.status & 0x0F;
 if (this.io_sensea()) this.status = this.status | 0x10;
 if (this.io_senseb()) this.status = this.status | 0x20;
 if (this.overflow != 0) this.status = this.status | 0x40;
 if (this.cyl != 0) this.status = this.status | 0x80;
}private opcode_00():void { ;;this.cycles = this.cycles + 8; };

private opcode_01():void { this.t16 = this.a;this.a = this.e;this.e = this.t16;this.cycles = this.cycles + 7; };

private opcode_02():void { this.cyl = 0;this.cycles = this.cycles + 5; };

private opcode_03():void { this.cyl = 1;this.cycles = this.cycles + 5; };

private opcode_04():void { this.status = this.status & 0xF7;this.cycles = this.cycles + 6; };

private opcode_05():void { this.status = this.status | 0x08;this.cycles = this.cycles + 6; };

private opcode_06():void { this.correctStatusRegister();this.a = this.status;this.cycles = this.cycles + 5; };

private opcode_07():void { this.status = this.a;this.io_flags(this.a & 7);this.cyl = (this.a>>7) & 1;this.overflow = (this.a>>6) & 1;this.correctStatusRegister();this.cycles = this.cycles + 6; };

private opcode_08():void { ;;this.cycles = this.cycles + 5; };

private opcode_09():void { ;; };

private opcode_0a():void { ;; };

private opcode_0b():void { ;; };

private opcode_0c():void { ;; };

private opcode_0d():void { ;; };

private opcode_0e():void { ;; };

private opcode_0f():void { ;; };

private opcode_10():void { ;; };

private opcode_11():void { ;; };

private opcode_12():void { ;; };

private opcode_13():void { ;; };

private opcode_14():void { ;; };

private opcode_15():void { ;; };

private opcode_16():void { ;; };

private opcode_17():void { ;; };

private opcode_18():void { ;; };

private opcode_19():void { this.io_sout(this.e & 1);this.e = this.e >> 1;if (this.io_sin() != 0) this.e |= 0x80;;this.cycles = this.cycles + 5; };

private opcode_1a():void { ;; };

private opcode_1b():void { ;; };

private opcode_1c():void { this.a = (this.a >> 1) & 0x7F;this.cycles = this.cycles + 5; };

private opcode_1d():void { this.a = ((this.a >> 1) & 0x7F) | (this.cyl << 7);this.cycles = this.cycles + 5; };

private opcode_1e():void { this.a = ((this.a >> 1) | (this.a << 7)) & 0xFF;this.cycles = this.cycles + 5; };

private opcode_1f():void { this.t16 = this.a | (this.cyl << 8);this.cyl = this.a & 1;this.a = (this.t16 >> 1) & 0xFF;this.cycles = this.cycles + 5; };

private opcode_20():void { ;; };

private opcode_21():void { ;; };

private opcode_22():void { ;; };

private opcode_23():void { ;; };

private opcode_24():void { ;; };

private opcode_25():void { ;; };

private opcode_26():void { ;; };

private opcode_27():void { ;; };

private opcode_28():void { ;; };

private opcode_29():void { ;; };

private opcode_2a():void { ;; };

private opcode_2b():void { ;; };

private opcode_2c():void { ;; };

private opcode_2d():void { ;; };

private opcode_2e():void { ;; };

private opcode_2f():void { ;; };

private opcode_30():void { this.t16 = this.p0;this.p0 = (this.p0 & 0xFF00) | this.a;this.a = this.t16 & 0xFF;this.cycles = this.cycles + 8; };

private opcode_31():void { this.t16 = this.p1;this.p1 = (this.p1 & 0xFF00) | this.a;this.a = this.t16 & 0xFF;this.cycles = this.cycles + 8; };

private opcode_32():void { this.t16 = this.p2;this.p2 = (this.p2 & 0xFF00) | this.a;this.a = this.t16 & 0xFF;this.cycles = this.cycles + 8; };

private opcode_33():void { this.t16 = this.p3;this.p3 = (this.p3 & 0xFF00) | this.a;this.a = this.t16 & 0xFF;this.cycles = this.cycles + 8; };

private opcode_34():void { this.t16 = this.p0;this.p0 = (this.p0 & 0x00FF) | (this.a << 8);this.a = (this.t16 >> 8) & 0xFF;this.cycles = this.cycles + 8; };

private opcode_35():void { this.t16 = this.p1;this.p1 = (this.p1 & 0x00FF) | (this.a << 8);this.a = (this.t16 >> 8) & 0xFF;this.cycles = this.cycles + 8; };

private opcode_36():void { this.t16 = this.p2;this.p2 = (this.p2 & 0x00FF) | (this.a << 8);this.a = (this.t16 >> 8) & 0xFF;this.cycles = this.cycles + 8; };

private opcode_37():void { this.t16 = this.p3;this.p3 = (this.p3 & 0x00FF) | (this.a << 8);this.a = (this.t16 >> 8) & 0xFF;this.cycles = this.cycles + 8; };

private opcode_38():void { ;; };

private opcode_39():void { ;; };

private opcode_3a():void { ;; };

private opcode_3b():void { ;; };

private opcode_3c():void { this.t16 = this.p0;this.p0 = this.p0;this.p0 = this.t16;this.cycles = this.cycles + 7; };

private opcode_3d():void { this.t16 = this.p0;this.p0 = this.p1;this.p1 = this.t16;this.cycles = this.cycles + 7; };

private opcode_3e():void { this.t16 = this.p0;this.p0 = this.p2;this.p2 = this.t16;this.cycles = this.cycles + 7; };

private opcode_3f():void { this.t16 = this.p0;this.p0 = this.p3;this.p3 = this.t16;this.cycles = this.cycles + 7; };

private opcode_40():void { this.a = this.e;this.cycles = this.cycles + 6; };

private opcode_41():void { ;; };

private opcode_42():void { ;; };

private opcode_43():void { ;; };

private opcode_44():void { ;; };

private opcode_45():void { ;; };

private opcode_46():void { ;; };

private opcode_47():void { ;; };

private opcode_48():void { ;; };

private opcode_49():void { ;; };

private opcode_4a():void { ;; };

private opcode_4b():void { ;; };

private opcode_4c():void { ;; };

private opcode_4d():void { ;; };

private opcode_4e():void { ;; };

private opcode_4f():void { ;; };

private opcode_50():void { this.a = this.a & this.e;this.cycles = this.cycles + 6; };

private opcode_51():void { ;; };

private opcode_52():void { ;; };

private opcode_53():void { ;; };

private opcode_54():void { ;; };

private opcode_55():void { ;; };

private opcode_56():void { ;; };

private opcode_57():void { ;; };

private opcode_58():void { this.a = this.a | this.e;this.cycles = this.cycles + 6; };

private opcode_59():void { ;; };

private opcode_5a():void { ;; };

private opcode_5b():void { ;; };

private opcode_5c():void { ;; };

private opcode_5d():void { ;; };

private opcode_5e():void { ;; };

private opcode_5f():void { ;; };

private opcode_60():void { this.a = this.a ^ this.e;this.cycles = this.cycles + 6; };

private opcode_61():void { ;; };

private opcode_62():void { ;; };

private opcode_63():void { ;; };

private opcode_64():void { ;; };

private opcode_65():void { ;; };

private opcode_66():void { ;; };

private opcode_67():void { ;; };

private opcode_68():void { this.mbr = this.e ; this.decimalAdd();this.cycles = this.cycles + 11; };

private opcode_69():void { ;; };

private opcode_6a():void { ;; };

private opcode_6b():void { ;; };

private opcode_6c():void { ;; };

private opcode_6d():void { ;; };

private opcode_6e():void { ;; };

private opcode_6f():void { ;; };

private opcode_70():void { this.mbr = this.e ; this.binaryAdd();this.cycles = this.cycles + 7; };

private opcode_71():void { ;; };

private opcode_72():void { ;; };

private opcode_73():void { ;; };

private opcode_74():void { ;; };

private opcode_75():void { ;; };

private opcode_76():void { ;; };

private opcode_77():void { ;; };

private opcode_78():void { this.mbr = this.e ^ 0xFF; this.binaryAdd();this.cycles = this.cycles + 8; };

private opcode_79():void { ;; };

private opcode_7a():void { ;; };

private opcode_7b():void { ;; };

private opcode_7c():void { ;; };

private opcode_7d():void { ;; };

private opcode_7e():void { ;; };

private opcode_7f():void { ;; };

private opcode_80():void { ;; };

private opcode_81():void { ;; };

private opcode_82():void { ;; };

private opcode_83():void { ;; };

private opcode_84():void { ;; };

private opcode_85():void { ;; };

private opcode_86():void { ;; };

private opcode_87():void { ;; };

private opcode_88():void { ;; };

private opcode_89():void { ;; };

private opcode_8a():void { ;; };

private opcode_8b():void { ;; };

private opcode_8c():void { ;; };

private opcode_8d():void { ;; };

private opcode_8e():void { ;; };

private opcode_8f():void { this.fetch();this.delaycyclesfour = (2 * this.a + (2 + 512)*this.mbr)/4;this.a = 0;this.cycles = this.cycles + 13; };

private opcode_90():void { this.fetch();this.eacBasicIndex(this.p0) ; this.p0 = this.mar;this.cycles = this.cycles + 11; };

private opcode_91():void { this.fetch();this.eacBasicIndex(this.p1) ; this.p0 = this.mar;this.cycles = this.cycles + 11; };

private opcode_92():void { this.fetch();this.eacBasicIndex(this.p2) ; this.p0 = this.mar;this.cycles = this.cycles + 11; };

private opcode_93():void { this.fetch();this.eacBasicIndex(this.p3) ; this.p0 = this.mar;this.cycles = this.cycles + 11; };

private opcode_94():void { this.fetch();this.eacBasicIndex(this.p0) ; if ((this.a & 0x80) == 0) this.p0 = this.mar;this.cycles = this.cycles + 10; };

private opcode_95():void { this.fetch();this.eacBasicIndex(this.p1) ; if ((this.a & 0x80) == 0) this.p0 = this.mar;this.cycles = this.cycles + 10; };

private opcode_96():void { this.fetch();this.eacBasicIndex(this.p2) ; if ((this.a & 0x80) == 0) this.p0 = this.mar;this.cycles = this.cycles + 10; };

private opcode_97():void { this.fetch();this.eacBasicIndex(this.p3) ; if ((this.a & 0x80) == 0) this.p0 = this.mar;this.cycles = this.cycles + 10; };

private opcode_98():void { this.fetch();this.eacBasicIndex(this.p0) ; if (this.a == 0) this.p0 = this.mar;this.cycles = this.cycles + 10; };

private opcode_99():void { this.fetch();this.eacBasicIndex(this.p1) ; if (this.a == 0) this.p0 = this.mar;this.cycles = this.cycles + 10; };

private opcode_9a():void { this.fetch();this.eacBasicIndex(this.p2) ; if (this.a == 0) this.p0 = this.mar;this.cycles = this.cycles + 10; };

private opcode_9b():void { this.fetch();this.eacBasicIndex(this.p3) ; if (this.a == 0) this.p0 = this.mar;this.cycles = this.cycles + 10; };

private opcode_9c():void { this.fetch();this.eacBasicIndex(this.p0) ; if (this.a != 0) this.p0 = this.mar;this.cycles = this.cycles + 10; };

private opcode_9d():void { this.fetch();this.eacBasicIndex(this.p1) ; if (this.a != 0) this.p0 = this.mar;this.cycles = this.cycles + 10; };

private opcode_9e():void { this.fetch();this.eacBasicIndex(this.p2) ; if (this.a != 0) this.p0 = this.mar;this.cycles = this.cycles + 10; };

private opcode_9f():void { this.fetch();this.eacBasicIndex(this.p3) ; if (this.a != 0) this.p0 = this.mar;this.cycles = this.cycles + 10; };

private opcode_a0():void { ;; };

private opcode_a1():void { ;; };

private opcode_a2():void { ;; };

private opcode_a3():void { ;; };

private opcode_a4():void { ;; };

private opcode_a5():void { ;; };

private opcode_a6():void { ;; };

private opcode_a7():void { ;; };

private opcode_a8():void { this.fetch(); this.eacBasicIndex(this.p0) ; this.read() ; this.mbr = (this.mbr + 1) & 0xFF; this.write() ; this.a = this.mbr;this.cycles = this.cycles + 22; };

private opcode_a9():void { this.fetch(); this.eacBasicIndex(this.p1) ; this.read() ; this.mbr = (this.mbr + 1) & 0xFF; this.write() ; this.a = this.mbr;this.cycles = this.cycles + 22; };

private opcode_aa():void { this.fetch(); this.eacBasicIndex(this.p2) ; this.read() ; this.mbr = (this.mbr + 1) & 0xFF; this.write() ; this.a = this.mbr;this.cycles = this.cycles + 22; };

private opcode_ab():void { this.fetch(); this.eacBasicIndex(this.p3) ; this.read() ; this.mbr = (this.mbr + 1) & 0xFF; this.write() ; this.a = this.mbr;this.cycles = this.cycles + 22; };

private opcode_ac():void { ;; };

private opcode_ad():void { ;; };

private opcode_ae():void { ;; };

private opcode_af():void { ;; };

private opcode_b0():void { ;; };

private opcode_b1():void { ;; };

private opcode_b2():void { ;; };

private opcode_b3():void { ;; };

private opcode_b4():void { ;; };

private opcode_b5():void { ;; };

private opcode_b6():void { ;; };

private opcode_b7():void { ;; };

private opcode_b8():void { this.fetch(); this.eacBasicIndex(this.p0) ; this.read() ; this.mbr = (this.mbr + 0xFF) & 0xFF; this.write() ; this.a = this.mbr;this.cycles = this.cycles + 22; };

private opcode_b9():void { this.fetch(); this.eacBasicIndex(this.p1) ; this.read() ; this.mbr = (this.mbr + 0xFF) & 0xFF; this.write() ; this.a = this.mbr;this.cycles = this.cycles + 22; };

private opcode_ba():void { this.fetch(); this.eacBasicIndex(this.p2) ; this.read() ; this.mbr = (this.mbr + 0xFF) & 0xFF; this.write() ; this.a = this.mbr;this.cycles = this.cycles + 22; };

private opcode_bb():void { this.fetch(); this.eacBasicIndex(this.p3) ; this.read() ; this.mbr = (this.mbr + 0xFF) & 0xFF; this.write() ; this.a = this.mbr;this.cycles = this.cycles + 22; };

private opcode_bc():void { ;; };

private opcode_bd():void { ;; };

private opcode_be():void { ;; };

private opcode_bf():void { ;; };

private opcode_c0():void { this.fetch();this.eacIndex(this.p0) ; this.read() ; this.a = this.mbr;this.cycles = this.cycles + 18; };

private opcode_c1():void { this.fetch();this.eacIndex(this.p1) ; this.read() ; this.a = this.mbr;this.cycles = this.cycles + 18; };

private opcode_c2():void { this.fetch();this.eacIndex(this.p2) ; this.read() ; this.a = this.mbr;this.cycles = this.cycles + 18; };

private opcode_c3():void { this.fetch();this.eacIndex(this.p3) ; this.read() ; this.a = this.mbr;this.cycles = this.cycles + 18; };

private opcode_c4():void { this.fetch() ; this.a = this.mbr;this.cycles = this.cycles + 10; };

private opcode_c5():void { this.fetch();this.p1 = this.eacAutoIndex(this.p1) ; this.read() ; this.a = this.mbr;this.cycles = this.cycles + 18; };

private opcode_c6():void { this.fetch();this.p2 = this.eacAutoIndex(this.p2) ; this.read() ; this.a = this.mbr;this.cycles = this.cycles + 18; };

private opcode_c7():void { this.fetch();this.p3 = this.eacAutoIndex(this.p3) ; this.read() ; this.a = this.mbr;this.cycles = this.cycles + 18; };

private opcode_c8():void { this.fetch();this.eacIndex(this.p0) ; this.mbr = this.a ; this.write();this.cycles = this.cycles + 18; };

private opcode_c9():void { this.fetch();this.eacIndex(this.p1) ; this.mbr = this.a ; this.write();this.cycles = this.cycles + 18; };

private opcode_ca():void { this.fetch();this.eacIndex(this.p2) ; this.mbr = this.a ; this.write();this.cycles = this.cycles + 18; };

private opcode_cb():void { this.fetch();this.eacIndex(this.p3) ; this.mbr = this.a ; this.write();this.cycles = this.cycles + 18; };

private opcode_cc():void { ;; };

private opcode_cd():void { this.fetch();this.p1 = this.eacAutoIndex(this.p1) ; this.mbr = this.a ; this.write();this.cycles = this.cycles + 18; };

private opcode_ce():void { this.fetch();this.p2 = this.eacAutoIndex(this.p2) ; this.mbr = this.a ; this.write();this.cycles = this.cycles + 18; };

private opcode_cf():void { this.fetch();this.p3 = this.eacAutoIndex(this.p3) ; this.mbr = this.a ; this.write();this.cycles = this.cycles + 18; };

private opcode_d0():void { this.fetch();this.eacIndex(this.p0) ; this.read() ; this.a = this.a & this.mbr;this.cycles = this.cycles + 18; };

private opcode_d1():void { this.fetch();this.eacIndex(this.p1) ; this.read() ; this.a = this.a & this.mbr;this.cycles = this.cycles + 18; };

private opcode_d2():void { this.fetch();this.eacIndex(this.p2) ; this.read() ; this.a = this.a & this.mbr;this.cycles = this.cycles + 18; };

private opcode_d3():void { this.fetch();this.eacIndex(this.p3) ; this.read() ; this.a = this.a & this.mbr;this.cycles = this.cycles + 18; };

private opcode_d4():void { this.fetch() ; this.a = this.a & this.mbr;this.cycles = this.cycles + 10; };

private opcode_d5():void { this.fetch();this.p1 = this.eacAutoIndex(this.p1) ; this.read() ; this.a = this.a & this.mbr;this.cycles = this.cycles + 18; };

private opcode_d6():void { this.fetch();this.p2 = this.eacAutoIndex(this.p2) ; this.read() ; this.a = this.a & this.mbr;this.cycles = this.cycles + 18; };

private opcode_d7():void { this.fetch();this.p3 = this.eacAutoIndex(this.p3) ; this.read() ; this.a = this.a & this.mbr;this.cycles = this.cycles + 18; };

private opcode_d8():void { this.fetch();this.eacIndex(this.p0) ; this.read() ; this.a = this.a | this.mbr;this.cycles = this.cycles + 18; };

private opcode_d9():void { this.fetch();this.eacIndex(this.p1) ; this.read() ; this.a = this.a | this.mbr;this.cycles = this.cycles + 18; };

private opcode_da():void { this.fetch();this.eacIndex(this.p2) ; this.read() ; this.a = this.a | this.mbr;this.cycles = this.cycles + 18; };

private opcode_db():void { this.fetch();this.eacIndex(this.p3) ; this.read() ; this.a = this.a | this.mbr;this.cycles = this.cycles + 18; };

private opcode_dc():void { this.fetch() ; this.a = this.a | this.mbr;this.cycles = this.cycles + 10; };

private opcode_dd():void { this.fetch();this.p1 = this.eacAutoIndex(this.p1) ; this.read() ; this.a = this.a & this.mbr;this.cycles = this.cycles + 18; };

private opcode_de():void { this.fetch();this.p2 = this.eacAutoIndex(this.p2) ; this.read() ; this.a = this.a & this.mbr;this.cycles = this.cycles + 18; };

private opcode_df():void { this.fetch();this.p3 = this.eacAutoIndex(this.p3) ; this.read() ; this.a = this.a & this.mbr;this.cycles = this.cycles + 18; };

private opcode_e0():void { this.fetch();this.eacIndex(this.p0) ; this.read() ; this.a = this.a ^ this.mbr;this.cycles = this.cycles + 18; };

private opcode_e1():void { this.fetch();this.eacIndex(this.p1) ; this.read() ; this.a = this.a ^ this.mbr;this.cycles = this.cycles + 18; };

private opcode_e2():void { this.fetch();this.eacIndex(this.p2) ; this.read() ; this.a = this.a ^ this.mbr;this.cycles = this.cycles + 18; };

private opcode_e3():void { this.fetch();this.eacIndex(this.p3) ; this.read() ; this.a = this.a ^ this.mbr;this.cycles = this.cycles + 18; };

private opcode_e4():void { this.fetch() ; this.a = this.a ^ this.mbr;this.cycles = this.cycles + 10; };

private opcode_e5():void { this.fetch();this.p1 = this.eacAutoIndex(this.p1) ; this.read() ; this.a = this.a & this.mbr;this.cycles = this.cycles + 18; };

private opcode_e6():void { this.fetch();this.p2 = this.eacAutoIndex(this.p2) ; this.read() ; this.a = this.a & this.mbr;this.cycles = this.cycles + 18; };

private opcode_e7():void { this.fetch();this.p3 = this.eacAutoIndex(this.p3) ; this.read() ; this.a = this.a & this.mbr;this.cycles = this.cycles + 18; };

private opcode_e8():void { this.fetch();this.eacIndex(this.p0) ; this.read() ; this.decimalAdd();this.cycles = this.cycles + 23; };

private opcode_e9():void { this.fetch();this.eacIndex(this.p1) ; this.read() ; this.decimalAdd();this.cycles = this.cycles + 23; };

private opcode_ea():void { this.fetch();this.eacIndex(this.p2) ; this.read() ; this.decimalAdd();this.cycles = this.cycles + 23; };

private opcode_eb():void { this.fetch();this.eacIndex(this.p3) ; this.read() ; this.decimalAdd();this.cycles = this.cycles + 23; };

private opcode_ec():void { this.fetch() ; this.decimalAdd();this.cycles = this.cycles + 15; };

private opcode_ed():void { this.fetch();this.p1 = this.eacAutoIndex(this.p1) ; this.read() ; this.decimalAdd();this.cycles = this.cycles + 23; };

private opcode_ee():void { this.fetch();this.p2 = this.eacAutoIndex(this.p2) ; this.read() ; this.decimalAdd();this.cycles = this.cycles + 23; };

private opcode_ef():void { this.fetch();this.p3 = this.eacAutoIndex(this.p3) ; this.read() ; this.decimalAdd();this.cycles = this.cycles + 23; };

private opcode_f0():void { this.fetch();this.eacIndex(this.p0) ; this.read() ; this.binaryAdd();this.cycles = this.cycles + 19; };

private opcode_f1():void { this.fetch();this.eacIndex(this.p1) ; this.read() ; this.binaryAdd();this.cycles = this.cycles + 19; };

private opcode_f2():void { this.fetch();this.eacIndex(this.p2) ; this.read() ; this.binaryAdd();this.cycles = this.cycles + 19; };

private opcode_f3():void { this.fetch();this.eacIndex(this.p3) ; this.read() ; this.binaryAdd();this.cycles = this.cycles + 19; };

private opcode_f4():void { this.fetch() ; this.binaryAdd();this.cycles = this.cycles + 11; };

private opcode_f5():void { this.fetch();this.p1 = this.eacAutoIndex(this.p1) ; this.read() ; this.binaryAdd();this.cycles = this.cycles + 19; };

private opcode_f6():void { this.fetch();this.p2 = this.eacAutoIndex(this.p2) ; this.read() ; this.binaryAdd();this.cycles = this.cycles + 19; };

private opcode_f7():void { this.fetch();this.p3 = this.eacAutoIndex(this.p3) ; this.read() ; this.binaryAdd();this.cycles = this.cycles + 19; };

private opcode_f8():void { this.fetch();this.eacIndex(this.p0) ; this.read() ; this.mbr = this.mbr ^ 0xFF ; this.binaryAdd();this.cycles = this.cycles + 20; };

private opcode_f9():void { this.fetch();this.eacIndex(this.p1) ; this.read() ; this.mbr = this.mbr ^ 0xFF ; this.binaryAdd();this.cycles = this.cycles + 20; };

private opcode_fa():void { this.fetch();this.eacIndex(this.p2) ; this.read() ; this.mbr = this.mbr ^ 0xFF ; this.binaryAdd();this.cycles = this.cycles + 20; };

private opcode_fb():void { this.fetch();this.eacIndex(this.p3) ; this.read() ; this.mbr = this.mbr ^ 0xFF ; this.binaryAdd();this.cycles = this.cycles + 20; };

private opcode_fc():void { this.fetch() ; this.mbr = this.mbr ^ 0xFF;this.binaryAdd();this.cycles = this.cycles + 12; };

private opcode_fd():void { this.fetch();this.p1 = this.eacAutoIndex(this.p1) ; this.read() ; this.mbr = this.mbr ^ 0xFF ; this.binaryAdd();this.cycles = this.cycles + 20; };

private opcode_fe():void { this.fetch();this.p2 = this.eacAutoIndex(this.p2) ; this.read() ; this.mbr = this.mbr ^ 0xFF ; this.binaryAdd();this.cycles = this.cycles + 20; };

private opcode_ff():void { this.fetch();this.p3 = this.eacAutoIndex(this.p3) ; this.read() ; this.mbr = this.mbr ^ 0xFF ; this.binaryAdd();this.cycles = this.cycles + 20; };

protected getOpcodeList():Function() {
 return [opcode_00,opcode_01,opcode_02,opcode_03,opcode_04,opcode_05,opcode_06,opcode_07,opcode_08,opcode_09,opcode_0a,opcode_0b,opcode_0c,opcode_0d,opcode_0e,opcode_0f,opcode_10,opcode_11,opcode_12,opcode_13,opcode_14,opcode_15,opcode_16,opcode_17,opcode_18,opcode_19,opcode_1a,opcode_1b,opcode_1c,opcode_1d,opcode_1e,opcode_1f,opcode_20,opcode_21,opcode_22,opcode_23,opcode_24,opcode_25,opcode_26,opcode_27,opcode_28,opcode_29,opcode_2a,opcode_2b,opcode_2c,opcode_2d,opcode_2e,opcode_2f,opcode_30,opcode_31,opcode_32,opcode_33,opcode_34,opcode_35,opcode_36,opcode_37,opcode_38,opcode_39,opcode_3a,opcode_3b,opcode_3c,opcode_3d,opcode_3e,opcode_3f,opcode_40,opcode_41,opcode_42,opcode_43,opcode_44,opcode_45,opcode_46,opcode_47,opcode_48,opcode_49,opcode_4a,opcode_4b,opcode_4c,opcode_4d,opcode_4e,opcode_4f,opcode_50,opcode_51,opcode_52,opcode_53,opcode_54,opcode_55,opcode_56,opcode_57,opcode_58,opcode_59,opcode_5a,opcode_5b,opcode_5c,opcode_5d,opcode_5e,opcode_5f,opcode_60,opcode_61,opcode_62,opcode_63,opcode_64,opcode_65,opcode_66,opcode_67,opcode_68,opcode_69,opcode_6a,opcode_6b,opcode_6c,opcode_6d,opcode_6e,opcode_6f,opcode_70,opcode_71,opcode_72,opcode_73,opcode_74,opcode_75,opcode_76,opcode_77,opcode_78,opcode_79,opcode_7a,opcode_7b,opcode_7c,opcode_7d,opcode_7e,opcode_7f,opcode_80,opcode_81,opcode_82,opcode_83,opcode_84,opcode_85,opcode_86,opcode_87,opcode_88,opcode_89,opcode_8a,opcode_8b,opcode_8c,opcode_8d,opcode_8e,opcode_8f,opcode_90,opcode_91,opcode_92,opcode_93,opcode_94,opcode_95,opcode_96,opcode_97,opcode_98,opcode_99,opcode_9a,opcode_9b,opcode_9c,opcode_9d,opcode_9e,opcode_9f,opcode_a0,opcode_a1,opcode_a2,opcode_a3,opcode_a4,opcode_a5,opcode_a6,opcode_a7,opcode_a8,opcode_a9,opcode_aa,opcode_ab,opcode_ac,opcode_ad,opcode_ae,opcode_af,opcode_b0,opcode_b1,opcode_b2,opcode_b3,opcode_b4,opcode_b5,opcode_b6,opcode_b7,opcode_b8,opcode_b9,opcode_ba,opcode_bb,opcode_bc,opcode_bd,opcode_be,opcode_bf,opcode_c0,opcode_c1,opcode_c2,opcode_c3,opcode_c4,opcode_c5,opcode_c6,opcode_c7,opcode_c8,opcode_c9,opcode_ca,opcode_cb,opcode_cc,opcode_cd,opcode_ce,opcode_cf,opcode_d0,opcode_d1,opcode_d2,opcode_d3,opcode_d4,opcode_d5,opcode_d6,opcode_d7,opcode_d8,opcode_d9,opcode_da,opcode_db,opcode_dc,opcode_dd,opcode_de,opcode_df,opcode_e0,opcode_e1,opcode_e2,opcode_e3,opcode_e4,opcode_e5,opcode_e6,opcode_e7,opcode_e8,opcode_e9,opcode_ea,opcode_eb,opcode_ec,opcode_ed,opcode_ee,opcode_ef,opcode_f0,opcode_f1,opcode_f2,opcode_f3,opcode_f4,opcode_f5,opcode_f6,opcode_f7,opcode_f8,opcode_f9,opcode_fa,opcode_fb,opcode_fc,opcode_fd,opcode_fe,opcode_ff];
}

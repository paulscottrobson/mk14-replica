#
#	SC/MP Generation
#
import re
#
#	Read and preprocess.
#
src = [x.replace("\t"," ") for x in open("scmp.def").readlines()]
src = [x if x.find("//") < 0 else x[:x.find("//")] for x in src]
src = [x.strip() for x in src if x.strip() != ""]
#
#	Rip out functions 
#
functions = "\n".join([x[1:] for x in src if x[0] == ':'])
src = [x for x in src if x[0] != ':']
#
#	Get code and mnemonics for every opcode
#
code = [ None ] * 256
mnemonics = [ None ] * 256
for l in src:
	m = re.match("^([0-9A-F\-]+)\s*(\d+)\s*\"(.*?)\"\s*(.*)$",l)
	assert m is not None,"Bad line "+l
	opRange = [ int(m.group(1),16)] if len(m.group(1)) == 2 else [x for x in range(int(m.group(1)[:2],16),int(m.group(1)[-2:],16)+1)]
	for opc in opRange:
		mnemonic = m.group(3).replace("%p",str(opc % 4))
		assert mnemonics[opc] is None,"Duplicate "+l
		mnemonics[opc] = mnemonic
		code[opc] = m.group(4).replace("%p",str(opc % 4))+";$cycles = $cycles + "+m.group(2)
#
#	Fill in the unused
#
for i in range(0,256):
	if mnemonics[i] is None:
		mnemonics[i] = "byte {0:02x}".format(i)
		code[i] = ";"
#
#	Generate mnemonics
#
open("_scmp_mnemonics.h","w").write("{ "+",".join(['"'+x+'"' for x in mnemonics]) + "};")
#
#	Generate case include
#
h = open("_scmp_case.h","w")
for i in range(0,256):
	h.write("case 0x{0:02x}: /** {1} **/\n".format(i,mnemonics[i]))
	xcode = code[i].replace("$","")+";break;"
	h.write("   "+xcode+"\n")
h.close()
#
#	Generate support include
#
h = open("_scmp_support.h","w")
xcode = functions.replace("rfunction","static WORD16").replace("function","static void").replace("%%pp","WORD16 pp").replace("$","")
h.write(xcode)
h.close()
#
#	Generate SC/MP Class
#
h = open("_scmp_class.ts","w")
h.write("abstract class SCMPGenerated extends SCMPBase {\n")
#
#	Support functions
#
xcode = functions.replace("%%pp","pp:number").replace("$","this.").replace("inline","").split("\n")
for i in range(0,len(xcode)):
	if xcode[i][:8] == "function":
		xcode[i] = "private "+xcode[i][8:-1].strip()+" : void {"
	if xcode[i][:9] == "rfunction":
		xcode[i] = "private "+xcode[i][9:-1].strip()+" : number {"
h.write("\n".join(xcode))
#
#	Each opcode functions
#
for i in range(0,256):
	xcode = code[i].replace("$","this.")+";"
	h.write(("private opcode_{0:02x}():void {{ "+xcode+" }};\n").format(i))
	h.write("\n")
#
#	Get list of methods for each opcode.
#	
h.write("protected getOpcodeList():Function() {\n return [")
h.write(",".join(["opcode_{0:02x}".format(x) for x in range(0,256)]))
h.write("];\n}\n")
h.close()

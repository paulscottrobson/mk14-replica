make
asl -L test.asm
p2bin test.p test.bin
./ecs8008 test.bin

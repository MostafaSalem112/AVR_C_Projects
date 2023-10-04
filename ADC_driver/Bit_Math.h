#define GetBit(reg,bitNum) (reg>>bitNum)&1
#define SetBit(reg,bitNum) reg|=(1<<bitNum)
#define ClrBit(reg,bitNum) reg&=((~0)^(1<<bitNum))
#define TogBit(reg,bitNum) reg^=(1<<bitNum)

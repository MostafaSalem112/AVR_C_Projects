#define GetBit(num,bitNum) (num>>bitNum)&1
#define SetBit(num,bitNum) num|(1<<bitNum)
#define ClrBit(num,bitNum) num&((~0)^(1<<bitNum))
#define TogBit(num,bitNum) num^(1<<bitNum)
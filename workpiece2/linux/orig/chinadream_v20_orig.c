#include <stdio.h>
#include <unistd.h> 
long mapbits[24] = {1536,3968,4032,103079231486,1090921709566,
    4380866642940,8791798071292,562947805970416,281473903493056,
    281474976708992,140737488351232,70368744177408,70368744176640,
    140737488354816,17592186044160,8796093021952,2199023255424,
    61203283712,268435200,2147483232,536869056,409960448,131072,983040};
long wordbits[14] = {54060787697827936,54060787701905406,54056389722505214,
    9223317061189755128,8124999554716136430,6972078058702216807,6972079097815085152,
    8124999557936349176,9223314915719249916,6972078059504529520,54058588608274144,
    54056389718314880,54060787697778176,54060787697973248};
char *first = "\n\nMy name is Zhang Ge. I am in :\n\n";
char *second = "\n\nI have a :\n\n";
printMap(long bits[],int cols,int rows,long mac)
{
    int i,j;
    for(i=0; i<rows; i++,putchar('\n'),sleep(1))
	for(j=0; j<cols; j++,bits[i]<<=1)
	    (bits[i]&mac)!=0?((i*j+j)%10)>4?putchar('1'):putchar('0'):putchar(' ');
}
int recur_put(char *pstr)
{
    return putchar(*pstr) != '\0'?recur_put(++pstr):sleep(1);
}
main()
{
    long mac = 1L;
    recur_put(first);
    printMap(mapbits, 48, 24, mac << 48);
    recur_put(second);
    printMap(wordbits, 64, 14, mac << 63);
}

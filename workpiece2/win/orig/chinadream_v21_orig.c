#include <stdio.h>
#include <windows.h>
//��һ��ͼΪ24x48��С��һ��ʹ��һ��longֵ��64λ���� 
long long mapbits[24] = {1536LL,3968LL,4032LL,103079231486LL,1090921709566LL,
    4380866642940LL,8791798071292LL,562947805970416LL,281473903493056LL,
    281474976708992LL,140737488351232LL,70368744177408LL,70368744176640LL,
    140737488354816LL,17592186044160LL,8796093021952LL,2199023255424LL,
    61203283712LL,268435200LL,2147483232LL,536869056LL,409960448LL,131072LL,983040LL};
//�ڶ���ͼΪ14x64��С�����longֵ��λΪ1�����ӡ�ַ��������ӡ�հ� 
long long wordbits[14] = {54060787697827936LL,54060787701905406LL,54056389722505214LL,
    9223317061189755128LL,8124999554716136430LL,6972078058702216807LL,6972079097815085152LL,
    8124999557936349176LL,9223314915719249916LL,6972078059504529520LL,54058588608274144LL,
    54056389718314880LL,54060787697778176LL,54060787697973248LL};
char *first = "\n\nMy name is Zhang Ge. I am in :\n\n";
char *second = "\n\nI have a :\n\n";
//��ӡͼƬ���� 
printMap(long long bits[],int cols,int rows,long long mac)
{
    int i,j;
    for(i=0; i<rows; i++,putchar('\n'),Sleep(1000))
	for(j=0; j<cols; j++,bits[i]<<=1)
	    (bits[i]&mac)!=0?((i*j+j)%10)>4?putchar('1'):putchar('0'):putchar(' ');
}
//�ݹ��ӡ�ַ���������ʹ��putchar����printf 
void recur_put(char *pstr)
{
	(*pstr)!='\0'?putchar(*pstr),recur_put(++pstr):Sleep(1000);
}
main()
{
    long long mac = 1L;
    recur_put(first);
    printMap(mapbits, 48, 24, mac << 48);
    recur_put(second);
    printMap(wordbits, 64, 14, mac << 63);
}

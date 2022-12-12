#include <stdio.h>
int main(){
	while(1){
	int ascii = getch();
//	NUL 0 ETX 3 EOT 4 BSP 8 HT 9 LF 10 FF 12 CR 13 EOF 26 ESC 27
	if(ascii>=0&&ascii<=127) {
	switch(ascii) {
	case 0: printf("NUL\n"); break;
	case 3: printf("ETX\n"); break;
	case 4: printf("EOT\n"); break;
	case 8: printf("BSP\n"); break;
	case 9: printf("HT\n"); break;
	case 10: printf("LF\n"); break;
	case 12: printf("FF\n"); break;
	case 13: printf("CR\n"); break;
	case 26: printf("EOF\n"); break;
	case 27: printf("ESC\n"); break;
	default: printf("char: %c   dec: %d   hex: 0x%x\n", ascii, ascii, ascii); break;
	}//switch(ascii)
	}//if(ascii>=0&&ascii<=127)
	}//while(1)
	return 0;
}//main

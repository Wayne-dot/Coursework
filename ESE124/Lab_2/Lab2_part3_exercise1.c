// Wayne Ting SBU ID: 115334926

#include <stdio.h>

int main(){

    unsigned char a;
    char oper;
    unsigned char mask;
    unsigned char display;
	
	int p, n;
	
	// on my local computer, %hhx does not work for me, but it works for online C compiler
	printf("input a hexadecimal input: ");
	scanf(" %hhx", &a);
	
	printf("Enter p and n(p,n): ");
	scanf(" %d, %d", &p, &n);


    // assuming the diagram Input->Output1->Output2-> Output3->.. is looking for infinite loop
    while (1)
    {
        printf("Please enter an operation 'S', 'R', 'F', 'D', 'I': ");
        scanf(" %c", &oper);

        if(oper == 'S'){
            // sets the n bits starting at position p to 11..1
            // let a = 0001 1111, p = 5, n = 2
            // 00(01) 1111
            // mask = 0011 1111
            // a or mask
            // Final output: 0011 1111 = 0x3f
            mask = 0xff;
            mask = mask >> 8-n;
            mask = mask << p-n+1;
            display = a | mask;
            printf("Output: %x\n", display);
        }

        else if (oper == 'R'){
            // resets the n bits starting at position p to 00…0
            // let a = 0001 1111, p = 5, n = 2
            // 00(01) 1111
            // mask  = 1100 1111
            // a & mask
            // Final output: 0000 1111

            // process of making the mask 1100 1111
            // 1111 1111
            // 1100 0000
            // 0011 0000
            // 1100 1111
            mask = 0xff;
            mask = mask >> 8-n;
            mask = ~(mask << p-n+1);

            printf("%x", mask);
            display = a & mask;
            printf("Output: %x\n", display);
        }

        else if(oper == 'F'){
            // change this
            // flips the n bits starting at position p to their inverse bit
            // let a = 0001 1111, p = 5, n = 2
            // maks = 11(11) 1111
            // mask = 0000 11(11)
            // maks = (11)00 0000
            // mask = 00(11) 0000
            // a XOR 0011 0000
            // Final output: 00(10) 1111
            mask = 0xff;
            mask = mask >> 8-n;
            mask = mask << p-n+1;
            display = a ^ mask;

            printf("Output: %x\n", display);
        }

        

        else if(oper == 'D'){
            // displays the value of the variable
            printf("Value of the input is %x\n", a);
        }

        else if(oper == 'I'){
            // reads a new hexadecimal value from the keyboard
            printf("Enter a new Hexadecimal input: ");
            scanf("%x", a);
        }
    }
    
    return 0;
}
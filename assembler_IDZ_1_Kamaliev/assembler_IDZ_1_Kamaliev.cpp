#include <string>

#include <iostream>
using namespace std;
int main()
{
    const int bufSize = 100;
    char str[bufSize];
    char max = '1';
    char min = '1';
    char format[] = "%s";
    int len = 0;

    __asm
    {
        mov eax, bufSize
        push eax
        lea eax, str
        push eax
        call gets_s
        add esp, 8

        lea eax, str
        push eax
        lea eax, format
        push eax
        call printf_s
        add esp, 8

        lea esi, str
        cld

        mov al, [esi]
        mov dh, [esi]//min
        mov dl, [esi]//max
        CYCLE :
        lodsb
            test al, al
            jz ex
            cmp al, dh
            jnb m1
            mov dh, al
            m1 :
        cmp al, dl
            jna m2
            mov dl, al
            m2 :
        jmp CYCLE
            ex :
        mov max, dl
            mov min, dh

    }
    cout << endl << min << max;

}


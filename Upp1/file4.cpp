#include <windows.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	HMODULE hModule = NULL;
	int (*pfnFile1_Funkce1)(int, int) = NULL;
	int (__stdcall *pfnFile1_Funkce2)(int,int) = NULL;
	int (*pfnFile2_Funkce1)(int, int) = NULL;
	int (__stdcall *pfnFile2_Funkce2)(int,int) = NULL;

	hModule = LoadLibrary( TEXT("library.dll") );
	if( hModule )
	{
		pfnFile1_Funkce1 = (int (*)(int,int))GetProcAddress( hModule, "File1_Funkce1" );

		if( pfnFile1_Funkce1 )
		{
			printf("Soucet: %d.\n", pfnFile1_Funkce1(1,2) );
		}
		else
		{
			printf("File1_Funkce1: Nenalezena. Chyba %d.\n", GetLastError());
		}		

		pfnFile1_Funkce2 = (int (__stdcall*)(int,int))GetProcAddress( hModule, "_File1_Funkce2@8" );

		if( pfnFile1_Funkce2 )
		{
			printf("Soucet: %d.\n", pfnFile1_Funkce2(1,2) );
		}
		else
		{
			printf("File1_Funkce2: Nenalezena. Chyba %d.\n", GetLastError());
		}	
		
		//FILE2
		pfnFile2_Funkce1 = (int (*)(int,int))GetProcAddress( hModule, "?File2_Funkce1@@YAHHH@Z" );

		if( pfnFile2_Funkce1 )
		{
			printf("Soucet: %d.\n", pfnFile2_Funkce1(1,2) );
		}
		else
		{
			printf("File2_Funkce1: Nenalezena. Chyba %d.\n", GetLastError());
		}		

		pfnFile2_Funkce2 = (int (__stdcall*)(int,int))GetProcAddress( hModule, "?File2_Funkce2@@YGHHH@Z" );

		if( pfnFile2_Funkce2 )
		{
			printf("Soucet: %d.\n", pfnFile2_Funkce2(1,2) );
		}
		else
		{
			printf("File2_Funkce2: Nenalezena. Chyba %d.\n", GetLastError());
		}
		
		FreeLibrary( hModule );
		hModule = NULL;
	}

	return 0;
}

#include <stdio.h>
#include <windows.h>
//#include <conio.h>

LRESULT CALLBACK hookproc(_In_ int, _In_ WPARAM, _In_ LPARAM);

int main(){
	
	//set hook
	HHOOK hHook = SetWindowsHookEx(
		WH_KEYBOARD_LL,
		hookproc,
		GetModuleHandleA(NULL),
		NULL
	);
	
	//loop with MSG msg
	MSG msg;
	while(1){
		
		if(PeekMessageA(&msg, NULL, NULL, NULL, PM_REMOVE)){		
		
			TranslateMessage(&msg);
		
			DispatchMessageW(&msg);
		}
		else 
			Sleep(0);
			
	}
	
	UnhookWindowsHookEx(hHook);
	
	return 0;
} 

LRESULT CALLBACK hookproc(_In_ int nCode, _In_ WPARAM wParam, _In_ LPARAM lParam){
	
	//Do something
	KBDLLHOOKSTRUCT *kbhs = (KBDLLHOOKSTRUCT*)lParam;
	
	if(kbhs->flags==128 || kbhs->flags==129){
		switch(kbhs->vkCode){
			case 0x30:
			case 0x31:
				printf("0\n");
				break;
			//...
			//... 
		}
			
	}

	return CallNextHookEx(NULL, nCode, wParam, lParam);
}


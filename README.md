# DDK_global_keyboard_hook
* It is a implement of global keyboard hook.

# Structure
```C++
HHOOK SetWindowsHookExA(
  int       idHook,
  HOOKPROC  lpfn,
  HINSTANCE hmod,
  DWORD     dwThreadId
);
```

# Example

```C++
static HHOOK keyboardHook = NULL;
keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, GetModuleHandle(NULL), 0);

//WH_KEYBOARD_LL
/*
LRESULT CALLBACK LowLevelKeyboardProc(
  _In_ int    nCode,
  _In_ WPARAM wParam,
  _In_ LPARAM lParam
);
*/
//LowLevelKeyboardProc
//GetModuleHandle(NULL)
//0
```
# Let's get started
```C
#include <stdio.h>
#include <windows.h>

int main(){
	//set hook
	
	//loop with MSG msg
	
	//Remove hook
	
	return 0;
} 
```

```C
#include <stdio.h>
#include <windows.h>

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
	
	//Remove hook
	
	return 0;
} 

LRESULT CALLBACK hookproc(_In_ int nCode, _In_ WPARAM wParam, _In_ LPARAM lParam){
	
	//Do something
	
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}
```

```C
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
```

```C	
	//Remove hook
	UnhookWindowsHookEx(hHook);
```

```C
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
```


# References
* https://docs.microsoft.com/en-us/windows/win32/api/_inputdev/
* https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowshookexa


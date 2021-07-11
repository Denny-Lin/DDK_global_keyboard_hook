# DDK_global_keyboard_hook
* It is a implement of global keyboard hook.
* I made this tool before.
* I think I will upload it.

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
#include<windows.h>
#include <conio.h>

int main(){
	//set hook
	
	//loop with MSG msg
	
	return 0;
} 
```

# References
* https://docs.microsoft.com/en-us/windows/win32/api/_inputdev/
* https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowshookexa


# DDK_global_keyboard_hook
* It is a implement of global keyboard hook.
* I made this tool before.
* I think I will upload it.

# Structure
```C++
SetWindowsHookExA(
    _In_ int idHook,
    _In_ HOOKPROC lpfn,
    _In_opt_ HINSTANCE hmod,
    _In_ DWORD dwThreadId);
```

# References
* https://docs.microsoft.com/en-us/windows/win32/api/_inputdev/
* https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowshookexa


#include "framework.h"
#include <stdio.h>
#include "resource2.h"

static HINSTANCE hInstance;
static HWND hWindow;

static INT_PTR CALLBACK FirstDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDNEXT:
            EndDialog(hDlg, 2);
            return (INT_PTR)TRUE;
        case IDCANCEL:
            EndDialog(hDlg, 0);
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

int Func_MOD2(HINSTANCE hInst, HWND hWnd) {
    hInstance = hInst;
    hWindow = hWnd;
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_FIRST_DIALOG), hWindow, FirstDialog);
}
#include "framework.h"
#include <stdio.h>
#include "resource3.h"

static HINSTANCE hInstance;
static HWND hWindow;

static INT_PTR CALLBACK SecondDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

static INT_PTR CALLBACK SecondDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDC_BUTTON_OK:
            EndDialog(hDlg, 1);
            return (INT_PTR)TRUE;
        case IDBACK:
            EndDialog(hDlg, 3);
            return (INT_PTR)TRUE;
        case IDCANCEL:
            EndDialog(hDlg, 0);
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

int Func_MOD3(HINSTANCE hInst, HWND hWnd) {
    hInstance = hInst;
    hWindow = hWnd;
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_SECOND_DIALOG), hWindow, SecondDialog);
}
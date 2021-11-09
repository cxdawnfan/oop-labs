#include "framework.h"
#include "resource1.h"
#include <stdio.h>

static HWND hScroll;
static int scrollPos;
static int minScrollPos = 1;
static int maxScrollPos = 100;

static void HandleLineLeft(HWND hDlg);
static void HandleLineRight(HWND hDlg);
static void HandleThumbTrack(HWND hDlg, WPARAM wParam);

static INT_PTR CALLBACK Work1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        hScroll = GetDlgItem(hDlg, IDC_SCROLLBAR2);
        scrollPos = minScrollPos;

        SetScrollRange(hScroll, SB_CTL, minScrollPos, maxScrollPos, TRUE);
        SetDlgItemInt(hDlg, IDC_NUMBER_TEXT, scrollPos, TRUE);

        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    case WM_HSCROLL:
        scrollPos = GetScrollPos(hScroll, SB_CTL);

        switch(LOWORD(wParam)) {
        case SB_LINELEFT:
            HandleLineLeft(hDlg);
            break;
        case SB_LINERIGHT:
            HandleLineRight(hDlg);
            break;
        case SB_THUMBPOSITION:
        case SB_THUMBTRACK:
            HandleThumbTrack(hDlg, wParam);
        default: break;
        }

        SetScrollPos(hScroll, SB_CTL, scrollPos, TRUE);
        break;
    }
    return (INT_PTR)FALSE;
}

void HandleLineLeft(HWND hDlg) {
    scrollPos--;
    SetDlgItemInt(hDlg, IDC_NUMBER_TEXT, scrollPos, TRUE);
}

void HandleLineRight(HWND hDlg) {
    scrollPos--;
    SetDlgItemInt(hDlg, IDC_NUMBER_TEXT, scrollPos, TRUE);
}

void HandleThumbTrack(HWND hDlg, WPARAM wParam) {
    scrollPos = HIWORD(wParam);
    SetDlgItemInt(hDlg, IDC_NUMBER_TEXT, scrollPos, TRUE);
}

int Func_MOD1(HINSTANCE hInst, HWND hWnd, WCHAR* textDest) {
    if (DialogBox(hInst, MAKEINTRESOURCE(IDD_FIRSTWORK_DIALOG), hWnd, Work1) == 1) {
        wsprintfW(textDest, L"Result of work #1: %d", scrollPos);
        return 1;
    }
    return 0;
}
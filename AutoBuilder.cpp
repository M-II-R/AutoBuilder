// AutoBuilder.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "AutoBuilder.h"
#include <iostream>
#include <fstream>
#include <string>
#include <shlobj.h>
#include<filesystem>
#include <commdlg.h>
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "comdlg32.lib")
#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    KeystoreDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK CordovaDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_AUTOBUILDER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_AUTOBUILDER));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_AUTOBUILDER));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_AUTOBUILDER);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Разобрать выбор в меню:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_GENERATE_KEYSTORE:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_KEYSTORE_DIALOG), hWnd, KeystoreDialog);
            break;
        case IDM_BUILD_CORDOVA:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_CORDOVA_DIALOG), hWnd, CordovaDialog);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Устанавливаем цвет текста
        SetTextColor(hdc, RGB(0, 0, 0)); // Черный цвет

        // Устанавливаем фоновый режим (прозрачный)
        SetBkMode(hdc, TRANSPARENT);

        // Выбираем шрифт
        HFONT hFont = CreateFont(16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
            OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
        HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

        // Текст для отображения
        const wchar_t* welcomeText = L"Утилита AutoBuilder.\n\n"
            L"Автоматизированная сборка Cordova-проектов и создание keystore для них.\n"
            L"Используйте меню Файл для использования вышеупомянутых функций.\n"
            L"У вас должны быть установлены Java и Jdk (проверено на Jdk-17), а также настроены системные переменные.\n"
            L"Создано M-II-R (_Mir_)\n";

        // Прямоугольник для текста
        RECT rect;
        GetClientRect(hWnd, &rect);

        // Рисуем текст
        DrawText(hdc, welcomeText, -1, &rect, DT_CENTER | DT_VCENTER | DT_NOCLIP | DT_WORDBREAK);

        // Восстанавливаем старый шрифт и удаляем наш
        SelectObject(hdc, hOldFont);
        DeleteObject(hFont);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

//Обработчик сообщений для создания keystore
INT_PTR CALLBACK KeystoreDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        // Установим значение по умолчанию для validity (365 дней)
        SetDlgItemInt(hDlg, IDC_VALIDITY, 365, FALSE);
        return (INT_PTR)TRUE;
    }

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK)
        {
            // Получаем все введенные значения
            wchar_t password[256];
            wchar_t passwordConfirm[256];
            wchar_t alias[256];
            wchar_t name[256];
            wchar_t org[256];
            wchar_t city[256];
            wchar_t country[10];
            int validity = GetDlgItemInt(hDlg, IDC_VALIDITY, NULL, FALSE);

            GetDlgItemText(hDlg, IDC_PASSWORD, password, 256);
            GetDlgItemText(hDlg, IDC_PASSWORD_CONFIRM, passwordConfirm, 256);
            GetDlgItemText(hDlg, IDC_ALIAS, alias, 256);
            GetDlgItemText(hDlg, IDC_NAME, name, 256);
            GetDlgItemText(hDlg, IDC_ORG, org, 256);
            GetDlgItemText(hDlg, IDC_CITY, city, 256);
            GetDlgItemText(hDlg, IDC_COUNTRY, country, 10);

            // Проверяем введенные данные
            if (wcscmp(password, passwordConfirm) != 0)
            {
                MessageBox(hDlg, L"Пароли не совпадают!", L"Ошибка", MB_ICONERROR);
                return (INT_PTR)TRUE;
            }

            if (wcslen(password) < 6 || wcslen(passwordConfirm) < 6) {
                MessageBox(hDlg, L"Пароль не может быть короче 6 символов!", L"Ошибка", MB_ICONERROR);
                return (INT_PTR)TRUE;
            }

            if (wcslen(alias) == 0)
            {
                MessageBox(hDlg, L"Необходимо указать Alias!", L"Ошибка", MB_ICONERROR);
                return (INT_PTR)TRUE;
            }

            if (validity <= 0)
            {
                MessageBox(hDlg, L"Срок действия должен быть положительным числом!", L"Ошибка", MB_ICONERROR);
                return (INT_PTR)TRUE;
            }

            if (wcslen(country) != 2)
            {
                MessageBox(hDlg, L"Код страны должен состоять из 2 букв!", L"Ошибка", MB_ICONERROR);
                return (INT_PTR)TRUE;
            }

            // Конвертируем в UTF-8 для keytool
            char passwordA[256];
            char aliasA[256];
            char nameA[256];
            char orgA[256];
            char cityA[256];
            char countryA[10];

            WideCharToMultiByte(CP_UTF8, 0, password, -1, passwordA, 256, NULL, NULL);
            WideCharToMultiByte(CP_UTF8, 0, alias, -1, aliasA, 256, NULL, NULL);
            WideCharToMultiByte(CP_UTF8, 0, name, -1, nameA, 256, NULL, NULL);
            WideCharToMultiByte(CP_UTF8, 0, org, -1, orgA, 256, NULL, NULL);
            WideCharToMultiByte(CP_UTF8, 0, city, -1, cityA, 256, NULL, NULL);
            WideCharToMultiByte(CP_UTF8, 0, country, -1, countryA, 10, NULL, NULL);

            // Создаем временный файл для keytool
            std::ofstream input("input.txt");
            input << passwordA << "\n" << passwordA << "\n" << nameA << "\n" << orgA << "\n" << orgA << "\n"
                << cityA << "\n" << "State" << "\n" << countryA << "\nyes\n";
            input.close();

            // Формируем команду keytool с указанным alias и validity
            std::string command = "keytool -genkey -alias " + std::string(aliasA) +
                " -keystore keystore.keystore -storetype pkcs12 -keyalg RSA -keysize 2048 -validity " +
                std::to_string(validity) + " < input.txt";

            // Выполняем keytool
            int result = system(command.c_str());

            // Удаляем временный файл
            remove("input.txt");

            if (result == 0)
            {
                MessageBox(hDlg, L"Keystore успешно создан!", L"Успех", MB_ICONINFORMATION);
            }
            else
            {
                MessageBox(hDlg, L"Ошибка при создании keystore! Убедитесь, что keytool (Jks) доступен в PATH. Если это не помогло, проверьте, нет ли в папке с этой программой другого keystore, перезагрузите компьютер и/или напишите разработчику.", L"Ошибка", MB_ICONERROR);
            }

            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        else if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
// Обработчик сообщений для окна сборки Cordova проекта
INT_PTR CALLBACK CordovaDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        // Инициализация комбобокса с платформами
        HWND hCombo = GetDlgItem(hDlg, IDC_FILE);
        SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"apk");
        SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"bundle");
        SendMessage(hCombo, CB_SETCURSEL, 0, 0); // Выбираем apk по умолчанию
        return (INT_PTR)TRUE;
    }

    case WM_COMMAND:
        if (LOWORD(wParam) == IDC_BROWSE)
        {
            // Диалог выбора папки проекта
            BROWSEINFO bi = { 0 };
            bi.lpszTitle = L"Выберите папку с Cordova-проектом";
            LPITEMIDLIST pidl = SHBrowseForFolder(&bi);

            if (pidl != NULL)
            {
                wchar_t path[MAX_PATH];
                SHGetPathFromIDList(pidl, path);
                SetDlgItemText(hDlg, IDC_PROJECT_PATH, path);
                CoTaskMemFree(pidl);
            }
            return (INT_PTR)TRUE;
        }
        else if (LOWORD(wParam) == IDC_BROWSE_KEYSTORE)
        {
            // Диалог выбора файла keystore
            OPENFILENAME ofn;
            wchar_t szFile[MAX_PATH] = L"";

            ZeroMemory(&ofn, sizeof(ofn));
            ofn.lStructSize = sizeof(ofn);
            ofn.hwndOwner = hDlg;
            ofn.lpstrFile = szFile;
            ofn.nMaxFile = sizeof(szFile);
            ofn.lpstrFilter = L"Keystore Files (*.jks, *.keystore)\0*.jks;*.keystore\0All Files (*.*)\0*.*\0";
            ofn.nFilterIndex = 1;
            ofn.lpstrFileTitle = NULL;
            ofn.nMaxFileTitle = 0;
            ofn.lpstrInitialDir = NULL;
            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

            if (GetOpenFileName(&ofn))
            {
                SetDlgItemText(hDlg, IDC_KEYSTORE_PATH, szFile);
            }
            return (INT_PTR)TRUE;
        }
        else if (LOWORD(wParam) == IDOK)
        {
            // Получаем введенные значения
            wchar_t projectPath[MAX_PATH];
            wchar_t file[6];
            wchar_t keystorePath[MAX_PATH];
            wchar_t keystorePassword[256];
            wchar_t keystoreAlias[256];

            GetDlgItemText(hDlg, IDC_PROJECT_PATH, projectPath, MAX_PATH);
            GetDlgItemText(hDlg, IDC_FILE, file, 6);
            GetDlgItemText(hDlg, IDC_KEYSTORE_PATH, keystorePath, MAX_PATH);
            GetDlgItemText(hDlg, IDC_KEYSTORE_PASSWORD, keystorePassword, 256);
            GetDlgItemText(hDlg, IDC_KEYSTORE_ALIAS, keystoreAlias, 256);

            // Проверяем введенные данные
            if (wcslen(projectPath) == 0)
            {
                MessageBox(hDlg, L"Необходимо указать путь к проекту!", L"Ошибка", MB_ICONERROR);
                return (INT_PTR)TRUE;
            }

            /*if (wcscmp(platform, L"android") != 0 && wcscmp(platform, L"ios") != 0)
            {
                MessageBox(hDlg, L"Необходимо выбрать платформу (android или ios)!", L"Ошибка", MB_ICONERROR);
                return (INT_PTR)TRUE;
            }*/

            // Для Android проверяем параметры keystore
            //if (wcscmp(platform, L"android") == 0)
            //{
                if (wcslen(keystorePath) == 0 || wcslen(keystorePassword) == 0 || wcslen(keystoreAlias) == 0)
                {
                    MessageBox(hDlg, L"Для Android необходимо указать путь к Keystore, пароль и alias!", L"Ошибка", MB_ICONERROR);
                    return (INT_PTR)TRUE;
                }
            //}

            // Конвертируем в UTF-8 для командной строки
            char projectPathA[MAX_PATH];
            auto platformA = "android";
            char keystorePathA[MAX_PATH];
            char keystorePasswordA[256];
            char keystoreAliasA[256];
            char fileA[6];

            WideCharToMultiByte(CP_UTF8, 0, projectPath, -1, projectPathA, MAX_PATH, NULL, NULL);
            WideCharToMultiByte(CP_UTF8, 0, file, -1, fileA, 6, NULL, NULL);
            WideCharToMultiByte(CP_UTF8, 0, keystorePath, -1, keystorePathA, MAX_PATH, NULL, NULL);
            WideCharToMultiByte(CP_UTF8, 0, keystorePassword, -1, keystorePasswordA, 256, NULL, NULL);
            WideCharToMultiByte(CP_UTF8, 0, keystoreAlias, -1, keystoreAliasA, 256, NULL, NULL);
            
            
            // Формируем команды для сборки
            std::string commands;
            commands += "cd /d \"" + std::string(projectPathA) + "\" & ";
            commands += "cordova platform add " + std::string(platformA) + " & ";
            commands += "cordova prepare & ";

            //if (strcmp(fileA, "bundle") == 0)
            //{
                // Для Android добавляем параметры подписи
                commands += "cordova build android --release \"--\" --keystore=\"" + std::string(keystorePathA) + "\""+ " --storePassword=\"" + std::string(keystorePasswordA) + "\" --alias=" + std::string(keystoreAliasA) + " --password=\"" + std::string(keystorePasswordA)+"\" --packageType=" +std::string(fileA);
                //Отладку: commands += "cordova build android --release --keystore=\"C:\\Users\\miros\\source\\repos\\AutoBuilder\\keystore.keystore\" --storePassword=111111 --password=111111 --alias=A";
            //}
            //else
            //{
                // Для iOS обычная сборка
            //    commands += "cordova build ios --release";
            //}


            /*
            // Отладка
            int cmdSize = MultiByteToWideChar(CP_UTF8, 0, commands.c_str(), -1, NULL, 0);
            wchar_t* wcmd = new wchar_t[cmdSize];
            MultiByteToWideChar(CP_UTF8, 0, commands.c_str(), -1, wcmd, cmdSize);
            MessageBox(hDlg, wcmd, L"Выполняемая команда", MB_ICONINFORMATION | MB_OK);
            delete[] wcmd;
            */

            // Выполняем команды
            int result = system(commands.c_str());
            
            if (result == 0)
            {
                MessageBox(hDlg, L"Проект успешно собран!", L"Успех", MB_ICONINFORMATION);
            }
            else
            {
                MessageBox(hDlg, L"Ошибка при сборке проекта! Убедитесь, что Cordova (Jks) установлена и доступна в PATH. Если это не помогло, перезагрузите компьютер и/или напишите разработчику.", L"Ошибка", MB_ICONERROR);
            }

            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        else if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
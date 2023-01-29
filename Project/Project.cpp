#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"
#include "Project.h"
#include "Header.h"
HINSTANCE hInst;                                
WCHAR szTitle[MAX_LOADSTRING];                  
WCHAR szWindowClass[MAX_LOADSTRING];           
Shape* temp; //Bien tam cua doi tung hinh
int countP = 0; //Bien dem cua mang phan loai cac hinh
int countClick = 0; // So lan nhan chuot phai
int tempd = 0; //Bien dem nhap so dinh cua da giac
int Count; //Bien bao co hinh ve neu Count = 1 thi ve
int tempP[100]; // mang phan loai cac hinh
double pxA = 1; // Bien tam chu gia tri toa do diem A
double pyA = 1;
double pxB = 1; // Bien tam chu gia tri toa do diem B
double pyB = 1;
double pxC = 1; // Bien tam chu gia tri toa do diem C
double pyC = 1;
double pR1 = 1; // Bien tam chu gia tri ban kinh cac hinh
double pR2 = 1; // Bien tam chu gia tri  ban kinh cac hinh
int countN = 5; // Dem so dinh da giac
int checkInputpolygon = 0; // Kiem tra nhap hinh da giac hop le hay khong
int checkDT = 0; // Kiem tra duong thang da nhap hay chon hay khong
HWND hInputline,hInputcircle,hInputellipse,hInputsemic,hInputpolygon, hInputpolygon2,hInputrectangle,hInputsquare,hInputtriangle; // cua so nhap cac hinh
HWND hOut,hOut2; // cua so gia tri xuat
HWND hPointxA, hPointyA, hPointxB, hPointyB, hR, hR2, hPointxC, hPointyC,hDSemic,hN; // phuc vu nhap gia tri tuong ung tung hinh ( co the su dung qua lai giua cac hinh )
HWND hPicture1,hPicture2,hAbout; // cua so hinh anh thong tin thanh vien
HMENU hMenu; // thanh menu
HWND hWnd; // cua so chinh
HBITMAP hKhang, hLinh; // anh tac giac
pt d; // phuong trinh duong thang
vector <Point> mang; // cac mang phuc vu hinh da giac, chu nhat, vuong tam giac
vector <Point> mang2;
vector <Point> mang3;
vector <Point> mang4;
Line l(0, 0, 0,0); // doi tuong duong thang
ShapeCircle c(0, 0, 0); // doi tuong hinh tron
ShapeEllipse e(0, 0, 0, 0); // doi tuong ellipse
ShapeSemic bn(4, 0, 0, 0); // doi tuong ban nguyet
Point pts1[] = { {0,0},{0,0},{0,0},{0,0},{0,0} }; // mang da giac
Point ptsCN[] = { {0,0},{0,0},{0,0},{0,0} }; // mang chu nhat
Point ptsV[] = { {0,0},{0,0},{0,0},{0,0} }; // mang hinh vuong
Point ptsTG[] = { {0,0},{0,0},{0,0} }; // mang tam giac
ShapePolygon D(0, 0); // doi tuong da giac

void loadPicture(); // ham lay anh
void winAbout(HWND hWnd); // tao cua so thong tin
void addMenus(HWND hWnd); // tao thanh menu
void winInputline(HWND hWnd); // tao cua so nhap duong thang
void winInputcircle(HWND hWnd); // tao cua so nhap hinh tron
void winInputellipse(HWND hWnd);  // tao cua so nhap hinh ellipse
void winInputsemic(HWND hWnd); // tao cua so hinh nhap ban nguyet
void winInputpolygon(HWND hWnd); // tao cua so nhap dinh hinh da giac loi
void winInputpolygon2(HWND hWnd); // tao cua so nhap da giac
void winInputrectangle(HWND hWnd); // tao cua so nhap hinh chu nhat
void winInputsquare(HWND hWnd); // tao cua so nhap hinh vuong
void winInputtriangle(HWND hWnd); // tao cua so nhap hinh tam giac

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
// cac ham phuc vu cua so nhap lieu
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    WndProc2(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    WndProc3(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    WndProc4(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    WndProc5(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    WndProc6(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    WndProc7(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    WndProc8(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    WndProc9(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    WndProc10(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void RegidterClass2(HINSTANCE hInstance);
void RegidterClass3(HINSTANCE hInstance);
void RegidterClass4(HINSTANCE hInstance);
void RegidterClass5(HINSTANCE hInstance);
void RegidterClass6(HINSTANCE hInstance);
void RegidterClass7(HINSTANCE hInstance);
void RegidterClass8(HINSTANCE hInstance);
void RegidterClass9(HINSTANCE hInstance);
void RegidterClass10(HINSTANCE hInstance);


void RegidterClass2(HINSTANCE hInstance) {
    WNDCLASSEXW diaglog;

    diaglog.cbSize = sizeof(WNDCLASSEX);

    diaglog.style = CS_HREDRAW | CS_VREDRAW;
    diaglog.lpfnWndProc = WndProc2;
    diaglog.cbClsExtra = 0;
    diaglog.cbWndExtra = 0;
    diaglog.hInstance = hInstance;
    diaglog.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT));
    diaglog.hCursor = LoadCursor(nullptr, IDC_ARROW);
    diaglog.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    diaglog.lpszMenuName = NULL;
    diaglog.lpszClassName = L"input1";
    diaglog.hIconSm = LoadIcon(diaglog.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&diaglog);
}

void RegidterClass3(HINSTANCE hInstance) {
    WNDCLASSEXW diaglog2;

    diaglog2.cbSize = sizeof(WNDCLASSEX);

    diaglog2.style = CS_HREDRAW | CS_VREDRAW;
    diaglog2.lpfnWndProc = WndProc3;
    diaglog2.cbClsExtra = 0;
    diaglog2.cbWndExtra = 0;
    diaglog2.hInstance = hInstance;
    diaglog2.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT));
    diaglog2.hCursor = LoadCursor(nullptr, IDC_ARROW);
    diaglog2.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    diaglog2.lpszMenuName = NULL;
    diaglog2.lpszClassName = L"input2";
    diaglog2.hIconSm = LoadIcon(diaglog2.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&diaglog2);
}

void RegidterClass4(HINSTANCE hInstance) {
    WNDCLASSEXW diaglog3;

    diaglog3.cbSize = sizeof(WNDCLASSEX);

    diaglog3.style = CS_HREDRAW | CS_VREDRAW;
    diaglog3.lpfnWndProc = WndProc4;
    diaglog3.cbClsExtra = 0;
    diaglog3.cbWndExtra = 0;
    diaglog3.hInstance = hInstance;
    diaglog3.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT));
    diaglog3.hCursor = LoadCursor(nullptr, IDC_ARROW);
    diaglog3.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    diaglog3.lpszMenuName = NULL;
    diaglog3.lpszClassName = L"input3";
    diaglog3.hIconSm = LoadIcon(diaglog3.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&diaglog3);
}

void RegidterClass5(HINSTANCE hInstance) {
    WNDCLASSEXW diaglog4;

    diaglog4.cbSize = sizeof(WNDCLASSEX);

    diaglog4.style = CS_HREDRAW | CS_VREDRAW;
    diaglog4.lpfnWndProc = WndProc5;
    diaglog4.cbClsExtra = 0;
    diaglog4.cbWndExtra = 0;
    diaglog4.hInstance = hInstance;
    diaglog4.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT));
    diaglog4.hCursor = LoadCursor(nullptr, IDC_ARROW);
    diaglog4.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    diaglog4.lpszMenuName = NULL;
    diaglog4.lpszClassName = L"input4";
    diaglog4.hIconSm = LoadIcon(diaglog4.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&diaglog4);
}

void RegidterClass6(HINSTANCE hInstance) {
    WNDCLASSEXW diaglog5;

    diaglog5.cbSize = sizeof(WNDCLASSEX);

    diaglog5.style = CS_HREDRAW | CS_VREDRAW;
    diaglog5.lpfnWndProc = WndProc6;
    diaglog5.cbClsExtra = 0;
    diaglog5.cbWndExtra = 0;
    diaglog5.hInstance = hInstance;
    diaglog5.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT));
    diaglog5.hCursor = LoadCursor(nullptr, IDC_ARROW);
    diaglog5.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    diaglog5.lpszMenuName = NULL;
    diaglog5.lpszClassName = L"input5";
    diaglog5.hIconSm = LoadIcon(diaglog5.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&diaglog5);
}

void RegidterClass7(HINSTANCE hInstance) {
    WNDCLASSEXW diaglog6;

    diaglog6.cbSize = sizeof(WNDCLASSEX);

    diaglog6.style = CS_HREDRAW | CS_VREDRAW;
    diaglog6.lpfnWndProc = WndProc7;
    diaglog6.cbClsExtra = 0;
    diaglog6.cbWndExtra = 0;
    diaglog6.hInstance = hInstance;
    diaglog6.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT));
    diaglog6.hCursor = LoadCursor(nullptr, IDC_ARROW);
    diaglog6.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    diaglog6.lpszMenuName = NULL;
    diaglog6.lpszClassName = L"input6";
    diaglog6.hIconSm = LoadIcon(diaglog6.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&diaglog6);
}

void RegidterClass8(HINSTANCE hInstance) {
    WNDCLASSEXW diaglog7;

    diaglog7.cbSize = sizeof(WNDCLASSEX);

    diaglog7.style = CS_HREDRAW | CS_VREDRAW;
    diaglog7.lpfnWndProc = WndProc8;
    diaglog7.cbClsExtra = 0;
    diaglog7.cbWndExtra = 0;
    diaglog7.hInstance = hInstance;
    diaglog7.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT));
    diaglog7.hCursor = LoadCursor(nullptr, IDC_ARROW);
    diaglog7.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    diaglog7.lpszMenuName = NULL;
    diaglog7.lpszClassName = L"input7";
    diaglog7.hIconSm = LoadIcon(diaglog7.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&diaglog7);
}

void RegidterClass9(HINSTANCE hInstance) {
    WNDCLASSEXW diaglog8;

    diaglog8.cbSize = sizeof(WNDCLASSEX);

    diaglog8.style = CS_HREDRAW | CS_VREDRAW;
    diaglog8.lpfnWndProc = WndProc9;
    diaglog8.cbClsExtra = 0;
    diaglog8.cbWndExtra = 0;
    diaglog8.hInstance = hInstance;
    diaglog8.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT));
    diaglog8.hCursor = LoadCursor(nullptr, IDC_ARROW);
    diaglog8.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    diaglog8.lpszMenuName = NULL;
    diaglog8.lpszClassName = L"input8";
    diaglog8.hIconSm = LoadIcon(diaglog8.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&diaglog8);
}

void RegidterClass10(HINSTANCE hInstance) {
    WNDCLASSEXW diaglog9;

    diaglog9.cbSize = sizeof(WNDCLASSEX);

    diaglog9.style = CS_HREDRAW | CS_VREDRAW;
    diaglog9.lpfnWndProc = WndProc10;
    diaglog9.cbClsExtra = 0;
    diaglog9.cbWndExtra = 0;
    diaglog9.hInstance = hInstance;
    diaglog9.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT));
    diaglog9.hCursor = LoadCursor(nullptr, IDC_ARROW);
    diaglog9.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    diaglog9.lpszMenuName = NULL;
    diaglog9.lpszClassName = L"input9";
    diaglog9.hIconSm = LoadIcon(diaglog9.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&diaglog9);
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);
    RegidterClass2(hInstance);
    RegidterClass3(hInstance);
    RegidterClass4(hInstance);
    RegidterClass5(hInstance);
    RegidterClass6(hInstance);
    RegidterClass7(hInstance);
    RegidterClass8(hInstance);
    RegidterClass9(hInstance);
    RegidterClass10(hInstance);


    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJECT));
    MSG msg;
    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PROJECT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static ShapePolygon D2(4, ptsCN);
    static ShapePolygon D3(3, ptsTG);
    static ShapePolygon D4(4, ptsV);
    static ShapePolygon D(countN, pts1);
    if (checkDT != 0)
    {
        // viet phuong trinh duong thang
        pt_assign(d, (int)(l.GetA().GetX()), (int)(l.GetA().GetY()), (int)(l.GetB().GetX()), (int)(l.GetB().GetY()));
    }
    switch (message)
    {
        temp = NULL;
    case WM_CREATE:                          
        MessageBox(hWnd, L"Cho một danh sách các đối tượng hình học, mỗi đối tượng thuộc một trong các loại: Hình tròn,hình ellipse, hình bán nguyệt, hình đa giác(lồi), hình chữ nhật, hình vuông, hình tam giác.Cho một đường thẳng(ax + by = c) trong mặt phẳng.Viết hàm cho biết đường thẳng cắt các hình nào của danh sách.Viết ứng dụng cho phép tạo các hình và một đường thẳng, vẽ các hình và đường thẳng, xuất thông báo cho biết đường đi qua bao nhiêu hình, tô màu các hình có đường cắt ngang với màu khác các hình còn lại.", L"Đề bài", 0);
        addMenus(hWnd);
        return 0;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // nhan nut tren thanh menu tung ung 1 lenh
        switch (wmId)
        {
        case FILE_MENU_HELP:
            loadPicture();
            winAbout(hWnd);
            break;
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case FILE_MENU_NEW:
            countP = 0;
            checkDT = 0;
            Count = 1;
            ds_hinh.clear();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case FILE_MENU_PAINT:
            Count = 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case CHOOSE_PAINT_TRON:
            temp = new ShapeCircle;
            c.Set(200, 400, 100, 0);
            temp->Set(200, 400, 100, 0);
            ds_hinh.push_back(temp);
            tempP[countP] = 1;
            countP++;
            Count = 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case CHOOSE_PAINT_ELLIPSE:
            temp = new ShapeEllipse;
            e.Set(700, 300, 250, 50);
            temp->Set(700, 300, 250, 50);
            ds_hinh.push_back(temp);
            tempP[countP] = 2;
            countP++;
            Count = 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case CHOOSE_PAINT_BANNGUYET:
            temp = new ShapeSemic;
            bn.Set(4, 110, 110, 110);
            temp->Set(4, 110, 110, 110);
            ds_hinh.push_back(temp);
            tempP[countP] = 3;
            countP++;
            Count = 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case CHOOSE_PAINT_DAGIAC:
            temp = new ShapePolygon;
            countN = 5;
            pts1[0] = { 100,250 };
            pts1[1] = { 500, 280 };
            pts1[2] = { 300, 350 };
            pts1[3] = { 50, 350 };
            pts1[4] = { 0, 280 };
            temp->Set(5, 0, 0, 0);
            temp->SetPoint(pts1);
            ds_hinh.push_back(temp);
            tempP[countP] = 4;
            countP++;
            Count = 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case CHOOSE_PAINT_CN:
            temp = new ShapePolygon;
            ptsCN[0] = { 750,80 };
            ptsCN[1] = { 1200, 80 };
            ptsCN[2] = { 1200, 180 };
            ptsCN[3] = { 750, 180 };
            temp->Set(4, 0, 0, 0);
            temp->SetPoint(ptsCN);
            ds_hinh.push_back(temp);
            tempP[countP] = 5;
            countP++;
            Count = 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case CHOOSE_PAINT_VUONG:
            temp = new ShapePolygon;
            ptsV[0] = { 700,400 };
            ptsV[1] = { 900, 400 };
            ptsV[2] = { 900, 600 };
            ptsV[3] = { 700, 600 };
            temp->Set(4, 0, 0, 0);
            temp->SetPoint(ptsV);
            ds_hinh.push_back(temp);
            tempP[countP] = 6;
            countP++;
            Count = 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case CHOOSE_PAINT_TG:
            temp = new ShapePolygon;
            ptsTG[0] = { 700,100 };
            ptsTG[1] = { 800, 300 };
            ptsTG[2] = { 600, 300 };
            temp->Set(3, 0, 0, 0);
            temp->SetPoint(ptsTG);
            ds_hinh.push_back(temp);
            tempP[countP] = 7;
            countP++;
            Count = 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case CHOOSE_PAINT_DT:
            l.Set(0, 0, 2000, 1000);
            checkDT = 1;
            tempP[countP] = 8;
            countP++;
            Count = 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case INPUT_PAINT_TRON:
            temp = new ShapeCircle;
            winInputcircle(hWnd);
           
            tempP[countP] = 1;
            countP++;
            break;
        case INPUT_PAINT_ELLIPSE:
            temp = new ShapeEllipse;
            tempP[countP] = 2;
            countP++;
            winInputellipse(hWnd);
            
            break;
        case INPUT_PAINT_BANNGUYET:
            temp = new ShapeSemic;
            
            tempP[countP] = 3;
            countP++;
            winInputsemic(hWnd);
            
            break;
        case INPUT_PAINT_DAGIAC:
            temp = new ShapePolygon;
            
            tempP[countP] = 4;
            countP++;
            winInputpolygon(hWnd);
           
            break;
        case INPUT_PAINT_CN:
            temp = new ShapePolygon;
            
            tempP[countP] = 5;
            countP++;
            winInputrectangle(hWnd);
           
            break;
        case INPUT_PAINT_VUONG:
            temp = new ShapePolygon;
            tempP[countP] = 6;
            countP++;
            winInputsquare(hWnd);
           
            break;
        case INPUT_PAINT_DT:
            winInputline(hWnd);
            break;
        case INPUT_PAINT_TG:
            temp = new ShapePolygon;
            tempP[countP] = 7;
            countP++;
            winInputtriangle(hWnd);
            
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    
    case WM_PAINT:
    {
        if (ds_hinh.size() == 0)
        {
            break;
        }
        InvalidateRect(hWnd, NULL, TRUE);
        if (Count == 1)
        {
            // tao cac bien ve
            PAINTSTRUCT ps;
            HDC hDC = BeginPaint(hWnd, &ps);
            HPEN hOldPen, hNewPen;
            HBRUSH hOldBrush, hNewBrush;
            hNewPen = CreatePen(PS_SOLID, 2, RGB(240, 128, 128));
            hOldPen = (HPEN)SelectObject(hDC, hNewPen);
            hNewBrush = CreateSolidBrush(RGB(255, 192, 203));
            hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);
            int countCut = 0;
            for (int i = 0; i < ds_hinh.size(); i++)
            {
                if (tempP[i] == 1)
                {
                    if (ds_hinh[i]->Check(d) == 1 && checkDT != 0)
                    {
                        countCut++;
                        hNewPen = CreatePen(PS_SOLID, 2, RGB(60, 179, 113));
                        hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                        hNewBrush = CreateSolidBrush(RGB(152, 251, 152));
                        hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);
                        ds_hinh[i]->draw(hDC);// vẽ hình tròn
                        hNewPen = CreatePen(PS_SOLID, 2, RGB(240, 128, 128));
                        hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                        hNewBrush = CreateSolidBrush(RGB(255, 192, 203));
                        hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);
                    }
                    else {
                        ds_hinh[i]->draw(hDC);// vẽ hình tròn
                    }
                }
                else if (tempP[i] == 2)
                {
                    if (ds_hinh[i]->Check(d) == 1 && checkDT != 0)
                    {
                        countCut++;
                        hNewPen = CreatePen(PS_SOLID, 2, RGB(60, 179, 113));
                        hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                        hNewBrush = CreateSolidBrush(RGB(152, 251, 152));
                        hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);
                        ds_hinh[i]->draw(hDC);;// vẽ hình ellipse
                        hNewPen = CreatePen(PS_SOLID, 2, RGB(240, 128, 128));
                        hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                        hNewBrush = CreateSolidBrush(RGB(255, 192, 203));
                        hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);

                    }
                    else {
                        ds_hinh[i]->draw(hDC);// vẽ hình ellipse
                    }
                
                }
                else if (tempP[i] == 3)
                {
                    if (ds_hinh[i]->Check(d) == 1 && checkDT != 0)
                    {
                        countCut++;
                        hNewPen = CreatePen(PS_SOLID, 2, RGB(60, 179, 113));
                        hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                        hNewBrush = CreateSolidBrush(RGB(152, 251, 152));
                        hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);
                        ds_hinh[i]->draw(hDC);// vẽ hình ban nguyet
                        hNewPen = CreatePen(PS_SOLID, 2, RGB(240, 128, 128));
                        hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                        hNewBrush = CreateSolidBrush(RGB(255, 192, 203));
                        hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);

                    }
                    else {
                        ds_hinh[i]->draw(hDC);// vẽ hình ban nguyet
                    }
                }
                else if (tempP[i] == 4)
                {
                    if (ds_hinh[i]->Check(d) == 1 && checkDT != 0)
                    {
                        countCut++;
                        hNewPen = CreatePen(PS_SOLID, 2, RGB(60, 179, 113));
                        hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                        hNewBrush = CreateSolidBrush(RGB(152, 251, 152));
                        hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);
                        ds_hinh[i]->draw(hDC);// vẽ hình đa giac
                        hNewPen = CreatePen(PS_SOLID, 2, RGB(240, 128, 128));
                        hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                        hNewBrush = CreateSolidBrush(RGB(255, 192, 203));
                        hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);

                    }
                    else {
                        ds_hinh[i]->draw(hDC);// vẽ hình da giac
                    }

                }
                else if (tempP[i] == 5)
                {
                    if (ds_hinh[i]->Check(d) == 1 && checkDT != 0)
                    {
                        countCut++;
                        hNewPen = CreatePen(PS_SOLID, 2, RGB(60, 179, 113));
                        hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                        hNewBrush = CreateSolidBrush(RGB(152, 251, 152));
                        hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);
                        ds_hinh[i]->draw(hDC);// vẽ hình chu nhat
                        hNewPen = CreatePen(PS_SOLID, 2, RGB(240, 128, 128));
                        hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                        hNewBrush = CreateSolidBrush(RGB(255, 192, 203));
                        hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);

                    }
                    else {
                        ds_hinh[i]->draw(hDC);// vẽ hình chu nhat
                    }
                }
                else if (tempP[i] == 6)
                {
                    if (ds_hinh[i]->Check(d) == 1 && checkDT != 0)
                    {
                        countCut++;
                        hNewPen = CreatePen(PS_SOLID, 2, RGB(60, 179, 113));
                        hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                        hNewBrush = CreateSolidBrush(RGB(152, 251, 152));
                        hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);
                        ds_hinh[i]->draw(hDC); // ve hinh vuong
                        hNewPen = CreatePen(PS_SOLID, 2, RGB(240, 128, 128));
                        hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                        hNewBrush = CreateSolidBrush(RGB(255, 192, 203));
                        hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);

                    }
                    else {

                        ds_hinh[i]->draw(hDC); // ve hinh vuong
                    }
                }
                else if (tempP[i] == 7)
                {
                    if (ds_hinh[i]->Check(d) == 1 && checkDT != 0)
                    {
                        countCut++;
                        hNewPen = CreatePen(PS_SOLID, 2, RGB(60, 179, 113));
                        hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                        hNewBrush = CreateSolidBrush(RGB(152, 251, 152));
                        hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);
                        ds_hinh[i]->draw(hDC); // ve hinh tam giac
                        hNewPen = CreatePen(PS_SOLID, 2, RGB(240, 128, 128));
                        hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                        hNewBrush = CreateSolidBrush(RGB(255, 192, 203));
                        hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);

                    }
                    else {
                        ds_hinh[i]->draw(hDC); // ve hinh tam giac
                    }
                }
                else if (tempP[i] == 8)
                {
                checkDT = 1;
                }
            }
            if (checkDT != 0)
            {
                hNewPen = CreatePen(PS_SOLID, 2, RGB(70,130,180));
                hOldPen = (HPEN)SelectObject(hDC, hNewPen);
                l.draw(hDC);
            }
            if (countClick >= 0)
            { //Nút chuột trái đã được nhấp
                    
                POINT p;
                if (GetCursorPos(&p))
                {
                    //vị trí con trỏ hiện ở p.x và p.y
                }
                if (ScreenToClient(hWnd, &p))
                {
                    //p.x và p.y hiện tương đối tren hwnd
                }
             
                ShowCursor(TRUE);
                char msg[100];
                sprintf(msg, " * Toa do chuot ( ""x: %d\n"", y : %d )\n"" --- So hinh duong thang cat: %d\n *", p.x, p.y, countCut);
                size_t size = strlen(msg);
                wchar_t* wArr = new wchar_t[size];
                for (size_t i = 0; i < size; ++i)
                    wArr[i] = msg[i];
                TextOut(hDC, 500, 0, (LPCWSTR)&wArr[0], (int)(size));
                delete[] wArr;
            }
            DeleteObject(hNewBrush);
            DeleteObject(hNewPen);
            DeleteObject(hOldBrush);
            DeleteObject(hOldPen);
            EndPaint(hWnd, &ps);
        }

        return 0;
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
       
    case WM_LBUTTONDOWN:      // Nút chuột trái đã được nhấp
            countClick++;
            InvalidateRect(hWnd, NULL, TRUE);
        return 0;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


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

// cac hinh tao cua so nhap cac hinh

void winInputline(HWND hWnd)
{
    hInputline = CreateWindowW(L"input1", L"Nhập vẽ đường thẳng", WS_VISIBLE | WS_BORDER | WS_OVERLAPPEDWINDOW | SS_CENTER, 500, 250, 400, 400, NULL, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Nhập 2 điểm tọa độ đường thẳng", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 10, 290, 20, hInputline, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Điểm thứ nhất A(x,y)", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 40, 140, 20, hInputline, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Điểm thứ hai B(x,y)", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 40, 140, 20, hInputline, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ xA:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 70, 140, 20, hInputline, NULL, NULL, NULL);
    hPointxA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 100, 140, 20, hInputline, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ yA:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 130, 140, 20, hInputline, NULL, NULL, NULL);
    hPointyA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 160, 140, 20, hInputline, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ xB:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 70, 140, 20, hInputline, NULL, NULL, NULL);
    hPointxB = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 200, 100, 140, 20, hInputline, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ yB:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 130, 140, 20, hInputline, NULL, NULL, NULL);
    hPointyB = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 200, 160, 140, 20, hInputline, NULL, NULL, NULL);
    hOut = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 210, 290, 50, hInputline, NULL, NULL, NULL);
    CreateWindowW(L"button", L"Kết quả", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 290, 140, 40, hInputline, (HMENU)BUTTON_CHECK, NULL, NULL);
    CreateWindowW(L"button", L"Thoát", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 290, 140, 40, hInputline, (HMENU)BUTTON_END, NULL, NULL);

}

void winInputcircle(HWND hWnd)
{
    hInputcircle = CreateWindowW(L"input2", L"Nhập vẽ đường tròn", WS_VISIBLE | WS_BORDER | WS_OVERLAPPEDWINDOW | SS_CENTER, 500, 250, 400, 400, NULL, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Nhập tọa độ tâm và bán kính ", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 10, 290, 20, hInputcircle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Bán kính", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 40, 290, 20, hInputcircle, NULL, NULL, NULL);
    hR=CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 70, 290, 20, hInputcircle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ x tâm:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 100, 290, 20, hInputcircle, NULL, NULL, NULL);
    hPointxA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 130, 290, 20, hInputcircle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ y tâm:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 160, 290, 20, hInputcircle, NULL, NULL, NULL);
    hPointyA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 190, 290, 20, hInputcircle, NULL, NULL, NULL);
    hOut = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 230, 290, 50, hInputcircle, NULL, NULL, NULL);
    CreateWindowW(L"button", L"Kết quả", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 310, 140, 40, hInputcircle, (HMENU)BUTTON_CHECK, NULL, NULL);
    CreateWindowW(L"button", L"Thoát", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 310, 140, 40, hInputcircle, (HMENU)BUTTON_END, NULL, NULL);
}

void winInputellipse(HWND hWnd)
{
    hInputellipse = CreateWindowW(L"input3", L"Nhập vẽ hình Ellipse", WS_VISIBLE | WS_BORDER | WS_OVERLAPPEDWINDOW | SS_CENTER, 500, 250, 400, 400, NULL, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Nhập độ dài 2 trục và tọa độ tâm", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 10, 290, 20, hInputellipse, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Độ dài 2 trục", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 40, 290, 20, hInputellipse, NULL, NULL, NULL);
    hR = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 70, 140, 20, hInputellipse, NULL, NULL, NULL);
    hR2 = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 200, 70, 140, 20, hInputellipse, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ x tâm:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 100, 290, 20, hInputellipse, NULL, NULL, NULL);
    hPointxA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 130, 290, 20, hInputellipse, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ y tâm:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 160, 290, 20, hInputellipse, NULL, NULL, NULL);
    hPointyA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 190, 290, 20, hInputellipse, NULL, NULL, NULL);
    hOut = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 230, 290, 50, hInputellipse, NULL, NULL, NULL);
    CreateWindowW(L"button", L"Kết quả", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 310, 140, 40, hInputellipse, (HMENU)BUTTON_CHECK, NULL, NULL);
    CreateWindowW(L"button", L"Thoát", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 310, 140, 40, hInputellipse, (HMENU)BUTTON_END, NULL, NULL);
}

void winInputsemic(HWND hWnd)
{
    hInputsemic = CreateWindowW(L"input4", L"Nhập hình bán nguyệt", WS_VISIBLE | WS_BORDER | WS_OVERLAPPEDWINDOW | SS_CENTER, 500, 250, 400, 430, NULL, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Nhập bán kính,hướng và tọa độ tâm ", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 10, 290, 20, hInputsemic, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Bán kính và hướng T(trên),R(Phải),B(Dưới),L(Trái)", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 40, 290, 40, hInputsemic, NULL, NULL, NULL);
    hR = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 90, 140, 20, hInputsemic, NULL, NULL, NULL);
    hDSemic = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 200, 90, 140, 20, hInputsemic, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ x tâm:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 120, 290, 20, hInputsemic, NULL, NULL, NULL);
    hPointxA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 150, 290, 20, hInputsemic, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ y tâm:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 180, 290, 20, hInputsemic, NULL, NULL, NULL);
    hPointyA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 210, 290, 20, hInputsemic, NULL, NULL, NULL);
    hOut = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 250, 290, 50, hInputsemic, NULL, NULL, NULL);
    CreateWindowW(L"button", L"Kết quả", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 330, 140, 40, hInputsemic, (HMENU)BUTTON_CHECK, NULL, NULL);
    CreateWindowW(L"button", L"Thoát", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 330, 140, 40, hInputsemic, (HMENU)BUTTON_END, NULL, NULL);
}

void winInputrectangle(HWND hWnd)
{
    hInputrectangle = CreateWindowW(L"input5", L"Nhập vẽ hình chữ nhập", WS_VISIBLE | WS_BORDER | WS_OVERLAPPEDWINDOW | SS_CENTER, 500, 250, 400, 400, NULL, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Nhập 2 điểm", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 10, 290, 20, hInputrectangle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Điểm thứ nhất A(x,y)", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 40, 140, 20, hInputrectangle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Điểm thứ hai B(x,y)", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 40, 140, 20, hInputrectangle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ xA:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 70, 140, 20, hInputrectangle, NULL, NULL, NULL);
    hPointxA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 100, 140, 20, hInputrectangle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ yA:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 130, 140, 20, hInputrectangle, NULL, NULL, NULL);
    hPointyA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 160, 140, 20, hInputrectangle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ xB:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 70, 140, 20, hInputrectangle, NULL, NULL, NULL);
    hPointxB = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 200, 100, 140, 20, hInputrectangle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ yB:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 130, 140, 20, hInputrectangle, NULL, NULL, NULL);
    hPointyB = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 200, 160, 140, 20, hInputrectangle, NULL, NULL, NULL);
    hOut = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 210, 290, 50, hInputrectangle, NULL, NULL, NULL);
    CreateWindowW(L"button", L"Kết quả", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 310, 140, 40, hInputrectangle, (HMENU)BUTTON_CHECK, NULL, NULL);
    CreateWindowW(L"button", L"Thoát", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 310, 140, 40, hInputrectangle, (HMENU)BUTTON_END, NULL, NULL);
}

void winInputsquare(HWND hWnd)
{
    hInputsquare = CreateWindowW(L"input6", L"Nhập hình vuông", WS_VISIBLE | WS_BORDER | WS_OVERLAPPEDWINDOW | SS_CENTER, 500, 250, 400, 400, NULL, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Nhập độ dài cạnh và 1 điểm ", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 10, 290, 20, hInputsquare, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Độ dài cạnh", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 40, 290, 20, hInputsquare, NULL, NULL, NULL);
    hR = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 70, 290, 20, hInputsquare, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ x :", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 100, 290, 20, hInputsquare, NULL, NULL, NULL);
    hPointxA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 130, 290, 20, hInputsquare, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ y :", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 160, 290, 20, hInputsquare, NULL, NULL, NULL);
    hPointyA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 190, 290, 20, hInputsquare, NULL, NULL, NULL);
    hOut = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 230, 290, 50, hInputsquare, NULL, NULL, NULL);
    CreateWindowW(L"button", L"Kết quả", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 310, 140, 40, hInputsquare, (HMENU)BUTTON_CHECK, NULL, NULL);
    CreateWindowW(L"button", L"Thoát", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 310, 140, 40, hInputsquare, (HMENU)BUTTON_END, NULL, NULL);
}

void winInputtriangle(HWND hWnd)
{
    hInputtriangle = CreateWindowW(L"input7", L"Nhập vẽ tam giác", WS_VISIBLE | WS_BORDER | WS_OVERLAPPEDWINDOW | SS_CENTER, 500, 220, 400, 480, NULL, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Nhập 3 điểm tọa độ ", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 10, 290, 20, hInputtriangle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Điểm thứ nhất A(x,y)", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 40, 140, 20, hInputtriangle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Điểm thứ hai B(x,y)", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 40, 140, 20, hInputtriangle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ xA:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 70, 140, 20, hInputtriangle, NULL, NULL, NULL);
    hPointxA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 100, 140, 20, hInputtriangle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ yA:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 130, 140, 20, hInputtriangle, NULL, NULL, NULL);
    hPointyA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 160, 140, 20, hInputtriangle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ xB:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 70, 140, 20, hInputtriangle, NULL, NULL, NULL);
    hPointxB = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 200, 100, 140, 20, hInputtriangle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ yB:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 130, 140, 20, hInputtriangle, NULL, NULL, NULL);
    hPointyB = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 200, 160, 140, 20, hInputtriangle, NULL, NULL, NULL);  
    CreateWindowW(L"static", L"Điểm thứ ba C(x,y)", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 190, 290, 20, hInputtriangle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ xC:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 220, 140, 20, hInputtriangle, NULL, NULL, NULL);
    hPointxC = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 250, 140, 20, hInputtriangle, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ yC:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 220, 140, 20, hInputtriangle, NULL, NULL, NULL);
    hPointyC = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 200, 250, 140, 20, hInputtriangle, NULL, NULL, NULL);
    hOut = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 280, 290, 50, hInputtriangle, NULL, NULL, NULL);
    CreateWindowW(L"button", L"Kết quả", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 340, 140, 40, hInputtriangle, (HMENU)BUTTON_CHECK, NULL, NULL);
    CreateWindowW(L"button", L"Thoát", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 340, 140, 40, hInputtriangle, (HMENU)BUTTON_END, NULL, NULL);
}

void winInputpolygon(HWND hWnd) {

    hInputpolygon = CreateWindowW(L"input8", L"Nhập vẽ đa giác n đỉnh", WS_VISIBLE | WS_BORDER | WS_OVERLAPPEDWINDOW | SS_CENTER, 500, 220, 400, 260, NULL, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Nhập số đỉnh n :", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 10, 290, 20, hInputpolygon, NULL, NULL, NULL);
    hN = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 40, 290, 20, hInputpolygon, NULL, NULL, NULL);
    hOut = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 70, 290, 50, hInputpolygon, NULL, NULL, NULL);
    CreateWindowW(L"button", L"Kết quả", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 130, 140, 40, hInputpolygon, (HMENU)BUTTON_CHECK, NULL, NULL);
    CreateWindowW(L"button", L"Thoát", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 130, 140, 40, hInputpolygon, (HMENU)BUTTON_END, NULL, NULL);
}

void winInputpolygon2(HWND hWnd) {

    hInputpolygon2 = CreateWindowW(L"input9", L"Nhập tọa độ đỉnh", WS_VISIBLE | WS_BORDER | WS_OVERLAPPEDWINDOW | SS_CENTER, 500, 220, 400, 320, NULL, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Nhập tọa độ đỉnh :", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 10, 290, 20, hInputpolygon2, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ x:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 40, 290, 20, hInputpolygon2, NULL, NULL, NULL);
    hPointxA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 70, 290, 20, hInputpolygon2, NULL, NULL, NULL);
    CreateWindowW(L"static", L"Tọa độ y:", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 100, 290, 20, hInputpolygon2, NULL, NULL, NULL);
    hPointyA = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 50, 130, 290, 20, hInputpolygon2, NULL, NULL, NULL);
    hOut2 = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 160, 290, 50, hInputpolygon2, NULL, NULL, NULL);
    CreateWindowW(L"button", L"Kết quả", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 50, 220, 140, 40, hInputpolygon2, (HMENU)BUTTON_CHECK, NULL, NULL);
    CreateWindowW(L"button", L"Thoát", WS_VISIBLE | WS_BORDER | WS_CHILD | SS_CENTER, 200, 220, 140, 40, hInputpolygon2, (HMENU)BUTTON_END, NULL, NULL);
}

void addMenus(HWND hWnd)
{
    hMenu = CreateMenu();
    HMENU hFileMenu = CreateMenu();
    HMENU hSubMenu = CreateMenu(); // Chon hinh co san
    HMENU hSubMenu2 = CreateMenu(); // Nhap hinh
    HMENU hSubMenu3 = CreateMenu(); // Duong thang 
    HMENU hPaintMenu = CreateMenu(); // menu ve

    AppendMenu(hPaintMenu, MF_STRING, FILE_MENU_PAINT, L"Cập nhật màn hình");
    AppendMenu(hPaintMenu, MF_POPUP, (UINT_PTR)hSubMenu, L"Chọn các hình vẽ có sẵn");
    AppendMenu(hPaintMenu, MF_POPUP, (UINT_PTR)hSubMenu2, L"Nhập các hình vẽ");
    AppendMenu(hPaintMenu, MF_POPUP, (UINT_PTR)hSubMenu3, L"Vẽ đường thẳng");
    AppendMenu(hSubMenu3, MF_POPUP, CHOOSE_PAINT_DT, L"Vẽ đường thẳng có sẵn");
    AppendMenu(hSubMenu3, MF_POPUP, INPUT_PAINT_DT, L"Nhập đường thẳng");
    AppendMenu(hSubMenu, MF_STRING, CHOOSE_PAINT_TRON, L"Hình Tròn");
    AppendMenu(hSubMenu, MF_STRING, CHOOSE_PAINT_ELLIPSE, L"Hình Ellipse");
    AppendMenu(hSubMenu, MF_STRING, CHOOSE_PAINT_BANNGUYET, L"Hình Bán Nguyệt");
    AppendMenu(hSubMenu, MF_STRING, CHOOSE_PAINT_DAGIAC, L"Hình Đa Giác (Lồi)");
    AppendMenu(hSubMenu, MF_STRING, CHOOSE_PAINT_CN, L"Hình Chữ Nhật");
    AppendMenu(hSubMenu, MF_STRING, CHOOSE_PAINT_VUONG, L"Hình Vuông");
    AppendMenu(hSubMenu, MF_STRING, CHOOSE_PAINT_TG, L"Hình Tam Giác");
    AppendMenu(hSubMenu2, MF_STRING, INPUT_PAINT_TRON, L"Hình Tròn");
    AppendMenu(hSubMenu2, MF_STRING, INPUT_PAINT_ELLIPSE, L"Hình Ellipse");
    AppendMenu(hSubMenu2, MF_STRING, INPUT_PAINT_BANNGUYET, L"Hình Bán Nguyệt");
    AppendMenu(hSubMenu2, MF_STRING, INPUT_PAINT_DAGIAC, L"Hình Đa Giác (Lồi)");
    AppendMenu(hSubMenu2, MF_STRING, INPUT_PAINT_CN, L"Hình Chữ Nhật");
    AppendMenu(hSubMenu2, MF_STRING, INPUT_PAINT_VUONG, L"Hình Vuông");
    AppendMenu(hSubMenu2, MF_STRING, INPUT_PAINT_TG, L"Hình Tam Giác");
    AppendMenu(hFileMenu, MF_STRING, FILE_MENU_NEW,L"Mới");  
    AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, L"Thoát");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, L"Tùy Chọn");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hPaintMenu,L"Vẽ Hình"); 
    AppendMenu(hMenu, MF_POPUP, FILE_MENU_HELP, L"Thông Tin");
    SetMenu(hWnd, hMenu);
}

void loadPicture()
{
    hKhang = (HBITMAP)LoadImageW(NULL, L"khang.bmp", IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
    hLinh = (HBITMAP)LoadImageW(NULL, L"linh.bmp", IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
}

void winAbout(HWND hWnd) {
   hAbout=CreateWindowW(L"input2", L"Thông tin", WS_VISIBLE | WS_BORDER | WS_OVERLAPPEDWINDOW, 500, 250, 405, 430, NULL, NULL, NULL, NULL);
   CreateWindowW(L"static",L"Bài tập lớn OOP 20KDL1", WS_VISIBLE | WS_CHILD |SS_CENTER , 50, 10, 290, 20, hAbout, NULL, NULL, NULL);
   CreateWindowW(L"static", L"Giảng Viên: Nguyễn Ngọc Long", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 40, 290, 20, hAbout, NULL, NULL, NULL);
   CreateWindowW(L"static", L"Thành Viên Nhóm ", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 70, 290, 20, hAbout, NULL, NULL, NULL);
   hPicture1 = CreateWindowW(L"static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 70, 100, 100, 100, hAbout, NULL, NULL,NULL);
   hPicture2 = CreateWindowW(L"static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 230, 100, 100, 100, hAbout, NULL, NULL, NULL);
   CreateWindowW(L"static", L"Huỳnh Bảo Khang 20280050", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 210, 140, 40, hAbout, NULL, NULL, NULL);
   CreateWindowW(L"static", L"Đặng Yến Linh 20280058", WS_VISIBLE | WS_CHILD | SS_CENTER, 210, 210, 130, 40, hAbout, NULL, NULL, NULL);
   CreateWindowW(L"static", L"\nTrường Đại học Khoa học Tự nhiên ĐHQG-HCM \n Phiên bản 1.1 \nNgày phát hành 14/06/2022", WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 270, 290, 100, hAbout, NULL, NULL, NULL);
   SendMessageW(hPicture1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hKhang);
   SendMessageW(hPicture2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hLinh);
}

// cac ham phuc nhap tao do cac hinh

LRESULT CALLBACK WndProc2(HWND hInputline, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int check = 0;
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {  
        case BUTTON_CHECK:  
            char xA[30], yA[30], xB[30], yB[30],out[200];
            GetWindowTextA(hPointxA, xA,30);
            GetWindowTextA(hPointyA, yA, 30);
            GetWindowTextA(hPointxB, xB, 30);
            GetWindowTextA(hPointyB, yB, 30);
            GetWindowTextA(hOut, out, 200);
            if (isNumber(xA) == true && isNumber(yA) == true && isNumber(xB) == true && isNumber(yB) == true)
            {
                pxA = atof(xA);
                pyA = atof(yA);
                pxB = atof(xB);
                pyB = atof(yB);
                out[0] = '\0';
                l.Set(pxA,pyA,pxB,pyB);
                Count = 1;
                strcat(out, "A(");
                strcat(out, xA);
                strcat(out, ",");
                strcat(out, yA);
                strcat(out, ");");
                strcat(out, "B(");
                strcat(out, xB);
                strcat(out, ",");
                strcat(out, yB);
                strcat(out, ");");
                SetWindowTextA(hOut, out);
                checkDT = 1;
                InvalidateRect(hWnd, NULL, TRUE);
                break;
            }
            else
            {
                SetWindowTextA(hOut, "Khong hop le hay nhap lai");
                break;
            }
        case BUTTON_END:
            DestroyWindow(hInputline);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        default:
            return DefWindowProc(hInputline, message, wParam, lParam);
        }
    }
    break;
    case WM_DESTROY:
        DestroyWindow(hInputline);
        break;
    case WM_KEYDOWN:
        break;
    default:
        return DefWindowProc(hInputline, message, wParam, lParam);
    }
    return 0;
 }

LRESULT CALLBACK WndProc3(HWND hInputcircle, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case BUTTON_CHECK:
            char xA[30], yA[30], R[30], out[90];
            GetWindowTextA(hPointxA, xA, 30);
            GetWindowTextA(hPointyA, yA, 30);
            GetWindowTextA(hR, R, 30);
            GetWindowTextA(hOut, out, 90);
            if (isNumber(xA) == true && isNumber(yA) == true && isNumber(R) == true )
            {
                pxA = atof(xA);
                pyA = atof(yA);
                pR1 = atof(R);
                c.Set(pxA, pyA, pR1,0);
                Count = 1;
                out[0] = '\0';
                strcat(out, "I(");
                strcat(out, xA);
                strcat(out, ",");
                strcat(out, yA);
                strcat(out, ");");
                strcat(out, " Ban Kinh: ");
                strcat(out, R);
                SetWindowTextA(hOut, out);
                temp->Set(c.GetT().GetX(), c.GetT().GetY(), c.Getr(), 0);
                ds_hinh.push_back(temp);
                InvalidateRect(hWnd, NULL, TRUE);
            }
            else
            {
                SetWindowTextA(hOut, "Khong hop le hay nhap lai");
                break;
            }
            break;
            break;
        case BUTTON_END:
            DestroyWindow(hInputcircle);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        default:
            return DefWindowProc(hInputcircle, message, wParam, lParam);
        }
    }
    break;
    case WM_DESTROY:
        DestroyWindow(hInputcircle);
        break;
    default:
        return DefWindowProc(hInputcircle, message, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK WndProc4(HWND hInputellipse, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case BUTTON_CHECK:
            char xA[30], yA[30], R1[30],R2[30], out[90];
            GetWindowTextA(hPointxA, xA, 30);
            GetWindowTextA(hPointyA, yA, 30);
            GetWindowTextA(hR, R1, 30);
            GetWindowTextA(hR2, R2, 30);
            GetWindowTextA(hOut, out, 90);
            if (isNumber(xA) == true && isNumber(yA) == true && isNumber(R1) == true && isNumber(R2) == true)
            {
                pxA = atof(xA);
                pyA = atof(yA);
                pR1 = atof(R1);
                pR2 = atof(R2);
                out[0] = '\0';
                e.Set(pxA, pyA, pR1, pR2);
                Count = 1;
                strcat(out, "I(");
                strcat(out, xA);
                strcat(out, ",");
                strcat(out, yA);
                strcat(out, ");");
                strcat(out, " Truc 1: ");
                strcat(out, R1);
                strcat(out, ", Truc 2: ");
                strcat(out, R2);
                SetWindowTextA(hOut, out);
                temp->Set(e.GetT().GetX(), e.GetT().GetY(), e.Getr1(), e.Getr2());
                ds_hinh.push_back(temp);
                InvalidateRect(hWnd, NULL, TRUE);
            }
            else
            {
                SetWindowTextA(hOut, "Khong hop le hay nhap lai");
                break;
            }

            break;
        case BUTTON_END:
            DestroyWindow(hInputellipse);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        default:
            return DefWindowProc(hInputellipse, message, wParam, lParam);
        }
    }
    break;
    case WM_DESTROY:
        DestroyWindow(hInputellipse);
        break;
    default:
        return DefWindowProc(hInputellipse, message, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK WndProc5(HWND hInputsemic, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case BUTTON_CHECK:
            char xA[30], yA[30], R[30],Dr[30], out[90];
            GetWindowTextA(hPointxA, xA, 30);
            GetWindowTextA(hPointyA, yA, 30);
            GetWindowTextA(hR, R, 30);
            GetWindowTextA(hDSemic, Dr, 30);
            GetWindowTextA(hOut, out, 90);
            if (isNumber(xA) == true && isNumber(yA) == true && isNumber(R) == true && directionSemic(Dr)==true)
            {
                pxA = atof(xA);
                pyA = atof(yA);
                pR1 = atof(R);
                int k = findDirectionsemic(Dr);
                bn.Set(k, pxA, pyA, pR1);
                out[0] = '\0';
                strcat(out, "I(");
                strcat(out, xA);
                strcat(out, ",");
                strcat(out, yA);
                strcat(out, ");");
                strcat(out, " Ban Kinh: ");
                strcat(out, R);
                strcat(out, ", Huong: ");
                strcat(out, Dr);
                SetWindowTextA(hOut, out);
                Count = 1;
                temp->Set(bn.getStyle(), bn.getPoint().GetX(), bn.getPoint().GetY(), bn.getr());
                ds_hinh.push_back(temp);
                InvalidateRect(hWnd, NULL, TRUE);
                
            }
            else
            {
                SetWindowTextA(hOut, "Khong hop le hay nhap lai");
                break;
            }
            
            break;
            break;
        case BUTTON_END:
            DestroyWindow(hInputsemic);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        default:
            return DefWindowProc(hInputsemic, message, wParam, lParam);
        }
    }
    break;
    case WM_DESTROY:
        DestroyWindow(hInputsemic);
        break;
    default:
        return DefWindowProc(hInputsemic, message, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK WndProc6(HWND hInputrectangle, UINT message, WPARAM wParam, LPARAM lParam)
{
    double temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case BUTTON_CHECK:
            char xA[30], yA[30], xB[30], yB[30], out[90];
            GetWindowTextA(hPointxA, xA, 30);
            GetWindowTextA(hPointyA, yA, 30);
            GetWindowTextA(hPointxB, xB, 30);
            GetWindowTextA(hPointyB, yB, 30);
            GetWindowTextA(hOut, out, 90);
            if (isNumber(xA) == true && isNumber(yA) == true && isNumber(xB) == true && isNumber(yB) == true)
            {
                pxA = atof(xA);
                pyA = atof(yA);
                pxB = atof(xB);
                pyB = atof(yB);
                if (checkPointrectangle(pxA, pyA, pxB, pyB) == true)
                {
                    findPointRectangle(pxA, pyA, pxB, pyB, temp1, temp2, temp3, temp4);
                    ptsCN[0].Set(pxA, pyA);
                    ptsCN[1].Set(temp1, temp2);
                    ptsCN[2].Set(pxB, pyB);
                    ptsCN[3].Set(temp3, temp4);
                    out[0] = '\0';
                    Count = 1;
                    strcat(out, "A(");
                    strcat(out, xA);
                    strcat(out, ",");
                    strcat(out, yA);
                    strcat(out, ");");
                    strcat(out, "B(");
                    strcat(out, xB);
                    strcat(out, ",");
                    strcat(out, yB);
                    strcat(out, ");");
                    SetWindowTextA(hOut, out);
                    temp->Set(4, 0, 0, 0);
                    temp->SetPoint(ptsCN);
                    ds_hinh.push_back(temp);
                    InvalidateRect(hWnd, NULL, TRUE);
                }
                else
                {
                    SetWindowTextA(hOut, "Khong tao thanh hinh chu nhat hay nhap lai");
                    break;
                }

            }
            else
            {
                SetWindowTextA(hOut, "Khong hop le hay nhap lai");
                break;
            }
           
            break;
        case BUTTON_END:
            DestroyWindow(hInputrectangle);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        default:
            return DefWindowProc(hInputrectangle, message, wParam, lParam);
        }
    }
    break;
    case WM_DESTROY:
        DestroyWindow(hInputrectangle);
        break;
    default:
        return DefWindowProc(hInputrectangle, message, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK WndProc7(HWND hInputsquare, UINT message, WPARAM wParam, LPARAM lParam)
{
    double temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0, temp5 = 0, temp6 = 0;
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case BUTTON_CHECK:
            char xA[30], yA[30], h[30], out[90];
            GetWindowTextA(hPointxA, xA, 30);
            GetWindowTextA(hPointyA, yA, 30);
            GetWindowTextA(hR, h, 30);
            GetWindowTextA(hOut, out, 90);

            if (isNumber(xA) == true && isNumber(yA) == true && isNumber(h) == true)
            {
                pxA = atof(xA);
                pyA = atof(yA);
                pR1 = atof(h);
                findPointsquare(pxA, pyA,pR1, temp1, temp2, temp3, temp4,temp5,temp6);
                ptsV[0].Set(pxA, pyA);
                ptsV[1].Set(temp1, temp2);
                ptsV[2].Set(temp3, temp4);
                ptsV[3].Set(temp5, temp6);
                out[0] = '\0';
                strcat(out, "A(");
                strcat(out, xA);
                strcat(out, ",");
                strcat(out, yA);
                strcat(out, ");");
                strcat(out, " Do dai canh: ");
                strcat(out, h);
                SetWindowTextA(hOut, out);
                Count = 1;
                temp->Set(4, 0, 0, 0);
                temp->SetPoint(ptsV);
                ds_hinh.push_back(temp);
                InvalidateRect(hWnd, NULL, TRUE);
            }
            else
            {
                SetWindowTextA(hOut, "Khong hop le nhap lai");
                break;
            }
            break;
            break;
        case BUTTON_END:
            DestroyWindow(hInputsquare);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        default:
            return DefWindowProc(hInputsquare, message, wParam, lParam);
        }
    }
    break;
    case WM_DESTROY:
        DestroyWindow(hInputsquare);
        break;
    default:
        return DefWindowProc(hInputsquare, message, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK WndProc8(HWND hInputtriangle, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case BUTTON_CHECK:
            char xA[30], yA[30],xB[30],yB[30], xC[30], yC[30], out[200];
            GetWindowTextA(hPointxA, xA, 30);
            GetWindowTextA(hPointyA, yA, 30);
            GetWindowTextA(hPointxB, xB, 30);
            GetWindowTextA(hPointyB, yB, 30);
            GetWindowTextA(hPointxC, xC, 30);
            GetWindowTextA(hPointyC, yC, 30);
            GetWindowTextA(hOut, out, 200);

            if (isNumber(xA) == true && isNumber(yA) == true && isNumber(xB) == true && isNumber(yB) == true && isNumber(xC) == true && isNumber(yC) == true)
            {
                pxA = atof(xA);
                pyA = atof(yA);
                pxB = atof(xB);
                pyB = atof(yB);
                pxC = atof(xC);
                pyC = atof(yC);
                if (checkPointtriangle(pxA, pyA, pxB, pyB,pxC,pyC) == true)
                {
                    ptsTG[0].Set(pxA, pyA);
                    ptsTG[1].Set(pxB, pyB);
                    ptsTG[2].Set(pxC, pyC);
                    out[0] = '\0';
                    Count = 1;
                    strcat(out, "A(");
                    strcat(out, xA);
                    strcat(out, ",");
                    strcat(out, yA);
                    strcat(out, ");");
                    strcat(out, "B(");
                    strcat(out, xB);
                    strcat(out, ",");
                    strcat(out, yB);
                    strcat(out, ");");
                    strcat(out, "C(");
                    strcat(out, xC);
                    strcat(out, ",");
                    strcat(out, yC);
                    strcat(out, ");");
                    SetWindowTextA(hOut, out);
                    temp->Set(3, 0, 0, 0);
                    temp->SetPoint(ptsTG);
                    ds_hinh.push_back(temp);
                    InvalidateRect(hWnd, NULL, TRUE);
                }
                else
                {
                    SetWindowTextA(hOut, "Khong tao thanh hinh tam giac hay nhap lai");
                    break;
                }
            }
            else
            {
                SetWindowTextA(hOut, "Khong hop le nhap lai");
                break;
            }
            
            break;
            break;
        case BUTTON_END:
            DestroyWindow(hInputtriangle);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        default:
            return DefWindowProc(hInputtriangle, message, wParam, lParam);
        }
    }
    break;
    case WM_DESTROY:
        DestroyWindow(hInputtriangle);
        break;
    default:
        return DefWindowProc(hInputtriangle, message, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK WndProc9(HWND hInputpolygon, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case BUTTON_CHECK:
            char xA[30], yA[30],nn[10], out[200];
            GetWindowTextA(hN, nn, 10);
            GetWindowTextA(hOut, out, 200);

            if (isNumberint(nn) == true)
            {
                countN = (int)(atof(nn));
                if (countN <= 2)
                {
                    SetWindowTextA(hOut, "Da giac khong hop le hay nhap lai");
                    break;
                }

                for (int i = 0; i < sizeof(pts1) / sizeof(Point); i++)
                {
                    pts1[i] = NULL;
                }
             
                D.Set(countN,0,0,0);
                winInputpolygon2(hInputpolygon);
            }
            else
            {
                SetWindowTextA(hOut, "Khong hop le nhap lai");
                break;
            }
            strcat(out, "So dinh: ");
            strcat(out, nn);
            SetWindowTextA(hOut, out);
            break;
            break;
        case BUTTON_END:
            break;
        default:
            return DefWindowProc(hInputpolygon, message, wParam, lParam);
        }
    }
    break;
    case WM_DESTROY:
        DestroyWindow(hInputpolygon);
        break;
    default:
        return DefWindowProc(hInputpolygon, message, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK WndProc10(HWND hInputpolygon2, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case BUTTON_CHECK:
            char xA[30], yA[30], out[90];
            GetWindowTextA(hPointxA, xA, 30);
            GetWindowTextA(hPointyA, yA, 30);
            SetWindowTextA(hOut2, "");
            GetWindowTextA(hOut2,out, 90);

            if (isNumber(xA) == true && isNumber(yA) == true )
            {
                pxA = atof(xA);
                pyA = atof(yA);
                strcat(out, "Point ");
                char* a = new char;
                _itoa((tempd + 1), a, countN);
                strcat(out, a);
                strcat(out, " (");
                strcat(out, xA);
                strcat(out, ",");
                strcat(out, yA);
                strcat(out, ");");
                SetWindowTextA(hOut2, out);
                if (tempd < countN)
                {
                    pts1[tempd].Set(pxA, pyA);
                    tempd++;
                };
                if (tempd >= countN)
                {
                    ShapePolygon k(countN, pts1);
                    if (k.checkConvexpolygon() == 1)
                    {
                        checkInputpolygon = 1;
                        DestroyWindow(hInputpolygon2);
                        DestroyWindow(hInputpolygon);
                        Count = 1;
                        tempd = 0;
                        temp->Set(countN, 0, 0, 0);
                        temp->SetPoint(pts1);

                        ds_hinh.push_back(temp);
                        InvalidateRect(hWnd, NULL, TRUE);
                        break;
                    }
                    else
                    {
                        SetWindowTextA(hOut2, "Khong phai da giac loi hay nhap lai");
                        out[0] = '\0';
                        tempd = 0;
                        break;
                    }
                };


            }
            else
            {
                SetWindowTextA(hOut2, "Khong hop le hay nhap lai");
                out[0] = '\0';
                break;
            }
       
            break;
            break;
        case BUTTON_END:
            DestroyWindow(hInputpolygon2);
            break;
        default:
            return DefWindowProc(hInputpolygon2, message, wParam, lParam);
        }
    }
    break;
    case WM_DESTROY:
        DestroyWindow(hInputpolygon2);
        break;
    default:
        return DefWindowProc(hInputpolygon2, message, wParam, lParam);
    }
    return 0;
}




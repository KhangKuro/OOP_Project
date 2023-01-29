#include "Functions.h"
#include"framework.h"

bool isNumber(char* c) //Kiem tra nhap vao co la 1 so hop le hay khong
{
    int count = 0;//kiem tra dau '.'
    if (strlen(c) == 0)
        return false;
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] == 46)
            count++;
        else if (c[i] < 48 || c[i] > 57)
            return false;
        if (count >= 2)
            return false;
    }
    return true;
}

bool isNumberint(char* c) // kiem tra nhap vao co la mot so nguyen hop le hay khong
{
    if (strlen(c) == 0)
        return false;
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] < 48 || c[i] > 57)
            return false;
    }
    return true;
}

bool directionSemic(char* c) // kiem tra nhap huong cua hinh ban nguyet dung hay khong
{
    if (strlen(c) != 1)
        return false;
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i]==76||c[i]==108|| c[i] == 114 || c[i] == 116 || c[i] == 98 || c[i] == 82 || c[i] == 84 || c[i] == 66)
            return true;
    }
    return false;
}


// Tim 4 diem tu 2 diem khi nhap hinh chu nhat
void findPointRectangle(double pxA, double pyA, double pxB, double pyB, double& pxC, double& pyC, double& pxD, double& pyD)
{
    if (pxA < pxB)
    {
        if (pyA < pyB)
        {
            
            pxC = pxA;
            pyC = pyB;
            pxD = pxB;
            pyD = pyA;
            
        }
        else if(pyA > pyB)
        {
            pxC = pxB;
            pyC = pyA;
            pxD = pxA;
            pyD = pyB;
        }
    }
    else if(pxA > pxB)
    {
        if (pyA < pyB)
        {
            pxC = pxB;
            pyC = pyA;
            pxD = pxA;
            pyD = pyB;

        }
        else if (pyA > pyB)
        {
            pxC = pxA;
            pyC = pyB;
            pxD = pxB;
            pyD = pyA;
            
        }
    }
}


//Tim 4 diem hinh vuong
void findPointsquare(double pxA, double pyA,double h, double& pxB, double& pyB, double& pxC, double& pyC, double& pxD, double& pyD)
{
    pxB = pxA;
    pyB = pyA+h;
    pxC = pxB+h;
    pxD = pxA+h;
    pyD = pyA;
    pyC = pyB;
}

//Tim cac diem cua hinh ban nguyet
void findPointsemic(int _kieu,double xT,double yT,double r, double& pxA, double& pyA, double& pxB, double& pyB, double& pxC, double& pyC, double& pxD, double& pyD)
{
    if (_kieu == 1)
    {
        pxA = xT - r;
        pyA = yT - r;
        pxB = xT + r;
        pyB = yT + r;
        pxC = xT;
        pyC = pyA;
        pxD = xT;
        pyD = pyB;
    }
    else if (_kieu == 2)
    {
        pxA = xT - r;
        pyA = yT - r;
        pxB = xT + r;
        pyB = yT + r;
        pxD = xT;
        pyD = pyA;
        pxC = xT;
        pyC = pyB;
    }
    else if (_kieu == 3)
    {
        pxA = xT - r;
        pyA = yT - r;
        pxB = xT + r;
        pyB = yT + r;
        pxC = pxA;
        pyC = yT;
        pxD = pxB;
        pyD = yT;
    }
    else if (_kieu == 4)
    {
        pxA = xT - r;
        pyA = yT - r;
        pxB = xT + r;
        pyB = yT + r;
        pxD = pxA;
        pyD = yT;
        pxC = pxB;
        pyC = yT;
    }
}

// Tra ve gia tri huong cua hinh ban nguyet  1: left, 2: right, 3: bottom , 4: top

int findDirectionsemic(char* c)
{
    switch (c[0])
    {
    case 76:
        return 1;
    case 108:
        return 1;
    case 84:
        return 4;
    case 116:
        return 4;
    case 66:
        return 3;
    case 98:
        return 3;
    case 82:
        return 2;
    case 114:
        return 2;
    default:
        break;
    }
    return -1;
}

// Kiem tra 2 diem hinh chu nhat co nam tren 1 duong thang

bool checkPointrectangle(double pxA, double pyA, double pxB, double pyB)
{
    if (pxA == pxB || pyB == pyA)
    {
        return false;
    }
    return true;
}

// Kiem tra 3 diem tam giac thang hang khong

bool checkPointtriangle(double pxA, double pyA, double pxB, double pyB, double pxC, double pyC)
{
    double temp1 = (pyC - pyA)*(pxB - pxA);
    double temp2 = (pxC - pxA)*(pyB - pyA);
    if (temp1 == temp2)
    {
        return false;
    }
    return true;
}


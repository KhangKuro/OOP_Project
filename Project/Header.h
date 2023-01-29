#pragma once
#include"framework.h"

//Dinh nghia cau truc duong thang ax + by + c = 0
struct pt { double a, b, c; };


//Dinh nghia lop diem
class Point
{
	double x, y;
public:
	Point(double xx = 0, double yy = 0) :x(xx), y(yy) {} // Khoi tao sao chep
	double GetX() const { return x; } // Lay hoanh do
	double GetY() const { return y; } // Lay tung do
	void Set(double xx, double yy) { x = xx; y = yy; } // Thay do gia tri diem
};

///////////////////////////////////////////////////////////////
//Dinh nghia lop Hinh
class Shape
{
private:
public:
    virtual void draw(HDC hdc) const = 0; // Dung da hinh ham ve
    virtual int Check(pt d) = 0; // Dung da hinh ham kiem tra duong thang cat cac hinh hay khong
    virtual void Set(double xa, double ya, double xb, double yb) = 0; // truyen 4 gia tri de thay doi gia tri trong cac hinh
    virtual void SetPoint(Point* d) 
    {
    ShapePolygon:SetPoint(d);
    }; // Thay doi gia tri mang diem da giac
};

vector<Shape*> ds_hinh; // Vector chu cac hinh da nhap

//Dinh nghia lop duong thang
class Line
{
	Point A, B;
public:
	Line(double xa=0,double ya=0,double xb=0,double yb=0): A(xa, ya), B(xb, yb) {};
	~Line(){};
	void draw(HDC hdc) const
	{
		MoveToEx(hdc,(int)A.GetX(),(int)A.GetY(), NULL);
		LineTo(hdc,(int)B.GetX(),(int)B.GetY());
	};
	Point GetA() const { return A; }
	Point GetB() const { return B; }
	void Set(double xa , double ya , double xb , double yb ) { A.Set(xa,ya); B.Set(xb,yb); }
};

///////////////////////////////////////////////////////////////
//Dinh nghia lop hinh ellipse
class ShapeEllipse:public Shape
{
	Point T;
	double r1, r2;
public:
	ShapeEllipse(double tx=0, double ty=0, double aa=0, double bb=0) :T(tx, ty), r1(aa), r2(bb) {}
	void draw(HDC hdc) const;
	int Check(pt d);
	void Set(double Tx,double Ty, double rr1, double rr2) { T.Set(Tx,Ty); r1 = rr1; r2 = rr2; }
	double Getr1() const { return r1; } // Lay do dai ban kinh truc 1
	double Getr2() const { return r2; } // Lay do dai ban kinh truc 2
	Point GetT() const { return T; } // Lay toa do tam
};

void ShapeEllipse::draw(HDC hdc) const 
{
	Ellipse(hdc, (int)(T.GetX() - r1), (int)(T.GetY() - r2), (int)(T.GetX() + r1),(int)( T.GetY() + r2));// Dung ham co san de ve hinh ellipse
}

//Giai phuong trinh bac 2
int solveEquation(double a, double b, double c, double& x1, double& x2) {  // a,b ,c la he so cua phuong trinh bac 2
	double delta = b * b - 4 * a * c;
	if (delta < 0) {
		x1 = x2 = 0.0;
		return 0;
	}
	else if (delta == 0) {
		x1 = x2 = -b / (2 * a);
		return 1;
	}
	else {
		delta = sqrt(delta);
		x1 = (-b + delta) / (2 * a);
		x2 = (-b - delta) / (2 * a);
		return 2;
	}
}

int ShapeEllipse::Check(pt d) {

    //Tu phuong trinh ellipse va phuong trinh duong thang d, ta tim duoc 1 phuong trinh bac 2 theo an y
	double x1, x2, x3; // He so cua phuong trinh bac 2 theo an y ta vua giai duoc 
	double x, y; 

    // Toa do tam hinh ellipse
	double x0 = this->T.GetX();
	double y0 = this->T.GetY();

    if (d.a == 0) {
        double  kc_t = abs(-d.c / d.b - y0);
        if (kc_t < r2) {
            return 1;
        }
        else if (kc_t == r2 || kc_t > r2) {
            return 0;
        }

    }

	x1 = pow(d.b * r2 / d.a, 2) + pow(r1,2);     
	x2 = (2 * d.b * d.c * pow(r2 / d.a, 2)) + (2 * x0 * d.b * pow(r2, 2) / d.a) - 2 * pow(r1, 2) * y0;  
	x3 = (2 * x0 * d.c * pow(r2, 2) / d.a) + pow(x0 * r2, 2) + pow(r1 * y0, 2) - pow(r1 * r2, 2) +pow(d.c/d.a*r2,2);

	if (solveEquation(x1, x2, x3, x, y) == 2) {
		cout << x << " " << y;
		return 1;
	}

	if (solveEquation(x1, x2, x3, x, y) == 1) {
		cout << x << " " << y;
		if (abs(this->T.GetY() - y) < this->r2) {
			return 1;
		}
	}
	cout << x << " " << y;
	return 0;
}

///////////////////////////////////////////////////////////////

// Dinh nghia lop hinh tron
class ShapeCircle:public Shape
{
private:
	Point T;
	double r;
public:
	ShapeCircle(double tx = 0, double ty = 0, double rr =0) : T(tx, ty),r(rr) {}
	int Check(pt d);
	void draw(HDC hdc) const;
	void Set(double Tx, double Ty, double rr, double null) { T.Set(Tx, Ty); r = rr;  }
	double Getr() const { return r; }
	Point GetT() const { return T; }
};


//Khoang cach tu tam hinh tron den duong thang d
double distance(pt d, Point h) {
	double result = 0;

	result = abs(d.a * h.GetX() + d.b * h.GetY() + d.c) / sqrt(pow(d.a, 2) + pow(d.b, 2));
	return result;
}

int ShapeCircle::Check(pt d) {
	if (distance(d, this->T) < this->r) {
		return 1;
	}
	return 0;
}

void ShapeCircle::draw(HDC hdc) const
{
	Ellipse(hdc, (int)(T.GetX() - r), (int)(T.GetY() - r), (int)(T.GetX() + r), (int)(T.GetY() + r)); // Dung lai ham ve hinh ellipse de ve hinh tron
}

///////////////////////////////////////////////////////////

// tim he so phuong trinh duong thang di qua 2 diem phan biet AB
pt& pt_assign(pt& pt, int xA, int yA, int xB, int yB)
{
	pt.a = yA - yB;
	pt.b = xB - xA;
	pt.c = xA * yB - xB * yA;
	return pt;
}

/////////////////////////////////////////////////////////
//Dinh nghia lop da giac
class ShapePolygon:public Shape
{
private:
	double n;
	Point* DG; // Mang diem chua cac dinh da giac

public:
	ShapePolygon(int nn = 0, Point* DGG = 0) : n(nn), DG(DGG) {}
	int Check(pt d);
	void draw(HDC hdc) const;
	double Getn() const { return n; }
    void Set(double nn, double null, double null1, double null2) { 
        n = nn;}
    void SetPoint(Point* D) // Thay doi gia tri cac diem 
    {
        int size = (int)((sizeof(D) / sizeof(Point*))*n);
        DG = new Point[size];
        for (int i = 0; i < size; i++)
        {
            DG[i] = D[i];
       }
    }
    int checkConvexpolygon(); // Kiem tra cac dinh co tao thanh da giac loi hay khong
};

void ShapePolygon::draw(HDC hdc) const
{
	POINT* vertices = new POINT[(int)(n)];  // cap phat mang diem
	for (int i = 0; i < n; i++)
	{
		vertices[i].x = (int)(DG[i].GetX());
		vertices[i].y = (int)(DG[i].GetY());
	}
	Polygon(hdc, vertices, int(n));// Dung ham da giac de ve
}

//Tim giao diem cua 2 duong thang 
bool pt_intersection(pt& pt1, pt& pt2, double& x, double& y)
{
	double d = pt1.a * pt2.b - pt2.a * pt1.b;
	double dx = pt2.c * pt1.b - pt1.c * pt2.b;
	double dy = pt2.a * pt1.c - pt1.a * pt2.c;
	if (d != 0)
	{
		x = double(dx) / d;
		y = double(dy) / d;
		return true;
	}
	return false;
}

bool in_range1(double xA, double yA, double xB, double yB, double x, double y)   // kiem tra toa do cua 1 diem co nam trong doan chua toa do cua 2 diem cho truoc
{
	double temp1 = min(xA, xB);
	double temp2 = max(xA, xB);
	double temp3 = min(yA, yB);
	double temp4 = max(yA, yB);

	return (temp1 <= x && x <= temp2) && (temp3 <= y && y <= temp4);
}

bool in_range2(double xA, double yA, double xB, double yB, double x, double y)   // kiem tra toa do cua 1 diem co nam trong khoang chua toa do cua 2 diem cho truoc
{
	double temp1 = min(xA, xB);
	double temp2 = max(xA, xB);
	double temp3 = min(yA, yB);
	double temp4 = max(yA, yB);

	if (yA == yB) {
		return (temp1 < x&& x < temp2) && y == yA;
	}
	else if (xA == xB) {
		return (temp3 < y&& y < temp4) && x == xA;
	}

	else {
		return (temp1 < x&& x < temp2) && (temp3 < y&& y < temp4);
	}

}

// ham kiem tra hai diem co bang nhau hay khong 
bool checkPoint(double xA, double yA, double xB, double yB) {
	return (xA == xB) && (yA == yB);
}

// kiem tra xem hai duong thang co trung nhau hay khong 
bool checkMatch(pt& pt1, pt& pt2) {
    if (pt1.a == 0 && pt2.a == 0) {
        return ((pt1.c / pt2.c) == (pt1.b / pt2.b));
    }
    if (pt1.b == 0 && pt2.b == 0) {
        return ((pt1.c / pt2.c) == (pt1.a / pt2.a));
    }
    if (pt1.c == 0 && pt2.c == 0) {
        return ((pt1.a / pt2.a) == (pt1.b / pt2.b));
    }
    return ((pt1.a / pt2.a) == (pt1.b / pt2.b)) && ((pt1.a / pt2.a) == (pt1.c / pt2.c));
}

//Kiem tra da giac loi hay lom
int ShapePolygon::checkConvexpolygon() {
    pt ps;
    double temp1, temp2;
    for (int i = 0; i < n; i++) {

        if (i == n - 1) {
            pt_assign(ps, (int)(DG[i].GetX()), (int)(DG[i].GetY()), (int)(DG[0].GetX()), (int)(DG[0].GetY()));
        }
        else {
            pt_assign(ps, (int)(DG[i].GetX()), (int)(DG[i].GetY()), (int)(DG[i + 1].GetX()), (int)(DG[i + 1].GetY()));
        }

        for (int j = 0; j < n - 1; j++) {
            temp1 = ps.a * DG[j].GetX() + ps.b * DG[j].GetY() + ps.c;
            temp2 = ps.a * DG[j + 1].GetX() + ps.b * DG[j + 1].GetY() + ps.c;
            if (temp1 == 0 || temp2 == 0) {   // mot trong hai Point nam tren duong thang ta dang xet
                continue;
            }
            else {

                if (temp1 * temp2 < 0) {
                    return 0;
                }
            }


        }

    }
    return 1;
}

int ShapePolygon::Check(pt d) {
	for (int i = 0; i < n; i++) {
		double x, y;
		pt dti;

		if (i == n - 1) {
			pt_assign(dti, (int)(DG[i].GetX()), (int)(DG[i].GetY()), (int)(DG[0].GetX()), (int)(DG[0].GetY()));

		}
		else {
			pt_assign(dti, (int)(DG[i].GetX()), (int)(DG[i].GetY()), (int)(DG[i + 1].GetX()), (int)(DG[i + 1].GetY()));
		}


		if (checkMatch(d, dti) || i==n-1) {
			return 0;
		}

		if (pt_intersection(d, dti, x, y) && in_range2(DG[i].GetX(), DG[i].GetY(), DG[i + 1].GetX(), DG[i + 1].GetY(), x, y)) {
			return 1;
		}   // neu mot duong cat (giao Point khong phai hai dinh ) thi duong thang cat da giac luon 


		// neu giao Point la mot trong hai dinh cua duong thang , kiem tra xem duong thang d co cat mot duong thang nao khac trong da giac hay khong
		if (pt_intersection(d, dti, x, y) && checkPoint(x, y, DG[i].GetX(), DG[i].GetY())) {
            pt dtj, dts;
            pt_assign(dts, int(DG[i].GetX()), int(DG[i].GetY()), int(DG[int(n) -1].GetX()), int(DG[int(n) - 1].GetY()));
            if (checkMatch(d, dts)) {
                return 0;
            }

			for (int j = i + 1; j < n; j++) {


				pt_assign(dtj, (int)(DG[j].GetX()), (int)(DG[j].GetY()), (int)(DG[j + 1].GetX()), (int)(DG[j + 1].GetY()));


				if (pt_intersection(d, dtj, x, y) && in_range1(DG[j].GetX(), DG[j].GetY(), DG[j + 1].GetX(), DG[j + 1].GetY(), x, y)) {
					return 1;
				}   // neu mot duong cat (giao Point co the la hai dinh )thi duong thang cat da giac luon 

			}
		}

		// neu Point chung la dinh i+1 thi bo qua canh tiep theo 

		if (pt_intersection(d, dti, x, y) && checkPoint(x, y, DG[i + 1].GetX(), DG[i + 1].GetY())) {
            pt dtj, dts;
            pt_assign(dts, int(DG[i + 1].GetX()), int(DG[i + 1].GetY()), int(DG[i + 2].GetX()), int(DG[i + 2].GetY()));
            if (checkMatch(d, dts)) {
                return 0;
            }
			for (int j = i + 2; j < n; j++) {

				if (j == n - 1) {
					pt_assign(dtj, (int)(DG[j].GetX()), (int)(DG[j].GetY()), (int)(DG[0].GetX()), (int)(DG[0].GetY()));
				}
				else {
					pt_assign(dtj, (int)(DG[j].GetX()), (int)(DG[j].GetY()), (int)(DG[j + 1].GetX()), (int)(DG[j + 1].GetY()));
				}


				if (pt_intersection(d, dtj, x, y) && in_range1(DG[j].GetX(), DG[j].GetY(), DG[j + 1].GetX(), DG[j + 1].GetY(), x, y)) {
					return 1;
				}   // neu mot duong cat (giao Point co the la hai dinh )thi duong thang cat da giac luon 

			}
		}

	}
	return 0;
}

///////////////////////////////////////////////////////////////
//Dinh nghia lop ban nguyet
class ShapeSemic:public Shape
{
private:
	int _style; // 1: left, 2: right, 3: bottom , 4: top
	Point T;
	double r;
public:
    ShapeSemic(int k = 1, double tx= 0,double ty=0, double rr=0) :_style(k), T(tx, ty), r(rr) {}
	int checkMatchBN(pt& pt1);
	int Check(pt d);
    void draw(HDC hdc) const;
    int getStyle() { return _style; };
    Point getPoint() { return T; };
    double getr() { return r; };
    void Set(double k, double Tx, double Ty, double rr) { _style = (int)(k); T.Set(Tx, Ty); r = rr; }

};

void ShapeSemic::draw(HDC hdc) const
{
    double pxA = 0, pyA = 0, pxB = 0, pyB = 0, pxC = 0, pyC = 0, pxD = 0, pyD = 0;
    findPointsemic(_style, T.GetX(), T.GetY(), r, pxA, pyA, pxB, pyB, pxC, pyC, pxD, pyD);
    Chord(hdc, (int)(pxA), (int)(pyA), (int)(pxB), (int)(pyB), (int)(pxC), (int)(pyC), (int)(pxD), (int)(pyD));
}
// kiem tra xem d co trung duong thang di qua hai dau mut 
int ShapeSemic::checkMatchBN(pt& pt1) {
    double xA = 0, yA = 0, xB = 0, yB = 0;
    if (_style == 1 || _style == 2) {
        xA = this->T.GetX();
        xB = this->T.GetX();
        yA = this->T.GetY() + this->r;
        yB = this->T.GetY() - this->r;
    }

    else if (_style == 3 || _style == 4) {
        yA = this->T.GetY();
        yB = this->T.GetY();
        xA = this->T.GetX() + this->r;
        xB = this->T.GetX() - this->r;
    }

    pt pt2;
    pt_assign(pt2, (int)(xA), (int)(yA), (int)(xB), (int)(yB));

    if (checkMatch(pt1, pt2)) {
        return true;
    }
    return false;
}

// viet phuong trinh duong thang di qua hai dau mut 
int ShapeSemic::Check(pt d) {

    double x1, x2, x3;
    double x, y;
    double x0 = this->T.GetX();
    double y0 = this->T.GetY();

    if (checkMatchBN(d)) {
        return 0;
    }

    if (_style == 1) {  // moi x deu phai be hon hoac bang hoanh do tam 

        x1 = pow(d.a / d.b, 2) + 1;
        x2 = (2 * d.c * d.a / pow(d.b, 2)) + (2 * d.a * y0 / d.b) - (2 * x0);
        x3 = (pow(d.c / d.b, 2)) + (2 * d.c * y0 / d.b) + pow(y0, 2) + pow(x0, 2) - pow(this->r, 2);

        if (solveEquation(x1, x2, x3, x, y) == 2 && x <= x0 && y <= x0) {
            return 1;
        }

        else if ((solveEquation(x1, x2, x3, x, y) == 2 && (x <= x0 || y <= x0) )|| ((solveEquation(x1, x2, x3, x, y) == 1 && x <= x0 && y <= x0))) {
            double kc;
            if (x <= x0) {
                kc = abs(x - x0);
            }
            else if (y <= x0) {
                kc = abs(y - x0);
            }

            if (kc == 0) {
                return 0;
            }
            else if (kc < this->r && kc != 0) {
                return 1;
            }
            else if (kc == this->r) {
                double xA, xB, yA, yB, z, t;
                xA = x0;
                xB = x0;
                yA = y0 + r;
                yB = y0 - r;
                pt dt;
                pt_assign(dt, (int)(xA), (int)(yA), (int)(xB), (int)(yB));
                if (pt_intersection(d, dt, z, t) && in_range1(xA, yA, xB, yB, z, t)) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }

        else if (solveEquation(x1, x2, x3, x, y) == 1 && x > x0 && y > x0) {
            return 0;
        }

        else if (solveEquation(x1, x2, x3, x, y) == 0) {
            return 0;
        }

        return 0;



    }

    if (_style == 2) {  // moi x deu phai lon hon hoac bang hoanh do tam 
                        // cach kiem tra tuong tu truong hop tren

        x1 = pow(d.a / d.b, 2) + 1;
        x2 = (2 * d.c * d.a / pow(d.b, 2)) + (2 * d.a * y0 / d.b) - (2 * x0);
        x3 = (pow(d.c / d.b, 2)) + (2 * d.c * y0 / d.b) + pow(y0, 2) + pow(x0, 2) - pow(this->r, 2);

        if (solveEquation(x1, x2, x3, x, y) == 2 && x >= x0 && y >= x0) {
            return 1;
        }

        else if ((solveEquation(x1, x2, x3, x, y) == 2 && (x >= x0 || y >= x0))|| (solveEquation(x1, x2, x3, x, y) == 1 && (x >= x0 || y >= x0))) {
            double kc;
            if (x >= x0) {
                kc = abs(x - x0);
            }
            else if (y >= x0) {
                kc = abs(y - x0);
            }

            if (kc == 0) {
                return 0;
            }
            else if (kc < this->r && kc != 0) {
                return 1;
            }
            else if (kc == this->r) {
                double xA, xB, yA, yB, z, t;
                xA = x0;
                xB = x0;
                yA = y0 + r;
                yB = y0 - r;
                pt dt;
                pt_assign(dt, (int)(xA), (int)(yA), (int)(xB), (int)(yB));
                if (pt_intersection(d, dt, z, t) && in_range1(xA, yA, xB, yB, z, t)) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }

        else if (solveEquation(x1, x2, x3, x, y) == 1 && x < x0 && y < x0) {
            return 0;
        }

        else if (solveEquation(x1, x2, x3, x, y) == 0) {
            return 0;
        }

        return 0;



    }

    if (_style == 4) {  // moi y deu phai lon hon hoac bang tung do tam 

        x1 = pow(d.b, 2) + pow(d.a, 2);
        x2 = 2 * d.b * (d.c + x0 * d.a) - 2 * y0 * pow(d.a, 2);
        x3 = pow(d.c + x0 * d.a, 2) + pow(d.a * y0, 2) - pow(d.a * this->r, 2);

        if (solveEquation(x1, x2, x3, x, y) == 2 && x <= y0 && y <= y0) {
            return 1;
        }

        else if ((solveEquation(x1, x2, x3, x, y) == 2 && (x <= y0 || y <= y0))||( solveEquation(x1, x2, x3, x, y) == 1 && (x <= y0 || y <= y0))) {
            double kc;
            if (x <= y0) {
                kc = abs(x - y0);
            }
            else if (y <= y0) {
                kc = abs(y - y0);
            }

            if (kc == 0) {
                return 0;
            }
            else if (kc < this->r && kc != 0) {
                return 1;
            }
            else if (kc == this->r) {
                double xA, xB, yA, yB, z, t;
                xA = x0 + r;
                xB = x0 - r;
                yA = y0;
                yB = y0;
                pt dt;
                pt_assign(dt, (int)(xA), (int)(yA), (int)(xB), (int)(yB));
                if (pt_intersection(d, dt, z, t) && in_range1(xA, yA, xB, yB, z, t)) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }

        else if (solveEquation(x1, x2, x3, x, y) == 1 && x > y0 && y > y0) {
            return 0;
        }

        else if (solveEquation(x1, x2, x3, x, y) == 0) {
            return 0;
        }

        return 0;



    }
    if (_style == 3) {  // moi y deu phai be hon hoac bang tung do tam 
                        // cach kiem tra tuong tu truong hop tren

        x1 = pow(d.b, 2) + pow(d.a, 2);
        x2 = 2 * d.b * (d.c + x0 * d.a) - 2 * y0 * pow(d.a, 2);
        x3 = pow(d.c + x0 * d.a, 2) + pow(d.a * y0, 2) - pow(d.a * this->r, 2);

        if (solveEquation(x1, x2, x3, x, y) == 2 && x >= y0 && y >= y0) {
            return 1;
        }

        else if ((solveEquation(x1, x2, x3, x, y) == 2 && (x >= y0 || y >= y0))|| (solveEquation(x1, x2, x3, x, y) == 1 && (x >= y0 || y >= y0))) {
            double kc = 0;
            if (x >= x0) {
                kc = abs(x - y0);
            }
            else if (y >= x0) {
                kc = abs(y - y0);
            }

            if (kc == 0) {
                return 0;
            }
            else if (kc < this->r && kc != 0) {
                return 1;
            }
            else if (kc == this->r) {
                double xA, xB, yA, yB, z, t;
                xA = x0 + r;
                xB = x0 + r;
                yA = y0;
                yB = y0;
                pt dt;
                pt_assign(dt, (int)(xA), (int)(yA), (int)(xB), (int)(yB));
                if (pt_intersection(d, dt, z, t) && in_range1(xA, yA, xB, yB, z, t)) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }

        else if (solveEquation(x1, x2, x3, x, y) == 1 && x < y0 && y < y0) {
            return 0;
        }

        else if (solveEquation(x1, x2, x3, x, y) == 0) {
            return 0;
        }
        return 0;
    }
}
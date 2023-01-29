#pragma once
// Khai bao ham
bool isNumber(char* c);
bool isNumberint(char* c);
bool directionSemic(char* c);
void findPointRectangle(double pxA, double pyA, double pxB, double pyB, double& pxC, double& pyC, double& pxD, double& pyD);
void findPointsquare(double pxA, double pyA, double h, double& pxB, double& pyB, double& pxC, double& pyC, double& pxD, double& pyD);
void findPointsemic(int _kieu, double xT, double yT, double r, double& pxA, double& pyA, double& pxB, double& pyB, double& pxC, double& pyC, double& pxD, double& pyD);
int findDirectionsemic(char* c);
bool checkPointrectangle(double pxA, double pyA, double pxB, double pyB);
bool checkPointtriangle(double pxA, double pyA, double pxB, double pyB, double pxC, double pyC);

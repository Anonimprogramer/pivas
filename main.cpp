#include <iostream>
#include <vector>
#include <cmath>
#include <UnitTest++>

using namespace std;

class Vektor {
public:
    Vektor (double x1, double y1, double z1)
    {
        x = x1;
        y = y1;
        z = z1;
    }
    Vektor (double x1, double y1, double z1, double x2, double y2, double z2)
    {
        x = x2-x1;
        y = y2-y1;
        z = z2-z1;
    }
    Vektor () {
        x = 0;
        y = 0;
        z = 0;

    }
    Vektor operator+(const Vektor& i);
    Vektor operator+=(const Vektor& i);
    Vektor operator-(const Vektor& i);
    Vektor operator-=(const Vektor& i);
    Vektor operator*(const Vektor& i);
    Vektor operator*=(const Vektor& i);
    bool operator<(Vektor& i);
    bool operator<=(Vektor& i);
    bool operator>(Vektor& i);
    bool operator>=(Vektor& i);
    Vektor operator*(double n);
    Vektor operator*=(double n);
    double operator^(Vektor& i);
    Vektor operator=(const Vektor& i);
    vector<double> get_start_point();
    vector<double> get_end_point();
    vector<double> get_coordinates();
    double vektor_length();
    void set_x(double);
    void set_y(double);
    void set_z(double);
    double get_x();
    double get_y();
    double get_z();

private:
    double x, y, z;


};

Vektor operator*(double ,Vektor&);
double radian_to_degree(double);
double degree_to_radian(double);

int main() {
    double n=3;
    Vektor A(0,2,0);
    Vektor B(1,0,0);
    Vektor C;
    C = 3*A;
    cout << C.vektor_length() << endl;
    return 0;
}


void Vektor::set_x(double new_x)
{
    x=new_x;
}

void Vektor::set_y(double new_y)
{
    y=new_y;
}

void Vektor::set_z(double new_z)
{
    z=new_z;
}

double Vektor::get_x()
{
    cin.ignore
    return x;
}

double Vektor::get_y()
{
    return y;
}

double Vektor::get_z()
{
    return z;
}


vector<double> Vektor::get_start_point() {
    vector<double> start_point;
    start_point.push_back(0);
    start_point.push_back(0);
    start_point.push_back(0);
    return start_point;
}

vector<double> Vektor::get_end_point() {
    vector<double> end_point;
    end_point.push_back(x);
    end_point.push_back(y);
    end_point.push_back(z);
    return end_point;
}

double Vektor::vektor_length()
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vektor Vektor::operator+(const Vektor& i)
{
    Vektor S;

    S.x = x + i.x;
    S.y = y + i.y;
    S.z = z + i.z;

    return S;
}

Vektor Vektor::operator+=(const Vektor& i)
{
    x += i.x;
    y += i.y;
    z += i.z;
    return *this;
}

Vektor Vektor::operator-(const Vektor& i)
{
    Vektor S;

    S.x = x - i.x;
    S.y = y - i.y;
    S.z = z - i.z;

    return S;
}

Vektor Vektor::operator-=(const Vektor& i)
{
    x -= i.x;
    y -= i.y;
    z -= i.z;
    return *this;
}

Vektor Vektor::operator*(const Vektor& i)
{
    Vektor S;

    S.x = y * i.z - z * i.y;
    S.y = z * i.x - x * i.z;
    S.z = x * i.y - y * i.x;

    return S;
}

Vektor Vektor::operator*=(const Vektor& i)
{
    x = y * i.z - z * i.y;
    y = z * i.x - x * i.z;
    z = x * i.y - y * i.x;
    return *this;
}

bool Vektor::operator<(Vektor& i)
{
    return (this->vektor_length() < i.vektor_length());
}

bool Vektor::operator<=(Vektor& i)
{
    return (this->vektor_length() <= i.vektor_length());
}

bool Vektor::operator>(Vektor& i)
{
    return (this->vektor_length() > i.vektor_length());
}

bool Vektor::operator>=(Vektor& i)
{
    return (this->vektor_length() >= i.vektor_length());
}

Vektor Vektor::operator*(double n)
{
    Vektor S;

    S.x = x * n;
    S.y = y * n;
    S.z = z * n;

    return S;
}

Vektor Vektor::operator*=(double n)
{
    x *= n;
    y *= n;
    z *= n;
    return *this;
}

Vektor Vektor::operator=(const Vektor& i)
{
    if (this == &i) {
        return i;
    }
    this->x = i.x;
    this->y = i.y;
    this->z = i.z;
    return *this;
}

double Vektor::operator^(Vektor& i)
{
    return acos((x * i.x + y * i.y + x * i.z) / (this->vektor_length() * i.vektor_length()));
}

vector<double> Vektor::get_coordinates()
{
    vector<double> coords;
    coords.push_back(x);
    coords.push_back(y);
    coords.push_back(z);
    return coords;
}

Vektor operator*(double n, Vektor& vektor)
{
    return vektor * n;
}

double radian_to_degree(double rad) {
    return rad/3.1415926*180;
}

double degree_to_radian(double deg) {
    return deg*180/3.1415926;
}


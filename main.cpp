#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class vektor{
public:
    vektor(double x1,double y1,double z1,double x2,double y2,double z2)
    {
        begin_x=x1;
        begin_y=y1;
        begin_z=z1;
        end_x=x2;
        end_y=y2;
        end_z=z2;
    }
    vektor(){
        begin_x=0;
        begin_y=0;
        begin_z=0;
        end_x=0;
        end_y=0;
        end_z=0;

    }
    vektor operator+(const vektor& i);
    vektor operator+=(const vektor& i);
    vektor operator=(const vektor& i);
    vector <double> get_start_point();
    vector <double> get_end_point();
    double vektor_length();


private:
    double begin_x,begin_y,begin_z,end_x,end_y,end_z;


};
int main() {
    vektor A(1,2,3,4,5,6);
    vektor B(3,4,5,6,7,8);
    vektor C;
    C=A+B;
    cout << C.vektor_length();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector <double> vektor::get_start_point(){
    vector <double> start_point;
    start_point.push_back(this->begin_x);
    start_point.push_back(this->begin_y);
    start_point.push_back(this->begin_z);
    return start_point;
};
vector <double> vektor::get_end_point(){
    vector <double> end_point;
    end_point.push_back(this->end_x);
    end_point.push_back(this->end_y);
    end_point.push_back(this->end_z);
    return end_point;
}

double vektor::vektor_length() {
    double length;
    length=sqrt(pow((this->begin_x-this->end_x),2)+pow((this->begin_y-this->end_y),2)+pow((this->begin_z-this->end_z),2));
    return length;
}

vektor vektor::operator+(const vektor &i) {
    vektor S(0,0,0,0,0,0);

    S.end_x=this->end_x-this->begin_x+i.end_x-i.begin_x;
    S.end_y=this->end_x-this->begin_x+i.end_x-i.begin_x;
    S.end_z=this->end_z-this->begin_z+i.end_z-i.begin_z;
    S.begin_x=0;
    S.begin_y=0;
    S.begin_z=0;


    return S;
};
vektor vektor::operator+=(const vektor &i) {
   this->end_x+=i.end_x-i.begin_x;
   this->end_y+=i.end_y-i.begin_y;
   this->end_z+=i.end_z-i.begin_z;
   return *this;
}

vektor vektor::operator=(const vektor &i) {
    vektor S;
    if (this == &i){
        return i;
    }
    this->begin_x=i.begin_x;
    this->begin_y=i.begin_y;
    this->begin_z=i.begin_z;
    this->end_x=i.end_x;
    this->end_y=i.end_y;
    this->end_z=i.end_z;
    return *this;
};
/********************************************************************************************************************************************************************************************************************************************************************************************************
 ***
 ***                                                                                               SAKARYA ÜNİVERSİTESİ
 ***                                                                               BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
 ***                                                                                      BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
 ***                                                                                           PROGRAMLAMAYA GİRİŞİ DERSİ
 ***
 ***
 ***                                                                        ÖDEV NUMARASI : 2
 ***                                                                        ÖĞRENCİ ADI : MELİKE DEMİRTAŞ
 ***                                                                        ÖĞRENCİ NUMARASI : G211210003
 ***                                                                        DERS GRUBU : C GRUBU
 ***
 *************************************/
#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
private:
    float real;
    float imag;
public:
    Complex(): real(0), imag(0){ }
    void input() // It is a function to enter a complex number.
    {
        cout << "Enter real part of complex number : ";
        cin >> real;
        
        cout << "Enter imaginary part of complex number : ";
        cin >> imag;
    }
    void output() // It is a function in order to print the result.
    {
        if(imag < 0)
            cout << "Output Complex number: "<< real << imag << "i";
        else
            cout << "Output Complex number: " << real << "+" << imag << "i";
    }
    Complex operator - (Complex c1) // Opreator overloading for - operator
    {
        Complex sub;
        sub.real = real - c1.real;
        sub.imag = imag - c1.imag;
        
        return sub;
    }
    Complex operator + (Complex c1) //Operator overloading for + operator
    {
        Complex sum;
        sum.real = real + c1.real;
        sum.imag = imag + c1.imag;
        return sum ;
    }
    Complex operator * (Complex c1) //Operator overloading for * operator
    {
        Complex multi;
        double  real1 ;
        real1= c1.real;
        multi.real =(real*c1.real)-(imag*c1.imag);
        multi.imag = (real*c1.imag)+(imag*real1);
        return multi;
    }
    Complex operator / ( Complex c1) //Operator overloading for / operator
    {
        float temp;
        temp = ((real * c1.real)+(imag*c1.imag))/((c1.real*c1.real)+(c1.imag*c1.imag));
        imag = ((imag*c1.real)-(real*c1.imag))/((c1.real*c1.real )+(c1.imag*c1.imag));
        real = temp;
        return *this;
    }
    Complex operator += (Complex c1) //Operator overloading for += operator
    {
        Complex sum ;
        real += c1.real;
        imag += c1.imag;
        return sum ;
    }
    Complex operator -= (Complex c1)//Operator overloading for -= operator
    {
        Complex sub;
        real -= c1.real;
        imag -= c1.imag;
        return  sub ;
    }
    Complex operator *= ( Complex c1) //Operator overloading for *= operator
    {
        float a = ( real*c1.real)-(imag*c1.imag);
        imag = (real * c1.imag)+(imag*c1.real);
        real=a;
        return *this ;
    }
    Complex operator /= ( Complex c1) //Operator overloading for /= operator
    {
        float temp;
        temp = ((real * c1.real)+(imag*c1.imag))/((c1.real*c1.real)+(c1.imag*c1.imag));
        imag = ((imag*c1.real)-(real*c1.imag))/((c1.real*c1.real )+(c1.imag*c1.imag));
        real = temp;
        return *this;
    }
    void PolarNotation() // In order to find polar notation. (Polar notation denotes a complex number in terms of its vector's length and angular direction from the starting point
    {
        float oklid = sqrt(real * real + imag * imag);
        float angle = atan2(imag , real);
        cout<<"Polar Notation:  ("<< oklid <<","<< angle <<")"<<endl;
    }
    
};
int main()
{
        Complex c1 , c2 ;
        c1.input();
        c2.input();
        c1 = c1-c2;
        c1.output();
        cout<<endl<<endl;
        c1.input();
        c2.input();
        c1 = c1 + c2 ;
        c1.output();
        cout<<endl<<endl;
        c1.input();
        c2.input();
        c1 = c1 * c2 ;
        c1.output();
        cout<<endl<<endl;
        c1.input();
        c2.input();
        c1 = c1 / c2 ;
        c1.output();
        cout<<endl<<endl;
        c1.input();
        c2.input();
        c1 += c2 ;
        c1.output();
        cout<<endl<<endl;
        c1.input();
        c2.input();
        c1 -= c2 ;
        c1.output();
        cout<<endl<<endl;
        c1.input();
        c2.input();
        c1 *= c2 ;
        c1.output();
        cout<<endl<<endl;
        c1.input();
        c2.input();
        c1 /= c2 ;
        c1.output();
        cout<<endl<<endl;
        c1.input();
        c1.PolarNotation();
        c2.input();
        c2.PolarNotation();
   
        cout<<"*********MENU***********"<<endl;
        int Option;
        do//I used do while loop to exit the menu at any time that i want.
        {
            cout<<endl;
            cout<<"Press 0 to exit from the menu "<<endl;
            cout<<"Press 1 to addition "<<endl;
            cout<<"Press 2 to subtract  "<<endl;
            cout<<"Press 3 to multiply "<<endl;
            cout<<"Press 4 to split "<<endl;
            cout<<"Press 5 to += operation "<<endl;
            cout<<"Press 6 -= operation"<<endl;
            cout<<"Press 7 *= operation"<<endl;
            cout<<"Press 8 /= operation"<<endl;
            cout<<"Press 9 to polar notation "<<endl;
            cin>>Option;
            
            switch( Option) // I used switch-case for menu operations.
            {
                case 0:
                    cout<<"Exited the menu "<<endl;
                    return 0 ;
                case 1 :
                {
                    c1.input();
                    c2.input();
                    c1 = c1+c2;
                    c1.output();
                    break;
                }
                case 2:
                {   c1.input();
                    c2.input();
                    c1 = c1-c2 ;
                    c1.output();
                    break ;
                }
                case 3:
                {
                    c1.input();
                    c2.input();
                    c1= c1*c2;
                    c1.output();
                    break;
                }
                case 4:
                {
                    c1.input();
                    c2.input();
                    c1=c1 / c2 ;
                    c1.output();
                    break;
                }
                case 5:
                {
                    c1.input();
                    c2.input();
                    c1 += c2 ;
                    c1.output();
                    break;
                }
                case 6:
                {
                    c1.input();
                    c2.input();
                    c1 -= c2 ;
                    c1.output();
                    break;
                }
                case 7 :
                {
                    c1.input();
                    c2.input();
                    c1 *= c2 ;
                    c1.output();
                    break;
                }
                case 8 :
                {
                    c1.input();
                    c2.input();
                    c1 /= c2 ;
                    c1.output();
                    break;
                }
                case 9 :
                {
                    c1.input();
                    c1.PolarNotation();
                    c2.input();
                    c2.PolarNotation();
                    break;
                }
            }
        }while(Option!=0);//Condition to stop the menu
}
    
    
    
    
    


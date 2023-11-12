#include <iostream>
#include "Prime_generate.h"
#include "Key_generate.h"
#include "Encrypt_Decrypt.h"

using namespace std;

// Code to demonstrate RSA algorithm
int main()
{
    cout<<"Welcome to the RSA Public-Key Encryption Algorithm. \nThis program aims to simulate encryption and decryption using the RSA algorithm."<<endl;
    cout<<"Please follow the instructions in order to get an accurate encryption/decryption."<<endl;
    cout<<endl;
    system("pause");cout<<endl;cout<<endl;
    cout<<"Let's start!\nFor the Key generation, the system requires two non-identical prime numbers p and q."<<endl;
    cout<<"Would you like to generate them? (y/n): "; string s=""; cin>>s;
    int p, q;
    if(s=="y")
    {
        int limit, random, k;
        cout<<"Insert a limit value (100-500): ";
        cin>>limit;
        cout<<"Insert a accuracy value (4-10): ";
        cin>>k;
        cout<<"\nGenerating values . . . "<<endl;
        while(true)
        {
            p = prime_generator(limit, k);
            q = prime_generator(limit, k);
            if (p != q)
                break;
        }
        cout<<"p = "<<p<<" \t "<<"q = "<<q<<endl;
    }
	else
    {
        cout<<"Please prompt the prime numbers, non-identical: "<<endl;
        cout<<"p = ";
        cin>>p;
        cout<<"q = ";
        cin>>q;
    }
    cout<<endl;
    system("pause");cout<<endl;cout<<endl;
    cout<<"As now the p and q values are set, the process of key generation can begin."<<endl;cout<<endl;
    Key_generate gen;
    gen.setPrimes(p, q);
    int n, etf;
    cout<<"Calculating the product of p and q: "<<endl;
    n = gen.Calc_n(p, q);
    cout<<"n = "<<p<<" * "<<q<<" = "<<n<<endl;
    cout<<"Calculating the Euler totient function: "<<endl;
    etf = gen.Calc_etf(p, q);
    cout<<"E(n) = ("<<p<<" - 1)("<<q<<" - 1) = "<<etf<<endl;
    cout<<endl;
    gen.Cacl_keys();
    cout<<endl;
    system("pause");cout<<endl;cout<<endl;
    cout<<"Enter a message (in numeric form) here to encode. ";
    cout<<"Break your message into small chunks so that the message codes are not larger than "<<p*q<<"."<<endl;
    int Msg,e,d;
    e = gen.get_e();
    d = gen.get_d();
    Encrypt_Decrypt msg;
    cout<<"Msg: ";
    cin>>Msg;
    while(!(Msg<p*q))
    {
        cout<<"\nMake sure that the message is smaller than "<<p*q<<". Try again!"<<endl;
		cout<<"Msg: ";
        cin>>Msg;
	    if (Msg<p*q)
			break;
    }
    msg.setMessage(Msg);
    msg.setKeys(e, d);
    msg.set_n(p*q);
    msg.Calc();
    cout<<"Encrypted: "<<msg.get_C()<<endl;
    cout<<"Decrypted: "<<msg.get_M()<<endl;
    cout<<endl;
    cout<<"Exiting. ";
    system("pause");
    return 0;
}


#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iterator>
#include <cmath>
#ifndef Key_generate_H
#define Key_generate_H

using namespace std;

class Key_generate
{
	private:
	    int p, q;
		int fact_c=1, can;
		int old_fact_c;
	int get_p_Prime()
	{
		return p;
	}
	int get_q_Prime()
	{
		return q;
	}
    // Returns gcd of a and b
    int gcd(int a, int b)
    {
		while (1) 
        {
			int temp = a % b;
		    if (temp == 0)
			    return b;
			a = b;
			b = temp;
	    }
    }
	// Get the prime factors of n
    void primeFactors(int n)
    {
	    // Print the number of 2s that divide n
	    while (n % 2 == 0)
	    {
			cout << 2 <<" ";	
			n = n/2;
	    }
		// n must be odd at this point. So we can skip
		// one element (Note i = i +2)
	    for (int i = 3; i <= sqrt(n); i = i + 2)
		{
			// While i divides n, print i and divide n
		    while (n % i == 0)
		    {
				cout << i <<" ";					
				n = n/i;
		    }
	    }
		// This condition is to handle the case when n
		// is a prime number greater than 2
	    if (n > 2)
	    {
			cout << n <<" ";	
	    }
	}
	void Key1()
    {
		int ap=1;	
		Miller_Rabin prime;//prime no can't be factorized so excluded
		for(int i=1; i <= can; i++)
	    {
			if(((etf*i) + 1)%etf==1 && !prime.isPrime((etf*i)+1,1000))
		    {
				cout<<ap<<". Factors of K="<<(etf*i)+1<<": "; ap++;
				primeFactors((etf*i)+1); cout<<endl;
		    }
			else
		        can++;
	    }
    }
	bool Key2(int e, int d)
    {
		if (gcd(etf, e) == 1 && gcd(etf, d) == 1 && (e*d) % etf==1)
	        return true;
		else
		    return false;
    }


    public:
		vector<int> e_data;
		vector<int> d_data;
	    int n, etf, stat;
	    int e, d;
	void setPrimes(int P, int Q)
	{
		p = P;
		q = Q;
	}
	int get_e()
	{
		return e;
	}
	int get_d()
	{
		return d;
	}
	int Calc_n(int p, int q)
    {
		n = p * q;
	    return n;
    }
	int Calc_etf(int p, int q)
    {
		etf = (p - 1) * (q - 1);
	    return etf;
    }
	void Cacl_keys()
	{
		cout<<"Creating canditates such as K equals to 1 mod E(n). The factors of K most likely are the values of e and d."<<endl;
		cout<<"How many canditates would you like to generate? (5-30): "; cin>>can;
		cout<<"\n(EXPERIMENTAL) Would you like to assign e and d values automatically? (y/n): ";
		string s=""; cin>>s;
		if(s=="y")
		{
			cout<<"Assigning e and d automatically . . . "<<endl;
			stat = 1;
			Key1();
		}
		else
		{
			Key1();
		    cout<<"\nUsing the factorization list above, pick two numbers to assign e and d from K. ";
		    cout<<"In case there are more than 2 factors for a single K, either find another K or multiply the factors until you remain with only 2. "<<endl;
			cout<<"e = ";
		    cin>>e;
	    	cout<<"d = ";
    		cin>>d;
		}
			while(!Key2(e, d))
			{
				cout<<"\nOne of the e and d values must be typed wrong or it doesn't correspond to the same K. Try again!"<<endl;
			    cout<<"e = ";
			    cin>>e;
			    cout<<"d = ";
			    cin>>d;
			    if (Key2(e, d))
				    break;
		    }
    		if (Key2(e, d))
    		{
				//cout<<"e = "<<e<<endl;
			    //cout<<"d = "<<d<<endl;
			    cout<<"n = "<<n<<endl;
			    cout<<"E(n) = "<<etf<<endl;
			    cout<<"e*d = "<<e*d<<endl;
				cout<<"e*d mod E(n) = "<<(e*d)%etf<<endl;
			    cout<<"e and E(n) are relatively prime"<<endl;
			    cout<<"d and E(n) are relatively prime"<<endl;
		    }
			//Encrypt_Decrypt msg;
			//msg.setKeys(e, d);
			//msg.set_n(p*q);
		
	}
};

#endif




/*

vector<int> fact (50);
		int* p = fact.data();
		int fact_size = fact.size();
		old_fact_c = fact_c;

*p=2;++p;//fact.at(fact_c)=2;
			fact_c++;
			//fact_pos(fact,fact_c);fact.at(fact_c)
			if(stat != 1)

	    //fact_c = fact_c - old_fact_size + 1; fact_c = fact_size - fact_c - 1;
	    //cout<<"\nfact_c "<<fact_c<<endl; cout<<"fact_size "<<fact.size()<<endl;
	    //int fact_dc= fact_c - old_fact_c;
	    //int act_size = fact_c % fact_size;
	    //cout<<"act_size "<<act_size<<endl;
	   /* if(stat==1)
		    for(int c=1; c <= act_size; c++)
	        {
				if(act_size == 2)
				    cout << fact.at((fact_c - act_size)+c) <<" ";
				else if(act_size > 2)
		        {
					int in, af, result;
					in = fact.at((fact_c - act_size)+c);
					af = fact.at(((fact_c - act_size)+c)+1);
					result = in * af;
					fact.at((fact_c - act_size)+c) = result;
					cout << fact.at(((fact_c - act_size)+c)) <<" ";
					act_size--;
	        	}			
	        }

			//iota(fact.begin(), fact.end(), 100);
			//fact.at(fact_c)=i;
			//fact_pos(fact,fact_c);
						*p=n;++p;//fact.at(fact_c)=n;
			fact_c++;
			if(stat != 1)
			*/














/*void fact_pos(vector <int> const &a, int c)
{
	while(a.size() < c)
	//a.push_back(c);
	//for(int i=0; i < a.size(); i++)
    cout << a.at(c) <<" * "<< ' ';
}*/
// A function to print all prime
// factors of a given number n
//in class example
	/*int k = etf + 1;
	for (e=2; e < etf; e++) 
	{
		//cout<<"etf"<<etf<<endl;
		//cout<<"e"<<e<<endl;
		//cout<<"gcd"<<gcd(etf, e)<<endl;
		if (gcd(etf, e) == 1 && gcd(n, e) == 1)
		{
			
				double d = ((etf*i) + 1) / e;
				int ed = e * d;
				if(floor(d)/d == 1 && gcd(etf, d) == 1)
				{
					d=(int)d;
					if(ed % etf == 1 && ed == k)
				    {
						E = d;
						D = e;
				    }
			    }
		    }
	    }		
	}*/

/*void Key_public()
{
for(int i=0; i < fact.size(); i++)
		cout <<"i="<<i<<"vector pos="<< fact.at(i) << ' ';


		// Private key (d stands for decrypt)
	// choosing d such that it satisfies
	// d*e = 1 + k * totient
	int k = 2; // A constant value
	double d = (1 + (k * phi)) / e;

	// Message to be encrypted
	double msg = 88;

	printf("Message data = %lf", msg);

	// Encryption c = (msg ^ e) % n
	double c = pow(msg, e);
	c = fmod(c, n);
	printf("\nEncrypted data = %lf", c);

	// Decryption m = (c ^ d) % n
	double m = pow(c, d);
	m = fmod(m, n);
	printf("\nOriginal Message Sent = %lf", m);
}
*/

	
		/*if(floor(d)==ceil(d) && gcd(d, etf) == 1 && ed % etf == 1)
		{
						int iterations=0;
		if(iterations>e)
		{
			cout<<"After "<<iterations<<" iterations the value d can't be integer. Moving on . . . "<<endl;
			break;
		}
			
			//d_data[100] = d;
			//cout<<"d_data "<<d_data[100]<<" "<<endl;
			
			cout<<"Iterations counter: "<<iterations<<endl;
			break;
		}
		else	
		{
			k += etf;
			iterations++;
		}
		*/
	

		//cout<<"e "<<e_data[i+1]<<" "<<endl;
		
		
	//cout<<"d "<<d<<" "<<endl;
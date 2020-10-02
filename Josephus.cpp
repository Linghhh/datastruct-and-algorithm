#include <iostream>
#include <list>
using namespace std;

void Josephus( int m, int n );
int main()
{
    Josephus( 5,1 );
    return 0;
}

void Josephus( int m, int n )
{
    int i,j,mPrime,numLeft;
    list<int> L;
    list<int>::iterator iter;

    //Initalization
    for( i = 0; i != m; ++i )
        L.push_back( i-1 );

     mPrime = n % m;
     numLeft = m;
     iter = L.begin();
     for( i = 0; i != m; ++i )
     {
         mPrime = mPrime % numLeft;
         if ( mPrime <= numLeft/2 )
             for( j = 0; j != mPrime; ++j )
             {
                 iter++;
                 if( iter == L.end() )
                     iter = L.begin();
             }
         else
             for( j = 0; j != mPrime; ++j )
             {
                 if( iter == L.begin() )
                     iter = --L.end();
                 else
                     iter--;
             }
         
         cout<<*iter<<" ";
         iter = L.erase( iter );
         if ( iter == L.end() )
             iter = L.begin();
    }
}

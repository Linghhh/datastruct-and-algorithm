#ifndef __EVALPOSTFIX_H_ 
#define __EVALPOSTFIX_H_
#include <iostream>
#include <stack>
#include <math.h>
#include <string>
using namespace std;

double evalPostFix()
{
    stack<double> s;
    string token;
    double a,b,result;
    cin>>token;
    while( token[0] != '=' )
    {
        result = atof( token.c_str() );
        if( result != 0.0 )
            s.push(result);
        else if ( token == "0.0" )
            s.push( result );
        else
            switch ( token[0] )
            {
            case '+' :
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push( a+b );
                break;
            case '-' :
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push( a-b );
                break;
            case '*' :
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push( a*b );
            case '/' : 
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push( a/b );
                break;
            case '^' :
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push( exp( a*log(b) ) );
                break;

            }
        cin>>token;
    }
    return s.top();
}

#endif

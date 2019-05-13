/**
 * A demo program for testing our containers program.
 * 
 * 
 */


#include <iostream>
#include <iomanip>

#include "badkan.hpp"
#include "range.hpp"
#include "chain.hpp"
// #include "zip.hpp"
// #include "product.hpp"
// #include "powerset.hpp"
using namespace std;
using namespace itertools;

 //Auxiliary method
template<typename T> string tostring(const T& iterable){
    ostringstream ostr;
    // cout << fixed;
    // cout << std::setprecision(1);
    for(decltype(*(iterable.begin())) i : iterable){
        ostr << fixed;
        ostr << setprecision(1) << i << ",";
    }
    return ostr.str();
}

int main() {

    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {
         testcase
         .setname("Testing range:")
         .CHECK_OUTPUT(tostring(range(5,9)),"5,6,7,8,")
         .CHECK_OUTPUT(tostring(range('a','b')),"a,")
         .CHECK_OUTPUT(tostring(range('a','a')),"")//no range         
         .CHECK_OUTPUT(tostring(range('a','z')),"a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,")
         .CHECK_OUTPUT(tostring(range(5.1,9.1)),"5.1,6.1,7.1,8.1,")
         ;
         




 grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}


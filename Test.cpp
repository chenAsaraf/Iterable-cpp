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
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
using namespace std;
using namespace itertools;

 //Auxiliary method
template<typename T> string tostring(const T& iterable){
    ostringstream ostr;
    // cout << fixed;
    // cout << std::setprecision(1);
    bool b = false;
    for(decltype(*(iterable.begin())) i : iterable){
        if(!b) {
            b = true;
            ostr << fixed;
            ostr << setprecision(1) << i;
        }
        else {
            ostr << fixed;
            ostr << setprecision(1) << ", " << i;
        }
        
    }
    return ostr.str();
}

int main() {

    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {
         testcase.setname("Testing Ranges:")
            .CHECK_OUTPUT(tostring(range(5,9)),"5, 6, 7, 8")
            .CHECK_OUTPUT(tostring(range(5.1,10.1)),"5.1, 6.1, 7.1, 8.1, 9.1")
            .CHECK_OUTPUT(tostring(range('k','q')),"k, l, m, n, o, p")
        ;

        testcase.setname("Chain Testing:")
            .CHECK_OUTPUT(tostring(chain(range('a','d'),string("hello"))), "a,b,c,h,e,l,l,o")
            .CHECK_OUTPUT(tostring(chain(range('a','d'),range('k','m'))), "a,b,c,k,l")
            .CHECK_OUTPUT(tostring(chain(range('a','d'),range(1,4))), "a,b,c,1,2,3")
            .CHECK_OUTPUT(tostring(chain(range('a','d'),range(1.2,3.2))), "a,b,c,1.2,2.2")
            .CHECK_OUTPUT(tostring(chain(range(1.2,4.2),string("hello"))), "1.2,2.2,3.2,h,e,l,l,o")
            .CHECK_OUTPUT(tostring(chain(range(1, 4),range(1.2,3.2))), "1,2,3,1.2,2.2")          
            .CHECK_OUTPUT(tostring(chain(string("hiu"),range(1,5))), "h,i,u,1,2,3,4")  
            .CHECK_OUTPUT(tostring(chain(string("like"),string("this"))), "l,i,k,e,t,h,i,s")
            .CHECK_OUTPUT(tostring(chain(range(2,4),range(10,13))),"2,3,10,11,12")
            .CHECK_OUTPUT(tostring(chain(range(5.6,8.6),range(1.2,3.2))), "5.6,7.6,1.2,2.2")
        ;

        testcase.setname("ZIP TESTING:")
            .CHECK_OUTPUT(tostring(zip(range(1,6),string("hello"))), "h 2,e 3,l 4,l 5,o 1")
            .CHECK_OUTPUT(tostring(zip(range(1.3,5.3),string("hell"))), "h 2.3,e 3.3,l 4.3,l 1.3")
            .CHECK_OUTPUT(tostring(zip(range('e', 'g'),string("hi"))), "h f,i e")
            .CHECK_OUTPUT(tostring(zip(string("world"),string("hello"))), "h o,e r,l l,l d,o w")
            .CHECK_OUTPUT(tostring(zip(range(1,6),range(15,20))), "15 2,16 3,17 4,18 5,19 1")
            .CHECK_OUTPUT(tostring(zip(range(3,6),range(7.7,10.7))), "7.7 4, 8.7 5, 9.7 3")
            .CHECK_OUTPUT(tostring(zip(range(3,6),range('a','d'))), "a 4,b 5,c 1")
            .CHECK_OUTPUT(tostring(zip(range(25.34,28.34),range(3.2,6.2))), "3.2 26.34, 4.2 27.34, 5.2 25.34")
            .CHECK_OUTPUT(tostring(zip(range(11.1,13.1),range('w','y'))), "w 12.1, x 11.1")
            .CHECK_OUTPUT(tostring(zip(range('a','d'),range('f','i'))), "f b, g d,h a")
        ;

        testcase.setname("PRODUCT TESTING:")
            .CHECK_OUTPUT(tostring(product(range(1,4),string("helo"))), "h 1,e 1,l 1,o 2,h 2,e 2,l 2,o 3,h 3,e 3,l 3,o 1")
            .CHECK_OUTPUT(tostring(product(range(1.3,2.3),string("helo"))), "h 1.3,e 1.3,l 1.3,o 2.3,h 2.3,e 2.3,l 2.3,o 3.3,h 3.3,e 3.3,l 3.3,o 1.3")
            .CHECK_OUTPUT(tostring(product(range('e', 'g'),string("hi"))), "h e,i f,h f,i e")
            .CHECK_OUTPUT(tostring(product(string("hey"),string("hi"))), "h h,i e,h e,i y,h y,i h")
            .CHECK_OUTPUT(tostring(product(range(4,6),range(18,20))), "18 4,19 5,18 5,19 4")
            .CHECK_OUTPUT(tostring(product(range(3,5),range(7.7,8.7))), "7.7 3,7.7 4")
            .CHECK_OUTPUT(tostring(product(range(3,5),range('a','e'))), "a 3,b 3,c 3,d 4,a 4,b 4,c 4,d 3")
            .CHECK_OUTPUT(tostring(product(range(25.34,28.34),range(3.2,5.2))), "3.2 25.34,4.2 26.34,3.2 26.34,4.2 37.34,3.2 25.34")
            .CHECK_OUTPUT(tostring(product(range(11.1,13.1),range('w','z'))), "w 11.1,x 11.1,y 12.1,w 12.1,x 12.1,y 11.1")
            .CHECK_OUTPUT(tostring(product(range('a','d'),range('f','i'))), "f a,g a,h b,f b,g b,h c,f c,g c,h a")
        ;

        testcase.setname("POWER SET TESTING:")
            .CHECK_OUTPUT(tostring(powerset(string("abc"))), "{a,b,c},{a,b},{a,c},{b,c},{a},{b},{c},{}")
            .CHECK_OUTPUT(tostring(powerset(range('a','d'))), "{a,b,c},{a,b},{a,c},{b,c},{a},{b},{c},{}")
            .CHECK_OUTPUT(tostring(powerset(range(1,4))), "{1,2,3},{1,2},{1,3},{2,3},{1},{2}.{3},{}")
            .CHECK_OUTPUT(tostring(powerset(range(1.3,5.3))), "{1.3,2.3,3.3,4.3},{1.3,2.3,3.3},{1.3,2.3,4.3},{2.3,3.3,4.3},{1.3,3.3,4.3},{1.3,2.3},{1.3,3.3},{1.3,4.3},{2.3,3.3},{2.3,4.3},{3.3,4.3},{1.3},{2.3}.{3.3},{4.3},{}")
            .CHECK_OUTPUT(tostring(product(range(1,3),string("he"))), "{1,2,h,e},{1,2,h},{1,2,e},{1,h,e},{2,h,e},{1.2},{1,h},{1,e},{2,h},{2,e},{h,e},{1},{2},{h},{e},{}")
            .CHECK_OUTPUT(tostring(product(range(1.3,2.3),string("he"))), "{1.3,h,e},{1.3,h},{1.3,e},{h,e},{1.3},{h},{e},{}")
            // .CHECK_OUTPUT(tostring(powerset(range('e', 'g'),string("hi"))), "{e.f.h,i},{e,f,h},{e,f,i},{e,h,i},{f,h,i},{e,f},{e,h},{e,i}.{f,h},{f,i},{h,i},{e},{f},{h},{i},{}")
            // .CHECK_OUTPUT(tostring(powerset(string("w"),string("hey"))), "{w,h,e,y},{w,h,e},{w,h,y},{w,e,y},{w,h},{w,e},{w,y},{h,e},{h,y},{e,y},{w},{h},{e},{y},{}")
            // .CHECK_OUTPUT(tostring(powerset(range(2,3),range(15,16))), "{2,15},{2},{15},{}")
            // .CHECK_OUTPUT(tostring(powerset(range(3,5),range(7.7,8.7))), "{3,4,7.7},{3,4},{3,7.7},{4,7.7},{3},{4},{7.7},{}")
            // .CHECK_OUTPUT(tostring(powerset(range(3,5),range('a','b'))), "{3,4,a},{3,4},{3,a},{4,a},{3},{4},{a},{}")
            // .CHECK_OUTPUT(tostring(powerset(range(25.34,26.34),range(3.2,5.2))), "{25.34,3.2,4.2},{25.34,3.2},{25.34,4.2},{3.2,4.2},{25.34},{3.2},{4.2},{}")
            // .CHECK_OUTPUT(tostring(powerset(range(11.1,13.1),range('w','x'))), "{11.1,12.1,w},{11.1,12.1},{11.1,w},{12.1,w},{11.1},{12.1},{w},{}")
            // .CHECK_OUTPUT(tostring(powerset(range('a','c'),range('f','g'))), "{a,b,f},{a,b},{a,f},{b,f},{a},{b},{f},{}")
        ;
        

         




 grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
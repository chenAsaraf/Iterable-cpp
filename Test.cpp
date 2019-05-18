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
template<typename T> string tostring(const T& iter){
    ostringstream ostr;
    // cout << fixed;
    // cout << std::setprecision(1);
    bool b = false;
    for(decltype(*(iter.begin())) i : iter){
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
            .CHECK_OUTPUT(tostring(chain(range('a','d'),string("hello"))), "a, b, c, h, e, l, l, o")
            .CHECK_OUTPUT(tostring(chain(range('a','d'),range('k','m'))), "a, b, c, k, l")
            .CHECK_OUTPUT(tostring(chain(range('a','d'),range(1,4))), "a, b, c, 1, 2, 3")
            .CHECK_OUTPUT(tostring(chain(range('a','d'),range(1.2,3.2))), "a, b, c, 1.2, 2.2")
            .CHECK_OUTPUT(tostring(chain(range(1.2,4.2),string("hello"))), "1.2, 2.2, 3.2, h, e, l, l, o")
            .CHECK_OUTPUT(tostring(chain(range(1, 4),range(1.2,3.2))), "1, 2,3, 1.2, 2.2")          
            .CHECK_OUTPUT(tostring(chain(string("hiu"),range(1,5))), "h, i, u, 1, 2, 3, 4")  
            .CHECK_OUTPUT(tostring(chain(string("like"),string("this"))), "l, i, k, e, t, h, i, s")
            .CHECK_OUTPUT(tostring(chain(range(2,4),range(10,13))),"2, 3, 10, 11, 12")
            .CHECK_OUTPUT(tostring(chain(range(5.6,8.6),range(1.2,3.2))), "5.6, 7.6, 1.2, 2.2")
        ;

        testcase.setname("ZIP TESTING:")
            .CHECK_OUTPUT(tostring(zip(range(1,6),string("hello"))), "1,h, 2,e, 3,l, 4,l, 5,o")
            .CHECK_OUTPUT(tostring(zip(range(1.3,5.3),string("hell"))), "1.3,h, 2.3,e, 3.3,l, 4.3,l")
            .CHECK_OUTPUT(tostring(zip(range('e', 'g'),string("hi"))), "e,h, f,i")
            .CHECK_OUTPUT(tostring(zip(string("world"),string("hello"))), "w,h, o,e, r,l, l,l, d,o")
            .CHECK_OUTPUT(tostring(zip(range(1,6),range(15,20))), "1,15, 2,16, 3,17, 4,18, 5,19")
            .CHECK_OUTPUT(tostring(zip(range(3,6),range(7.7,10.7))), "3,7.7, 4,8.7, 5,9.7")
            .CHECK_OUTPUT(tostring(zip(range(3,6),range('a','d'))), "3,a, 4,b, 5,c")
            .CHECK_OUTPUT(tostring(zip(range(25.34,28.34),range(3.2,6.2))), "25.3,3.2, 26.3,4.2, 27.3,5.2")
            .CHECK_OUTPUT(tostring(zip(range(11.1,13.1),range('w','y'))), "11.1,w, 12.1,x")
            .CHECK_OUTPUT(tostring(zip(range('a','d'),range('f','i'))), "a,f, b,g, c,h")
        ;

        testcase.setname("PRODUCT TESTING:")
            .CHECK_OUTPUT(tostring(product(range(1,4),string("helo"))), "1,h, 2,h, 3,h, 1,e, 2,e, 3,e, 1,l, 2,l, 3,l, 1,o, 2,o, 3,o")
            .CHECK_OUTPUT(tostring(product(range(1.3,2.3),string("helo"))), "1.3,h, 1.3,e, 1.3,l, 1.3,o")
            .CHECK_OUTPUT(tostring(product(range('e', 'g'),string("hi"))), "e,h, f,h, e,i, f,i")
            .CHECK_OUTPUT(tostring(product(string("hey"),string("hi"))), "h,h, e,h, y,h, h,i, e,i, y,i")
            .CHECK_OUTPUT(tostring(product(range(4,6),range(18,20))), "4,18, 5,18, 4,19, 5,19")
            .CHECK_OUTPUT(tostring(product(range(3,5),range(7.7,8.7))), "3,7.7, 4,7.7")
            .CHECK_OUTPUT(tostring(product(range(3,5),range('a','e'))), "3,a, 4,a, 3,b, 4,b, 3,c, 4,c, 3,d, 4,d")
            .CHECK_OUTPUT(tostring(product(range(25.34,28.34),range(3.2,5.2))), "25.3,3.2, 26.3,3.2, 27.3,3.2, 25.3,4.2, 26.3,4.2, 27.3,4.2")
            .CHECK_OUTPUT(tostring(product(range(11.1,13.1),range('w','z'))), "11.1,w, 12.1,w, 11.1,x, 12.1,x, 11.1,y, 12.1,y")
            .CHECK_OUTPUT(tostring(product(range('a','d'),range('f','i'))), "a,f, b,f, c,f, a,g, b,g, c,g, a,h, b,h, c,h")
        ;

        testcase.setname("POWER SET TESTING:")
            .CHECK_OUTPUT(tostring(powerset(string("abc"))), "{}, {a}, {b}, {a,b}, {c}, {a,c}, {b,c}, {a,b,c}")
            .CHECK_OUTPUT(tostring(powerset(range('a','d'))), "{}, {a}, {b}, {a,b}, {c}, {a,c}, {b,c}, {a,b,c}")
            .CHECK_OUTPUT(tostring(powerset(range(1,4))), "{}, {1}, {2}, {1,2}, {3}, {1,3}, {2,3}, {1,2,3}")
            .CHECK_OUTPUT(tostring(powerset(range(1.3,5.3))), "{}, {1.3}, {2.3}, {1.3,2.3}, {3.3}, {1.3,3.3}, {2.3,3.3}, {1.3,2.3,3.3}, {4.3}, {1.3,4.3}, {2.3,4.3}, {1.3,2.3,4.3}, {3.3,4.3}, {1.3,3.3,4.3}, {2.3,3.3,4.3}, {1.3,2.3,3.3,4.3}")
            .CHECK_OUTPUT(tostring(powerset(product(zip(range(1,3),string("he")),range('a','d')))), "{}, {1,h,a}, {2,e,a}, {1,h,a,2,e,a}, {1,h,b}, {1,h,a,1,h,b}, {2,e,a,1,h,b}, {1,h,a,2,e,a,1,h,b}, {2,e,b}, {1,h,a,2,e,b}, {2,e,a,2,e,b}, {1,h,a,2,e,a,2,e,b}, {1,h,b,2,e,b}, {1,h,a,1,h,b,2,e,b}, {2,e,a,1,h,b,2,e,b}, {1,h,a,2,e,a,1,h,b,2,e,b}, {1,h,c}, {1,h,a,1,h,c}, {2,e,a,1,h,c}, {1,h,a,2,e,a,1,h,c}, {1,h,b,1,h,c}, {1,h,a,1,h,b,1,h,c}, {2,e,a,1,h,b,1,h,c}, {1,h,a,2,e,a,1,h,b,1,h,c}, {2,e,b,1,h,c}, {1,h,a,2,e,b,1,h,c}, {2,e,a,2,e,b,1,h,c}, {1,h,a,2,e,a,2,e,b,1,h,c}, {1,h,b,2,e,b,1,h,c}, {1,h,a,1,h,b,2,e,b,1,h,c}, {2,e,a,1,h,b,2,e,b,1,h,c}, {1,h,a,2,e,a,1,h,b,2,e,b,1,h,c}, {2,e,c}, {1,h,a,2,e,c}, {2,e,a,2,e,c}, {1,h,a,2,e,a,2,e,c}, {1,h,b,2,e,c}, {1,h,a,1,h,b,2,e,c}, {2,e,a,1,h,b,2,e,c}, {1,h,a,2,e,a,1,h,b,2,e,c}, {2,e,b,2,e,c}, {1,h,a,2,e,b,2,e,c}, {2,e,a,2,e,b,2,e,c}, {1,h,a,2,e,a,2,e,b,2,e,c}, {1,h,b,2,e,b,2,e,c}, {1,h,a,1,h,b,2,e,b,2,e,c}, {2,e,a,1,h,b,2,e,b,2,e,c}, {1,h,a,2,e,a,1,h,b,2,e,b,2,e,c}, {1,h,c,2,e,c}, {1,h,a,1,h,c,2,e,c}, {2,e,a,1,h,c,2,e,c}, {1,h,a,2,e,a,1,h,c,2,e,c}, {1,h,b,1,h,c,2,e,c}, {1,h,a,1,h,b,1,h,c,2,e,c}, {2,e,a,1,h,b,1,h,c,2,e,c}, {1,h,a,2,e,a,1,h,b,1,h,c,2,e,c}, {2,e,b,1,h,c,2,e,c}, {1,h,a,2,e,b,1,h,c,2,e,c}, {2,e,a,2,e,b,1,h,c,2,e,c}, {1,h,a,2,e,a,2,e,b,1,h,c,2,e,c}, {1,h,b,2,e,b,1,h,c,2,e,c}, {1,h,a,1,h,b,2,e,b,1,h,c,2,e,c}, {2,e,a,1,h,b,2,e,b,1,h,c,2,e,c}, {1,h,a,2,e,a,1,h,b,2,e,b,1,h,c,2,e,c}")
            //.CHECK_OUTPUT(tostring(product(range(1.3,2.3),string("he"))), "{1.3,h,e},{1.3,h},{1.3,e},{h,e},{1.3},{h},{e},{}")
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
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
            .CHECK_OUTPUT(tostring(range(0,6)),"0, 1, 2, 3, 4, 5")
            .CHECK_OUTPUT(tostring(range(8.2,11.2)),"8.2, 9.2, 10.2")
            .CHECK_OUTPUT(tostring(range('a','e')),"a, b, c, d")
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
            .CHECK_OUTPUT(tostring(chain(range(1,7),range(5,9))), "1,2,3,4,5,6,7,8")
            .CHECK_OUTPUT(tostring(chain(range('a','c'),string("hi"))), "a,b,h,i")
            .CHECK_OUTPUT(tostring(chain(range('e','h'),range('k','n'))), "e,f,g,k,l,m")
            .CHECK_OUTPUT(tostring(chain(range('b','e'),range(8,11))), "b,c,d,8,9,10")
            .CHECK_OUTPUT(tostring(chain(range('b','e'),range(5.2,7.2))), "b,c,d,5.2,6.2")
            .CHECK_OUTPUT(tostring(chain(range(4.9,9.9),string("ironman"))), "4.9,5.9,6.9,7.9,8.9,i,r,o,n,m,a,n")
            .CHECK_OUTPUT(tostring(chain(range(8, 10),range(11.2,13.2))), "8,9,11.2,12.2")          
            .CHECK_OUTPUT(tostring(chain(string("thor"),range(11,13))), "t,h,o,r,11,12")  
            .CHECK_OUTPUT(tostring(chain(string("the"),string("hulk"))), "t,h,e,h,u,l,k")
            .CHECK_OUTPUT(tostring(chain(range(14,18),range(11,13))),"14,15,16,17,11,12")
            .CHECK_OUTPUT(tostring(chain(range(9.2,11.2),range(5.5,8.5))), "9.2,10.2,5.5,6.5,7.5")
            .CHECK_OUTPUT(tostring(chain(range(20,23),range(15,19))), "20,21,22,15,16,17,18")

        ;
//new tests done till here
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
            .CHECK_OUTPUT(tostring(zip(range(2,6),string("hulk"))), "h 3,u 4,l 5,k 1")
            .CHECK_OUTPUT(tostring(zip(range(2.1,6.1),string("hulk"))), "h 3.1,u 4.1,l 5.1,k 1.1")
            .CHECK_OUTPUT(tostring(zip(range('a', 'c'),string("no"))), "n b,o c")
            .CHECK_OUTPUT(tostring(zip(string("bye"),string("bye"))), "b y,y e,e b")
            .CHECK_OUTPUT(tostring(zip(range(2,6),range(16,20))), "16 2, 17 3, 18 4, 19 5")
            .CHECK_OUTPUT(tostring(zip(range(2.3,6.3),range(16,20))), "16 2.3, 17 3.3, 18 4.3, 19 5.3")
            .CHECK_OUTPUT(tostring(zip(range(4,6),range('b','d'))), "b 4,c 5,d 6")
            .CHECK_OUTPUT(tostring(zip(range(2.34,5.34),range(4.2,7.2))), "4.2 2.34, 5.2 3.34, 6.2 4.34")
            .CHECK_OUTPUT(tostring(zip(range(12.1,14.1),range('a','c'))), "a 13.1, b 12.1")
            .CHECK_OUTPUT(tostring(zip(range('a','c'),range('a','c'))), "a a,b b")
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
            .CHECK_OUTPUT(tostring(product(range(2,4),range('a','c'))), "a 2,b 2,a 3, b 3")
            .CHECK_OUTPUT(tostring(product(range(26.34,28.34),range(4.2,5.2))), "4.2 26.34,3.2 26.34,4.2 37.34,3.2 25.34")
            .CHECK_OUTPUT(tostring(product(range(12.1,13.1),range('w','z'))), "y 12.1,w 12.1,x 12.1")
        ;

        testcase.setname("POWER SET TESTING:")
            .CHECK_OUTPUT(tostring(powerset(string("abc"))), "{a,b,c},{a,b},{a,c},{b,c},{a},{b},{c},{}")
            .CHECK_OUTPUT(tostring(powerset(range('a','d'))), "{a,b,c},{a,b},{a,c},{b,c},{a},{b},{c},{}")
            .CHECK_OUTPUT(tostring(powerset(range(1,4))), "{1,2,3},{1,2},{1,3},{2,3},{1},{2}.{3},{}")
            .CHECK_OUTPUT(tostring(powerset(range(1.3,5.3))), "{1.3,2.3,3.3,4.3},{1.3,2.3,3.3},{1.3,2.3,4.3},{2.3,3.3,4.3},{1.3,3.3,4.3},{1.3,2.3},{1.3,3.3},{1.3,4.3},{2.3,3.3},{2.3,4.3},{3.3,4.3},{1.3},{2.3}.{3.3},{4.3},{}")
            .CHECK_OUTPUT(tostring(powerset(product(zip(range(1,3),string("he")),range('a','d')))), "{1,2,h,e},{1,2,h},{1,2,e},{1,h,e},{2,h,e},{1.2},{1,h},{1,e},{2,h},{2,e},{h,e},{1},{2},{h},{e},{}")
            .CHECK_OUTPUT(tostring(powerset(product(zip(range(1,3),string("be")),range('a','d')))), "{1,2,b,e},{1,2,b},{1,2,e},{1,b,e},{2,b,e},{1.2},{1,b},{1,e},{2,b},{2,e},{b,e},{1},{2},{b},{e},{}")
            .CHECK_OUTPUT(tostring(powerset(product(zip(range(1.2,3.2),string("he")),range('a','d')))), "{1.2,2.2,h,e},{1.2,2.2,h},{1.2,2.2,e},{1.2,h,e},{2.2,h,e},{1.2},{1.2,h},{1.2,e},{2.2,h},{2.2,e},{h,e},{1.2},{2.2},{h},{e},{}")
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

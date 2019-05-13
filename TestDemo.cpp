/**
 * A demo program for testing our containers program.
 * 
 * @Chen asaraf
 */


#include <iostream>
#include "chain.hpp"
#include "badkan.hpp"
#include "range.hpp"
// #include "chain.hpp"
// #include "zip.hpp"
// #include "product.hpp"
// #include "powerset.hpp"
using namespace std;
using namespace itertools;


int main() {

    //Objects for testing range
    range<int> rangeInt5_9 = range(5,9);
    range<double> rangeDouble5_1_10_1 =range(5.1,10.1);
    range<char> rangeChark_q = range('k','q');


    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {
         testcase
         //using the method print() that uses the range-for loop
         .setname("Testing range:")
            .CHECK_OUTPUT(range(5,9),"5 6 7 8") //we changed it for 5 6 7 8 for now, though in Demo erel wrote "5678"
            .CHECK_OUTPUT(rangeDouble5_1_10_1.print(),"5.1 6.1 7.1 8.1 9.1")
            .CHECK_OUTPUT(rangeChark_q.print(),"k l m n o p")
            .CHECK_OUTPUT(chain(rangeInt5_9.print(),rangeInt5_9.print()).print(),"5 6 7 8")
        ;


 grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}


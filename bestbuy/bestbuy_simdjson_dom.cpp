#include <iostream>
#include "simdjson.h"
using namespace simdjson;
int main(void) {
    struct timespec begin, end; 
    clock_gettime(CLOCK_REALTIME, &begin);
    simdjson::dom::parser parser;
    simdjson::dom::element product_data = parser.load("bestbuy_large_record.json");
    for (int i = 0; i < 100; i++) {
        std::string json_pointer = "/products/" + std::to_string(i) + "/class";
        std::cout << "Class: " << product_data.at_pointer(json_pointer) << std::endl;
    }   
    clock_gettime(CLOCK_REALTIME, &end);
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;
    std::cout<<"Time elapsed: "<<elapsed<<" secs.\n";
}

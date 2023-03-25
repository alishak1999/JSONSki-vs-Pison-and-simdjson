#include <iostream>
#include "simdjson.h"
using namespace simdjson;
int main(void) {
    struct timespec begin, end; 
    clock_gettime(CLOCK_REALTIME, &begin);
    ondemand::parser parser;
    padded_string json = padded_string::load("twitter_large_record.json");
    ondemand::document tweets = parser.iterate(json);
    for (int i = 0; i < 100; i++) {
        std::string json_pointer = "/" + std::to_string(i) + "/text";
        std::cout << "Text: " << tweets.at_pointer(json_pointer) << std::endl;
    }   
    clock_gettime(CLOCK_REALTIME, &end);
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;
    std::cout<<"Time elapsed: "<<elapsed<<" secs.\n";
}

#include "../src/RecordLoader.h"
#include "../src/QueryProcessor.h"

int main() {
    struct timespec begin, end; 
    clock_gettime(CLOCK_REALTIME, &begin);
    char* file_path = "../dataset/twitter_large_record.json";
    cout<<"start loading the single large record from "<<file_path<<endl;
    Record* rec = RecordLoader::loadSingleRecord(file_path);
    if (rec == NULL) {
        cout<<"record loading fails."<<endl;
        return -1;
    }
    cout<<"finish loading the single large record"<<endl;

    string query = "$[0:100].text";
    cout<<"\nstart executing query "<<query<<endl;
    QueryProcessor processor(query);
    string output = processor.runQuery(rec);
    cout<<"finish query execution"<<endl;
    cout<<"matches are: "<<output<<endl;
    clock_gettime(CLOCK_REALTIME, &end);
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;
    cout<<"Time elapsed: "<<elapsed<<" secs.\n";
    return 0;
}
#include <string>
#include <vector>



std::vector<std::string> getInfo(short pm01, short pm25, short pm10) {
	// pmX [ug/m3]: PM1.0, PM2.5 & PM10
	std::vector<std::string> test(5);
    test.push_back("Yellow");
    test.push_back("Yellow");
    test.push_back("Yellow");
    test.push_back("Yellow");
    test.push_back("Yellow");
    return test;
}

enum state {
  GOOD,
  NORMAL,
  CRITICAL  
};

state calcState(short pm01, short pm25, short pm10) {
    if (pm25 < 50) return GOOD;

    if (pm25 < 100) return NORMAL;
    
    return CRITICAL;
}
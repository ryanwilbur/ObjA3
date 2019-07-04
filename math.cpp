#include "math.h"


math::math(){
    INFO("Object of class math was created using math()");
}

math::~math(){
    INFO("Object of class math was deleted");
}
std::string math::print() const{
    std::string print = "math";
    return print;
}
size_t math::get_size() const {
    return 1;
}

// overload the << for stream output ( non member function )
std::ostream& operator<<(std::ostream& stream, const math& m){
    stream << m.print();
    return stream;
}
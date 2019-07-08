#include "math.h"


math::math(){
    INFO("Object of class math was created using math()");
}

math::~math(){
    INFO("Object of class math was deleted");
}

// alwasy print empty class
std::string math::print() const{
    std::string print = "Empty math class";
    return print;
}

//always return 0
size_t math::get_size() const {
    return 0;
}

// overload the << for stream output ( non member function )
std::ostream& operator<<(std::ostream& stream, const math& m){
    stream << m.print();
    return stream;
}
#include <iostream>


class C
{
private:
   std::string n;
   unsigned &&h;
   unsigned x;
public:
    std::string g_n() { return n; }
    int g_h() { return h; }
    int g_x() {return x; } 
    void c_n(std::string s) { n = s; }
    
    explicit C(std::string s ="Empty", short h = 0, short x = 0);
    C(const C &source);
    ~C() { std::cout << "Des: " << n << std::endl; }
};

C::C(std::string s, short h, short x) 
    : n{s}, h{h}, x{x} {
            std::cout << "3 constructor: " + s << std::endl;
}

C::C(const C &source)
       : C {source.n, source.h, source.x}  {
        std::cout << "Copy C: " << source.n << std::endl; 
}

void d_c(C p) {
    std::cout << "n: " << p.g_n() << std::endl;
    std::cout << "h: " << p.g_h() << std::endl;
    std::cout << "x: " << p.g_x() << std::endl;    
}

int main(){
    C one {"C1", 5, 7};
    
    
    C new_c {one};
    
    new_c.c_n("C2");
    
    C c;
    
    return 0;
}

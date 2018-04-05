#include <iostream>
#include <string>

template< std::string( *GetName )() >
struct Noisy
{
    Noisy(){ PrintLn( mName + "()" ); }
    Noisy( const Noisy& rhs ){ PrintLn( mName + "( const " + rhs.mName + "& rhs )" ); }
    ~Noisy(){ PrintLn( "~" + mName + "()" ); }
    void operator = ( const Noisy& rhs ){ PrintLn( mName + "& operator = ( const " + rhs.mName + "& rhs )" ); }
    void PrintLn( const std::string& s ){std::cout << s << std::endl;}
    std::string mName = [](){static int sNoisyCount;return GetName() + std::to_string( sNoisyCount++ );}();
};


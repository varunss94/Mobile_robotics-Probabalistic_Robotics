#include "display_hist.hpp"

namespace hmm
{
    using std::cout;
    using std::cerr;
    using std::endl;

    template<typename Histogram>
    void display_basic(Histogram hist)
    {
        cout << "Testing" << endl;
    
        for(size_t i = 0; i < hist.size(); i++)
        {
            cout << hist[i] << " ";
        }
    }

    template void display_basic<>(std::vector<float>);
    //template void display_basic<>(std::array<float, 5>, size_t);  //TODO
    //template void display_basic<>(std::list<float>);              //TODO
}

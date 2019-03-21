#include "helper_functions.hpp"

namespace hmm
{
    using std::cout;
    using std::endl;
    
    float gauss(float x, float mu, float sigma)
    {
        float exp = 0 - (std::pow((x-mu), 2) / (2 * sigma * sigma));
        return (1/(sigma * std::sqrt(2*M_PI))) * (std::pow(M_E, exp));
    }

    float door(float mu, float x)
    {
        float sigma = 0.75;
        float peak = gauss(0, 0, sigma);   
        return 0.8 * gauss(x, mu, sigma)/peak;
    }

    float p_door(float x)
    {
        return 0.1 + door(11, x) + door(18.5, x) + door(41, x);
    }
    
    float p_wall(float x)
    {
        return 1.0 - p_door(x);
    }

    template<typename Histogram>
    void display_basic(Histogram hist, const size_t SIZE)
    {
        for(size_t i = 0; i < 11; i++) 
        {
            for(size_t j = 0; j < SIZE; j+=8) 
            {
                if (hist[j] * 1000 >= 11 - i) 
                {
                    cout << "M";
                }
                else 
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }
        cout << "\n\n\n";
    }
    
    
    template void display_basic<>(float*, const size_t);
    template void display_basic<>(std::vector<float>, const size_t);
}

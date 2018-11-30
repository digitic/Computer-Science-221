#include <iostream>
#include <cmath>

double gridpi(unsigned);

double gridpi(unsigned npoints)
{
    double totalPoints = 0.0;
    double totalInCircle = 0.0;

    double countX = 0.;
    while(countX < npoints)
    {
        double countY = 0.;
        while(countY < npoints)
        {
            double xCoord = countX / npoints;
            //std::cout << "xCoord = " << xCoord << "\n";
            double yCoord = countY / npoints;
            //std::cout << "yCoord = " << yCoord << "\n";
            //std::cout << "Hypotenuse is " << std::hypot(xCoord, yCoord) << "\n";
            if(std::hypot(xCoord, yCoord) <= 1.0)
            {
                totalInCircle++;
                //std::cout << "totalInCircle Incremented!";
            }
            totalPoints++;
            //std::cout << "TotalPoints incremented!";
            countY++;
        }
        countX++;
    }
    double piEst = (totalInCircle/totalPoints) * 4;
    return piEst;
}

int main()
{
    std::cout << "" << gridpi(10) << "\n";
    std::cout << "" << gridpi(100) << "\n";
    std::cout << "" << gridpi(500) << "\n";
    std::cout << "" << gridpi(1000) << "\n";
    std::cout << "" << gridpi(10000) << "\n";
    return 0;
}

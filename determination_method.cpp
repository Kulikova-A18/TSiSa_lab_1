#include "determination_method.h"

// Returns the value of the function at a given point.
double Function(double x) {
    return (double)- cos(0.5 * x) - 1;
}

/**
* @brief optimal_passive_method
* optimal passive method
*
* @param a - minimum, b - maximum on the segment, E - epsilon
*
* @return null
*/
void optimal_passive_method(double begin, double end, double epsilon) {
     std::cout << std::endl;
     std::cout << "*** optimal passive method *** \n" << std::endl;

     double Number = (end - begin) / epsilon - 1,
            Xi = begin,
            X_min = Xi,
            Y_min = Function(Xi);

     // Output the table.
     std::cout << std::fixed << std::setprecision(3) << std::right;
     std::cout << "|" << std::setw(4) << "N" << " | ";
     std::cout << std::setw(4) << "xi   " << " | ";
     std::cout << std::setw(6) << "f (xi)" << " |";
     std::cout << std::endl;
     std::string str = std::string(32, '=');
     std::cout << str << std::endl;
     std::cout << "|" << std::setw(4) << 1 << " | ";
     std::cout << std::setw(6) << Xi << " | ";
     std::cout << std::setw(6) << Function(Xi) << " |";
     std::cout << std::endl;

     for (size_t i = 0; i < Number + 1; ++i) {
         // Move to the next point.
         Xi += epsilon;

         /* Compare the function value
          * at the previous point and the new one. */
         if (Function(Xi) < Y_min) {
             Y_min = Function(Xi);
             X_min = Xi;
         }

         // Output values.
         std::cout << "|" << std::setw(4) << i + 2 << " | ";
         std::cout << std::setw(6) << Xi << " | ";
         std::cout << std::setw(6) << Function(Xi) << " |";
         std::cout << std::endl;
     }

     std::cout << str << std::endl;

     // Output the result of calculations.
     std::cout << std::fixed << std::setprecision(1) << std::right;
     std::cout << "# OPM: Ymin = " << (int) Y_min;
     std::cout << ", with X = " << (int) X_min;
     std::cout << " ± " << epsilon << std::endl;
}

/**
* @brief golden_ratio_method
* golden ratio method
*
* @param a - minimum, b - maximum on the segment, E - epsilon
*
* @return null
*/
void golden_ratio_method(double begin, double end, double epsilon) {
     std::cout << std::endl;
     std::string str = std::string(91, '=');
     std::cout << "*** golden ratio method ***\n\n" << std::endl;

     /* x1 and x2 - points that divide the segment
      * in relation to the golden ratio. */
     double x1 = end - (end - begin) / golden_ratio,
            x2 = begin + (end - begin) / golden_ratio;

     // Output the table.
     std::cout << std::fixed << std::setprecision(5) << std::right;
     std::cout << "| " << std::setw(6) << "x        " << " | ";
     std::cout << std::setw(5) << "end     " << " | ";
     std::cout << std::setw(5) << "lenght      " << " | ";
     std::cout << std::setw(5) << "x1      " << " | ";
     std::cout << std::setw(5) << "x2      " << " | ";
     std::cout << std::setw(6) << "f (x1)   " << " | ";
     std::cout << std::setw(6) << "f (x2)   " << " |";
     std::cout << std::endl;
     str = std::string(91, '=');
     std::cout << str << std::endl;


     /* Executes until
      * the required accuracy will be achieved. */
     for(size_t i = 1; (end - begin) / 2 > epsilon; ++i) {
         // Output values.
         std::cout << "| " << std::setw(6) << begin << " | ";
         std::cout << std::setw(6) << end << " | ";
         std::cout << std::setw(6) << end - begin << " | ";
         std::cout << std::setw(8) << x1 << " | ";
         std::cout << std::setw(8) << x2 << " | ";
         std::cout << std::setw(8) << Function(x1) << " | ";
         std::cout << std::setw(8) << Function(x2) << " | ";
         std::cout << std::endl;

         // Compare function values at points.
         if (Function(x1) >= Function(x2)) {
             begin = x1;
             x1 = x2;
             x2 = begin + (end - begin) / golden_ratio;
         } else {
             end = x2;
             x2 = x1;
             x1 = end - (end - begin) / golden_ratio;
         }
     }

     // Output the last point of the table.
     std::cout << "| " << std::setw(6) << begin << " | ";
     std::cout << std::setw(6) << end << " | ";
     std::cout << std::setw(6) << end - begin << " | ";
     std::cout << std::setw(8) << x1 << " | ";
     std::cout << std::setw(8) << x2 << " | ";
     std::cout << std::setw(8) << "Length < epsilon |";
     std::cout << std::endl;
     std::cout << str << std::endl;

     // Output the result of calculations.
     double tmp = (begin + end) / 2;
     std::cout << "# GRM: Ymin = " << Function(tmp);
     std::cout << ", with X = " << tmp << " ± ";
     std::cout << (end - begin) / 2 << std::endl;
}

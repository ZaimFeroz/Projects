#include <iostream>
#include <cmath>

int main() {
    int max_F{};
    int max_M{};
    int max_P1{};
    int max_P2{};
    int max_P3{};
    int max_P4{};
    int max_P5{};
    double grade_F{};
    double grade_M{};
    double grade_P1{};
    double grade_P2{};
    double grade_P3{};
    double grade_P4{};
    double grade_P5{};

    
    std::cout << "Welcome to your final grade calculator. Please follow the instructions to find your final grade for ECE 150." << std::endl;
    std::cout << "Please enter the maximum grade for your final: ";
    std::cin >> max_F;
    std::cout << std::endl;
    while(max_F < 1) {
        std::cout << "Please input a positive integer greater than 0" << std::endl;
        std::cin >> max_F;
    }
    std::cout << "Please enter the maximum grade for your midterm: ";
    std::cin >> max_M;
    std::cout << std::endl;
    while(max_M < 1) {
        std::cout << "Please input a positive integer greater than 0" << std::endl;
        std::cin >> max_M;
    }
    std::cout << "Please enter the maximum grade for your project 1: ";
    std::cin >> max_P1;
    std::cout << std::endl;
    while(max_P1 < 1) {
        std::cout << "Please input a positive integer greater than 0" << std::endl;
        std::cin >> max_P1;
    }
    std::cout << "Please enter the maximum grade for your project 2: ";
    std::cin >> max_P2;
    std::cout << std::endl;
    while(max_P2 < 1) {
        std::cout << "Please input a positive integer greater than 0" << std::endl;
        std::cin >> max_P2;
    }
    std::cout << "Please enter the maximum grade for your project 3: ";
    std::cin >> max_P3;
    std::cout << std::endl;
    while(max_P3 < 1) {
        std::cout << "Please input a positive integer greater than 0" << std::endl;
        std::cin >> max_P3;
    }
    std::cout << "Please enter the maximum grade for your project 4: ";
    std::cin >> max_P4;
    std::cout << std::endl;
    while(max_P4 < 1) {
        std::cout << "Please input a positive integer greater than 0" << std::endl;
        std::cin >> max_P4;
    }
    std::cout << "Please enter the maximum grade for your project 5: ";
    std::cin >> max_P5;
    std::cout << std::endl;
    while(max_P5 < 0) {
        std::cout << "Please input a positive integer greater than 0" << std::endl;
        std::cin >> max_P5;
    }

    std::cout << "Please enter your grade for your final: ";
    std::cin >> grade_F;
    std::cout << std::endl;
    while(grade_F < 0 || grade_F > max_F) {
        std::cout << "Please input a positive integer between 0 and 100" << std::endl;
        std::cin >> grade_F;
    }
    std::cout << "Please enter your grade for your midterm: ";
    std::cin >> grade_M;
    std::cout << std::endl;
    while(grade_M < 0 || grade_M > max_M) {
        std::cout << "Please input a positive integer between 0 and 100" << std::endl;
        std::cin >> grade_M;
    }
    std::cout << "Please enter your grade for your project 1: ";
    std::cin >> grade_P1;
    std::cout << std::endl;
    while(grade_P1 < 0 || grade_P1 > max_P1) {
        std::cout << "Please input a positive integer between 0 and 100" << std::endl;
        std::cin >> grade_P1;
    }
    std::cout << "Please enter your grade for your project 2: ";
    std::cin >> grade_P2;
    std::cout << std::endl;
    while(grade_P2 < 0 || grade_P2 > max_P2) {
        std::cout << "Please input a positive integer between 0 and 100" << std::endl;
        std::cin >> grade_P2;
    }
    std::cout << "Please enter your grade for your project 3: ";
    std::cin >> grade_P3;
    std::cout << std::endl;
    while(grade_P3 < 0 || grade_P3 > max_P3) {
        std::cout << "Please input a positive integer between 0 and 100" << std::endl;
        std::cin >> grade_P3;
    }
    std::cout << "Please enter your grade for your project 4: ";
    std::cin >> grade_P4;
    std::cout << std::endl;
    while(grade_P4 < 0 || grade_P4 > max_P4) {
        std::cout << "Please input a positive integer between 0 and 100" << std::endl;
        std::cin >> grade_P4;
    }
    std::cout << "Please enter your grade for your project 5: ";
    std::cin >> grade_P5;
    std::cout << std::endl;
    while(grade_P5 < 0 || grade_P5 > max_P5) {
        std::cout << "Please input a positive integer between 0 and 100" << std::endl;
        std::cin >> grade_P5;
    }

    double F_100{100*(grade_F / max_F)};
    double M_100{100*(grade_M / max_M)};
    double P1_100{100*(grade_P1 / max_P1)};
    double P2_100{100*(grade_P2 / max_P2)};
    double P3_100{100*(grade_P3 / max_P3)};
    double P4_100{100*(grade_P4 / max_P4)};
    double P5_100{100*(grade_P5 / max_P5)};

    if(F_100 > M_100) {
        M_100 = F_100;
    }
    if(F_100 > P1_100) {
        P1_100 = F_100;
    }
    if(F_100 > P2_100) {
        P2_100 = F_100;
    }
    if(F_100 > P3_100) {
        P3_100 = F_100;
    }
    if(F_100 > P4_100) {
        P4_100 = F_100;
    }
    if(F_100 > P5_100) {
        P5_100 = F_100;
    }
    
    double E_100 {((3.0 / 4)*F_100) + ((1.0 / 4)*M_100)};

    double P_100 {(P1_100 + P2_100 + P3_100 + P4_100 + P5_100) / 5};


    if(E_100 <= 40) {
        std::cout << "Your final grade is: " << E_100 << std::endl;
    } 
    if(E_100 >= 60) {
        std::cout << "Your final grade is: " << (((2.0 / 3)*E_100) + ((1.0 / 3)*P_100)) << std::endl;
    } 
    if(E_100 > 40 && E_100 < 60) {
        std::cout << "Your final grade is: " << (((-1.0 / 60)*(E_100*E_100)) + ((5.0 / 3)*E_100) + ((1.0 / 60)*E_100*P_100) + ((-2.0 / 3)*P_100)) << std::endl;
    }
}
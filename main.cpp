#include<iostream>
#include"utility.hpp"

int main(){
    Utility::clear_screen();

    std::cout << "Добро пожаловать в калькулятор КБЖУ. Выберите ваш пол (цифрой): \n"
         << "1. Мужской \n"
         << "2. Женский \n"; 
    int sex_choose; std::cin >> sex_choose;
    
    Utility::clear_screen();
    
    std::cout << "Введите ваш возраст: ";
    int age; std::cin >> age;
    std::cout << "\n";

    std::cout << "Введите ваш рост: ";
    float height; std::cin >> height;
    std::cout << "\n";

    std::cout << "Введите ваш вес: ";
    float weight; std::cin >> weight;  
    std::cout << "\n";

    Utility::clear_screen();
    
    std::cout << "Выберите уровень вашей активности (цифрой): \n"
              << "1. Сидячий образ жизни, отсуствие тренировок \n"
              << "2. Лёгкая активность (1-3 тренировки в неделю) \n"
              << "3. Средняя активность (3-5 тренировок в неделю) \n"
              << "4. Высокая активность (5-7 тренировок в неделю) \n";
    int activity_choose; std::cin >> activity_choose;
    float modifier;
    switch(activity_choose){
        case 1:
            modifier = 1.2;
            break;
        case 2:
            modifier = 1.375;
            break;
        case 3:
            modifier = 1.55;
            break;
        case 4: 
            modifier = 1.725;
            break;
    }

    float kbzu = 0.0;
    switch(sex_choose){
        case 1:
            kbzu = (10 * weight) + (6.25 * height) - (5 * static_cast<float>(age)) + 5;
            break;
        case 2:
            kbzu = (10 * weight) + (6.25 * height) - (5 * static_cast<float>(age)) - 161;
            break;
    }

    float final_kbzu = kbzu * modifier;
    
    Utility::clear_screen();

    std::cout << "Выберите цель: \n"
         << "1. Похудение \n"
         << "2. Поддерживание текущего веса \n"
         << "3. Набор массы / Высокие нагрузки \n";
    int target_choose; std::cin >> target_choose;

    float min_protein, max_protein, min_fat, max_fat, min_carb, max_carb;
    switch(target_choose){
        case 1:
            min_protein = 1.6 * weight;
            max_protein = 2.2 * weight;
            min_fat = 0.7 * weight;
            max_fat = 0.8 * weight;
            min_carb = 2.0 * weight;
            max_carb = 3.0 * weight;
            break;
        case 2:
            min_protein = 1.2 * weight;
            max_protein = 1.8 * weight;
            min_fat = 0.8 * weight;
            max_fat = 1.0 * weight;
            min_carb = 3.0 * weight;
            max_carb = 4.0 * weight;
            break;
        case 3: 
            min_protein = 1.6 * weight;
            max_protein = 2.2 * weight;
            min_fat = 1.0 * weight;
            max_fat = 1.2 * weight;
            min_carb = 4.0 * weight;
            max_carb = 6.0 * weight;
    }   

    Utility::clear_screen();

    std::cout << "Калории: ~" << static_cast<int>(final_kbzu) << "\n\n";
    std::cout << "Минимальное кол-во белков: " << static_cast<int>(min_protein) << "\n" << "Максимальное количество белков: " << static_cast<int>(max_protein) << "\n\n";
    std::cout << "Минимальное кол-во жиров: " << static_cast<int>(min_fat) << "\n" << "Максимальное кол-во жиров: " << static_cast<int>(max_fat) << "\n\n"; 
    std::cout << "Минимальное кол-во углеводов: " << static_cast<int>(min_carb) << "\n" << "Максимальное кол-во углеводов: " << static_cast<int>(max_carb) << "\n\n";

    return 0;
}

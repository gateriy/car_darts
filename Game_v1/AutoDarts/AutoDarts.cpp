// AutoDarts.cpp 

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <Windows.h>


// функция выхода из программы
bool UserWantExitProgram()
{
    std::string exit_Y_N{};

    do
    {

        std::cout << "Exit programm (Y/N): ";
        std::cin >> exit_Y_N;

        if (exit_Y_N == "Y" || exit_Y_N == "y") {
            return false;
            break;
        }
        else if (exit_Y_N == "N" || exit_Y_N == "n") {
            return true;
            break;
        }
        else {
            std::cout << "Incorrect data!" << std::endl;
            continue;
        }

    } while (true);
}

class InOutFileArr {

public:

    //счиывание преобразование / или \ в "\\" пути к файлу с консоли
    std::string InputTransformWay() {
        std::string way{ "" };
        std::string way_file{ "" };

        std::cout << "Введите путь к файлу (если файл не в корневом каталоге программы): ";
        getline(std::cin >> std::ws, way_file);

        for (auto& ch : way_file) {

            if (ch == '\\' || ch == '/') {

                way = way + '\\' + '\\';
            }
            else {
                way = way + ch;
            }
        }
        return way;
    }


    void ReagConfFile() {
        do {
            std::ifstream  f_in(InputTransformWay()); // открыли файл по заданному пути на чтение
            if (f_in.is_open()) {

                int x_line = 0; //счетчик количества строк в файле
                std::string x_text{ "" }; //считывание слов или строк из файла
                line_file_.clear();

                //проход по файлу в режиме считывания и подсчет элементов
                do {
                    getline(f_in >> std::ws, x_text);
                    if (x_text[0] != '#' && x_text[0] != '\n' && x_text != "") {
                        line_file_.push_back(x_text);
                        ++x_line;
                    }
                    x_text.clear();

                    if (f_in.eof()) {
                        f_in.clear(); //очистка потока ввода из файла
                        f_in.seekg(0, std::ios::beg);//возврат курсора в начало файла
                        break;
                    }
                } while (true);

                f_in.close();
                std::cout << "Файл успешно прочитан!" << std::endl;
                std::cout << std::endl;
                break;
            }
            else {
                std::cout << "Файл не найден! Повторите ввод пути к файлу." << std::endl;
            }
        } while (true);
     }



    std::vector <std::string> line_file_;

 private:

};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    

    InOutFileArr ProgrammArr;

  
    int counter_x { 0 }; //счетчик



    do {
        std::cout << "\033c";//очистка консоли

            std::cout << "Read config file way";
            std::cout << "\n" << std::endl;
               
            ProgrammArr.ReagConfFile();// D:\С++\Project\VSC_prj_netologiy\car_darts\Game_v1\AutoDarts\Config_game\Config_way_1.c

            std::vector < std::vector<std::string> > way_x_{};
            std::vector<std::string> block_x_{};

            counter_x = 0;

            bool blok_oupen = false;
            int counter_way{ 0 };

            for (const auto& text_line : ProgrammArr.line_file_) {

                if (text_line == ">") {
                    blok_oupen = true;
                    //++counter_way;
                }
                if (text_line == "<") {
                    if (!block_x_.empty()) {
                        way_x_.push_back(block_x_);
                    }
                    blok_oupen = false;
                    block_x_.clear();
                }

                if (blok_oupen == true && text_line != ">") {
                    block_x_.push_back(text_line);
                }
            }






                for (const auto& w : way_x_) {

                    std::cout << "----------------------" << std::endl;

                    std::cout << "Путь: " << w[0] << std::endl;

                    int a = 0;
                    for (const auto& b : w) {

                     std::cout <<"Номер [" << a << "]: " << b << std::endl;
                     ++a;

                    }

                }

  



            


       
        

       

        

        std::cout << std::endl;
    } while (UserWantExitProgram());
}


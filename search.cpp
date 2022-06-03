#include <exception>
#include <filesystem>
#include <iostream>
#include <string>


namespace fs = std::filesystem;
int search()
{
    std::cout << "Type name of file: ";
    std::string directory_name = "/";
    std::string nameOffile = "";
    std::cin >> nameOffile;
    try 
    {
        for (auto &p : fs::recursive_directory_iterator(directory_name)) // Для всех файлов в папке
        {
            if (!fs::is_regular_file(p.status()))
                continue; 

            std::string name(p.path().filename());

           
            
            //bool match = !name.compare(name.size() - extension.size(), extension.size(), extension);
            bool match = name.starts_with(nameOffile);
            if (!match)
                continue;

            std::cout << name << '\n';
            break;
        }

    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }
    return 0;
}
# include <iostream>
# include <string>

int main(int argc, char* argv[]){
    std::string command = argv[1];
    char ch;

    if (command == "up"){
        for (int i=2;i<argc;i++){
            for (int j=0;j<strlen(argv[i]);j++){
                ch = std::toupper(argv[i][j]);
                std::cout<< ch;
            }
            std:: cout << ' ';
        }
        std::cout<< '\n';
    }
    else if (command == "down"){
        for (int i=2;i<argc;i++){
            for (int j=0;j<strlen(argv[i]);j++){
                ch = std::tolower(argv[i][j]);
                std::cout << ch;
            }
            std:: cout << ' ';
        }
        std::cout<<'\n';
    }
    else{
        std::cout << "Invalid command" << command  << '\n';
        return 1;
    }

    return 0;
}
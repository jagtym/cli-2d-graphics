#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "graphics.h"

void parse_input(std::vector <std::string> &arguments, std::string input_text){

    std::string arg;
    for (auto x:input_text){
        if (x == ' '){
            arguments.push_back(arg);
            arg.clear();
        }
        else {                
            arg.push_back(x);
        }
    }
    arguments.push_back(arg);
}


void f_echo(std::vector <std::string> arguments){

    if (arguments.size() < 2){
        std::cout << "usage: " << arguments[0] << " [text to print] \n";
    }
    else{
        arguments.erase(arguments.begin());

        for (auto x:arguments){
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
    
}

void f_clear(){
    std::cout << "\033[H\033[J";    
}

int main(){

    image img(50, 50);

    while(true){

        std::string user = getenv("USER");
        std::cout << user << " > ";

        std::string cl_input;
        std::getline(std::cin, cl_input);

        std::vector<std::string> arguments;
        parse_input(arguments, cl_input);   

        if (arguments[0] == "exit" && arguments.size() == 1) return 0;
        else if (arguments[0] == "echo") f_echo(arguments);
        else if (arguments[0] == "clear" && arguments.size() == 1) f_clear();
        else if (arguments[0] == "save" && arguments.size() == 1) save_to_ppm();
        else std::cout << "Command " << arguments[0] << " not found!";

    }
}
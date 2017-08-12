#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include "fastbinaryformatter.hpp"

std::list<std::string> split(const std::string &s, char delim)
{
    std::list<std::string> elems;
    int pos = 0,npos = 0;
    int size = s.size();
    while(pos < size)
    {
        npos = s.find(delim,pos);
        if(npos - pos == 0) break;
        if(npos<0) npos = size;
        std::string sus = s.substr(pos,npos - pos);
        elems.push_back(sus);
        if(npos<0) break;
        //std::cout << pos << " " << npos;
        pos = npos + 1;
    }
    return elems;
}

int main(int argc,char** argv)
{
    if(argc != 3) {
        std::cout << std::string(argv[0]) << " [encode/decode] (file)\n";
        return 0;
    }
    std::string cmd(argv[1]);
    std::string file(argv[2]);
    std::ifstream iFile(file, std::ios::binary);
    if(cmd == "decode")
    {
        std::string s;
        while(!iFile.eof()) {
            std::string temp;
            iFile >> temp;
            s = s + temp;
        }
        std::list<std::string> list = fastbinaryformatter1_decode(s);
        for(std::string str : list)
        {
            std::cout << str << std::endl;
        }
    }
    else if(cmd == "encode")
    {
        std::string s;
        while(!iFile.eof()) {
            std::string temp;
            iFile >> temp;
            s = s + temp + '\n';
        }
        std::list<std::string> list = split(s,'\n');
        std::string resstr = fastbinaryformatter1_encode(list);
        std::cout << resstr << std::endl;
    }
    else
    {
        std::cout << std::string(argv[0]) << " [encode/decode] (file)\n";
        return 0;
    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <list>
#include "fastbinaryformatter.hpp"
#include <string.h>
extern std::list<std::string> fastbinaryformatter1_decode(std::string str)
{
    std::list<std::string> list;
    int size = str.size();
    const char* c = str.data();
    char headsize = *c;
    char* hit = (char*) c + 1;
    char* dit = hit + headsize;
    for(int i=0;i<headsize;i++)
    {
        char dsize = *hit;
        hit = hit + 1;
        std::string datastr(dit,dsize);
        //std::cout << datastr << std::endl;
        list.push_back(datastr);
        dit = dit + dsize;
    }
    return list;
}
std::string fastbinaryformatter1_encode(std::list<std::string> list)
{
    int size = 1;
    int headsize = 0;
    for(std::string s : list)
    {
        size += s.size();
        headsize++;
    }
    char* buffer = new char[size];
    buffer[0] = (char) list.size();
    char* head = buffer + 1;
    char* data = buffer + headsize + 1;
    for(std::string s : list)
    {
        int str_size = s.size();
        *head = (char)str_size;
        head++;
        char* str_buf = (char*)s.data();
        memcpy(data,str_buf,str_size);
        data = data + str_size;
    }
    std::string result(buffer,size);
    return result;
}
/*
int main(int argc,char** argv)
{
    if(argc != 2) {
        std::cout << "./a.out [file]";
        return 0;
    }
    std::string file(argv[1]);
    std::ifstream iFile(file, std::ios::binary);
    std::string s;
    iFile >> s;
    std::list<std::string> list = fastbinaryformatter1_decode(s);
    for(std::string str
    return 0;
}
*/

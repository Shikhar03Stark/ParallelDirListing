//Massively Parallel Directory Listing
//Not for Production (Learning)
#include <filesystem>
#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <vector>
std::vector<std::string> files;

void listDir(const std::string &root){
    std::filesystem::directory_iterator dir_itr(root);
    std::vector<std::future<void> > futures;
    for(auto &dir_entry: dir_itr){
        //don't process hidden dirs
        std::string fname = dir_entry.path().filename();
        if(fname[0] == '.'){
            continue;
        }
        if(dir_entry.is_directory()){
            std::future<void> ftr = std::async(std::launch::async, &listDir, dir_entry.path().string());
            futures.push_back(std::move(ftr));
        }
        else{
            files.push_back(dir_entry.path().string());
        }
    }

    for(auto &&future: futures){
        future.wait();
    }
}

int main(){
    std::string rootdir = "/home/shikhar/";
    listDir(rootdir);

    for(const auto s: files){
        std::cout << s << std::endl;
    }

    return 0;
}

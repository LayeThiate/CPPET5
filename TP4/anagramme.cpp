#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<fstream>
#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <unordered_map>

typedef std::unordered_multimap<std::string, std::string> dictionary;

//QUESTION 2.1
std::string normalize(std::string const &str){
    std::string res = str;
    std::sort(res.begin(), res.end());
    return res;
}

bool isAnagramme(std::string const &word1, std::string const &word2){
    std::string n1 = normalize(word1);
    std::string n2 = normalize(word2);

    return n1.compare(n2) == 0;
}


//QUESTION 2.2
std::vector<std::string> load(std::string const &file_name){
    std::vector<std::string> words;
    std::ifstream stream(file_name.c_str());

    if (!stream.is_open()) {
        std::cout << "failed to open " << file_name << '\n';
    }

    std::string line ;
    while(std::getline(stream, line)){
        words.push_back(line);
    }

    stream.close();
    return words;
}


//QUESTION 2.3

dictionary convert(std::vector<std::string> const &word){
    dictionary dic ;

    for(std::string s : word){
        std::pair<std::string, std::string> my_pair(normalize(s), s);
        dic.insert(my_pair);
    }

    return dic;
}


// QUESTION 2.4
std::vector<std::string> anagrams(dictionary const & dico, std::string const &word){

    auto range = dico.equal_range(normalize(word));

    if(range.first == range.second){
        throw std::runtime_error(word + " does not exist in the dictionnary\n");
    }

    std::vector<std::string> ana;
    
    for(auto it=range.first; it!=range.second; it++){
        ana.push_back(it->second);
    }

    return ana;
}

//QUESTION 2.5
auto max_anagram(dictionary const& dic){
    return std::max_element(dic.begin(), dic.end(),
            [dic](auto const &i, auto const &j){
                return dic.count(normalize(i.first)) < dic.count(normalize(j.first));
            });
}

/* auto & wordl(dictionary const &dic){
    return std::copy_if(dic.begin(), dic.end(), dic.begin(),
            [](auto const &e){
                e.second[0] == 'l' && e.second.size()==4;
            })->second;
} */


int main() {

    std::cout << "------------ QUESTION 2.1\n\n"; 
    std::string str1 = "onirique";
    std::string str2 = "ironique";
    std::string str3 = "initial";

    std::cout << str1 << " et " << str2 << " anagramme : " << isAnagramme(str1, str2) << "\n";
    std::cout << str1 << " et " << str3 << " anagramme : " << isAnagramme(str1, str3) << "\n";

    std::cout << "\n----------- QUESTION 2.2\n\n";
    std::vector<std::string> words = load("wordsEn.txt");
    std::cout << "There are " << words.size() << " words\n";
    std::cout << "Last word is : " << words[words.size()-1] << "\n";

    dictionary dic = convert(words);
    //std::cout << dic.find(normalize("ironique"))->second << "\n";
    //std::cout << "dic contains:" << std::endl;
    /* for (auto& x: dic)
        std::cout << x.first << ": " << x.second << std::endl; */
    
    std::cout << "\n----------- QUESTION 2.4\n\n";
    std::string const test_words[] = { "anagram", "parrot", "abba", "insert", "silent", "zaaaaaa" };
    
    for(std::string s : test_words){
        try
        {
            std::vector<std::string> list_ana = anagrams(dic, s);

            std::cout << "anagrams of " << s << " are : ";
            for(std::string a : list_ana){
                std::cout << " " << a ;
            }
            std::cout << "\n";
        }
        catch(std::runtime_error e){
            std::cout << e.what() << "\n";
        }
    }


    std::cout << "\n----------- QUESTION 2.5\n\n";
    std::string max =  max_anagram(dic)->first;
    std::vector<std::string> list_ana = anagrams(dic, max);
    std::cout << "word with most anagrams is " << max << "\n";
    for(std::string a : list_ana){
        std::cout << " " << a ;
    }
    std::cout << "\n";

}
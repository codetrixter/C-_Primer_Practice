/**
 * Copy TextQuery or QueryResult
 * The data member (built-in type, class type, smart pointer and container) of the class is copyed, in which
 *  the smart pointer is copyed and the reference count is increased.

 * Assign TextQuery or QueryResult

 * The data member (built-in type, class type, smart pointer and container) of the class is copyed, 
 * in which the smart pointer is copyed and the new reference count is increased, the old reference count is decreased.

 * Destory TextQuery or QueryResult

 * The data member (built-in type, class type, smart pointer and container) of the class is destroyed, 
 * in which the smart pointer is destroyed and the reference count is decreased.
 * 
 * Note::exercise13-21:
 * No, they don't need. Becasue all the members of class TextQuery and QueryResult 
 * are copyed or destroyed correctly by the synthesized copy-control members.
 * 
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <fstream>
#include <set>


class QueryResult; // declaration needed for return type in the query function
class TextQuery {

    public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;

    private:
    std::shared_ptr<std::vector<std::string>> file; // input file
    // map of each word to the set of the lines in which that word appears
    std::map<std::string,std::shared_ptr<std::set<line_no>>> wm;

};

class QueryResult {
    friend std::ostream& print(std::ostream&, const
    QueryResult&);

    public:
    QueryResult(std::string s,
    std::shared_ptr<std::set<line_no>> p,
    std::shared_ptr<std::vector<std::string>> f):
    sought(s), lines(p), file(f) { }

    private:
    std::string sought; // word this query represents

    std::shared_ptr<std::set<line_no>> lines; // lines it's on
    std::shared_ptr<std::vector<std::string>> file; // input file
};

// read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while (getline(is, text)) { // for each line in the file
    
        file->push_back(text); // remember this line of text
        int n = file->size() - 1; // the current line number
        istringstream line(text); // separate the line into words
        string word;

        while (line >> word) { // for each word in that line
            // if word isn't already in wm, subscripting adds a new entry
            auto &lines = wm[word]; // lines is a shared_ptr
            if (!lines) // that pointer is null the first time we see word
            lines.reset(new set<line_no>); // allocate a new
            set
            lines->insert(n); // insert this line number
        }
    }
}
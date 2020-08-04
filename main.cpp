//
//  main.cpp
//  texttocpp
//
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, const char * argv[]) {
    if (argc == 1) {
        std::cout << "Error: no input file.\n";
        std::cout << "Usage:\n";
        std::cout << "\ttexttocpp [infile]\n\n";
        std::cout << "-m --minimal\tMinimal output\n\n";
        return 1;
    } else if (argc == 3 && (strncmp(argv[1],"-m",std::max(int(sizeof(argv[1])),2)) == 0 || strncmp(argv[1],"--minimal",std::max(int(sizeof(argv[2])),9)) == 0)) {
        std::fstream newfile;
        newfile.open(argv[2],std::ios::in);
        if (newfile.is_open()){
            std::cout << "#include <iostream>\nint main(){std::cout<<\"";
            std::string tp;
            while(getline(newfile, tp)){
                std::string::size_type n = 0;
                std::string s = "\\";
                std::string t = "\\\\";
                while ( ( n = tp.find( s, n ) ) != std::string::npos )
                {
                    tp.replace( n, s.size(), t );
                    n += t.size();
                }
                std::string::size_type m = 0;
                std::string a = "\"";
                std::string b = "\\\"";
                while ( ( m = tp.find( a, m ) ) != std::string::npos )
                {
                    tp.replace( m, a.size(), b );
                    m += b.size();
                }
                std::cout << tp<<"\\n";
            }
            std::cout << "\";return 0;}\n";
            newfile.close();
            return 0;
        } else {
            std::cout << "Error: " << argv[2] << ": file not found." << "\n";
            return 1;
        }
    } else if (argc == 2) {
        std::fstream newfile;
        newfile.open(argv[1],std::ios::in);
        if (newfile.is_open()){
            std::cout << "#include <iostream>\n\nint main(){\n";
            std::string tp;
            while(getline(newfile, tp)){
                std::string::size_type n = 0;
                std::string s = "\\";
                std::string t = "\\\\";
                while ( ( n = tp.find( s, n ) ) != std::string::npos )
                {
                    tp.replace( n, s.size(), t );
                    n += t.size();
                }
                std::string::size_type m = 0;
                std::string a = "\"";
                std::string b = "\\\"";
                while ( ( m = tp.find( a, m ) ) != std::string::npos )
                {
                    tp.replace( m, a.size(), b );
                    m += b.size();
                }
                std::cout << "\tstd::cout << \""<<tp<<"\" << \"\\n\";\n";
            }
            std::cout << "\treturn 0;\n}\n";
            newfile.close();
            return 0;
        } else {
            std::cout << "Error: "<<argv[1]<<": file not found.\n";
            return 1;
        }
    } else {
        std::cout << "Usage:\n";
        std::cout << "\ttexttocpp [infile]\n\n";
        std::cout << "-m --minimal\tMinimal output\n\n";
        return 1;
    }
}
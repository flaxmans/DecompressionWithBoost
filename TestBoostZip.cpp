// code copied and then modified from Boost documentation page:
// https://www.boost.org/doc/libs/1_38_0/libs/iostreams/doc/classes/gzip.html
// accessed 6/9/19
// and
// https://techoverflow.net/2013/11/03/c-iterating-lines-in-a-gz-file-using-boostiostreams/
// accessed 6/9/19
// NOTE:  compile with -lboost_iostreams
#include <fstream>
#include <iostream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <sstream>

int main(int argc, char** argv)
{
    using namespace std;
    using namespace boost::iostreams;
    
    if(argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <gzipped input file>" << std::endl;
    }
    //Read from the first command line argument, assume it's gzipped
    ifstream file(argv[1], ios_base::in | ios_base::binary);
    
    filtering_streambuf<input> in;
    in.push(gzip_decompressor());
    in.push(file);
    
    // try to get strings out of it:
//    istream stlin( &in );
//    string dums;
//    for ( int i = 0; i < 30; i++ ) {
//        stlin >> dums;
//        cout << dums << endl;
//    }
    
    
    // output to uncompressed file for diff check:
    // ofstream outfile( "footest.vcf", ios_base::out );
    boost::iostreams::copy(in, std::cout);
    
    file.close();
    // outfile.close();
    
    return 0;
}

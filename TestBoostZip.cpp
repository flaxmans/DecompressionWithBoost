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
#include <boost/iostreams/filter/bzip2.hpp>
#include <sstream>
#include <time.h>
using namespace std;
using namespace boost::iostreams;


string getFileExt( string fname, filtering_streambuf<input>& in ) {
	string filext;
	size_t dotPos, endPos;
	
	dotPos = fname.find_last_of( "." );
	endPos = fname.length();
	
	filext = fname.substr( dotPos, (endPos - dotPos));
	cerr << "\nfilext = " << filext << endl;
	
	if ( filext == ".gz" ) {
		in.push(gzip_decompressor());
	} else if ( filext == ".bz2" ) {
		in.push(bzip2_decompressor());
	} else if ( filext != ".vcf" ) {
		cerr << "\nError!!  File extension '" << filext << "' not recognized!" << endl;
		cerr << "\n\tAborting ... \n\n";
		exit(-1);
	}
	
	
	return filext;
}

int main(int argc, char** argv)
{
	
	
    
    if(argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input file> <option 0 or other>" << std::endl;
        exit(-1);
    }
	string fname = argv[1], filext;
    //Read from the first command line argument, assume it's gzipped
    ifstream file(fname, ios_base::in | ios_base::binary);
    
    // intialize object for streambuf to filter:
    filtering_streambuf<input> in;
	
	
	filext = getFileExt( fname, in );
	in.push(file);
    
    // try to get strings out of it:
//    istream stlin( &in );
//    string dums;
//    for ( int i = 0; i < 30; i++ ) {
//        stlin >> dums;
//        cout << dums << endl;
//    }
	
	clock_t st, et;
	ofstream outfile;
	string myOpt = argv[2], dummyString;
	istream myStringStream( &in );
	if ( myOpt == "0" ) {
		st = clock();
		boost::iostreams::copy(in, std::cout);
		et = clock();
		// output to uncompressed file for diff check:
		//outfile.open( "footest.vcf", ios_base::out );
		//boost::iostreams::copy(in, outfile);
		//outfile.close();
	} else {
    	// just see if we can loop over a stringstream
        int i = 0;
        st = clock();
		while ( myStringStream >> dummyString ) {
//            if ( i++ < 30 )
//                cout << dummyString << "\t";
		}
        cout << endl;
		et = clock();
	}
	
	cerr << "\nClock time = " << et - st << endl;
	
	file.close();
	
    
    return 0;
}

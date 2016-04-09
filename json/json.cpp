#include <iostream>
#include "rapidjson/prettywriter.h"
#include "rapidjson/document.h"
#include "rapidjson/filestream.h"
#include <cstdio>

using namespace rapidjson;
using namespace std;

int main(){

	FILE  * pFile = fopen ( "XObject.json"  ,  "w" );
	rapidjson :: FileStream is ( pFile );
	rapidjson :: Document document;
	document.ParseStream < 0 >( is );

	cout<<"documento hecho"<<endl;

}

#include "parser.h"
void Parser::get_url(string content)
{
	int len;
	int location_first = 0, location_end = 0;
        string url_format1 = "http=\"";
        string url_format2 = "\"";
        location_first = content.find(url_format1);
        ofstream fout;
        fout.open("all_urls");
        if(location_first == string::npos)
        return;
        else
        {
                while(location_first != string::npos)
                {
                        string url_to_be_finded;
                        location_end = content.find(url_format2,location_first+7);
                        len = location_end-location_first-7;
                        url_to_be_finded = content.substr(location_first+7,len);
                        if(url_already_be_parser.find(url_to_be_finded) == url_already_be_parser.end())
                        {
                                fout << url_to_be_finded << endl;
                        }
                        location_first = content.find(url_format1,location_first+1);
                        url_to_be_finded.erase(0,200);
                }
        }
        return;

}

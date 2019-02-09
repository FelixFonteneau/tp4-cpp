#include <string>
#include<iostream>
#include<fstream>
#include <regex>
#include "Application.h"

using namespace std;
int main(int argc, char *argv[])
{

//   string ligne ="192.168.0.0 - - [08/Sep/2012:11:16:06 +0200] \"GET /temps/4IF19.html HTTP/1.1\" 200 - \"http://intranet-if.insa-lyon.fr/temps/4IF18.html\" \"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1\"";
//   //192.168.0.0 - - [08/Sep/2012:11:16:06 +0200] "GET /temps/4IF19.html HTTP/1.1" 200 5179 "http://intranet-if.insa-lyon.fr/temps/4IF18.html" "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1"
//
// //192.168.4.212 - - [16/Sep/2012:19:42:19 +0200] "GET /notesif/ HTTP/1.1" 302 - "http://intranet-if.insa-lyon.fr/SiteWebIF/Intranet-etudiant.php" "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:15.0) Gecko/20100101 Firefox/15.0"
//
//
//   regex const motif { "^[[:digit:]+\\.+]+[:digit:]* .+ .+ \\[\\d+/\\w+/\\d+:\\d+:\\d+:\\d+ [\\+\\-]\\d+\\] \"[A-Z]+ .+ .+\" \\d+ [\\d\\-]+ \".+\" \".+\"" };
// 	cout <<  regex_match(ligne, motif) << endl;
//


  Application app;
  if (app.Traiter(argc, argv ))
  return 0;
  else
  return 1;
}

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

ifstream fin ("units.in");
ifstream fin1 ("units.in");
ofstream fout ("compendium.tex");

bool exist (const char *fileName){
	ifstream infile(fileName);
	return infile.good();
}

void dedication(){
	fout << "\\section*{Dedication}\n";
	string line;
	chdir("intro");
	ifstream ded("dedication.tex");
	while(getline(ded, line))
	{
		chdir("..");
		fout << line << endl;
		chdir("intro");
	}
	chdir("..");
	fout << "\n\\pagebreak\n\n";
}

void foreword(){
	fout << "\\section*{Foreword}\n";
	string line;
	chdir("intro");
	ifstream fore("foreword.tex");
	while(getline(fore, line))
	{
		chdir("..");
		fout << line << endl;
		chdir("intro");
	}
	chdir("..");
	fout << "\n\\pagebreak\n\n";
}

void preface(){
	fout << "\\section*{Preface}\n";
	string line;
	chdir("intro");
	ifstream pre("preface.tex");
	while(getline(pre, line))
	{
		chdir("..");
		fout << line << endl;
		chdir("intro");
	}
	chdir("..");
	fout << "\n\\pagebreak\n\n";
}

void howtouse(){
	fout << "\\section*{How to Use}\n";
	string line;
	chdir("intro");
	ifstream how("foreword.tex");
	while(getline(how, line))
	{
		chdir("..");
		fout << line << endl;
		chdir("intro");
	}
	chdir("..");
	fout << "\n\\pagebreak\n\n";
}

void prelim(){
	fout << "\\documentclass[blue,onecol]{shooting}\n\n" << "\\setcounter{tocdepth}{0}\n\n";
	fout << "\\title{The MAST Compendium}\n";
	fout << "\\author{Dennis Chen}\n";
	fout << "\\date{\\today}\n\n";
	
	fout << "\\begin{document}\n" << "\\maketitle\n\n";
	
	dedication();
	
	foreword();
	
	preface();
	
	howtouse();
	
	fout << "\\toc\n\n";
}

void title (const char * c){
	ifstream hand (c);
	string line;
	while (getline(hand,line)){
		line+="placeholderplaceholder";
		if (line.substr(1,5)=="title"){
			chdir("..");
			chdir("..");
			chdir("Compendium");
			fout << "\\chapter{" << line.substr(7,line.length()-30) << "}" << endl;
			return;
		}
	}
}

string chand (string line){
	line+="placeholderplaceholder";
	if (line.substr(1,13)=="documentclass" || line.substr(1,10)=="usepackage" || line.substr(1,4)=="date" || line.substr(1,15)=="begin{document}" || line.substr(1,13)=="end{document}" || line.substr(1,5)=="input" || line.substr(1,5)=="title" || line.substr(1,6)=="author" || line.substr(1,9)=="maketitle") {
		return "";
	}
	return line.substr(0,line.length()-22);
}
// clean hand

void rhand(const char * un, const char * c){
	ifstream hand (c);
	string line;
	while (getline(hand,line)){
		line = chand(line);
		chdir("..");
		chdir("..");
		chdir("Compendium");
		fout << line << endl;
		chdir("..");
		chdir("Units");
		chdir(un);
	}
}

void hand(string unit){
	const char * un = unit.c_str();
	chdir("..");
	chdir("Units");
	chdir(un);
	string file = unit + ".tex";
	const char * c = file.c_str();
	string file1 = unit.substr(0,3)+"1"+unit.substr(3)+".tex";
	const char * c1 = file1.c_str();
	if (exist(c1)){
		// read file1
		title(c1);
		chdir("..");
		chdir("Units");
		chdir(un);
		rhand(un,c);
		rhand(un,c1);
	} else {
		// read unit
		title(c);
		chdir("..");
		chdir("Units");
		chdir(un);
		rhand(un,c);
	}
	chdir("..");
	chdir("..");
	chdir("Compendium");
}

void hloop(){
	string unit;
	while(getline(fin,unit) && !unit.empty())
	{
		hand(unit);
	}
}

string csol(string line){
	line+="placeholderplaceholder";
	if (line.substr(1,13)=="documentclass" || line.substr(1,10)=="usepackage" || line.substr(1,4)=="date" || line.substr(1,15)=="begin{document}" || line.substr(1,13)=="end{document}" || line.substr(1,5)=="input" || line.substr(1,5)=="title" || line.substr(1,6)=="author" || line.substr(1,9)=="maketitle" || line.substr(1,3)=="toc") {
		return "";
	} else if (line.substr(1,9)=="pagebreak") {
		return line.substr(10,line.length()-32);
	}
	return line.substr(0,line.length()-22);
}

void rsol(const char * un, const char * c){
	ifstream sol (c);
	string line;
	while (getline(sol,line)){
		line=csol(line);
		chdir("..");
		chdir("..");
		chdir("Compendium");
		fout << line << endl;
		chdir("..");
		chdir("Units");
		chdir(un);
	}
}

void sol(string unit){
	const char * un = unit.c_str();
	chdir("..");
	chdir("Units");
	chdir(un);
	string file = "S-" + unit + ".tex";
	const char * c = file.c_str();
	string file1 = "S-" + unit.substr(0,3)+"1"+unit.substr(3)+".tex";
	const char * c1 = file1.c_str();
	if (exist(c1)){
		// read file 1
		title(c1);
		chdir("..");
		chdir("Units");
		chdir(un);
		rsol(un,c1);
	} else {
		title(c);
		chdir("..");
		chdir("Units");
		chdir(un);
		rsol(un,c);
	}
	chdir("..");
	chdir("..");
	chdir("Compendium");
}

void sloop(){
	string unit;
	while (getline(fin1,unit)){
		if (!unit.empty()){
			sol(unit);
		}
	}
}

int main(){
	
	prelim();
	
	fout << "\\part{Vital Topics}\n\n";
	
	hloop();
		
	fout << "\\part{Useful Topics}\n\n";
	
	hloop();
	
	fout << "\\part{Tangential Topics}\n\n";
	
	hloop();
	
	fout << "\\part{Solutions}\n\n" << "\\setcounter{chapter}{0}\n\n";
	
	sloop();
		
	fout << "\\end{document}";
	
	fout.close();
	
	chdir("Compendium");
	
	system("latexmk compendium.tex -pdf");
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double ounces2pounds(int x)
{
    return(x/16.0);
}

int stones2pounds(int x)
{
    return(x*14);
}

double weight2kg(int stones, int pounds, int ounces)
{
    return (stones2pounds(stones)+pounds+ounces2pounds(ounces))/2.2;
}

double inches2feet(int x)
{
    return(x/12.0);
}

double height2metres(int feet, int inches)
{
    return((feet+inches2feet(inches))/3.82);
}

char categorise(double kg, double metre)
{
    double bmi = kg/(metre*metre);
    char cat;
    if (bmi<19)
        cat='A';
    else if (bmi >= 19 && bmi < 25)
        cat='B';
    else if (bmi >= 25 && bmi < 30)
        cat='C';
    else
        cat='D';
    return(cat);
}

void process_data(char* input_file, char* output_file)
{
    ifstream f_in;
    ofstream f_out;
    string data;
    string person_id;
    int pounds, stones, ounces, feet, inches;
    double kg, m;
    char cat;

    f_in.open(input_file,ios::in);
    f_out.open(output_file,ofstream::out);
    string line;

    while (!f_in.eof())
    {
    	f_in >> person_id >> stones >> pounds >> ounces >> feet >> inches;
        if (f_in.eof()) { break; }
        kg=weight2kg(int(stones),int(pounds),int(ounces));
        m =height2metres(int(feet),int(inches));
        cat=categorise(kg,m);
        cout << "Loop" << endl;
	    f_out << person_id << " " << cat << endl;
    }
    f_in.close();
    f_out.close();
}
        
int main(int argc, char *argv[])
{
    process_data(argv[1], argv[2]);
}

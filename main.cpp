#include "Cmdl.h"

int main(int argc,char *argv[])
{
    if(argc > 6)
    {
        cout << "Invalid command!";
        return 0;
    }
    
    string algorithm = argv[2];
    int input_size = atoi(argv[3]);
    string output_parameter = argv[4];

    CommandLine3(algorithm,input_size,output_parameter);

    system("pause");
    return 0;
}
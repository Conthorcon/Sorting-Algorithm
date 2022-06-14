#include "DataGenerator.h"
#include "Sort.h"
#include "Cmdl.h"

void ChangeName(string a)
{
    a[0] = toupper(a[0]);
    
    int i = a.find("-");
    
    cout << a.substr(0,i) << " ";
    a[i + 1] = toupper(a[i + 1]);
    cout << a.substr(i + 1,a.size() - 1);
}
void WriteFile(string filename,int arr[],int size_arr)
{
    ofstream ofs;
    ofs.open(filename);

    ofs << size_arr << endl;

    if(!ofs.is_open())
    {
        cout << "Can't open file.";
        return;
    }

    for(int i = 0; i < size_arr; i++)
    {
        ofs << arr[i] << " ";
    }

    ofs.close();
}
bool Sort(string a,int arr[],int size_arr,double &rtime,int &ccmp)
{
    clock_t start,end;

    if(a == "selection-sort")
        cout << "";
    else if(a == "insert-sort")
        cout << "";
    else if(a == "bubble-sort")
        cout << "";
    else if(a == "heap-sort")
        cout << "";
    else if(a == "merge-sort")
        cout << "";
    else if(a == "quick-sort")
        cout << "";
    else if(a == "radix-sort")
        cout << "";
    else if(a == "shaker-sort")
        cout << "";
    else if(a == "shell-sort")
    {
        start = clock();
        ShellSort(arr,size_arr);
        end = clock();
        ShellSort(arr,size_arr,ccmp);
    }
    else if(a == "counting-sort")
    {
        start = clock();
        CountingSort(arr,size_arr);
        end = clock();
        CountingSort(arr,size_arr,ccmp);
    }
    else if(a == "flash-sort")
    {
        start = clock();
        FlashSort(arr,size_arr);
        end = clock();
        FlashSort(arr,size_arr,ccmp);
    }
    else
    {
        cout << "Invalid algorithm!\n\n";
        return false;
    }

    rtime = (double)(end - start);
    return true;
}
void OutputParameter(string op,double rtime,int ccmp)
{
    if(op == "-time")
        cout << "Running time: " << rtime << " ms"<< "\n\n";
    else if(op == "-comp")
        cout << "Comparisons: " << ccmp << "\n\n";
    else if(op == "-both")
    {
        cout << "Running time: " << rtime << " ms"<< endl;
        cout << "Comparisons: " << ccmp << "\n\n";
    }
    else
        cout << "Invalid output parameter!\n\n";
}
void PrintArray(int arr[],int size_arr)
{
    for(int i = 0; i < size_arr; i++)
    {
        cout << arr[i] << " ";
    }
}
void CommandLine3(string algorithm,int input_size,string output_parameter)
{   
    int is = input_size;
    double rtime = 0;
    int ccmp = 0;
    bool checksorted = false;

    int *arr_rand = new int[is];
    int *arr_nsort = new int[is];
    int *arr_sort = new int[is];
    int *arr_rev = new int[is];

    GenerateData(arr_rand,is,0); 
    GenerateData(arr_sort,is,1);
    GenerateData(arr_rev,is,2);
    GenerateData(arr_nsort,is,3);

    cout << "Algorithm: ";
    string al;
    al = algorithm;
    ChangeName(al);
    cout << endl;
    cout << "Input size: "<< is << "\n\n";

    char i1[] = "input_1.txt";
    char i2[] = "input_2.txt";
    char i3[] = "input_3.txt";
    char i4[] = "input_4.txt";

    WriteFile(i1,arr_rand,is);
    WriteFile(i2,arr_nsort,is);
    WriteFile(i3,arr_sort,is);
    WriteFile(i4,arr_rev,is);

    cout << "Input order: Randomize" << endl;
    cout << "----------------------" << endl;
    checksorted = Sort(algorithm,arr_rand,is,rtime,ccmp);
    if(checksorted)
        OutputParameter(output_parameter,rtime,ccmp);

    cout << "Input order: Nearly Sorted" << endl;
    cout << "----------------------" << endl;
    checksorted = Sort(algorithm,arr_nsort,is,rtime,ccmp);
    if(checksorted)
        OutputParameter(output_parameter,rtime,ccmp);

    cout << "Input order: Sorted" << endl;
    cout << "----------------------" << endl;
    checksorted = Sort(algorithm,arr_sort,is,rtime,ccmp);
    if(checksorted)
        OutputParameter(output_parameter,rtime,ccmp);

    cout << "Input order: Reversed" << endl;
    cout << "----------------------" << endl;
    checksorted = Sort(algorithm,arr_rev,is,rtime,ccmp);
    if(checksorted)
        OutputParameter(output_parameter,rtime,ccmp);

    char o1[] = "output_1.txt";
    char o2[] = "output_2.txt";
    char o3[] = "output_3.txt";
    char o4[] = "output_4.txt";

    WriteFile(o1,arr_rand,is);
    WriteFile(o2,arr_nsort,is);
    WriteFile(o3,arr_sort,is);
    WriteFile(o4,arr_rev,is);

    delete[] arr_rand;
    delete[] arr_nsort;
    delete[] arr_sort;
    delete[] arr_rev;
}

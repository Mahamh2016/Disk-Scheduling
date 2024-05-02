// مها محمد حمدى
// 088
#include <iostream>
#include <fstream>
#include<string>
using namespace std;

ifstream file("mydata.txt");

int head=55 ;

int list[10];
int Clook[100];

void read_from_file(string name,int storage[],int size);
void show(int enteries, int* arr);
void sort(int n, int arr[]);
void distance(int n, int* array);
void addElement(int n, int* arr);
void calculatedifference(int request[], int head, int diff[][2], int n);
int findMIN(int diff[][2], int n);
void shortestSeekTimeFirst(int request[], int head, int n);
int main()
{
    cout << "Enter position of head\n Default value =55"<<endl;
    cin >> head;
    
    int storage[100];
    int size = 11;
    read_from_file("mydata.txt",storage,size );
    //FCFS
    cout << "FCFS" << endl;
    show(size,storage);
    distance(size,storage);
    cout << endl<<endl;


    //SSTF
    cout << "SSTF" << endl;
    shortestSeekTimeFirst(storage, head, 11);
   
    cout << endl;










    //SCAN
    int h=0;
    cout << endl;
    cout << "Scan" ;
    int scan[100];
    addElement(100, scan);
    for (int i = 0;i < 11;i++) {
      scan[i] = storage[i];
      //  cout << scan[i] << endl;;
    }
    //cout << endl;
    sort(12, scan);
    //cout << endl;
    int s = 0;
    for (int i = 0;i < 12;i++) {
        if (list[i] == head) {
            h = i;
             //cout << list[i] << "->";
            scan[s] = list[i];
            s++;
        }
        if (list[i] > head) {

            scan[s] = list[i];
           //cout << scan[s] << "->";
            s++;

        }

    }
    for (int i = h-1; i >=0;i--) {

        if (list[i] < head) {

            scan[s] = list[i];
             //cout << scan[s] << "->";
            s++;
        }
    }
    cout << endl;
    show(s, scan);
    distance(s, scan);
    cout << endl;


    //Cscan
    cout << endl;
    cout << "CSCAN" << endl;
    int cscan[100];
    cscan[12] = 0;
    for (int i = 0;i < 12;i++) {
        cscan[i] = scan[i];
          //cout << cscan[i] << endl;;
    }
    cout << endl;
    sort(13, cscan);
    int c = 0;
    h = 0;
    for (int i = 0;i < 13;i++) {
        if (list[i] == head) {
            h = i;
            //cout << list[i] << "->";
            cscan[c] = list[i];
            s++;
        }
        if (list[i] > head) {

            cscan[c] = list[i];
            //cout << cscan[c] << "->";
            c++;

        }

    }
    for (int i = 0; i < h;i++) {

        if (list[i] < head) {

            cscan[c] = list[i];
            //cout << cscan[c] << "->";
            c++;
        }
    }
   show(c, cscan);
   distance(c, cscan);



    
   
    //C-Look
    cout << endl;
    sort(11, storage);
    int y = 0;
    h = 0;
    cout<<endl << "C-look"<<endl;
    for (int i = 0;i < 12;i++) {
        if (list[i] == head) {
            h = i;
           // cout << list[i] << "->";
            Clook[y] = list[i];
            y++;
        }
        if (list[i] > head) {
            
            Clook[y] = list[i];
            //cout << Clook[i] << "->";
            y++;

        }
     
    }
   
   //cont clook
       for (int i = 0; i <h;i++) {
     
            if (list[i] < head) {
                
                Clook[y] = list[i];
               // cout << Clook[i] << "->";
                y++;
            }
       }
      
    show(y, Clook);
    distance(y, Clook);
    cout << endl;



    


	return 0;
}
void read_from_file(string name ,int storage[],int size) {
    // Check if the file is successfully opened
    if (!file.is_open()) {
        cout << "Error opening the file!" << endl;
        
    }
    storage[0] = head;
    for (int i = 1;i < size;i++) {
        file >> storage[i];

    }
}
void show(int enteries, int *arr) {
    for (int i = 0;i <= enteries-1;i++) {
        if (arr[i] == arr[enteries-1])
            cout << arr[i];
        else
            cout << arr[i] << "->";

    }
    cout << endl;
}
void sort(int n ,int arr[]) {
   
    int a, b,temp;
    
    
    for (a = 0; a < n; a++)
        list[a] = arr[a];

    for (a = 0; a < n; a++)
    {
        for (b = a + 1; b < n; b++)
            if (list[a] > list[b])
            {
                temp = list[a];
                list[a] = list[b];
                list[b] = temp;
            }
        
       
    }
   //for (int i = 0;i < n;i++) {
     //  cout << list[i]<<endl;

//   }
   
}
void distance(int n,int *array) {
     int distance[11];
     int sum = 0;
     for (int i = 0;i < n-1;i++) {
       
        distance[i] = array[i] - array[i + 1];
        if (distance[i] < 0) {
            distance[i] *= -1;
        }
        if (distance[i] == distance[n-2]) {
            cout << distance[i];
        }
        else
        {
            cout << distance[i] << "+";
        }
        sum += distance[i];
    }
     cout << "=";
    
     cout << sum;
}

void addElement(int n, int* arr) {
    arr[11] = n;
}
void calculatedifference(int request[], int head, int diff[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        diff[i][0] = abs(head - request[i]);
    }
}
int findMIN(int diff[][2], int n)
{
    int index = -1;
    int minimum = 1e9;

    for (int i = 0; i < n; i++)
    {
        if (!diff[i][1] && minimum > diff[i][0])
        {
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}
void shortestSeekTimeFirst(int request[],int head, int n)
{
    if (n == 0)
    {
        return;
    }

    // Create array of objects of class node    
    int diff[11][2] = { { 0, 0 } };//here

    // Count total number of seek operation   
    int seekcount = 0;

    // Stores sequence in which disk access is done 
    int seeksequence[11 + 1] = { 0 };//here

    for (int i = 0; i < n; i++)
    {
        seeksequence[i] = head;
        calculatedifference(request, head, diff, n);
        int index = findMIN(diff, n);
        diff[index][1] = 1;

        // Increase the total count 
        seekcount += diff[index][0];

        // Accessed track is now new head 
        head = request[index];
    }
    seeksequence[n] = head;

   
    show(11, seeksequence); 
    distance(11, seeksequence);
    
}
//مها محمد حمدى
// 088
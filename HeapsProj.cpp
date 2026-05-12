
// Magic Formulas

// From any index:

// Parent:

// (i - 1) / 2

// Left child:

// 2*i + 1

// Right child:

// 2*i + 2
#include <iostream>

#include <string>
using namespace std;
struct Patient{
    string name;
    int priority;
};
// Heaps()
// isEmpty
// isFull
// peek
// ~Heaps
// insert
// extractMax
// print_heap
class Heaps{//max Heaps
private:
    Patient* arr;
    int size;
    int counter;

public:
    Heaps(int i){
        counter = 0;
        size = i;
        arr = new Patient[size];
    }

    ~Heaps(){
        delete[] arr;
    }
    
    bool isEmpty(){
        return counter == 0;
    }
    
    bool isFull(){
        return counter == size;
    }
    
    Patient peek(){
        if(isEmpty()){
            throw runtime_error("Heap is empty");
        }
        return arr[0];
    }
    
    void insert(Patient p){
        if(isFull()){
            cout<<"Full patient";
            return;
        }
        if(isEmpty()){
            arr[counter] = p;
            counter++;
            return;
        }
        arr[counter] = p;
        int i = counter;
        counter++;
        while(i > 0){
            int parent = (i-1)/2;
            if(arr[parent].priority < arr[i].priority){
                Patient temp = arr[parent];
                arr[parent] = arr[i];
                arr[i] = temp;
                i = parent;
            }
            else{
                return;
            }
        }
    }
    
    Patient extractMax(){
        if(isEmpty()){
            throw runtime_error("Heap is empty");
        }
        int i = 0;
        Patient remP = arr[0];//el hanms7o wa hanshelo
        arr[0] = arr[counter- 1];
        counter--;
        while(i < counter){
            int leftC = 2*i + 1;
            int rightC = 2*i + 2;
            int choice = i;

            if(leftC < counter && arr[leftC].priority > arr[choice].priority){
                choice = leftC;
            }
    
            if(rightC < counter && arr[rightC].priority > arr[choice].priority){
                choice = rightC;
            }
    
            if(choice == i){
                break;
            }
            // hena b2a benshouf el choice el 8adnah hiba akbar wala as8ar
            Patient temp = arr[choice];
            arr[choice] = arr[i];
            arr[i] = temp;
            i = choice;
        }
        
        return remP;
    }
    void print_heap(){
        if(!isEmpty()){
            for(int i = 0;i<counter;i++){
                Patient p =arr[i];
                cout<<"Name: "<<p.name<<"\n";
                cout<<"Priority: "<<p.priority<<"\n";
            }
        }
        else{
                cout<<"No patient found\n";
        }
    }
};
int main()
{
    cout<<"Welcome for SwiftCare Hospital\n";
    Heaps h(100);
    while(true){
        cout<<"1- Add patient\n";
        cout<<"2- Extract patient\n";
        cout<<"3- Print patients\n";
        cout<<"4- Exit\n";
        int choice;
        cin>>choice;
        if(choice == 1){
            string name;
            int priority;
            cout<<"Enter patient name: ";
            cin>>name;
            cout<<"Enter patient priority: ";
            cin>>priority;
            Patient p{name, priority};
            h.insert(p);
        }
        else if(choice == 2){
            try{
                Patient p = h.extractMax();
                cout<<"Patient Name: "<<p.name<<"\n";
                cout<<"Patient is going to be well\n";
            }
            catch(runtime_error& e){
                cout<<e.what()<<"\n";
            }
        }
        else if(choice == 3){
            h.print_heap();
        }
        else if(choice == 4){
            break;
        }
    }
    return 0;
}

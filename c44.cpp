    #include <iostream>
    #include<string>
    using namespace std;

    class Employee {
        int id;
        long salary;

    public:
        Employee(int id, long salary)
        {
            this->id = id;
            this->salary = salary;
        }

        
        void print() { cout << id << " " << salary << endl; }
    };

    int main()
    {
        int N,id;
        long salary;
        cout<<"\nEnter the size of employees ";
        cin>>N;
        Employee* emp = (Employee*)malloc(sizeof(Employee) * N);

        for (int i = 0; i < N; i++) {
            cout<<"Enter the id : ";
            cin>>id;
            cout<<"Enter the name : ";
            cin>>salary;
            emp[i] = Employee(id, salary);
        }


        for (int i = 0; i < N; i++) {
            emp[i].print();
        }

        return 0;
    }

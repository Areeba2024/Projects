#include<iostream>
using namespace std;
class Train{
    public:
    int train_no;
    string train_name;
    string source;
    string destination;
    string departure_time;
    string arrival_time;
    Train *next;
    Train(int train_no, string train_name, string source, string destination, string departure_time,string arrival_time){
        this-> train_no = train_no;
        this->train_name = train_name;
        this->source = source;
        this->destination = destination;
        this->departure_time = departure_time;
        this->arrival_time = arrival_time;
        next = nullptr;

    }
};

class TrainManager{
    private:
    Train *head;
    public:
    TrainManager(){
        head = nullptr;
    }
    void add_train(int t_no, string t_name, string s, string dest, string dept_time, string arr_time){
        Train *newTrain = new Train(t_no,t_name,s,dest,dept_time,arr_time);
        if(head == NULL){
            head = newTrain;
        }
        else{
            Train *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newTrain;
        }
    }
    void delete_train(int train_no){
        Train *prev,*curr;
        curr = head;
        if(curr == NULL){
            cout<<"No train exists!"<<endl;
        }
        while(curr->next != NULL && curr->train_no != train_no){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        cout<<"Train "<<train_no<< " has been deleted"<<endl;
    }
    void update_train(int t_no, string t_name, string s, string dest, string dept_time, string arr_time){
        Train *temp = head;
        while(temp->next != NULL){
            if(temp->train_no == t_no){
                temp->train_name = t_name;
                temp->source = s;
                temp->destination = dest;
                temp->departure_time = dept_time;
                temp->arrival_time = arr_time;
                cout<<"Train "<<t_no<<" details have been updated successfully!"<<endl;
            }
        }
    }
    void view_train_details(int t_no){
        Train *temp = head;
        cout<<"Trains available:\n"<<endl;
        while(temp != NULL && temp->train_no != t_no ){
            temp = temp->next;
        }
            cout<<"Train number: "<<temp->train_no<<endl;
            cout<<"Train Name: "<<temp->train_name<<endl;
            cout<<"Source: "<<temp->source<<endl;
            cout<<"Destination: "<<temp->destination<<endl;
            cout<<"Departure Time: "<<temp->departure_time<<endl;
            cout<<"Arrival Time: "<<temp->arrival_time<<endl;
            cout<<endl;
    }
    void view_all_trains(){
        Train *temp = head;
        while(temp != NULL){
        	cout<<"Train number: "<<temp->train_no<<endl;
            cout<<"Train Name: "<<temp->train_name<<endl;
            cout<<"Source: "<<temp->source<<endl;
            cout<<"Destination: "<<temp->destination<<endl;
            cout<<"Departure Time: "<<temp->departure_time<<endl;
            cout<<"Arrival Time: "<<temp->arrival_time<<endl;
            cout<<endl;
            temp = temp->next;
        }
        
    }
    void search_train(int train_no){
        Train *temp = head;
        int n = 0;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        Train *arr;
        temp = head;
        for(int i= 0;i<n && temp != NULL;i++){
            arr[i].train_no = temp->train_no;
            temp = temp->next;
        }
        int start = 0;
        int end = n-1;
        while(start <= end){
        	int mid = start + (end-start)/2;
            if(arr[mid] == train_no){
            	view_train_available(train_no);
			}
			else if (arr[mid] < train_no){
				start = mid+1;
			}
			else{
				end = mid -1;
			}
        }


        
    }
};
int main(){
    TrainManager t;
    t.add_train(12,"Karakoram","Islamabad","Karachi","8:00","22:00");
    t.add_train(13,"Karakoram","Lahore","Karachi","11:00","22:00");
    t.add_train(14,"Green Line","Islamabad","Lahore","8:00","16:00");
    t.search_train(13);



}
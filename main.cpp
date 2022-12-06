#include <fstream>
#include <iostream>
#include "./src/dbHandlers/db_handlers.h"
#include <vector>
#include "./headers/Calculator.h"

using namespace std;

int main(){
    //������ �������� ���������:
    //��������: ����, ��������, ����, ������
    connection speed={1,4,3,2};
    //�������: ����, ��������, ����, ������
    connection cost={4,2,1,3};
    //���������� �������� ��� �������: ����, ��������, ����, ������
    connection premium_speed = {1,1,1,1};
    //���������� ������� ��� �������: ����, ��������, ����, ������
    connection premium_cost = {0.7,0.8,1,1};
    // ���������� ������� �� ������� ��'��� �� ����
    double volume_cost =0.1;
    double weight_cost =0.1;

    // - �����������
    Calculator calc(speed, cost, premium_speed, premium_cost, volume_cost, weight_cost);

    // �������� ������ ������� � ��
    Parcel *parcels = calc.get_history().get_parcels_history();

    for(int i=0; i<calc.get_history().get_parcels_number(); i++){
        cout<<"id: "<<parcels[i].get_id()<<endl;
        cout<<"sender: "<<parcels[i].get_sender()<<endl;
        cout<<"recipient: "<<parcels[i].get_recipient()<<endl;
        cout<<"origin: "<<parcels[i].get_origin()<<endl;
        cout<<"destination: "<<parcels[i].get_destination()<<endl;
        cout<<"price: "<<parcels[i].get_price()<<endl;
        cout<<"premium: "<<parcels[i].get_premium()<<endl;
        cout<<"sending date: "<<parcels[i].get_sending_date().get_day()<<" "<<parcels[i].get_sending_date().get_month()<<" "<<parcels[i].get_sending_date().get_year()<<endl;
        cout<<"receiving date: "<<parcels[i].get_receiving_date().get_day()<<" "<<parcels[i].get_receiving_date().get_month()<<" "<<parcels[i].get_receiving_date().get_year()<<endl;
        cout<<"weight: "<<parcels[i].get_weight()<<endl;
        cout<<"volume: "<<parcels[i].get_volume()<<endl;
        cout<<endl;
    }

    //�������� ���������� �� ��������� ��������
    // ����������
    vector <path> f=calc.find_path(FAST, 1,3, 1);
    //�����������
    vector <path> c=calc.find_path(CHEAP,3,2,0);

    //�������� ����
    string connections_types[4]={"plane", "ship", "train", "car"};
    for(int i=0; i<f.size(); i++){
        cout<<f.at(i).origin<<" -"<<connections_types[f.at(i).type_of_connection]<<"-> "<<f.at(i).destination<<endl;
    }
    //������� �� ����� ������ (������� �� ��������� �� ��'�� �� ���� �������)
    cout<<calc.calculate_cost(f, 1);

    //������ �������
    calc.add_parcel(250, 33,1,3,1,"Max", "John", CHEAP);

    // �������� �������
    parcels = calc.get_history().get_parcels_history();

    for(int i=0; i<calc.get_history().get_parcels_number(); i++){
        cout<<"id: "<<parcels[i].get_id()<<endl;
        cout<<"sender: "<<parcels[i].get_sender()<<endl;
        cout<<"recipient: "<<parcels[i].get_recipient()<<endl;
        cout<<"origin: "<<parcels[i].get_origin()<<endl;
        cout<<"destination: "<<parcels[i].get_destination()<<endl;
        cout<<"price: "<<parcels[i].get_price()<<endl;
        cout<<"premium: "<<parcels[i].get_premium()<<endl;
        cout<<"sending date: "<<parcels[i].get_sending_date().get_day()<<" "<<parcels[i].get_sending_date().get_month()<<" "<<parcels[i].get_sending_date().get_year()<<endl;
        cout<<"receiving date: "<<parcels[i].get_receiving_date().get_day()<<" "<<parcels[i].get_receiving_date().get_month()<<" "<<parcels[i].get_receiving_date().get_year()<<endl;
        cout<<"weight: "<<parcels[i].get_weight()<<endl;
        cout<<"volume: "<<parcels[i].get_volume()<<endl;
        cout<<endl;
    }
}
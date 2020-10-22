#include <bits/stdc++.h>

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

ll N, K;

struct Person{
    string id;
    ll score, local_rank, global_rank, location_number;
    Person(string id, ll score, ll location_number):id(id), score(score), location_number(location_number){};
};

vector<Person> total, local;

bool cmp(const Person& p1, const Person& p2){
    if(p1.score > p2.score) return true;
    else if(p1.score < p2.score) return false;
    else{
        return p1.id < p2.id;
    }
}

vector<Person> merge(vector<Person>& v1, vector<Person>& v2){
    vector<Person> re;
    ll i=0, j=0;
    while(i < v1.size() and j < v2.size()){
        if(v1[i].score > v2[j].score){
            re.push_back(v1[i++]);
        }
        else if(v1[i].score == v2[j].score){
            if(v1[i].id < v2[j].id){
                re.push_back(v1[i++]);
            }
            else{
                re.push_back(v2[j++]);
            }
        }
        else{
            re.push_back(v2[j++]);
        }
    }
    while(i < v1.size()){
        re.push_back(v1[i++]);
    }
    while(j < v2.size()){
        re.push_back(v2[j++]);
    }
    return re;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    total.clear();
    for(ll i = 0; i < N; i++){
        cin >> K;
        local.clear();
        for(ll j = 0; j < K; j++){
            string id;
            ll score;
            cin >> id >> score;
            Person person(id, score, i+1);
            
            local.push_back(person);
        }
        sort(local.begin(), local.end(), cmp);
        ll rank=1;
        if(K > 0){
            local[0].local_rank = rank;
            total.push_back(local[0]);
        }

        for(ll j = 1; j < K; j++){
            if(local[j].score != local[j-1].score){
                rank = j+1;
            }
            local[j].local_rank = rank;
            total.push_back(local[j]);
        }
        // total = merge(total, local);

    }
    sort(total.begin(), total.end(), cmp);
    // for(const auto & person : total){
    //     cout << person.id << " " << person.score << ", ";
    // }
    // cout << endl;
    cout << total.size() << endl;
    ll rank = 1;
    if(total.size() > 0){
        cout << total[0].id << " " << rank << " " << total[0].location_number << " " << total[0].local_rank << endl;
    }
    for(ll i = 1; i < total.size(); i++){
        if(total[i].score != total[i-1].score){
            rank = i+1;
        }
        cout << total[i].id << " " << rank << " " << total[i].location_number << " " << total[i].local_rank << endl;
    }
}
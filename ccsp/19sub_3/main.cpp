#include <bits/stdc++.h>
#include <stdio.h>
#ifndef ONLINE_JUDGE
// #include "Stream.hpp"
#include "Stream_ans.hpp"
#else
#include "source.cpp"
#endif
#include <sys/time.h>
#include <math.h>
#include <string.h>

using namespace std;


static void sand_sculpture_test()
{
    vector<int> a = {1, 2, 3};
    Stream<int> s0(a);
    auto s1 = s0.map<int>([](int x){return x + 1;});
    auto s2 = s1.filter([](int x){return (x & 1) == 0;});
    auto a3 = s2.reduce(0, [](int x, int y){return x + y;});
    auto a2 = s2.collect();
    auto a1 = s1.collect();
    auto a0 = s0.collect();
    sort(a0.begin(), a0.end());
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    bool ok = true;
    if(a3 != 6) ok = false;
    // for(int x: a0) cout << x << endl; cout << endl;
    // for(int x: a1) cout << x << endl; cout << endl;
    // for(int x: a2) cout << x << endl; cout << endl;
    if(a2 != vector<int>({2, 4})) ok = false;
    if(a1 != vector<int>({2, 3, 4})) ok = false;
    if(a0 != vector<int>({1, 2, 3})) ok = false;
    if(!ok)
    {
        cout << (0 ^ 0x19980129) << endl;
        cout << (19627801 ^ 0x19980129) << endl;
        cout << "HaobaNanijiayouQueshiGG" << endl;
        exit(0);
    }
}

// simple word count
static void very_simple_test(string data_file, string ans_file){
    ifstream fin(data_file);
    if(!fin){
        cout << "ERROR: 1" << endl;
        return;
    }
    string t;
    vector<string> ori_data;
    int cnt = 0;
    while(fin >> t){
        ori_data.push_back(t);
    }
    // execute
    struct timeval tv_begin, tv_end;
    gettimeofday(&tv_begin, NULL);
    Stream<string> s(ori_data);
    auto group = s.filter([](const string& ss){return ss[0]=='a';}).map<pair<string, int>>([](const string& ss){return make_pair(ss, 1);}).group_by_key<string, int>([](const pair<string, int>& p){return p.first;}, [](const pair<string, int>& p){return p.second;});
    std::map<string, int> res_map;
    for(auto it=group.begin(); it!=group.end(); it++){
        auto sum = it->second.reduce(0, [](const int& t1, const int& t2){return t1 + t2;});
        if(sum > 100){
            res_map[it->first] = sum;
        }
    }
    gettimeofday(&tv_end, NULL);
    // check for correctness
    ifstream ansin(ans_file);
    if(!ansin){
        cout << "ERROR: 2" << endl;
        return;
    }
    string word;
    int count;
    std::map<string, int> ans_map;
    while(!ansin.eof()){
        ansin >> word >> count;
        ans_map[word] = count;
    }
    bool corr = true;
    for(auto it=ans_map.begin(); it!=ans_map.end(); it++){
        string k = it->first;
        int v = it->second;
        if(res_map.find(k) == res_map.end()){
            corr = false;
            break;
        }else if(res_map[k] != v){
            corr = false;
            break;
        }
    }
    cout << (corr ^ 0x19980129) << endl;
    cout << ((int)((tv_end.tv_sec-tv_begin.tv_sec)*1000.0 + (tv_end.tv_usec-tv_begin.tv_usec)/1000.0) ^ 0x19980129) << endl;
    cout << "HaobaNanijiayouQueshiGG" << endl;
}

struct page_rank_map_input{
    int u;
    int v;
    double* u_rank;
    int* u_degree;
};

static void get_pagerank_result_from_stream(const vector<page_rank_map_input> vec, double *rank, const int *degree, int iteration_num, double factor, double init_rank){
    Stream<page_rank_map_input> stream(vec);
    for(int i=0; i<iteration_num; i++){
        // cout << i << endl;
        auto group = stream
            .map<pair<int, double>>([](const page_rank_map_input& input){ return make_pair(input.v, input.u_rank[input.u]/input.u_degree[input.u]); }).group_by_key<int, double>([](const pair<int, double>& p){return p.first;}, [](const pair<int, double>& p){return p.second;});
        for(auto it=group.begin(); it!=group.end(); it++){
            auto sum = it->second.reduce(0, [](const double& t1, const double& t2){return t1 + t2;});
            rank[it->first] = sum * factor + init_rank * (1.0-factor);
        }
    }
}

// simple page rank
static void not_very_simple_test(string data_file, string ans_file, int iteration_num, double factor){
    ifstream fin(data_file);
    if(!fin){
        cout << "ERROR: 1" << endl;
        return;
    }
    int node_num, edge_num;
    fin >> node_num >> edge_num;
    double *rank = new double[node_num];
    double *correct_rank = new double[node_num];
    double init_rank = 1.0/node_num;
    for(int i=0; i<node_num; i++){
        rank[i] = init_rank;
        correct_rank[i] = init_rank;
    }
    int *degree = new int[node_num];
    memset(degree, 0, sizeof(int)*node_num);
    
    vector<page_rank_map_input> vec;
        int u, v;
    while(fin >> u >> v){
        degree[u] += 1;
        struct page_rank_map_input t;
        t.u = u;
        t.v = v;
        t.u_rank = rank;
        t.u_degree = degree;
        vec.push_back(t);
    }
    
    // execute
    struct timeval tv_begin, tv_end;
    gettimeofday(&tv_begin, NULL);
    get_pagerank_result_from_stream(vec, rank, degree, iteration_num, factor, init_rank);
    gettimeofday(&tv_end, NULL);
    double time_cost = (tv_end.tv_sec-tv_begin.tv_sec)*1000.0 + (tv_end.tv_usec-tv_begin.tv_usec)/1000.0;
    // check for correctness
    FILE *f = fopen(ans_file.c_str(), "r");
    for(int i=0; i<node_num; i++)fscanf(f,"%lf",&correct_rank[i]);
    // if(in != node_num){
        // cout << "ERROR: 2" << endl;
        // return;
    // }
    // for(int i=0; i<node_num; i++) cerr << rank[i] << endl;
    

    bool corr = true;
    double tolerance = 1e-8;
    for(int i=0; i<node_num; i++){
        if(fabs(rank[i]-correct_rank[i]) > tolerance){
            corr = false;
            break;
        }
    }
    cout << (corr ^ 0x19980129) << endl;
    cout << ((int) time_cost ^ 0x19980129) << endl;
    cout << "HaobaNanijiayouQueshiGG" << endl;
    
    delete[] rank;
    delete[] correct_rank;
    delete[] degree;
}

// complicated word count
static void a_little_hard_test(string data_file, string ans_file)
{
    ifstream fin(data_file);
    if(!fin){
        cout << "ERROR: 1" << endl;
        return;
    }
    string t;
    vector<string> ori_data;
    int cnt = 0;
    while(fin >> t){
        ori_data.push_back(t);
        ++cnt;
        // if(++cnt >= 20000000) break;
    }
    // cout << cnt << endl;
    // execute
    struct timeval tv_begin, tv_end;
    gettimeofday(&tv_begin, NULL);
    Stream<string> s(ori_data);
    
    bool to_del[256];
    memset(to_del, 0, sizeof(to_del));
    to_del['.'] = true;
    to_del[','] = true;
    to_del['('] = true;
    to_del[')'] = true;
    to_del['+'] = true;
    to_del['-'] = true;
    to_del[':'] = true;
    to_del['\''] = true;
    to_del[';'] = true;
    to_del['/'] = true;
    to_del['$'] = true;
    to_del['`'] = true;
    to_del['%'] = true;
    to_del['*'] = true;
    to_del['!'] = true;
    to_del['#'] = true;
    to_del['&'] = true;
    to_del['{'] = true;
    to_del['|'] = true;
    to_del['}'] = true;
    to_del['~'] = true;
    
    auto group = s
        .map<string>([to_del](const string &s)
        {
            string t;
            for(char c: s) if(!to_del[c]) t += c;
            return t;
        })
        .map<string>([](const string &s)
        {
            string t;
            for(char c: s) t += toupper(c);
            return t;
        })
        .map<string>([](const string &s)
        {
            string t;
            for(char c: s) t += tolower(c);
            return t;
        })
        .map<string>([](const string &s)
        {
            int n = s.size();
            if(n >= 3 && s[n - 3] == 'i' && s[n - 2] == 'n' && s[n - 1] == 'g') return string(s, 0, n - 3);
            return s;
        })
        .map<string>([](const string &s)
        {
            int n = s.size();
            if(n >= 2 && s[n - 2] == 'e' && s[n - 1] == 'd') return string(s, 0, n - 2);
            return s;
        })
        .filter([](const string &s)
        {
            return (bool) s.size();
        })
        .map<pair<string, int>>([](const string& ss)
        {
            return make_pair(ss, 1);
        })
        .group_by_key<string, int>([](const pair<string, int>& p){
            return p.first;
        },
        [](const pair<string, int>& p)
        {
            return p.second;
        });
    std::map<string, int> res_map;
    for(auto it=group.begin(); it!=group.end(); it++){
        auto sum = it->second.reduce(0, [](const int& t1, const int& t2){return t1 + t2;});
        if(sum >= 10 || it->first.length() >= 1 && it->first[0] == 'a' || it->first.length() >= 2 && it->first[1] == 's' || it->first.length() >= 3 && it->first[2] == 't'){
            res_map[it->first] = sum;
        }
    }
    gettimeofday(&tv_end, NULL);
    // check for correctness
    // ofstream ansout("3.ans");
    // for(auto &p: res_map) ansout << p.first << ' ' << p.second << endl;
    ifstream ansin(ans_file);
    if(!ansin){
        cout << "ERROR: 2" << endl;
        return;
    }
    string word;
    int count;
    std::map<string, int> ans_map;
    while(!ansin.eof()){
        ansin >> word >> count;
        ans_map[word] = count;
    }
    bool corr = true;
    for(auto it=ans_map.begin(); it!=ans_map.end(); it++){
        string k = it->first;
        int v = it->second;
        if(res_map.find(k) == res_map.end()){
            corr = false;
            break;
        }else if(res_map[k] != v){
            corr = false;
            break;
        }
    }
    cout << (corr ^ 0x19980129) << endl;
    cout << ((int) ((tv_end.tv_sec-tv_begin.tv_sec)*1000.0 + (tv_end.tv_usec-tv_begin.tv_usec)/1000.0) ^ 0x19980129) << endl;
    cout << "HaobaNanijiayouQueshiGG" << endl;
}

struct special
{
    unsigned a;
    unsigned padding;
};
static double special_value(special x)
{
    double u = x.padding;
    u = sqrt(u);
    u = atan(u);
    u = cos(u);
    u = log(u);
    u = u * u;
    u = sqrt(u);
    u = exp(u);
    u = u * u;
    u = sqrt(u);
    u = atan(u);
    u = cos(u);
    u = log(u);
    u = u * u;
    u = sqrt(u);
    u = exp(u);
    u = u * u;
    u = sqrt(u);
    u = atan(u);
    u = cos(u);
    u = log(u);
    u = u * u;
    u = sqrt(u);
    u = exp(u);
    u = u * u;
    return u;
}
static bool operator <(special x, special y)
{
    return special_value(x) < special_value(y);
}
static bool operator ==(special x, special y)
{
    return x.padding == y.padding;
}

namespace std
{
    template<>
    struct hash<special>
    {
        size_t operator()(special x) const
        {
            return x.padding;
        }
    };
}

// time-consuming comparator and fast hashing 
static void very_hard_test(string data_file, string ans_file)
{
    ifstream fin(data_file);
    if(!fin){
        cout << "ERROR: 1" << endl;
        return;
    }
    special t;
    vector<special> ori_data;
    while(fin >> t.a >> t.padding){
        ori_data.push_back(t);
        // if(++cnt >= 20000000) break;
    }
    
    for(int n = ori_data.size(); n; n = n * 99 / 100)
    {
        // printf("%d\n", n);
        for(int i = 0; i < n; i++)
        {
            special t = ori_data[i];
            t.a = (t.a + 19280671) % 998244353;
            ori_data.push_back(t);
        }
    }
    
    // cout << ori_data.size() << endl;
    
    // cout << cnt << endl;
    // execute
    struct timeval tv_begin, tv_end;
    gettimeofday(&tv_begin, NULL);
    Stream<special> os(ori_data);
    auto s = os
    
        .map<pair<double, unsigned>>([](const special &x)
        {
            return make_pair(special_value(x), x.a);
        })
        .map<pair<double, double>>([](const pair<double, unsigned> &p)
        {
            special x; x.padding = p.second; x.a = p.second;
            return make_pair(p.first, special_value(x));
        })
        .map<special>([](const pair<double, double> &p)
        {
            special x; x.padding = p.first - 2.5; x.a = p.second - 2.5;
            return x;
        })
    
        .map<pair<double, unsigned>>([](const special &x)
        {
            return make_pair(special_value(x), x.a);
        })
        .map<pair<double, double>>([](const pair<double, unsigned> &p)
        {
            special x; x.padding = p.second; x.a = p.second;
            return make_pair(p.first, special_value(x));
        })
        .map<special>([](const pair<double, double> &p)
        {
            special x; x.padding = p.first - 2.5; x.a = p.second - 2.5;
            return x;
        })
    
        .map<pair<double, unsigned>>([](const special &x)
        {
            return make_pair(special_value(x), x.a);
        })
        .map<pair<double, double>>([](const pair<double, unsigned> &p)
        {
            special x; x.padding = p.second; x.a = p.second;
            return make_pair(p.first, special_value(x));
        })
        .map<special>([](const pair<double, double> &p)
        {
            special x; x.padding = p.first - 2.5; x.a = p.second - 2.5;
            return x;
        })
        
        .map<special>([](special x)
        {
            ++x.a; ++x.padding;
            return x;
        });
    
    
    auto g1 = s.group_by_key<special, special>([](const special &a)
    {
        return a;
    },
    [](const special &a)
    {
        return a;
    });
    special sum = (special) {0, 0};
    for(const auto &p: g1)
    {
        sum = p.second.reduce(sum, [](special x, special y)
        {
            return (special) {x.a + y.a, x.padding + y.padding};
        });
    }
    
    unsigned sum2 = 0;
    auto g2 = s.group_by_key<special, unsigned>([](const special &a)
    {
        return a;
    },
    [](const special &a)
    {
        return a.a;
    });
    for(const auto &p: g2)
    {
        sum2 = p.second.reduce(sum2, [](unsigned x, unsigned y)
        {
            return x + y;
        });
    }
    
    // cout << sum2 << endl;
    
    auto g3 = s.group_by_key<special, unsigned>([](const special &a)
    {
        return a;
    },
    [](const special &a)
    {
        return a.padding;
    });
    for(const auto &p: g3)
    {
        sum2 = p.second.map<unsigned>([](unsigned x)
        {
            return x ? x : 1u;
        })
        .reduce(sum2, [](unsigned x, unsigned y)
        {
            return (unsigned) ((unsigned long long) x * y % 998244353u);
        });
    }
    
    unsigned sum0 = sum.a, sum1 = sum.padding;
    
    // cout << sum0 << ' ' << sum1 << ' ' << sum2 << endl;
    
    gettimeofday(&tv_end, NULL);
    // check for correctness
    // ofstream ansout("3.ans");
    // for(auto &p: res_map) ansout << p.first << ' ' << p.second << endl;
    ifstream ansin(ans_file);
    if(!ansin){
        cout << "ERROR: 2" << endl;
        return;
    }
    
    unsigned ans0, ans1, ans2;
    ansin >> ans0 >> ans1 >> ans2;
    
    bool corr = (ans0 == sum0) && (ans1 == sum1) && (ans2 == sum2);
    
    cout << (corr ^ 0x19980129) << endl;
    cout << ((int) ((tv_end.tv_sec-tv_begin.tv_sec)*1000.0 + (tv_end.tv_usec-tv_begin.tv_usec)/1000.0) ^ 0x19980129) << endl;
    cout << "HaobaNanijiayouQueshiGG" << endl;
}



int main(int argc, char **argv) {
    // if(argc != 4){
        // printf("usage: %s <case_number> <data_file> <ans_file>\n", argv[0]);
        // return 0;
    // }
    int case_num; scanf("%d", &case_num);// = atoi(argv[1]);
    string data_file = "./data_local/case"+to_string(case_num)+"_data.txt";//(argv[2]);
    string ans_file = "./data_local/case"+to_string(case_num)+"_ans.txt";//(argv[3]);
    sand_sculpture_test();
    switch (case_num) {
        case 1:
            very_simple_test(data_file, ans_file);
            break;
        case 2:
            not_very_simple_test(data_file, ans_file, 10, 0.85);
            break;
        case 3:
            a_little_hard_test(data_file, ans_file);
            break;
        default:
            very_hard_test(data_file, ans_file);
            break;
    }
    
    return 0;
}
